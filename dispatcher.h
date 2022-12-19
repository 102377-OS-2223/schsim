#ifndef __DISPATCHER__
#define __DISPATCHER__

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m" // Per els parats.
#define KGRN  "\x1B[32m" // Per els en execució.
#define KYEL  "\x1B[33m" // Per els esperant...
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

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

size_t initFromCSVFile(char* filename, Process** procTable);

int run_dispatcher(Process *procTable, size_t nprocs, int algorithm, int modality);
void printMetrics(size_t simulationCPUTime, size_t nprocs, Process *procTable );
void printSimulation(size_t nprocs, Process *procTable, size_t duration);
void printValueOfCurrentProcessInTime(Process current, int time);
int getCurrentBurst(Process* proc, int current_time);
size_t getTotalCPU(Process *procTable, size_t nprocs);

#endif