#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "menu.h"

#define archAdmin "admin.bin"
#define archEntrenador "usuarioEntrenador.bin"

typedef struct
{
    char admin[15];
    char contrasena [15];
} admin;
typedef struct
{
    char usuario[15];
    char contrasena[15];
    int eliminado;
} usuario;

/// ---------------------------------------- E S T A D I S T I C A S --------------------------------------------
int estCantJugadorUNDeporte (nodo * );
int estCantJugadorTotal(celda  [], int );
void estCantJugadoresPorDeporte (celda deportes[], int validos);

int main()
{

    celda deportes [dim];
    int validos=0, pos=0;
    char nombre[30];
    jugador a;

    /*validos= alPrincipio(aJugadores,deportes);
    nodo * aux = jugCrearNodoNuevo(aJugadores);
    validos = agregarNodoAlArreglo(deportes,aux,validos);
    mostrarArreglo(deportes,validos);
    alFinal(aJugadores,deportes,validos);*/
    validos=alPrincipio(aJugadores,deportes);

    //pos= mostrarJugadoresHabilitados(deportes,validos);
    iniciarMenu(deportes,validos,dim);
    //mostrarArreglo(deportes,validos);
    alFinal(aJugadores,deportes,validos);
    return 0;
}


/// ---------------------------------------- E S T A D I S T I C A S --------------------------------------------

int estCantJugadorTotal(celda deportes [], int validos)
{
    int suma=0;
    for (int i=0; i<validos; i++)
    {
        suma+=estCantJugadorUNDeporte(deportes[i].lista);
    }
    return suma;
}

int estCantJugadorUNDeporte (nodo * lista)
{
    int suma;
    if (lista == NULL)
        suma=0;
    else
    {
        if (lista->player.eliminado==0)
            suma = 1 + estCantJugadorUNDeporte(lista->sig);
        else
            suma = 0 + estCantJugadorUNDeporte(lista->sig);
    }
    return suma;
}

///------------------------------------- S I S T E M A - D E - L O G U E O -------------------------------------------
void crearAdmin ()
{
    admin a;
    int repe;
    FILE * archi = fopen (archAdmin, "a+b");
    if (archi != NULL)
    {
        printf ("Ingrese un nombre de usuario \n");
        fflush(stdin);
        gets(a.admin);
        repe = usuarioRepetido(a.admin,archi);
        while (repe !=0)
        {
            printf ("El nombre ingresado ya se encuentra en uso, ingrese uno nuevo \n");
            fflush(stdin);
            gets(a.admin);
            repe=adminRepetido(a.admin,archi);
        }
        printf ("Ingrese contrasena (maximo 15 caracteres)\n");
        fflush(stdin);
        gets(a.contrasena);
        fwrite (&a,sizeof(admin),1,archi);
        fclose(archi);
    }
}
int adminRepetido (char nombre[], FILE * archi)
{
    admin a;
    int flag=0;
    fseek(archi,0,0);
    while (fread(&a,sizeof(admin),1,archi)>0 && flag ==0)
    {
        if (strcmp(a.admin,nombre)==0)
            flag=1;
    }
    return flag;
}
void crearUsuarioEntrenador ()
{
    usuario a;
    int repe;
    FILE * archi = fopen (archEntrenador, "a+b");
    if (archi != NULL)
    {
        printf ("Ingrese un nombre de usuario \n");
        fflush(stdin);
        gets(a.usuario);
        repe = usuarioRepetido(a.usuario,archi);
        while (repe !=0)
        {
            printf ("El nombre ingresado ya se encuentra en uso, ingrese uno nuevo \n");
            fflush(stdin);
            gets(a.usuario);
            repe=usuarioRepetido(a.usuario,archi);
        }
        printf ("Ingrese contrasena (maximo 15 caracteres)\n");
        fflush(stdin);
        gets(a.contrasena);
        a.eliminado=0;
        fwrite (&a,sizeof(usuario),1,archi);
        fclose(archi);
    }
}
int usuarioRepetido (char nombre[], FILE * archi)
{
    usuario a;
    int flag=0;
    fseek(archi,0,0);
    while (fread(&a,sizeof(usuario),1,archi)>0 && flag ==0)
    {
        if (strcmp(a.usuario,nombre)==0)
            flag=1;
    }
    return flag;
}

void estCantJugadoresPorDeporte (celda deportes[], int validos)
{
    int i=0, cant=0;
    while (i<validos)
    {
        cant=estCantJugadorUNDeporte(deportes[i].lista);
        printf ("DEPORTE %s , hay %d jugadores\n", deportes[i].deporte, cant);
        cant=0;
        i++;
    }
}
