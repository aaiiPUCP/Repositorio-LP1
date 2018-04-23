/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * 
 * Author: Arian Gallardo 20153227
 */

double elem(int n, int fil, int col, double* A){
    return *(A + fil*n + col);
}

void suma(int n, double* A, double* B, double* X){
    for(int i = 0 ; i < n*n; i++) *(X + i) = *(A + i) + *(B + i);
}

void prod_escalar(int n, double s, double* A, double* X){
    for(int i = 0 ; i < n*n; i++) *(X + i) = (*(A + i)) * s;
}

double trace(int n, double* A){
    double ret = 0;
    for(int i = 0 ; i < n; i ++) ret += *(A + i*(n + 1));
    return ret;
}
