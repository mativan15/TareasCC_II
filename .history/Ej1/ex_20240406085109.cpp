#include <iostream>
#include "c_calendario.h"
using namespace std;

void iniciar(){
    bool bucle{true};
    int dia_i{0};
    int duracion{0};
    int año{0};
    int mes{0};
    int res{0};
    Calendario cal1;
    do {
        cout << "\x1B[31m" << "\n\n\tBienvenido, ingrese año:" << "\x1B[m \n\t";
        cin >> año;
        if (cin.fail() || !(año >= 1 && año <= 9999)) {
            cout << "\nValor incorrecto!"; 
            cin.clear();           
            cin.ignore(100, '\n');
        } else {
            cal1.año = año;
            cout << "\x1B[31m" << "\n\tIngrese mes" << "\x1B[m " << "\n\t1.Enero \t2.Febrero \t3.Marzo \t4.Abril \n\t5.Mayo \t\t6.Junio \t7.Julio \t8.Agosto \n\t9.Setiembre \t10.Octubre \t11.Noviembre \t12.Diciembre" << "\n\t";
            cin >> mes;
            if (cin.fail() || !(mes >= 1 && mes <= 12)) {
                cout << "\nValor incorrecto!"; 
                cin.clear();           
                cin.ignore(100, '\n');
            } else {
                cal1.mes = mes;
                cal1.imp_cal();
            }
        }
        cout << "\n\tIngrese 1 para repetir" << "\n";
        cin >> res;
        if (res != 1) {
            bucle = false;
            break;
        }
    } while (bucle);
}


