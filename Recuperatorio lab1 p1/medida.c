#include "medida.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "validaciones.h"


int menuMedida(void)
{
    int opcion;

    system("cls");
    printf("------------medida------------\n\n");

    printf("1- Bajo\n");
    printf("2- Mediano\n");
    printf("3- Alto\n");


    utn_getNumero(&opcion,"Ingrese opcion: ","Error. Opcion inexistente\n",1,3,-1);

    return opcion;
}
void listarMedidas(eMedida medida[],int tamMedida)
{
    printf("    ID      medida\n");

    for(int i=0; i<tamMedida; i++)
    {
        printf(" %d        %9s \n",medida[i].id,medida[i].descripcion);
    }
}
void cargarMedida(char descripcion[],int id,eMedida medida[],int tamMedida)
{
    for(int i=0; i< tamMedida; i++)
    {
        if(id== medida[i].id)
        {
            strcpy(descripcion,medida[i].descripcion);
            break;
        }
    }
}
