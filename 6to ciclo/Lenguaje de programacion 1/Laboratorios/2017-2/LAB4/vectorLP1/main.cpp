/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Arian Gallardo 20153227
 *
 * Created on 22 de septiembre de 2017, 08:13 AM
 */

#include <iostream>
#include <iomanip>
#include "vectorLP1.h"

using namespace std;

/*
 * 
 */
int main() {
    int n;
    cout << "Ingrese el tamanho de los vectores: ";
    cin >> n;
    double* A = new double[n];
    double* B = new double[n];
    double* X = new double[n];
    
    cout << "Ingrese los " << n << " valores del vector A: ";
    for(int i = 0 ; i < n ; i ++) cin >> *(A + i);
    
    cout << "Ingrese los " << n << " valores del vector B: ";
    for(int i = 0 ; i < n ; i ++) cin >> *(B + i);
    
    suma(A,B,X,n);
    cout << "La suma de los vectores es: <";
    for(int i = 0 ; i < n ; i ++) cout << fixed << setprecision(3) << setw(10) << *(X + i);
    cout << ">" << endl;
    double esc;
    cout << "Ingrese un numero escalar: ";
    cin >> esc;
    prod_escalar(esc,A,X,n);
    cout << "El producto escalar de ";
    cout << fixed << setprecision(3) << esc;
    cout << " y A es: <";
    for(int i = 0 ; i < n ; i ++) cout << fixed << setprecision(3) << setw(10) << *(X + i);
    cout << ">" << endl;
    cout << "El modulo del vector A es: ";
    cout << fixed << setprecision(3) << modulo(A,n) << endl;
    cout << "El producto punto de A y B es: ";
    cout << fixed << setprecision(3) << setw(10) << producto_punto(A,B,n) << endl; 
    return 0;
}

