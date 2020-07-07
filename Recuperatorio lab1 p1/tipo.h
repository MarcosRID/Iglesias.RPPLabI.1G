#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];

} eTipo;

#endif // TIPO_H_INCLUDED

/** \brief menu del los TIPO DE MASCOTAS
 *
 * \return el numero correspondiente a la opcion.
 *
 */
int menuTipo(void);


/** \brief
 *
 * \param tipo[] eTipo
 * \param tamTipo int
 * \return void
 *
 */
void listarTipo(eTipo tipo[],int tamTipo);

/** \brief obtiene el valor del campo id de una estructura eTipo
 *
 * \param vector de char en donde se guardara dicho valor
 * \param id del tipo de animal que requiero
 * \param vector de tipo eTipo
 * \param tamaño del vector eTipo
 * \return void
 *
 */
void cargarTipo(char descripcion[],int id,eTipo tipo[],int tamTipo);
