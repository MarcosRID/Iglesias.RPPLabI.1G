#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN.h"

int calcularMayor(int* pResultado,int num1,int num2)
{
    int todoOk=-1;

    if(pResultado!=NULL)
    {
        if(num1==num2)
        {
            todoOk=0;
        }else
        {
            if(num1>num2)
            {
                *pResultado=num1;
                todoOk=1;
            }
            else
            {
                *pResultado=num2;
                todoOk=2;
            }
        }
    }
    return todoOk;
}
//------------------------------------------------------------------------
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
//------------------------------------------------------------------------
int utn_getNumeroFlotante( float * pResultado,char * mensaje,char * mensajeError,float minimo,float maximo,int reintentos)
{
    int todoOk=-1;
    float bufferFloat;

    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && (reintentos>=0 || reintentos==-1))
    {
        do
        {
            printf("%s",mensaje);

            if(getFloat(&bufferFloat)==0 && minimo<=bufferFloat && bufferFloat<=maximo)
            {
                todoOk=0;
                *pResultado=bufferFloat;
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
int esFlotante(char* cadena)//devuelve verdadero  o falso
{
    int todoOk=-1;
    int i=0;
    int contadorPuntos=0;

    if(cadena[0]=='-' || cadena[0]=='+' )
    {
        i=1;
    }
    for(/*inicialice la i afuera*/; cadena[i]!='\0' ; i++)
    {
        if('9'<cadena[i] || cadena[i]<'0')//busco si hay caracteres.
        {
            if(cadena[i]=='.')
            {
                contadorPuntos++;

                if(contadorPuntos>1)
                {
                    todoOk=-1;
                    break;
                }
            }else
            {
                todoOk=-1;
                break;
            }
        }
        todoOk=0;
    }

    return todoOk;
}
//------------------------------------------------------------------------
int getFloat(float* pResultado)
{
    int todoOk=-1;
    char buffer[400];
    fflush(stdin);

    if(myGets(buffer,400)==-1 && esFlotante(buffer)==0)
    {
        todoOk=0;
        *pResultado=atof(buffer);
    }
    return todoOk;
}
//------------------------------------------------------------------------
int imprimirNumeros(int* arrayInt,int len)
{
    int todoOk=-1;

    if(arrayInt != NULL && len>0)
    {
        for(int i=0; i< len ; i++)
        {
            printf("indice: %d  valor:%d\n",i,arrayInt[i]);
        }
        todoOk=0;
    }
    return todoOk;
}
//------------------------------------------------------------------------
int cargarArrayInt(int* arrayInt,int len)
{
    int todoOk=-1;

    if(arrayInt != NULL)
    {
        for(int i=0; i< len ; i++)
        {
            utn_getNumero(&arrayInt[i],"\nIngrese un numero: ","\nERROR solo numeros entre -999 y 999",-999,999,-1);
        }
        todoOk=0;
    }
    return todoOk;
}
//------------------------------------------------------------------------
int borrarInpares(int* arrayInt,int len)
{
    int todoOk=-1;

    if(arrayInt != NULL)
    {
        for(int i=0; i< len ; i++)
        {
            if(arrayInt[i] % 2 !=0)
            {
                arrayInt[i]=0;
            }
        }
        todoOk=0;
    }
    return todoOk;
}
//------------------------------------------------------------------------
int borrarPares(int* arrayInt,int len)
{
    int todoOk=-1;

    if(arrayInt != NULL)
    {
        for(int i=0; i< len ; i++)
        {
            if(arrayInt[i] % 2 ==0)
            {
                arrayInt[i]=0;
            }
        }
        todoOk=0;
    }
    return todoOk;
}
