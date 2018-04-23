/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Curso.h
 * Author: Karla Isabel Pedraza Salinas 20141056
 *
 * Created on 11 de julio de 2017, 09:43 AM
 */

#ifndef CURSO_H
#define CURSO_H
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
class Curso {
public:
    Curso();
    Curso(const Curso& orig);
    virtual ~Curso();
    void SetRequisitos(vector<char*> requisitos);
    vector<char*> GetRequisitos() const;
    void SetCreditos(double creditos);
    double GetCreditos() const;
    void SetNombre(char* nombre);
    char* GetNombre() const;
    void SetCodigo(char* codigo);
    char* GetCodigo() const;
    friend istream & operator >>(istream&,Curso&);
    friend ostream & operator <<(ostream&,Curso&);
    bool operator >(Curso&);
private:
    char* codigo;
    char* nombre;
    double creditos;
    vector<char*> requisitos;
};

#endif /* CURSO_H */

