
//Algoritmos y Estructuras de Datos Avanzados
//Práctica: Juego de la Vida C++
//AUTOR: Darwin González Suárez
//Archivo donde se implementan los metodos necesarios para el funcionamiento de la clase tablero

#include "tablero_t.hpp"

tablero_t::tablero_t(int n, int m){
    n_ = n;
    m_ = m;
    tab_.resize(n);
    for (int i = 0; i < n_; i++) {
        tab_[i].resize(m_);
    }
    turno_ = 0;
}

tablero_t::~tablero_t(){
    n_ = 0;
    m_ = 0;
    tab_.resize(0);
    tab_.clear();
    turno_ = 0;
}

void tablero_t::inicializarTablero(){

    int aleatorio,col,fil,opt,pos_i,pos_j,num_cel;
    srand(time(NULL));

    cout << "¿Cómo desea inicializar el tablero?(seleccione una de las opciones): "<<endl;
    cout << "[1].Introducir las celulas vivas por teclado dandole su posicion"<<endl;
    cout << "[2].Generar celulas de forma aleatoria por el tablero"<<endl;
    cout << "Introduzca la opción: ";
    cin>>opt;

    if(opt==2){
      aleatorio = rand() % 1 + (n_ * m_);

      for (int i = 0; i < aleatorio; i++) {
          col = rand() % n_;
          fil = rand() % m_;
          tab_[col][fil].cambiar();
      }
      imprimirTablero();
      sleep(2);
    }

    if(opt==1){
      cout <<"Introduza el numero células vivas que quiere introducir al comienzo de la generacion: "<<endl;
	     cin>> num_cel;

		    for(int k =0 ;k < num_cel; k++) {
			       cout << "Introduzca el elemento de la posicion ->( i , j )<- que desea cambiar:"<<endl;
			       cin>>pos_i;
			       cin>>pos_j;
			       tab_[pos_i][pos_j].cambiar();

		     }
         cout<<endl;
         imprimirTablero();
         sleep(2);
    }
}


void tablero_t::analizarVecinos(){

    //Cumprueba el numero de vecinos de cada celula
    for (int i = 0; i < n_; i++) {
        for (int j = 0; j < m_; j++) {
            for (int x = i-1; x <= i+1; x++) {
                for (int y = j-1; y <= j+1; y++) {
                    if (((x >= 0) && (x < n_)) && ((y >= 0) && (y < m_)) && (!((i == x) && ( j == y)))){
                            if(tab_[x][y].get_state()){
                                tab_[i][j].set_num_vecinos(tab_[i][j].get_num_vecinos()+1);
                            }
                    }
                }
            }
        }
    }

    //Transiciones
    for (int i = 0; i < n_; i++) {
        for (int j = 0; j < m_; j++) {
            //Si está muerta y tiene 3 vecinos, "nace"
            if (!tab_[i][j].get_state() && tab_[i][j].get_num_vecinos() == 3) {

                tab_[i][j].cambiar();

            }
            //Si está viva y tiene 2 0 3 vecinos muere
            if (tab_[i][j].get_state() && (tab_[i][j].get_num_vecinos() != 3 && tab_[i][j].get_num_vecinos() != 2)) {

                tab_[i][j].cambiar();
            }
            tab_[i][j].reiniciar();
        }
    }
}

void tablero_t::avanzarFrame(){

        system("clear");
        analizarVecinos();
        imprimirTablero();
        sleep(2);

}

void tablero_t::imprimirTablero(){

  cout << "---  TABLERO JUEGO DE LA VIDA  ---" << endl;
    for (int i = 0; i < m_ - 1; i++) {
        cout << "----";
    }
    cout << "-" << endl;

    for (int i = 0; i < n_; i++) {
        cout << "| ";
        for (int j = 0; j < m_; j++) {
            cout << tab_[i][j].get_symbol();
            cout << " |";
        }
        cout << endl;


        for (int x = 0; x < m_-1; x++) {
            cout << "----";
        }
        cout << "-" << endl;
    }

}
