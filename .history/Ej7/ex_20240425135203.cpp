#include <iostream>
#include "multi.h"
#include "header.h"
using namespace std;
void inicio(){
    bool bucle{true};
    int res{0};
    do {
        MultiMatrix matriz1;
        cout << "\x1B[36m" << "\n\n\tBienvenido:" << "\x1B[m\n\t"
         << "\x1B[36m" << "\n\tMatrices Random" << "\x1B[m \n\t";
        matriz1.print();    
        matriz1.multiplicar();
        cout << "\n\n\tIngrese 1 para repetir" << "\n\t";
        cin >> res;
        if (res != 1) {
            bucle = false;
            break;
        } else {
            bucle = true;
        } 

    }while (bucle);
}


