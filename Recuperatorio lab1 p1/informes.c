#include "medida.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "validaciones.h"
#include "color.h"
#include "tipo.h"
#include "servicio.h"
#include "cliente.h"
#include "mascota.h"
#include "trabajo.h"
#include "fecha.h"
#include "informes.h"


int menuInforme(void)
{
    int opcion;

    printf("1-Listar por color deseado\n");
    printf("2-Listar por tipo deseado\n");
    printf("3-Listar Mascota mas joven/es\n");
    printf("4-Listar por tipo\n");
    printf("5-Listar por color y tipo desead\n");
    printf("6-Listar color/es predominante/s\n");;
    printf("7-Listar trabajos de una mascota\n");
    printf("8-Suma total de una mascota\n");
    printf("9-Mascotas segun el servicio\n");
    printf("10-Trabajos por fecha\n");
    printf("11-cantidad de mascotas bajas\n");
    printf("12-Cantidad de mascota de cada cliente\n");
    printf("13-Listar mascotas (elegir el tamanio)\n");
    printf("14-Listar mascotas (agrupadas por medidas)\n");
    printf("15-Informar medida predominante\n");
    printf("16-Lista por tipo y medida (a escojer)\n");
    printf("17-Lista los clientes y mascotas por medida (elegir la medida)\n");
    printf("18-Informar cantidad mascotas bajas\n");


    utn_getNumero(&opcion,"Ingrese opcion\n","Error. Solo opciones numericas (1 al 10)\n",1,18,-1);

    return opcion;
}

void infomeMascotasColor(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eMedida medida[],int tamMedida)
{
    int idColor;
    char descripcionColor[20];

    listarColor(color,tamColor);
    utn_getNumero(&idColor,"Ingrese ID del color deseado\n","Error solo ID existentes\n",5000,tamColor+4999,-1);

    cargarColor(descripcionColor,idColor,color,tamColor);

    system("cls");
    printf("-----------Informe de mascotas (color %s)-----------\n\n",descripcionColor);

    for(int i=0 ; i<tamMas ; i++)
    {
        if(mas[i].idColor==idColor)
        {
            mostrarMascota(mas[i],tipo,tamTipo,color,tamColor,cliente,tamCliente,medida,tamMedida);
        }
    }
}

void infomeMascotasTipo(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eMedida medida[],int tamMedida)
{

    int idTipo;
    char descripcionTipo[20];

    listarTipo(tipo,tamTipo);
    utn_getNumero(&idTipo,"Ingrese ID del tipo deseado\n","Error solo ID existentes\n",1000,tamColor+999,-1);

    cargarTipo(descripcionTipo,idTipo,tipo,tamTipo);

    system("cls");
    printf("-----------Informe de mascotas (Tipo %s)-----------\n\n",descripcionTipo);

    for(int i=0 ; i<tamMas ; i++)
    {
        if(mas[i].idTipo==idTipo)
        {
            mostrarMascota(mas[i],tipo,tamTipo,color,tamColor,cliente,tamCliente,medida,tamMedida);
        }
    }
}

int infomeMascotaMenor(int masMenores[], eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente)
{
    int mascotaMenor;
    int cantidad=0;
    int flag=1;

    for (int i=0 ; i < tamMas ; i++)
    {
        if( ( mas[i].isEmpty==0 && mascotaMenor>mas[i].edad ) || flag==1)
        {
            mascotaMenor=mas[i].edad;
            flag=0;
        }
    }

    for(int i=0 ; i<tamMas ; i++)
    {
        if(mas[i].isEmpty==0 && mas[i].edad==mascotaMenor)
        {
            masMenores[cantidad]=i;
            cantidad++;
        }
    }
    return cantidad;
}
void informarPorTipo(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eMedida medida[],int tamMedida)
{
    char auxDescripcion[20];

    for(int t=0 ; t<tamTipo ; t++) //recorro vector de tipo.
    {
        cargarTipo(auxDescripcion,1000+t,tipo,tamTipo);

        printf("\n-------------------------------TIPO: %s-------------------------------\n\n",auxDescripcion);

        for(int m=0 ; m<tamMas ; m++)//recorro vector de mascota.
        {
            if(mas[m].idTipo==tipo[t].id)
            {
                mostrarMascota(mas[m],tipo,tamTipo,color,tamColor,cliente,tamCliente,medida,tamMedida);
            }
        }
    }
}

