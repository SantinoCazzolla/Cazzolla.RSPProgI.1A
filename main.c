#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
int id;
char marca[20];
int tipo;
float peso;
}eVehiculo;

///////////////////////////////////////////////////////////////////////////CONSTRUCCTORES///////////////////////////////////////////////////////////////////////////

eVehiculo* vehiculo_new();
eVehiculo* vehiculo_nuevoParametros(int id,char* marca,int tipo, float peso);

///////////////////////////////////////////////////////////////////////////SETTERS///////////////////////////////////////////////////////////////////////////

int veiculoSetMarca(eVehiculo* this,char* marca);
int vehiculoSetId(eVehiculo* this,int id);
int vehiculoSetPeso(eVehiculo* this,float peso);
int vehiculoSetTipo(eVehiculo* this,int tipo);

///////////////////////////////////////////////////////////////////////////GUARDADOS DE TEXTO Y BINARIO///////////////////////////////////////////////////////////////////////////

int guardarEnTexto(char* path, eVehiculo* vehiculo);
int guardarEnBinario(char* path, eVehiculo* vehiculo);

///////////////////////////////////////////////////////////////////////////MAIN///////////////////////////////////////////////////////////////////////////

int main()
{

    eVehiculo* Autito = vehiculo_nuevoParametros(4321, "chevrolet", 2020, 376.15);
    printf("%d\n", Autito->id);
    printf("%s\n", Autito->marca);
    printf("%d\n", Autito->tipo);
    printf("%.2f\n", Autito->peso);

    guardarEnTexto("Autito", Autito);
    guardarEnBinario("AutitoBin", Autito);


    return 0;
}

///////////////////////////////////////////////////////////////////////////CONSTRUCCTORES///////////////////////////////////////////////////////////////////////////

eVehiculo* vehiculo_new()
{
    eVehiculo* p =(eVehiculo*) malloc(sizeof(eVehiculo));
    if(p!= NULL)
    {
        p->id=0;
        p->peso=0;
        p->tipo=0;
        strcpy(p->marca, " ");
    }
    return p;
}

eVehiculo* vehiculo_nuevoParametros(int id,char* marca,int tipo, float peso)
{
    eVehiculo* p = vehiculo_new();
    if(p!= NULL)
    {
        if(!(vehiculoSetId(p, id)==0 && vehiculoSetTipo(p, tipo)==0 && veiculoSetMarca(p, marca)== 0&& vehiculoSetPeso(p, peso)==0))
        {
            p = NULL;
        }
    }
    return p;
}

///////////////////////////////////////////////////////////////////////////SETTERS///////////////////////////////////////////////////////////////////////////

int veiculoSetMarca(eVehiculo* this,char* marca)
{
    int todoOk=1;
    if(this!=NULL && marca!=NULL && strlen(marca)<20)
    {
        strcpy(this->marca, marca);
        todoOk=0;
    }

    return todoOk;
}
int vehiculoSetId(eVehiculo* this,int id)
{
    int todoOk=1;
    if(this!=NULL && id >0)
    {
        this->id=id;
        todoOk=0;
    }

    return todoOk;
}

int vehiculoSetTipo(eVehiculo* this,int tipo)
{
    int todoOk=1;
    if(this!=NULL && tipo >0)
    {
        this->tipo=tipo;
        todoOk=0;
    }

    return todoOk;
}


int vehiculoSetPeso(eVehiculo* this,float peso)
{
    int todoOk=1;
    if(this!=NULL && peso >0)
    {
        this->peso=peso;
        todoOk=0;
    }

    return todoOk;
}

///////////////////////////////////////////////////////////////////////////GUARDADOS DE TEXTO Y BINARIO///////////////////////////////////////////////////////////////////////////

int guardarEnTexto(char* path, eVehiculo* vehiculo)
{
    int retorno=0;
    FILE* f = NULL;
    f = fopen(path, "w");
    if(f!= NULL && vehiculo != NULL)
    {
        int cant = fprintf(f, "%d,%s,%d,%f", vehiculo->id, vehiculo->marca,vehiculo->tipo,vehiculo->peso);
        if(cant <=0)
        {
            printf("Ocurrio algo\n");
        }
        retorno=1;
    }
    fclose(f);
    return retorno;
}

int guardarEnBinario(char* path, eVehiculo* vehiculo)
{
    int retorno=0;
    FILE* f = NULL;
    f = fopen(path, "wb");
    if(f!= NULL && vehiculo != NULL)
    {
        if(fwrite(vehiculo, sizeof(eVehiculo), 1, f) != 1)
        {
            printf("Hubo un error\n");
        }
        retorno=1;
    }
    return retorno;
    fclose(f);
}
