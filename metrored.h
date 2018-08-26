#include <string>
#include <iostream>
#include "dataloader.h"


#ifndef METRORED_H
#define METRORED_H

   
    typedef struct ruta{
        linea estacion;
        struct ruta*link;
    }ruta;

    typedef ruta*recorrido;
    
    
    /**
    * Funcion que valida si existe destino en la misma linea consultada
    * @param inicio Estacion inicio
    * @param destrino Estacion destino
    * @return
    */
    bool destinoEnLinea(linea inicio, linea destino);
    
    /**
    * Funcion que genera la direccion a recorrer
    * @param inicio 
    * @param destino
    * @return
    */
    std::string buscarDireccion(linea incio, linea destino);
    
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
    linea getUbicacion(char* estacion, linea l1, linea l2, linea l4, linea l4a, linea l5, linea l6);
    
    /**
     * Funcion que retorna la distancia entre dos estaciones
     * @param inicio
     * @param destino
     * @return 
     */
    int calcularDistanciaMismaLinea(linea inicio, linea destino);
    
    /**
     * Funcion que realiza combinacion cambiando al nodo siguiente nodo*combinacion
     * @param lx
     */
    void hacerCombinacion(linea *lx);
   
    /**
     * Funcion encargada de recorrer la linea X, con la direccion/sentido por parámetro
     * @param lx Linea a recorrer
     * @param sentido Sentido/Direccion a moverse por la linea
     */
    void recorrerLinea(linea lx, std::string sentido);
    
    
    
    

#endif /* METRORED_H */