void informarPorTipoColorRequerido(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eMedida medida[],int tamMedida)
{
    int auxIdTipo;
    int auxIdColor;
    char auxDescripcionTipo[20];
    char auxDescripcionColor[20];

    listarTipo(tipo,tamTipo);
    utn_getNumero(&auxIdTipo,"Ingrese ID (tipo) deseado: ","Error solo ID existenes (formato numerico)\n",1000,tamTipo+1000,-1);

    system("cls");

    listarColor(color,tamColor);
    utn_getNumero(&auxIdColor,"Ingrese ID (color) deseado: ","Error solo ID existenes (formato numerico)\n",5000,tamColor+5000,-1);

    system("cls");

    cargarColor(auxDescripcionColor,auxIdColor,color,tamColor);
    cargarTipo(auxDescripcionTipo,auxIdTipo,tipo,tamTipo);

    printf("---------------Lista: Mascotas Por Tipo: %s y Color: %s-----------------\n\n",auxDescripcionTipo,auxDescripcionColor);

    for(int i=0 ; i<tamMas ; i++)
    {
        if( auxIdTipo==mas[i].idTipo && auxIdColor==mas[i].idColor )
        {
            mostrarMascota(mas[i],tipo,tamTipo,color,tamColor,cliente,tamCliente,medida,tamMedida);
        }
    }
}

void informarColorPredominante(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente)
{
    int colorMax;
    int flag=1;
    int indice=0;
    char descripcionColores[tamColor][20];
    int colores[tamTipo];
    int mC;

    //inicializo el vector de colores en cero (se guardaran la cantidad de colores en su respectivo indice)
    for(int i=0 ; i<tamColor ; i++)
    {
        colores[i]=0;
    }
    //cuento la cantidad de cada color.
    for(int c=0 ; c<tamColor ; c++)
    {
        for(int m=0 ; m<tamMas ; m++)
        {
            if(color[c].id==mas[m].idColor)
            {
                colores[c]++;
            }
        }
    }

    //busco el maximo.
    for(int i=0 ; i<tamColor ; i++)
    {
        if(colorMax<colores[i] || flag==1)
        {
            colorMax=colores[i];
            flag=0;
        }
    }

    //cuanto la cantidadde maximos iguales que existen.
    for(int i=0 ; i<tamColor ; i++)
    {
        if(colorMax==colores[i])
        {
            colores[indice]=i;
            indice++;
        }
    }

    //cargo la descripcion de cada color.
    for(int i=0 ; i<indice ; i++)
    {
        mC=colores[i];
        cargarColor(descripcionColores[i],mC+5000,color,tamColor);
    }

    // muestro por pantalla los colores maximosñ.
    printf("Color/es predominante/s \n\n");
    for(int i=0 ; i<indice ; i++)
    {
        printf("%s\n",descripcionColores[i]);
    }
}

