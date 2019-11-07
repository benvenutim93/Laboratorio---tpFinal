#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <stdio.h>
#include "jugador.h"


void imprimirCabecera(char cabecera[]);
void imprimirOpcionesSubMenuADMIN();
void imprimirOpcionesMenuPrincipal();
int ingresarOpcion();
void switchSubMenuADMIN();
int switchMenuPrincipal(celda[],int,int);
void iniciarMenu(celda[], int, int);
void imprimirOpcionesSubMenuENTRENADOR();
int switchSubMenuENTRENADOR();
void imprimirOpcionesSubMenuAdminJugador ();
int switchSubMenuAdminJugador(celda[],int,int);
void imprimirOpcionesSubMenuAdminEntrenador();
int switchSubMenuAdminEntrenador(celda[],int,int);
void imprimirOpcionesSubMenuAdminEstadistica();
int switchSubMenuAdminEstadistica(celda[],int,int);
void imprimirOpcionesBuscarJugador ();
int switchOpcionesBuscarJugador(celda[],int,int);


#endif // MENU_H_INCLUDED
