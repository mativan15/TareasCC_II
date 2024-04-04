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
    if (millar >= 4){
        print_num_ex(millar, 0,7,0);
    } else {
        print_num(millar, 0,7,0);
    }
    cout << "    ";
    print_num(centena, 6,5,6);
    cout << "    ";
    print_num(decena, 4,3,4);
    cout << "    ";
    print_num(unidad, 2,1,2);
    //print_num(millar, 0,1,2);
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
    char simbolos[8] = {'\0', 'I', 'V', 'X', 'L', 'C', 'D', 'M'};

    if (cifra >= 5) {
        //index_b += 2;
        index_m += 1;
        cifra -= 5;
    } else {
        index_b = 0;
    }
    if (cifra <= 3){
        cout << simbolos[index_b];
        for (int i = 0; i < cifra; i++){
            cout << simbolos[index_u];
        }
    } else {
        cout << simbolos[index_u] << simbolos[index_m];
    }
}
void Romanos::print_num_ex(int cifra, int index_b, int index_u, int index_m){

}