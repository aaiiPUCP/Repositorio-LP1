/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * * Author: Daniel Chapi Alejo
 * Codigo: 20140352
 */

/* 
 * File:   Tortuga.h
 * Author: alulab14
 *
 * Created on 9 de junio de 2017, 08:07 AM
 */
#include <fstream>
#include <iostream>
#include "Tablero.h"
using namespace std;

#ifndef TORTUGA_H
#define TORTUGA_H

class Tortuga{
private:
    int fila,columna,pluma,orientacion;
public:
    ~Tortuga();
    Tortuga();
    Tortuga(int fila, int columna, int pluma, int orientacion);
    void SetOrientacion(int orientacion);

    int GetOrientacion() const;

    void SetPluma(int pluma);

    int GetPluma() const;

    void SetColumna(int columna);

    int GetColumna() const;

    void SetFila(int fila);

    int GetFila() const;
    
    void dibujar(Tablero& );
    void girar_tortuga(int);
    int validar_movimiento(Tablero&,int);
    void mover(Tablero&,int);
    void reset_tortuga();
    void ejecutar_comando(Tablero&,int*);
    void procesar_archivo(ifstream&,Tablero&);
    
    
};


#endif /* TORTUGA_H */

