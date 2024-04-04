#include <iostream>
#include <fstream>
#include "encriptador.h"
#include "inverso.h"
using namespace std;
Encriptador::Encriptador(){
    k_pub = 0;
    k_priv = 0;
    caracter = 0;
    ptr = nullptr;
    c_ptr = nullptr;
}
void Encriptador::encriptar(){
    Inverso inv1(k_pub, 256);
    k_priv = inv1.inverso_m();
    ifstream archivo("data.txt", ios::in);
    if (!archivo) {
        cerr << "no se pudo abrir archivo xd" << endl;
    }
    //ptr = (char*)caracter;
    while (archivo.get(caracter)) {
        cout << caracter << " \n" << static_cast<int>(caracter) << endl;
    }
}
void Encriptador::desencriptar(){
//union { char
}