void informarServiciosMascota(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eServicio servicio[],int tamServicio,eTrabajo trabajo[],int tamTrabajo,eMedida medida[],int tamMedida)
{
    int auxIdMascota;
    int vecorIdServicios[20];
    int indice=0;
    char descripcionServicios[20][20];

    mostrarMascotas(mas,tamMas,tipo,tamTipo,color,tamColor,cliente,tamCliente,medida,tamMedida);
    utn_getNumero(&auxIdMascota,"ingrese id mascota\n","Error id incorrecto\n",1000,999+tamMas,-1);

    //busco y guardo los ID SERVICIO correspondiente al ID MASCOTA.
    for(int i=0; i<tamTrabajo ; i++)
    {
        if(trabajo[i].isEmpty==0 && trabajo[i].idMascota==auxIdMascota)
        {
            vecorIdServicios[indice]=trabajo[i].idServicio;
            indice++;
        }
    }

    //guardo en la matriz DESVRIPCION_SERVICIO la descripcion del servicio correspondiante al Id servicio.
    system("cls");
    printf("\n::::Servicios obtenidos:::: \n");
    for(int i=0 ; i<indice ; i++)
    {
        cargarServicio(descripcionServicios[i],vecorIdServicios[i],servicio,tamServicio);
        printf("- %s \n",descripcionServicios[i]);
    }


}
void informarTotalGasto(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eServicio servicio[],int tamServicio,eTrabajo trabajo[],int tamTrabajo,eMedida medida[],int tamMedida)
{
    int auxIdMascota;
    int vecorIdServicios[20];
    int indice=0;
    int indiceMatriz=0;
    float totalAPagar=0;
    char descripcionServicios[20][20];

    mostrarMascotas(mas,tamMas,tipo,tamTipo,color,tamColor,cliente,tamCliente,medida,tamMedida);
    utn_getNumero(&auxIdMascota,"ingrese id mascota\n","Error id incorrecto\n",1000,999+tamMas,-1);

    //busco y guardo los ID SERVICIO correspondiente al ID MASCOTA
    for(int i=0; i<tamTrabajo ; i++)
    {
        if(trabajo[i].isEmpty==0 && trabajo[i].idMascota==auxIdMascota)
        {
            vecorIdServicios[indice]=trabajo[i].idServicio;
            indice++;
        }
    }

    //guardo en la matriz DESVRIPCION_SERVICIO la descripcion del servicio correspondiante al Id servicio.
    for(int vs=0 ; vs<indice ; vs++)
    {

        for(int s=0 ; s<tamServicio ; s++)
        {
            if(vecorIdServicios[vs] == servicio[s].id)
            {
                totalAPagar+=cargarServicio(descripcionServicios[indiceMatriz],vecorIdServicios[vs],servicio,tamServicio);
                indiceMatriz++;
            }
        }
    }


    printf("\n::::Servicios obtenidos::::\n");
    for(int i=0; i<indiceMatriz ; i++)
    {
        printf("\n-%s",descripcionServicios[i]);
    }
    printf("Total a parat: $%.2f\n",totalAPagar);
}

void informarMascotasServicioRequerido(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eServicio servicio[],int tamServicio,eTrabajo trabajo[],int tamTrabajo,eMedida medida[],int tamMedida)
{
    int auxIdServicio;
    int indice=0;
    int vecorIdMascotas[100];
    char fechas[20][13];
    char descripcion[20];

    listarServicio(servicio,tamServicio);
    utn_getNumero(&auxIdServicio,"Ingrese ID (Servicio) ","Error Inexistente\n",20000,19999+tamServicio,-1);

    for(int i=0; i<tamTrabajo ; i++)
    {
        if(trabajo[i].isEmpty==0 && trabajo[i].idServicio==auxIdServicio)
        {
            vecorIdMascotas[indice]=trabajo[i].idMascota;
            snprintf(fechas[indice],12,"%02d/%02d/%d",trabajo[i].fecha.dia,trabajo[i].fecha.mes,trabajo[i].fecha.anio);//Guardo las fechas en formato string
            indice++;
        }
    }

    cargarServicio(descripcion,auxIdServicio,servicio,tamServicio);

    for(int i=0; i<indice ; i++)
    {
        vecorIdMascotas[i]=buscarMascotas(vecorIdMascotas[i],mas,tamMas);
    }


    system("cls");
    printf("::::::::::Servicio: %s::::::::::\n",descripcion);

    for(int vm=0 ; vm<indice ; vm++)
    {
        mostrarMascota(mas[vecorIdMascotas[vm]],tipo,tamTipo,color,tamColor,cliente,tamCliente,medida,tamMedida);
        printf("Fecha: %s\n",fechas[vm]);
        printf("bucle numero %d\n",vm);

    }

}

