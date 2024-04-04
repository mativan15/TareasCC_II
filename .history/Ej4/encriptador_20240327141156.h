#include <iostream>
using namespace std;
class Encriptador{ public:
    int k_priv;
    int k_pub;
    char caracter;
    void* ptr;
    Encriptador();
    void encriptar();
    void desencriptar();
};