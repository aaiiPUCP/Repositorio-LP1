/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaAlumno.h
 * Author: Karla Isabel Pedraza Salinas 20141056
 *
 * Created on 11 de julio de 2017, 08:37 AM
 */

#ifndef LISTAALUMNO_H
#define LISTAALUMNO_H
#include "NodoAlumno.h"
class ListaAlumno {
public:
    ListaAlumno();
    ListaAlumno(const ListaAlumno& orig);
    virtual ~ListaAlumno();  
    void eliminar();
    void leerAlumnos(ifstream&);
    void leerCursosNotas(ifstream&);
    void imprimirReporte(ofstream&);
    NodoAlumno* buscar(Alumno*);
private:
    void insertar(Alumno*&);
    NodoAlumno* lista;
};

#endif /* LISTAALUMNO_H */

