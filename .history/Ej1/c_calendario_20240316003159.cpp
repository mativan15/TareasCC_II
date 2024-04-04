#include <iostream>

#include "c_calendario.h"

using namespace std;

Calendario::Calendario(){
    dia_i = 0;
    duracion = 0;
    año = 0;
    mes = 0;
    bisiesto = false;
    dia_i_a = 0;//temporal, lunes de 2024
}
bool Calendario::cal_bisiesto(){
    if (año%4==0){
        if (año%100==0){
            if (año%400==0){
                return true;
            }
            return false;
        }
        return true;
    } else {
        return false;
    }
    
}

int Calendario::long_mes(int vmes){
    if (vmes==1 || vmes==3 || vmes==5 || vmes== 7 || vmes==8 || vmes==10 || vmes==12){
        return 31;
    } else if (vmes==2){
        if (bisiesto){
            return 29;
        } else {
            return 28;
        }
    } else {
        return 30;
    }
}
int Calendario::cal_dia_i(){
    int conteo {0};
    int temp_mes {0};
    for (int i=1; i<mes; i++){
        temp_mes = long_mes(i);
        cout << "\ndias del mes" << temp_mes << endl;
        conteo += temp_mes;
        cout << "\nconteo" << conteo << endl;

    }
    return conteo%7;
}

int Calendario::cal_dia_i_a(){
    int desfase {0};
    int extra {0};
    if (año <= 2024) {
        desfase = año-2024;
        extra = desfase /4;
        
        cout << "\ndesfase" << desfase << endl;
        cout << "\nextra" << extra << endl;

        return (7+(desfase+extra)%7)%7;
    } else {
        /*if (desfase>=1 && desfase<=3){
            desfase += 1;
        }*/
        
        desfase = (año-2025);
        extra = desfase /4;
        desfase += 2;
        cout << "\ndesfase" << desfase << endl;
        cout << "\nextra" << extra << endl;

        return (desfase+extra)%7;
    }
}

void Calendario::imp_cal(){
    bisiesto = cal_bisiesto();
    duracion = long_mes(mes);
    dia_i = cal_dia_i();
    dia_i_a = cal_dia_i_a();
    dia_i += dia_i_a;
    /*cout << "\ndia_i_a" << dia_i_a << endl;
    cout << "\ndia_i" << dia_i << endl;*/
    dia_i = dia_i%7;
    //cout << duracion << endl;
    cout << "\x1B[31m" << "\n\n\tLu\tMa\tMi\tJu\tVi\tSa\tDo" << "\x1B[m \n";
    int pos{0};
    for (;pos < dia_i; pos++){
        cout << "\t";
    }
    int i{0};
    while (i < duracion) {
        if (pos % 7 == 0){
            cout << "\n";
        }
        i++;
        pos++;
        cout << "\t" << i; // << " " << pos % 7;

    }
    /*
    for (int i = 0; i < duracion; i++){
        cout << "\t" << i;
    }*/
    
    cout << "\n";

}