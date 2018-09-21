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
void pop(recorrido *combinaciones) {    
    recorrido aux = *combinaciones;
    recorrido tmp = *combinaciones;
    
    if ( tmp != NULL ) {
        aux = aux->link;
        *combinaciones = aux;
        free(tmp);
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
        if ( l_right->combinacion && !inLista(r_comb, l_right)) {
            agregarLineaRecorrido(&r_comb, l_right);
        }
        l_right = l_right->der;
    }
    while ( l_left != NULL ) {
        if ( l_left->combinacion && !inLista(r_comb, l_left)) {
            agregarLineaRecorrido(&r_comb, l_left);
        }
        l_left = l_left->izq;
    }    
    *combinaciones = r_comb;
}

bool inLista(recorrido combinaciones, linea lx) {
    recorrido aux = combinaciones;
    bool state = false;
    while(aux != NULL) {
        if ( aux->estacion->nombre == lx->nombre ) {
            return true;
        }
        aux = aux->link;
    }
    return state;
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
    recorrido stack_combinaciones = NULL;
   

    if (destinoEnLinea(estacion_inicio, destino)) {
        std::string direccion;
        direccion = buscarDireccion(estacion_inicio, destino);
        recorrerLinea(estacion_inicio, direccion, destino, &p_ruta);
        mostrarRecorrido(p_ruta);
    } else {
        std::cout << "\nDestino no se encuentra en linea actual"<<std::endl;
        std::cout << "Generando Combinaciones"<<std::endl;

        // combinaciones es para empezar a iterar
        obtenerCombinacionesLinea(&combinaciones, estacion_inicio);
        // stack la envio a la funcion 
        obtenerCombinacionesLinea(&stack_combinaciones, estacion_inicio);

        std::cout << "\nCombinaciones :" << combinaciones->estacion->nombre_linea << std::endl ;
        mostrarRecorrido(combinaciones);
        recorrido combinaciones_conocidas = NULL;
        recorridos rutas = NULL;
        recorrido tmp = combinaciones;

        bool iterar = true;
        int cont = 1;
        while(iterar) {
            buscarDestinoDesde(&tmp, destino, &stack_combinaciones, &combinaciones_conocidas, &rutas);
            pop(&tmp);
            cont++;  
            if (tmp == NULL){
                iterar = false;
            }

        }   
        std::cout << "Combinaciones conocidas: "<<std::endl;
        mostrarRecorrido(combinaciones_conocidas);
        std::cout << "StackCombinaciones: "<<std::endl;
        mostrarRecorrido(stack_combinaciones);
        // if (quedanCombinacionesARecorrer(combinaciones_conocidas)){
        //  std::cout << "\n FaltanCombinaciones: "<<std::endl;
        // }
    }
}

