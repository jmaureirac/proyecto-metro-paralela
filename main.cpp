#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include "funciones.h"

using namespace std;

/*
 *
 */
int main(int argc, char** argv) {

    if ( argc > 2) {
        char* flag = argv[1];
        if (strcmp(flag,"-v") == 0){
            cout << "\nIntegrantes:\n\tLucas Henry\n\tEsteban Martínez\n\tJorge Maureira\nPiedad pofavo" << endl;
	    } else {
    	    if(strcmp(flag,"-f") == 0){
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
                cargarLinea(tl1, &l1, "L1");
                cargarLinea(tl2, &l2, "L2");
                cargarLinea(tl4, &l4, "L4");
                cargarLinea(tl4a, &l4a, "L4a");
                cargarLinea(tl5, &l5, "L5");
                cargarLinea(tl6, &l6, "L6");

                /* Limpiar las lineas */
                cleanLinea(&l1);
                cleanLinea(&l2);
                cleanLinea(&l4);
                cleanLinea(&l4a);
                cleanLinea(&l5);
                cleanLinea(&l6);

                /* Prueba buscar combinacion entre lineas 1 y 2 */

                generarTodasCombinaciones(&l1,&l2,&l4,&l4a,&l5,&l6);
                // Inputs Linea y Nombre Destino
                // estaDestinoEnLinea(&l1, "Santa Ana");


                /* Ver por pantalla */
                cout << "\nL1: \n" << endl;
                imprimirLinea(l1);

                cout << "\nL2: \n" << endl;
                imprimirLinea(l2);

                cout << "\nL4: \n" << endl;
                imprimirLinea(l4);

                cout << "\nL4a: \n" << endl;
                imprimirLinea(l4a);

                cout << "\nL5: \n" << endl;
                imprimirLinea(l5);

                cout << "\nL6: \n\n" << endl;
                imprimirLinea(l6);

                linea estacion_inicial = (linea) malloc(sizeof (nodo));
                linea estacion_destino = (linea) malloc(sizeof (nodo));
                linea stack_rutas = (linea) malloc(sizeof (nodo));

                estacion_inicial = getUbicacion(argv[2], l1, l2, l4, l4a, l5, l6);
                estacion_destino = getUbicacion(argv[3], l1, l2, l4, l4a, l5, l6);
                // recorrerLinea(estacion, "izq");
                busquedaRutaMasCorta(estacion_inicial, estacion_destino, l1, l2, l4, l4a, l5, l6, &stack_rutas);


            } else {
    	           cout << "\nParámetros inválidos\n" << endl;
    	    }
	    }

    }

    return 0;
}
