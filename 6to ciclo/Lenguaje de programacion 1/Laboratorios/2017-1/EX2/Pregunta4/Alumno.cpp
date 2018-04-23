/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.cpp
 * Author: Karla Isabel Pedraza Salinas 20141056
 * 
 * Created on 11 de julio de 2017, 08:04 AM
 */

#include "Alumno.h"
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
Alumno::Alumno() {
    nombre=NULL;
}

Alumno::Alumno(const Alumno& orig) {
}
Alumno::~Alumno() {
    if (nombre) delete[] nombre;
}

void Alumno::SetNombre(char* _nombre) {
    if (nombre) delete[] nombre;
    nombre=new char[strlen(_nombre)+1];
    strcpy(nombre,_nombre);
}

char* Alumno::GetNombre() const {
    char* _nombre=new char[strlen(nombre)+1];
    strcpy(_nombre,nombre);
    return _nombre;
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}
void Alumno::leerDatos(ifstream&in){
    in>>codigo;
    in.get();
    char nom[200];
    in.getline(nom,200,',');
    SetNombre(nom);
}
bool Alumno::operator > (Alumno&o){
    return this->codigo>o.codigo;
}