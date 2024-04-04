#include <iostream>
#include "calculadora.h"
using namespace std;
Calculadora::Calculadora(){
    num1 = 0;
    num2 = 0;
    mod = 0;
}
void Calculadora::inverso_m(){

}
void Calculadora::suma(){
    res = num1 + num2;
}
void Calculadora::multi(){
    res = num1 * num2;
}
void Calculadora::print_res(){
    //res = res%mod;
    cout << "\x1B[96m" << "\n\tRespuesta: " << res << "\x1B[m" << endl;
}
/*

int Romanos::cal_centena(){
    return(num /100) % 10;
}
int Romanos::cal_millar(){
    return(num /1000) % 10;
} 
void Romanos::print_num(int cifra, int index_b, int index_u, int index_m){ //0-3999
    if (cifra >= 5) { //5-9
        index_m += 1;
        cifra -= 5;
    } else {
        index_b = 0;
    }
    if (cifra <= 3){ //0-3 (5-8)
        cout << simbolos[index_b];
        for (int i = 0; i < cifra; i++){
            cout << simbolos[index_u];
        }
    } else {//4 (9)
        cout << simbolos[index_u] << simbolos[index_m];
    }
}
void Romanos::print_num_ex(int cifra){ //millar 4-9  -> con multiplicacion
    if (cifra >= 5) { //5-9
        cifra -= 5;
    } else { //4
        cout << "__\n\t"
            << simbolos[1] << simbolos[2];
        cifra = 5;
    }
    if (cifra <= 3){ //0-3
        cout << "_\n\t" << simbolos[2];
        for (int i = 0; i < cifra; i++){
            cout << simbolos[7];
        }
    } else if (cifra == 4){ //4
        cout << "__\n\t"
            << simbolos[1] << simbolos[3];
    }
}*/