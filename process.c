#include <stdio.h>
#include <stdlib.h>
#include "process.h"

void printProcess(Process proces){
    printf("{id:%d, name:%s, arrive_time:%d, burst:%d}\n", proces.id,proces.name,proces.time,proces.burst);
}

void cleanProcess(Process proces){

    if (proces.name != NULL){
        free(proces.name);
    }
};