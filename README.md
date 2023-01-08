# schsim

### 1 Lectura de codi

Reviseu el codi del repositori. Un cop enteneu el funcionament heu de fer una aportació que millori algun aspecte del codi. Aquesta millora s’ha de presentar com un commit on en la descripció del commit s’explica que esteu millorant. També cal comentar-ho al codi per deixar clar la millora aportada.

### Resposta

Vam pensar que ficant una gamma de colors als procesos faria que fossin més reconeixibles. Així que vam importar els colors vermell per a quan es bloquegi el proces, blau per a quan acabi, verd per a quan executi i blanc per a que retorni al color original. Diem això perque vam trobar que que si no es retornaba al color inicial la terminal sencera cambiaba de color.

A més d'això altre problema que ens varem trobar va ser que la taula mostrada al terminal es descompensaben les columnes amb aquests cambis de colors, així que vam haber de restar un espai a cada missatge, ja que els color compten com a un bit més.

### 2 Logs

Implementeu utilitzant els logs el mode verbose (-v). Aquest mode ha d’explicar pas a pas el funcionament de la simulació i mostrant la taula de processos actuals en cada instant de temps.

### Resposta

Per a implementar el mode verbose ens vam trobar amb que per a que impremés el missatge de running en funció de l'algorisme utilitzat vam haber de fer un if en funció de l'algorisme, el vam fer per a fcfs, priorities i sjf. Després per al sorting vam haber de trobar quan n'hi arriba.

Quan s'encua un proces, vam fer que manés el missatge a més de la taula de processos en aquell moment. Quan s'acaba un proces fem que digui que s'ha acabat, a més de dir-ne que ara ha sigut desbloquejat un proces. I fem que ens vagi dient si n'hi ha procesos en cua esperant.

Quan s'acabin tots els processos enviarà un missatge dient que s'està acabant en funció de l'algorisme utilitzat (això és posible gràcies a un if en funció dels algorismes). I com a últim missatge ens enviarà que s'està netejant.

### 3 ToString

Implementeu la funció marcada amb TODO. Aquesta funció ha de retornar una cadena de text a partir de la informació de l’estructura procés. Es presenta com un commit independent.

### Resposta

El que farem serà agafar-ne els diferents atributs del proces i concatenar-los a un string. Això oho farem gràcies a la funció strcat. El problema que ens vam trobar va ser que name per exemple, és un caràcter no un integer, així que hem de tractar-lo com a tal.