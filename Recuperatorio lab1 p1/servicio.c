#include "servicio.h"
#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

void listarServicio(eServicio servicio[],int tamServicio)
{
    printf("    ID           Servicio    Precio\n");

    for(int i=0;i<tamServicio;i++)
    {
        printf(" %d%18s     %.2f\n",servicio[i].id,servicio[i].descripcion,servicio[i].precio);
    }
}
float cargarServicio(char descripcion[],int id,eServicio servicio[],int tamServicio)
{
    float precio=-1;

    for(int i=0; i< tamServicio;i++)
    {
        if(id == servicio[i].id )
        {
            strcpy(descripcion,servicio[i].descripcion);
            precio=servicio[i].precio;
            break;
        }
    }
    return precio;
}
int buscarServicio(int id,eServicio servicio[],int tamServicio)
{
    int indice=-1;

    for(int i=0 ; i<tamServicio ; i++)
    {
        if(servicio[i].id==id)
        {
            indice=i;
        }
    }
    return indice;
}
