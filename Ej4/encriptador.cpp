#include <iostream>
#include <fstream>
#include "encriptador.h"
#include "inverso.h"
using namespace std;
Encriptador::Encriptador(){
    k_pub = 0;
    k_priv = 0;
    caracter = 0;
    ascii = 0;
}
void Encriptador::encriptar(){
    Inverso inv1(k_pub, 256);
    k_priv = inv1.inverso_m();
    if (k_priv!=0){
        cout << "\tTu clave privada (contraseña) es: " << k_priv << endl;
        f_processing(k_pub);
    } else {
        cout << "\x1B[31m" << "\tNo se puede generar clave privada, intenta con otro número\n" << "\x1B[m";
    }
}
void Encriptador::desencriptar(int c_priv){
    if (c_priv == k_priv){
        f_processing(k_priv);
    } else if (k_priv==0){
        cout << "\x1B[31m" << "\tEl archivo no está encriptado"  << "\x1B[m" << endl;
    } else {
        cout << "\x1B[31m" << "\tClave incorrecta"  << "\x1B[m" << endl;
    }
    
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
    cout << "\x1B[32m" << "\tArchivo procesado correctamente\n" << "\x1B[m";
    archivo.close();
}