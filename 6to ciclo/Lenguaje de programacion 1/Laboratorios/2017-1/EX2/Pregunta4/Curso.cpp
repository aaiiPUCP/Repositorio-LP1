/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Curso.cpp
 * Author: Karla Isabel Pedraza Salinas 20141056
 * 
 * Created on 11 de julio de 2017, 09:43 AM
 */

#include "Curso.h"
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
Curso::Curso() {
    codigo=NULL;
}

Curso::Curso(const Curso& orig) {
    SetCodigo(orig.codigo);
    SetNombre(orig.nombre);
    SetRequisitos(orig.requisitos);
}

Curso::~Curso() {
    if (codigo) delete[] codigo;
    if (nombre) delete[] nombre;
}

void Curso::SetRequisitos(vector<char*> requisitos) {
    this->requisitos = requisitos;
}

vector<char*> Curso::GetRequisitos() const {
    return requisitos;
}

void Curso::SetCreditos(double creditos) {
    this->creditos = creditos;
}

double Curso::GetCreditos() const {
    return creditos;
}

void Curso::SetNombre(char* _nombre) {
    //Arroja error si lo descomento igual con los demas
    //if (nombre) delete[] nombre;
    nombre=new char[strlen(_nombre)+1];
    strcpy(nombre,_nombre);
}

char* Curso::GetNombre() const {
    char* _nombre=new char[strlen(nombre)+1];
    strcpy(_nombre,nombre);
    return _nombre;
}

void Curso::SetCodigo(char* _codigo) {
    //if (codigo) delete[] codigo;
    codigo=new char[strlen(_codigo)+1];
    strcpy(codigo,_codigo);
}

char* Curso::GetCodigo() const {
    char* _codigo=new char[strlen(codigo)+1];
    strcpy(_codigo,codigo);
    return _codigo;
}

bool Curso::operator >(Curso&c){
    return strcmp(this->codigo,c.codigo)>0;
}

istream & operator >>(istream&in, Curso&c){
    char cod[200],nom[200];
    in.getline(cod,200,',');
    in.getline(nom,200,',');
    in>>c.creditos;
    c.SetNombre(nom);
    c.SetCodigo(cod);
    while(!in.eof() && in.peek()!='\n'){
        char aux[200];
        in.get();
        int cant=0;
        while(!in.eof() &&in.peek()!='\n' && in.peek()!=','){
            in>>aux[cant];
            cant++;
        }
        aux[cant]=0;
        char* req=new char[strlen(aux)+1];
        strcpy(req,aux);
        c.requisitos.push_back(req);
    }
    in>>ws;
    return in;
}

ostream & operator <<(ostream&out,Curso&c){
    out<<left<<setw(10)<<c.codigo<<setw(50)<<c.nombre<<setw(15)<<setprecision(4)<<c.creditos;
    int cant=0;
    for(vector<char*>::iterator it=c.requisitos.begin();it!=c.requisitos.end();it++){
        if(cant!=0) out<<"/";
        out<<*it;
        cant++;
    }
    out<<endl;
    return out;
}