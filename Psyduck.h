#ifndef PSYDUCK_H_INCLUDED
#define PSYDUCK_H_INCLUDED
#include "Pokemon.h"

class Psyduck : public Pokemon{

private:

    bool primerGolpe;

public:

    Psyduck(){
        this->vida = 100;
        this->danio = 10;
        this->nombre = "Psyduck";
        this->habilidad = true;
        this->primerGolpe = false;
        this->derrotado = false;
        this->envenenado = false;
    };
    //aumenta vida cuando ataca y danio cuando pierde danio
    virtual int Atacar(Pokemon* objetivo){
        if(this->vida > 0){
            std::cout << this->nombre << " Ataca a " << objetivo->getNombre() << " con un danio de: " << this->danio << std::endl;
            objetivo->RecibirDanio(danio,this);
            this->vida += 10;
            return this->danio;
        }
    };
    virtual int RecibirDanio(int unDanio, Pokemon* atacante){
        if(habilidad){
            if(!primerGolpe){
                std::cout << this->getNombre() << " se ah defendido del primer golpe" << std::endl;
                primerGolpe=true;
                return 0;
            }
        }
        this->vida -= unDanio;
        this->danio +=10;
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


#endif // PSYDUCK_H_INCLUDED
