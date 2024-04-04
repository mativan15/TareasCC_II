#include <iostream>
#include "inverso.h"
using namespace std;
Inverso::Inverso(int V2, int V1){//v1 = mod   V2= num original
    this->V2 = V2;
    this->V1 = V1;
    Q = 0;
    R = 0;
    U0 = 0;
    U1 = 0;
    U2 = 0;
    res = 0;
}
int Inverso::inverso_m(){

    return res;
}