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
    fstream archivo("data.txt", ios::in | ios::out);
    if (!archivo) {
        cerr << "no se pudo abrir archivo xd" << endl;
    }
    //ptr = (char*)caracter;
    while (archivo.get(caracter)){
        ascii = static_cast<int>(caracter);
        cout << caracter << " -> " << ascii << "      ";
        ascii = (ascii*k_pub)%256;
        caracter = static_cast<char>(ascii);
        cout << ascii << " -> " << caracter << "      ";
        cout << (ascii*k_priv)%256 << " -> " << static_cast<char>((ascii*k_priv)%256)<< endl;

        archivo.seekp(-1, ios::cur);
        archivo.put(caracter);
    }
    cout << "Archivo encriptado correctamente\n";
    archivo.close();
}
void Encriptador::desencriptar(){
//union { char
}