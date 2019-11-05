#include "jugador.h"



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
    if(archi != NULL)
    {
    fwrite(&a,sizeof(jugador),1,archi);
    fclose(archi);
    }
}

int alPrincipio (char archivo[],celda deportes[])
{
    jugador aux;
    nodo * nn;
    int validos=0;
    FILE * archi = fopen(archivo,"rb");
    if (archi != NULL)
    {

    while (fread (&aux,sizeof(jugador),1,archi)>0)
    {
        nn = crearNodoDesdeJugador(aux);
        validos = agregarNodoAlArreglo (deportes,nn,validos);
    }

    fclose (archi);
    }
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
    while (i<validos && flag ==0)
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
{
    ///devuelve la lista modificada
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


nodo * buscarJugadorNombreArreglo (celda deportes[],int validos, char buscado [])
{
    nodo * aux;
    int i=0;
    while (i<validos)
    {
        aux=buscarJugadorNombreLista(deportes[i].lista,buscado);
        i++;
    }

    return aux;

}
nodo * buscarJugadorNombreLista (nodo * lista, char buscado [])
{
    nodo * seg = lista;
    nodo * aux = NULL;
    while (seg != NULL)
    {
        if (strcmpi (seg->player.nombreYapellido,buscado)==0)
            aux=seg;
        seg = seg->sig;
    }
    return aux;
}

nodo * jugadorBaja (nodo * lista, jugador baja) ///antes se pregunta que jugador se quiere dar de baja, y se pasa por parametro la lista del deporte el jugador.
{
    ///devuelve la lista modificada
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
    if (archi != NULL)
    {
    for (int i=0; i<validos; i++)
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
}
nodo * buscarJugadorPorDniArreglo (celda arreglo [], int validos, char buscado[])
{
    nodo * aux;
    int i=0;
    while (i<validos)
    {
        aux=buscarJugadorPorDniLista(arreglo[i].lista,buscado);
        i++;
    }
    return aux;
}
nodo * buscarJugadorPorDniLista (nodo * lista , char buscado[])
{
    nodo * seg = lista;
    nodo * aux = NULL;
    while (seg != NULL)
    {
        if (strcmpi (seg->player.dni,buscado)==0)
            aux=seg;
        seg = seg->sig;
    }
    return aux;
}
nodo * buscarYmodificarJugador (celda arreglo [], int validos , char nombreJugador [])
{
    int i=0, flag=0;
    nodo * aux=NULL;
    while (i< validos && flag == 0)
    {
        aux=buscarJugadorNombreArreglo(arreglo,validos,nombreJugador);
        if (strcmpi(aux->player.nombreYapellido,nombreJugador)==0)
            aux = modificarJugador (aux);
        i++;
    }
    return aux;
}
nodo * modificarJugador( nodo * a)
{
    int op;
    printf ("QUE CAMPO DESEA MODIFICAR? \n");
    printf ("1- NOMBRE\n");
    printf ("2- DNI\n");
    printf ("3- DIRECCION\n");
    printf ("4- TELEFONO\n");
    printf ("5- DEPORTE\n");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        printf ("Ingrese nombre y apellido\n");
        fflush(stdin);
        gets(a->player.nombreYapellido);
        break;
    case 2:
        printf ("Ingrese dni \n");
        fflush(stdin);
        gets(a->player.dni);
        break;
    case 3:
        printf ("Ingrese direccion\n");
        fflush(stdin);
        gets(a->player.direccion);
        break;
    case 4:
        printf ("Ingrese telefono\n");
        fflush(stdin);
        gets(a->player.telefono);
        break;
    case 5:
        printf ("Ingrese nuevo deporte\n");
        fflush(stdin);
        gets(a->player.deporte);
        break;
    }
    return a;
}
nodo * pagoCuota(nodo * a)
{
    printf ("ULTIMA CUOTA PAGA: ");
    puts(a->player.cuota);
    printf ("Que mes va a pagar?\n");
    fflush(stdin);
    gets(a->player.cuota);
    return a;
}
