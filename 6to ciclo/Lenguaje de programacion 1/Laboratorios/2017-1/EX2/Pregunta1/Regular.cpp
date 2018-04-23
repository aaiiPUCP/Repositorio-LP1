/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Regular.cpp
 * Author: Karla Isabel Pedraza Salinas 20141056
 * 
 * Created on 11 de julio de 2017, 08:08 AM
 */

#include "Regular.h"
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
Regular::Regular() {
    facultad=NULL;
    especialidad=NULL;
}

Regular::Regular(const Regular& orig) {
}

Regular::~Regular() {
    if (facultad) delete[] facultad;
    if (especialidad) delete[] especialidad;
}

void Regular::SetFacultad(char* _facultad) {
    if (facultad) delete[] facultad;
    facultad=new char[strlen(_facultad)+1];
    strcpy(facultad,_facultad);
}

char* Regular::GetFacultad() const {
    char* _facultad=new char[strlen(facultad)+1];
    strcpy(_facultad,facultad);
    return _facultad;
}

void Regular::SetEspecialidad(char* _especialidad) {
    if (especialidad) delete[] especialidad;
    especialidad=new char[strlen(_especialidad)+1];
    strcpy(especialidad,_especialidad);
}

char* Regular::GetEspecialidad() const {
    char* _especialidad=new char[strlen(especialidad)+1];
    strcpy(_especialidad,especialidad);
    return _especialidad;
}
void Regular::leerDatos(ifstream&in){
    Alumno::leerDatos(in);
    char esp[200],fac[200];
    in.getline(esp,200,',');
    in.getline(fac,200,'\n');
    in>>ws;
    SetFacultad(fac);
    SetEspecialidad(esp);
    
}
void Regular::imprimirDatos(ofstream&out){
    out<<"ALUMNO REGULAR: "<<endl;
    Alumno::imprimirDatos(out);
    out<<"ESPECIALIDAD: "<<especialidad<<endl;
    out<<"FACULTAD: "<<facultad<<endl;  
}
