#include "dataloader.h"
#include "metrored.h"
#include <cstring>

/******************************************************************************************************************/
/*          OPERACIONES OPERACIONES SOBRE UNA LISTA DE TIPO RECORRIDO, AGREGAR, QUITAR, MOSTRAR, LARGO            */

// DOCUMENTAR
void agregarLineaRecorrido(recorrido *p_ruta, linea p_estacion) {
    recorrido auxiliar = *p_ruta;
    
    recorrido nuevo_nodo;
    nuevo_nodo = (recorrido) malloc(sizeof(ruta));
    nuevo_nodo->estacion = p_estacion;
    nuevo_nodo->link = NULL;
    
    if(auxiliar == NULL) {   
        *p_ruta = nuevo_nodo;        
    } else {
        while( auxiliar->link != NULL ) {
            auxiliar = auxiliar->link;
        }
        
        auxiliar->link = nuevo_nodo;
    }
}

// DOCUMENTAR
linea pop(recorrido *combinaciones) {    
    recorrido aux = *combinaciones;
    
    if ( aux == NULL ) return NULL;
    else {
        recorrido tmp = aux;
        aux = aux->link;
        *combinaciones = aux;
        free(tmp);
        return aux->estacion;
    }
    
}

// DOCUMENTAR
void mostrarRecorrido(recorrido p_ruta) {
    recorrido auxiliar = p_ruta;
    
    while( auxiliar != NULL ) {
        std::cout << auxiliar->estacion->nombre_linea << "\t"
                << auxiliar->estacion->codigo << "\t" 
                << auxiliar->estacion->nombre << std::endl;
        auxiliar = auxiliar->link;
    }
}

//DOCUMENTAR
int largoRecorrido(recorrido p_ruta) {
    int largo = 0;
    recorrido aux = p_ruta;
    
    while( aux != NULL ) {
        largo++;
        aux = aux->link;
    }
    
    return largo;
}

/*      FIN OPERACIONES OPERACIONES SOBRE UNA LISTA DE TIPO RECORRIDO, AGREGAR, QUITAR, MOSTRAR, LARGO            */
/******************************************************************************************************************/


/******************************************************************************************************************/
/*                                    INICIO OPERACIONES BASICAS                                                  */

bool destinoEnLinea(linea inicio, linea destino){
  return (inicio->nombre_linea == destino->nombre_linea) ? true : false;
}


std::string buscarDireccion(linea inicio, linea destino){
  return (inicio->id > destino->id) ? "izq" : "der";
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
    
    return NULL;
}


int calcularDistanciaMismaLinea(linea inicio, linea destino){
    /* se calcula distancia si pertenecen a la misma linea previamente */
    return (inicio->id > destino->id) ? inicio->id - destino->id : destino->id - inicio->id;
}


void hacerCombinacion(linea *lx) {
    linea combinate = *lx;
    if(combinate->combinacion != NULL) {
        combinate = combinate->combinacion;
    }
    *lx = combinate;
}

// DOCUMENTAR
void recorrerLinea(linea lx, std::string sentido, linea destino, recorrido *p_ruta) {
    linea estacion;
    estacion = lx;
    recorrido tmp = *p_ruta;
    /* se asume que esta en la misma linea */
    while ( estacion != destino ) {
        if (sentido.compare("der") == 0) {               
            agregarLineaRecorrido(&tmp, estacion);
            estacion = estacion->der;
        } else {
            agregarLineaRecorrido(&tmp, estacion);
            estacion = estacion->izq;
        }
    } 
    agregarLineaRecorrido(&tmp, estacion);
    
    
    *p_ruta = tmp;
}

// DOCUMEMTAR
void obtenerCombinacionesLinea(recorrido *combinaciones, linea lx) {
    recorrido r_comb = *combinaciones;
    linea l_right, l_left;
    l_right = lx;
    l_left = lx;
    
    while ( l_right != NULL ) {
        if ( l_right->combinacion ) {
            agregarLineaRecorrido(&r_comb, l_right);
        }
        l_right = l_right->der;
    }
    while ( l_left != NULL ) {
        if ( l_left->combinacion) {
            agregarLineaRecorrido(&r_comb, l_left);
        }
        l_left = l_left->izq;
    }    
    *combinaciones = r_comb;
}


/*                                  FIN INICIO OPERACIONES BASICAS                                                */
/******************************************************************************************************************/



/******************************************************************************************************************/
/*                                    INICIO CALCULAR RUTA                                                        */

void testingRecorrerLinea(linea inicio, linea destino) {
    linea estacion_inicio;
    estacion_inicio = inicio;
    
    recorrido combinaciones = NULL; 
    recorrido p_ruta = NULL;
   
    
    if (destinoEnLinea(estacion_inicio, destino)) {
        std::string direccion;
        direccion = buscarDireccion(estacion_inicio, destino);
        recorrerLinea(estacion_inicio, direccion, destino, &p_ruta);
        mostrarRecorrido(p_ruta);
    } else {
        obtenerCombinacionesLinea(&combinaciones, estacion_inicio);
        mostrarRecorrido(combinaciones);
    }

    
//    mostrarRecorrido(p_ruta);
}



/*                                          FIN CALCULAR RUTA                                                     */
/******************************************************************************************************************/
