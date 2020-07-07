#include "tipo.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "validaciones.h"


int menuTipo(void)
{

    int opcion;

    system("cls");
    printf("------------Tipos de Animales------------\n\n");

    printf("1- Ave\n");
    printf("2- Perro\n");
    printf("3- Gato\n");
    printf("4- Roedor\n");
    printf("5- Pez\n");

    utn_getNumero(&opcion,"Ingrese opcion: ","Error. Opcion inexistente\n",1,5,-1);

    return opcion;
}

void listarTipo(eTipo tipo[],int tamTipo)
{
    for(int i=0; i<tamTipo ; i++)
    {
        printf(" %d   %s\n",tipo[i].id,tipo[i].descripcion);
    }
}

void cargarTipo(char descripcion[],int id,eTipo tipo[],int tamTipo)
{
    for(int i=0; i< tamTipo; i++)
    {
        if(id== tipo[i].id)
        {
            strcpy(descripcion,tipo[i].descripcion);
            break;
        }
    }
}
