#include <iostream>
#include "binary.h"
using namespace std;
Binary::Binary(){
    ptr_inicio = nullptr;
    ptr_fin = nullptr;
    repetir = true;
    ptr_medio = ptr_inicio + (sizeof(array)/8);
    pos = 0;
}
void Binary::asignar_array(int* array_ptr){
    for (int i = 0; i < sizeof(array)/4; i++){
        array[i] = array_ptr[i];
    }
    ptr_inicio = array;
    ptr_fin = array+(sizeof(array)/4)-1;
}
void Binary::print(){
    for (int i = 0; i < sizeof(array)/4; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}
bool Binary::busqueda_bin(){
    do{
        ptr_medio = ptr_inicio + ((ptr_fin-ptr_inicio)/2);
        cout << "buscandoo  " << buscar << endl << "ptr_medio  " << *ptr_medio << endl << "ptr_inicio   " << *ptr_inicio << endl << "ptr_fin  " << *ptr_fin << endl << "distancia   " << ptr_fin-ptr_inicio << endl << endl;
        if (*ptr_medio == buscar){
            cout << "encontradooo" << endl;
            repetir = false;
            return true;
        } else if (*ptr_medio > buscar){
            cout << "menorrr" << endl;
            ptr_fin = ptr_medio-1;
        } else {
            cout << "mayorrrr" << endl;
            ptr_inicio = ptr_medio+1;
        }
        if (!((ptr_fin-ptr_inicio) >= 0 && (ptr_fin-ptr_inicio) <= ((sizeof(array)/4)-1))) {
            cout << "condicion de pareee  distancia " << ptr_fin-ptr_inicio << endl;
            repetir = false;
            return false;
        } else repetir = true;
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
            var = 0;
            var = ptr_medio-array;
            cout << "\x1B[32m" << "\n\n\tSe encontró el número " << buscar << " en la posición " << var << "\x1B[m\n\t";
            cout << "\t";
            for (int i = 0; i < sizeof(array)/4; i++) {
                if (i==var) cout << "\x1B[36m" << array[i] << " "<< "\x1B[m";
                else cout << array[i] << " ";
            }
            cout << endl<<endl;
        } else cout << "\x1B[31m" << "\n\n\tNo se encontró el número " << buscar <<  " :(" << "\x1B[m\n\t";
    }
}