#include <cstdlib>
#include <iostream>

#include "funciones.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    /* Se declaran lineas del metro como listas lineales con dos punteros */
    linea l1, l2, l4, l4a, l5, l6;
    
    /* Se declaran los nombres de los textos para abrir archivos */
    char* tl1 = NULL;
    char* tl2 = NULL;
    char* tl4 = NULL;
    char* tl4a = NULL;
    char* tl5 = NULL;
    char* tl6 = NULL;
    
    /* Asignaciones de memoria */
    l1 = (linea) malloc(sizeof (nodo));
    l2 = (linea) malloc(sizeof (nodo));    
    l4 = (linea) malloc(sizeof (nodo));    
    l4a = (linea) malloc(sizeof (nodo));    
    l5 = (linea) malloc(sizeof (nodo));    
    l6 = (linea) malloc(sizeof (nodo));   
    
    tl1 = (char *) calloc(20, sizeof (char));
    tl2 = (char *) calloc(20, sizeof (char));    
    tl4 = (char *) calloc(20, sizeof (char));    
    tl4a = (char *) calloc(20, sizeof (char));    
    tl5 = (char *) calloc(20, sizeof (char));    
    tl6 = (char *) calloc(20, sizeof (char));  
    
    /* Setear el path de los ficheros */
    snprintf(tl1, 20, "./public/L1.txt");
    snprintf(tl2, 20, "./public/L2.txt");
    snprintf(tl4, 20, "./public/L4.txt");
    snprintf(tl4a, 20, "./public/L4a.txt");
    snprintf(tl5, 20, "./public/L5.txt");
    snprintf(tl6, 20, "./public/L6.txt");

    /* Se cargan las lineas del metro con su correspondiente fichero */
    cargarLinea(tl1, &l1);
    cargarLinea(tl2, &l2);
    cargarLinea(tl4, &l4);
    cargarLinea(tl4a, &l4a);
    cargarLinea(tl5, &l5);
    cargarLinea(tl6, &l6);
    
    /* Limpiar las lineas */
    cleanLinea(&l1);
    cleanLinea(&l2);
    cleanLinea(&l4);
    cleanLinea(&l4a);
    cleanLinea(&l5);
    cleanLinea(&l6);
//
//    /* Ver por pantalla */
//    cout << "\nL1: \n" << endl;
//    imprimirLinea(l1);
//
//    cout << "\nL2: \n" << endl;
//    imprimirLinea(l2);
//
//    cout << "\nL4: \n" << endl;
//    imprimirLinea(l4);
//
//    cout << "\nL4a: \n" << endl;
//    imprimirLinea(l4a);
//
//    cout << "\nL5: \n" << endl;
//    imprimirLinea(l5);
//
//    cout << "\nL6: \n\n" << endl;
//    imprimirLinea(l6);

    linea lineas[6] = {l1,l2,l4,l4a,l5,l6};
    insertarCombinaciones(lineas);
    
    cout << "\nL4: \n" << endl;
    imprimirLinea(l4);
    
    cout << "\nL4a: \n" << endl;
    imprimirLinea(l4a);
    
    cout << "\nL5: \n" << endl;
    imprimirLinea(l5);
    
    cout << "\nL6: \n\n" << endl;
    imprimirLinea(l6);
    
    return 0;
}

