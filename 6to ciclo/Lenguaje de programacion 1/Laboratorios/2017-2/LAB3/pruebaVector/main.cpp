/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Arian Gallardo 20153227
 *
 * Created on 15 de septiembre de 2017, 08:47 AM
 */

#include <iostream>
#include <iomanip>
#include "vectorLP1.h"

using namespace std;


int main(){
    const int N = 5;
    double A[N], B[N];
    cout <<"Ingrese " << N << " valores para el vector A: ";
    for(int i = 0 ; i < N; i ++) cin >> A[i];
    cout <<"Ingrese " << N << " valores para el vector B: ";
    for(int i = 0 ; i < N; i ++) cin >> B[i];
    
    //Pruebas
    
    double X[N];
    suma(A,B,X,N);
    cout << "Suma: ";
    for(int i = 0; i < N ; i ++) cout << fixed << setprecision(3) << X[i] << " ";
    cout << endl;
    resta(A,B,X,N);
    cout << "Resta: ";
    for(int i = 0; i < N ; i ++) cout << fixed << setprecision(3) << X[i] << " ";
    cout << endl;
    
    double esc;
    cout << "Ingrese un valor escalar: ";
    cin >> esc;
    cout <<"Producto escalar de " << setprecision(3) << esc << " y A: ";
    prod_escalar(esc,A,X,N);
    for(int i = 0 ; i < N ;i ++) cout << fixed << setprecision(3) << X[i] << " ";
    cout << endl;
    
    vector_unitario(A,X,N);
    cout << "El vector unitario de A es: ";
    for(int i = 0 ; i < N; i++) cout << fixed << setprecision(3) << X[i] << " ";
    cout << endl;
    
    cout << "El producto punto de A y B es: ";
    cout << fixed << setprecision(3) << producto_punto(A,B, N) << endl;
    cout << endl;
    
    cout << "El coseno del angulo entre A y B es: ";
    cout << fixed << setprecision(3) << coseno_angulo(A,B,N) << endl;
    
    proyeccion(A,B,X,N);
    
    cout << "La proyeccion de A sobre B es: ";
    for(int i = 0 ; i < N; i ++) cout << fixed << setprecision(3) << X[i] << " ";
    cout << endl;
    
    cout << endl;
    
    cout << "Prueba de funciones sobrecargadas" << endl;
    cout << endl;
    
    double ax,ay,bx,by, rx, ry;
    cout << "Ingrese dos vectores de dos dimensiones (ax, ay, bx, by): ";
    cin >> ax >> ay >> bx >> by;
    suma(ax,ay,bx,by,rx,ry);
    cout << "La suma es: " << fixed << setprecision(3) << rx << " " << ry << endl;
    resta(ax,ay,bx,by,rx,ry);
    cout << "La resta es: " << fixed << setprecision(3) << rx << " " << ry << endl;
    cout <<"Ingrese un escalar: ";
    cin >> esc;
    prod_escalar(esc, ax, ay, rx, ry);
    cout << "El producto escalar de "<< fixed << setprecision(3) << esc << " y A es : " << rx << " " << ry << endl;
    
    cout << fixed << setprecision(3) << "El modulo de A es: " << modulo(ax,ay) << endl;
    cout << endl;
    return 0;
}

