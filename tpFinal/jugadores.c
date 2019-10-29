#include "jugadores.h"



///*funciones de la estructura jugador*///

jugador cargaIndividual ()
{
    jugador a;

    printf("Ingrese el nombre del jugador\t");
    fflush(stdin);
    gets(a.nombreYapellido);
    printf("Ingrese el DNI del jugador\t");
    fflush(stdin);
    gets(a.dni);
    printf("Ingrese direccion del jugador\t");
    fflush(stdin);
    gets(a.direccion);
    printf("Ingrese telefono del jugador\t");
    fflush(stdin);
    gets(a.telefono);
    printf("Ingrese posicion del jugador\t");
    fflush(stdin);
    gets(a.posicion);
    printf("Ingrese cuota del jugador\t");
    fflush(stdin);
    gets(a.cuota);
    a.eliminado=0;

    return a;
}

void muestraIndividiual (jugador a)
{
    printf("ID: %i",a.id);
    printf("Nombre:%s",a.nombreYapellido);
    printf("DNI:%s\n");
    printf("Direccion %s\n");
    printf("Telefono %s\n");
    printf("Posicion %s\n");
    printf("Cuota: %s\n");
}

jugador modificarJugador (jugador a, int op)
{
    switch (&op)
    {
        case 1: printf("Ingrese el nombre nuevo: \t");
        gets(a.nombreYapellido);
        break;
        case 2: printf("Ingrese el DNI nuevo: \t");
        gets(a.dni);
        break;
        case 3: printf("Ingrese direccion nueva: \t");
        gets(a.direccion);
        break;
        case 4: printf("Ingrese telefono nuevo: \t");
        gets(a.telefono);
        break;
        case 5: printf("Ingrese posicion nueva: \t");
        gets(a.posicion);
        break;
        case 6: printf("Ingrese nueva ultima cuota paga: \t");
        gets(a.cuota);
        break;
    }
    return a;
}







///*funciones de la lista*///
nodoJugador * inicLista()
{
    return NULL;
}

nodoJugador * crearNodo (jugador a)
{
    nodoJugador * nuevo;

    nuevo=(nodoJugador*)malloc(sizeof(nodoJugador));
    nuevo->dato=a;
    nuevo->sig=NULL;

    return nuevo;
}

nodoJugador * agregarPpio (nodoJugador * lista, nodoJugador * nuevo)
{
    if(lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        nuevo->sig=lista;
        lista=nuevo;
    }
    return lista;
}

nodoJugador * agregarOrden (nodoJugador * lista, nodoJugador * nuevo)
{
    nodoJugador * seguidora;
    nodoJugador * ante;

    if (lista==NULL)
    {
        lista=agregarPpio(lista,nuevo);
    }
    else
    {
        ante=lista;
        seguidora=lista->sig;

        while (seguidora!=NULL && strcmp(lista->dato.nombreYapellido,nuevo->dato.nombreYapellido)<0)
        {
            ante=seguidora;
            seguidora=seguidora->sig;
        }
        ante->sig=nuevo;
        nuevo->sig=NULL;
    }
    return lista;
}

jugador buscarJugador (nodoJugador* lista, char nombreJu []) ///busca jugador dentro de la lista, si no lo encuentra el id es -1;
{
    jugador a;
    a.id=-1;
   FILE * arch=fopen(ArchJugadores,"rb");

   if (arch!=NULL)
   {
       while (fread(&a,sizeof(jugador),1,arch)>0 && strcmp(lista->dato.nombreYapellido,nombreJu)!=0);

       if (feof(arch)) /// si llegó a fin de archivo
       {
           a.id = -1; ///hago saber que no se encontro el dato
       }
   }

   return a;
}



