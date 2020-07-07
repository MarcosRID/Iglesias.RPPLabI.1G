#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "validaciones.h"
#include "color.h"
#include "tipo.h"
#include "cliente.h"
#include "medida.h"

#include "mascota.h"




int menu(void)
{
    int opcion;

    system("cls");
    printf("------------Menu Principal------------\n\n");

    printf("1- Alta Mascota\n");
    printf("2- Modificar Mascota\n");
    printf("3- Baja Mascota \n");
    printf("4- Listar Mascotas \n");
    printf("5- Listar por Tipo y Nombre \n");
    printf("6- Listar por Color \n");
    printf("7- Listar por Servicios \n");
    printf("8- Alta Tabajo \n");
    printf("9- Listar Trabajos \n");
    printf("10- Informes\n");
    printf("11- Salir\n\n");
    utn_getNumero(&opcion,"Ingrese opcione: ","Error Opocion inexistente\n",1,11,-1);

    return opcion;
}

void inisializarMascotas(eMascota mas[],int tamMas)
{
    for(int i=0; i < tamMas ; i++ )
    {
        mas[i].isEmpty=1;
    }


}
int buscarLibreMascota(eMascota mas[],int tamMas)
{
    int indice=-1;

    for(int i=0 ; i < tamMas; i++ )
    {
        if(mas[i].isEmpty==1)
        {
            indice=i;
            break;
        }
    }

    return indice;
}
int buscarMascotas(int id,eMascota mas[],int tamMas)
{
    int existe=-1;

    for(int i=0; i<tamMas; i++)
    {
        if(mas[i].id==id && mas[i].isEmpty==0)// no compara con empleadodados de baja o formularios vacios
        {
            existe=i;
            break;
        }
    }
    return existe;
}
int altaMascota(int id,eMascota mas[],int tamMas,eTipo tipo[],eColor color[],eCliente cliente[],int tamCliente,eMedida medida[],int tamMedida)
{
    int todoOk=-1;
    int indice;
    eMascota auxMascota;

    indice = buscarLibreMascota(mas,tamMas);

    if(indice==-1)
    {
        printf(":::::::Sistema Completo:::::::\n");
        system("pause");
    }
    else
    {
        auxMascota.id=id;

        listarMedidas(medida,tamMedida);
        utn_getNumero(&auxMascota.idMedida,"Ingrese Id Medida: ","Error opcion inexistente\n",300,299+tamMedida,-1);

        listarClientes(cliente,tamCliente);
        utn_getNumero(&auxMascota.idCliente,"Ingrese ID cliente\n","Error solo ID validos\n",1000,tamCliente+999,-1);

        printf("Ingrese nombre de mascota: ");
        fflush(stdin);
        gets(auxMascota.nombre);// Falta validar nombre

        system("cls");
        printf("------ Alta Mascota------\n\n");
        auxMascota.idTipo=tipo[menuTipo()-1].id;

        system("cls");
        printf("------ Alta Mascota------\n\n");
        auxMascota.idColor=color[menuColor()-1].id;

        system("cls");
        printf("------ Alta Mascota------\n\n");
        printf("Ingrese edad");
        scanf("%d",&auxMascota.edad);

        auxMascota.isEmpty=0;

        mas[indice]=auxMascota;

        todoOk =1;
    }
    return todoOk;
}
int modificarMascota(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eMedida medida[],int tamMedida)
{
    int todoOk=-1;
    int id;
    int opcion;
    int indice;

    system("cls");
    printf("--------Modificar mascota--------\n\n");

    mostrarMascotas(mas,tamMas,tipo,tamTipo,color,tamColor,cliente,tamCliente,medida,tamMedida);

    utn_getNumero(&id,"ingrese ID de mascota a modificar\n","Error. Solo numeros de IDs existentes\n",1000,tamMas+1000,-1);

    indice=buscarMascotas(id,mas,tamMas);

    if(mas[indice].isEmpty==0)
    {
        system("cls");
        printf("            --------Modificar mascota--------\n\n");

        printf("ID         nombre     edad      tipo    color  || ID/cli.   nombre/cli.    genero/cli.\n\n");

        mostrarMascota(mas[indice],tipo,tamTipo,color,tamColor,cliente,tamCliente,medida,tamMedida);

        printf("\n1-Edidar tipo\n");
        printf("2-Editar nombre\n");
        utn_getNumero(&opcion,"Seleccione el campo a modificar\n","Error. solo numeros del 1 al 2\n",1,2,-1);

        switch(opcion)
        {
        case 1:
            mas[indice].idTipo=tipo[(menuTipo())-1].id;
            todoOk=1;
            break;
        case 2:
            printf("Ingrese nuevo nombre\n");
            fflush(stdin);
            gets(mas[indice].nombre);
            todoOk=1;
            break;

        }
    }
    return todoOk;
}
void mostrarMascota(eMascota mas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eMedida medida[],int tamMedida)
{
    char colorMascota[20];
    char tipoMascota[20];
    char nombreCliente[20];
    char medidas[20];
    char genero = cargarCliente(nombreCliente,mas.idCliente,cliente,tamCliente);

    cargarMedida(medidas,mas.idMedida,medida,tamMedida);
    cargarColor(colorMascota,mas.idColor,color,tamColor);
    cargarTipo(tipoMascota,mas.idTipo,tipo,tamTipo);

    printf("%d    %9s      %02d  %9s%9s %9s ||  %d   %9s         %c \n",mas.id,mas.nombre,mas.edad,tipoMascota,colorMascota,medidas,mas.idCliente,nombreCliente,genero);
}
void mostrarMascotas(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eMedida medida[],int tamMedida)
{
    printf("ID         nombre     edad      tipo    color  || ID/cli.   nombre/cli.    genero/cli.\n\n");

    for(int i=0; i< tamMas; i++)
    {
        if(mas[i].isEmpty==0)
        {
            mostrarMascota(mas[i],tipo,tamTipo,color,tamColor,cliente,tamCliente,medida,tamMedida);
        }
    }
}
int bajaMascota(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eMedida medida[],int tamMedida)
{
    int todoOk=-1;
    int id;
    int indice;

    system("cls");
    printf("---------Baja Mascota---------\n\n");

    mostrarMascotas(mas,tamMas,tipo,tamTipo,color,tamColor,cliente,tamCliente,medida,tamMedida);

    printf("Ingrese ID a bajar\n");
    scanf("%d",&id);

    indice = buscarMascotas(id,mas,tamMas);

    if(indice==-1)
    {
        printf("::::::: ID inexcistente :::::::\n");
        system("pause");
    }
    else
    {
        mas[indice].isEmpty=1;
        todoOk=1;
    }
    return todoOk;
}
void mostrarMascotaPorTipoNombre(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eMedida medida[],int tamMedida)
{
    eMascota auxMascota;
    char tipoaux1[20];
    char tipoaux2[20];

    for(int i=0; i<tamMas-1 ; i++)
    {
        cargarTipo(tipoaux1,mas[i].idTipo,tipo,tamTipo);

        for(int j= i+1; j<tamMas ; j++)
        {
            cargarTipo(tipoaux2,mas[j].idTipo,tipo,tamTipo);

            if(mas[i].isEmpty==0 && mas[j].isEmpty==0&&  strcmp(tipoaux1,tipoaux2)==1 )
            {
                auxMascota=mas[i];
                mas[i]=mas[j];
                mas[j]=auxMascota;
            }
            else if((strcmp(tipoaux1,tipoaux2)==0) && (strcmp(mas[i].nombre,mas[j].nombre)==1))
            {
                auxMascota=mas[i];
                mas[i]=mas[j];
                mas[j]=auxMascota;
            }
        }
    }
    mostrarMascotas(mas,tamMas,tipo,tamTipo,color,tamColor,cliente,tamCliente,medida,tamMedida);
}

