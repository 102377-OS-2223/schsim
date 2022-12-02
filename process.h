#define E 0
#define W 1
#define P 2
#define F 3

typedef struct process
{
    char * name;
    int time;
    int burst;
    int id;
    int * life;
} Process;

/* Donat un arxiu processos.csv amb el format:
    0;A;0;7
    Haurà de generar processos. */

Process *procTable;

Process readProcess(); //Fila 1



