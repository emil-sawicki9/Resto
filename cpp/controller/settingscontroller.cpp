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

#include "settingscontroller.h"
#include <QCoreApplication>

const QStringList SettingsController::sc_availableColors = { "#19886F", "#EC811B", "#682C90", "#C0159B", "#008000", "#0958EC", "#666666" };

SettingsController::SettingsController(QObject *parent)
    : QObject(parent), m_settings(QCoreApplication::organizationName(), QCoreApplication::applicationName())
{
    m_settings.setDefaultApplicationColor(sc_availableColors.first());
}

int SettingsController::breakDuration() const
{
    return m_settings.breakDuration();
}
int SettingsController::breakInterval() const
{
    return m_settings.breakInterval();
}
int SettingsController::workTime() const
{
    return m_settings.workTime();
}
int SettingsController::postponeTime() const
{
    return m_settings.postponeTime();
}
bool SettingsController::autoStart() const
{
    return m_settings.autoStart();
}

QPoint SettingsController::windowPosition() const
{
    return m_settings.windowPosition();
}

QSize SettingsController::windowSize() const
{
    return m_settings.windowSize();
}

QStringList SettingsController::availableColors() const
{
    return sc_availableColors;
}

QColor SettingsController::applicationColor() const
{
    return m_settings.applicationColor();
}

bool SettingsController::trayAvailable() const
{
    return m_settings.trayAvailable();
}

bool SettingsController::showTrayInfo() const
{
    return m_settings.showTrayInfo();
}

bool SettingsController::autoHide() const
{
    return m_settings.autoHide();
}

bool SettingsController::hideOnClose() const
{
    return m_settings.hideOnClose();
}

QString SettingsController::updateVersion() const
{
    return m_settings.updateVersion();
}

QDateTime SettingsController::nextUpdateCheck() const
{
    return m_settings.nextUpdateCheck();
}

void SettingsController::setBreakDuration(int breakDuration)
{
    if (m_settings.breakDuration() == breakDuration)
        return;

    m_settings.setBreakDuration(breakDuration);
    emit breakDurationChanged(breakDuration);
}
void SettingsController::setBreakInterval(int breakInterval)
{
    if (m_settings.breakInterval() == breakInterval)
        return;

    m_settings.setBreakInterval(breakInterval);
    emit breakIntervalChanged(breakInterval);
}
void SettingsController::setWorkTime(int workTime)
{
    if (m_settings.workTime() == workTime)
        return;

    m_settings.setWorkTime(workTime);
    emit workTimeChanged(workTime);
}
void SettingsController::setPostponeTime(int postponeTime)
{
    if (m_settings.postponeTime() == postponeTime)
        return;

    m_settings.setPostponeTime(postponeTime);
    emit postponeTimeChanged(postponeTime);
}
void SettingsController::setAutoStart(bool autoStart)
{
    if (m_settings.autoStart() == autoStart)
        return;

    m_settings.setAutoStart(autoStart);
    emit autoStartChanged(autoStart);
}

void SettingsController::setWindowPosition(const QPoint &windowPosition)
{
    if (m_settings.windowPosition() == windowPosition)
        return;

    m_settings.setWindowPosition(windowPosition);
    emit windowPositionChanged(windowPosition);
}

void SettingsController::setWindowSize(const QSize &windowSize)
{
    if (m_settings.windowSize() == windowSize)
        return;

    m_settings.setWindowSize(windowSize);
    emit windowSizeChanged(windowSize);
}

void SettingsController::setApplicationColor(QColor color)
{
    if (m_settings.applicationColor() == color)
        return;

    m_settings.setApplicationColor(color);
    emit applicationColorChanged(color);
}

void SettingsController::setTrayAvailable(bool trayAvailable)
{
    if (m_settings.trayAvailable() == trayAvailable)
        return;

    m_settings.setTrayAvailable(trayAvailable);
    emit trayAvailableChanged(trayAvailable);
}

void SettingsController::setShowTrayInfo(bool showTrayInfo)
{
    if (m_settings.showTrayInfo() == showTrayInfo)
        return;

    m_settings.setShowTrayInfo(showTrayInfo);
    emit showTrayInfoChanged(showTrayInfo);
}

void SettingsController::setAutoHide(bool autoHide)
{
    if (m_settings.autoHide() == autoHide)
        return;

    m_settings.setAutoHide(autoHide);
    emit autoHideChanged(autoHide);
}

void SettingsController::setHideOnClose(bool hideOnClose)
{
    if (m_settings.hideOnClose() == hideOnClose)
        return;

    m_settings.setHideOnClose(hideOnClose);
    emit hideOnCloseChanged(hideOnClose);
}

void SettingsController::setUpdateVersion(const QString &updateVersion)
{
    if (m_settings.updateVersion() == updateVersion)
        return;

    m_settings.setUpdateVersion(updateVersion);
    emit updateVersionChanged(updateVersion);
}

void SettingsController::setNextUpdateCheck(const QDateTime &nextUpdateCheck)
{
    if (m_settings.nextUpdateCheck() == nextUpdateCheck)
        return;

    m_settings.setNextUpdateCheck(nextUpdateCheck);
    emit nextUpdateCheckChanged(nextUpdateCheck);
}
