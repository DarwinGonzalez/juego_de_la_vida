
//Algoritmos y Estructuras de Datos Avanzados
//Práctica: Juego de la Vida C++
//AUTOR: Darwin González Suárez
//Archivo donde se declaran los metodos y atributos de la clase celula

#include <stdio.h>

class cel_t {

    bool state_;
    int num_vecinos_;
    char symbol_;

public:
    cel_t();
    ~cel_t();
    int get_num_vecinos();
    void set_num_vecinos(int x);
    void set_state(bool);
    bool get_state();
    void cambiar();
    char get_symbol();
    void set_symbol(char);
    void reiniciar();

};
