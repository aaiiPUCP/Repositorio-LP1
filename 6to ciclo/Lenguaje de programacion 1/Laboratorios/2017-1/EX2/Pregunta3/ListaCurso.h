/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaCurso.h
 * Author: Karla Isabel Pedraza Salinas 20141056
 *
 * Created on 11 de julio de 2017, 09:59 AM
 */

#ifndef LISTACURSO_H
#define LISTACURSO_H
#include "NodoCurso.h"
class ListaCurso {
public:
    ListaCurso();
    ListaCurso(const ListaCurso& orig);
    virtual ~ListaCurso();
    void leerCursos(ifstream&);
    void imprimirCursos(ofstream&);
private:
    void insertar(Curso*&);
    NodoCurso* lista;
    
};

#endif /* LISTACURSO_H */

