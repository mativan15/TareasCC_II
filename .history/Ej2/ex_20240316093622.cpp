#include <iostream>
#include "romanos.h"
using namespace std;

void iniciar(){
    bool bucle{true};
    while (bucle){
        cout << "\x1B[31m" << "\n\n\tBienvenido, ingresa un número del 1-9999: " << "\x1B[m \n";
        int numero{0};
        cin >> numero;
        Romanos rom1(numero);
        rom1
        int res;
        cout << "\n\tIngrese 1 para repetir" << "\n";
        cin >> res;
        if (res != 1) {
            bucle = false;
            break;
        }

    }
}


