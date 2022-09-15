#ifndef BULBASAUR_H_INCLUDED
#define BULBASAUR_H_INCLUDED
#include "Pokemon.h"

class Bulbasaur : public Pokemon{


public:

    Bulbasaur(){
        this->vida = 100;
        this->danio = 0;
        this->nombre = "Bulbasaur";
        this->habilidad = true;
        this->derrotado = false;
        this->envenenado = false;
    };
    //danio entre 10 a 60 y devuelve golpes recibidos
    virtual int Atacar(Pokemon* objetivo){
        if(this->vida > 0){
            danio = (dadito->Lanzar()) * 10;
            std::cout << this->nombre << " Ataca a " << objetivo->getNombre() << " con un danio de: " << this->danio << std::endl;
            objetivo->RecibirDanio(danio,this);
            return this->danio;
        }
    };
    virtual int RecibirDanio(int unDanio, Pokemon* atacante){
        this->vida -= unDanio;
        if(this->vida < 0){
            this->vida = 0;
        }
        std::cout << this->nombre << " recibio un ataque de " << unDanio << " y su vida disminuyo a " << this->vida << std::endl << std::endl;
        if(habilidad){
            if(dadito->Lanzar10() < 4 ){
                //devuelve ataque
                if(this->vida > 0){
                    std::cout << this->getNombre() << " devuelve el ataque" << std::endl;
                    this->Atacar(atacante);
                }
            }
        }
        if(this->vida <= 0){
            std::cout << this->getNombre() << " se debilito" << std::endl << std::endl;
            this->derrotado = true;
        }
        return unDanio;
    };
};


#endif // BULBASAUR_H_INCLUDED
