#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>

/* Lineas-Estaciones */
typedef struct nodo {
    int id;
    std::string codigo;
    std::string nombre;
    std::string nombre_linea;
    struct nodo*izq;
    struct nodo*der;
    struct nodo*combinacion;
}nodo;

typedef nodo*linea;
/* Fin lineas-estaciones */

/* Ruta-Recorrido */
typedef struct ruta{
    linea estacion;
    struct ruta*link;
}ruta;

typedef ruta*recorrido;
/* fin ruta-recorrido */


void cargarLinea(char* fichero, linea *lx, char* nombreLinea);
void cleanLinea(linea *lx);
void imprimirLinea(linea lx);
void buscarCombinaciones(linea* lx, linea* ln);
void generarTodasCombinaciones(linea *l1, linea *l2, linea *l4, linea *l4a, linea *l5, linea *l6);
void generarNombreLineaEstaciones(linea *l1, linea *l2, linea *l4, linea *l4a, linea *l5, linea *l6);
linea getUbicacion(char* estacion, linea l1, linea l2, linea l4, linea l4a, linea l5, linea l6);
bool estaDestinoEnCombinacion(linea *lx, linea inicio, linea destino);
void recorrerLinea(linea lx, std::string sentido);

void rutaMasCorta(linea inicio, linea destino, recorrido *ruta);
recorrido combinacionesLineaX(linea lx);

// LUCAS
void busquedaRutaMasCorta(linea incio, linea destino, linea l1, linea l2, linea l4, linea l4a, linea l5, linea l6, linea *stack_rutas);
recorrido recorrerLinea_v2(linea lx, linea destino, std::string sentido);
bool destinoEnLinea(linea inicio, linea destino);
std::string buscarDireccion(linea incio, linea destino);


#endif /* FUNCIONES_H */
