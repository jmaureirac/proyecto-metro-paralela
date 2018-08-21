#include <cstring>

#include "funciones.h"

/**
 * Funcion encargada de recorrer la linea X, con la direccion/sentido por parámetro
 * @param lx Linea a recorrer
 * @param sentido Sentido/Direccion a moverse por la linea
 */
void recorrerLinea(linea lx, std::string sentido) {
    linea estacion;
    estacion = lx;

    while ( estacion != NULL ) {
        std::cout << estacion->codigo << std::endl;

        if (sentido.compare("der") == 0) {
            std::cout << estacion->nombre << std::endl;
            estacion = estacion->der;
        } else {
            std::cout << estacion->nombre << std::endl;
            estacion = estacion->izq;
        }
    }
}


/**
 * Funcion que carga una linea desde un fichero a una lista
 * @param fichero "./public/Lx.txt"
 * @param lx Linea vacia a la cual se le cargan las estaciones
 */
void cargarLinea(char* fichero, linea *lx, char* nombreLinea){
    linea L = *lx;

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

            linea nuevaEstacion;
            nuevaEstacion = (linea) malloc(sizeof(nodo));

            nuevaEstacion->id = contador;
            /* SIGLA DE LARGO 3 TRUE, LARGO 2 FALSE */
            nuevaEstacion->codigo = ( lineaArchivo[2] != ' ' ) ? lineaArchivo.substr(0,3) : lineaArchivo.substr(0,2);
            nuevaEstacion->nombre = ( lineaArchivo[2] != ' ' ) ? lineaArchivo.substr(4, largoLinea-4) : lineaArchivo.substr(3, largoLinea-3);
            nuevaEstacion->nombre_linea = nombreLinea;
            nuevaEstacion->combinacion = NULL;
            nuevaEstacion->der = NULL;

            if (L == NULL) {
                /* SI LA LISTA VIENE VACIA, NUEVA ESTACION ES EL PRIMER NODO */
                L = nuevaEstacion;
                nuevaEstacion->izq = NULL;
            } else {
                /* LINKEA LA LISTA QUE VIENE RECORRIENDO, A LA NUEVA ESTACION */
                nuevaEstacion->izq = L;
                L->der = nuevaEstacion;
            }
            L = L->der;
            contador++;

        }
    }
    archivo.close();

}

/**
 * Funcion que imprime los datos de cada estacion de una linea por parametro
 * @param lx Linea que se de sea imprimir cada estacion
 */
void imprimirLinea(linea lx) {
    linea L;
    L = lx;

    while(L != NULL) {
        std::cout << "id: " << L->id << "\tcod: " << L->codigo << "\t nombre: " << L->nombre << " \t linea: " << L->nombre_linea;

        /* verificar si hay nodo estacion para evitar core */
        if (L->combinacion != NULL) {
            std::cout << "\t\tCombinacion: " << L->combinacion->codigo;
        } else {
            std::cout << "\t\tNo hay combinacion";
        }

        /* verificar si existe nodo izquierdo para evitar core */
        if (L->izq != NULL) {
            std::cout << "\t\t\tAnterior: " << L->izq->nombre;
        } else {
            std::cout << "\t\t\tEs la primera estacion";
        }

        /* verificar si hay nodo derecho para evitar core */
        if (L->der != NULL) {
            std::cout << "\t\t\tSiguiente: " << L->der->nombre << std::endl;
        } else {
            std::cout << "\t\t\tEs la ultima estacion" << std::endl;
        }



        L = L->der;

    }

}

/**
 * Funcion para eliminar el primer nodo de la linea que aparecia en blanco
 * @param lx Linea a la cual se le limpia el nodo
 */
void cleanLinea(linea *lx) {
    linea primeraEstacion = *lx;
    linea borrar = *lx;

    primeraEstacion = primeraEstacion->der;

    primeraEstacion->izq = NULL;
    *lx = primeraEstacion;

    free(borrar);

}


