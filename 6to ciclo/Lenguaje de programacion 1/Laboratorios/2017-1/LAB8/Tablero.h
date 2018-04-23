/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tablero.h
 * Author: Daniel Chapi Alejo
 * Codigo: 20140352
 *
 * Created on 9 de junio de 2017, 08:02 AM
 */

#include <iostream>
using namespace std;

#ifndef TABLERO_H
#define TABLERO_H

class Tablero{
private:
    int nFil,nCol;
    int** area;
public:
    ~Tablero();
    Tablero();
    Tablero(int nFil, int nCol);
    int** GetArea() const;

    int GetNCol() const;

    int GetNFil() const;

    void SetNCol(int );

    void SetNFil(int);   
    //corregir lo de arriba
    
    void pintar(int,int,int);
    void imprimir(ofstream &);
    int validar(int , int ); 
    void limpiar();
    void redimensionar(int , int );
        
    
};


#endif /* TABLERO_H */

