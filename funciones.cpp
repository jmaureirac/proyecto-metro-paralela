#include <cstring>

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


/**
 * Funcion que carga una linea desde un fichero a una lista
 * @param fichero "./public/Lx.txt"
 * @param lx Linea vacia a la cual se le cargan las estaciones
 */
void cargarLinea(char* fichero, linea *lx){
    linea L = *lx;
    
    std::ifstream archivo(fichero);
    char line[35];
    int contador = 0;

    if(archivo.fail()) {
        std::cerr << "Error al abrir el archivo " << fichero << std::endl;
    } else {
        while(!archivo.eof())
        {
            archivo.getline(line, sizeof(line));            
            std::string lineaArchivo = line;
            int largoLinea = lineaArchivo.length();
            
            linea nuevaEstacion;
            nuevaEstacion = (linea) malloc(sizeof(nodo));
            
            if ( line[2] != ' ' ) {
                /* SIGLA DE LARGO 3 */
                std::cout << "hola" << std::endl;
            } else {
                /* SIGLA DE LARGO 2 */
                nuevaEstacion->id = 0;
                nuevaEstacion->codigo = lineaArchivo.substr(0,2);
                nuevaEstacion->nombre = lineaArchivo.substr(3,largoLinea-1);
                
                //std::cout << "id: " << nuevaEstacion->id << "\tcod: " << nuevaEstacion->codigo << "\t   nombre: " << nuevaEstacion->nombre << std::endl;
                
            }
            
            contador++;
            
        }
    }
    archivo.close();
    
}

