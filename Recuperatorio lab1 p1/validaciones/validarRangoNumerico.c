#include "validarRangoNumerico.h"

int vaidarRangoNumerico(int numero,int limiteInferior,int limiteSuperior)
{
    int todoOk=1;

    if (numero>limiteInferior && numero<limiteSuperior)
    {
        todoOk=-1;
    }

    return todoOk;
}
