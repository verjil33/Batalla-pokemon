#ifndef SQUIRTLE_H_INCLUDED
#define SQUIRTLE_H_INCLUDED
#include "Pokemon.h"

class squirtle : public Pokemon{

private:

    bool muere;

public:

    squirtle(){
        this->vida = 80;
        this->danio = this->vida;
        this->nombre = "Squirtle";
        this->habilidad = true;
        this->muere = false;
        this->derrotado = false;
        this->envenenado = false;
    };
    //probabilidad de golpe critico al morir
    virtual int Atacar(Pokemon* objetivo){
        if(this->vida > 0){
            this->danio = this->vida;
            std::cout << this->nombre << " Ataca a " << objetivo->getNombre() << " con un danio de: " << this->danio <<std::endl;
            objetivo->RecibirDanio(danio, this);
            return this->danio;
        }
    };
    virtual int RecibirDanio(int unDanio, Pokemon* atacante){
        this->vida -= unDanio;
        if(this->vida < 0){
            this->vida = 0;
        }
        std::cout << this->nombre << " recibio un ataque de " << unDanio << " y su vida disminuyo a " << this->vida << std::endl << std::endl;

        if(this->vida<=0){
            if(dadito->Lanzar10()<4){
                std::cout << this->getNombre() << " se debilito, pero lanzo un ataque critico para derrotar a su oponente" << std::endl << std::endl;
                atacante->RecibirDanio(atacante->getVida(), atacante);
            }
            this->derrotado = true;
        }

        return unDanio;
    };
};


#endif // SQUIRTLE_H_INCLUDED
