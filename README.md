
# Act07 - Schsim

Aquest repositori forma part d'una pràctica de l'Assignatura de Sistemes Operatius de l'universitat de Lleida al campus d'Igualada.

En aquest projecte tractem el càlcul de la gestió de recursos que fa servir un computador 
de forma eficient amb els modes següents:
-   FCFS (FIFO o Cola, el primer en arribar és el primer en executar).
- SJF (Shortest Job First).
- RR (Round Robin).
- PRIORITIES (Treballa amb escala de prioritat per cada un dels processos).







## Usage:

Per a fer servir aquest projecte només necessites importar-lo al teu ordinador i dins del terminar executar el següent:

make

./schsim -a fcfs -m nonpreemptive -f ./process.csv -v

Aquest projecte agafa la informació del fitxer process.csv, per tant, es pot canviar la informació que posa i poder calcular les teves taules.

## Authors

- [@RickyBP](https://github.com/RickyBP)
- [@JoanBonell](https://github.com/JoanBonell)




## Optimizaticions: Activitat 1

Canvis de color, ara al imprimir una taula de gestió de recursos, diferencia els processos que estan parats amb color vermell, els que estan en execució en color verd i els que estan esperant en color groc.

## Logs: Activitat 2

No hem fet aquest apartat encara.

## Mètode toString(): Activitat 3

Hem afegit l'Activitat 3 en l'arxiu process.c en el mètode següent, per a imprimir correctament com ens demanava la pràctica.


Deixem el codi aqui també:

char* procToString(Process* p){

    char* str = malloc(sizeof(char)*100);
    sprintf(str, "{id:%d; name:%s; burst:%d; priority:%d; arrive_time:%d; lifecycle:[%ls]; ...}", p->id, p->name, p->burst, p->priority, p->arrive_time, p->lifecycle);
    return str;
}


## Fix Bugs: Activitat 4

Després de buscar durant molt de temps l'error que hi havia, que es veia clar que faltava fer un free en algun lloc,
tractant-se d'un procés ja que els bytes que ocupava un procès era de 56 bytes i justament teniem 3 processos per eliminar.

Hem trobat el punt on feia falta, es tractava de l'arxiu process.c

En la funció cleanProcess(Process process);
Només es tenia en compte que si el nom del procès era nul ens eliminés aquest procès de la memòria,
però no teniem en compte que si la seva "lifecycle" s'havia acabat, per tant era nul, no la eliminavem.

Per tant, hem afegit a la funció el següent:


void cleanProcess(Process proces){

    if (proces.name != NULL){
        free(proces.name);
    }
    // El que hem afegit:
    if(proces.lifecycle != NULL){
        free(proces.lifecycle);
    }
};

## Round Robin: Activitat 5

Per a fer l'algoritme de Round Robin, necessitavem una cua que comparés el temps d'arribada tenint l'afegit d'un quantum que tractés el procès.

Hem creat una nova funció dins del fitxer process.c

Es tracta de la següent funció:

int compareArrivalWithQuantum(const void *s1, const void *s2);

## ReadMe.md: Activitat 6.

Fer aquest ReadMe és l'activitat 6.
