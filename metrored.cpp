#include "dataloader.h"
#include "metrored.h"
#include <cstring>

/******************************************************************************************************************/


/* INICIO OPERACIONES BASICAS */

bool destinoEnLinea(linea inicio, linea destino){
  if (inicio->nombre_linea == destino->nombre_linea){
    return true;
  }
  return false;
}


std::string buscarDireccion(linea inicio, linea destino){
  if(inicio->id > destino->id){
    return "izq";
  }else{
    return "der";
  }
}


linea getUbicacion(char* estacion, linea l1, linea l2, linea l4, linea l4a, linea l5, linea l6) {
    linea metroRed[6] = { l1, l2, l4, l4a, l5, l6 };

    for(int i = 0; i<6; i++) {
        linea recorre = metroRed[i];
        while( recorre != NULL ) {
            if ( estacion == recorre->codigo ) {
                return recorre;
            }
            recorre = recorre->der;
        }
    }
    
    return NULL;
}


int calcularDistanciaMismaLinea(linea inicio, linea destino){
    /* se calcula distancia si pertenecen a la misma linea previamente */
    return (inicio->id > destino->id) ? inicio->id - destino->id : destino->id - inicio->id;
}


void hacerCombinacion(linea *lx) {
    linea combinate = *lx;
    if(combinate->combinacion != NULL) {
        combinate = combinate->combinacion;
    }
    *lx = combinate;
}


void recorrerLinea(linea lx, std::string sentido) {
    linea estacion;
    estacion = lx;

    while ( estacion != NULL ) {
        std::cout << estacion->codigo << std::endl;

        if (sentido.compare("der") == 0) {
            std::cout << estacion->nombre << std::endl;
            estacion = estacion->der;
        } else {
            std::cout << estacion->nombre << std::endl;
            estacion = estacion->izq;
        }
    }
}

/* FIN OPERACIONES BASICAS */


/******************************************************************************************************************/


/* INICIO CALCULAR RUTA */




/* FIN CALCULAR RUTA */


/******************************************************************************************************************/




