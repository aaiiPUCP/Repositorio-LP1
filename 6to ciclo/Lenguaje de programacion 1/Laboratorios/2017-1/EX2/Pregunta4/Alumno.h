/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.h
 * Author: Karla Isabel Pedraza Salinas 20141056
 *
 * Created on 11 de julio de 2017, 08:04 AM
 */

#ifndef ALUMNO_H
#define ALUMNO_H
#include <iostream>
using namespace std;
class Alumno {
public:
    Alumno();
    Alumno(const Alumno& orig);
    virtual ~Alumno();
    void SetNombre(char* nombre);
    char* GetNombre() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    virtual void leerDatos(ifstream&);
    virtual void imprimirDatos(ofstream&)=0;
    bool operator > (Alumno&);
protected:
    int codigo;
    char* nombre;
};

#endif /* ALUMNO_H */

