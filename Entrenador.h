#ifndef ENTRENADOR_H_INCLUDED
#define ENTRENADOR_H_INCLUDED
#include <string>
#include "Pokemon.h"



class Entrenador{

private:

    std::string nombre;

    std::list<Pokemon*>* pokemones;

    int cantPokemones;

    bool ultimoCaer = false;

public:

    Entrenador(std::string unNombre){
        this->nombre = unNombre;
        this->pokemones = new std::list<Pokemon*>;
    };

    ~Entrenador(){

        std::list<Pokemon*> :: iterator pos;
        pos = this->pokemones->begin();
        while(pos!= this->pokemones->end()){
            delete (*pos);
            pos++;
        }
        delete this->pokemones;
    };

    std::string getNombre(){
        return this->nombre;
    };

    /*
    void cambiarNombre(std::string unNombre){
        this->nombre = unNombre;
    };
    */


    /*
    Pokemon* primerPokemon(){
        std::list<Pokemon*> :: iterator pos;
        pos = this->pokemones->begin();
        return (*pos);
    };
    */

    void AniadirPokemon(Pokemon* unPokemon){
        if(this->pokemones->size() <= 3){
            this->pokemones->push_back(unPokemon);
            cantPokemones++;
            std::cout << "Se añadio el pokemon a la lista del entrenador " << this->nombre << std::endl;
        }
    }

    int SacarPokemon(int unNumero){
        int i = 1;
        std::list<Pokemon*> :: iterator pos;
        pos = this->pokemones->begin();
        while(pos != this->pokemones->end()){
            if(unNumero == i){
                this->pokemones->remove((*pos));
                cantPokemones--;
                return i;
            }
            pos++;
            i++;
        }
        this->pokemones->remove((*pos));

        return i;

    }

   int getCantPokemones(){
        return this->cantPokemones;
   }
    int getPokemones(){
        return this->pokemones->size();
    }

    void MostrarPokemones(){
        int i = 1;
        std::list<Pokemon*> :: iterator pos;
        pos = this->pokemones->begin();
        while(pos != this->pokemones->end()){
            std::cout << "(" << i << ") " << (*pos)->getNombre() << " | ";
            i++;
            pos++;
        }
        std::cout << std::endl << std::endl;

    }
    Pokemon* PokemonElegido(int unNumero){
        int i = 1;
        std::list<Pokemon*> :: iterator pos;
        pos = this->pokemones->begin();
        while(pos != this->pokemones->end()){
            if(unNumero == i){
                return (*pos);
            }
            pos++;
            i++;
        }
        return (*pos);
    }

    void cambiarUltimoCaer(){
        if(this->ultimoCaer){
            this->ultimoCaer=false;
        }
        else{
            this->ultimoCaer=true;
        }
    }

    bool getCaida(){
        return this->ultimoCaer;
    }
};




#endif // ENTRENADOR_H_INCLUDED
