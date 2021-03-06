/********************************************
**
** Copyright 2017 JustCode Justyna Kulinska
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

QtObject {
    property DialogsManager dialogsManager

    // controller
    property var controllerConnections: Connections {
        target: controller

        onBreakStartRequest: {
            dialogsManager.showBreakRequestDialog();
        }
        onWorkEndRequest: {
            dialogsManager.showEndWorkRequestDialog();
        }
        onChangeTimeRequest: {
            dialogsManager.showChangeTimeDialog();
        }
    }

    // update controller
    property var updateConnections: Connections {
        property bool initialCheck: true

        function onInitialCheckFinished() {
            if (controller.updater.updateAvailable) {
                var showUpdateDialog = false;
                if (controller.updater.compareVersions(controller.updater.newestVersion,
                                                       controller.settings.updateVersion) > 0) {
                    showUpdateDialog = true;
                } else {
                    var postponeDate = controller.settings.nextUpdateCheck;
                    if (!isNaN(postponeDate) &&
                            (new Date()).getDate() >= postponeDate.getDate()) {
                        showUpdateDialog = true;
                    }
                }
                if (showUpdateDialog)
                    dialogsManager.showUpdateInfoDialog();
            }
        }

        target: controller.updater

        onCheckFinished: {
            if (initialCheck) {
                initialCheck = false;
                onInitialCheckFinished();
            } else {
                if (controller.updater.updateAvailable) {
                    dialogsManager.showUpdateInfoDialog();
                } else {
                    dialogsManager.showNoUpdateDialog();
                }
            }
        }
        onCheckError: {
            if (initialCheck) {
                initialCheck = false;
            } else {
                dialogsManager.showUpdateErrorDialog();
            }
        }
    }
}

