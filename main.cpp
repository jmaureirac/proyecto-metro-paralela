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


    Metro metro_santiago = Metro("./public/lineas_metro.txt");
//    metro_santiago.setEstaciones('./public/lineas_metro.txt');
    cout << "\nHello World!\n" << endl;
    return 0;
}

