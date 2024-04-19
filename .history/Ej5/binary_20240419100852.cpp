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
    for (int i = 0; i < 10; i++) {
        cout << array[i] << " ";
    }
    cout << endl<<endl;
}
bool Binary::busqueda_bin(){
    do {
        pos = ptr_inicio + ((ptr_fin-ptr_inicio)/2);
        cout << "pos  " << *pos << endl << "ptr_inicio   " << *ptr_inicio << endl << "ptr_fin  " << *ptr_fin << endl << "var   " << ptr_fin-ptr_inicio << endl;
        if (ptr_fin-ptr_inicio==0) {
            repetir = false;
            return false;
        }
        if (*pos == buscar){
            repetir = false;
            return true;
        } else if (*pos < buscar){
            ptr_fin = pos-1;
        } else {
            ptr_inicio = pos+1;
        }
    }while(repetir);
    
}
void Binary::ejecutar(){
    int var{0};
    cout << "\x1B[36m" << "\n\n\tIngresa el número que quieres buscar:" << "\x1B[m\n\t";
    cin >> var;
    if (cin.fail() || !(var >= 0 && var <= 100)) {
        cout << "\n\tValor incorrecto! Ingrese una opcion válida:\n"; 
        cin.clear();           
        cin.ignore(100, '\n');
    } else {
        buscar=var;
        if (busqueda_bin()){
            var = ptr_inicio-pos;
            cout << "\x1B[36m" << "\n\n\tSe encontró el número " << buscar << " en la posición " << var << "\x1B[m\n\t";
            cout << "\t";
            for (int i = 0; i < 10; i++) {
                if (i==var) cout << "\x1B[36m" << array[i] << " "<< "\x1B[m";
                else cout << array[i] << " ";
            }
            cout << endl<<endl;
        }
    }
}