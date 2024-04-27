#include <iostream>
#include "multi.h"
#include "header.h"
#include "binary.h"
using namespace std;
void inicio(){
    bool bucle{true};
    int opcion{0};
    int res{0};
    int array_temp[20];
    Binary binary1;
    do {
        MultiMatrix matriz1;
        cout << "\x1B[36m" << "\n\n\tBienvenido:" << "\x1B[m\n\t"
         << "\x1B[36m" << "\n\tMatrices Random" << "\x1B[m \n\t";
        matriz1.print();    
        
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


