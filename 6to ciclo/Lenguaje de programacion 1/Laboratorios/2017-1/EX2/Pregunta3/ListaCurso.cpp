/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaCurso.cpp
 * Author: Karla Isabel Pedraza Salinas 20141056
 * 
 * Created on 11 de julio de 2017, 09:59 AM
 */

#include "ListaCurso.h"
#include <cstdlib>
#include <iomanip>
ListaCurso::ListaCurso() {
    lista=NULL;
}

ListaCurso::ListaCurso(const ListaCurso& orig) {
}

ListaCurso::~ListaCurso() {
}

void ListaCurso::leerCursos(ifstream&in){
    Curso* course;
    while(1){
        in>>ws;
        if(in.eof()) break;
        course=new Curso;
        in>>(*course);
        insertar(course);
    }
}
void ListaCurso::imprimirCursos(ofstream&out){
    out<<"                                             Cursos de la institucion"<<endl;
    out<<left<<setw(10)<<"Codigo"<<setw(50)<<"Nombre"<<setw(15)<<"Creditos"<<setw(20)<<"Requisitos"<<endl;
    NodoCurso *p=lista;
    while(p){
        out<<(*p);
        p=p->sig;
    }
}
void ListaCurso::insertar(Curso*&curso){
    NodoCurso *p=lista,*ant=NULL,*nuevo;
    nuevo=new NodoCurso;
    nuevo->curso = curso;
    while(p){
        if(*(p->curso)>*(nuevo->curso)) break;
        ant=p;
        p=p->sig;
    }
    nuevo->sig=p;
    if(ant) ant->sig=nuevo;
    else lista=nuevo;    
}