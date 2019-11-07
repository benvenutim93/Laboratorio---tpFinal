#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define dim 20

#define aJugadores "jugadores.bin"
///falta funcion de pagar cuota de un jugador.

typedef struct
{
    int id;
    char nombreYapellido[30];
    char dni[9];
    char direccion[20];
    char telefono[20];
    char deporte[15]; ///que ocupa jugando al deporte
    char categoria[5]; ///anio de nacimiento
    char cuota[15]; /// ultimo mes pago
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

nodo * jugInicLista ();
nodo * jugAgregarPpio(nodo *, nodo * );
int jugID(char []);  ///Obtiene el ID del jugador
jugador jugCrearJugador(char []); ///Pide los datos de un jugador y los ingresa en una estructura jugador
nodo * jugCrearNodoNuevo(char  []); ///Crea un nodo PIDIENDO los datos del jugador.
void mostrarJugador(jugador );
void jugMostrarArchivo(char []); ///Muestra todos los jugadores del archivo.
void jugMesCuota (char []); ///Utiliza la libreria time.h, devuelve el mes de la pc. (utilizado para el pago de cuotas)
void mostrarArreglo (celda [], int );
void mostrarLista (nodo * ); ///Muestra una lista
int validosCelda (celda[]);
void inicCeldasNull (celda  []);
void jugAlArchivo(char [], jugador ); ///Escribe una estructura de jugador en el archivo
int alPrincipio (char [],celda []); ///Ingresa al arreglo de celdas, todos los jugadores que existen en el archivo.
int jugAltaDeporte (celda [], char [],int ); ///Agrega un nuevo jugador al principio de la lista
int jugPosDeporte (celda [], char [], int );///Devuelve la posicion del arreglo de un deporte dado.
int jugAgregarDeporte (celda [], char [],int ); ///agrega un deporte al arreglo de celdas
nodo * crearNodoDesdeJugador (jugador ); ///Crea un nodo con los datos de un jugador ya cargados
int agregarNodoAlArreglo (celda  [],nodo *, int );
int mostrarJugEliminados(celda  [], int ); ///Muestra TODOS los jugadores eliminados Logicamente
int mostrarListaEliminados(nodo * ); ///Muestra los jugadores eliminados de una lista
nodo * jugadorAlta (nodo *, jugador );  ///Da de alta un jugador que estaba eliminado
nodo * buscarJugadorNombreArreglo (celda [],int, char  []);
nodo * buscarJugadorNombreLista (nodo *, char  []);
nodo * buscarJugadorPorDniArreglo (celda [], int, char[]);
nodo * buscarJugadorPorDniLista (nodo *, char[]);
nodo * jugadorBaja (nodo *, jugador );
int mostrarJugadoresHabilitados (celda  [], int );
int mostrarListaHabilitados (nodo * );
nodo * modificarJugador (nodo *);
nodo * buscarYmodificarJugador (celda[], int, char []);
nodo * pagoCuota (nodo *);
void alFinal (char  [], celda [], int ); ///Carga al archivo todos los jugadores del arreglo


#endif // JUGADOR_H_INCLUDED
