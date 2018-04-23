/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CursoNota.cpp
 * Author: Karla Isabel Pedraza Salinas 20141056
 * 
 * Created on 11 de julio de 2017, 08:38 AM
 */

#include "CursoNota.h"
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
CursoNota::CursoNota() {
    codigo=NULL;
}

CursoNota::CursoNota(const CursoNota& orig) {
    SetCodigo(orig.codigo);
    SetNota(orig.nota);
    
}

CursoNota::~CursoNota() {
    //if (codigo) delete[] codigo;
}

void CursoNota::SetNota(int nota) {
    this->nota = nota;
}

int CursoNota::GetNota() const {
    return nota;
}

void CursoNota::SetCodigo(char* _codigo) {
    //if (codigo) delete[] codigo;
    codigo= new char[strlen(_codigo)+1];
    strcpy(codigo,_codigo);
}

char* CursoNota::GetCodigo() const {
    char* _codigo= new char[strlen(codigo)+1];
    strcpy(_codigo,codigo);
    return _codigo;
}
istream & operator >>(istream&in,CursoNota&cn){
    char cod[200];
    in.getline(cod,200,',');
    in>>cn.nota;
    cn.SetCodigo(cod);
    in.get();
    in>>ws;
    return in;
}
ostream & operator <<(ostream&out,CursoNota&cn){
    out<<left<<setw(10)<<cn.codigo;
    out<<cn.nota<<endl;
    return out;
}
