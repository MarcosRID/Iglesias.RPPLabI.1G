#include "fecha.h"
#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED


typedef struct
{
    int id;
    int idMascota;
    int idServicio;
    eFecha fecha;
    int isEmpty;

} eTrabajo;

#endif // TRABAJO_H_INCLUDED


/** \brief carga un elemento vacio en el vector de tipo eTrabajo
 *
 * \param id correspondiente al elemento.
 * \param vector de tipo eTrabajo.
 * \param tamaño del vector eTrabajo.
 * \param vector de tipo eMascota.
 * \param tamaño del vector eMascota.
 * \param vector de tipo eTipo.
 * \param tamaño del vector eTipo.
 * \param vector de tipo eColor.
 * \param tamaño de vector eColor.
 * \param vector de tipo eServicio.
 * \param tamaño del vector eServicio.
 * \param vector de tipo eCliente.
 * \param tamaño del vector eCliente.
 * \return -1 = Error ó 0 si logro realizar el alta.
 *
 */
int altaTrabajos(int id,eTrabajo trabajo[],int tamTrabajo,eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eServicio serv[],int tamServ,eCliente cliente[],int tamCliente,eMedida medida[],int tamMedida);

/** \brief El campo isEmpty de cada elemento del array le da como valor 1 (vacio).
 *
 * \param vector de tipo eTrabajo
 * \param tamaño del vector eTrabajo
 * \return void
 *
 */
void inisializarTrabajose(eTrabajo trabajo[],int tamTrabajo);

/** \brief realiza una busqueda en los elementos en su campo isEmpty y retorna el primero que encuentre en 1
 *
 * \param vector de tipo eTrabajo
 * \param tamaño del vector eTrabajo
 * \return retorna el indice del elemento disponible
 *
 */
int buscarLibreTrabajo(eTrabajo trabajo[],int tamTrabajo);

/** \brief Muestra por pantalla un trabajo y la mascota que corresponde.
 *
 * \param valor de tipo eTrabajo
 * \param valor de tipo eMascota
 * \param vectpr de tipo eTipo
 * \param tamaño del vector eTipo
 * \param vector de tipo eColor
 * \param tamaño del vector eColor
 * \param vector de tipo eServicio
 * \param tamaño del vector eServicio
 * \param vector de tipo eCliente
 * \param tamaño del vecor eCliente
 * \return void
 *
 */
void mostrarTrabajo(eTrabajo trabajo,eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eServicio serv[],int tamServ,eCliente cliente[],int tamCliente,eMedida medida[],int tamMedida);

/** \brief muestra los trabajos y las mascotas que le correspondan
 *
 * \param vector de tipo eTrabajo
 * \param tamaño del vector eTrabajo
 * \param vector de tipo eMascota
 * \param tamaño del vector eMascota
 * \param vector de tipo eTipo
 * \param tamaño del vector eTipo
 * \param vector de tipo eColor
 * \param tamalo del vector eColor
 * \param vector de tipo eServicio
 * \param tamaño del vector eServicio
 * \param vector de tipo eCliente
 * \param tamaño del vector eCliente
 * \return void
 *
 */
void mostrarTrabajos(eTrabajo trabajo[],int tamTrabajo,eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eServicio serv[],int tamServ,eCliente cliente[],int tamCliente,eMedida medida[],int tamMedida);

