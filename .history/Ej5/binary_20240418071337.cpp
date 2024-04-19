#include <iostream>
#include "binary.h"
using namespace std;
Binary::Binary(int* array_ptr){
    for (int i = 0; i < 10; i++){
        array[i] = array_ptr[i];
    }
    
}