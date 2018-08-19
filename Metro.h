//
// Created by no-name on 8/18/18.
//

#ifndef METRO_H
#define METRO_H

#include <string>

class Metro {

    typedef std::string array[2];

    typedef struct Estacion {
        int id;
        std::string codigo;
        std::string nombre;
        struct Estacion*izq;
        struct Estacion*der;
        array combinacion;
    }Estacion;

    public:
        Metro();
        Metro(const char* fichero);
        virtual ~Metro();
        void setEstaciones();
        //void setEstaciones();
        //std::string caminoMasCorto(Estacion estacion_inicio, Estacion estacion_destino);

    private:
        int id;
        Estacion* estaciones = NULL;
};

#endif /* METRO_H */

