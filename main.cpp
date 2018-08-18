#include <cstdlib>
#include <iostream>

#include "funciones.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    linea l1sp;
    linea l1;
    
    l1sp = (linea) malloc(sizeof (nodo));
    l1 = (linea) malloc(sizeof (nodo));
    
    l1sp->id = 0;
    l1sp->codigo = "SP";
    l1sp->izq = NULL;
    l1sp->der = l1;
    l1sp->nombre = "San Pablo";
    l1sp->combinacion[0] = "-";
    l1sp->combinacion[1] = "-";
    
    
    l1->id = 1;
    l1->codigo = "LH";
    l1->izq = l1sp;
    l1->der = NULL;
    l1->nombre = "Los Héroes";
    l1->combinacion[0] = "LH";
    l1->combinacion[1] = "LHE" ;
    
    
    

    recorrerLinea(l1sp, "der");

    cout << "\nHello World!\n" << endl;
    return 0;
}

