//
// Created by no-name on 8/18/18.
//

#include "Metro.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <fstream>

using namespace std;

Metro::Metro() {}

Metro::Metro(const char* fichero){
    std::cout<<fichero<<endl;
    std::ifstream archivo(fichero);
    char line[35];
    int contador = 0;



    if(archivo.fail()) {
        std::cerr << "Error al abrir el archivo " << fichero << std::endl;
    } else {
        while(!archivo.eof())
        {
            Estacion *estacion;
            estacion = new Estacion;

            archivo.getline(line, sizeof(line));
            std::string lineaArchivo = line;
            int largoLinea = lineaArchivo.length();
            bool cambio_linea = largoLinea == 2 || (largoLinea==3 && lineaArchivo[2]=='a');

            estacion->id = contador;
            estacion->codigo = (lineaArchivo[2] != ' ') ? lineaArchivo.substr(0,3): lineaArchivo.substr(0,2);
            estacion->nombre = (lineaArchivo[2] != ' ') ? lineaArchivo.substr(4,largoLinea-4) : lineaArchivo.substr(3,largoLinea-3);
            estacion->der = NULL;

            if(this->estaciones == NULL){
                this->estaciones = estacion;
                estacion->izq = NULL;
            } else {
                estacion->izq = this->estaciones;
                this->estaciones->der = estacion;
            }
            std::cout<<lineaArchivo[3]<<endl;

            this->estaciones = this->estaciones->der;
            contador++;

        }
    }
    archivo.close();
}

Metro::~Metro() {
}