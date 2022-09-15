#ifndef POKEMON_H_INCLUDED
#define POKEMON_H_INCLUDED
#include <string>
#include "Dado.h"

class Pokemon{

protected:

    int vida;

    int danio;

    std::string nombre;

    bool habilidad;

    Dado* dadito = new Dado();

    bool derrotado;

    bool envenenado;

public:

    virtual ~Pokemon(){
        delete dadito;
    };

    virtual int Atacar(Pokemon* objetivo)=0;

    virtual int RecibirDanio(int danio, Pokemon* atacante)=0;

    int getVida(){
        return this->vida;
    };
    int getDanio(){
        return this->danio;
    };
    std::string getNombre(){
        return (this->nombre);
    };
    void cambiarHabilidad(){
        if(this->habilidad){
            this->habilidad=false;
        }
        else{
            this->habilidad=true;
        }
    };
    bool getEstado(){
        return this->derrotado;
    }

    void envenenar(){
        this->envenenado = true;
    }
    bool getVeneno(){
        return this->envenenado;
    }
    void danioVeneno(){
        this->vida -= 10;
    }


};
#endif // POKEMON_H_INCLUDED
