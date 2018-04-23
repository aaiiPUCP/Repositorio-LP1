/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoCurso.h
 * Author: Karla Isabel Pedraza Salinas 20141056
 *
 * Created on 11 de julio de 2017, 09:58 AM
 */

#ifndef NODOCURSO_H
#define NODOCURSO_H
#include "Curso.h"
class NodoCurso {
public:
    NodoCurso();
    NodoCurso(const NodoCurso& orig);
    virtual ~NodoCurso();
    friend ostream & operator <<(ostream&,NodoCurso&);
private:
    Curso* curso;
    NodoCurso* sig;
    friend class ListaCurso;
};

#endif /* NODOCURSO_H */

