/*
 * scheduler.c
 *
 *  Created on: Oct 26, 2024
 *      Author: thuyh
 */

#include "scheduler.h"

#define SCH_MAX_TACKS 40
uint8_t cycle = 10;
uint8_t time_drop = 0;
uint8_t current_index_task = 0;
sTasks SCH_Tasks_G[SCH_MAX_TACKS];
void SCH_INIT(void){
	current_index_task = 0;
}
void SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD){
    int index_add = current_index_task;
    DELAY = DELAY / cycle;
    if(current_index_task < SCH_MAX_TACKS){
        for(int i =0 ; i < current_index_task ; i++){
            if(SCH_Tasks_G[i].Delay <= DELAY)
            {
            	DELAY = DELAY - SCH_Tasks_G[i].Delay  ;
            }
            else{
                index_add = i;
                break;
            }
        }
        for(int i = current_index_task; i > index_add; i--){
            SCH_Tasks_G[i] = SCH_Tasks_G[i-1];
        }
        current_index_task++;
        SCH_Tasks_G[index_add].pTask = pFunction;
        SCH_Tasks_G[index_add].Delay = DELAY;
        SCH_Tasks_G[index_add].Period = PERIOD;
        if(index_add < current_index_task - 1) // Nếu không thêm vào cuối
            SCH_Tasks_G[index_add+1].Delay -= SCH_Tasks_G[index_add].Delay;
    }
}

void SCH_Update(void){
    if(SCH_Tasks_G[0].Delay > 0){
        SCH_Tasks_G[0].Delay--;
    }
    if(SCH_Tasks_G[0].Delay <= 0){
    	SCH_Tasks_G[0].RunMe++;
    }
}

void SCH_Dispatch_Task(void){
    if(SCH_Tasks_G[0].RunMe > 0){
        SCH_Tasks_G[0].RunMe--;
        (*SCH_Tasks_G[0].pTask)();
    	sTasks temp = SCH_Tasks_G[0];
        SCH_Delete(0);
        if(temp.Period > 0){
        	SCH_Add_Task(temp.pTask, temp.Period, temp.Period);
        }
    }
}

void SCH_Add_Oneshort_tasks(void (*pFunction)(),uint32_t DELAY){
	SCH_Add_Task(pFunction, DELAY, 0);
}

void SCH_Delete(uint32_t id) {
    if (id >= current_index_task) {
        // Invalid task ID
        return;
    }

    // If not deleting the last task, adjust the delay of the next task
    if (id < current_index_task - 1) {
        SCH_Tasks_G[id + 1].Delay += SCH_Tasks_G[id].Delay;
    }

    // Shift tasks to fill the gap
    for (int i = id; i < current_index_task - 1; i++) {
        SCH_Tasks_G[i] = SCH_Tasks_G[i + 1];
    }

    // Clear the last task (optional)

    SCH_Tasks_G[current_index_task - 1].Delay = 0;
    SCH_Tasks_G[current_index_task - 1].Period = 0;
    SCH_Tasks_G[current_index_task - 1].RunMe = 0;

    current_index_task--;
}
