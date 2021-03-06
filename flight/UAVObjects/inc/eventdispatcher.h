/**
 ******************************************************************************
 * @addtogroup TauLabsCore Tau Labs Core components
 * @{
 * @addtogroup UAVObjectHandling UAVObject handling code
 * @{
 *
 * @file       eventdispatcher.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @author     Tau Labs, http://taulabs.org, Copyright (C) 2012-2014
 * @author     dRonin, http://dronin.org Copyright (C) 2015
 * @brief      Event dispatcher, distributes object events as callbacks. Alternative
 * 	           to using tasks and queues. All callbacks are invoked from the event task.
 * @see        The GNU Public License (GPL) Version 3
 *
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, see <http://www.gnu.org/licenses/>
 */

#ifndef EVENTDISPATCHER_H
#define EVENTDISPATCHER_H

#include "pios_queue.h"

// Public types
/**
 * Event dispatcher statistics
 */
typedef struct {
	uint32_t lastErrorID;
	uint32_t eventErrors;
} EventStats;

// Public functions
void EventGetStats(EventStats* statsOut);
void EventClearStats();
int32_t EventPeriodicCallbackCreate(UAVObjEvent* ev, UAVObjEventCallback cb, uint16_t periodMs);
int32_t EventPeriodicCallbackUpdate(UAVObjEvent* ev, UAVObjEventCallback cb, uint16_t periodMs);
int32_t EventPeriodicQueueCreate(UAVObjEvent* ev, struct pios_queue *queue, uint16_t periodMs);
int32_t EventPeriodicQueueUpdate(UAVObjEvent* ev, struct pios_queue *queue, uint16_t periodMs);

#endif // EVENTDISPATCHER_H

/**
 * @}
 * @}
 */
