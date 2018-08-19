#include <cstdlib>
#include <iostream>

#include "funciones.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    

    linea l1;
    
    l1 = (linea) malloc(sizeof (nodo));    

    cargarLinea("./public/L1.txt", &l1);

    cout << "\nHello World!\n" << endl;
    return 0;
}

