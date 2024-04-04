#include <iostream>
using namespace std;

class Inverso {
public:
    int V1;
    int V2;
    int Q;
    int R;
    int U0;
    int U1;
    int U2;
    int res;
    int mod;
    Inverso(int V2, int mod);
    void inverso_m();
    void suma();
    void multi();
    void print_res();
};