void informarFechaServicioRequerido(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eServicio servicio[],int tamServicio,eTrabajo trabajo[],int tamTrabajo)
{
    eFecha fechas;
    int vectorFKTrabajoIdServicio[20];
    char descripcion[20][20];
    int indice=0;

    mostrarFechas(trabajo,tamTrabajo);
    utn_getNumero(&fechas.dia,"Ingrese Dia: ","Error solo Digitos\n",1,31,-1);
    utn_getNumero(&fechas.mes,"        Mes: ","Error solo Digitos (1 al 12)\n",1,12,-1);
    utn_getNumero(&fechas.anio,"       Anio: ","Error solo Digitos (1980 a 2100)\n",1980,2100,-1);

    for(int i=0 ; i<tamTrabajo ; i++)
    {
        if(trabajo[i].isEmpty==0 && trabajo[i].fecha.anio==fechas.anio && trabajo[i].fecha.mes==fechas.mes && trabajo[i].fecha.dia==fechas.dia)
        {
            vectorFKTrabajoIdServicio[indice]=trabajo[i].idServicio;
            indice++;
        }
    }

    if(indice!=0)
    {
        for(int i=0 ; i<indice ; i++)
        {
            cargarServicio(descripcion[i],vectorFKTrabajoIdServicio[i],servicio,tamServicio);
        }

        system("cls");
        printf("::::::::::Fecha: %02d/%02d/%d::::::::::\nServicios:\n",fechas.dia,fechas.mes,fechas.anio);

        for(int i=0 ; i<indice ; i++)
        {
            printf("          -%s\n",descripcion[i]);
        }
    }
    else
    {
        system("cls");
        printf("\n---No se realizaron trabajos ese dia---\n");
    }
}


void mostrarFechas(eTrabajo trabajo[],int tamTrabajo)
{
    for(int i=0 ; i<tamTrabajo ; i++)
    {
        if(trabajo[i].isEmpty==0)
        {
            printf("%02d/%02d/%d\n",trabajo[i].fecha.dia,trabajo[i].fecha.mes,trabajo[i].fecha.anio);
        }
    }
}


void informeCantMascotasBajas(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eServicio servicio[],int tamServicio,eTrabajo trabajo[],int tamTrabajo,eMedida medida[],int tamMedida)
{
    for(int i=0 ; i<tamMas ; i++)
    {
        if(mas[i].idMedida==301)
        {
            mostrarMascota(mas[i],tipo,tamTipo,color,tamColor,cliente,tamCliente,medida,tamMedida);
        }
    }
}

void informeMascotasPorMedidaDeseada(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eServicio servicio[],int tamServicio,eTrabajo trabajo[],int tamTrabajo,eMedida medida[],int tamMedida)
{

    int opcion= menuMedida();

    for(int i=0 ; i<tamMas ; i++)
    {
        if(mas[i].idMedida==medida[opcion-1].id)
        {
            mostrarMascota(mas[i],tipo,tamTipo,color,tamColor,cliente,tamCliente,medida,tamMedida);
        }
    }
}

void informeMascotaPorMedida(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eServicio servicio[],int tamServicio,eTrabajo trabajo[],int tamTrabajo,eMedida medida[],int tamMedida)
{

    char auxDescripcion[20];

    for(int t=0 ; t<tamTipo ; t++)
    {
        cargarMedida(auxDescripcion,300+t,medida,tamMedida);

        printf("\n-------------------------------Medida: %s-------------------------------\n\n",auxDescripcion);

        for(int m=0 ; m<tamMas ; m++)
        {
            if(mas[m].idMedida==medida[t].id)
            {
                mostrarMascota(mas[m],tipo,tamTipo,color,tamColor,cliente,tamCliente,medida,tamMedida);
            }
        }
    }
}

