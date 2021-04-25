#include <stdio.h> /*Libreria para escribir y leer, printf(); - scanf();*/
#include <stdlib.h> /* Libreria para usar funciones generales como malloc(); y free */
#include <stdbool.h> /*Libreria booleano, bool*/
#include <string.h> /* Libreria para poder usar strcpy() */

/** Incluimos la libreria "alumnos.h" **/
#include "../headers/tipos.h"
#include "../headers/funciones.h"


/*----;;AGREGAR ALUMNO;;-----------------------------------------------------------------------------*/

/** Función para comprobar la fecha introducido en la función "agregar_alumno()" **/
bool comprobar_fecha (fecha_t fecha) {

  bool fecha_valido;

  switch (fecha.mes)
  {
  case 1,3,5,7,8,10,12: //Enero, marzo, mayo, julio, agosto, octubre y diciembre. --> 31 días
    if (fecha.dia > 31 || fecha.dia<0) {
      fecha_valido = true;
    }
    break;
  case 4,6,9,11: //Abril, junio, septiembre y noviembre. --> 30 días
    if (fecha.dia > 30 || fecha.dia<0) {
      fecha_valido = true;
    }
    break;
  case 2: //Frebrero. --> 28/29 días
      if (fecha.dia > 29 || fecha.dia<0) {
        fecha_valido = true;
      } else {
        if (fecha.dia==29 && (fecha.any%400==0 ||(fecha.any%4==0 && fecha.any%100!=0))) {
        } else {
          fecha_valida = true;
        }
      }
    break;
  
  default:
    printf("La fecha no es valido\n");
    break;
  }

  return fecha_valido;
}

/** Función para añadir un alumno **/
bool agregar_alumno (nodo_t **lista)
{
  bool alumno_valido, fecha_valido, texto_valido; 
  alumno_t alumno_aux;
  nodo_t *alumno_dni_rep; /* Almacena el alumno con un dni igual al que se quiere agregar */
  fecha_t fecha_nacimiento_alumno;
  bool salida_dni;

  /* Introducir datos del alumno a agregar */
  
  printf("Nombre del alumno: "); /* Pedimos el nombre */
  scanf(" %s", &alumno_aux.nombre);

  printf("Apellido: "); /* Pedimos el apellido */
  scanf(" %c", &alumno_aux.apellido);

  do { /* Comprobar DNI del alumno */
    salida_dni = buscar_dni (*lista, &alumno_aux.dni.numero, &alumno_aux.dni.letra, &alumno_dni_rep);
    if (salida_dni)
    {
      printf ("Ya existe un alumno con ese DNI en la lista: %s %s", alumno_dni_rep->alumno.nombre, alumno_dni_rep->alumno.apellido);
      printf("Introduce un DNI distinto");
    }
    else
    {
      printf("El DNI se ha guardado correctamente");
    }
  } while (salida_dni);

  printf("Correo electronico: ");
  scanf(" %s", &alumno_aux.email);

  do { /* Comprobar nota del alumno */
    printf("Nota del alumno (por ejemplo, 6.8): ");
    scanf(" %f", &alumno_aux.nota);
  } while (alumno_aux.nota<0 || alumno_aux.nota>10);
  
  do {
    printf("Fecha de nacimiento: (dia, mes y año): ");
    printf("Dia: ");
    scanf("%d ", &fecha_nacimiento_alumno.dia);
    printf("Mes: ");
    scanf("%d ", &fecha_nacimiento_alumno.mes);
    printf("Año: ");
    scanf("%d ", &fecha_nacimiento_alumno.any);

    fecha_valido = comprobar_fecha(fecha_nacimiento_alumno);

  } while (!fecha_valido);
  
  do { /* Comprobar sexo del alumno */
    printf("Sexo (hombre [0], mujer [1] o no quiero decirlo [2]): ");
    scanf("%d ", &alumno_aux.sexo);
  } while (alumno_aux.sexo<0 || alumno_aux.sexo>2);

  /* Llamamos a la función "ordenar alumno", para que agrege al alumno introducido */
  alumno_valido = ordenar_alumno(lista, alumno_aux);    
  
  return alumno_valido;
  
}

/** Función para ordenar el alumno introducido en "agregar_alumno" **/

/*
CASO 1: Lista vacía--> Llamar a "agregar_nodo_principio()"
CASO 2: Si el numero del DNI es más grande al primer nodo--> Llamar a "agregar_nodo_principio()"
CASO 3: Si el numero del DNI es más grande al nodo 'actual', se guarda el nodo 'actual' y en caso del nodo que le siga no es igual a NULL-->  Llamar a "agregar_nodo_entre()"
CASO 4: Si el numero del DNI es más grande al nodo 'actual', se guarda el nodo 'actual' y en caso del nodo que le siga es igual a NULL-->  Llamar a "agregar_nodo_final()"
*/
bool ordenar_alumno (nodo_t **lista_p, alumno_t alumno_aux)
{
  /* Creación de nodos, para almacenar los datos al ordenar */
  nodo_t *nodo = NULL, *temp = NULL;
  nodo = *lista_p;
  
  /* Declaración de variables locales */
  bool sortir;
  int tempvar;
  
  /* Comprobar si la lista esta vacía, en caso afirmativo se llama a la función "..." para añadir el nodo al principio */
  if (comprobar_lista(*lista_p)) {
		agregar_nodo_principio(&lista_p, alumno_aux);
	} else {
    
    /* Asignar al nodo temporal los datos del puntero "lista_p" */
    temp = nodo;
    
    /* Recorre la lista enlazada, para comprobar en que posición de la lista a de añadir el alumno */
    while (/*lista->salto*/nodo != NULL && !sortir) {
      
      /* Comparación del numero del DNI para ordenar la lista */
      if (alumno_aux.dni.numero > temp->alumno.dni.numero) {

        /* Volcado del numero del DNI a la variable temporal "tempvar" */
        tempvar = temp->alumno.dni.numero;

        /* Intercambiar el numero del DNI */
        temp->alumno.dni.numero = temp->salto->alumno.dni.numero;
        temp->salto->alumno.dni.numero = tempvar;

        /* Llamada a las funciones de agragar el nodo (agregar_nodo_principio, agregar_nodo_entre, agregar_nodo_final) */
        // ...CONTINUAR
        
      }
      
      temp = temp->salto;

    }

    nodo = nodo->salto;
    return ;
  }

}

/*---------;;FIN AGREGAR ALUMNO;;-------------------------------------------------------------------------------------------*/

