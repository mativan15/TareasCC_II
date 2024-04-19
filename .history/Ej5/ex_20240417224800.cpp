#include <iostream>
#include "cocktail.h"
#include "header.h"
using namespace std;
void inicio(){
    bool bucle{true};
    int opcion{0};
    int res{0};
    do {
        Cocktail cocktail_1;
        cout << "\x1B[36m" << "\n\n\tBienvenido, ingresa la operación que quieres realizar:" << "\x1B[m\n\t" << "1. Cocktail Sort\n\t2. Binary Search" << "\x1B[m \n\t";
        cin >> opcion;
        if (cin.fail() || !(opcion >= 1 && opcion <= 2)) {
            cout << "\n\tValor incorrecto! Ingrese una opcion válida:\n"; 
            cin.clear();           
            cin.ignore(100, '\n');
        } else {
            switch (opcion){
            case 1:
                cout << "\x1B[36m" << "\n\n\tCocktail Sort" << "\x1B[m \n\t";
                cout << "Array random: ";
                cocktail_1.print();
                cocktail_1.ordenar();
                cout << "Array ordenado: ";
                cocktail_1.print();
                res = 1;
                break;
            default:
                cout << "\x1B[36m" << "\n\n\tBinary Search" << "\x1B[m \n\t";
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


