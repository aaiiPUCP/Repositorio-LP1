/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoAlumno.cpp
 * Author: Karla Isabel Pedraza Salinas 20141056
 * 
 * Created on 11 de julio de 2017, 08:37 AM
 */

#include "NodoAlumno.h"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;
NodoAlumno::NodoAlumno() {
    sig=NULL;
}

NodoAlumno::NodoAlumno(const NodoAlumno& orig) {
}

NodoAlumno::~NodoAlumno() {
    cursosNotas.clear();
}

void NodoAlumno::agregarCurso(CursoNota&c){
    cursosNotas.push_back(c);
}
void NodoAlumno::imprimirDatos(ofstream&out){
    alumno->imprimirDatos(out);
    out<<"LISTADO DE NOTAS: "<<endl;
    out<<left<<setw(10)<<"CODIGO";
    out<<"NOTA"<<endl;
    for(list<CursoNota>::iterator it=cursosNotas.begin();it!=cursosNotas.end();it++){
        out<<(*it);
    }
    out<<endl;
}