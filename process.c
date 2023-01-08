#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "process.h"
#include "log.h"

const char* processStatusNames[] = {"Ready", "Running", "Bloqued","Finished"};

void printProcess(Process proces){
    printf("{id:%d, name:%s, arrive_time:%d, burst:%d}\n", proces.id,proces.name,proces.arrive_time,proces.burst);
}

void cleanProcess(Process proces){

    if (proces.name != NULL){
        free(proces.name);
    }
};

Process initProcessFromTokens(char* line, char* separator){

  const size_t BUFSIZE = 32; // Quantitat de memoria per al Buffer
  size_t bufsize = BUFSIZE; 
  Process p; // Procès

  char *feature = malloc(bufsize * sizeof(char)); // Reserva de memoria.
  feature=strtok(line, separator); // Separar String por tokens.

  int features = 0;
  while (feature != NULL) {
            switch (features)
            {
            case 0:
                p.id=atoi(feature); // Retorna INT de id.
                break;
            case 1:
                p.name=malloc(sizeof(feature)); // Resrva memoria per al nom del procès
                strcpy(p.name,feature);
                break;
            case 2:
                p.priority=atoi(feature);
                break;
            case 3:
                p.arrive_time=atoi(feature);
                break;
            case 4:
                p.burst=atoi(feature);
            }
            feature=strtok(NULL, ";"); 
            features++;
    }
  free(feature); // Llibera memoria
  return p; // retorna procès
}

int compareArrival(const void *s1, const void *s2){
    Process *p1 = (Process *)s1;
    Process *p2 = (Process *)s2;
    if (p1->arrive_time > p2->arrive_time) 
        return 1; 
    else if (p1->arrive_time < p2->arrive_time)  
        return -1;
    else
        return 0;
}

int compareBurst(const void *s1, const void *s2){
    Process *p1 = (Process *)s1;
    Process *p2 = (Process *)s2;
    if (p1->burst > p2->burst){
        return 1; 
    }
    else if (p1->burst < p2->burst){
        return -1;
    }
    else{
        return 0;
    }
}

int comparePriority(const void *s1, const void *s2){
    Process *p1 = (Process *)s1;
    Process *p2 = (Process *)s2;
    if (p1->priority > p2->priority) 
        return 1; 
    else if (p1->priority < p2->priority)  
        return -1;
    else
        return 0;
}

/*int Compareall(const void *s1, const void *s2,){
    Process *p1 = (Process *)s1;
    Process *p2 = (Process *)s2;
    if (p1-> > p2) 
        return 1; 
    else if (p1 < p2)  
        return -1;
    else
        return 0;
}*/

//@TODO: Aquesta funció ha de retorna un cadena de text amb la següent info:
//{id:0; name:A; burst:7; priority:9; arrive_time:0; lifecycle:[EEEPPEF]; ...} 

 /*char* procToString(Process* p){


}*/