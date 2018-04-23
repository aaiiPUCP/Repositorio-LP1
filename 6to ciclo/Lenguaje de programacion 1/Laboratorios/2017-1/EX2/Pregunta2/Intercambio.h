/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Intercambio.h
 * Author: Karla Isabel Pedraza Salinas 20141056
 *
 * Created on 11 de julio de 2017, 08:12 AM
 */

#ifndef INTERCAMBIO_H
#define INTERCAMBIO_H
#include "Alumno.h"
class Intercambio: public Alumno {
public:
    Intercambio();
    Intercambio(const Intercambio& orig);
    virtual ~Intercambio();
    void SetSemestres(int semestres);
    int GetSemestres() const;
    void SetIdioma(char* idioma);
    char* GetIdioma() const;
    void SetPais(char* pais);
    char* GetPais() const;
    void leerDatos(ifstream&);
    void imprimirDatos(ofstream&);
private:
    char* pais;
    char* idioma;
    int semestres;
};

#endif /* INTERCAMBIO_H */

