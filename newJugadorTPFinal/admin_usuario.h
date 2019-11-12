#ifndef ADMIN_USUARIO_H_INCLUDED
#define ADMIN_USUARIO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char admin[15];
    char contrasena[15];
} admin;

typedef struct
{
    char nombre[15];
    char contrasena[15];
    int eliminado;
} usuario;

int logueoAdmin();
int logueoEntrenador();
void crearAdmin ();
int adminRepetido (char[],FILE*);
void crearUsuarioEntrenador();
int usuarioRepetido (char[], FILE*);
#endif // ADMIN_USUARIO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define archivoDT "entrenador.bin"
#define archAdmin "admin.bin"
#define archEntrenador "usuarioEntrenador.bin"
#define CUOTA 700
#include <time.h>