/**
 * Funcion que busca las combinaciones existentes entre dos lineas
 * @param lx Linea x
 * @param ln Linea n
 */
void buscarCombinaciones(linea *lx, linea *ln) {
    linea aux = *lx;

    /* Buscar en Linea X para cada estación */
    while( aux != NULL ) {

        /* Buscar en Linea N para cada estación */
        linea search = *ln;

        while( search != NULL ) {

            if ( aux->nombre == search->nombre ) {
                /* Asignacion de valores a ambas estaciones con codigos de la otra linea */
                aux->combinacion = search;
                search->combinacion = aux;
            }

            search = search->der;
        }

        aux = aux->der;
    }

}


linea getUbicacion(char* estacion, linea l1, linea l2, linea l4, linea l4a, linea l5, linea l6) {
    linea metroRed[6] = { l1, l2, l4, l4a, l5, l6 };

    for(int i = 0; i<6; i++) {
        linea recorre = metroRed[i];
        while( recorre != NULL ) {
            if ( estacion == recorre->codigo ) {
                return recorre;
            }
            recorre = recorre->der;
        }
    }
}







/**
* Funcion que recibe todas las lineas del metro y comprueba si tiene combinacion con las demás para generar los link
* @param l1 Linea 1
* @param l2 Linea 2
* @param l4 Linea 4
* @param l4a Linea 4a
* @param l5 Linea 5
* @param l6 Linea 6
*/
void generarTodasCombinaciones(linea *l1, linea *l2, linea *l4, linea *l4a, linea *l5, linea *l6) {
    linea metroRed[6] = { *l1, *l2, *l4, *l4a, *l5, *l6 };
    for(int i = 0; i<6; i++) {
        for(int j = 0; j<6; j++) {
            if ( i != j ) {
                buscarCombinaciones(&metroRed[i], &metroRed[j]);
            }
        }
    }
}

// bool estaDestinoEnCombinacion(linea current, linea combinacion, char){
//   linea left, right;
//   left, right = current;
//   while (left != NULL || right != NULL) {
//     if (left->nombre == destino) {
//       return true;
//     }
//     if (right->nombre == destino){
//       return true;
//     }
//     left = (left != NULL) ? left->izq;
//     right = (right != NULL) ? right->der;
//   }
//   return false;
// }

void busquedaRutaMasCorta(linea inicio, linea destino, linea l1, linea l2, linea l4, linea l4a, linea l5, linea l6, linea *stack_rutas){
    linea metroRed[6] = { l1, l2, l4, l4a, l5, l6 };
    linea estacion_inicial;
    linea estacion_destino;
    estacion_inicial = inicio;
    estacion_destino = destino;
    std::string ruta;

    if (estacion_inicial->nombre == estacion_destino->nombre ) {
      // stack_rutas.push(ruta);
    }
    if (destinoEnLinea(inicio, destino)){
        std::cout<<"SE ENCUENTRA DESTINO EN LINEA"<<std::endl;
        std::string direccion = buscarDireccion(inicio, destino);
        ruta = recorrerLinea_v2(inicio, destino, direccion);


    }
}
// Aplicare cambios para guardar la ruta hazta llegar
std::string recorrerLinea_v2(linea lx, linea destino, std::string sentido) {
    linea estacion;
    estacion = lx;
    std::string _stack_ruta;
    while ( estacion->nombre != destino->nombre ) {
        // std::cout << estacion->codigo << std::endl;
        if (sentido.compare("der") == 0) {
            std::cout << estacion->nombre << "  -  ";
            estacion = estacion->der;
        } else {
            std::cout << estacion->nombre << "  -  ";
            estacion = estacion->izq;
        }
    }
    std::cout << estacion->nombre << std::endl;
    return _stack_ruta;
}

bool destinoEnLinea(linea inicio, linea destino){
  if (inicio->nombre_linea == destino->nombre_linea){
    return true;
  }
  return false;
}

std::string buscarDireccion(linea inicio, linea destino){
  if(inicio->id > destino->id){
    return "izq";
  }else{
    return "der";
  }
}
