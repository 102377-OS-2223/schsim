#ifndef __DISPATCHER__
#define __DISPATCHER__

enum algorithms{FCFS, SJF, RR, PRIORITIES}; 
static const char * const algorithmsNames[] = {
	[FCFS] = "fcfs",
	[SJF] = "sjf",
    [RR] = "rr",
    [PRIORITIES] = "priorities",
};

enum modalities{PREEMPTIVE, NONPREEMPTIVE}; 
static const char * const modalitiesNames[] = {
	[PREEMPTIVE] = "preemptive",
	[NONPREEMPTIVE] = "nonpreemptive",
};

int num_algorithms(void);
int num_modalities(void);
size_t initProcTable(Process ** procTable);
void fcfs(Process * procTable, size_t nprocs);

#endif