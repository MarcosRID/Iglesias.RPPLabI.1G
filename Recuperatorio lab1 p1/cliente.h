#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED


typedef struct
{
    int id;
    char nombre[20];
    char genero;

} eCliente;


#endif // CLIENTE_H_INCLUDED

/** \brief Lista los elementos de tipo eCliente.
 *
 * \param Recibe vector de tipo eCliente.
 * \param Tamaño del vector
 * \return void
 *
 */
void listarClientes(eCliente cliente[],int tamCliente);

/** \brief Carga en un vector de char el valor del campo NOMBRE del vector de estructuras  eCliente mediante su valor del campo ID
 *
 * \param vector de tipo char
 * \param enter (el cual se utiliza para la busqueda)
 * \param vector de tipo eCliente
 * \param tamaño del vector eCliente
 * \return retorna el genero del elemento en ejecucion.
 *
 */
char cargarCliente(char nombre[],int id,eCliente cliente[],int tamCliente);
