/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * 
 * Author: Arian Gallardo 20153227
 */

#include <cmath>

void suma(double* A, double* B, double* X, int n){
    for(int i = 0 ; i < n ; i ++) *(X + i) = *(A + i) + *(B + i);
}

void prod_escalar(double s, double *A, double* X, int n){
    for(int i = 0 ; i < n ; i++) *(X + i) = s * ( *(A + i));
}

double modulo(double *A, int n){
    double ret = 0;
    for(int i = 0 ; i < n ; i ++) ret += (*(A + i))*( *(A + i));
    return sqrt(ret);
}

double producto_punto(double *A, double *B, int n){
    double ret = 0;
    for(int i = 0 ; i < n ; i ++) ret += (*(A + i)) * (*(B + i));
    return ret;
}