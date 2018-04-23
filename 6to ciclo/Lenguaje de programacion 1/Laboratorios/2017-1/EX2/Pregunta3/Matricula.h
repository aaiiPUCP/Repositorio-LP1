/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Matricula.h
 * Author: Karla Isabel Pedraza Salinas 20141056
 *
 * Created on 11 de julio de 2017, 08:53 AM
 */

#ifndef MATRICULA_H
#define MATRICULA_H
#include "ListaAlumno.h"
#include "ListaCurso.h"
#include <fstream>
using namespace std;
class Matricula {
public:
    Matricula();
    Matricula(const Matricula& orig);
    virtual ~Matricula();
    void leerAlumnos(ifstream&);
    void leerCursosNotas(ifstream&);
    void imprimirReporte(ofstream&);
    void leerCursos(ifstream&);
private:
    ListaAlumno* listaAlumnos;
    ListaCurso* listaCursos;
};

#endif /* MATRICULA_H */

