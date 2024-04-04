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
}
void Romanos::print_num(){
    cout << "numeroo  " << millar << "   "<< centena << "   "<< decena << "   ";
    print_unidad();
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
void Romanos::print_unidad(){
    char simbolos[4] = {'\0', 'I', 'V', 'X'};
    int index_b {0};
    int index_u {1};
    int index_m {2};
    if (unidad >= 5) {
        index_b += 2;
        index_m += 1;
        unidad -= 5;
    }
    if (unidad <= 3){
        cout << simbolos[index_b];
        for (int i = 0; i < unidad; i++){
            cout << simbolos[index_u];
        }
    } else {
        cout << simbolos[index_u] << simbolos[index_m];
    }
}