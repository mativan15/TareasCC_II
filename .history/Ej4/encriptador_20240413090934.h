#include <iostream>
#include <string>
using namespace std;
class Encriptador{ public:
    int k_priv;
    int k_pub;
    char caracter;
    int ascii;
    string textoo1, textoo2;
    Encriptador();
    void encriptar();
    void desencriptar(int c_priv);
};