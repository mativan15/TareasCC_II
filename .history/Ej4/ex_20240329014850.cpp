#include <iostream>
#include "encriptador.h"
#include "inverso.h"
using namespace std;

void inicio(){
    bool bucle{true};
    int c_priv{0};
    int c_pub{0};
    int opcion{0};
    Encriptador enc1;
    int res{0};
    do {
        cout << "\x1B[33m" << "\n\n\tBienvenido, ingresa la operación que quieres realizar: \n\t1. Encriptar\n\t2. Desencriptar" << "\x1B[m \n\t";
        cin >> opcion;
        if (cin.fail() || !(opcion >= 1 && opcion <= 2)) {
            cout << "\n\tValor incorrecto! Ingrese una opcion válida:\n"; 
            cin.clear();           
            cin.ignore(100, '\n');
        } else {
            switch (opcion){
            case 1:
                cout << "\x1B[36m" << "\n\n\tModo de Encriptación\n\tIngrese una clave pública:" << "\x1B[m \n\t";
                cin >> c_pub;
                enc1.k_pub = c_pub;
                enc1.encriptar();
                cout << "\n" << res << "\n";
                res = 1;
                break;
            default:
                cout << "\x1B[36m" << "\n\n\tModo de Desencriptación\n\tIngrese la clave privada:" << "\x1B[m \n\t";
                cin >> c_priv;
                enc1.desencriptar(c_priv);
                res = 1;
                break;
            }
        }
        cout << "\n\n\tIngrese 1 para repetir" << "\n\t";
        cin >> res;
        if (res != 1) {
            bucle = false;
            break;
        }
    }while (bucle);
}


