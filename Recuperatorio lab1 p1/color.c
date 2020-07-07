#include "color.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "validaciones.h"

int menuColor(void)
{

    int opcion;

    system("cls");
    printf("------------Colores------------\n\n");

    printf("1- Negro\n");
    printf("2- Blaco\n");
    printf("3- Gris\n");
    printf("4- Rojo\n");
    printf("5- Azul\n");

    utn_getNumero(&opcion,"Ingrese opcion: ","Error. Opcion inexistente\n",1,5,-1);

    return opcion;
}

void listarColor(eColor color[],int tamColor)
{
       printf("    ID      Color\n");

    for(int i=0;i<tamColor;i++)
    {
        printf(" %d        %9s \n",color[i].id,color[i].descripcion);
    }
}
void cargarColor(char descripcion[],int id,eColor color[],int tamColor)
{
    for(int i=0; i< tamColor;i++)
    {
        if(id== color[i].id)
        {
            strcpy(descripcion,color[i].descripcion);
            break;
        }
    }
}
