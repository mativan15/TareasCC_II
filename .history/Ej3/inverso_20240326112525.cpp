#include <iostream>
#include "inverso.h"
using namespace std;
Inverso::Inverso(int V2, int V1){//v1 = mod   V2= num original
    this->V2 = V2;
    this->V1 = V1;
    Q = 0;//cociente
    R = 0;//residuo mod
    U0 = 0;
    U1 = 1;
    U2 = 0;
    res = 0;
}
int Inverso::inverso_m(){
    while (true){
        Q = V1/V2;
        R = V1%V2;
        cout << "\nDIVISION: V2: " << V2 << "V1: " << V1 << "R: " << R << "Q: " << Q << "U0: " << U0 << "U1: " << U1 << "U2: " << U2 << "res: " << res << endl;
        if (R == 0){
            return 0;
        } else if (R == 1) {
            return res;
            break;
        }
        U2 = U0-Q*U1;
        //pasar valores:
        V1 = V2;
        V2 = R;
        U0 = U1;
        U1 = U2;
        cout << "\nFINAL: V2: " << V2 << "V1: " << V1 << "R: " << R << "Q: " << Q << "U0: " << U0 << "U1: " << U1 << "U2: " << U2 << "res: " << res << endl;

    }
    //return res;
}