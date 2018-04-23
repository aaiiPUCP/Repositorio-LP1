/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Arian Gallardo 20153227
 *
 * Created on 22 de septiembre de 2017, 08:55 AM
 */

#include <iostream>
#include <iomanip>
#include "matrizLP1.h"
#include "vectorLP1.h"
#include "auxiliar.h"
#include <cmath>

using namespace std;

/*
 * 
 */

//n indica el numero de elementos en el arreglo y sizeA indica el tamanho total del arreglo

int main() {
    char c;
    while( cin >> c){
        char op; cin >> op;
        if(op == 's'){
            double *A, *B, *aux;
            double u;
            int naux = 0, sizeaux = 0;
            int nA = 0, sizeA = 0;
            int nB = 0, sizeB = 0;
            while(cin >> u){
                push(aux, u, naux, sizeaux);
            }
            cin.clear();
            for(int i = 0; i < naux; i++){
                if(i < sizeaux/2) push(A, *(aux + i), nA, sizeA);
                else push(B, *(aux + i), nB, sizeB);
            }
            delete []aux;
            double *X = new double[nA];
            if(c == 'v'){
                suma(A,B,X,nA);
                cout << "Vector<" << sizeA << ">: ";
                cout << "   Suma: = <";
                for(int i = 0; i < nA; i++) cout << fixed << setprecision(2) << setw(6) << *(X + i);
                cout << ">" << endl;
            }
            else{
                suma(sqrt(nA),A,B,X);
                cout << "Matriz<" << (int)sqrt(nA) << "x" << (int)sqrt(nA) << ">: Suma = <";
                for(int i = 0; i < (int)sqrt(nA); i++){
                    for(int j = 0; j < (int)sqrt(nA); j++){
                        cout << fixed << setprecision(2) << setw(6) <<  *(X + i*((int)sqrt(nA)) + j);
                    }
                    if(i != (int)sqrt(nA) -1) cout << " | ";
                }
                cout << ">" << endl;
            }
        }
        else{
            double esc; cin >> esc;
            double *A;
            int nA = 0, sizeA = 0;
            double u;
            while(cin >> u){
                push(A, u, nA, sizeA);
            }
            cin.clear();
            double *X = new double[nA];
            if(c == 'v'){
                prod_escalar(esc, A, X, nA);
                cout << "Vector< " << sizeA << ">: ";
                cout << "   Prod: = <";
                for(int i = 0; i < nA; i++) cout << fixed << setprecision(2) << setw(6) << *(X + i);
                cout << ">" << endl;
            }
            else{
                prod_escalar(sqrt(nA),esc, A, X);
                cout << "Matriz<" << (int)sqrt(nA) << "x" << (int)sqrt(nA) << ">: Prod = <";
                for(int i = 0; i < (int)sqrt(nA); i++){
                    for(int j = 0; j < (int)sqrt(nA); j++){
                        cout << fixed << setprecision(2) << setw(6) << *(X + i*((int)sqrt(nA)) + j);
                    }
                    if(i != (int)sqrt(nA) -1) cout << " | ";
                }
                cout << ">" << endl;
            }
        }
    }
    return 0;
}

