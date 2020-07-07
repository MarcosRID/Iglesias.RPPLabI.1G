#include "medida.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "validaciones.h"
#include "color.h"
#include "tipo.h"
#include "cliente.h"
#include "mascota.h"
#include "servicio.h"
#include "fecha.h"
#include "trabajo.h"



void inisializarTrabajose(eTrabajo trabajo[],int tamTrabajo)
{
    for(int i=0; i < tamTrabajo ; i++ )
    {
        trabajo[i].isEmpty=1;
    }

}
int altaTrabajos(int id,eTrabajo trabajo[],int tamTrabajo,eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eServicio serv[],int tamServ,eCliente cliente[],int tamCliente,eMedida medida[],int tamMedida)
{
    int todoOk=-1;
    eTrabajo auxTrabajo;

    int indice = buscarLibreTrabajo(trabajo,tamTrabajo);

    system("cls");
    printf("--------Alta Trabajo-------\n\n");

    if(indice==-1)
    {
        printf("::::::Sistema completo::::::\n\n");
        system("pause");
    }
    else
    {
        auxTrabajo.id=id;

        mostrarMascotas(mas,tamMas,tipo,tamTipo,color,tamColor,cliente,tamCliente,medida,tamMedida);
        utn_getNumero(&auxTrabajo.idMascota,"Ingrese ID deseado: ","Error. solo ID de mascotas existentes\n",1000,tamMas+1000,-1);

        system("cls");
        printf("--------Alta Trabajo-------\n\n");
        listarServicio(serv,tamServ);
        utn_getNumero(&auxTrabajo.idServicio,"Ingrese ID correspondiente al servicio deseado: ","Error solo ID de Servicios existenes\n",20000,tamServ+20000,-1);


        system("cls");
        printf("--------Alta Trabajo-------\n\n");
        printf("Ingrese Fecha: dd/mm/aaaa ");
        scanf("%d/%d/%d",&auxTrabajo.fecha.dia,&auxTrabajo.fecha.mes,&auxTrabajo.fecha.anio);

        auxTrabajo.isEmpty=0;

        trabajo[indice]=auxTrabajo;
        todoOk=1;
    }
    return todoOk;
}
int buscarLibreTrabajo(eTrabajo trabajo[],int tamTrabajo)
{
    int indice=-1;

    for(int i=0; i<tamTrabajo; i++)
    {
        if(trabajo[i].isEmpty==1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
void mostrarTrabajo(eTrabajo trabajo,eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eServicio serv[],int tamServ,eCliente cliente[],int tamCliente,eMedida medida[],int tamMedida)
{
    char auxServicio[20];
    int indice;

    float auxPrecio=cargarServicio(auxServicio,trabajo.idServicio,serv,tamServ);
    indice=buscarMascotas(trabajo.idMascota,mas,tamMas);

    mostrarMascota(mas[indice],tipo,tamTipo,color,tamColor,cliente,tamCliente,medida,tamMedida);

    printf("Servicio: %9s \n precio: %.2f \n Fecha: %d/%d/%d\n",auxServicio,auxPrecio,trabajo.fecha.dia,trabajo.fecha.mes,trabajo.fecha.anio);
    printf("\n|--------------------------------------------------|\n");
}
void mostrarTrabajos(eTrabajo trabajo[],int tamTrabajo,eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eServicio serv[],int tamServ,eCliente cliente[],int tamCliente,eMedida medida[],int tamMedida)
{
    system("cls");
    printf("------------lista de trabajos-----------\n\n");

    for(int i=0; i<tamTrabajo ;i++)
    {
        if(trabajo[i].isEmpty==0)
        {
            printf("ID         nombre     edad      tipo    color  || ID/cli.   nombre/cli.    genero/cli.\n\n");

            mostrarTrabajo(trabajo[i],mas,tamMas,tipo,tamTipo,color,tamColor,serv,tamServ,cliente,tamCliente,medida,tamMedida);
        }
    }
    system("pause");
}
