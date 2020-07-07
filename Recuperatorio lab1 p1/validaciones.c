#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"


int validarRangoNumerico(int numero,int limiteInferior,int limiteSuperior)
{
    int todoOk=-1;

    if (numero>(limiteInferior -1) && numero<(limiteSuperior +1 ))
    {
        todoOk=1;
    }

    return todoOk;
}
//_________________________________________________________
int validarLargoString(char cadena[],int largo)
{
    int todoOk=-1;
    int i=-1;

    do
    {
        i++;
    }
    while(cadena[i]!='\0');

    if(i<largo)
    {
        todoOk=1;
    }

    return todoOk;
}
//_________________________________________________________
int myGets(char* cadena,int len)
{
    int todoOk=-1;
    fflush(stdin);
    fgets(cadena,len,stdin);
    cadena[strlen(cadena)-1]='\0';

//    scanf("%s",buffer); scanf es peligroso ya que deja un BAG  de seguridad
    return todoOk;
}
//-----------------------------------------------------------------------
int utn_getCaracter( char * pResultado,char * mensaje,char * mensajeError,char minimo,char maximo,int reintentos)
{
    int todoOk=-1;
    char bufferChar;

    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && (reintentos>=0 || reintentos==-1))
    {
        do
        {
            printf("%s",mensaje);
            fflush(stdin);
            scanf("%c",&bufferChar);

            if(minimo<=bufferChar && bufferChar<=maximo)
            {
                todoOk=0;
                *pResultado=bufferChar;
                break;
            }
            else
            {
                printf("%s",mensajeError);
            }
            if(reintentos!=-1)
            {
                reintentos--;
            }
        }while(0<reintentos || reintentos==-1);
    }
    return todoOk;
}
//------------------------------------------------------------------------
int getInt(int* pResultado)
{
    int todoOk=-1;
    char buffer[400];
    fflush(stdin);

    if(myGets(buffer,400)==-1 && esNumerica(buffer)==1)
    {
        todoOk=0;
        *pResultado=atoi(buffer);
    }
    return todoOk;
}
//------------------------------------------------------------------------
int esNumerica(char* cadena)//devuelve verdadero  o falso
{
    int todoOk=1;
    int i=0;

    if(cadena[0]=='-')
    {
        i=1;
    }
    for(/*inicialice la i afuera*/; cadena[i]!='\0' ; i++)
    {
        if('9'<cadena[i] || cadena[i]<'0')//busco si hay caracteres.
        {
            todoOk=0;
            break;
        }
    }
    return todoOk;
}
//------------------------------------------------------------------------
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
    int todoOk=-1;
    int bufferInt;

    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && (reintentos>=0 || reintentos==-1))// si es -1 pasa a ser un bucle infinito
    {
        do
        {
            printf("%s",mensaje);

//            scanf("%d",&bufferInt);

            if(getInt(&bufferInt)==0 && minimo<=bufferInt && bufferInt<=maximo)
            {
                todoOk=0;
                *pResultado=bufferInt;
                break;
            }
            else
            {
                printf("%s",mensajeError);
            }

            if(reintentos!=-1)
            {
                reintentos--;
            }
        }
        while(0<reintentos || reintentos==-1);
    }
    return todoOk;
}
