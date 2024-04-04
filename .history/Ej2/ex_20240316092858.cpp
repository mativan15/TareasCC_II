#include <iostream>
#include "romanos.h"
using namespace std;

void iniciar(){
    bool bucle{true};
    while (bucle){
        cout << "\x1B[31m" << "\n\n\tBienvenido, ingresa un número del 1-9999: " << "\x1B[m \n";
        int numero{0};
        Romanos rom1(numero);
        /*cin >> dia_i;
        cal1.dia_i = dia_i;
        cout << "\n\tingrese duracion" << "\n";
        cin >> duracion;
        cal1.duracion = duracion;*/
        cout << "\n\tingrese año" << "\n";
        cin >> año;
        cal1.año = año;
        cout << "\n\tIngrese mes" << "\n\t1.Enero 2.Febrero 3.Marzo 4.Abril \n\t5.Mayo 6.Junio 7.Julio 8.Agosto \n\t9.Setiembre 10.Octubre 11.Noviembre 12.Diciembre" << "\n\t";
        cin >> mes;
        cal1.mes = mes;
        cal1.imp_cal();
        int res;
        cout << "\n\tIngrese 1 para repetir" << "\n";
        cin >> res;
        //cal1.año = año;
        if (res != 1) {
            bucle = false;
            break;
        }

    }
}


