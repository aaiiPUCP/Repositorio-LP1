/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * Author: Arian Gabriel Gallardo Callalli 20153227
 *  */

#include <iostream>
#include <cstring>

using namespace std;

#define inc 5

void imprimeOrdenado(char **datos, int *indices, char **indicador){
    int p = indicador - &datos[0];
    while(p != -1){
        cout << datos[p] << endl;
        p = indices[p];
    }
}

void incrementar(char **&datos, int *&indices, int &n, int &size){
    if(n == 0){
        datos = new char*[inc];
        indices = new int[inc];
    }
    else{
        int *auxind = new int[inc + n];
        char **auxdatos = new char*[inc+n];
        for(int i = 0 ; i < n ; i++){
            auxind[i] = indices[i];
            auxdatos[i] = datos[i];
        }
        delete []datos;
        delete []indices;
        
        datos = auxdatos;
        indices = auxind;
    }
    size += inc;
}

void leeYCrearTablas(char **&datos, int *&indices, char **&indicador){
    char buff[300];
    int n = 0, size = 0;
    indicador = new char*;
    int first = 0;
    while(cin >> buff){
        if(n == size){
            incrementar(datos, indices, n, size);
            if(n != 0) indicador = &datos[first];
        }
        datos[n] = new char[strlen(buff) + 1];
        strcpy(datos[n], buff);
        if(n == 0){
            indicador = &datos[0];
            indices[n] = -1;
            first = n;
        }
        else{
            int p = indicador - datos;
            int flag = 0;
            while(indices[p] != -1 && strcmp(datos[indices[p]], datos[n]) <= 0){
                p = indices[p];
                flag = 1;
            }
            int next = indices[p];
            indices[p] = n;
            indices[n] = next;
            if(!flag){
                first = n;
            }
        }
        n++;
    }
}
