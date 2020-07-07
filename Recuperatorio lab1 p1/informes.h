#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED

/** \brief Despliga por pantalla el menu de informes.
 *
 * \param void.
 * \return la opcion seleccionada.
 *
 */
int menuInforme(void);

/** \brief Muestra por pantalla las mascotas del color elegido por el usuario.
 *
 * \param Vector de tipo eMascota.
 * \param Tamaño del vector eMascota.
 * \param Vector de tipo eTipo.
 * \param Tamaño del vector eTipo.
 * \param Vector de tipo eColor.
 * \param Tamaño del vector eColor.
 * \param Vector de tipo eCliente.
 * \param Tamaño del vector eCliente.
 * \return Void.
 *
 */
void infomeMascotasColor(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eMedida medida[],int tamMedida);

/** \brief Muestra por pantalla las mascotas del tipo seleccionado por el usuario.
 *
 * \param Vector de tipo eMascota.
 * \param Tamaño del vector eMascota.
 * \param Vector de tipo eTipo.
 * \param Tamaño del vector eTipo.
 * \param Vector de tipo eColor.
 * \param Tamaño del vector eColor.
 * \param Vector de tipo eCliente.
 * \param Tamaño del vector eCliente.
 * \return Void.
 *
 */
void infomeMascotasTipo(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eMedida medida[],int tamMedida);

/** \brief informa las mascotas del tipo seleccionado por el usuario.
 *
 * \param Vector de tipo eMascota.
 * \param Tamaño del vector eMascota.
 * \param Vector de tipo eTipo.
 * \param Tamaño del vector eTipo.
 * \param Vector de tipo eColor.
 * \param Tamaño del vector eColor.
 * \param Vector de tipo eCliente.
 * \param Tamaño del vector eCliente.
 * \return retorna la cantidad de mascotas mas jovenes.
 *
 */
int infomeMascotaMenor(int masMenores[], eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente);

/** \brief Muestro por pantalla las mascotas que perteneces a cada tipo.
 *
 * \param Vector de tipo eMascota.
 * \param Tamaño del vector eMascota.
 * \param Vector de tipo eTipo.
 * \param Tamaño del vector eTipo.
 * \param Vector de tipo eColor.
 * \param Tamaño del vector eColor.
 * \param Vector de tipo eCliente.
 * \param Tamaño del vector eCliente.
 * \return void.
 *
 */
void informarPorTipo(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eMedida medida[],int tamMedida);

/** \brief Muestro por pantalla las mascotas del tipo y color seleccionado por el usuario.
 *
 * \param Vector de tipo eMascota.
 * \param Tamaño del vector eMascota.
 * \param Vector de tipo eTipo.
 * \param Tamaño del vector eTipo.
 * \param Vector de tipo eColor.
 * \param Tamaño del vector eColor.
 * \param Vector de tipo eCliente.
 * \param Tamaño del vector eCliente.
 * \return void.
 *
 */
void informarPorTipoColorRequerido(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eMedida medida[],int tamMedida);

/** \brief Muestro por pantalla el/los colores predominantes.
 *
 * \param Vector de tipo eMascota.
 * \param Tamaño del vector eMascota.
 * \param Vector de tipo eTipo.
 * \param Tamaño del vector eTipo.
 * \param Vector de tipo eColor.
 * \param Tamaño del vector eColor.
 * \param Vector de tipo eCliente.
 * \param Tamaño del vector eCliente.
 * \return void.
 *
 */
void informarColorPredominante(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente);

/** \brief Muestro por pantalla los servicios que se le realizo a una mascota, la cual fue elegida por el usuario.
 *
 * \param Vector de tipo eMascota.
 * \param Tamaño del vector eMascota.
 * \param Vector de tipo eTipo.
 * \param Tamaño del vector eTipo.
 * \param Vector de tipo eColor.
 * \param Tamaño del vector eColor.
 * \param Vector de tipo eCliente.
 * \param Tamaño del vector eCliente.
 * \param vector de tipo eServicio.
 * \param tamaño del vector eServicio.
 * \param vector de tipo eTrabajo.
 * \param tamaño del vector eTrabajo.
 * \return void.
 *
 */
void informarServiciosMascota(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eServicio servicio[],int tamServicio,eTrabajo trabajo[],int tamTrabajo,eMedida medida[],int tamMedida);

