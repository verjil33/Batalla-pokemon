#ifndef BATALLA_H_INCLUDED
#define BATALLA_H_INCLUDED
#include <iostream>

#include "Pokemon.h"
#include "Pikachu.h"
#include "squirtle.h"
#include "Charmander.h"
#include "Bulbasaur.h"
#include "Psyduck.h"
#include "Abra.h"
#include "Gastly.h"
#include "Entrenador.h"
#include "Dado.h"


class Batalla{

private:

    Entrenador* entrenadorRojo;

    Entrenador* entrenadorAzul;

    Dado* dadito;

    int jugadorInicial;

    int eleccionRojo;

    int eleccionAzul;

    int pokemonesRojo;

    int pokemonesAzul;

public:

    Batalla(){
        this->dadito = new Dado();
    };

    ~Batalla(){

        entrenadorRojo->~Entrenador();

        entrenadorAzul->~Entrenador();

        delete this->dadito;

    };

    void Iniciar(){

         std::cout << "Ingrese el nombre del jugador ROJO" << std::endl;

         this->entrenadorRojo = this->setJugador();

         std::cout << "Ingrese el nombre del jugador AZUL" << std::endl;

         this->entrenadorAzul = this->setJugador();

         while(this->entrenadorAzul->getNombre() == this->entrenadorRojo->getNombre()){

            std::cout << "Los nombres de los entrenadores son iguales, por favor, ingrese uno diferente" << std::endl;

            this->entrenadorAzul = this->setJugador();
         }

         DeterminarSeleccionador();

         getch();

         system("cls");

         Combate();

    };


    Entrenador* setJugador(){

        std::string nombre;

        std::cout << "Nombre:";

        std::cin >> nombre;

        return(new Entrenador(nombre));
    };

