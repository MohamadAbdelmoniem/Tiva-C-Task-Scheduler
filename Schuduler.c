#include "Schuduler.h"
#include "tm4c123gh6pm.h"
#include "bitwise_operation.h"
#include "types.h"
#include "DIO.h"

extern int64 Counter;
task tasks[3];
uint8 i_task = 0;

void task_init(void (*pointer)(void), uint32 period, uint8 priority){
  task mytask;
  mytask.p = pointer;
  mytask.period = period;  
  mytask.priority = priority;
  tasks[i_task] = mytask;
  i_task++;
}

void sort_tasks() {
  uint8 i, j;
  task temp;
  for(i=0; i<3; i++) {
    for(j=i+1; j<3; j++) {
      if(tasks[j].priority > tasks[i].priority) {
        temp = tasks[i];
        tasks[i] = tasks[j];
        tasks[j] = temp;
      }
    }
  }
}

void Task_Scheduler() {
  uint32 i = 0;
  sort_tasks(); // sort tasks by priority
  while(1) {
    __asm("CPSID i");
    if(i == 3) {
      i = 0;
      DIO_WritePin(PORTF,2,0);
      DIO_WritePin(PORTF,3,0);
      DIO_WritePin(PORTF,1,0);
    }
    if(Counter % tasks[i].period == 0 && Counter!=0) {
      (*tasks[i].p)();
    }
    i++;
    __asm("CPSIE i");
  }
}

