#include <iostream>
using namespace std;

class Romanos {
public:
    int unidad;
    int decena;
    int centena;
    int millar;
    Romanos(int num);
    void print_num();
    int cal_unidad();
    int cal_decena();
    int cal_centena();
    int cal_millar();
};