//
//  main.cpp
//  TareaN1Software
//
//  Created by Diego Cristobal Navia Fuentes on 08-10-13.
//  Copyright (c) 2013 Diego Cristobal Navia Fuentes. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    string opcionString;
    int opcion = 0;

    cout<<"OPCIONES : "<<endl;
    cout<<"-i = INTEGRAL DEL UN POLINOMIO "<<endl;
    cout<<"-v = GRAFICA BAJO DE CURVA DEL POLINOMIO "<<endl;
    cout<<"-g = INFORMACION CREADORES "<<endl;
    cout<<"::INGRESE UNA OPCION::"<<endl<<endl;
    cin>>opcionString;
    
    if (opcionString=="-i") {
        opcion=1;
    }
    else{
        
        if (opcionString=="-v") {
            opcion=2;
        }
        else{
            if (opcionString=="-g") {
                opcion=3;
            }
            else{
                opcion=4;
            }
        }
    }
    
    
    switch (opcion) {
        case 1:
            cout<<"hola"<<endl;
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            cout<<"INGRESE OPCION CORRECTA"<<endl;
            break;
        default:
            break;
    }
    
    
    
    return 0;
}

