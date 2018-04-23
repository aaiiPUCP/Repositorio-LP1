/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * 
 * Arian Gallardo 20153227
 */

#include <iostream>
#include <cstring>
#include "Cadena.h"

using namespace std;

Cadena :: Cadena(){
    cadena = NULL; longitud = 0;
    capacidad = 0;
}

Cadena :: Cadena(const char *_cadena){
    cadena = new char[strlen(_cadena) + 1];
    strcpy(cadena, _cadena);
    longitud = strlen(_cadena);
    capacidad = longitud + 1;
}

Cadena :: Cadena(int _capacidad){
    capacidad = _capacidad;
    longitud = 0;
    cadena = new char[capacidad];
    strcpy(cadena,"");
}

void Cadena :: assign(const char *_cadena){
    if(capacidad >= strlen(_cadena) + 1){
        strcpy(cadena, _cadena);
        longitud = strlen(_cadena);
    }
    else{
        capacidad = (int)(1.3 * strlen(_cadena));
        if(cadena) delete [] cadena;
        cadena = new char[capacidad];
        strcpy(cadena, _cadena);
        longitud = strlen(_cadena);
    }
}

void Cadena :: assign(const Cadena &_cadena){
    if(capacidad >= _cadena.capacidad){
        strcpy(cadena, _cadena.cadena);
        longitud = _cadena.longitud;
    }
    else{
        capacidad = (int)(1.3 * _cadena.longitud);
        if(cadena) delete [] cadena;
        cadena = new char[capacidad];
        strcpy(cadena, _cadena.cadena);
        longitud = _cadena.longitud;
    }
}

Cadena& Cadena :: operator =(const char *_cadena){
    if(capacidad >= strlen(_cadena) + 1){
        strcpy(cadena, _cadena);
        longitud = strlen(_cadena);
    }
    else{
        capacidad = (int)(1.3 * strlen(_cadena));
        if(cadena) delete [] cadena;
        cadena = new char[capacidad];
        strcpy(cadena, _cadena);
        longitud = strlen(_cadena);
    }
    return *this;
}

Cadena& Cadena :: operator=(const Cadena &_cadena){
    if(capacidad >= _cadena.capacidad){
        strcpy(cadena, _cadena.cadena);
        longitud = _cadena.longitud;
    }
    else{
        capacidad = (int)(1.3 * _cadena.longitud);
        if(cadena) delete [] cadena;
        cadena = new char[capacidad];
        strcpy(cadena, _cadena.cadena);
        longitud = _cadena.longitud;
    }
    return *this;
}

void Cadena :: append(const char *_cadena){
    if(capacidad >= strlen(_cadena) + longitud + 1){
        strcat(cadena, _cadena);
        longitud += strlen(_cadena);
    }
    else{
        capacidad = (int)(1.3 * (strlen(_cadena) + longitud));
        char *aux = new char[capacidad];
        strcpy(aux, cadena); strcat(aux, _cadena);
        longitud = strlen(aux);
        cadena = aux;
    }
}

Cadena& Cadena :: operator +=(const Cadena &_cadena){
    if(capacidad >= longitud + _cadena.longitud + 1){
        strcat(cadena, _cadena.cadena);
        longitud += _cadena.longitud;
    }
    else{
        capacidad = (int)(1.3 * (_cadena.longitud + longitud));
        char *aux = new char[capacidad];
        strcpy(aux, cadena); strcat(aux,_cadena.cadena);
        longitud = strlen(aux);
        cadena = aux;
    }
    return *this;
}

Cadena& Cadena :: operator+(const Cadena &_cadena){
    char *aux = new char[_cadena.longitud + longitud + 1];
    strcpy(aux, cadena); strcat(aux, _cadena.cadena);
    Cadena *newCad = new Cadena(aux);
    return *newCad;
}

int Cadena :: compare(const char *_cadena){
    return strcmp(cadena, _cadena);
}

int Cadena :: compare(const Cadena &_cadena){
    return strcmp(cadena, _cadena.cadena);
}

int Cadena :: operator ==(const Cadena &_cadena){
    return (strcmp(cadena, _cadena.cadena) == 0);
}

int Cadena :: operator >(const Cadena &_cadena){
    return (strcmp(cadena, _cadena.cadena) > 0);
}

int Cadena :: operator <(const Cadena &_cadena){
    return (strcmp(cadena,_cadena.cadena) < 0);
}

int Cadena :: length(){
    return longitud;
}

void Cadena :: swap(Cadena &_cadena){
    char *tmpstr = new char[capacidad];
    if(cadena) strcpy(tmpstr, cadena);
    int tmpcap = capacidad;
    int tmpsz = longitud;
    
    if(cadena) delete []cadena;
    cadena = new char[_cadena.capacidad];
    if(_cadena.cadena) strcpy(cadena, _cadena.cadena);
    capacidad = _cadena.capacidad;
    longitud = _cadena.longitud;
    
    if(_cadena.cadena) delete []_cadena.cadena;
    _cadena.cadena = new char[tmpcap];
    strcpy(_cadena.cadena, tmpstr);
    _cadena.capacidad = tmpcap;
    _cadena.longitud = tmpsz;
}

void Cadena :: print(){
    cout << cadena << endl;
}

Cadena :: ~Cadena(){
    if(cadena) delete []cadena;
}

char* Cadena :: getCadena() const{
    if(!cadena) return NULL;
    char* aux = new char[strlen(cadena) + 1];
    strcpy(aux, cadena);
    return aux;
}

int Cadena :: getCapacidad() const{
    return capacidad;
}