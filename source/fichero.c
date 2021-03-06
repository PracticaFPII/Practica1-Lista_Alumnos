#include <stdio.h> /*Libreria para escribir y leer, printf(); - scanf();*/
#include <stdlib.h> /* Libreria para usar funciones generales como malloc(); y free */
#include <stdbool.h> /*Libreria booleano, bool*/

/** Incluimos la libreria "alumnos.h" **/
#include "../headers/tipos.h"
#include "../headers/funciones.h"


/** Funcion ABRIR fichero **/
void abrir_fichero (nodo_t **lista_p)
{
  /* Variables locales de la funcion */
  FILE *fit_lista;
  alumno_t alumno; /* Variable almacena alumno */
  
  /* Leemos el fichero */
  fit_lista = fopen ("lista_alumnos.out", "rb"); /* Se abre el fichero en modo lectura */
  if (fit_lista == NULL)
  {
    printf("\n La lista esta vacia, se creara una nueva\n");
  }
  else
  {
    fread(&alumno, sizeof(alumno_t), 1, fit_lista); /* Leemos los datos del primer alumno */
    agregar_nodo_principio(lista_p, alumno); /* Agregamos al principio de la lista vacia */

    fread(&alumno, sizeof(alumno_t), 1, fit_lista); /* Leemos los datos del segundo alumno (en el caso de que no exista se salta el bucle) */
    while (!feof(fit_lista))
    {
      agregar_nodo_final(lista_p, alumno); /* Agregamos los alumnos leídos a la lista */
      fread(&alumno, sizeof(alumno_t), 1, fit_lista); /* Leemos los datos de los alumnos */
    }
    printf("\n Se ha cargado la lista de alumnos\n");
    fclose (fit_lista); /* Cerramos el fichero */
  }
}


/** Funcion GUARDAR fichero **/
bool guardar_fichero (nodo_t *lista_p)
{
  /* Variables locales de la funcion */
  FILE *fit_lista;
  bool guardado_check; /* Si se ha guardado correctamente el fichero */
  alumno_t alumno; /* Variable que guarda el valor alumno_t de cada nodo */
  nodo_t *nodo_actual; /* Variable de control que se desplaza por la lista a guardar */

  /* Guardamos el fichero */
  fit_lista = fopen ("lista_alumnos.out", "wb");
  if (fit_lista == NULL)
  {
    guardado_check = false;
    printf ("\n No se ha podido guardar el fichero \n");
  }
  else
  {
    /* Guardamos en el fichero los datos de los alumnos */
    for (nodo_actual = lista_p; nodo_actual != NULL; nodo_actual = nodo_actual->salto) 
    {
      alumno = nodo_actual->alumno; 
      fwrite(&alumno, sizeof(alumno_t), 1, fit_lista); /* Guardamos los datos de los alumnos en binario */
    }
    fclose (fit_lista); /* Cerramos el fichero */
    guardado_check = true;
    printf("\n Se ha guardado la lista de alumnos \n");
  }
  return guardado_check;
}
