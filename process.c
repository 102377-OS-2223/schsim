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
            size_t len = strlen(feature);
            switch (features)
            {
            case 0:
                p.id=atoi(feature);
                break;
            case 1:
                p.name = malloc(len + 1);
                strcpy(p.name, feature);
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

char* procToString(Process* p){

    if (p == NULL){
        printf("Error: puntero p es NULL\n");
        return NULL;
    }

    if (p->lifecycle == NULL || strlen(p->lifecycle) == 0) {
        printf("Error: campo lifecycle es NULL o tiene longitud cero.\n");
        return NULL;
    }
    // determinar el tamaño de la cadena que necesitamos asignar
    size_t tamaño_requerido = snprintf(NULL, 0, "{id:%d; name:%s; burst:%d; priority:%d; arrive_time:%d; lifecycle:[%s]}", p->id, p->name, p->burst, p->priority, p->arrive_time, p->lifecycle);
    // asignar el espacio requerido, más uno para el terminador nulo
    char* cadena = malloc(tamaño_requerido + 1);
    // imprimir la información en el espacio asignado
    sprintf(cadena, "{id:%d; name:%s; burst:%d; priority:%d; arrive_time:%d; lifecycle:[%s]}", p->id, p->name, p->burst, p->priority, p->arrive_time, p->lifecycle);
    // devolver la cadena
    return cadena;
}


//@TODO: Aquesta funció ha de retorna un cadena de text amb la següent info:
//{id:0; name:A; burst:7; priority:9; arrive_time:0; lifecycle:[EEEPPEF]; ...} 
/* char* procToString(Process* p){

}*/