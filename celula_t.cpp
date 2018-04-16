
//Algoritmos y Estructuras de Datos Avanzados
//Práctica: Juego de la Vida C++
//AUTOR: Darwin González Suárez
//Archivo donde se implementan los metodos necesarios para el funcionamiento de la clase celula

#include "celula_t.hpp"

cel_t::cel_t(){
    state_ = false;
    num_vecinos_ = 0;
    symbol_ = ' ';
}

cel_t::~cel_t(){
    state_ = false;
    num_vecinos_ = 0;
    symbol_ = ' ';
}

int cel_t::get_num_vecinos(){

    return num_vecinos_;

}

void cel_t::set_num_vecinos(int x){

    num_vecinos_ = x;

}

void cel_t::set_state(bool x){
    state_ = x;
}

bool cel_t::get_state(){
    return state_;
}

void cel_t::cambiar(){
    if(state_){
        set_state(false);
        set_symbol(' ');
    }else{
        set_state(true);
        set_symbol('X');
    }
}

char cel_t::get_symbol(){
    return symbol_;
}

void cel_t::set_symbol(char symbol){
    symbol_ = symbol;
}

void cel_t::reiniciar(){
    num_vecinos_ = 0;
}
