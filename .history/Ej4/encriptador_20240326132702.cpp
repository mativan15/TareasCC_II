#include <iostream>
#include "encriptador.h"
using namespace std;
Encriptador::Encriptador(int V2, int V1){//v1 = mod   V2= num original
    this->V2 = V2;
    this->V1 = V1;
    Q = 0;//cociente
    R = 0;//residuo mod
    U0 = 0;
    U1 = 1;
    U2 = 0;
    res = 0;
}
void Encriptador::encriptar(){

}
void Encriptador::desencriptar(){

}