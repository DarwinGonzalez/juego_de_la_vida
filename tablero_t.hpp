
//Algoritmos y Estructuras de Datos Avanzados
//Práctica: Juego de la Vida C++
//AUTOR: Darwin González Suárez
//Archivo donde declaran los metodos y atributos necesarios para el funcionamiento de la clase tablero

#include "celula_t.hpp"

#include <stdio.h>
#include <vector>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class tablero_t {

    vector<vector<cel_t> > tab_;
    int n_;
    int m_;
    int turno_;

public:

    tablero_t(int n, int m);
    ~tablero_t();
    void inicializarTablero();
    void analizarVecinos();
    void avanzarFrame();
    void imprimirTablero();
};
