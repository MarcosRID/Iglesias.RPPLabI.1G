#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED



#endif // VALIDACIONES_H_INCLUDED

/** \brief Obtiene un numero entero entre el rango especificado.
 *
 * \param pResultado int* (guardo el entero validado)
 * \param mensaje char* (minima instruccion)
 * \param mensajeError char* (Mensaje de Fallos)
 * \param minimo int
 * \param maximo int
 * \param reintentos >=0 ó -1 para reintentos ilimitados
 * \return int
 *
 */
int utn_getNumero( int * pResultado,char * mensaje,char * mensajeError,int minimo,int maximo,int reintentos);

/** \brief Verifica si es solo contiene valores numericos enteros
 *
 * \param cadena char*
 * \return error -1 ó 0 success
 *
 */
int esNumerica(char* cadena);

/** \brief Obtiene un int validado.
 *
 * \param pResultado int*
 * \return int
 *
 */
int getInt(int* pResultado);

/** \brief  obtiene y retorna un string
 *
 * \param cadena char*
 * \param tamaño del array
 * \return int
 *
 */
int myGets(char* cadena,int len);

/** \brief verifica si un numero esta entre los parametros estimados.
 *
 * \param numero entero a verificar.
 * \param numero entero inferior.
 * \param numero entero superior.
 * \return 1 si esta entre los parametros ó -1 mo esta entre los parametros.
 *
 */

int VaidarRangoNumerico(int numero,int limiteInferior,int limiteSuperior);

/** \brief valida si un cadena es mas grande que el rango estimado.
 *
 * \param vector de caracteres a evaluar.
 * \param entero escalar (limite de caracteres)
 * \return -1 si la cadena es mas grande ó 1 si la cadena es mas chica o igual.
 *
 */

int validarLargoString(char cadena[],int largo);
