#include "menu.h"

///Funcion generica para mostrar una cabecera con un recuadro
void imprimirCabecera(char cabecera[])
{
    int i;
    printf("%c", 201);
    for(i=0; i<50; i++)
    {
        printf("%c",205);
    }
    printf("%c\n", 187);
    printf("%c%32s%19c\n", 186,cabecera,186);
    printf("%c", 200);
    for(i=0; i<50; i++)
    {
        printf("%c",205);
    }
    printf("%c", 188);
}



void imprimirOpcionesMenuPrincipal()
{
    printf("1. LOGUEO ADMIN\n");
    printf("2. LOGUEO ENTRENADOR\n");
    printf("0. SALIR\n");
}
void iniciarMenu(celda deportes[], int validos, int dimension)
{
    int salida;
    do
    {
        system("cls");
        imprimirCabecera("MI MENU PRINCIPAL");
        printf("\n\n");
        imprimirOpcionesMenuPrincipal();
        salida = switchMenuPrincipal(deportes,validos,dimension);
    }
    while(salida != 0);
}

int ingresarOpcion()
{
    int opcion;
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%i", &opcion);
    return opcion;
}
void imprimirOpcionesSubMenuADMIN()
{
    printf("1. JUGADORES\n");
    printf("2. ENTRENADORES\n");
    printf("3. ESTADISTICAS\n");
    printf("4. USUARIOS DEL SISTEMA\n");
    printf("0. SALIR\n");
}

void switchSubMenuADMIN(celda deportes[], int validos, int dimension)
{
    int op;
    do
    {
        op = ingresarOpcion();
        switch(op)
        {
        case 0:
            system ("cls");
            imprimirCabecera("MI MENU PRINCIPAL");
            printf ("\n\n");
            imprimirOpcionesMenuPrincipal();
            switchMenuPrincipal(deportes,validos,dimension);
        case 1: ///Dependiendo de lo que se necesite en cada case se puede llamar a un submenu o a una funcion en especifico
            system ("cls");
            imprimirCabecera("JUGADORES");
            printf ("\n\n");
            imprimirOpcionesSubMenuAdminJugador();
            switchSubMenuAdminJugador(deportes,validos,dimension);
            system("pause");
            break;
        case 2:
            system ("cls");
            imprimirCabecera("ENTRENADORES");
            printf ("\n\n");
            imprimirOpcionesSubMenuAdminEntrenador();
            switchSubMenuAdminEntrenador(deportes,validos,dimension);
            system("pause");
            break;
        case 3:
            system ("cls");
            imprimirCabecera("ESTADISTICAS");
            printf ("\n\n");
            imprimirOpcionesSubMenuAdminEstadistica();
            switchSubMenuAdminEstadistica(deportes,validos,dimension);
            system("pause");
            break;
        case 4:
            system ("cls");
            imprimirCabecera("USUARIOS DEL SISTEMA");
            printf ("\n\n");
            printf("Ingreso a la opcion 4 del Submenu 1\n");
            system("pause");
            break;
        default:
            printf("Opcion incorrecta\n");
        }
    }
    while(op != 0);
}

int switchMenuPrincipal(celda deportes[], int validos, int dimension)
{
    int op;
    do
    {
        op = ingresarOpcion();
        switch(op)
        {
        case 0:
            printf("Saliendo del sistema\n");
            exit(0);
            break;
        case 1:
            system("cls");
            imprimirCabecera("ADMIN");
            printf("\n\n");
            imprimirOpcionesSubMenuADMIN();
            switchSubMenuADMIN(deportes,validos, dimension);
            break;
        case 2:
            system("cls");
            imprimirCabecera("ENTRENADORES");
            printf("\n\n");
            imprimirOpcionesSubMenuENTRENADOR();
            switchSubMenuENTRENADOR();
            break;
        default:
            printf("Opcion incorrecta\n");

        }
    }
    while(op != 0);
    return op;
}


