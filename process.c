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

  const size_t BUFSIZE = 32;   
  size_t bufsize = BUFSIZE;
  Process p;

  char *feature = malloc(bufsize * sizeof(char));
  feature=strtok(line, separator); 

  int features = 0;
  while (feature != NULL) {
            switch (features)
            {
            case 0:
                p.id=atoi(feature);
                break;
            case 1:
                p.name=malloc(sizeof(feature));
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
  free(feature);
  return p;
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

//@TODO: Aquesta funció ha de retorna un cadena de text amb la següent info:
//{id:0; name:A; burst:7; priority:9; arrive_time:0; lifecycle:[EEEPPEF]; ...} 
char* procToString(Process* p){

    int i = p -> id;
    int n = p -> name;
    int b = p -> burst;
    int prior = p -> priority;
    int arr = p -> arrive_time;
    int life[] = p -> lifecycle;

    strcat(i, procToString);
    strcat(n, procToString);
    strcat(b, procToString);
    strcat(prior, procToString);
    strcat(arr, procToString);
    strcat(life, procToString);
}