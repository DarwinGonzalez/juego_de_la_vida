all:celula_t.hpp tablero_t.hpp main.cpp celula_t.cpp tablero_t.cpp
	g++ -std=c++11 main.cpp tablero_t.cpp celula_t.cpp -o test