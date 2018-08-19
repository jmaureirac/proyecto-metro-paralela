#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>


typedef struct nodo {
    int id;
    std::string codigo;
    std::string nombre;
<<<<<<< HEAD
    struct nodo*combinacion;
=======
>>>>>>> master
    struct nodo*izq;
    struct nodo*der;
    struct nodo*combinacion;
}nodo;

typedef nodo*linea;

void cargarLinea(char* fichero, linea *lx);
void cleanLinea(linea *lx);
void imprimirLinea(linea lx);
void buscarCombinaciones(linea* lx, linea* ln);
void generarTodasCombinaciones(linea *l1, linea *l2, linea *l3, linea *l4, linea *l4a, linea *l5, linea *l6);

void insertarCombinaciones(linea lx[]);
void recorrerLinea(linea lx, std::string sentido);

#endif /* FUNCIONES_H */

