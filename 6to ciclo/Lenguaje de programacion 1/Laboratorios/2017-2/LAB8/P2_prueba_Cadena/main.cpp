/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 10 de noviembre de 2017, 09:40 AM
 */

#include <iostream>
#include <cstring>
#include "Cadena.h"

using namespace std;

#define N 100
#define M 200

void merge(Cadena *arr, int n, int l,int mid, int r){
    int u = l, v = mid+1;
    Cadena* aux = new Cadena[r - l + 1];
    int p = 0;
    while( u <= mid && v <= r){
        if(arr[u] < arr[v]){
            aux[p++] = arr[u++];
        }
        else{
            aux[p++] = arr[v++];
        }
    }
    while(u <= mid){
        aux[p++] = arr[u++];
    }
    while(v <= r){
        aux[p++] = arr[v++];
    }
    int z = 0;
    for(int i = l; i <= r; i ++) arr[i] = aux[z++];
}

void mergesort(Cadena *arr, int n, int l, int r){
    if(l >= r) return;
    int mid = (l + r)/2;
    mergesort(arr, n, l, mid);
    mergesort(arr,n,mid+1, r);
    merge(arr, n, l, mid, r);
}

int main() {
    char s[N];
    Cadena arr[M];
    int p = 0;
    char nomb[N];
    while(cin >> s){
        strcpy(nomb, s);
        while(!(cin.peek()== '\r' || cin.peek() == '\n')){
            strcat(nomb, " "); cin >> s;
            strcat(nomb, s);
        }
        Cadena x(nomb);
        arr[p++] = x;
    }
    mergesort(arr, p, 0, p-1);
    for(int i = 0 ; i < p ; i ++){
        arr[i].print();
    }
    return 0;
}

