#include <iostream>
#include <array>
#include <string>
#include "romanos.h"
using namespace std;

Romanos::Romanos(int num){
    this->num = num;
    unidad = cal_unidad();
    decena = cal_decena();
    centena = cal_centena();
    millar = cal_millar();
    simbolos[0] = '\0';//, 'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    simbolos[1] = 'I';
    simbolos[2] = 'V';
    simbolos[3] = 'X';
    simbolos[4] = 'L';
    simbolos[5] = 'C';
    simbolos[6] = 'D';
    simbolos[7] = 'M';
    simbolos[8] = '\0';
}
void Romanos::print_num(){
    cout << "\x1B[96m" << "\n\t";

    if (millar >= 4){
        print_num_ex(millar);
    } else {
        print_num(millar, 0,7,0);
        //cout << "\n";
    }
    print_num(centena, 6,5,6);
    print_num(decena, 4,3,4);
    print_num(unidad, 2,1,2);
    cout << "\x1B[m";
}
int Romanos::cal_unidad(){
    return num % 10;
}
int Romanos::cal_decena(){
    return(num /10) % 10;
}
int Romanos::cal_centena(){
    return(num /100) % 10;
}
int Romanos::cal_millar(){
    return(num /1000) % 10;
} 
void Romanos::print_num(int cifra, int index_b, int index_u, int index_m){
    if (cifra >= 5) { //5-9
        index_m += 1;
        cifra -= 5;
    } else {
        index_b = 0;
    }
    if (cifra <= 3){ //0-3 (5-8)
        cout << "\x1B[96m" << simbolos[index_b];
        for (int i = 0; i < cifra; i++){
            cout << simbolos[index_u];
        }
    } else {//4 (9)
        cout << "\x1B[96m" << simbolos[index_u] << simbolos[index_m];
    }
}

void Romanos::print_num_ex(int cifra){ //millar 4-9
    if (cifra >= 5) { //5-9
        cifra -= 5;
    } else { //4
        cout << "\x1B[78m" << "__\n\t"
            << simbolos[1] << simbolos[2];
        cifra = 5;
    }
    if (cifra <= 3){ //0-3
        cout << "\x1B[78m" << "_\n\t" << simbolos[2];
        for (int i = 0; i < cifra; i++){
            cout << simbolos[7];
        }
    } else if (cifra == 4){ //4
        cout << "\x1B[78m" << "__\n\t"
            << simbolos[1] << simbolos[3];
    }
}