#ifndef Schuduler_H_
#define Schuduler_H_
#include "types.h"
 // declaring a pointer
struct task{
void (*p)(void);
uint32 period;
uint8 priority;
};
typedef struct task          	task; 
void task_init(void (*pointer)(void), uint32 period,uint8 priority);
void Task_Scheduler();
#endif