    void DeterminarSeleccionador(){


        std::cout << "Se lanzara una moneda para determinar que cual entrenador elegira primero. Cara "<< this->entrenadorRojo->getNombre() <<", cruz " << this->entrenadorAzul->getNombre() << std::endl;
        getch();
        std::cout << "Para elegir un pokemon selecicone el numero que corresponde a cada Pokemon para elegirlo" << std::endl;
        getch();

        if(dadito->LanzarMoneda() == 1){

            std::cout << "Salio cara" << std::endl;
            this->jugadorInicial = 1;
            std::cout << "El entrenador " << this->entrenadorRojo->getNombre() << " elijira primero." << std::endl << std::endl;
            getch();
            system("cls");
            ExplicacionPoke();
            do{
                std::cout << this->entrenadorRojo->getNombre() << " elija un pokemon:" << std::endl;

                SeleccionarPokemon(this->entrenadorRojo);
                this->pokemonesRojo++;

            }while(this->entrenadorRojo->getPokemones() < 3);

            std::cout << std::endl << "Ahora le toca al entrenador " << this->entrenadorAzul->getNombre() << " elijir sus pokemones" << std::endl << std::endl;
            getch();
            system("cls");
            ExplicacionPoke();
            do{
                std::cout << this->entrenadorAzul->getNombre() << " elija un pokemon:" << std::endl;

                SeleccionarPokemon(this->entrenadorAzul);
                this->pokemonesAzul++;

            }while(this->entrenadorAzul->getPokemones() < 3);
        }
        else{
            std::cout << "Salio cruz" << std::endl;
            jugadorInicial = 2;
            std::cout << "El entrenador " << this->entrenadorAzul->getNombre() << " elijira primero." << std::endl << std::endl;
            getch();
            system("cls");
            ExplicacionPoke();

            do{
                std::cout << this->entrenadorAzul->getNombre() << " elija un pokemon:" << std::endl;

                SeleccionarPokemon(this->entrenadorAzul);
                this->pokemonesAzul++;

            }while(this->entrenadorAzul->getPokemones() < 3);
            std::cout << std::endl << "Ahora le toca al entrenador " << this->entrenadorRojo->getNombre() << " elijir sus pokemones" << std::endl << std::endl;
            getch();
            system("cls");
            ExplicacionPoke();
            do{
                std::cout << this->entrenadorRojo->getNombre() << " elija un pokemon:" << std::endl;
                SeleccionarPokemon(this->entrenadorRojo);
                this->pokemonesRojo++;

            }while(this->entrenadorRojo->getPokemones() < 3);
        }


    }
    void SeleccionarPokemon(Entrenador* unEntrenador){

        int dado1, dado2, ingreso;

        dado1 = dadito->Lanzar();

        if(dado1 == 1){
            std::cout << "(1)Pikachu" << std::endl;
        }
        else if(dado1 == 2){
            std::cout << "(2)Squirtle" << std::endl;
        }
        else if(dado1 == 3){
            std::cout << "(3)Charmander" << std::endl;
        }
        else if(dado1 == 4){
            std::cout << "(4)Bulbasaur" << std::endl;
        }
        else if(dado1 == 5){
            std::cout << "(5)Psyduck" << std::endl;
        }
        else if(dado1 == 6){
            std::cout << "(6)Abra" << std::endl;
        }
        else if(dado1 == 7){
            std::cout << "(7)Gastly" << std::endl;
        }

        dado2 = dadito->Lanzar();

        if(dado2 == 1){
            std::cout << "(1)Pikachu" << std::endl;
        }
        else if(dado2 == 2){
            std::cout << "(2)Squirtle" << std::endl;
        }
        else if(dado2 == 3){
            std::cout << "(3)Charmander" << std::endl;
        }
        else if(dado2 == 4){
            std::cout << "(4)Bulbasaur" << std::endl;
        }
        else if(dado2 == 5){
            std::cout << "(5)Psyduck" << std::endl;
        }
        else if(dado2 == 6){
            std::cout << "(6)Abra" << std::endl;
        }
        else if(dado2 == 7){
            std::cout << "(7)Gastly" << std::endl;
        }
        std::cin >> ingreso;

        while(ingreso != dado1 && ingreso != dado2){
            std::cout << "Por favor, ingrese un numero para seleccionar su Pokemon" << std::endl;
            std::cin >> ingreso;
        }
        if(ingreso == 1){
            unEntrenador->AniadirPokemon(new Pikachu());
        }
        else if(ingreso == 2){
            unEntrenador->AniadirPokemon(new squirtle());
        }
        else if(ingreso == 3){
            unEntrenador->AniadirPokemon(new Charmander());
        }
        else if(ingreso == 4){
            unEntrenador->AniadirPokemon(new Bulbasaur());
        }
        else if(ingreso == 5){
            unEntrenador->AniadirPokemon(new Psyduck());
        }
        else if(ingreso == 6){
            unEntrenador->AniadirPokemon(new Abra());
        }
        else if(ingreso == 7){
            unEntrenador->AniadirPokemon(new Gastly());
        }
    }
    void Combate(){

        std::cout << "Comienza la batalla Pokemon, cada entrenador elige que Pokemon usar." << std::endl;
        //getch();
        std::cout << "Cuando un Pokemon es derrotado, el entrenador debera elegir otro pokemon" << std::endl;
        //getch();
        if(jugadorInicial == 1){
            std::cout << std::endl << "El entrenador ROJO -"<< this->entrenadorRojo->getNombre() << "- comenzara la batalla, Ambos enviran a sus Pokemones al campo de batalla." << std::endl;
            //getch();
            do{
                if(this->pokemonesRojo == this->entrenadorRojo->getCantPokemones()){
                    std::cout << std::endl << entrenadorRojo->getNombre() << " sus pokemones son:" << std::endl;
                    entrenadorRojo->MostrarPokemones();
                    std::cout << "Elija uno para enviarlo al combate " << std::endl;
                    std::cin >> this->eleccionRojo;
                }
                if(this->pokemonesAzul == this->entrenadorAzul->getCantPokemones()){
                    std::cout << std::endl << entrenadorAzul->getNombre() << " sus pokemones son:" << std::endl;
                    entrenadorAzul->MostrarPokemones();
                    std::cout << "Elija uno para enviarlo al combate " << std::endl;
                    std::cin >> this->eleccionAzul;
                }
                system("cls");
                std::cout << std::endl;
                if(this->pokemonesRojo == this->entrenadorRojo->getCantPokemones()){
                    std::cout << this->entrenadorRojo->getNombre() << " Envia a su " << this->entrenadorRojo->PokemonElegido(this->eleccionRojo)->getNombre() << std::endl << std::endl;
                    this->pokemonesRojo--;
                }
                if(this->pokemonesAzul == this->entrenadorAzul->getCantPokemones()){
                    std::cout << this->entrenadorAzul->getNombre() << " Envia a su " << this->entrenadorAzul->PokemonElegido(this->eleccionAzul)->getNombre() << std::endl << std::endl;
                    this->pokemonesAzul--;
                }


                if(this->entrenadorAzul->getCaida()){
                    this->entrenadorAzul->cambiarUltimoCaer();
                    Encuentro(this->entrenadorAzul, this->entrenadorRojo, this->eleccionAzul, this->eleccionRojo);
                }
                else if(this->entrenadorRojo->getCaida()){
                    this->entrenadorRojo->cambiarUltimoCaer();
                    Encuentro(this->entrenadorRojo, this->entrenadorAzul, this->eleccionRojo, this->eleccionAzul);
                }
                else{
                    Encuentro(this->entrenadorRojo, this->entrenadorAzul, this->eleccionRojo, this->eleccionAzul);
                }


                std::cout << "A " << this->entrenadorRojo->getNombre() << " le quedan " << this->entrenadorRojo->getPokemones() << " Pokemones" << std::endl;

                std::cout << "A " << this->entrenadorAzul->getNombre() << " le quedan " << this->entrenadorAzul->getPokemones() << " Pokemones" << std::endl;


            }while(this->entrenadorAzul->getPokemones() > 0 && this->entrenadorRojo->getPokemones() > 0);

        }
        else{
            std::cout << "El entrenador AZUL -"<< this->entrenadorAzul->getNombre() << "- comenzara la batalla, Ambos enviaran a sus Pokemones al campo de batalla." << std::endl;
            //getch();
            do{
                if(this->pokemonesAzul == this->entrenadorAzul->getCantPokemones()){

                    std::cout << std::endl << entrenadorAzul->getNombre() << " sus pokemones son:" << std::endl;
                    entrenadorAzul->MostrarPokemones();
                    std::cout << "Elija uno para enviarlo al combate " << std::endl;
                    std::cin >> this->eleccionAzul;
                }
                if(this->pokemonesRojo == this->entrenadorRojo->getCantPokemones()){
                    std::cout << std::endl << entrenadorRojo->getNombre() << " sus pokemones son:" << std::endl;
                    entrenadorRojo->MostrarPokemones();
                    std::cout << "Elija uno para enviarlo al combate " << std::endl;
                    std::cin >> this->eleccionRojo;

                }
                    system("cls");
                    std::cout << std::endl;
                    if(this->pokemonesAzul == this->entrenadorAzul->getCantPokemones()){
                        std::cout << this->entrenadorAzul->getNombre() << " Envia a su " << this->entrenadorAzul->PokemonElegido(this->eleccionAzul)->getNombre() << std::endl << std::endl;
                        this->pokemonesAzul--;
                    }
                    if(this->pokemonesRojo == this->entrenadorRojo->getCantPokemones()){
                        std::cout << this->entrenadorRojo->getNombre() << " Envia a su " << this->entrenadorRojo->PokemonElegido(this->eleccionRojo)->getNombre() << std::endl << std::endl;
                         this->pokemonesRojo--;
                    }


                if(this->entrenadorRojo->getCaida()){
                    this->entrenadorRojo->cambiarUltimoCaer();
                    Encuentro(this->entrenadorRojo, this->entrenadorAzul, this->eleccionRojo, this->eleccionAzul);
                }
                else if (this->entrenadorAzul->getCaida()){
                    this->entrenadorAzul->cambiarUltimoCaer();
                    Encuentro(this->entrenadorAzul, this->entrenadorRojo, this->eleccionAzul, this->eleccionRojo);
                }
                else{
                    Encuentro(this->entrenadorAzul, this->entrenadorRojo, this->eleccionAzul, this->eleccionRojo);
                }
                std::cout << "A " << this->entrenadorRojo->getNombre() << " le quedan " << this->entrenadorRojo->getPokemones() << " Pokemones" << std::endl;

                std::cout << "A " << this->entrenadorAzul->getNombre() << " le quedan " << this->entrenadorAzul->getPokemones() << " Pokemones" << std::endl;

                getch();

            }while(this->entrenadorRojo->getPokemones() > 0 && this->entrenadorAzul->getPokemones() > 0);

        }
        std::cout << "La batalla termino" << std::endl;

        if(this->entrenadorRojo->getPokemones() == this->entrenadorAzul->getPokemones()){
            std::cout <<  "Ambos entrenadores se qeudaron sin Pokemones, la batalla ah terminado en EMPATE" << std::endl;
        }
        else if(this->entrenadorRojo->getPokemones() <= 0){
            std::cout << this->entrenadorAzul->getNombre() << " ah ganado la batalla" << std::endl;
            std::cout << this->entrenadorRojo->getNombre() << " ah perdido la batalla" << std::endl;
        }
        else if(this->entrenadorAzul->getPokemones() <= 0){
            std::cout << this->entrenadorRojo->getNombre() << " ah ganado la batalla" << std::endl;
            std::cout << this->entrenadorAzul->getNombre() << " ah perdido la batalla" << std::endl;
        }
    };

