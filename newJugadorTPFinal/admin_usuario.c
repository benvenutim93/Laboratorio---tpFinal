#include "admin_usuario.h"
#define archAdmin "admin.bin"
#define archEntrenador "usuarioEntrenador.bin"

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
        gets(a.nombre);
        repe = usuarioRepetido(a.nombre,archi);
        while (repe !=0)
        {
            printf ("El nombre ingresado ya se encuentra en uso, ingrese uno nuevo \n");
            fflush(stdin);
            gets(a.nombre);
            repe=usuarioRepetido(a.nombre,archi);
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
        if (strcmp(a.nombre,nombre)==0)
            flag=1;
    }
    return flag;
}

int logueoAdmin()
{
    admin a;
    int flag=0,i=3;
    char nombre[20],contra[15];

    FILE* archi=fopen(archAdmin,"rb");

    printf("Ingrese nombre\n");
    fflush(stdin);
    gets(nombre);
    while(i>0)
    {
        printf("Ingrese la contrasenia\n");
        fflush(stdin);
        gets(contra);

        fseek(archi,0,0);
        flag=0;
        while(flag==0 && fread(&a,sizeof(admin),1,archi)>0)
        {
            if(strcmpi(a.admin,nombre)==0 && strcmpi(a.contrasena,contra)==0)
            {
                printf("Bienvenido %s\n",a.admin);
                flag=1;
                i=-1;
            }
            else if(strcmpi(a.admin,nombre)==0 && strcmpi(a.contrasena,contra)!=0)
            {
                printf("La contraseña es incorrecta\n\n");
                flag=2;
                i--;
            }
            else if(strcmpi(a.admin,nombre)!=0 && strcmpi(a.contrasena,contra)!=0)
            {
                printf("Los datos son invalidos\n\n");
                i--;
                flag=2;
                if(i>0)
                {
                    printf("Ingrese nombre\n");
                    fflush(stdin);
                    gets(nombre);
                }
            }
        }
    }
    if(i==0)
        printf("Llego a su limite de intentos");

    return flag;
}
int logueoEntrenador()
{
    usuario a;
    int flag=0,i=3;
    char nombre[20],contra[15];

    FILE* archi=fopen(archEntrenador,"rb");

    printf("Ingrese nombre\n");
    fflush(stdin);
    gets(nombre);
    while(i>0)
    {
        printf("Ingrese la contrasenia\n");
        fflush(stdin);
        gets(contra);
        fseek(archi,0,0);
        flag=0;
        while(flag==0 && fread(&a,sizeof(usuario),1,archi)>0)
        {
            if(strcmpi(a.nombre,nombre)==0 && strcmpi(a.contrasena,contra)==0)
            {
                printf("Bienvenido %s\n",a.nombre);
                flag=1;
                i=-1;
            }
            else if(strcmpi(a.nombre,nombre)==0 && strcmpi(a.contrasena,contra)!=0)
            {
                printf("La contraseña es incorrecta\n\n");
                flag=2;
                i--;
            }
            else if(strcmpi(a.nombre,nombre)!=0 && strcmpi(a.contrasena,contra)!=0)
            {
                printf("Los datos son invalidos\n\n");
                i--;
                flag=2;
                if(i>0)
                {
                    printf("Ingrese nombre\n");
                    fflush(stdin);
                    gets(nombre);
                }
            }
        }
    }
    if(i==0)
        printf("Llego a su limite de intentos");

    return flag;
}
