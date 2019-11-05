#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "jugador.h"


/// ---------------------------------------- E S T A D I S T I C A S --------------------------------------------
int estCantJugadorPorDeporte (nodo * );
int estCantJugadorTotal(celda  [], int );

int main()
{

    celda deportes [dim];
    int validos=0, pos=0;
    char nombre[30];
    jugador a;

    /*jugador a = jugCrearJugador(jugadores);
    jugAlArchivo(jugadores,a);
    jugador b = jugCrearJugador(jugadores);
    jugAlArchivo(jugadores,b);
    jugador c = jugCrearJugador(jugadores);
    jugAlArchivo(jugadores,c);
    jugMostrarArchivo(jugadores);
    */

    validos = alPrincipio(aJugadores,deportes);
    mostrarArreglo(deportes,validos);

    /*system("pause");
    system("cls");
    mostrarJugadoresHabilitados(deportes,validos);
    printf("Que jugador desea dar de baja? \n");
    fflush(stdin);
    gets(nombre);
    a = buscarJugadorNombreArreglo(deportes,validos,nombre);
    mostrarJugador(a);
    pos = jugPosDeporte(deportes,a.deporte,validos);
    printf ("pos: %d", pos);
    deportes[pos].lista=jugadorBaja(deportes[pos].lista,a);
    system ("pause");
    mostrarLista(deportes[pos].lista);
    alFinal(jugadores,deportes,validos);
    jugMostrarArchivo(jugadores);

    */
    return 0;
}


/// ---------------------------------------- E S T A D I S T I C A S --------------------------------------------

int estCantJugadorTotal(celda deportes [], int validos)
{
    int suma=0;
    for (int i=0; i<validos; i++)
    {
        suma+=estCantJugadorPorDeporte(deportes[i].lista);
    }
    return suma;
}

int estCantJugadorPorDeporte (nodo * lista)
{
    int suma;
    if (lista == NULL)
        suma=0;
    else
    {
        if (lista->player.eliminado==0)
            suma = 1 + estCantJugadorPorDeporte(lista->sig);
        else
            suma = 0 + estCantJugadorPorDeporte(lista->sig);
    }
    return suma;
}
