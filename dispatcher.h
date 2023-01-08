#ifndef __DISPATCHER__
#define __DISPATCHER__

#define WHITE "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define GRAY "\033[37m"
#define RESET "\033[0m"

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

int run_dispatcher(Process *procTable, size_t nprocs, int algorithm, int modality, bool verbose);
void printMetrics(size_t simulationCPUTime, size_t nprocs, Process *procTable );
void printSimulation(size_t nprocs, Process *procTable, size_t duration);
int getCurrentBurst(Process* proc, int current_time);
size_t getTotalCPU(Process *procTable, size_t nprocs);

#endif