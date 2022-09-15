#ifndef ABRA_H_INCLUDED
#define ABRA_H_INCLUDED
#include "Pokemon.h"

class Abra : public Pokemon{

public:

    Abra(){
        this->vida = 120;
        this->danio = 30;
        this->nombre = "Abra";
        this->habilidad = true;
        this->derrotado = false;
        this->envenenado = false;
    };
    //probabilidad de ignorar defensa

    virtual int Atacar(Pokemon* objetivo){
        if(this->vida > 0){
            std::cout << this->nombre << " Ataca a " << objetivo->getNombre() << " con un danio de: " << this->danio << std::endl;
            if(dadito->Lanzar10() < 3){
                objetivo->cambiarHabilidad();
                std::cout << this->nombre << " esquivo la defensa del enemigo" << std::endl << std::endl;
            }
            objetivo->RecibirDanio(danio,this);
            objetivo->cambiarHabilidad();
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
            std::cout << this->getNombre() << " se debilito" << std::endl << std::endl;
            this->derrotado = true;
        }

        return unDanio;
    };
};


#endif // ABRA_H_INCLUDED
