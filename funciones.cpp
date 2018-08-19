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
            
            if ( lineaArchivo[2] != ' ' ) {
                /* SIGLA DE LARGO 3 */
                nuevaEstacion->id = contador;
                nuevaEstacion->codigo = lineaArchivo.substr(0,3);
                nuevaEstacion->nombre = lineaArchivo.substr(4,largoLinea-4);
                nuevaEstacion->der = NULL;
                if (L == NULL) {
                    /* SI LA LISTA VIENE VACIA, NUEVA ESTACION ES EL PRIMER NODO */
                    L = nuevaEstacion;
                    nuevaEstacion->izq = NULL;
                } else {
                    /* LINKEA LA LISTA QUE VIENE RECORRIENDO, A LA NUEVA ESTACION */
                    nuevaEstacion->izq = L;
                    L->der = nuevaEstacion;                
                }
                //std::cout << "id: " << nuevaEstacion->id << "\tcod: " << nuevaEstacion->codigo << "\t   nombre: " << nuevaEstacion->nombre << "\t\t\t\t\tAnterior:" << nuevaEstacion->izq->nombre << std::endl;
            
            } else {
                /* SIGLA DE LARGO 2 */
                nuevaEstacion->id = contador;
                nuevaEstacion->codigo = lineaArchivo.substr(0,2);
                nuevaEstacion->nombre = lineaArchivo.substr(3,largoLinea-3);
                nuevaEstacion->der = NULL;
                if (L == NULL) {
                    /* SI LA LISTA VIENE VACIA, NUEVA ESTACION ES EL PRIMER NODO */
                    L = nuevaEstacion;
                    nuevaEstacion->izq = NULL;
                } else {
                    /* LINKEA LA LISTA QUE VIENE RECORRIENDO, A LA NUEVA ESTACION */
                    nuevaEstacion->izq = L;
                    L->der = nuevaEstacion;                
                }
                //std::cout << "id: " << nuevaEstacion->id << "\tcod: " << nuevaEstacion->codigo << "\t   nombre: " << nuevaEstacion->nombre <<  "\t\t\t\t\tAnterior:" << nuevaEstacion->izq->nombre << std::endl;                
            }
            
            L = L->der; 
            contador++;
            
        }
    }
    archivo.close();
    
}


/**
 * Funcion que imprime los datos de cada estacion de una linea por parametro
 * @param lx Linea que se de sea imprimir cada estacion
 */
void imprimirLinea(linea lx) {
    linea L;
    L = lx;
    
    while(L != NULL) {
        std::cout << "id: " << L->id << "\tcod: " << L->codigo << "\t   nombre: " << L->nombre;
        /* verificar si existe nodo izquierdo para evitar core */
        if (L->izq != NULL) {
            std::cout << "\tAnterior: " << L->izq->nombre;
        } else {
            std::cout << "\tEs la primera estacion";
        }
        
        /* verificar si hay nodo derecho para evitar core */
        if (L->der != NULL) {
            std::cout << "\tSiguiente: " << L->der->nombre << std::endl;
        } else {
            std::cout << "\tEs la ultima estacion" << std::endl;
        }
        L = L->der;
    }

}

