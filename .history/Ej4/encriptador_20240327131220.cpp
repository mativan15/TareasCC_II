#include <iostream>
#include "encriptador.h"
#include "inverso.h"
using namespace std;
Encriptador::Encriptador(){
    k_pub = 0;
    k_priv = 0;
}
void Encriptador::encriptar(){
    Inverso inv1(k_pub, 256);
}
void Encriptador::desencriptar(){

}