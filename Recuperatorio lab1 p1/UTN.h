#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED



#endif // UTN_H_INCLUDED

int calcularMayor(int* pResultado,int num1,int num2);
int myGets(char* cadena,int len);
int utn_getCaracter( char * pResultado,char * mensaje,char * mensajeError,char minimo,char maximo,int reintentos);


int utn_getNumero( int * pResultado,char * mensaje,char * mensajeError,int minimo,int maximo,int reintentos);
int esNumerica(char* cadena);
int getInt(int* pResultado);

/** \brief  imprime un array de enteros.
 *
 * \param puntero a entero (vector/array de interos);
 * \param Tamaño del array. (parametro en entero)
 * \return -1 Error ó 0 realizo la tarea con exito;
 *
 */
int imprimirNumeros(int* arrayInt,int len);

/** \brief  carga un array de enteros.
 *
 * \param puntero a entero (vector/array de interos);
 * \param Tamaño del array. (parametro en entero para no sobreescribir fuera del array);
 * \return -1 Error ó 0 realizo la tarea con exito;
 *
 */
int cargarArrayInt(int* arrayInt,int len);

/** \brief  Modifica el array dejando solo los numeros pares y reemplazando los impares por ceros.
 *
 * \param puntero a entero (vector/array de interos);
 * \param Tamaño del array. (parametro en entero );
 * \return -1 Error ó 0 realizo la tarea con exito;
 *
 */
int borrarInpares(int* arrayInt,int len);

/** \brief  Modifica el array dejando solo los numeros pares y reemplazando los pares por ceros.
 *
 * \param puntero a entero (vector/array de interos);
 * \param Tamaño del array. (parametro en entero );
 * \return -1 Error ó 0 realizo la tarea con exito;
 *
 */
int borrarPares(int* arrayInt,int len);


int utn_getNumeroFlotante( float * pResultado,char * mensaje,char * mensajeError,float minimo,float maximo,int reintentos);
int esFlotante(char* cadena);
int getFloat(float* pResultado);

