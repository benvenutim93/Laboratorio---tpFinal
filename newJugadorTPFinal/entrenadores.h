#ifndef ENTRENADORES_H_INCLUDED
#define ENTRENADORES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define CUOTA 700

typedef struct
{
    int id;
    char nombreYapellido [30];
    char dni[9];
    char direccion[20];
    char telefono[20];
    char deporte[20]; ///que da el profesor.
    int eliminado; ///1 elimado, 0 listo para usar
} entrenador;

typedef struct arbolEntrenador
{
    entrenador coach;
    struct arbolEntrenador* der;
    struct arbolEntrenador* izq;
} arbolEntrenador;

typedef struct
{
    char deporte [20];
    struct nodo * lista;
} celda;

arbolEntrenador* inicArbol();
int entId();///devuelve el id del nodo a crear
entrenador crearEntrenador();
arbolEntrenador* Pasaje_Archivo_Arbol(arbolEntrenador*);///pasa los entrenadores del archivo, los convierte en nodo arbol , y los agrega al arbol
arbolEntrenador* agregarArbolEntrenador(arbolEntrenador*, arbolEntrenador *);///agrega al arbol los DT(esta dentro de la funcion Pasaje_Archivos_Arbol)
void mostrarPreOrder(arbolEntrenador*);///muestra el arbol, primero muestra la raiz
void Cargar_Archivo_Entrenador();///crea un entrenador y lo guarda en el archivo
void mostrarArchivo();///muestra el archivo de entrenadores
void mostrarEntrenador(entrenador);///muestra un entrenador
void mostrar_deporte_entrenador(char[],celda[],arbolEntrenador*);///muestra toda la lista de jugadores del deporte de un entrenador
arbolEntrenador* buscarEntrenador(char[],arbolEntrenador*);///busca un entrenador en el arbol, por el nombre
arbolEntrenador* alta_entrenador(arbolEntrenador*,char[]);///da de alta a un entrenador (lo pone en 0)
arbolEntrenador* baja_entrenador(arbolEntrenador*,char[]);///da de baja a un entrenador (lo pone en 1)
arbolEntrenador* modificar_entrenador(arbolEntrenador*, char[]);///modifica NOMBRE, TEL, DIRECCION Y DEPORTE
entrenador pasaje_arbol_entrenador(arbolEntrenador* lito);///crea un entrenador, pasandole un arbol
void pasaje_arbol_archivo(arbolEntrenador*,FILE*);///pasa el arbol, con todas las modificaciones, al archivo, borrando el archivo anterior,y dejando el nuevo
void puntero_archivo(arbolEntrenador*);///crea un FILE* y se lo pasa a la funcion pasaje_arbol_archivo
int cantidad_total_de_entrenadores(arbolEntrenador*);
int cantidad_de_entrenadores_de_un_deporte(arbolEntrenador*,char[]);
int calcular_sueldo_entrenador(celda[],char[],arbolEntrenador*);
void mesActual(char[]);
int logueoAdmin();
int logueoEntrenador();
#endif // ENTRENADORES_H_INCLUDED
