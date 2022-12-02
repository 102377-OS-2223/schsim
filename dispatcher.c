#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "process.h"
#include "log.h"
#include "dispatcher.h"

int num_algorithms() {
  return sizeof(algorithmsNames) / sizeof(char *);
}

int num_modalities() {
  return sizeof(modalitiesNames) / sizeof(char *);
}

// @Jordi: Funció mock: Quan el grup del David tingui la seva funció la modificarem
size_t initProcTable(Process ** procTable){
    size_t nprocs = 3;
    *procTable = malloc(nprocs*sizeof(Process));
    Process * _procTable = *procTable;
    for (int i =0; i< nprocs;i++){
        Process p;
        p.id=i;
        p.name=malloc(10*sizeof(char));
        p.burst=0;
        p.time=0;
        p.life = 0;
        _procTable[i]=p;
    }
    /*És la diapositiva 15 de la setmana 11. Les dades introduïdes següents:*/
    _procTable[0].burst = 4;
    _procTable[0].time = 2;
    strcpy(_procTable[0].name, "B");
    _procTable[1].burst = 2;
    _procTable[1].time = 3;
    strcpy(_procTable[1].name, "C");
    _procTable[2].burst=7;
    _procTable[2].time=0;
    strcpy(_procTable[2].name, "A");
    return nprocs;
}

void fcfs(Process * procTable, size_t nprocs){

    // Imprimim les dades
    for(int p=0; p<nprocs; p++){
        Process proc = procTable[p];
        printProcess(proc);
    }

    // Ordenar procTable per temps d'arribada

    int notdone = 1;
    int time_total = 0;
    for(int i = 0; i < 3; i ++){
        time_total += procTable[i].time;
    }
    
    /*while(notdone){
        for(int time = 0; time < time_total; i++){
            Process selected;
            //if(time>=)
            //ORDENAR LA LLISTA DE PROCESSOS.
        }
    }*/

}



