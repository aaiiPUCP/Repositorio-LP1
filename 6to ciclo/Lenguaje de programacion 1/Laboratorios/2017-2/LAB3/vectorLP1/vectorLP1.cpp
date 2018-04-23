/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * Author : Arian Gabriel Gallardo Callalli 20153227
 */

#include <cmath>

void suma(double *A, double *B, double *X, int numDim){
    for(int i = 0 ; i < numDim; i++) X[i] = A[i] + B[i];
}

void resta(double *A, double *B, double *X, int numDim){
    for(int i = 0 ; i < numDim; i++) X[i] = A[i] - B[i];
} 

void prod_escalar(double s, double *A, double *X, int numDim){
    for(int i = 0 ; i < numDim; i ++) X[i] = A[i]*s;
}

double modulo (double *A, int numDim){
    double ret = 0;
    for(int i = 0 ; i < numDim; i++) ret += A[i] * A[i];
    return sqrt(ret);
}

void vector_unitario(double *A, double *X, int numDim){
    double mod = modulo(A, numDim);
    for(int i = 0 ; i < numDim; i++) X[i] = A[i]*1.0 / mod;
}

double producto_punto(double *A, double *B, int numDim){
    double ret = 0;
    for(int i = 0 ; i < numDim; i ++) ret += A[i]* B[i];
    return ret;
}

double coseno_angulo(double *A, double *B, int numDim){
    return producto_punto(A,B, numDim)/ (modulo(A, numDim) * modulo(B, numDim));
}

void proyeccion (double *A, double *B, double *X, int numDim){
    vector_unitario(B, X, numDim); //El ub se guarda en X
    prod_escalar(producto_punto(A,B,numDim)/ modulo(B,numDim), X, X, numDim); //El resultado final se guarda en X
}

//4 sobrecargas 

void suma(double a1 , double a2, double b1, double b2, double &x1, double &x2){
    x1 = a1 + b1; x2 = a2 + b2;
}

void resta(double a1 , double a2, double b1, double b2, double &x1, double &x2){
    x1 = a1 - b1; x2 = a2 - b2;
}

void prod_escalar(double s, double a1, double a2, double &x1, double &x2){
    x1 = a1*s; x2 = a2*s;
}

double modulo(double a1, double a2){
    return sqrt(a1 * a1 + a2*a2);
}