#ifndef DADO_H_INCLUDED
#define DADO_H_INCLUDED
#include <time.h>
#include <windows.h>

class Dado{

private:

    int carasChico = 6;

    int carasGrande = 10;

    int moneda = 2;


public:

    Dado(){
        srand(time(NULL));
    };

    int Lanzar(){
        return (1+(rand() % this->carasChico));
    };

    int Lanzar10(){
        return (1+(rand() % this->carasGrande));
    };

    int LanzarMoneda(){
        return (1+(rand() % this->moneda));
    };
};

#endif // DADO_H_INCLUDED
