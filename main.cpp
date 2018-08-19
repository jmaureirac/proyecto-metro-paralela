#include <cstdlib>
#include <iostream>

#include "funciones.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    linea l1, l2, l4, l4a, l5, l6;
    
    l1 = (linea) malloc(sizeof (nodo));
    l2 = (linea) malloc(sizeof (nodo));    
  

    cargarLinea("./public/L1.txt", &l1);
    cargarLinea("./public/L2.txt", &l2);
    //cargarLinea("./public/L4.txt", &l4);
    //cargarLinea("./public/L4a.txt", &l4a);
    //cargarLinea("./public/L5.txt", &l5);
    //cargarLinea("./public/L6.txt", &l6);
    
    
    cout << "L1: \n\n" << endl;
    imprimirLinea(l1);


    cout << "L2: \n\n" << endl;

    imprimirLinea(l2);
    
    cout << "\nHello World!\n" << endl;
    return 0;
}

