#include <iostream>
using namespace std;

class Romanos {
public:
    int num;
    int unidad;
    int decena;
    int centena;
    int millar;
    char[9] simbolos;
    Romanos(int num);
    void print_num();
    int cal_unidad();
    int cal_decena();
    int cal_centena();
    int cal_millar();
    void print_num(int cifra, int index_b, int index_u, int index_m);
    void print_num_ex(int cifra);
};