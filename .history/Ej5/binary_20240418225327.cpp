#include <iostream>
#include "binary.h"
using namespace std;
Binary::Binary(){
    ptr_inicio = nullptr;
    ptr_fin = nullptr;
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
    if (*pos == buscar){

    }
}