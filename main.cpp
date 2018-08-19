#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "Metro.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    char* ruta_fichero = "./public/lineas_metro.txt";
    Metro metro_santiago = new Metro(ruta_fichero);
//    metro_santiago.setEstaciones('./public/lineas_metro.txt');
    cout << "\nHello World!\n" << endl;
    return 0;
}

