#ifndef __PROCESS__
#define __PROCESS__


// Process
// Ready (P): The process is waiting for the scheduler. 
// Running (E): The process consumes CPU 
// Blocked (W): The process does input/output operations. 
// Finished (F): The process finishes its work.
enum processStatus{Ready, Running, Bloqued, Finished};


typedef struct process
{
    char* name;
    int time;
    int burst;
    int id;
    int * life;
} Process;

void printProcess(Process proces);
void cleanProcess(Process proces);

#endif