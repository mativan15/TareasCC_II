#include <iostream>
#include "binary.h"
using namespace std;
Binary::Binary(){
    ptr_inicio = nullptr;
    ptr_fin = nullptr;
    repetir = true;
    pos = ptr_inicio + (sizeof(array)/2);
}
void Binary::asignar_array(int* array_ptr){
    for (int i = 0; i < 10; i++){
        array[i] = array_ptr[i];
    }
    ptr_inicio = array;
    ptr_fin = array+9;
}
void Binary::print(){
    cout << "\t";
    for (int i = 0; i < 10; i++) {
        cout << array[i] << " ";
    }
    cout << endl<<endl;
}
bool Binary::busqueda_bin(){
    do {
        pos = ptr_inicio + ((ptr_fin-ptr_inicio)/2);
        if (ptr_fin-ptr_inicio==1) return false;
        cout << "pos" << *pos << endl << "ptr_inicio" << *ptr_inicio << endl << "ptr_fin" << *ptr_fin << endl;
        if (*pos == buscar){
            return true;
        } else if (*pos < buscar){
            ptr_fin = pos-1;
        } else {
            ptr_inicio = pos+1;
        }
    }while(repetir);
}