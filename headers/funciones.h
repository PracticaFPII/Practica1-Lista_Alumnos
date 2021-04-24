#pragma once 
#include <stdbool.h>

/** Cabeceras de los procedimientos usados por el programa **/
/*--------------------------------------------------------------------*/

/* Funciones NODO */
void iniciar_lista(nodo_t **lista);
bool comprobar_lista (nodo_t *lista);
void agregar_nodo_principio (nodo_t **lista,alumno_t alumno);
void agregar_nodo_entre (nodo_t *lista, alumno_t alumno/*, nodo_anterior*/);
void agregar_nodo_final(nodo_t **lista_p, alumno_t alumno_datos);


/*Funciones FICHEROS */
bool abrir_fichero(nodo_t **lista_p);
bool guardar_fichero(nodo_t *lista_p);


/* Funcion AGREGAR_ALUMNOS */
bool agregar_alumno (alumno_t *alumno, nodo_t **lista);
bool ordenar_alumno (nodo_t **p_lista, alumno_t alumno_aux, alumno_t *alumno);
void agregar_nodo (nodo_t *lista/*,datos*/);


/* Funciones BUSCAR */
bool comprobar_letra (int numero_dni, char letra_dni);
bool buscar_dni (nodo_t *lista, int *numero_dni, char *letra_dni, nodo_t **ultimo_alumno);
bool comparar_dni (nodo_t *lista, int numero_dni, char letra_dni, nodo_t **ultimo_alumno);
bool comparar_nombre (char nombre_buscado[], char nombre_nodo[]);
int buscar_nombre (nodo_t *lista, nodo_t **alumno_buscada);


/* Funciones VER_ELIMINAR */
bool ver_alumno(nodo_t *p_ultimo_alum);
void buscar_nodo (nodo_t *lista, nodo_t *nodo_buscar, nodo_t **nodo_previo);
void eliminar_alumno(nodo_t **p_lista, nodo_t **p_ultimo_alum);