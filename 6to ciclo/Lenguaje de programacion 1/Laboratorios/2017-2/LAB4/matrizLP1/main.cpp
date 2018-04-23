/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Arian Gallardo 20153227
 *
 * Created on 22 de septiembre de 2017, 08:30 AM
 */

#include <iostream>
#include <iomanip>
#include "matrizLP1.h"

using namespace std;

/*
 * 
 */
int main() {
    int n;
    cout << "Ingrese el numero de filas/columnas de la matriz cuadrada: ";
    cin >> n;
    double* A = new double[n*n];
    double* B = new double[n*n];
    double* X = new double[n*n];
    
    cout << "Datos para la primera matriz" << endl;
    cout << endl;
    for(int i = 0 ; i < n; i ++){
        cout << "Ingrese " << n << " elementos para la fila " << i+1 << ": ";
        for(int j = 0; j < n ; j++){
            cin >> *(A + i*n + j);
        }
    }
    cout << endl;
    
    cout << "Datos para la segunda matriz" << endl;
    cout << endl;
    for(int i = 0 ; i < n; i ++){
        cout << "Ingrese " << n << " elementos para la fila " << i+1 << ": ";
        for(int j = 0; j < n ; j++){
            cin >> *(B + i*n + j);
        }
    }
    cout << endl;
    
    int fil, col;
    cout << "Ingrese una posicion en la matriz (fila, columna), 0-based: ";
    cin >> fil >> col;
    cout << "El elemento en la posicion (" << fil << "," << col << ")" << " de la primera matriz es: " << setprecision(3) << elem(n,fil,col,A) << endl;
    
    suma(n,A,B,X);
    
    cout << "La suma de las matrices es:" << endl;
    cout << "< ";
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n ; j ++) cout << fixed << setprecision(2) << setw(6) << *(X + i*n + j);
        if(i != n-1) cout << " | ";
        else cout << " >";
    }
    cout << endl;
    
    double esc;
    cout << "Ingrese un escalar: ";
    cin >> esc;
    
    prod_escalar(n,esc,A,X);
    cout << "El producto escalar de " << setprecision(3) << esc << " y A es: " << endl;
    cout << "< ";
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n ; j ++) cout << fixed << setprecision(2) << setw(6) << *(X + i*n + j);
        if(i != n-1) cout << " | ";
        else cout << " >";
    }
    cout << endl;
    
    cout << "La traza de A es: " << setprecision(2) << trace(n,A) << endl;
    
    return 0;
}