    void Encuentro(Entrenador* primerEntrenador, Entrenador* segundoEntrenador, int eleccionPrimero, int eleccionSegundo){

        do{
                std::cout << primerEntrenador->PokemonElegido(eleccionPrimero)->getNombre() << " de " << primerEntrenador->getNombre() << " se prepara para atacar a " << segundoEntrenador->PokemonElegido(eleccionSegundo)->getNombre() << " de " << segundoEntrenador->getNombre() << std::endl;

                primerEntrenador->PokemonElegido(eleccionPrimero)->Atacar(segundoEntrenador->PokemonElegido(eleccionSegundo));

                std::cout << std::endl;

                if(segundoEntrenador->PokemonElegido(eleccionSegundo)->getVida() > 0){

                    std::cout << segundoEntrenador->PokemonElegido(eleccionSegundo)->getNombre() << " de " << segundoEntrenador->getNombre() << " se prepara para atacar a " << primerEntrenador->PokemonElegido(eleccionPrimero)->getNombre() << " de " << primerEntrenador->getNombre() << std::endl;

                    segundoEntrenador->PokemonElegido(eleccionSegundo)->Atacar(primerEntrenador->PokemonElegido(eleccionPrimero));

                    std::cout << std::endl;
            }

            if(primerEntrenador->PokemonElegido(eleccionPrimero)->getVeneno()){
                primerEntrenador->PokemonElegido(eleccionPrimero)->danioVeneno();
            }
             if(segundoEntrenador->PokemonElegido(eleccionSegundo)->getVeneno()){
                segundoEntrenador->PokemonElegido(eleccionSegundo)->danioVeneno();
            }
            getch();

        }while(!segundoEntrenador->PokemonElegido(eleccionSegundo)->getEstado() && !primerEntrenador->PokemonElegido(eleccionPrimero)->getEstado());

        if(primerEntrenador->PokemonElegido(eleccionPrimero)->getEstado()){
            std::cout << primerEntrenador->PokemonElegido(eleccionPrimero)->getNombre() << " de " << primerEntrenador->getNombre() << " ah sido vencido" << std::endl << std::endl;
            primerEntrenador->SacarPokemon(eleccionPrimero);
            primerEntrenador->cambiarUltimoCaer();

        }
        if(segundoEntrenador->PokemonElegido(eleccionSegundo)->getEstado()){
            std::cout << segundoEntrenador->PokemonElegido(eleccionSegundo)->getNombre() << " de " << segundoEntrenador->getNombre() << " ah sido vencido" << std::endl << std::endl;
            segundoEntrenador->SacarPokemon(eleccionSegundo);
            segundoEntrenador->cambiarUltimoCaer();

        }
        getch();
    }

    void ExplicacionPoke(){
        std::cout << "Los Pokemones para elegir son:\n\nPikachu (Vida: 120, Danio: 30, 40 puntos despues de realizar 3 ataques, Habilidad especial: Posibilidad de esquiver un ataque)" << std::endl << std::endl;

        std::cout << "Squirtle (Vida: 80, Danio: igual a la vida actual, Habilidad especial: Probabilidad de ralizar un golpe critico al morir )" << std::endl << std::endl;

        std::cout << "Charmander (Vida: 150, Danio: 40, Habilidad especial: Si recibe 3 golpes, al morir revive con 40 de vida )" << std::endl << std::endl;

        std::cout << "Bulbasaur (Vida: 100, Danio: 10-60 multiplos de 10, Habilidad especial: Probabilidad de devolver ataque )" << std::endl << std::endl;

        std::cout << "Psyduck (Vida: 100 + 10 por cada golpe realizado, Danio: 10 + 10 por cada golpe recibido, Habilidad especial: Ignora el primer golpe)" << std::endl << std::endl;

        std::cout << "Abra (Vida: 120, Danio: 30, Habilidad especial: posibilidad de ignorar la defensa del enemigo)" << std::endl << std::endl;

    }
};



#endif // BATALLA_H_INCLUDED
