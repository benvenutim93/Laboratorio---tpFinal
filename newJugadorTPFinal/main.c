#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define dim 20

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
int jugID(char []);
jugador jugCrearJugador(char []);
nodo * jugCrearNodoNuevo(char  []);
void mostrarJugador(jugador );
void jugMostrarArchivo(char []);
void jugMesCuota (char []);
void mostrarArreglo (celda [], int );
void mostrarLista (nodo * );
int validosCelda (celda[]);
void inicCeldasNull (celda  []);
void jugAlArchivo(char [], jugador );
int alPrincipio (char [],celda []);
int jugAltaDeporte (celda [], char [],int );
int jugPosDeporte (celda [], char [], int );
int jugAgregarDeporte (celda [], char [],int );
nodo * crearNodoDesdeJugador (jugador );
int agregarNodoAlArreglo (celda  [],nodo *, int );
void mostrarJugEliminados(celda  [], int );
void mostrarListaEliminados(nodo * );
nodo * jugadorAlta (nodo * , jugador );
jugador buscarJugadorNombreArreglo (celda [],int, char  []);
jugador buscarJugadorNombreLista (nodo *, char  []);
nodo * jugadorBaja (nodo * , jugador );
void mostrarJugadoresHabilitados (celda  [], int );
void mostrarListaHabilitados (nodo * );
void alFinal (char  [], celda [], int );





