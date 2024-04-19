#include <iostream>
#include "cocktail.h"
#include "header.h"
#include "binary.h"
using namespace std;
bool comp_bin(int* arr_ptr){
    if (*(arr_ptr+9) == 0) {
        cout << "Error. El array no esta ordenado!" << "\n\t";
        return false;
    } else return true;
}
void inicio(){
    bool bucle, ordenado{true};
    int opcion{0};
    int res{0};
    Binary binary1;
    do {
        Cocktail cocktail_1;
        /*
        char* i, q;

        char C[3][100]={"hoawkjsjfh hj", "dnvhbjakjsdk", "fbjskabfhsdbjf"};
        void lowercase(char*i[100], char (*f)[100]){
            for (char(*p)[100] = i; p<=f ; p++) {
                for (char *q = *p ; *q ; q++){
                    if (*q >= 'A' && *q <= 'Z') *q += 32;
                }
            }
        }
        lowercase(C, C+2);
*/
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
                cout << "\x1B[31m"<< "\n\tArray random:  " << "\x1B[m\t";
                cocktail_1.print();
                cout << "\n\t";
                cocktail_1.ordenar();
                cout << "\x1B[32m" << "\n\tArray ordenado: " << "\x1B[m";
                cocktail_1.print();
                res = 1;
                break;
            default:
                cout << "\x1B[36m" << "\n\n\tBinary Search" << "\x1B[m \n\t";
                
                if (comp_bin(cocktail_1.array_ordenado)) binary1.asignar_array(cocktail_1.array_ordenado);
                binary1.print();
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


