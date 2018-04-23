/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Arian Gabriel Gallardo Callalli 20153227
 *
 * Created on 29 de septiembre de 2017, 08:09 AM
 */

#include <iostream>
#include "funcionesPreg2.h"

using namespace std;

int main(){
    char* linea[500];
    char **codigo, **nombre;
    float *credAcum;
    int *indices;
    int nd = 0, szd = 0;
    int first = 0;
    while(cin.getline(linea, 500)){
        char **tokens = new char[500];
        int n = 0;
        split(linea, tokens, n);
        if(tokens[1][0] >='0' && tokens[2][0] <='9'){
            if(strcmp(tokens[1], "10") > 0){
                int x = 0;
                while(strcmp(codigo[x], tokens[1]) != 0) x++;
                float cred = atof(tokens[3]);
                credAcum[nd] += cred;
            }
        }
        else{
            int sz = 0;
            for(int i = 1 ; i < n; i ++) sz+= strlen(tokens[i]) + 1;
            char *nombrep = new char[sz];
            nombrep[0] = '\0';
            for(int i = 1; i < n ; i++){
                strcat(nombrep, tokens[i]);
                if(i != n-1) strcat(nombrep,"/");
            }
            if(nd == szd) incrementar(codigo, nombre, credAcum, indices, nd, szd);
            codigo[nd] = new char[strlen(tokens[0]) + 1];
            nombre[nd] = new char[strlen(nombrep) + 1];
            credAcum[nd] = 0.0;
            if(nd == 0){
                first = nd;
            }
        }
    }
    return 0;
}

