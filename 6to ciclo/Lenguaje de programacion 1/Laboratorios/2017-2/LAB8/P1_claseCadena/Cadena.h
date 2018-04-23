/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cadena.h
 * Author: Arian Gallardo 20153227
 *
 * Created on 10 de noviembre de 2017, 08:05 AM
 */

#ifndef CADENA_H
#define CADENA_H

#include <iostream>
using namespace std;

class Cadena{
private:
    char *cadena;
    int longitud;
    int capacidad;
public:
    //Constructores
    Cadena();
    Cadena(const char*);
    Cadena(int);
    
    //Asignacion
    void assign(const char*);
    void assign(const Cadena&);
    Cadena& operator =(const char*);
    Cadena& operator =(const Cadena&);
    
    //Agregacion
    void append(const char*);
    Cadena& operator +=(const Cadena&);
    
    //Concatenacion
    Cadena& operator +(const Cadena&);
    
    //Comparacion
    int compare(const char *);
    int compare(const Cadena&);
    int operator ==(const Cadena&);
    int operator <(const Cadena&);
    int operator >(const Cadena&);
    
    //Otros metodos xd
    int length();
    void swap(Cadena&);
    void print();
    ~Cadena();
    
    //Getters
    char* getCadena() const;
    int getCapacidad() const;
    
    
};

#endif /* CADENA_H */

