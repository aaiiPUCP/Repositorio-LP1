/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaAlumno.cpp
 * Author: Karla Isabel Pedraza Salinas 20141056
 * 
 * Created on 11 de julio de 2017, 08:37 AM
 */

#include "ListaAlumno.h"
#include "Regular.h"
#include "Intercambio.h"
#include <fstream>
#include <iostream>
#include "CursoNota.h"
#include "Alumno.h"
#include <cstdlib>
ListaAlumno::ListaAlumno() {
    lista=NULL;
}

ListaAlumno::ListaAlumno(const ListaAlumno& orig) {
}

ListaAlumno::~ListaAlumno() {
}

void 
ListaAlumno::insertar(Alumno*& alumno){
    NodoAlumno *p=lista,*ant=NULL,*nuevo;
    nuevo=new NodoAlumno;
    nuevo->alumno = alumno;
    while(p){
        if(*(p->alumno)>*(nuevo->alumno)) break;
        ant=p;
        p=p->sig;
    }
    nuevo->sig=p;
    if(ant) ant->sig=nuevo;
    else lista=nuevo;
}
NodoAlumno* ListaAlumno::buscar(Alumno* _alumno){
    NodoAlumno *p=lista;
    while(p){
        if((p->alumno)->GetCodigo()==_alumno->GetCodigo())
            return p;
        p=p->sig;
    }
    return NULL;
}
void ListaAlumno::eliminar(){
    NodoAlumno *p;
    while(lista){
        p=lista;
        lista=lista->sig;
        delete p;
    }
}
void ListaAlumno::leerCursosNotas(ifstream& in){
    Alumno* student=new Regular;
    int codigo;
    while(1){
        if( in.eof()) break;
        in>>codigo;
        in.get();
        student->SetCodigo(codigo);
        NodoAlumno* nodo=buscar(student);
        CursoNota cn;
        in>>cn;
        if(nodo)
            nodo->agregarCurso(cn);
    }
}

void ListaAlumno::leerAlumnos(ifstream&in){
    char c;   
    Alumno *student;
    while(1){
        in>>ws;
        if(in.eof()) break;
        in>>c;in.get();
        if(c=='R')
            student=new Regular;
        else
            student=new Intercambio;
        student->leerDatos(in);
        insertar(student);

    }
}
void ListaAlumno::imprimirReporte(ofstream&out){
    out<<"                                    Alumnos de la institucion"<<endl;
    NodoAlumno *p=lista;
    while(p){
        p->imprimirDatos(out);
        p=p->sig;
    }
}