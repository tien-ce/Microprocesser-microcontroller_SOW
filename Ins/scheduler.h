/*
 * scheduler.h
 *
 *  Created on: Oct 26, 2024
 *      Author: thuyh
 */

#ifndef INS_SCHEDULER_H_
#define INS_SCHEDULER_H_
#include "stdint.h"
extern uint8_t current_index_task;
extern uint8_t time_drop;
typedef struct{
	void (*pTask)(void);
	int32_t Delay;
	uint32_t Period;
	uint8_t RunMe;
} sTasks;
extern uint8_t time_drop ;
void send_time();
void SCH_INIT(void);
void SCH_Add_Task(void (*pFunction)(),
						uint32_t DELAY,
						uint32_t PERIOD);
void SCH_Update(void);
void SCH_Dispatch_Task(void);
void SCH_Delete(uint32_t ID);
void SCH_Add_Oneshort_tasks(void (*pFunction)(),uint32_t DELAY);
void SCH_Go_To_Sleep(void);
void SCH_Report_Status(void);
#endif /* INS_SCHEDULER_H_ */
