/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Matricula.cpp
 * Author: Karla Isabel Pedraza Salinas 20141056
 * 
 * Created on 11 de julio de 2017, 08:53 AM
 */

#include "Matricula.h"
#include "NodoAlumno.h"
#include <iomanip>
#include <fstream>
#include <iostream>
#include "Intercambio.h"
Matricula::Matricula() {
    listaAlumnos=new ListaAlumno;
    listaCursos=new ListaCurso;
}

Matricula::Matricula(const Matricula& orig) {
}

Matricula::~Matricula() {
    listaAlumnos->eliminar();
}
void Matricula::leerAlumnos(ifstream&in){
    listaAlumnos->leerAlumnos(in);
}
void Matricula::leerCursosNotas(ifstream&in){
    listaAlumnos->leerCursosNotas(in);
}
void Matricula::imprimirReporte(ofstream&out){
    listaCursos->imprimirCursos(out);
    for(int i=0;i<160;i++) out<<'=';out<<endl;
    listaAlumnos->imprimirReporte(out);
}
void Matricula::leerCursos(ifstream&in){
    listaCursos->leerCursos(in);
}
void Matricula::imprimirReporte4(ifstream&in,ofstream&out){
    Alumno* al=new Intercambio;
    int codigo;
    while(1){
        in>>ws;
        if(in.eof()) break;
        in>>codigo;
        al->SetCodigo(codigo);
        NodoAlumno* nodo=listaAlumnos->buscar(al);
        if(nodo){
            nodo->imprimirDatos(out);
            out<<"CURSOS QUE QUIERE MATRICULARSE"<<endl;
            out<<left<<setw(10)<<"Codigo"<<setw(50)<<"Nombre"<<setw(15)<<"Creditos"<<setw(20)<<"Requisitos"<<endl;
            while(!in.eof() && in.peek()!='\n'){
                char aux[200];
                in.get();
                int cant=0;
                while(!in.eof() &&in.peek()!='\n' && in.peek()!=','){
                    in>>aux[cant];
                    cant++;
                }
                aux[cant]=0;
                NodoCurso* nodo2=listaCursos->buscar(aux);
                if(nodo2)
                    out<<*nodo2;
            }
            in>>ws;
            out<<endl;
        }
        else{
            in.ignore(200,'\n');
        }
    }
}