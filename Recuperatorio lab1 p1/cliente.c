#include "cliente.h"
#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

void listarClientes(eCliente cliente[],int tamCliente)
{
    for(int i=0;i<tamCliente;i ++)
    {
        printf(" %d   %9s  %c\n",cliente[i].id,cliente[i].nombre,cliente[i].genero);
    }
}
char cargarCliente(char nombre[],int id,eCliente cliente[],int tamCliente)
{
    char genero='n';

    for(int i=0; i<tamCliente ;i++)
    {
        if(id == cliente[i].id)
        {
            strcpy(nombre,cliente[i].nombre);
            genero=cliente[i].genero;
        }
    }
    return genero;
}
