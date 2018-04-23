/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * * Author: Daniel Chapi Alejo
 * Codigo: 20140352
 */

#include "Tablero.h"
#include <iostream>
#include <fstream>
using namespace std;
Tablero:: ~Tablero(){
    for(int i=0;i<this->nFil;i++) delete [] (this->area)[i];
    delete [] this->area;
}
Tablero::Tablero(){
    this->nFil=40;
    this->nCol=70;
    this->area= new int*[this->nFil];
    for(int i=0;i<nFil;i++){
        (this->area)[i]= new int[this->nCol];
    }
    for (int i=0;i<nFil;i++){
        for (int j=0;j<nCol;j++){
            (this->area)[i][j]=0;
        }
    } //llenamos todo de ceros
}
Tablero::Tablero(int nFil, int nCol):
    nFil(nFil), nCol(nCol) {
    this->area= new int*[nFil];
    for(int i=0;i<nFil;i++){
        (this->area)[i]= new int[nCol];
    }
    for (int i=0;i<nFil;i++){
        for (int j=0;j<nFil;j++){
            (this->area)[i][j]=0;
        }
    } //llenamos todo de ceros
}

int** Tablero::GetArea() const {
    int** aux= new int*[this->nFil];
    for(int i=0;i<this->nFil;i++){
        aux[i]= new int[this->nCol];
        for(int j=0;j<this->nCol;j++){
            aux[i][j]=(this->area)[i][j];
        }
    }
    return aux;
}

int Tablero::GetNCol() const {
    return nCol;
}

int Tablero::GetNFil() const {
    return nFil;
}


void Tablero::SetNCol(int nCol) {
    this->nCol = nCol;
}

void Tablero::SetNFil(int nFil) {
    this->nFil = nFil;
}
void Tablero::pintar(int pluma,int f,int c){
    if(pluma==1) (this->area)[f][c]=1;
}
void Tablero::imprimir(ofstream &arch){
    for (int i=0;i<(this->nFil);i++){
        for (int j=0;j<(this->nCol);j++){
            if((this->area)[i][j]==0) arch <<"  "; 
            else arch<< " #";
        }
        arch << endl;
    }
}
int Tablero:: validar(int f, int c){
    if(f>=0 && f<this->nFil && c>=0 && c<this->nCol) return 1;
    return 0;
}
 
void Tablero::limpiar(){
    for (int i=0;i<this->nFil;i++){
        for (int j=0;j<this->nCol;j++){
            (this->area)[i][j]=0;
        }
    }
}


void Tablero::redimensionar(int filas , int columnas){
    int newF= this->nFil + filas;
    int newC= this->nCol + columnas;
    //guardamos el dibujo en un aux
    int** aux= new int*[this->nFil];
    for(int i=0;i<this->nFil;i++){
        aux[i]= new int[this->nCol];
        for(int j=0;j<this->nCol;j++){
            aux[i][j]=(this->area)[i][j];
        }
    }
    
    
    //redimensionamos el area
    for(int i=0;i<this->nFil;i++) delete [] (this->area)[i];
    delete [] this->area;
    this->area= new int*[newF];
    for(int i=0; i<newF;i++){
        (this->area)[i]= new int[newC];
    }
    //llenamos todo de cero
    for (int i=0;i<newF;i++){
        for (int j=0;j<newC;j++){
            (this->area)[i][j]=0;
        }
    }
    //copiamos el dibujo hasta donde se pueda
    for(int i=0;(i<newF && i<this->nFil);i++){
        for(int j=0;(j<newC && j<this->nCol);j++){
            (this->area)[i][j]= aux[i][j];
        }
    }
    this->nFil=newF;
    this->nCol=newC;
}