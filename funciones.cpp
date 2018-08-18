#include "funciones.h"


/**
 * Funcion encargada de recorrer la linea X, con la direccion/sentido por parámetro
 * @param lx Linea a recorrer
 * @param sentido Sentido/Direccion a moverse por la linea
 */
void recorrerLinea(linea lx, std::string sentido) {
    linea estacion;
    estacion = lx;
    
    while ( estacion != NULL ) {
        std::cout << estacion->codigo << std::endl;
        
        if (sentido.compare("der") == 0) {
            estacion = estacion->der;
        } else {
            estacion = estacion->izq;
        } 
    }
}