void informeMedidaPredominante(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eServicio servicio[],int tamServicio,eTrabajo trabajo[],int tamTrabajo,eMedida medida[],int tamMedida)
{
    int contador[3]= { };
    int max;
    int flag=1;
    int indice=0;
    char descripcion[20];

    //cuento la macnt de mascotas con su respectiba medida
    for(int j=0 ; j<tamMedida ; j++)
    {
        for(int i=0; i<tamMas ; i++)
        {
            if(mas[i].idMedida==medida[j].id)
            {
                contador[j]++;
            }
        }
    }

    //busco maximo
    for(int i=0; i<tamMedida ; i++)
    {
        if(max<contador[i] || flag==1)
        {
            max=contador[i];
            flag=0;
        }
    }
    // busco si hay otro max medidas
    for(int i=0; i<tamMedida ; i++)
    {
        if(max==contador[i])
        {
            contador[indice]=i;
            indice++;
        }

    }

    //muestro los mayores
    printf("El/Los mayores son: \n");
    for(int i=0; i<indice ; i++)
    {
        cargarMedida(descripcion,medida[contador[i]].id,medida,tamMedida);
        printf("              10    -%s\n\n",descripcion);
    }
}

void inforMascotaJovenMedidaBaja(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eServicio servicio[],int tamServicio,eTrabajo trabajo[],int tamTrabajo,eMedida medida[],int tamMedida)
{
    int contadorEdadesBajos[tamMas];
    int cantBajos=0;
    int flag=1;
    int min;

    for(int i=0; i<tamMas ; i++)
    {
        if(mas[i].idMedida==medida[0].id)
        {
            contadorEdadesBajos[cantBajos]=mas[i].edad;
            cantBajos++;
        }
    }

    for(int i=0; i<cantBajos ; i++)
    {
        if(min<contadorEdadesBajos[i] || flag==1)
        {
            min=contadorEdadesBajos[i];
            flag=0;
        }
    }

    printf("La Mascota menor mas baja es: \n");

    for(int i=0; i< tamMas ; i++)
    {
        if(mas[i].edad==min && mas[i].idMedida==medida[0].id)
        {
            mostrarMascota(mas[i],tipo,tamTipo,color,tamColor,cliente,tamCliente,medida,tamMedida);
        }
    }
}

void informePorTipoMedidaDeseada(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eServicio servicio[],int tamServicio,eTrabajo trabajo[],int tamTrabajo,eMedida medida[],int tamMedida)
{
    int opcionColor = menuColor();
    int opcionMedida = menuMedida();


    for(int i=0; i< tamMas ; i++)
    {
        if(mas[i].idColor==(opcionColor+4999) && mas[i].idMedida==(opcionMedida+299))
        {
            mostrarMascota(mas[i],tipo,tamTipo,color,tamColor,cliente,tamCliente,medida,tamMedida);
        }
    }
}

void informeClientesConMascotarMedidaDeseada(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eServicio servicio[],int tamServicio,eTrabajo trabajo[],int tamTrabajo,eMedida medida[],int tamMedida)
{
    int opcionMedida=menuMedida();
    int arrayBajos[tamMas];
    int indice=0;
    char descripcion[20];


    for(int i=0; i< tamMas ; i++)
    {
        if((opcionMedida+299) == mas[i].idMedida)
        {
            arrayBajos[indice]=i;
            indice++;
        }
    }

    for(int i=0; i< indice ; i++)
    {
        cargarCliente(descripcion,mas[arrayBajos[i]].idCliente,cliente,tamCliente);

        printf("                         .....:::%s:::.....\n",descripcion);
        mostrarMascota(mas[arrayBajos[i]],tipo,tamTipo,color,tamColor,cliente,tamCliente,medida,tamMedida);
        printf("-----------------------------------------------------------------\n");
    }
}

void informarCantidadMascotasPorCliente(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eServicio servicio[],int tamServicio,eTrabajo trabajo[],int tamTrabajo,eMedida medida[],int tamMedida)
{
    int clientesCantMascotas[tamCliente];
    char descripcion[20];


    for(int j=0; j< tamCliente ; j++)
    {
        clientesCantMascotas[j]=0;

        for(int i=0; i< tamMas ; i++)
        {
            if(mas[i].idCliente==cliente[j].id)
            {
                clientesCantMascotas[j]++;
            }
        }
    }

    for(int i=0; i< tamCliente ; i++)
    {
        cargarCliente(descripcion,cliente[i].id,cliente,tamCliente);
        printf("Cliente: %s tiene %d macota/s\n",descripcion,clientesCantMascotas[i]);
    }


}
