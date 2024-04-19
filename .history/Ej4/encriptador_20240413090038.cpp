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
        fstream archivo1("data.txt", ios::in | ios::out);
        if (!archivo1) {
            cerr << "no se pudo abrir archivo xd" << endl;
        }
        fstream archivo2("encriptado.txt", ios::in | ios::out);
        if (!archivo2) {
            cerr << "no se pudo abrir archivo xd" << endl;
        }
        while (archivo1.get(caracter)){
            ascii = static_cast<int>(caracter);
            ascii = (ascii*k_pub)%256;
            caracter = static_cast<char>(ascii);
            archivo2.put(caracter);
        }
        cout << "\x1B[32m" << "\tArchivo procesado correctamente\n" << "\x1B[m";
        archivo1.close();
        archivo2.close();
    } else {
        cout << "\x1B[31m" << "\tNo se puede generar clave privada, intenta con otro número :(\n" << "\x1B[m";
    }
}
void Encriptador::desencriptar(int c_priv){
    if (c_priv == k_priv){
        //f_processing(k_priv);
    } else if (k_priv==0){
        cout << "\x1B[31m" << "\tEl archivo no está encriptado"  << "\x1B[m" << endl;
    } else {
        cout << "\x1B[31m" << "\tClave incorrecta"  << "\x1B[m" << endl;
    }
    
}
