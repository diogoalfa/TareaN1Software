//
// main.cpp
// TareaN1Software
//
// Created by Diego Cristobal Navia Fuentes on 08-10-13.
// Copyright (c) 2013 Diego Cristobal Navia Fuentes. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct vectorChar {
    char polinomio[20];
    int largo;
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
  // cout<<"Largo POl:"<<largoPolinomio<<endl;
    
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
    int esta=0;
   for (int i = 0; i < argc ; i++ ) 
   {
        if (strcmp(argv[i],"-i")==0) { //si es 0 es por que son iguales
            opcion=1;
            
        }  
        if(strcmp(argv[i],"-v")==0) {
                opcion=2;
              
            }
         if(strcmp(argv[i],"-g")==0) {
                    opcion=3;
                    
                }       
    }
    if (opcion==0)//si no cambio la opcion se le asigna 4
    {
       opcion=4;
    }
    
        strcpy( polinomio, argv[2] );
    
        switch (opcion) {
            case 1:
                cout<<endl;
                descomponerPolinomio(polinomio);          
                break;
            case 2:
                cout<<"Datos integrantes"<<endl;
                break;
            case 3:
                 cout<<"PNG"<<endl;
                 break;
            case 4:
                cout<<"INGRESE OPCION CORRECTA"<<endl;
                break;
                        }
    
    return 0;
}
