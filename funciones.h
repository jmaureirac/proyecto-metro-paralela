#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>

typedef std::string array[2];

typedef struct nodo {
    int id;
    std::string codigo;
    std::string nombre;
    struct nodo*combinacion;
    struct nodo*izq;
    struct nodo*der;
}nodo;

typedef nodo*linea;

void cargarLinea(char* fichero, linea *lx);
void cleanLinea(linea *lx);
void imprimirLinea(linea lx);


void insertarCombinaciones(linea lx[]);
void recorrerLinea(linea lx, std::string sentido);

#endif /* FUNCIONES_H */

