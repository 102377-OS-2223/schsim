#include "process.h"
#include<stdlib.h>
#include<stdio.h>
//FCFS
Process* procTable;
int bufsize =100;


void initProcTable(Process * procTable);
void fcfs(Process * procTable);

int main(int argc, char* argv[]){
    
    initProcTable(procTable);

    int * life;
    
    //for(int i = 0; i < procTable->id;i++){
    //    printf("Process %d: %d\n", i, procTable->processes[i].pid);
   // }

}
void fcfs(Process * procTable){
    int notdone = 1;
    int time_total = 0;
    for(int i = 0; i < 3; i ++){
        time_total += procTable[i].time;
    }
    
    while(notdone){
        for(int time = 0; time < time_total; i++){
            Process selected;
            //if(time>=)
            //ORDENAR LA LLISTA DE PROCESSOS.
        }
    }

}
void initProcTable(Process *procTable){
    procTable = malloc(3*sizeof(Process));
    for (int i =0; i< 3;i++){
        Process p;
        p.id=i;
        p.name=malloc(bufsize*sizeof(char));
        p.burst=0;
        p.time=0;
        p.life = 0;
        procTable[i]=p;
    }
    /*És la diapositiva 15 de la setmana 11. Les dades introduïdes següents:*/
    procTable[0].burst=7;
    procTable[0].time=0;
    procTable[1].burst = 4;
    procTable[1].time = 2;
    procTable[2].burst = 2;
    procTable[2].time = 3;
}
