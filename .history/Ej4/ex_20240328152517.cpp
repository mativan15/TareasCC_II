#include <iostream>
#include "encriptador.h"
#include "inverso.h"
using namespace std;

void inicio(){
    bool bucle{true};
    while (bucle){
        Encriptador enc1;
        cout << "\x1B[31m" << "\n\n\tBienvenido, ingresa la operación que quieres realizar: \n\t1. Encriptar\n\t2. Desencriptar" << "\x1B[m \n\t";
        int opcion{0};
        cin >> opcion;
        int c_priv;
        int c_pub;
        switch (opcion){
        case 1:
            cout << "\x1B[32m" << "\n\n\tModo de Encriptación\n\tIngrese una clave pública:" << "\x1B[m \n\t";
            cin >> c_pub;
            enc1.k_pub = c_pub;
            enc1.encriptar();
            break;
        default:
            cout << "\x1B[32m" << "\n\n\tModo de Desencriptación\n\tIngrese la clave privada:" << "\x1B[m \n\t";
            cin >> c_priv;
            enc1.desencriptar(c_priv);
            break;
        }
        int res;
        cout << "\n\n\tIngrese 1 para repetir" << "\n\t";
        cin >> res;
        if (res != 1) {
            bucle = false;
            break;
        }

    }
}


