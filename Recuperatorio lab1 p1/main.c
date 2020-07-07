#include "medida.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
#include "dataWereHouse.h"

#define CANTCLIENTE 5
#define CANTCOLOR 5
#define CANTTIPO 5
#define CANTSERVICIO 3
#define CANTTRABAJO 20
#define CANTMASCOTA 100
#define LEN_MASCOTA_HARCODEADO 10
#define TAMTRABAJOS 10
#define CANTMEDIDAS 3



void hardcorderaMascotas(eMascota mas[],int tamMas);
void hardcorderaTrabajos(eTrabajo trabajo[],int tamTrabajo);

int main()
{

    eTipo tipos[CANTTIPO] = { {1000,"Ave"},{1001,"Perro"},{1002,"Gato"},{1003,"Roedor"},{1004,"Pez"} };
    eColor colores [CANTCOLOR] = { {5000,"Negro"},{5001,"Blanco"},{5002,"Gris"},{5003,"Rojo"},{5004,"Azul"} };
    eServicio servicios[CANTSERVICIO] = { {20000,"Corte",250},{20001,"Desparasitado",300},{20002,"Castrado",400} };
    eCliente clientes[CANTCLIENTE] = { {1000,"Maria",'F'},{1001,"Luisa",'F'},{1002,"Carla",'F'},{1003,"Juan",'M'},{1004,"Pedro",'M'} };
    eMascota mascotas[CANTMASCOTA];
    eTrabajo trabajos[CANTTRABAJO];
    eMedida medidas[CANTMEDIDAS] = { {300,"Bajo"},{301,"Mediano"},{302,"Alto"} };

    int idAutoMascota=1000;
    int idAutoTrabajo=1000;
    char continuar='s';
    char confirmar;
    int mascotasMenores[CANTMASCOTA]= {};
    int cantidad;
    int flag=1;

//  __________HARCODEO INICIO___________________/*
    inisializarMascotas(mascotas,CANTMASCOTA);
    inisializarTrabajose(trabajos,CANTTRABAJO);

    hardcorderaMascotas(mascotas,LEN_MASCOTA_HARCODEADO);
    idAutoMascota+=LEN_MASCOTA_HARCODEADO;

    hardcorderaTrabajos(trabajos,TAMTRABAJOS);
    idAutoTrabajo+=TAMTRABAJOS;
//  ___________HARCODEO FINAL___________________*/

    while(continuar=='s')
    {
        switch(menu())
        {
        case 1:
            system("cls");
            printf("::::::::: Alta Mascota:::::::::\n\n");

            if(altaMascota(idAutoMascota,mascotas,CANTMASCOTA,tipos,colores,clientes,CANTCLIENTE,medidas,CANTMEDIDAS)==1)
            {
                idAutoMascota++;
                printf("Se realizo opoeracion con exito\n");
                system("pause");
                flag=1;
            }
            else
            {
                printf("No se Pudo realizar la operacion\n");
                system("pause");
            }
            break;
        case 2:
            if(flag)
            {
                if(modificarMascota(mascotas,CANTMASCOTA,tipos,CANTTIPO,colores,CANTCOLOR,clientes,CANTCLIENTE,medidas,CANTMEDIDAS)==1)
                {
                    printf("Se realizo con exito la operacion\n");
                    system("pause");
                }
                else
                {
                    printf("Ocurrio un error al modificar\n");
                    system("pause");
                }
            }
            else
            {
                printf("Se debe realizar al menos 1 alta \n");
                system("pause");
            }
            break;
        case 3:
            if(flag)
            {
                system("cls");
                printf(":::::::::BAJA MASCOTA:::::::::\n");
                if(bajaMascota(mascotas,CANTMASCOTA,tipos,CANTTIPO,colores,CANTCOLOR,clientes,CANTCLIENTE,medidas,CANTMEDIDAS)==1)
                {
                    printf("Operacion realizada con exito\n");
                    system("pause");
                }
                else
                {
                    printf("Error. la operacion no se logro realizar\n");
                    system("pause");
                }
            }
            else
            {
                printf("Se debe realizar al menos 1 alta \n");
                system("pause");
            }
            break;
        case 4:
            if(flag)
            {
                system("cls");
                printf(":::::::::MOSTRAR MASCOTA:::::::::\n");
                mostrarMascotas(mascotas,CANTMASCOTA,tipos,CANTTIPO,colores,CANTCOLOR,clientes,CANTCLIENTE,medidas,CANTMEDIDAS);
                system("pause");
            }
            else
            {
                printf("Se debe realizar al menos 1 alta \n");
                system("pause");
            }
            break;
        case 5:
            if(flag)
            {
                system("cls");
                printf(":::::::::MOSTRAR MASCOTA (Tipo y Nombre):::::::::\n");
                mostrarMascotaPorTipoNombre(mascotas,CANTMASCOTA,tipos,CANTTIPO,colores,CANTCOLOR,clientes,CANTCLIENTE,medidas,CANTMEDIDAS);
                system("pause");
            }
            else
            {
                printf("Se debe realizar al menos 1 alta \n");
                system("pause");
            }
            break;
        case 6:
            if(flag)
            {
                system("cls");
                printf(":::::::::MOSTRAR COLORES:::::::::\n");
                listarColor(colores,CANTCOLOR);
                system("pause");
            }
            else
            {
                printf("Se debe realizar al menos 1 alta \n");
                system("pause");
            }
            break;
        case 7:
            if(flag)
            {
                system("cls");
                printf(":::::::::MOSTRAR SERVICIOS:::::::::\n");
                listarServicio(servicios,CANTSERVICIO);
                system("pause");
            }
            else
            {
                printf("Se debe realizar al menos 1 alta \n");
                system("pause");
            }
            break;
        case 8:
            if(flag)
            {
                altaTrabajos(idAutoTrabajo,trabajos,CANTTRABAJO,mascotas,CANTMASCOTA,tipos,CANTTIPO,colores,CANTCOLOR,servicios,CANTSERVICIO,clientes,CANTCLIENTE,medidas,CANTMEDIDAS);
            }
            else
            {
                printf("Se debe realizar al menos 1 alta \n");
                system("pause");
            }
            break;
        case 9:
            if(flag)
            {
                mostrarTrabajos(trabajos,CANTTRABAJO,mascotas,CANTMASCOTA,tipos,CANTTIPO,colores,CANTCOLOR,servicios,CANTSERVICIO,clientes,CANTCLIENTE,medidas,CANTMEDIDAS);
            }
            else
            {
                printf("Se debe realizar al menos 1 alta \n");
                system("pause");
            }
            break;
        case 10:
            if(flag)
            {
                system("cls");
                switch(menuInforme())
                {
                case 1:
                    system("cls");
                    printf("-----------Informe de mascotas (color solicitado)-----------\n\n");
                    infomeMascotasColor(mascotas,CANTMASCOTA,tipos,CANTTIPO,colores,CANTCOLOR,clientes,CANTCLIENTE,medidas,CANTMEDIDAS);
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    printf("-----------Informe de mascotas (color solicitado)-----------\n\n");
                    infomeMascotasTipo(mascotas,CANTMASCOTA,tipos,CANTTIPO,colores,CANTCOLOR,clientes,CANTCLIENTE,medidas,CANTMEDIDAS);
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    printf("-------------La mascota menor-----------\n");

                    cantidad=infomeMascotaMenor(mascotasMenores,mascotas,CANTMASCOTA,tipos,CANTTIPO,colores,CANTCOLOR,clientes,CANTCLIENTE);

                    for(int i=0; i<cantidad ; i++)
                    {
                        mostrarMascota(mascotas[mascotasMenores[i]],tipos,CANTTIPO,colores,CANTCOLOR,clientes,CANTCLIENTE,medidas,CANTMEDIDAS);

                    }
                    system("pause");
                    break;
                case 4:
                    system("cls");
                    printf("-------------Lista de mascotas (Agrupacion: TIPO)-----------\n");
                    informarPorTipo(mascotas,LEN_MASCOTA_HARCODEADO,tipos,CANTTIPO,colores,CANTCOLOR,clientes,CANTCLIENTE,medidas,CANTMEDIDAS);
                    system("pause");
                    break;
                case 5:
                    system("cls");
                    printf("-------------Lista de mascota Color Tipo Requerido-----------\n");
                    informarPorTipoColorRequerido(mascotas,LEN_MASCOTA_HARCODEADO,tipos,CANTTIPO,colores,CANTCOLOR,clientes,CANTCLIENTE,medidas,CANTMEDIDAS);
                    system("pause");
                    break;
                case 6:
                    system("cls");
                    informarColorPredominante(mascotas,LEN_MASCOTA_HARCODEADO,tipos,CANTTIPO,colores,CANTCOLOR,clientes,CANTCLIENTE);
                    system("pause");
                    break;
                case 7:
                    system("cls");
                    informarServiciosMascota(mascotas,LEN_MASCOTA_HARCODEADO,tipos,CANTTIPO,colores,CANTCOLOR,clientes,CANTCLIENTE,servicios,CANTSERVICIO,trabajos,CANTTRABAJO,medidas,CANTMEDIDAS);
                    system("pause");
                    break;
                case 8:
                    system("cls");
                    informarTotalGasto(mascotas,LEN_MASCOTA_HARCODEADO,tipos,CANTTIPO,colores,CANTCOLOR,clientes,CANTCLIENTE,servicios,CANTSERVICIO,trabajos,CANTTRABAJO,medidas,CANTMEDIDAS);
                    system("pause");
                    break;
                case 9:
                    system("cls");
                    informarMascotasServicioRequerido(mascotas,LEN_MASCOTA_HARCODEADO,tipos,CANTTIPO,colores,CANTCOLOR,clientes,CANTCLIENTE,servicios,CANTSERVICIO,trabajos,CANTTRABAJO,medidas,CANTMEDIDAS);
                    system("pause");
                    break;
                case 10:
                    system("cls");
                    informarFechaServicioRequerido(mascotas,LEN_MASCOTA_HARCODEADO,tipos,CANTTIPO,colores,CANTCOLOR,clientes,CANTCLIENTE,servicios,CANTSERVICIO,trabajos,CANTTRABAJO);
                    system("pause");
                    break;
                case 11:
                    system("cls");
                    informarCantidadMascotasPorCliente(mascotas,LEN_MASCOTA_HARCODEADO,tipos,CANTTIPO,colores,CANTCOLOR,clientes,CANTCLIENTE,servicios,CANTSERVICIO,trabajos,CANTTRABAJO,medidas,CANTMEDIDAS);
                    system("pause");
                    break;
                case 12:
                    system("cls");
                    informeMascotasPorMedidaDeseada(mascotas,LEN_MASCOTA_HARCODEADO,tipos,CANTTIPO,colores,CANTCOLOR,clientes,CANTCLIENTE,servicios,CANTSERVICIO,trabajos,CANTTRABAJO,medidas,CANTMEDIDAS);
                    system("pause");
                    break;
                case 13:
                    system("cls");
                    informeMascotaPorMedida(mascotas,LEN_MASCOTA_HARCODEADO,tipos,CANTTIPO,colores,CANTCOLOR,clientes,CANTCLIENTE,servicios,CANTSERVICIO,trabajos,CANTTRABAJO,medidas,CANTMEDIDAS);
                    system("pause");
                    break;
                case 14:
                    system("cls");
                    informeMedidaPredominante(mascotas,LEN_MASCOTA_HARCODEADO,tipos,CANTTIPO,colores,CANTCOLOR,clientes,CANTCLIENTE,servicios,CANTSERVICIO,trabajos,CANTTRABAJO,medidas,CANTMEDIDAS);
                    system("pause");
                    break;
                case 15:
                    system("cls");
                    inforMascotaJovenMedidaBaja(mascotas,LEN_MASCOTA_HARCODEADO,tipos,CANTTIPO,colores,CANTCOLOR,clientes,CANTCLIENTE,servicios,CANTSERVICIO,trabajos,CANTTRABAJO,medidas,CANTMEDIDAS);
                    system("pause");
                    break;
                case 16:
                    system("cls");
                    informePorTipoMedidaDeseada(mascotas,LEN_MASCOTA_HARCODEADO,tipos,CANTTIPO,colores,CANTCOLOR,clientes,CANTCLIENTE,servicios,CANTSERVICIO,trabajos,CANTTRABAJO,medidas,CANTMEDIDAS);
                    system("pause");
                    break;
                case 17:
                    system("cls");
                    informeClientesConMascotarMedidaDeseada(mascotas,LEN_MASCOTA_HARCODEADO,tipos,CANTTIPO,colores,CANTCOLOR,clientes,CANTCLIENTE,servicios,CANTSERVICIO,trabajos,CANTTRABAJO,medidas,CANTMEDIDAS);
                    system("pause");
                    break;
                case 18:
                    system("cls");
                    informeCantMascotasBajas(mascotas,LEN_MASCOTA_HARCODEADO,tipos,CANTTIPO,colores,CANTCOLOR,clientes,CANTCLIENTE,servicios,CANTSERVICIO,trabajos,CANTTRABAJO,medidas,CANTMEDIDAS);
                    system("pause");
                    break;
                }
            }
            else
            {
                printf("Se debe realizar al menos 1 alta \n");
                system("pause");
            }
            break;
        case 19:
            printf("Confirmar Salida s=SI n=NO \n");
            fflush(stdin);
            scanf("%c",&confirmar);
            confirmar=tolower(confirmar);

            if (confirmar=='s')
            {
                continuar='n';
            }
            else
            {
                continuar='s';
            }
            break;
        }
    }


    return 0;
}

void hardcorderaMascotas(eMascota mas[],int tamMas)
{
    for(int i=0; i < tamMas ; i++ )
    {
        mas[i].id=id[i];
        mas[i].idColor=idColor[i];
        mas[i].idTipo=idTipo[i];
        mas[i].edad=edad[i];
        mas[i].idCliente=idCliente[i];
        mas[i].idMedida=idMedida[i];
        strcpy(mas[i].nombre,nombre[i]);

        mas[i].isEmpty=0;

    }

}
void hardcorderaTrabajos(eTrabajo trabajo[],int tamTrabajo)
{
    for(int i=0; i < tamTrabajo ; i++ )
    {
        trabajo[i].id=id[i];
        trabajo[i].idMascota=idMascota[i];
        trabajo[i].idServicio=idServicio[i];
        trabajo[i].fecha.dia=dia[i];
        trabajo[i].fecha.mes=mes[i];
        trabajo[i].fecha.anio=anio[i];

        trabajo[i].isEmpty=0;
    }
}

