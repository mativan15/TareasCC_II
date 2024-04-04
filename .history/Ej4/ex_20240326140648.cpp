#include <iostream>
#include "encriptador.h"
using namespace std;

void inicio(){
    bool bucle{true};
    while (bucle){
        Encriptador enc1;
        cout << "\x1B[31m" << "\n\n\tBienvenido, ingresa la operación que quieres realizar: \n\t1. Encriptar\n\t2. Desencriptar" << "\x1B[m \n\t";
        int opcion{0};
        cin >> opcion;
        switch (opcion){
        case 1:
            int c_priv;
            int c_pub;
            cout << "\x1B[32m" << "\n\n\tModo de Encriptación\n\tIngrese una clave pública:" << "\x1B[m \n\t";
            cin >> c_pub;
            enc1.k_pub = c_pub;
            enc1
            break;
        default:
            
            break;
        }
        cal1.print_res();
        int res;
        cout << "\n\n\tIngrese 1 para repetir" << "\n\t";
        cin >> res;
        if (res != 1) {
            bucle = false;
            break;
        }

    }
}