void imprimirOpcionesSubMenuENTRENADOR()
{
    printf("1. IMPRIMIR PLANILLAS DE JUGADORES\n");
    printf("2. VER ESTADO CUOTA DE JUGADORES\n");
    printf("3. SALIR\n");
}
int switchSubMenuENTRENADOR(celda deportes[], int validos, int dimension)
{
    int op;
    do
    {
        op = ingresarOpcion();
        switch(op)
        {
        case 0:
            system ("cls");
            imprimirCabecera("MI MENU PRINCIPAL");
            printf ("\n\n");
            imprimirOpcionesMenuPrincipal();
            switchMenuPrincipal( deportes, validos, dimension);
        case 1:
            system("cls");
            imprimirCabecera("IMPRIMIR PLANILLA DE JUGADORES");
            printf("\n\n");

            break;
        case 2:
            printf("VER ESTADO CUOTA DE JUGADORES\n");
            system("pause");
            break;

        }
    }
    while(op != 0);
    return op;
}
void imprimirOpcionesSubMenuAdminJugador ()
{
    printf("1. NUEVO JUGADOR\n");
    printf("2. ALTA JUGADOR\n");
    printf("3. BAJA JUGADOR\n");
    printf("4. BUSCAR JUGADOR\n");
    printf("5. LISTADO POR DEPORTE DE JUGADORES\n");
    printf("6. LISTADO DE TODOS LOS JUGADORES\n");
    printf("7. MODIFICAR JUGADOR\n");
    printf("0. SALIR\n");
}
int switchSubMenuAdminJugador(celda deportes[], int validos, int dimension)
{
    char alta [30], baja[30];
    int op, pos, cant;
    nodo * aux;
    do
    {
        op = ingresarOpcion();
        switch(op)
        {
        case 0:
            system("cls");
            imprimirCabecera("ADMIN");
            printf ("\n\n");
            imprimirOpcionesSubMenuADMIN();
            switchSubMenuADMIN( deportes,  validos,  dimension);
            break;
        case 1:
            system("cls");
            imprimirCabecera("NUEVO JUGADOR");
            printf("\n\n");
            aux = jugCrearNodoNuevo(aJugadores);
            validos = agregarNodoAlArreglo(deportes,aux,validos);
            system("pause");
            system("cls");
            imprimirCabecera("ADMIN");
            printf ("\n\n");
            imprimirOpcionesSubMenuADMIN();
            switchSubMenuADMIN( deportes,  validos,  dimension);
            break;
        case 2:
            system("cls");
            imprimirCabecera("ALTA JUGADOR");
            printf ("\n\n");
            cant = mostrarJugEliminados(deportes,validos);
            if (cant == 0)
            {
                printf ("No hay jugadores disponibles para ser dados de alta\n");
            }
            else
            {
                printf ("Ingrese el nombre del jugador a dar de alta \n");
                fflush (stdin);
                gets (alta);
                aux = buscarJugadorNombreArreglo(deportes,validos,alta);
                pos = jugPosDeporte(deportes,aux->player.deporte, validos);
                aux =jugadorAlta(deportes[pos].lista, aux->player);
                printf ("El jugador fue dado de alta\n");
                mostrarJugador(aux->player);
            }
            system("pause");
            system("cls");
            imprimirCabecera("ADMIN");
            printf ("\n\n");
            imprimirOpcionesSubMenuAdminJugador();
            switchSubMenuAdminJugador(deportes,  validos,  dimension);
            break;
        case 3:
            system("cls");
            imprimirCabecera("BAJA JUGADOR");
            printf("\n\n");
            cant = mostrarJugadoresHabilitados(deportes,validos);
            if (cant == 0)
                printf ("No hay jugadores disponibles para ser dados de baja\n");
            else
            {
                printf ("Ingrese el nombre del jugador a dar de baja \n");
                fflush (stdin);
                gets (baja);
                aux = buscarJugadorNombreArreglo(deportes,validos,baja);
                pos = jugPosDeporte(deportes,aux->player.deporte, validos);
                aux =jugadorBaja(deportes[pos].lista, aux->player);
                printf ("El jugador fue dado de baja\n");
                mostrarJugador(aux->player);
            }
            system("pause");
            system("cls");
            imprimirCabecera("ADMIN");
            printf ("\n\n");
            imprimirOpcionesSubMenuAdminJugador();
            switchSubMenuAdminJugador(deportes,  validos,  dimension);
            break;
        case 4:
            system("cls");
            imprimirCabecera("BUSCAR JUGADOR");
            printf("\n\n");
            imprimirOpcionesBuscarJugador ();
            switchOpcionesBuscarJugador(deportes,validos,dimension);
            break;
        case 5:
            system("cls");
            imprimirCabecera("LISTA POR DEPORTE");
            printf("\n\n");
            printf ("De que deporte desea ver los jugadores?\n");
            fflush(stdin);
            gets(alta);
            pos = jugPosDeporte(deportes,alta,validos);
            if (pos == -1)
                printf ("El deporte buscado no se encuentra \n");
            else
            {
                printf ("DEPORTE:");
                puts (deportes[pos].deporte);
                mostrarLista(deportes[pos].lista);
            }
            system("pause");
            system("cls");
            imprimirCabecera("ADMIN");
            printf ("\n\n");
            imprimirOpcionesSubMenuAdminJugador();
            switchSubMenuAdminJugador(deportes,  validos,  dimension);
            break;
        case 6:
            system("cls");
            imprimirCabecera("MOSTRAR TODOS LOS JUGADORES");
            printf("\n\n");
            mostrarArreglo(deportes,validos);
            system("pause");
            system("cls");
            imprimirCabecera("ADMIN");
            printf ("\n\n");
            imprimirOpcionesSubMenuAdminJugador();
            switchSubMenuAdminJugador(deportes,  validos,  dimension);
            break;
        case 7:
            system("cls");
            imprimirCabecera("MODIFICAR JUGADOR");
            printf("\n\n");
            printf ("Ingrese el nombre del jugador a modificar \n");
            fflush(stdin);
            gets(baja);
            aux = buscarYmodificarJugador(deportes,validos,baja);
            printf ("Mostrando jugador modificado: \n");
            mostrarJugador(aux->player);
            system("pause");
            system("cls");
            imprimirCabecera("ADMIN");
            printf ("\n\n");
            imprimirOpcionesSubMenuAdminJugador();
            switchSubMenuAdminJugador(deportes,  validos,  dimension);
            break;
        }
    }
    while(op != 0);
    return op;
}
void imprimirOpcionesSubMenuAdminEntrenador()
{
    printf("1. NUEVO ENTRENADOR\n");
    printf("2. ALTA ENTRENADOR\n");
    printf("3. BAJA ENTRENADOR\n");
    printf("4. MODIFICAR ENTRENADOR\n");
    printf("5. MOSTRAR LISTA DE ENTRENADORES\n");
    printf("0. SALIR\n");
}
int switchSubMenuAdminEntrenador(celda deportes[], int validos, int dimension)
{
    int op;
    do
    {
        op = ingresarOpcion();
        switch(op)
        {
        case 0:
            system("cls");
            imprimirCabecera("ADMIN");
            printf ("\n\n");
            imprimirOpcionesSubMenuADMIN();
            switchSubMenuADMIN(deportes, validos, dimension);
            break;
        case 1:
            system("cls");
            imprimirCabecera("NUEVO ENTRENADOR");
            printf("\n\n");
            break;
        case 2:
            imprimirCabecera("ALTA ENTRENADOR\n");
            system("pause");
            break;
        case 3:
            system("cls");
            imprimirCabecera("BAJA ENTRENADOR");
            printf("\n\n");
            break;
        case 4:
            system("cls");
            imprimirCabecera("MODIFICAR ENTRENADOR");
            printf("\n\n");
            break;
        case 5:
            system("cls");
            imprimirCabecera("MOSTRAR LISTA DE ENTRENADORES");
            printf("\n\n");
            break;
        }
    }
    while(op != 0);
    return op;
}
void imprimirOpcionesSubMenuAdminEstadistica()
{
    printf("1. CANTIDAD JUGADORES TOTAL\n");
    printf("2. CANTIDAD JUGADORES POR DEPORTE\n");
    printf("3. CANTIDAD DE ENTRENADORES TOTAL\n");
    printf("4. CANTIDAD DE ENTRENADORES POR DEPORTE\n");
    printf("5. CANTIDAD DE DEPORTES\n");
    printf("6. CALCULO DE SUELDO DE UN ENTRENADOR\n");
    printf("0. SALIR\n");
}
int switchSubMenuAdminEstadistica(celda deportes[], int validos, int dimension)
{
    int op, cant;
    do
    {
        op = ingresarOpcion();
        switch(op)
        {
        case 0:
            system("cls");
            imprimirCabecera("ADMIN");
            printf ("\n\n");
            imprimirOpcionesSubMenuADMIN();
            switchSubMenuADMIN(deportes,validos,dimension);
        case 1:
            system("cls");
            imprimirCabecera("CANTIDAD JUGADORES TOTAL");
            printf("\n\n");
            cant = estCantJugadorTotal(deportes,validos);
            printf ("En total hay %d jugadores en el club\n");
            system("pause");
            system("cls");
            imprimirCabecera("ESTADISTICAS");
            printf ("\n\n");
            imprimirOpcionesSubMenuAdminEstadistica();
            switchSubMenuAdminEstadistica(deportes,validos,dimension);
            break;
        case 2:
            system("cls");
            imprimirCabecera("CANTIDAD JUGADORES POR DEPORTE");
            printf("\n\n");
            cant = estCantJugadoresPorDeporte(deportes,validos);
            system("pause");
            system("cls");
            imprimirCabecera("ESTADISTICAS");
            imprimirOpcionesSubMenuAdminEstadistica();
            switchSubMenuAdminEstadistica(deportes,validos,dimension);
            break;
        case 3:
            system("cls");
            imprimirCabecera("CANTIDAD DE ENTRENADORES TOTAL");
            printf("\n\n");
            break;
        case 4:
            system("cls");
            imprimirCabecera("CANTIDAD DE ENTRENADORES POR DEPORTE");
            printf("\n\n");
            break;
        case 5:
            system("cls");
            imprimirCabecera("CANTIDAD DE DEPORTES");
            printf("\n\n");
            break;
        case 6:
            system("cls");
            imprimirCabecera("CALCULO DE SUELDO DE UN ENTRENADOR");
            printf("\n\n");
            break;
        }
    }
    while(op != 0);
    return op;
}
void imprimirOpcionesBuscarJugador ()
{
    printf ("1. BUSCAR POR DNI\n");
    printf ("2. BUSCAR POR NOMBRE\n");
    printf ("3. SALIR \n");
}
int switchOpcionesBuscarJugador(celda deportes [], int validos, int dimension)
{
    int op;
    nodo * aux;
    char buscado [30];
    do
    {
        op = ingresarOpcion();
        switch(op)
        {
        case 1:
            system ("cls");
            imprimirCabecera("BUSCAR JUGADOR");
            printf ("\n\n");
            printf ("Ingrese el DNI del jugador buscado \n");
            fflush(stdin);
            gets(buscado);
            aux = buscarJugadorPorDniArreglo(deportes,validos,buscado);
            mostrarJugador(aux->player);
            system("pause");
            system("cls");
            imprimirCabecera("JUGADOR");
            printf ("\n\n");
            imprimirOpcionesSubMenuAdminJugador();
            switchSubMenuAdminJugador(deportes,validos,dimension);
            break;
        case 2:
            system ("cls");
            imprimirCabecera("BUSCAR JUGADOR");
            printf ("\n\n");
            printf ("Ingrese el NOMBRE del jugador buscado \n");
            fflush(stdin);
            gets(buscado);
            aux = buscarJugadorNombreArreglo(deportes,validos,buscado);
            mostrarJugador(aux->player);
            system("pause");
            system("cls");
            imprimirCabecera("JUGADOR");
            printf ("\n\n");
            imprimirOpcionesSubMenuAdminJugador();
            switchSubMenuAdminJugador(deportes,validos,dimension);
            break;
        }
    }
    while (op!=0);
    return op;
}
