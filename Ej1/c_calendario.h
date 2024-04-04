#include <iostream>
using namespace std;

class Calendario {public:
    int dia_i;
    int duracion;
    int año;
    int mes;
    bool bisiesto;
    int dia_i_a;
    Calendario();
    bool cal_bisiesto();
    int long_mes(int vmes);
    void imp_cal();
    int cal_dia_i();
    int cal_dia_i_a();
};