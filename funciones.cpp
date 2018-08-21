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


/**
 * Funcion que recibe la estacion del argumento del programa y determina ubicacion en la linea de la estacion
 * @param estacion String argumento recibido
 * @param l1 Linea 1
 * @param l2 Linea 2
 * @param l4 Linea 4
 * @param l4a Linea 4a
 * @param l5 Linea 5
 * @param l6 Linea 6
 * @return Retorna la estacion en forma de linea(lista) donde se tienen todos los campos necesarios
 */
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


/**
 * Funcion de busqueda de ruta mas corta recibiendo inicio y destino en formato de linea
 * @param inicio 
 * @param destino 
 * @param l1 Linea 1
 * @param l2 Linea 2
 * @param l4 Linea 4
 * @param l4a Linea 4a
 * @param l5 Linea 5
 * @param l6 Linea 6
 * @param stack_rutas 
 */

/*void busquedaRutaMasCorta(linea inicio, linea destino, linea l1, linea l2, linea l4, linea l4a, linea l5, linea l6, linea *stack_rutas){
    linea metroRed[6] = { l1, l2, l4, l4a, l5, l6 };
    linea estacion_inicial;
    linea estacion_destino;
    estacion_inicial = inicio;
    estacion_destino = destino;
   //std::string ruta;

    if (estacion_inicial->nombre == estacion_destino->nombre ) {
      // stack_rutas.push(ruta);
    }
    if (destinoEnLinea(inicio, destino)){
        std::cout<<"SE ENCUENTRA DESTINO EN LINEA"<<std::endl;
        std::string direccion = buscarDireccion(inicio, destino);
        recorrido ruta;
        recorrerLinea_v2(inicio, destino, direccion, &ruta);

    }
}*/


void rutaMasCorta(linea inicio, linea destino, recorrido *ruta_corta) {
    linea viajero = inicio;
    
    if ( destinoEnLinea(inicio, destino) ) {
        if ( inicio->id > destino->id ) {
            *ruta_corta = recorrerLinea_v2(inicio, destino, "izq");
        } else {
            *ruta_corta = recorrerLinea_v2(inicio, destino, "der");
        }
    } else {
        /* casi :( */
    }
    recorrido aux = *ruta_corta;
    while(aux != NULL) {
        std::cout << aux->estacion->nombre << std::endl;
        aux = aux->link;
    }
    
}

/*error fatal*/
/*recorrido combinacionesLineaX(linea lx) {
    recorrido combinaciones = (recorrido) malloc(sizeof(ruta));
    recorrido aux = combinaciones;
    
    linea left = lx;
    linea right = lx;
    while ( left != NULL ) {
        if( left->combinacion != NULL ) {
            recorrido append = (recorrido) malloc(sizeof(ruta));
            append->estacion = left;
            append->link = NULL;
            
            if( aux != NULL ) {
                aux->link = append;
            } else {
                aux = append;
            }
            aux = aux->link;
        } 
        left->izq;        
    }
    while ( right != NULL ) {
        if( right->combinacion != NULL ) {
            recorrido append = (recorrido) malloc(sizeof(ruta));
            append->estacion = right;
            append->link = NULL;
            
            if( aux != NULL ) {
                aux->link = append;
            } else {
                aux = append;
            }
            aux = aux->link;
        } 
        right->izq;        
    }
    
    recorrido weaita = (recorrido) malloc(sizeof(ruta));
    while(weaita != NULL) {
        std::cout << weaita->estacion->nombre << std::endl;
        weaita = weaita->link;
    }
    
    return combinaciones;
    
}
*/

/**
 * 
 * @param lx
 * @param destino
 * @param sentido
 * @return 
 */
recorrido recorrerLinea_v2(linea inicio, linea destino, std::string sentido) {
    linea aux;
    aux = inicio;
    
    recorrido inicio_destino = (recorrido) malloc(sizeof(ruta));
    recorrido main = inicio_destino;
    main->estacion = aux;
    main->link = NULL;
    while ( aux->nombre != destino->nombre ) {
        // std::cout << estacion->codigo << std::endl;
        recorrido append = (recorrido) malloc(sizeof(ruta));
        if (sentido.compare("der") == 0) {
            //std::cout << estacion->nombre << "  -  ";
            aux = aux->der;           
        } else {
            //std::cout << estacion->nombre << "  -  ";
            aux = aux->izq;        
        }
        append->estacion = aux;
        append->link = NULL;
        
        main->link = append;
        main = main->link;
    }
    return inicio_destino;
    //std::cout << estacion->nombre << std::endl;
}


/**
 * 
 * @param inicio
 * @param destino
 * @return 
 */
bool destinoEnLinea(linea inicio, linea destino){
  if (inicio->nombre_linea == destino->nombre_linea){
    return true;
  }
  return false;
}


/**
 * 
 * @param inicio
 * @param destino
 * @return 
 */
std::string buscarDireccion(linea inicio, linea destino){
  if(inicio->id > destino->id){
    return "izq";
  }else{
    return "der";
  }
}


