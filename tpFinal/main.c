#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
///Porcentaje de deudores en mes "x".
///buscar jugador por ID en arbol.
///pasar todos a un arbol, y despues dividirlo en el arreglo de listas.

typedef struct
{
    int id;
    char nombreYapellido[30];
    char dni[9];
    char direccion[20];
    char telefono[20];
    char posicion[15]; ///que ocupa jugando al deporte
    char cuota[20]; /// ultimo mes pago
    int eliminado; ///1 eliminado, 0 listo para usar.
} jugador;

typedef struct nodo
{
    jugador player;
    struct nodo * sig;
} nodo;

typedef struct
{
    char deporte [20];
    struct nodo * lista;
} celda;
typedef struct
{
    int id;
    char nombreYapellido [30];
    char dni[9];
    char direccion[20];
    char telefono[20];
    char deporte[20]; ///que da el profesor.
    int eliminado; ///1 elimado, 0 listo para usar

}entrenador;

int main()
{
    char jugadores[] = "jugadores.bin";
    char deportes [] = "deportes.bin";
    char entrenadores [] = "entrenadores.bin";
    char admin [] = "admin.bin";
    return 0;
}
nodo * inicLista()
{
    return NULL;
}
nodo * agregarPpio (nodo * lista, nodo * nn);
{
    if (lista != NULL)
        nn->sig=lista;
    lista=nn;
    return lista;
}
jugador buscarJugadorNombre (nodo * lista, char nombre[], char archivo[])
{
    FILE * archi = fopen(archivo,"rb");
    jugador a;
    while (fread(&a,sizeof(jugador),1,archi)>0)
    {

    }
}
