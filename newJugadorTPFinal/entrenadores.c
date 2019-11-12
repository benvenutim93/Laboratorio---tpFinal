#include "entrenadores.h"
#define archivoDT "entrenador.bin"

arbolEntrenador* inicArbol()
{
    return NULL;
}
int entId()///devuelve el id del siguiente usuario a registrar
{

    int aux;
    entrenador a;

    FILE* archi=fopen(archivoDT,"rb");
    if(archi==NULL)
        aux=0;
    else
    {
        fseek(archi,sizeof(entrenador)*(-1),2);
        fread(&a,sizeof(entrenador),1,archi);
        aux=a.id+1;
    }
    fclose(archi);
    return aux;
}
entrenador crearEntrenador()   ///crea un entrenador
{
    entrenador a;
    a.id= entId();
    printf("NOMBRE Y APELLIDO\n");
    fflush(stdin);
    gets(a.nombreYapellido);
    printf("DNI:\n");
    fflush(stdin);
    gets(a.dni);
    printf("DIRECCION:\n");
    fflush(stdin);
    gets(a.direccion);
    printf("TELEFONO:\n");
    fflush(stdin);
    gets(a.telefono);
    printf("DEPORTE:\n");
    fflush(stdin);
    gets(a.deporte);
    a.eliminado=0;
    return a;
}
arbolEntrenador* Pasaje_Archivo_Arbol(arbolEntrenador* lito)///Pasa del Entrenador guardado en el archivo a un nodoArbol y crea el arbol con los nodos
{

    entrenador b;

    FILE* archi=fopen(archivoDT,"rb");

    while(fread(&b,sizeof(entrenador),1,archi)>0)
    {
        arbolEntrenador* na=(arbolEntrenador*) malloc(sizeof(arbolEntrenador));
        na->coach = b;
        na->der=NULL;
        na->izq=NULL;
        lito=agregarArbolEntrenador(lito,na);
    }
    fclose(archi);
    return lito;
}
arbolEntrenador* agregarArbolEntrenador(arbolEntrenador* arbol, arbolEntrenador * nn)
{
    if (arbol == NULL)
        arbol = nn;
    else if (strcmpi(nn->coach.nombreYapellido,arbol->coach.nombreYapellido)<0)
        arbol->izq=agregarArbolEntrenador(arbol->izq,nn);
    else
        arbol->der = agregarArbolEntrenador (arbol->der,nn);
    return arbol;
}
void mostrarPreOrder(arbolEntrenador * arbol)
{
    if (arbol!=NULL)
    {
        printf("\n\n");
        printf("ID: %d\n",arbol->coach.id);
        printf("NOMBRE:");
        puts(arbol->coach.nombreYapellido);
        printf ("DNI:\n");
        fflush(stdin);
        puts(arbol->coach.dni);
        printf("DIRECCION:\n");
        fflush(stdin);
        puts(arbol->coach.direccion);
        printf("TELEFONO:\n");
        fflush(stdin);
        puts(arbol->coach.telefono);
        printf("DEPORTE:\n");
        fflush(stdin);
        puts(arbol->coach.deporte);
        printf("ESTADO DE ELIMINADO: %d\n",arbol->coach.eliminado);
        mostrarPreOrder(arbol->izq);
        mostrarPreOrder(arbol->der);
    }
}
void Cargar_Archivo_Entrenador()
{
    entrenador nuevo;

    nuevo=crearEntrenador();

    FILE* archi=fopen(archivoDT,"ab");

    fwrite(&nuevo,sizeof(entrenador),1,archi);

    fclose(archi);
}
void mostrarArchivo()
{
    entrenador a;

    FILE* archi=fopen(archivoDT,"rb");
    printf("\n\n");
    printf("\nARCHIVO\n");
    while(fread(&a,sizeof(entrenador),1,archi)>0)
    {
        mostrarEntrenador(a);
    }
    fclose(archi);
}
void mostrarEntrenador(entrenador aux)
{
    printf("ID:%d\n",aux.id);
    printf("NOMBRE:");
    puts(aux.nombreYapellido);
    printf ("DNI:\n");
    fflush(stdin);
    puts(aux.dni);
    printf("DIRECCION:\n");
    fflush(stdin);
    puts(aux.direccion);
    printf("TELEFONO:\n");
    fflush(stdin);
    puts(aux.telefono);
    printf("DEPORTE:\n");
    fflush(stdin);
    puts(aux.deporte);
    printf("ESTADO DE ELIMINADO: %d\n",aux.eliminado);
    printf("\n\n");
}
arbolEntrenador* buscarEntrenador(char DT[],arbolEntrenador* lito)
{
    arbolEntrenador*aux;



    if(lito!=NULL)
    {
        if(strcmpi(lito->coach.nombreYapellido,DT)==0)
            aux=lito;
        else
        {
            if(strcmpi(lito->coach.nombreYapellido,DT)>0)
                aux=buscarEntrenador(DT,lito->der);
            else
                aux=buscarEntrenador(DT,lito->izq);
        }
    }
    return aux;
}
void mostrar_deporte_entrenador(char DT[],celda vector[],arbolEntrenador* lito)
{
    int i=0;
    arbolEntrenador* aux;
    aux=buscarEntrenador(DT,lito);

    if(aux!=NULL)
    {
        while(strcmpi(aux->coach.nombreYapellido,vector[i].deporte)!=0)
        {
            i++;
        }
       mostrarLista(vector[i].lista);
    }
}
arbolEntrenador* alta_entrenador(arbolEntrenador* lito,char nombre[])
{
    arbolEntrenador* aux;
    aux=buscarEntrenador(nombre,lito);

    aux->coach.eliminado=0;

    return lito;
}
arbolEntrenador* baja_entrenador(arbolEntrenador* lito,char nombre[])
{
    arbolEntrenador* aux;
    aux=buscarEntrenador(nombre,lito);

    aux->coach.eliminado=1;

    return lito;
}
arbolEntrenador* modificar_entrenador(arbolEntrenador* lito, char nombre[])
{
    int mod=0;
    arbolEntrenador* aux;
    aux=buscarEntrenador(nombre, lito);
    printf("Que desea modificar?\n");
    printf("Oprima 1 si desea modifica el NOMBRE \n");
    printf("Oprima 2 si desea modifica el DIRECCION \n");
    printf("Oprima 3 si desea modifica el TELEFONO \n");
    printf("Oprima 4 si desea modifica el DEPORTE \n");
    scanf("%d",&mod);
    switch(mod)
    {
    case 1:
        printf("Ingrese el nuevo nombre\n");
        fflush(stdin);
        gets(aux->coach.nombreYapellido);
        break;
    case 2:
        printf("Ingrese la nueva direccion\n");
        fflush(stdin);
        gets(aux->coach.direccion);
        break;
    case 3:
        printf("Ingrese el nuevo telefono\n");
        fflush(stdin);
        gets(aux->coach.telefono);
        break;
    case 4:
        printf("Ingrese el nuevo deporte\n");
        fflush(stdin);
        gets(aux->coach.deporte);
        break;
    }
    return lito;
}
arbolEntrenador* jug_del_entrenador(celda vector[],char nombre[],arbolEntrenador* master)
{
    arbolEntrenador* DT;
    int i=0;
    if(strcmpi(nombre,master->coach.nombreYapellido)!=0)
    {
        DT=jug_del_entrenador(vector,nombre,master);
    }
    if(DT!=NULL)
    {
        while(strcmpi(DT->coach.deporte,vector[i].deporte)!=0)
        {
            i++;
        }
    }
    mostrarLista(vector[i].lista);
}
entrenador pasaje_arbol_entrenador(arbolEntrenador* lito)
{
    entrenador a;
    strcpy(a.deporte,lito->coach.deporte);
    strcpy(a.direccion,lito->coach.direccion);
    strcpy(a.dni,lito->coach.dni);
    strcpy(a.nombreYapellido,lito->coach.nombreYapellido);
    strcpy(a.telefono,lito->coach.telefono);
    a.eliminado=lito->coach.eliminado;
    a.id=lito->coach.id;
    return a;
}
void puntero_archivo(arbolEntrenador* lito)
{

    FILE* archi=fopen(archivoDT,"wb");

    if(archi!=NULL)
    {
        pasaje_arbol_archivo(lito,archi);
    }
    fclose(archi);
}
void pasaje_arbol_archivo(arbolEntrenador* lito, FILE* archi)
{
    entrenador a;

    if(lito!=NULL)
    {
        a=pasaje_arbol_entrenador(lito);
        pasaje_arbol_archivo(lito->der,archi);
        pasaje_arbol_archivo(lito->izq,archi);
        fwrite(&a,sizeof(entrenador),1,archi);
    }
}
int cantidad_total_de_entrenadores(arbolEntrenador* lito)
{
    int cant=0;
    if(lito!=NULL)
    {
        cant=1+cantidad_total_de_entrenadores(lito->der)+cantidad_total_de_entrenadores(lito->izq);
    }
    return cant;
}
int cantidad_de_entrenadores_de_un_deporte(arbolEntrenador* lito,char deporte[])
{
    int cant=0;
    if(lito!=NULL)
    {
        if(strcmpi(lito->coach.deporte,deporte)==0)
            cant++;
        cant=cantidad_de_entrenadores_de_un_deporte(lito->der,deporte)+cantidad_de_entrenadores_de_un_deporte(lito->izq,deporte)+cant;
    }
    return cant;
}
void mesActual(char actual[])
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
        strcpy(actual,"Enero");
        break;
    case 1:
        strcpy(actual,"Febrero");
        break;
    case 2:
        strcpy(actual,"Marzo");
        break;
    case 3:
        strcpy(actual,"Abril");
        break;
    case 4:
        strcpy(actual,"Mayo");
        break;
    case 5:
        strcpy(actual,"Junio");
        break;
    case 6:
        strcpy(actual,"Julio");
        break;
    case 7:
        strcpy(actual,"Agosto");
        break;
    case 8:
        strcpy(actual,"Septiembre");
        break;
    case 9:
        strcpy(actual,"Octubre");
        break;
    case 10:
        strcpy(actual,"Noviembre");
        break;
    case 11:
        strcpy(actual,"Diciembre");
        break;
    }
}
int calcular_sueldo_entrenador(celda vector[],char nombreDT[],arbolEntrenador* lito)
{
    int i=0,sueldo=0;
    arbolEntrenador* DT;
    char actual[20];
    char mes[15];
    DT=buscarEntrenador(nombreDT,lito);
    mesActual(actual);
    strcpy(mes,actual);
    while(strcmpi(vector[i].deporte,DT->coach.deporte)!=0)
    {
        i++;
    }
    nodo* seg=vector[i].lista;
    while(seg!=NULL)
    {
        if(strcmpi(seg->player.cuota,mes)==0)
            i++;
        seg=seg->sig;
    }
    sueldo=i*CUOTA;

    return sueldo;
}
