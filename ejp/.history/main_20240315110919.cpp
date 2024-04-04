#include <iostream>
#include <array>
#include <string>
using namespace std;
// en los numeros romanos no se puede repetir un simbolo mÃ¡s de 3 veces seguidas
// Por lo tanto se aÃ±ade una linea encima del numero romano, indicando que el numero se multiplica por 1000
// 3999 -> MMMCMXCIX
// 50->L ; 100->C; 500->D; 1000->M
//390 -> CCXC
//400 -> CD
//440 -> CDXL


void try1(int n){
    array <string, 10> unidades = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X"};

    switch(n){
        case 1:
            cout<<unidades[0];
            break;
        case 2:
            cout<<unidades[1];
            break;
        case 3:
            cout<<unidades[2];
            break;
        case 4:
            cout<<unidades[3];
            break;
        case 5:
            cout<<unidades[4];
            break;
        case 6:
            cout<<unidades[5];
            break;
        case 7:
            cout<<unidades[6];
            break;
        case 8:
            cout<<unidades[7];
            break;
        case 9:
            cout<<unidades[8];
            break;
        case 10:
            cout<<unidades[9];
            break;
        default:
            break;
    }
}

void try2(int n){
    array <string, 7> basics = {"I", "V", "X", "L", "C", "D", "M"};

     switch(n){
        case 1:
            cout<<basics[0];
            break;
        case 2:
            cout<<basics[0]+basics[0];
            break;
        case 3:
            cout<<basics[0]+basics[0]+basics[0];
            break;
        case 4:
            cout<<basics[0]+basics[1];
            break;
        case 5:
            cout<<basics[1];
            break;
        case 6:
            cout<<basics[1]+basics[0];
            break;
        case 7:
            cout<<basics[1]+basics[0]+basics[0];
            break;
        case 8:
            cout<<basics[1]+basics[0]+basics[0]+basics[0];
            break;
        case 9:
            cout<<basics[0]+basics[2];
            break;
        case 10:
            cout<<basics[2];
            break;
        default:
            break;
    }
}

void try3(int n){
    array <string, 7> basics = {"I", "V", "X", "L", "C", "D", "M"};
    array <int, 7> basicsN= {1,5,10,50,100,500,1000};
    if (n==0){
        return;
    }
    for (int i=0; i<7;i++){
        if (basicsN[i]==n){
            cout<< basics[i];
            return;
        }
        else if (basicsN[i]==n+1){
            cout<<basics[0]+basics[i];
            return;
        }
    }

    if (n<4){
        for(int j=0; j<n;j++){
            cout<<basics[0];
        }
        return;
    }
    else if(n>5){
        cout<<basics[1];
        for(int k=0; k<n-5;k++){
            cout<<basics[0];
        }
        return;
    }
   
}

void try4(int n){
    array <string, 7> basics = {"I","V","X", "L", "C", "D", "M"};
    array <int, 7> basicsN= {1,5,10,50,100,500,1000};


    if (n==0){
        return;
    }
    for (int i=0; i<7;i++){
        if (basicsN[i]==n*10){
            cout<< basics[i];
            return;
        }
        else if (basicsN[i]==(n*10)+10){
            cout<<basics[2]+basics[i];
            return;
        }
    }

    if (n<4){
        for(int j=0; j<n;j++){
            cout<<basics[2];
        }
        return;
    }
    else if(n>5){
        cout<<basics[3];
        for(int k=0; k<n-5;k++){
            cout<<basics[2];
        }
        return;
    }
   
}

void try5(int n){
    array <string, 7> basics = {"I","V","X", "L", "C", "D", "M"};
    array <int, 7> basicsN= {1,5,10,50,100,500,1000};


    if (n==0){
        return;
    }
    for (int i=0; i<7;i++){
        if (basicsN[i]==n*100){
            cout<< basics[i];
            return;
        }
        else if (basicsN[i]==(n*100)+100){
            cout<<basics[4]+basics[i];
            return;
        }
    }

    if (n<4){
        for(int j=0; j<n;j++){
            cout<<basics[4];
        }
        return;
    }
    else if(n>5){
        cout<<basics[5];
        for(int k=0; k<n-5;k++){
            cout<<basics[4];
        }
        return;
    }
   
}

int main(){
    int year;
    cout<<"ingrese un año: ";
    cin>>year;
  

    int n=1;
    while(year>0){
        switch (n){
        case 1:
            try3(year%10);
            year=year/10;
            n++;
            break;
        case 2:
            try4(year%10);
            year=year/10;
            n++;
            break;
        case 3:
            try5(year%10);
            year=year/10;
            n++;
            break;
        default:
            break;
        }

    }


    
    array <string,5> decenas = {"X","L","C","D","M"};


   

};