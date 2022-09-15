#ifndef GASTLY_H_INCLUDED
#define GASTLY_H_INCLUDED
#include "Pokemon.h"

class Gastly : public Pokemon{

public:

    Gastly(){
        this->vida = 120;
        this->danio = 30;
        this->nombre = "Gastly";
        this->habilidad = true;
        this->derrotado = false;
        this->envenenado = false;
    };
    virtual int Atacar(Pokemon* objetivo){
        if(this->vida > 0){
            if(habilidad){
                if(dadito->Lanzar10() > 5){
                    std::cout << this->nombre << " Ataca a " << objetivo->getNombre() << " con un danio de: " << this->danio << " y enveneno a su objetivo" << std::endl;
                    objetivo->RecibirDanio(danio, this);
                    objetivo->envenenar();
                    return this->danio;
                }
                else{
                    std::cout << this->nombre << " Ataca a " << objetivo->getNombre() << " con un danio de: " << this->danio << std::endl;
                    objetivo->RecibirDanio(danio, this);
                    return this->danio;
                }

            }
        }

    };
    virtual int RecibirDanio(int unDanio, Pokemon* atacante){
        this->vida -= unDanio;
        if(this->vida < 0){
        this->vida = 0;
        if(habilidad){
            if(dadito->Lanzar10() > 5){
                std::cout << this->nombre << " recibio un ataque de " << unDanio << " y su vida disminuyo a " << this->vida << " pero enveneno a su objetivo" << std::endl << std::endl;
                atacante->envenenar();
                if(this->vida <= 0){
                    std::cout << this->getNombre() << " se debilito" << std::endl << std::endl;
                    this->derrotado = true;
                }
                return 0;
            }
        }
        std::cout << this->nombre << " recibio un ataque de " << unDanio << " y su vida disminuyo a " << this->vida << std::endl << std::endl;

        if(this->vida <= 0){
            std::cout << this->getNombre() << " se debilito" << std::endl << std::endl;
            this->derrotado = true;
        }
        return unDanio;
    };

};
#endif // GASTLY_H_INCLUDED
