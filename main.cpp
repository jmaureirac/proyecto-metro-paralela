#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>

#include "dataloader.h"
#include "metrored.h"

using namespace std;

/*
 *
 */
int main(int argc, char** argv) {

    if ( argc <= 2 ) {
        char* flag = argv[1];
        if (strcmp(flag,"-v") == 0){
            cout << "\nIntegrantes:\n\tLucas Henry\n\tEsteban Martínez\n\tJorge Maureira\n\n" << endl;
        }
    } else {
        char* flag = argv[1];
        if(strcmp(flag,"-f") == 0){
            linea l1, l2, l4, l4a, l5, l6;
            
            l1 = (linea) malloc(sizeof (nodo));
            l2 = (linea) malloc(sizeof (nodo));
            l4 = (linea) malloc(sizeof (nodo));
            l4a = (linea) malloc(sizeof (nodo));
            l5 = (linea) malloc(sizeof (nodo));
            l6 = (linea) malloc(sizeof (nodo));
            
            generarLineasMetro(&l1, &l2, &l4, &l4a, &l5, &l6);
            
            linea inicio, destino;
            inicio = (linea) malloc(sizeof (nodo));
            destino = (linea) malloc(sizeof (nodo));
            
            inicio = getUbicacion(argv[2], l1, l2, l4, l4a, l5, l6);
            destino = getUbicacion(argv[3], l1, l2, l4, l4a, l5, l6);

            cout << "Estación de inicio  : " << inicio->nombre << endl;
            cout << "Estación destino    : " << destino->nombre << endl;
//            cout << "\n" << destino->combinacion->der->codigo << endl;
//            cout << "\n" << destino->combinacion->der->der->codigo << endl;
//            cout << "\n" << destino->combinacion->der->der->der->codigo << endl;
//            cout << "\n" << destino->combinacion->der->der->der->der->codigo << endl;
            
//            cout << buscarDireccion(inicio, destino) << endl;
            
            cout << endl;
            testingRecorrerLinea(inicio, destino);
            
//            cout << calcularDistanciaMismaLinea(inicio, destino) << endl;
//            
//            cout << destino->codigo << endl;
//            hacerCombinacion(&destino);
//            cout << destino->codigo << endl;
            
        } else {
            cout << "\nParámetros inválidos\n" << endl;
        }

    }

    return 0;
}