int main()
{
    char jugadores[] = "jugadores.bin";
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

    validos = alPrincipio(jugadores,deportes);
    mostrarJugadoresHabilitados(deportes,validos);
    /*mostrarArreglo(deportes,validos);
    system("pause");
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

nodo * jugInicLista ()
{
    return NULL;
}
nodo * jugAgregarPpio(nodo * lista, nodo * nn)
{
    if (lista != NULL)
        nn->sig=lista;
    lista=nn;
    return lista;
}
int jugID(char archivo[])
{
    jugador a;
    int id;
    FILE * archi = fopen (archivo,"rb");
    if (archi == NULL)
        id=0;
    else
    {
        fseek(archi,sizeof(jugador)*(-1),2);
        fread(&a,sizeof(jugador),1,archi);
        id=a.id+1;
    }
    fclose(archi);
    return id;
}
jugador jugCrearJugador(char archivo[])
{
    jugador a;
    char pago = 's';
    a.id = jugID(archivo);
    printf ("Nombre y apellido del jugador \n");
    fflush(stdin);
    gets(a.nombreYapellido);
    printf ("Direccion \n");
    fflush(stdin);
    gets (a.direccion);
    printf ("Telefono de contacto \n");
    fflush(stdin);
    gets(a.telefono);
    printf ("DNI \n");
    fflush(stdin);
    gets(a.dni);
    printf ("Categoria:\n");
    fflush(stdin);
    gets(a.categoria);
    printf ("Deporte \n");
    fflush(stdin);
    gets(a.deporte);
    printf ("Paga la cuota ahora? S/N \n");
    scanf("%c", &pago);
    if (pago == 's')
    {
        jugMesCuota(a.cuota);
    }
    else
        strcpy(a.cuota,"Sin Pagar");
    a.eliminado=0;

    return a;
}
nodo * jugCrearNodoNuevo(char archivo [])
{
    jugador a = jugCrearJugador(archivo);
    jugAlArchivo(archivo,a);
    nodo * nn = (nodo*)malloc (sizeof(nodo));
    nn->player=a;
    nn->sig = NULL;
    return nn;
}
void mostrarJugador(jugador a)
{
    printf ("\nID JUGADOR: %d\n",a.id);
    printf ("NOMBRE Y APELLIDO:");
    puts(a.nombreYapellido);
    printf ("DNI:");
    puts(a.dni);
    printf ("CATEGORIA:");
    puts(a.categoria);
    printf ("DIRECCION:");
    puts(a.direccion);
    printf ("TELEFONO:");
    puts(a.telefono);
    printf("DEPORTE:");
    puts(a.deporte);
    printf("ULTIMO MES PAGO:");
    puts(a.cuota);
    printf ("Eliminado: %d \n",a.eliminado);
}
void jugMostrarArchivo(char archivo[])
{
    FILE * archi = fopen(archivo,"rb");
    jugador a;

    if (archi!=NULL)
    {
        while (fread(&a,sizeof(jugador),1,archi)>0)
        {
            mostrarJugador(a);
        }
    }
}
void jugMesCuota (char mesCuota[])
{
    time_t sisTime;
    struct tm * tiempo;
    int mes;

    time(&sisTime);
    tiempo=localtime(&sisTime);
    mes=tiempo->tm_mon;

    switch (mes)
    {
    case 0:
        strcpy(mesCuota,"Enero");
        break;
    case 1:
        strcpy(mesCuota,"Febrero");
        break;
    case 2:
        strcpy(mesCuota,"Marzo");
        break;
    case 3:
        strcpy(mesCuota,"Abril");
        break;
    case 4:
        strcpy(mesCuota,"Mayo");
        break;
    case 5:
        strcpy(mesCuota,"Junio");
        break;
    case 6:
        strcpy(mesCuota,"Julio");
        break;
    case 7:
        strcpy(mesCuota,"Agosto");
        break;
    case 8:
        strcpy(mesCuota,"Septiembre");
        break;
    case 9:
        strcpy(mesCuota,"Octubre");
        break;
    case 10:
        strcpy(mesCuota,"Noviembre");
        break;
    case 11:
        strcpy(mesCuota,"Diciembre");
        break;
    }
}

void mostrarArreglo (celda deportes[], int validos)
{
    for (int i=0; i<validos; i++)
    {
        printf ("DEPORTE: \t");
        puts(deportes[i].deporte);
        mostrarLista(deportes[i].lista);
        printf ("---------------------------\n");
    }
}
void mostrarLista (nodo * lista)
{
    nodo * seg = lista;
    while (seg != NULL)
    {
        if (seg->player.eliminado==0)
            mostrarJugador(seg->player);
        seg=seg->sig;
    }
}

int validosCelda(celda deportes[])
{
    int i=0, validos=0;
    while (i<dim)
    {
        if (deportes[i].lista!=NULL)
            validos++;
        i++;
    }
    return validos;
}
void inicCeldasNull (celda deportes [])
{
    int i=0;
    while(i<dim)
    {
        deportes[i].lista=jugInicLista();
        i++;
    }
}
void jugAlArchivo(char archivo[], jugador a)
{
    FILE * archi = fopen (archivo,"ab");
    fwrite(&a,sizeof(jugador),1,archi);
    fclose(archi);
}

int alPrincipio (char archivo[],celda deportes[])
{
    FILE * archi = fopen(archivo,"rb");
    jugador aux;
    nodo * nn;
    int validos=0;
    while (fread (&aux,sizeof(jugador),1,archi)>0)
    {
        nn = crearNodoDesdeJugador(aux);
        validos = agregarNodoAlArreglo (deportes,nn,validos);
    }

    fclose (archi);
    return validos;
}
int jugAltaDeporte (celda deportes[], char archivo[],int validos)
{
    int pos;
    nodo * aux = jugCrearNodoNuevo(archivo);
    pos=jugPosDeporte (deportes, aux->player.deporte, validos);
    if (pos==-1)
    {
        validos=jugAgregarDeporte (deportes,aux->player.deporte,validos);
        pos=validos-1;
    }
    deportes[pos].lista=jugAgregarPpio(deportes[pos].lista,aux);
    return validos;
}
int jugPosDeporte (celda deportes[], char deporte[], int validos)
{
    int pos=-1, i=0;
    while (i<validos)
    {
        if (strcmpi(deportes[i].deporte,deporte)==0)
            pos=i;
        i++;
    }
    return pos;
}
int jugAgregarDeporte (celda deportes[], char deporte[],int validos)
{
    strcpy(deportes[validos].deporte,deporte);
    deportes[validos].lista=jugInicLista();
    validos++;
    return validos;
}
int agregarNodoAlArreglo (celda deportes [],nodo * nn, int validos)
{
    int i=0, flag=0;
    while (i<validos)
    {
        if (strcmpi(nn->player.deporte,deportes[i].deporte)==0)
        {
            deportes[i].lista=jugAgregarPpio(deportes[i].lista,nn);
            flag=1;
        }
        i++;
    }
    if (flag != 1)
    {
        validos=jugAgregarDeporte(deportes,nn->player.deporte,i);
        deportes[i].lista=jugAgregarPpio(deportes[i].lista,nn);
    }
    return validos;
}

nodo * crearNodoDesdeJugador (jugador a)
{
    nodo * nn = (nodo*)malloc (sizeof(nodo));
    nn->player=a;
    nn->sig = NULL;
    return nn;
}

void mostrarJugEliminados(celda deportes [], int validos)
{
    printf ("JUGADORES ELIMINADOS\n\n");
    for (int i=0; i<validos; i++)
    {
        mostrarListaEliminados(deportes[i].lista);
    }
}
void mostrarListaEliminados(nodo * lista)
{
    nodo * seg = lista;
    while (seg != NULL)
    {
        if (seg->player.eliminado == 1)
            mostrarJugador(seg->player);
        seg=seg->sig;
    }
}
nodo * jugadorAlta (nodo * lista, jugador alta) ///antes se pregunta que jugador se quiere dar de baja, y se pasa por parametro la lista del deporte el jugador.
{                                               ///devuelve la lista modificada
    nodo * seg = lista;
    if (lista != NULL)
    {
        while (seg != NULL && strcmpi(seg->player.nombreYapellido,alta.nombreYapellido)!=0)
            seg=seg->sig;
        if (seg != NULL)
            seg->player.eliminado=0;
    }
    return lista;
}


jugador buscarJugadorNombreArreglo (celda deportes[],int validos, char buscado [])
{
    jugador a;
    int i=0;
    while (i<validos)
    {
        a=buscarJugadorNombreLista(deportes[i].lista,buscado);
        i++;
    }

    return a;

}

jugador buscarJugadorNombreLista (nodo * lista, char buscado [])
{
    nodo * seg = lista;
    jugador a;
    while (seg != NULL)
    {
        if (strcmpi (seg->player.nombreYapellido,buscado)==0)
            a=seg->player;
        seg = seg->sig;
    }
    return a;
}

nodo * jugadorBaja (nodo * lista, jugador baja) ///antes se pregunta que jugador se quiere dar de baja, y se pasa por parametro la lista del deporte el jugador.
{                                               ///devuelve la lista modificada
    nodo * seg = lista;
    if (lista != NULL)
    {
        while (seg != NULL && strcmpi(seg->player.nombreYapellido,baja.nombreYapellido)!=0)
            seg=seg->sig;
        if (seg != NULL)
            seg->player.eliminado=1;
    }
    return lista;
}

void mostrarJugadoresHabilitados (celda deportes [], int validos)
{
    printf ("JUGADORES HABILITADOS\n\n");
    for (int i=0; i<validos; i++)
    {
        mostrarListaHabilitados(deportes[i].lista);
    }
}
void mostrarListaHabilitados (nodo * lista)
{
    nodo * seg = lista;
    while (seg != NULL)
    {
        if (seg->player.eliminado == 0)
            mostrarJugador(seg->player);
        seg=seg->sig;
    }
}
void alFinal (char archivo [], celda deportes[], int validos)
{
    FILE * archi = fopen(archivo, "wb");
    jugador aux;
    for (int i=0;i<validos;i++)
    {
        nodo * seg = deportes[i].lista;
        while (seg!=NULL)
        {
            aux=seg->player;
            fwrite(&aux,sizeof(jugador),1,archi);
            seg=seg->sig;
        }
    }
    fclose(archi);
}