void buscarDestinoDesde(recorrido *inicio_variable, linea destino, recorrido *stack_combinaciones, recorrido *combinaciones_conocidas, recorridos *rutas ){
    recorrido ruta = NULL;
    recorrido stack_combinaciones_p = *stack_combinaciones;
    recorrido combinaciones_conocidas_p = *combinaciones_conocidas;
    recorrido nuevas_combinaciones = NULL;
    recorrido inicio_v = *inicio_variable;
    std::cout << "\nBuscando destino en combinacion: "<< inicio_v->estacion->combinacion->nombre <<std::endl;
    if(destinoEnLinea(inicio_v->estacion->combinacion, destino)){
        agregarLineaRecorrido(&combinaciones_conocidas_p, inicio_v->estacion->combinacion);
        std::cout << "Destino en Linea! -> "<< inicio_v->estacion->combinacion->nombre <<std::endl;
        std::cout << "Combinacion a ... " << inicio_v->estacion->nombre << std::endl;
        std::string direccion;
        direccion = buscarDireccion(inicio_v->estacion->combinacion, destino);
        recorrerLinea(inicio_v->estacion->combinacion, direccion, destino, &ruta);
        mostrarRecorrido(ruta);
    } else {        
        agregarLineaRecorrido(&combinaciones_conocidas_p, inicio_v->estacion->combinacion);
        std::cout << "\nDestino no se encuentra en: "<< inicio_v->estacion->combinacion->nombre <<std::endl;
        std::cout << "\nBuscando sus combinaciones"<<std::endl;
        obtenerCombinacionesLinea(&nuevas_combinaciones, inicio_v->estacion->combinacion);
        std::cout << "\nMostrando combinaciones"<<std::endl;
        mostrarRecorrido(nuevas_combinaciones);
        std::cout << "\nEliminando Combinaciones conocidas"<<std::endl;
        eliminarCombinacionesConocidas(&nuevas_combinaciones, stack_combinaciones_p);
        // mostrarRecorrido(*stack_combinaciones);
        agregarCombinacionesLimpias(&stack_combinaciones_p, nuevas_combinaciones);
    }
    // se guardan combinaciones conocidas
    *combinaciones_conocidas = combinaciones_conocidas_p;
    *stack_combinaciones = stack_combinaciones_p;
    
    std::cout << "\n CombinacionesExploradas: "<< obtenerLargoRecorrido(combinaciones_conocidas_p)<<std::endl;
    if (quedanCombinacionesARecorrer(combinaciones_conocidas_p)){
         std::cout << "\n FaltanCombinaciones: "<<std::endl;
         explorarCombinacionesEnStack(stack_combinaciones_p, combinaciones_conocidas_p, &inicio_v);
    }else{
        //TERMINO
        inicio_v = NULL;
        *inicio_variable = inicio_v;
    }

}
void explorarCombinacionesEnStack(recorrido stack_combinaciones, recorrido combinaciones_conocidas, recorrido *inicio_anterior){
    std::cout<<"explorarCombinacionesEnStack"<<std::endl;
    recorrido combinaciones_faltantes = NULL;

}


bool quedanCombinacionesARecorrer(recorrido combinaciones){
    int largo = obtenerLargoRecorrido(combinaciones);
    if (largo <= 10 ){
        return true;
    }
    return false;
}

int obtenerLargoRecorrido(recorrido lista){
    int contador = 0;
    while(lista){
        contador++;
        lista = lista->link;
    }
    return contador;
}

void agregarCombinacionesLimpias(recorrido *stack_combinaciones, recorrido nuevas_combinaciones){
    recorrido _stack_combinaciones = *stack_combinaciones;
    recorrido _stack_combinaciones_limpias = NULL;
    
    while(_stack_combinaciones){
        if(!inLista(_stack_combinaciones, nuevas_combinaciones->estacion)){
            agregarLineaRecorrido(&_stack_combinaciones_limpias, _stack_combinaciones->estacion);
        }
        _stack_combinaciones = _stack_combinaciones->link;
    }
    while(nuevas_combinaciones){
        if(!inLista(_stack_combinaciones, nuevas_combinaciones->estacion)){
            agregarLineaRecorrido(&_stack_combinaciones_limpias, nuevas_combinaciones->estacion);
        }
        nuevas_combinaciones = nuevas_combinaciones->link;
    }        
    *stack_combinaciones = _stack_combinaciones_limpias;
}

void eliminarCombinacionesConocidas(recorrido *nuevas_combinaciones, recorrido stack_combinaciones){
    recorrido combinaciones_limpias = NULL;
    recorrido combinaciones_entrantes = *nuevas_combinaciones;
    while (combinaciones_entrantes){
        if (!inLista(stack_combinaciones, combinaciones_entrantes->estacion)){
            agregarLineaRecorrido(&combinaciones_limpias, combinaciones_entrantes->estacion);
        } else {
            std::cout<<"Combinacion ya conocida: "<< combinaciones_entrantes->estacion->nombre <<std::endl;
        }
        combinaciones_entrantes = combinaciones_entrantes->link;
    }

    *nuevas_combinaciones = combinaciones_limpias;

}

/*                                          FIN CALCULAR RUTA                                                     */
/******************************************************************************************************************/
