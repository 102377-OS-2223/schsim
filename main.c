#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "process.h"
#include "log.h"
#include "dispatcher.h"
#include <getopt.h>

#define OPTSTR "a:f:m:vh"

void clean(void);
void usage(void);

// Parameters
char *filename = NULL;
char *algorithm = NULL;
char *modality = NULL;
bool verbose = false;

int main(int argc, char *argv[]){

    int opt;
    while ((opt = getopt(argc, argv, OPTSTR)) != EOF)
        switch(opt) {
            case 'h': usage(); 
                clean(); 
                return EXIT_SUCCESS;
                break;  
            case 'v':
                verbose = true;
                break;
            case 'f': 
                    filename = strdup(optarg); 
                break;
            case 'a':
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
            case 'm':
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
 
 // Es millora la funció usage perquè mostri els algorismes i modalitats disponibles.
void usage(){


    printf("Usage: dispatcher [OPTIONS] algorithm:filename:modality \n");
    printf("Options:\n");
    printf("\t-h\t\tShow this help message\n");
    printf("\t-v\t\tVerbose mode\n");
    printf("\t-a\t\tAlgorithm to use\n");
    printf("\t-f\t\tFilename to read from\n");
    printf("\t-m\t\tModality to use\n");
    printf("Algorithms:\n");
    for (int i = 0; i < num_algorithms(); i++) {
        printf("\t%s\n", algorithmsNames[i]);
    }
    printf("Modalities:\n");
    for (int i = 0; i < num_modalities(); i++) {
        printf("\t%s\n", modalitiesNames[i]);
    }

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