/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Intercambio.cpp
 * Author: Karla Isabel Pedraza Salinas 20141056
 * 
 * Created on 11 de julio de 2017, 08:12 AM
 */

#include "Intercambio.h"
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
Intercambio::Intercambio() {
    pais=NULL;
    idioma=NULL;
}

Intercambio::Intercambio(const Intercambio& orig) {
}

Intercambio::~Intercambio() {
    if (pais) delete[]pais;
    if (idioma) delete[]idioma;
    
}

void Intercambio::SetSemestres(int semestres) {
    this->semestres = semestres;
}

int Intercambio::GetSemestres() const {
    return semestres;
}

void Intercambio::SetIdioma(char* _idioma) {
    if (idioma) delete[] idioma;
    idioma=new char[strlen(_idioma)+1];
    strcpy(idioma,_idioma);
}

char* Intercambio::GetIdioma() const {
    char* _idioma=new char[strlen(idioma)+1];
    strcpy(_idioma,idioma);
    return _idioma;
}

void Intercambio::SetPais(char* _pais) {
    if (pais) delete[] pais;
    pais=new char[strlen(_pais)+1];
    strcpy(pais,_pais);
}

char* Intercambio::GetPais() const {
    char* _idioma=new char[strlen(pais)+1];
    strcpy(_idioma,pais);
    return _idioma;
}

void Intercambio::leerDatos(ifstream&in){
    Alumno::leerDatos(in);
    char _pais[200],_idioma[200];
    in.getline(_pais,200,',');
    in.getline(_idioma,200,',');
    in>>semestres;
    in>>ws;
    SetPais(_pais);
    SetIdioma(_idioma);
}
void Intercambio::imprimirDatos(ofstream&out){
    out<<"ALUMNO INTERCAMBIO: "<<endl;
    Alumno::imprimirDatos(out);
    out<<"PAIS: "<<pais<<endl;
    out<<"IDIOMA: "<<idioma<<endl;  
    out<<"NUMERO DE SEMETRES: "<<semestres<<endl;
}