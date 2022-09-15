#ifndef PIKACHU_H_INCLUDED
#define PIKACHU_H_INCLUDED
#include "Pokemon.h"


class Pikachu : public Pokemon{



public:

    Pikachu(){
        this->vida = 120;
        this->danio = 30;
        this->nombre = "Pikachu";
        this->habilidad = true;
        this->derrotado = false;
        this->envenenado = false;
    };
    //probabilidad de esquivar ataques
    virtual int Atacar(Pokemon* objetivo){
        if(this->vida > 0){
            std::cout << this->nombre << " Ataca a " << objetivo->getNombre() << " con un danio de: " << this->danio << std::endl;
            objetivo->RecibirDanio(danio, this);
            return this->danio;
        }

    };
    virtual int RecibirDanio(int unDanio, Pokemon* atacante){

        if(habilidad){
            if(dadito->Lanzar10() > 5){
                std::cout << this->getNombre() << " Logro esquivar el ataque" << std::endl << std::endl;
                //esquiva
                return 0;
            }
        }
        //recibe danio
        this->vida -= unDanio;
        if(this->vida < 0){
            this->vida = 0;
        }
        std::cout << this->nombre << " recibio un ataque de " << unDanio << " y su vida disminuyo a " << this->vida << std::endl << std::endl;

        if(this->vida <= 0){
            std::cout << this->getNombre() << " se debilito" << std::endl << std::endl;
            this->derrotado = true;
        }

        return unDanio;
    };

};
#endif // PIKACHU_H_INCLUDED