/** \brief Muestro por pantalla los servicios y el total a abonar de una mascota (Elegida por el usuario)
 *
 * \param Vector de tipo eMascota.
 * \param Tamaño del vector eMascota.
 * \param Vector de tipo eTipo.
 * \param Tamaño del vector eTipo.
 * \param Vector de tipo eColor.
 * \param Tamaño del vector eColor.
 * \param Vector de tipo eCliente.
 * \param Tamaño del vector eCliente.
 * \param vector de tipo eServicio.
 * \param tamaño del vector eServicio.
 * \param vector de tipo eTrabajo.
 * \param tamaño del vector eTrabajo.
 * \return void.
 *
 */
void informarTotalGasto(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eServicio servicio[],int tamServicio,eTrabajo trabajo[],int tamTrabajo,eMedida medida[],int tamMedida);

/** \brief Muestro por pantalla los trabajos ,y su respectiva mascota, dependiando del servicio que ingrese el usuario.
 *
 * \param Vector de tipo eMascota.
 * \param Tamaño del vector eMascota.
 * \param Vector de tipo eTipo.
 * \param Tamaño del vector eTipo.
 * \param Vector de tipo eColor.
 * \param Tamaño del vector eColor.
 * \param Vector de tipo eCliente.
 * \param Tamaño del vector eCliente.
 * \param vector de tipo eServicio.
 * \param tamaño del vector eServicio.
 * \param vector de tipo eTrabajo.
 * \param tamaño del vector eTrabajo.
 * \return void.
 *
 */
void informarMascotasServicioRequerido(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eServicio servicio[],int tamServicio,eTrabajo trabajo[],int tamTrabajo,eMedida medida[],int tamMedida);

/** \brief Muestro por pantalla los servicios que se realizasor segun la fecha ingresada por el usuario.
 *
 * \param Vector de tipo eMascota.
 * \param Tamaño del vector eMascota.
 * \param Vector de tipo eTipo.
 * \param Tamaño del vector eTipo.
 * \param Vector de tipo eColor.
 * \param Tamaño del vector eColor.
 * \param Vector de tipo eCliente.
 * \param Tamaño del vector eCliente.
 * \param vector de tipo eServicio.
 * \param tamaño del vector eServicio.
 * \param vector de tipo eTrabajo.
 * \param tamaño del vector eTrabajo.
 * \return void.
 */
void informarFechaServicioRequerido(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eServicio servicio[],int tamServicio,eTrabajo trabajo[],int tamTrabajo);

/** \brief Muestra por pantalla las fechas del los trabajos dados de alta.
 *
 * \param vector de tipo eTrabajo
 * \param tamaño del vector eTrabajo
 * \return void
 *
 */
void mostrarFechas(eTrabajo trabajo[],int tamTrabajo);


/** \brief inforam la cantidad de mascotas que tiene cada cliente
 *
 * \param mas[] eMascota
 * \param tamMas int
 * \param tipo[] eTipo
 * \param tamTipo int
 * \param color[] eColor
 * \param tamColor int
 * \param cliente[] eCliente
 * \param tamCliente int
 * \param servicio[] eServicio
 * \param tamServicio int
 * \param trabajo[] eTrabajo
 * \param tamTrabajo int
 * \param medida[] eMedida
 * \param tamMedida int
 * \return void
 *
 */
void informarCantidadMascotasPorCliente(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eServicio servicio[],int tamServicio,eTrabajo trabajo[],int tamTrabajo,eMedida medida[],int tamMedida);

/** \brief muestra por pantalla las mascotas de la medida que seleccione el usuario
 *
 * \param mas[] eMascota
 * \param tamMas int
 * \param tipo[] eTipo
 * \param tamTipo int
 * \param color[] eColor
 * \param tamColor int
 * \param cliente[] eCliente
 * \param tamCliente int
 * \param servicio[] eServicio
 * \param tamServicio int
 * \param trabajo[] eTrabajo
 * \param tamTrabajo int
 * \param medida[] eMedida
 * \param tamMedida int
 * \return void
 *
 */
void informeMascotasPorMedidaDeseada(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eServicio servicio[],int tamServicio,eTrabajo trabajo[],int tamTrabajo,eMedida medida[],int tamMedida);

