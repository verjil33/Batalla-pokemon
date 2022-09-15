#ifndef CHARMANDER_H_INCLUDED
#define CHARMANDER_H_INCLUDED
#include "Pokemon.h"

class Charmander : public Pokemon{

private:

    bool revive;
    int golpesRecibidos;

public:

    Charmander(){
        this->vida = 150;
        this->danio = 40;
        this->nombre = "Charmander";
        this->habilidad = true;
        this->golpesRecibidos = 0;
        this->revive = false;
        this->derrotado = false;
        this->envenenado = false;
    };
    //pierde vida cuando pega y si recibe 3 golpes revive
    virtual int Atacar(Pokemon* objetivo){
        if(this->vida > 0){
            std::cout << this->nombre << " Ataca a " << objetivo->getNombre() << " con un danio de: " << this->danio << std::endl <<"Pero sufrio un daño de 10 al atacar"<< std::endl;
            objetivo->RecibirDanio(danio, this);
            this->vida -= 10;
            return this->danio;
        }
    };
    virtual int RecibirDanio(int unDanio, Pokemon* atacante){
        if(habilidad){
            golpesRecibidos++;
            if(golpesRecibidos > 3){
                this->revive = true;
            }
        }
        this->vida -= unDanio;
        if(this->vida < 0){
            this->vida = 0;
        }
        std::cout << this->nombre << " recibio un ataque de " << unDanio << " y su vida disminuyo a " << this->vida << std::endl << std::endl;
        if(this->vida <= 0){
            std::cout << this->getNombre() << " se debilito" << std::endl << std::endl;
            this->derrotado = true;
            if(revive && derrotado){
                this->derrotado = false;
                std::cout << this->nombre << " revivio con una vida de 40 puntos" << std::endl << std::endl;
                this->vida=40;
                this->revive = false;
                this->cambiarHabilidad();
            }

        }
        return unDanio;
    };
};


#endif // CHARMANDER_H_INCLUDED
