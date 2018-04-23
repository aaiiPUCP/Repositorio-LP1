/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoAlumno.h
 * Author: Karla Isabel Pedraza Salinas 20141056
 *
 * Created on 11 de julio de 2017, 08:37 AM
 */

#ifndef NODOALUMNO_H
#define NODOALUMNO_H
#include "Alumno.h"
#include "CursoNota.h"
#include <list>
using namespace std;
class NodoAlumno {
public:
    NodoAlumno();
    NodoAlumno(const NodoAlumno& orig);
    virtual ~NodoAlumno();
    void agregarCurso(CursoNota&);
    void imprimirDatos(ofstream&);
private:
    Alumno* alumno;
    list<CursoNota> cursosNotas;
    NodoAlumno* sig;
    friend class ListaAlumno;
};

#endif /* NODOALUMNO_H */

