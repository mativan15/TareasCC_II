#include <iostream>
using namespace std;
class Encriptador{ public:
    int k_priv;
    int k_pub;
    char caracter;
    int ascii;
    Encriptador();
    void encriptar();
    void desencriptar(int c_priv);
};