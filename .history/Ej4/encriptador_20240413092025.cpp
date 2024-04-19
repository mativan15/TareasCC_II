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
        fstream archivo1("data.txt", ios::in |ios::out);
        if (!archivo1) {
            cerr << "no se pudo abrir archivo xd" << endl;
        }
        while (archivo1.get(caracter)){
            //cout << "hola"<<caracter << endl;
            ascii = static_cast<int>(caracter);
            ascii = (ascii*k_pub)%256;
            caracter = static_cast<char>(ascii);
            textoo1 += caracter;
        }
        cout << textoo1 << endl;
        archivo1.close();
        fstream archivo2("encriptadooo.txt", ios::in | ios::out);
        if (!archivo2) {
            cerr << "no se pudo abrir archivo xd" << endl;
        }
        archivo2<<textoo1;
        archivo2.close();
        cout << "\x1B[32m" << "\tArchivo procesado correctamente\n" << "\x1B[m";
    } else {
        cout << "\x1B[31m" << "\tNo se puede generar clave privada, intenta con otro número :(\n" << "\x1B[m";
    }
}
void Encriptador::desencriptar(int c_priv){
    if (c_priv == k_priv){
        //f_processing(k_priv);
        fstream archivo2("encriptadooo.txt", ios::in |ios::out);
        if (!archivo2) {
            cerr << "no se pudo abrir archivo xd" << endl;
        }
        while (archivo2.get(caracter)){
            ascii = static_cast<int>(caracter);
            ascii = (ascii*k_priv)%256;
            caracter = static_cast<char>(ascii);
            textoo2 += caracter;
        }
        cout << textoo1 << endl;
        archivo2.close();
        fstream archivo3("desencriptadooo.txt", ios::in |ios::out);
        if (!archivo3) {
            cerr << "no se pudo abrir archivo xd" << endl;
        }
        archivo3<<textoo1;

        archivo3.close();
        cout << "\x1B[32m" << "\tArchivo procesado correctamente\n" << "\x1B[m";
    } else if (k_priv==0){
        cout << "\x1B[31m" << "\tEl archivo no está encriptado"  << "\x1B[m" << endl;
    } else {
        cout << "\x1B[31m" << "\tClave incorrecta"  << "\x1B[m" << endl;
    }
    
}
