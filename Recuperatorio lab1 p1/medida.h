#ifndef MEDIDA_H_INCLUDED
#define MEDIDA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];

}eMedida;


#endif // MEDIDA_H_INCLUDED

int menuMedida(void);
void listarMedidas(eMedida medida[],int tamMedida);
void cargarMedida(char descripcion[],int id,eMedida medida[],int tamMedida);
