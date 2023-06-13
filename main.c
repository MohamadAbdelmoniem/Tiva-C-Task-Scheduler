#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/interrupt.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/timer.h"
#include "bitwise_operation.h"
#include "tm4c123gh6pm.h"
#include "DIO.h"
#include "inc/hw_ints.h"
#include "Schuduler.h"
#include "Counter.h"

extern int64 Counter;

void Blinky1(){
    DIO_WritePin(PORTF,1,1);
    //delayMs(333);
}

void Blinky2(){
    DIO_WritePin(PORTF,2,1);
    //delayMs(333);
}

void Blinky3(){
    DIO_WritePin(PORTF,3,1);
   // delayMs(333);
}

void Systick_Handler(){
 Counter++; 
}

void Systick_Intillize(){
  SysTickDisable(); 
  SysTickIntDisable();
  SysTickPeriodSet(16000000-1);
  SysTickIntRegister(Systick_Handler); 
  SysTickIntEnable();
  SysTickEnable();
}

int main()
{
  DIO_Init_port(PORTF,0x0E);
  task_init(&Blinky1,5,1);
  task_init(&Blinky2,10,2);
  task_init(&Blinky3,20,3);
  Systick_Intillize();
  Task_Scheduler();
}
