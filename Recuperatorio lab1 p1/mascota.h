#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    int idTipo;
    int idColor;
    int edad;
    int idCliente;
    int idMedida;
    int isEmpty;

} eMascota;


#endif // MASCOTA_H_INCLUDED




/** \brief menu de opciones pirncipal
 *
 * \return retorna el numero de la opcion correspondiente.
 *
 */
int menu(void);

/** \brief inicializa el campo isEmpty en 1 indicando que esta vacio
 *
 * \param vector de tipo eMascota.
 * \param tamaño del vecto.
 * \return void
 *
 */
void inisializarMascotas(eMascota mas[],int tamMas);

/** \brief buscar un elemento con el primer con el campo isEmpty
 *
 * \param vector de tipo eMascota.
 * \param tamaño del vector
 * \return void
 *
 */
int buscarLibreMascota(eMascota mas[],int tamMas);

/** \brief carga un elemento vacio en el vector de tipo eMascota
 *
 * \param id correspondiente al elemento.
 * \param vector de tipo eMascota
 * \param tamaño del vector eMascota
 * \param vector de tipo eTipo
 * \param tamaño del vector eTipo
 * \param vector de tipo eCliente
 * \param tamaño del vector eCliente
 * \return 1 realizo con exito ó 0 si no se logro encontrar espacio
 *
 */
int altaMascota(int id,eMascota mas[],int tamMas,eTipo tipo[],eColor color[],eCliente cliente[],int tamCliente,eMedida medida[],int tamMedida);

/** \brief modifica 1 valor de 1 elemento.
 *
 * \param vector de tipo eMascota.
 * \param tamaño del vector de eMascota
 * \param vector de tipo eTipo
 * \param tamaño del vector eTipo
 * \param vector de tipo eColor
 * \param tamaño del vector eColor
 * \param vector de tipo eCliente
 * \param tamaño del vector eCliente
 * \return 1 realizo con exito ó 0 si no se logro dar de alta
 *
 */
int modificarMascota(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eMedida medida[],int tamMedida);

/** \brief muestra los valores de los campo de una estructura de tipo eMascota
 *
 * \param valor de tipo eMascota
 * \param tipo[] eTipo
 * \param tamTipo int
 * \param color[] eColor
 * \param tamColor int
 * \param cliente[] eCliente
 * \param tamCliente int
 * \return void
 *
 */
void mostrarMascota(eMascota mas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eMedida medida[],int tamMedida);

/** \brief
 *
 * \param mas[] eMascota
 * \param tamMas int
 * \param tipo[] eTipo
 * \param tamTipo int
 * \param color[] eColor
 * \param tamColor int
 * \param cliente[] eCliente
 * \param tamCliente int
 * \return void
 *
 */
void mostrarMascotas(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eMedida medida[],int tamMedida);

/** \brief busca en el vector ,comparando du campo id con el id ingresado, un elemento tipo eMascota.
 *
 * \param id del elemento requerido. (int)
 * \param vector de tipo eMascota.
 * \param tamaño del vector eMascota
 * \return indice si se realizo con exito ó 0 si no enxiste.
 *
 */
int buscarMascotas(int id,eMascota mas[],int tamMas);

/** \brief realisa una baja logica a un elemento
 *
 * \param vector de tipo eMascota
 * \param tamaño del vector eMascota
 * \param vector de tipo eTipo
 * \param tamaño del vector eTipo
 * \param vector de tipo eColor
 * \param tamaño del vector eColor
 * \param vector de tipo eCliente
 * \param tamaño del vector eCliente
 * \return 1 realizo con exito ó 0 si no se logro dar de encontrar
 *
 */
int bajaMascota(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eMedida medida[],int tamMedida);
/** \brief muestra por pantalla los elementos de un vector ordenados por tipo y nombre
 *
 * \param vector de tipo eMascota
 * \param tamaño del vector eMascota.
 * \param vector de tipo eTipo
 * \param tamaño del vector eTipo
 * \param vector de tipo eColor
 * \param tamaño del vector eColor
 * \param vector de tipo eCliente
 * \param tamaño del vector eCliente
 * \return void
 *
 */
void mostrarMascotaPorTipoNombre(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eMedida medida[],int tamMedida);
