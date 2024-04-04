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
    cout << "Tu clave privada (contraseña) es: " << k_priv << endl;
    f_processing(k_pub);
}
void Encriptador::desencriptar(){
    cout << "Ingresa tu clave privada (contraseña): " << endl;
    
    f_processing(k_pub);
}
void Encriptador::f_processing(int k){
fstream archivo("data.txt", ios::in | ios::out);
    if (!archivo) {
        cerr << "no se pudo abrir archivo xd" << endl;
    }
    while (archivo.get(caracter)){
        ascii = static_cast<int>(caracter);
        ascii = (ascii*k)%256;
        caracter = static_cast<char>(ascii);
        archivo.seekp(-1, ios::cur);
        archivo.put(caracter);
    }
    cout << "Archivo procesado correctamente\n";
    archivo.close();
}