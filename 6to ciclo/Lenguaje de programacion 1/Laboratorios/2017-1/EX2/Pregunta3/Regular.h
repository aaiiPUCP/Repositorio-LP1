/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Regular.h
 * Author: Karla Isabel Pedraza Salinas 20141056
 *
 * Created on 11 de julio de 2017, 08:08 AM
 */

#ifndef REGULAR_H
#define REGULAR_H
#include "Alumno.h"
class Regular: public Alumno {
public:
    Regular();
    Regular(const Regular& orig);
    virtual ~Regular();
    void SetFacultad(char* facultad);
    char* GetFacultad() const;
    void SetEspecialidad(char* especialidad);
    char* GetEspecialidad() const;
    void leerDatos(ifstream&);
    void imprimirDatos(ofstream&);
private:
    char* especialidad;
    char* facultad;
};

#endif /* REGULAR_H */

