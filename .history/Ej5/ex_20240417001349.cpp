#include <iostream>
#include "cocktail.h"
#include "header.h"
using namespace std;
void inicio(){
    bool bucle{true};
    int opcion{0};
    Cocktail cocktail_1;
    int res{0};
    do {
        cout << "\x1B[36m" << "\n\n\tBienvenido, ingresa la operación que quieres realizar:" << "\x1B[m\n\t" << "1. Encriptar\n\t2. Desencriptar" << "\x1B[m \n\t";
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


