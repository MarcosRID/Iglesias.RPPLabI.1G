#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED


typedef struct
{
    int id;
    char descripcion[20];
    float precio;

} eServicio;


#endif // SERVICIO_H_INCLUDED


/** \brief mustra por pantalla los servicios
 *
 * \param vector de tipo eServicio
 * \param tamaño del vector eServicio
 * \return void
 *
 */
void listarServicio(eServicio servicio[],int tamServicio);

/** \brief obtener el valor del campo DESCRIPCION de tipo eServicio.
 *
 * \param vector en donde se cargara dicho valor.
 * \param id del servicio que solicite.
 * \param vector de tipo eServicio
 * \param tamaño del vector eServicio
 * \return retorna el precio del servicio seleccionado ó -1 si no se logro conseguir.
 *
 */
float cargarServicio(char descripcion[],int id,eServicio servicio[],int tamServicio);

int buscarServicio(int id,eServicio servicio[],int tamServicio);

