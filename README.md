# schsim descripción
schsim es un simulador de procesos de planificación de procesos. El objetivo de este proyecto es proporcionar una herramienta de simulación para ayudar y comprender los conceptos de planificación de procesos. 



# Ejecución
schsim se puede ejecutar a través de la línea de comandos:
```
./schsim -a fcfs -m preemptive -f ./process.csv

-a: algoritmo de planificación de procesos
-m: modo de planificación de procesos
-f: archivo de entrada
```
# Uso
schsim se puede usar para simular varios algoritmos de planificación de procesos. Los algoritmos de planificación de procesos que se pueden simular son:
* FCFS
* SJF
* RR
* Priority


# Ejemplo
schsim se puede usar para simular el algoritmo de planificación de procesos FCFS. El siguiente ejemplo muestra cómo simular el algoritmo de planificación de procesos FCFS con 3 procesos. El archivo de entrada se llama "process.csv". El archivo de entrada contiene los detalles de los procesos que se van a simular. Cada línea del archivo de entrada contiene los detalles de un proceso. Los detalles de un proceso se componen de 5 campos separados por ";". 

-El primer campo es el tiempo de llegada del proceso. 
-El segundo campo es el nombre del proceso. 
-El tercer campo es el tiempo de servicio del proceso.
-El cuarto campo es el tiempo de espera del proceso.
-El quinto campo es el tiempo de respuesta del proceso.


El siguiente ejemplo muestra el contenido del archivo de entrada "process.csv":
```
1;B;1;2;4
2;C;6;3;2
0;A;5;0;7
```









