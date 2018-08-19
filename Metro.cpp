//
// Created by no-name on 8/18/18.
//

#include "Metro.h"
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

Metro::Metro() {}

Metro::Metro(char* fichero){

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
            std::cout<<lineaArchivo<<endl;
//            linea nuevaEstacion;
//            nuevaEstacion = (linea) malloc(sizeof(nodo));

//            if ( line[2] != ' ' ) {
//                /* SIGLA DE LARGO 3 */
//                std::cout << "hola" << std::endl;
//            } else {
//                /* SIGLA DE LARGO 2 */
//                nuevaEstacion->id = 0;
//                nuevaEstacion->codigo = lineaArchivo.substr(0,2);
//                nuevaEstacion->nombre = lineaArchivo.substr(3,largoLinea-1);
//
//                //std::cout << "id: " << nuevaEstacion->id << "\tcod: " << nuevaEstacion->codigo << "\t   nombre: " << nuevaEstacion->nombre << std::endl;
//
//            }

            contador++;

        }
    }
    archivo.close();
}

Metro::~Metro() {
}