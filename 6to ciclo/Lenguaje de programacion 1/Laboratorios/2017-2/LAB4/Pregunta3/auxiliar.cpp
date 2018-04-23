/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * 
 * Arian Gallardo 20153227
 */

#define INC 5

void incrementar(double* &A,int &n, int &size){
    if(n == 0){
        A = new double[INC];
    }
    else{
        double *aux = new double[size + INC];
        for(int i = 0 ; i < n ; i ++) *(aux + i) = *(A + i);
        delete []A;
        A = aux;
    }
    size += INC;
}

void push(double* &A, double x, int &n, int &size){
    if(n == size){
        incrementar(A,n,size);
    }
    *(A + n++) = x;
}