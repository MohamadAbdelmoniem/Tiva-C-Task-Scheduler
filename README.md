# Tiva-C-Task-Scheduler

This project implements a simple task scheduler for a microcontroller using the TM4C123GH6PM microcontroller. The task scheduler allows you to schedule and prioritize tasks to be executed at specific intervals. It uses the SysTick timer to keep track of time and trigger task execution.

## Prerequisites

To run this project, you need the following prerequisites:

- TM4C123GH6PM microcontroller
- TivaWare C Series software development kit (SDK)
- IAR Embedded Workbench or any other compatible Integrated Development Environment (IDE)

## Installation

1. Clone this repository to your local machine:

   ```shell
   git clone https://github.com/MohamadAbdelmoniem/tiva-c-task-scheduler.git
   ```

2. Open the project in your IDE (e.g., IAR Embedded Workbench).

3. Connect your TM4C123GH6PM microcontroller to your computer.

4. Build and flash the project to the microcontroller.

## Usage

Once the project is successfully installed and flashed to the microcontroller, it will execute the scheduled tasks based on their priorities and intervals.

The main file `main.c` contains the task initialization and scheduling code. You can modify this file to add or modify tasks as per your requirements. The tasks are defined as separate functions and can be customized based on the desired functionality.

```c
// Example task initialization
task_init(&Blinky1, 5, 1); // Initialize Blinky1 task with period 5 and priority 1

// Example task function
void Blinky1() {
    // Task logic here
    DIO_WritePin(PORTF, 1, 1);
    // delayMs(333);
}
```

The task scheduler is implemented in `Schuduler.c`, which sorts the tasks based on their priorities and executes them accordingly.

```c
// Sort tasks by priority
sort_tasks();

// Task scheduler loop
while(1) {
    // Disable interrupts temporarily
    __asm("CPSID i");

    // Check if all tasks have been executed
    if(i == 3) {
        i = 0;
        // Reset any state or flags if necessary
        DIO_WritePin(PORTF, 2, 0);
        DIO_WritePin(PORTF, 3, 0);
        DIO_WritePin(PORTF, 1, 0);
    }

    // Check if the current task should be executed based on its period
    if(Counter % tasks[i].period == 0 && Counter != 0) {
        // Execute the task function
        (*tasks[i].p)();
    }

    // Move to the next task
    i++;

    // Re-enable interrupts
    __asm("CPSIE i");
}
```

Feel free to modify the code to add more tasks or customize the behavior of existing tasks. Make sure to rebuild and flash the project to see the changes on your microcontroller.

## Contributing

Contributions to this project are welcome. If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.
```

Please note that the instructions may vary slightly depending on the specific version of IAR Embedded Workbench you are using. Make sure to adapt the steps accordingly.
