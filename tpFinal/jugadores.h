#ifndef JUGADORES_H_INCLUDED
#define JUGADORES_H_INCLUDED
#include <strings.h>

#define ArchJugadores "jugadores.bin" ///ARCHIVO JUGADORES


///estructura y lista de jugadores con prototipado de funciones relacionadas.

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

typedef struct nodoJugador
{
    jugador dato;
    struct nodoJugador * sig;
} nodoJugador;

#endif // JUGADORES_H_INCLUDED
