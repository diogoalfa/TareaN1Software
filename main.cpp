//
//  main.cpp
//  TareaN1Software
//
//  Created by Diego Cristobal Navia Fuentes on 08-10-13.
//  Copyright (c) 2013 Diego Cristobal Navia Fuentes. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct vectorChar {
    char polinomio[20];
    int largo;
};

struct tipoPolinomio {
    int tipoPolinomio=0;
    int numPolinomio;
};

struct tipPolinomio {
    int tipoPolinomio;
};

int largoString(char polinimio[]){
    int largo=0;
    int i=0;
    while (polinimio[i]!='\0') {
        largo++;
        i++;
    }
    return largo;
}

void imprimirVectorStringSeparado(vectorChar polinomios[],int n){
    
    int largoPolinomio=0;

    for (int i=0; i<n; i++) {
        
        largoPolinomio=polinomios[i].largo;
        
        for (int j=0; j<largoPolinomio; j++) {
            cout<<polinomios[i].polinomio[j];
        }
        cout<<" + ";
    }
   cout<<endl;
}

void integrarConExponente(vectorChar polinomios[],int numPolinomio){
    
    int exponente=0;
    int largoPolinomio=0;
    int i=numPolinomio;
    
    largoPolinomio=polinomios[i].largo;
    
        for (int j=0; j<largoPolinomio; j++) {
            
            if (polinomios[i].polinomio[j]=='^') {
                exponente=polinomios[i].polinomio[j+1]-48;
                exponente++;
                polinomios[i].polinomio[j+1]='0'+exponente;
                polinomios[i].polinomio[j+2]='/';
                polinomios[i].polinomio[j+3]='0'+exponente;
            }
            
        }
    
    polinomios[i].largo=polinomios[i].largo+2;
    
}
void integrarSinExponente(vectorChar polinomios[],int numPolinomio){
    
    int largoPolinomio=0;
    int i=numPolinomio;
    
    largoPolinomio=polinomios[i].largo;
    
    for (int j=0; j<largoPolinomio; j++) {
        
        if (polinomios[i].polinomio[j]=='x') {
            polinomios[i].polinomio[j+1]='^';
            polinomios[i].polinomio[j+2]='2';
            polinomios[i].polinomio[j+3]='/';
            polinomios[i].polinomio[j+4]='2';
        }
        
    }
    polinomios[i].largo=polinomios[i].largo+4;

    
    
}
void integrarConstante(vectorChar polinomios[],int numPolinomio){
  
    int largoPolinomio=0;
    int i=numPolinomio;
    
    largoPolinomio=polinomios[i].largo;
  //  cout<<"Largo POl:"<<largoPolinomio<<endl;
    
     polinomios[i].polinomio[largoPolinomio]='x';

   // cout<<"Largo Polimonio :"<<polinomios[i].largo<<endl;
    polinomios[i].largo=polinomios[i].largo+1;
    
}


//
void integrarPolinomio(vectorChar polinomios[],int n){
    
    int largoPolinomio=0;
    //tipoPolinomio tipPol;
    tipPolinomio tipoPolinomio[n];
    
    //Comprueba Si ALGUN POLINOMIO tiene Exponente
    for (int i=0; i<n; i++) {
        largoPolinomio=polinomios[i].largo;
        for (int j=0; j<largoPolinomio; j++) {
            if (polinomios[i].polinomio[j]=='^') {
                tipoPolinomio[i].tipoPolinomio=1;
            }
            
        }
        
        
       
    }
    
    //Comprueba si ALGUN POLINOMIO eS Sin exponente EN X
    for (int i=0; i<n; i++) {
        largoPolinomio=polinomios[i].largo;
        for (int j=0; j<largoPolinomio; j++) {
            if (tipoPolinomio[i].tipoPolinomio!=1) {
                if (polinomios[i].polinomio[j]=='x') {
                    tipoPolinomio[i].tipoPolinomio=2;
                }
            }
            
            
        }
        
       
        
    }
    
    //Comprueba Que tipo de polinomio es y lo manda a INTEGRAR
    for (int i=0; i<n; i++) {
        if (tipoPolinomio[i].tipoPolinomio==1) {
            integrarConExponente(polinomios, i);
        }
        else{
            if (tipoPolinomio[i].tipoPolinomio==2) {
                 integrarSinExponente(polinomios,i);
            }
            else{
                integrarConstante(polinomios, i);
            }
        }
       
        
    }
    
    cout<<"INTEGRADO :"<<endl;
    imprimirVectorStringSeparado(polinomios, n);
    
}


//DESCOMPONE EL STRING INICIAL EL SUBSTRING .SEPARADOS POR EL MAS .CREA POLINOMIOS MAS PEQUEÑOS
void descomponerPolinomio(char polinomio[]){
 
    int j=0,k=0;
    vectorChar polAux[20];
    //cout<<"Largo Polinomio :"<<largoString(polinomio)<<endl;
    for (int i=0; i<largoString(polinomio); i++) {
        if (polinomio[i]!='+') {
            polAux[j].polinomio[k]=polinomio[i];
            k++;
            polAux[j].largo=k;
        }
        else{
            j++;
            k=0;
        }
    }
    imprimirVectorStringSeparado(polAux,j);
    integrarPolinomio(polAux, j);
}



int main(int argc, const char * argv[])
{
    string opcionString;
    int opcion = 0;
    char polinomio[100];
    int opcionDoWhile=0;
do {
    
    cout<<"OPCIONES : "<<endl;
    cout<<"-i = INTEGRAL DEL UN POLINOMIO "<<endl;
    cout<<"-g = GRAFICA BAJO DE CURVA DEL POLINOMIO "<<endl;
    cout<<"-v = INFORMACION CREADORES "<<endl;
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
                
                cout<<"Ingrese un polinomio"<<endl;
                cin>>polinomio;
                cout<<endl;
                descomponerPolinomio(polinomio);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                cout<<"INGRESE OPCION CORRECTA"<<endl;
                opcionDoWhile=0;
                break;
            case 5:
                cout<<"ADIOS :D "<<endl;
                opcionDoWhile=1;
                
            default:
                break;
        }
} while (opcionDoWhile==0);
    
    
    
    
    return 0;
}

