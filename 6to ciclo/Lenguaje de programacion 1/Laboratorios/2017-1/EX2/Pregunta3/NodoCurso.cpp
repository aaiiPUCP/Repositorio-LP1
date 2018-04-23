/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoCurso.cpp
 * Author: Karla Isabel Pedraza Salinas 20141056
 * 
 * Created on 11 de julio de 2017, 09:58 AM
 */

#include "NodoCurso.h"
#include <cstdlib>
NodoCurso::NodoCurso() {
    sig=NULL;
}

NodoCurso::NodoCurso(const NodoCurso& orig) {
}

NodoCurso::~NodoCurso() {
}

ostream & operator <<(ostream&out,NodoCurso&c){
    out<<*(c.curso);
}