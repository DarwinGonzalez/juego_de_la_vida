
//Algoritmos y Estructuras de Datos Avanzados
//Práctica: Juego de la Vida C++
//AUTOR: Darwin González Suárez
//Archivo donde se aloja el programa principal o menú de la práctica


#include "tablero_t.hpp"


int main(void) {

  int N,M;
  int x= 20;

  system("clear");
  cout<<endl<<endl;
  cout << " ▶▶▶▶ PRÁCTICA 1: AEDA ◀◀◀◀" << endl;
  cout <<"Practica ① de Algoritmos y Estructuras de Datos Avanzados:"<<endl;
  cout<<endl;

  cout<<"Para la generación por defecto del tablero introduzca las dimensiones predefinidas."<<endl;
  cout<<"Introduzca las dimensiones que desea: "<<endl;
  cout<<"ALTURA: ";
  cin >> N;
  cout<<"ANCHURA: ";
  cin>> M;
  cout<<endl;

  tablero_t A(N,M);

  A.inicializarTablero();
  while(x < 1000){
  A.analizarVecinos();
  A.avanzarFrame();
  }

}
