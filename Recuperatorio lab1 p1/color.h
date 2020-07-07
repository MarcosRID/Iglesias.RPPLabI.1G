#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];


} eColor;


#endif // COLOR_H_INCLUDED

/** \brief despliega un menu por pantella de los tipo de colores
 *
 * \return retorna la opcion elegida
 *
 */
int menuColor(void);

/** \brief lista lo elementos del array.
 *
 * \param vector de eColores.
 * \param tamaño del vector
 * \return void
 *
 */
void listarColor(eColor color[],int tamColor);

/** \brief obtiene el valor del campo DESCRIPCION del elemento eCliente.
 *
 * \param vector de char donde se guarda dicho dato
 * \param ID por el cual busca en el vector de eCliente.
 * \param vector de eColores
 * \param tamaño del vector de colores
 * \return void
 *
 */
void cargarColor(char descripcion[],int id,eColor color[],int tamColor);
