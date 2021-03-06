
# Practica-FP-II

## Estructura principal:

![estructura_principal](https://i.imgur.com/0DroeAv.png)

## Estructura ficheros:

![imagen](https://user-images.githubusercontent.com/54553754/116708462-06f5dd00-a9d0-11eb-9c1b-556671bb6f49.png)


## Enunciado:

Quan s'inicia el programa, ha d’aparèixer un menú amb les següents opcions:

    1 Afegir alumne
    2 Buscar per: DNI o Nom
    3 Mostrar llista Alumnes
    4 Veure últim alumne buscat
    5 Eliminar últim alumne buscat
    6 Guardar llista Alumnes en Fitxer
    7 Recuperar llista Alumnes de Fitxer
    0 Sortir

El programa mantindrà en tot moment un llistat a memòria amb els alumnes que s’han anat afegint.
Cada alumne tindrà la següent informació:

    - Nom complet de l’alumne
    - NIF (número i lletra)
    - Correu electrònic
    - Nota (per exemple, 9.3)
    - Data de naixement (dia, mes i any)
    - Sexe : (home, dona, prefereix no declarar-ho, qualsevol altra que considereu adient...) {Penseu bé quin tipus de dada fareu servir.}

L’opció **Afegir alumne** demanarà totes les dades de l’alumne a l’usuari i l’afegirà al llistat. Cal que
aquest llistat es mantingui sempre ordenat per número de DNI, per tant, a l’hora d’inserir, caldrà
inserir-lo en el lloc adient. Cal també comprovar que no existeix ja un alumne amb aquest número
de DNI.
Cal tenir en compte que no podem fer cap suposició sobre la quantitat màxima d’alumnes que
podem tenir. Aquesta quantitat, en tot cas, pot veure’s limitada per la memòria RAM de l’ordinador.
Cal controlar el cas que no es pugui afegir un alumne per falta de memòria.

L'opció **Buscar per DNI** buscarà en el llistat si existeix un alumne amb el DNI especificat. En cas
de trobar-lo, s’informarà del nom de l’alumne. En cas de no trobar-lo, ho indicarà mitjançant un
missatge per pantalla. En introduir un DNI (ja sigui per fer una cerca o ja sigui perquè s’està afegint
a un alumne) comprovar que aquest sigui correcte, és a dir, que la lletra es correspon al número
introduït segons l’algorisme del DNI.

L’opció **Buscar per nom** buscarà a un alumne pel seu nom. Cal no distingir entre majúscules i
minúscules. Així mateix es podrà posar només un prefix del nom, de manera que si busquem a
l’alumna MARIA GARCIA, podrem buscar Maria Garcia, Maria o Mari.
En cas que el nom (o prefix) introduït coincideixi amb un sol alumne, s’informarà del nom complet
trobat. En cas que el nom introduït coincideixi amb diversos alumnes, s’informarà del nombre
d’alumnes trobats.

L’opció **Veure últim alumne buscat**, mostrarà totes les dades de l’últim alumne trobat en la darrera
cerca que s’ha fet utilitzant les opcions 2 o 3. En cas que la última cerca no hagués trobat cap
alumne, caldria informar-ho. Així mateix, en cas que la última cerca hagi estat per nom i hagués
trobat més d’un alumne, es mostrarà el primer d’aquests alumnes.
L’opció Eliminar últim alumne mostrarà en primer lloc totes les dades de l’últim alumne trobat en
la darrera cerca i, seguidament, preguntarà a l’usuari si està segur d’eliminar aquest alumne. En
cas de confirmació per part de l’usuari, l’alumne serà eliminat de la llista.

L’opció **Sortir** acabarà el programa. Qualsevol altra opció tornarà a mostrar el menú en finalitzar
