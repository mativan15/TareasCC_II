#include <iostream>
#include <fstream>
#include "encriptador.h"
#include "inverso.h"
using namespace std;
Encriptador::Encriptador(){
    k_pub = 0;
    k_priv = 0;
    caracter = 0;
}
void Encriptador::encriptar(){
    Inverso inv1(k_pub, 256);
    k_priv = inv1.inverso_m();
    ifstream archivo("data.txt", ios::in);
    if (!archivo) {
        cerr << "no se pudo abrir archivo xd" << endl;
    }
    
    while (archivo.get(ch)) {
        std::cout << ch;
    }
}
void Encriptador::desencriptar(){
union { char
}