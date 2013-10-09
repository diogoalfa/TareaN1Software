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
    cout<<"-g = INFORMACION CREADORES "<<endl;
    cout<<"::INGRESE UNA OPCION::"<<endl;
    cin>>opcionString;
    
    if (opcionString=="-g") {
        opcion=1;
    }
    
    
    switch (opcion) {
        case 1:
            cout<<"hola"<<endl;
            break;
            
        default:
            break;
    }
    
    
    
    return 0;
}

