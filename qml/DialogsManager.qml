/********************************************
**
** Copyright 2016 JustCode Justyna Kulinska
**
** This file is part of Resto.
**
** Resto is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** any later version.
**
** Resto is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with Resto; if not, write to the Free Software
** Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
**
********************************************/

import QtQuick 2.5
import "dialogs"

Item {
    id: root

    // accessors ---------------------------------------------------------
    function showBreakRequestDialog() {
        d.showDialog(breakRequestDialog)
    }
    function showBreakDialog() {
        d.showDialog(breakDialog);
    }
    function showEndWorkRequestDialog() {
        d.showDialog(endWorkRequestDialog)
    }
    function showAboutDialog() {
        d.showDialog(aboutDialog)
    }
    function showSettingsDialog() {
        d.showDialog(settingsDialog)
    }
    function showUpdateInfoDialog() {
        d.showDialog(updateInfoDialog)
    }
    function showNoUpdateDialog() {
        d.showDialog(noUpdateDialog)
    }
    function showUpdateErrorDialog() {
        d.showDialog(updateErrorDialog)
    }
    function showChangeTimeDialog() {
        d.showDialog(changeTimeDialog)
    }

    // -------------------------------------------------------------------

    // logic -------------------------------------------------------------
    QtObject {
        id: d

        property var loaderComponent: Component {
            Loader {
                property string id

                Connections {
                    target: item

                    onClosing: {
                        d.loadersMap[id] = "";
                        destroy();
                    }
                }
            }
        }
        property var loadersMap: new Object

        function showDialog(component) {
            var id = component.toString();
            if (loadersMap[id]) {
                console.warn("Dialogs Manager", "Dialog already exist");
                return;
            }

            var loaderItem = loaderComponent.createObject(root);
            loaderItem.id = id;
            loaderItem.sourceComponent = component;
            loaderItem.active = true;
            loaderItem.item.show();

            loadersMap[id] = loaderItem;
        }
    }
    // -------------------------------------------------------------------

    // components --------------------------------------------------------
    Component {
        id: breakRequestDialog

        BreakRequestDialog {
            onAccept: {
                controller.startBreak();
                showBreakDialog();
            }
            onPostpone: {
                controller.postponeBreak();
            }
            onSkip: {
                controller.startWork();
            }
        }
    }

    Component {
        id: breakDialog

        BreakDialog {
            onEndBreak: {
                controller.startWork();
            }
        }
    }

    Component {
        id: endWorkRequestDialog

        EndWorkRequestDialog {
            onAccept: {
                controller.stop();
            }
        }
    }

    Component {
        id: aboutDialog

        AboutDialog {}
    }

    Component {
        id: settingsDialog

        SettingsDialog {}
    }

    Component {
        id: updateInfoDialog

        UpdateInfoDialog {
            onAccept: {
                controller.updater.download();
            }
            onPostpone: {
                controller.updater.postpone();
            }
            onSkip: {
                controller.updater.skip();
            }
        }
    }
    Component {
        id: noUpdateDialog

        CustomDialog {
            title: qsTr("You have the latest version!")
            description: qsTr("No updates available.")
        }
    }
    Component {
        id: updateErrorDialog

        CustomDialog {
            title: qsTr("Cannot get update information")
            description: qsTr("Please check your internet connection and try again.")
        }
    }
    Component {
        id: changeTimeDialog

        ChangeTimeDialog {

            onAddTime: {
                controller.timer.addTime(time)
            }
            onSubstractTime: {
                controller.timer.substractTime(time)
            }
        }
    }

    // -------------------------------------------------------------------
}
