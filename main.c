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


    //@Jordi: Aqui cridem a la funció del dispatcher en funció dels paràmetres ara simplemnt crido a la funció
    Process* procTable; 
    size_t nprocs = initProcTable(&procTable);
    fcfs(procTable,nprocs);
    for(int p=0; p<nprocs; p++){
        cleanProcess(procTable[p]);
    }
    free(procTable);
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