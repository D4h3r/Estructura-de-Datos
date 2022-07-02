/*
El presidente Donald Trump viene a ayudarle en este examen, y ha puesto en alerta todas las Unidades del
Ejército de los Estados Unidos debido a la alta tensión mundial provocada por Corea del Norte. Para ello se ha
diseñado una organización que da cuenta de los objetivos y misiles:
Ejercito: Contiene el nombre del Comandante en Jefe, un abb de Unidades Militares ordenado por id y una lista
simplemente enlazada de los objetivos, esta lista de objetivos es manejada con nodo fantasma.
Unidad Militar: Contiene un id, el nombre del general a cargo de la Unidad, el número de soldados de reserva y un
arreglo no compacto de punteros a los misiles.
Objetivo: Cada objetivo tiene un nombre, nombre del presidente, latitud y longitud.
Misil: El misil tiene un número de serie, potencia, tipo y un puntero al objetivo que atacaría en posible conflicto
*/

/*
a) struct int agregarMisil (struct Ejercito *e, struct Misil *misil, int unidadMilitar)
Recibe un puntero al Ejercito Coreano, un puntero al nuevo misil y el código de la unidad militar en
donde se agregará este misil. Esta función, y en conjunto con las funciones auxiliares, debe recorrer las
unidades militares y cuando corresponda agregar el misil a dicha unidad militar.
En caso de éxito de la operación retornará 1 y en cualquier otro caso retorna 0. Para el recorrido del
árbol utilice recursividad en in orden. No olvide considerar las notas del punto 2.

b) struct Objetivo eliminarObjetivo (struct Ejercito *e, char * nombre)
Recibe un puntero al Ejercito Coreano y el nombre del objetivo a eliminar. Debe buscar el objetivo a
eliminar y cuando lo encuentre debe desenlazar todas las referencias de los misiles hacia el objetivo a
ser eliminado.
Finalmente retorna un puntero al objetivo desenlazado y en el caso de fracaso retorna null. Para el
recorrido del árbol utilice recursividad en post orden. No olvide considerar las notas del punto 2.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ejercito
{
    char *nombreComandante;
    struct NodoUnidad *unidades;
    struct NodoObjetivo *objetivo;
};

struct NodoUnidad
{
    struct UnidadMilitar *unidad;
    struct NodoUnidad *izq, *der;
};

struct UnidadMilitar
{
    int id;
    char *general;
    int numeroSoldados;
    struct Misil **misiles;
};

struct NodoObjetivo
{
    struct Objetivo *objetivo;
    struct NodoObjetivo *sig;
};

struct Objetivo
{
    char *nombre;
    char *presidente;
    float latitud;
    float longitud;
};

struct Misil
{
    int numeroSerie;
    float potencia;
    int tipo;
    struct Objetivo *objetivo;
}

int agregarMisil(struct Ejercito *e, struct Misil *misil, int unidadMilitar)
{
    //arbol
    if (e->unidades != NULL)
    {
        //vemos si es una unidad militar
        if (e->unidades->unidad->id == unidadMilitar)
        {
            e->unidades->unidad->misiles[e->unidades->unidad->numeroSoldados] = misil;
            e->unidades->unidad->numeroSoldados++;
            return 1;
        }
        else if (e->unidades->unidad->id < unidadMilitar)
        {
            return agregarMisil(e->unidades->der, misil, unidadMilitar);
        }
        else
            return agregarMisil(e->unidades->izq, misil, unidadMilitar);
        }
    return 0;
}

//funcion que cuenta cuantos misiles hay en una unidad militar
int contarMisiles(struct Ejercito *e, int *contador)
{
    //iniciar contador
    (*contador) = 0;
    if (e->unidades != NULL)
    {
        contarMisiles(e->unidades->der, contador);
        contarMisiles(e->unidades->izq, contador);
        (*contador)++;
    }
    return *contador;
}

//funcion que busca el objetivo a eliminar dado el nombre la latitud y longitud, simple linked list with ghost node
struct Objetivo *buscarObjetivo(struct NodoObjetivo *objetivo, float latitud, float longitud)
{
    struct Objetivo *rec = objetivo->sig;
    while (rec != NULL)
    {
        if (rec->latitud == latitud && rec->longitud == longitud)
            return rec; //si son iguales retornamos el elemento buscado
        rec = rec->sig;
    }
    return NULL;
}


//si se encuentra el objetivo a eliminar, se desenlaza todas las referencias de los misiles hacia el objetivo a ser eliminado
void desenlazarReferenciaMisilesAObjetivo (struct UnidadMilitar **misiles, struct Objetivo *objetivo, float latitud, 
                                            float longitud, int totalMisiles)
{
    struct Objetivo *objetivoBuscado = buscarObjetivo(objetivo, latitud, longitud);
    if (objetivoBuscado != NULL)
    {
        for (int i = 0; i < totalMisiles && misiles[i] != NULL; i++)
        {
            if (misiles[i]->objetivo->latitud == objetivoBuscado->latitud && misiles[i]->objetivo->longitud == objetivoBuscado->longitud)
                misiles[i]->objetivo = NULL;
                return;
        }
    }
}

//POST ORDEN
struct Objetivo *eliminarObjetivo(struct Ejercito *e, char *nombre)
{
    struct Objetivo *objetivoEncontrado = buscarObjetivo(e->objetivo, e->objetivo->latitud, e->objetivo->longitud);
    //recorremos el arbol en post orden
    if (!(*(e->objetivo)->nombre == *nombre))
    {
        eliminarObjetivo(e->unidades->izq, nombre);
        eliminarObjetivo(e->unidades->der, nombre);
    }
    else
    {
        //si encuentra al objetivo a eliminar, se desenlaza todas las referencias de los misiles hacia el objetivo a ser eliminado
        desenlazarReferenciaMisilesAObjetivo(e->unidades->misiles, objetivoEncontrado, e->objetivo->latitud, e->objetivo->longitud, e->unidades->totalMisiles);
        //free y retornamos un puntero al objetivo desenlazado
        free(objetivoEncontrado);
        return objetivoEncontrado;
    }
    return NULL;
}


int main()
{
    return 0;
}