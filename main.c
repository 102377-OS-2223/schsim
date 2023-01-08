#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "process.h"
#include "log.h"
#include "dispatcher.h"
#include <getopt.h>

#define OPTSTR "a:f:m:vh" // Options string

void clean(void);
void usage(void);

// Parameters
char *filename = NULL;
char *algorithm = NULL;
char *modality = NULL;
bool verbose = false;

int main(int argc, char *argv[]){

    int opt;
    while ((opt = getopt(argc, argv, OPTSTR)) != EOF) //   EOF = -1
        switch(opt) {
            case 'h':  // help
                usage(); 
                clean(); 
                return EXIT_SUCCESS;
                break;  
            case 'v': // verbose
                verbose = true;
                break;
            case 'f': // filename
                    filename = strdup(optarg); 
                break;
            case 'a': // algorithm
                    for (int i = 0; i < num_algorithms(); i++) {
                        if (strcmp(optarg, algorithmsNames[i]) == 0) {
                            algorithm = strdup(optarg); 
                            break;
                        }
                    }
                     if (algorithm == NULL){
                        fprintf(stderr, "No such algorithm: %s\n", optarg);
                        clean();
                        return EXIT_FAILURE;
                    }
                    break;
            case 'm': // modality
                    for (int i = 0; i < num_modalities(); i++) {
                        if (strcmp(optarg, modalitiesNames[i]) == 0) {
                            modality = strdup(optarg);
                            break;
                        }
                    }
                    if (modality == NULL){
                        fprintf(stderr, "No such modality: %s\n", optarg);
                        clean();
                        return EXIT_FAILURE;
                    }
                    break;
    }

    log_set_quiet(!verbose);
if ( algorithm != NULL && filename != NULL && modality != NULL){

        Process * procTable;
        size_t nprocs = initFromCSVFile(filename, &procTable);
        
        if (strncmp(algorithm, algorithmsNames[FCFS], sizeof(algorithmsNames[FCFS])/sizeof(char *))==0){
            if (strncmp(modality, modalitiesNames[PREEMPTIVE], sizeof(modalitiesNames[PREEMPTIVE])/sizeof(char *) ) == 0){
                printf("%s can not be executed in %s mode ... changing to %s\n",algorithmsNames[FCFS],
                 modalitiesNames[PREEMPTIVE], modalitiesNames[NONPREEMPTIVE]);
            }
            run_dispatcher(procTable,nprocs,FCFS,NONPREEMPTIVE); 
        }else if (strcmp(algorithm, algorithmsNames[SJF])==0){
            if (strcmp(modality, modalitiesNames[PREEMPTIVE])==0){
                run_dispatcher(procTable,nprocs,SJF,PREEMPTIVE);
            }else{
                run_dispatcher(procTable,nprocs,SJF,NONPREEMPTIVE);
            }
            
        }else if (strcmp(algorithm, algorithmsNames[PRIORITIES])==0){
            if (strcmp(modality, modalitiesNames[PREEMPTIVE])==0){
                run_dispatcher(procTable,nprocs,PRIORITIES,PREEMPTIVE);
            }else{
                run_dispatcher(procTable,nprocs,PRIORITIES,NONPREEMPTIVE);
            }     
        }
    
        free(procTable);
    } else {
        fprintf(stderr, "algorithm:filename:modality are required to run simulation.\n");
    }

    clean();
    return EXIT_SUCCESS;
}
   
    

void usage(){
      fprintf(stderr,
      " usage:\n"
      "    ./schsim  [-a [fcfs,sjf,rr,priorities]] [-h] [-m] [-f inputFile]\n"
      "       -a  [fcfs,sjf,rr,priorities]  \n"
      "       -m    [preemptive,nonpreemptive]  \n"
      "       -h:            print out this help message\n"
      "       -f file.csv:  read process table from csv file\n"
      "       -v activate verbose \n"
      "\n");
}

void clean(){
    // Cleanning dynamic memory
    if (algorithm != NULL)
        free(algorithm);

    if (filename != NULL)
        free(filename);

    if (modality != NULL)
        free(modality);
}