/** \brief Lista las mascotas separadas agrupadas por su medida
 *
 * \param mas[] eMascota
 * \param tamMas int
 * \param tipo[] eTipo
 * \param tamTipo int
 * \param color[] eColor
 * \param tamColor int
 * \param cliente[] eCliente
 * \param tamCliente int
 * \param servicio[] eServicio
 * \param tamServicio int
 * \param trabajo[] eTrabajo
 * \param tamTrabajo int
 * \param medida[] eMedida
 * \param tamMedida int
 * \return void
 *
 */
void informeMascotaPorMedida(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eServicio servicio[],int tamServicio,eTrabajo trabajo[],int tamTrabajo,eMedida medida[],int tamMedida);

/** \brief Muestra por panalla la medida predominante
 *
 * \param mas[] eMascota
 * \param tamMas int
 * \param tipo[] eTipo
 * \param tamTipo int
 * \param color[] eColor
 * \param tamColor int
 * \param cliente[] eCliente
 * \param tamCliente int
 * \param servicio[] eServicio
 * \param tamServicio int
 * \param trabajo[] eTrabajo
 * \param tamTrabajo int
 * \param medida[] eMedida
 * \param tamMedida int
 * \return void
 *
 */
void informeMedidaPredominante(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eServicio servicio[],int tamServicio,eTrabajo trabajo[],int tamTrabajo,eMedida medida[],int tamMedida);

/** \brief informa la mascota mas joben de estatura baja
 *
 * \param mas[] eMascota
 * \param tamMas int
 * \param tipo[] eTipo
 * \param tamTipo int
 * \param color[] eColor
 * \param tamColor int
 * \param cliente[] eCliente
 * \param tamCliente int
 * \param servicio[] eServicio
 * \param tamServicio int
 * \param trabajo[] eTrabajo
 * \param tamTrabajo int
 * \param medida[] eMedida
 * \param tamMedida int
 * \return void
 *
 */
void inforMascotaJovenMedidaBaja(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eServicio servicio[],int tamServicio,eTrabajo trabajo[],int tamTrabajo,eMedida medida[],int tamMedida);

/** \brief lista las mascotas segun la medida que elija el usuario
 *
 * \param mas[] eMascota
 * \param tamMas int
 * \param tipo[] eTipo
 * \param tamTipo int
 * \param color[] eColor
 * \param tamColor int
 * \param cliente[] eCliente
 * \param tamCliente int
 * \param servicio[] eServicio
 * \param tamServicio int
 * \param trabajo[] eTrabajo
 * \param tamTrabajo int
 * \param medida[] eMedida
 * \param tamMedida int
 * \return void
 *
 */
void informePorTipoMedidaDeseada(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eServicio servicio[],int tamServicio,eTrabajo trabajo[],int tamTrabajo,eMedida medida[],int tamMedida);

/** \brief muestra los clientes segun la medida que seleccione el usuario
 *
 * \param mas[] eMascota
 * \param tamMas int
 * \param tipo[] eTipo
 * \param tamTipo int
 * \param color[] eColor
 * \param tamColor int
 * \param cliente[] eCliente
 * \param tamCliente int
 * \param servicio[] eServicio
 * \param tamServicio int
 * \param trabajo[] eTrabajo
 * \param tamTrabajo int
 * \param medida[] eMedida
 * \param tamMedida int
 * \return void
 *
 */
void informeClientesConMascotarMedidaDeseada(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eServicio servicio[],int tamServicio,eTrabajo trabajo[],int tamTrabajo,eMedida medida[],int tamMedida);

/** \brief informa la cantidad de mascotas bajas
 *
 * \param mas[] eMascota
 * \param tamMas int
 * \param tipo[] eTipo
 * \param tamTipo int
 * \param color[] eColor
 * \param tamColor int
 * \param cliente[] eCliente
 * \param tamCliente int
 * \param servicio[] eServicio
 * \param tamServicio int
 * \param trabajo[] eTrabajo
 * \param tamTrabajo int
 * \param medida[] eMedida
 * \param tamMedida int
 * \return void
 *
 */
void informeCantMascotasBajas(eMascota mas[],int tamMas,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente,eServicio servicio[],int tamServicio,eTrabajo trabajo[],int tamTrabajo,eMedida medida[],int tamMedida);

