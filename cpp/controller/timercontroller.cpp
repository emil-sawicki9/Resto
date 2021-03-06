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

#include "timercontroller.h"

TimerController::TimerController(QObject *parent)
    : QObject(parent)
{
    m_timer.setTimerType(Qt::PreciseTimer);
    m_timer.setInterval(1000);  // one second interval

    connect(&m_timer, &QTimer::timeout, this, &TimerController::onTimeTic);
}

int TimerController::elapsedBreakDuration() const
{
    return m_elapsedBreakDuration;
}

int TimerController::elapsedWorkPeriod() const
{
    return m_elapsedWorkPeriod;
}

int TimerController::elapsedWorkTime() const
{
    return m_elapsedWorkTime;
}

TimerController::PeriodType TimerController::activePeriodType() const
{
    return m_periodType;
}

void TimerController::start(bool restart)
{
    if (restart)
    {
        // set initial state
        setElapsedBreakDuration(0);
        setElapsedWorkPeriod(0);
        setElapsedWorkTime(0);
    }

    m_timer.start();
}
void TimerController::stop()
{
    m_timer.stop();
}

void TimerController::countBreakTime()
{
    if (m_periodType == PeriodType::Break)
    {
        return;
    }

    m_periodType = PeriodType::Break;
    emit activePeriodTypeChanged(m_periodType);
}
void TimerController::countWorkTime()
{
    if (m_periodType == PeriodType::Work)
    {
        return;
    }

    m_periodType = PeriodType::Work;
    emit activePeriodTypeChanged(m_periodType);
}

void TimerController::setElapsedBreakDuration(int elapsedBreakDuration)
{
    if (m_elapsedBreakDuration == elapsedBreakDuration)
    {
        return;
    }

    m_elapsedBreakDuration = elapsedBreakDuration;
    emit elapsedBreakDurationChanged(elapsedBreakDuration);
}
void TimerController::setElapsedWorkPeriod(int elapsedWorkPeriod)
{
    if (m_elapsedWorkPeriod == elapsedWorkPeriod)
    {
        return;
    }

    m_elapsedWorkPeriod = elapsedWorkPeriod;
    emit elapsedWorkPeriodChanged(elapsedWorkPeriod);
}
void TimerController::setElapsedWorkTime(int elapsedWorkTime)
{
    if (m_elapsedWorkTime == elapsedWorkTime)
    {
        return;
    }

    m_elapsedWorkTime = elapsedWorkTime;
    emit elapsedWorkTimeChanged(elapsedWorkTime);
}

void TimerController::incrementWorkTime()
{
    setElapsedWorkPeriod(elapsedWorkPeriod() + 1);
    setElapsedWorkTime(elapsedWorkTime() + 1);
}
void TimerController::incrementBreakTime()
{
    setElapsedBreakDuration(elapsedBreakDuration() + 1);
}

void TimerController::onTimeTic()
{
    switch (m_periodType)
    {
    case PeriodType::Break:
        incrementBreakTime();
        break;
    case PeriodType::Work:
        incrementWorkTime();
        break;
    default:
        Q_ASSERT(false);
    }
}

void TimerController::addTime(int time)
{
    const int newTime = time * 60;
    setElapsedWorkPeriod(newTime + elapsedWorkPeriod());
    setElapsedWorkTime(newTime + elapsedWorkTime());
}

void TimerController::substractTime(int time)
{
    const int newTime = time * 60;
    int newElapsedWork = elapsedWorkTime() - newTime;
    if (newElapsedWork < 0)
        newElapsedWork = 0;
    int newElapsedPeriod = elapsedWorkPeriod() - newTime;
    if (newElapsedPeriod < 0)
        newElapsedPeriod = 0;
    setElapsedWorkPeriod(newElapsedPeriod);
    setElapsedWorkTime(newElapsedWork);
}
