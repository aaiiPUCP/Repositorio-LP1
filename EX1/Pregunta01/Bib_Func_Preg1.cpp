/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * 
 * Arian Gallardo 20153227
 */

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iomanip>

using namespace std;

#define N 1000
#define M 100

#define MAX_CAR 100


inline void impLinea(char c){
    for(int i = 0; i < MAX_CAR; i++) cout << c;
    cout <<endl;
}

template<typename T>
void incrementar(T *&lst, int n, int INC){
    if(n == 0){
        lst = new T[INC + 1];
    }
    else{
        T *aux = new T[INC + n + 1];
        for(int i = 0 ; i < n + 1; i ++) aux[i] = lst[i];
        delete []lst;
        lst = aux;
    }
}

template void incrementar(int *&lst, int n, int INC);
template void incrementar(char **&lst, int n, int INC);
template void incrementar(int **&lst, int n, int INC);

template<typename T>
void add(T *&lst, T x, int INC){
    int n = 0;
    if(lst){
        while(lst[n]) n++;
    }
    if(n % INC == 0) incrementar(lst, n, INC);
    lst[n] = x;
    lst[n+1] = 0;
}

template void add(int *&lst, int n, int INC);
template void add(char **&lst, char* n, int INC);

void split(char *linea, char **&tokens, int &n){
    int z = strlen(linea);
    for(int i = 0 ; i < z; i++){
        if(linea[i] == ','){
            linea[i] = '\0';
            n++;
        }
    }
    n++;
    int x = 0;
    tokens = new char *[n];
    int y = 0;
    while(x < z){
        tokens[y] = new char[strlen(&linea[x]) + 1];
        strcpy(tokens[y++], &linea[x]);
        while(linea[x] != '\0'){
            x++;
            if(x == z) break;
        }
        x ++;
    }
}

void leeCursos(int *&codCur, char **&cursos, int **&requisitos){
    codCur = NULL; cursos = NULL; requisitos = NULL;
    char buff[N];
    int x = 0;
    while(cin.getline(buff, N)){
        if(strcmp(buff, "") == 0) break;
        char **tokens; int n = 0;
        split(buff, tokens, n);
        add(codCur, atoi(tokens[0]), 1); add(cursos, tokens[1], 1);
        incrementar(requisitos, x, 1);
        requisitos[x] = NULL;
        for(int i = 2 ; i < n ; i ++) add(requisitos[x], atoi(tokens[i]), 1);
        x ++;
    }
}

void imprimirCursos(int *codCur, char **cursos, int **requisitos){
    cout << setw(60) << "CURSOS DISPONIBLES A MATRICULA" << endl;
    impLinea('=');
    int n = 0;
    cout << "CODIGO" << setw(50) << "NOMBRE" << setw(30) << "REQUISITOS" << endl; 
    impLinea('-');
    while(codCur[n]){
        cout << codCur[n] << setw(50) << cursos[n];
        if(!requisitos[n]){
            cout << endl;
            n ++; continue;
        }
        else{
            cout << setw(10) << requisitos[n][0];
            for(int i = 1; requisitos[n][i]; i++) cout << ", " << requisitos[n][i];
            cout << endl;
        }
        n ++;
    }
    cout << endl;
}