/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CursoNota.h
 * Author: Karla Isabel Pedraza Salinas 20141056
 *
 * Created on 11 de julio de 2017, 08:38 AM
 */

#ifndef CURSONOTA_H
#define CURSONOTA_H
#include <iostream>
using namespace std;
class CursoNota {
public:
    CursoNota();
    CursoNota(const CursoNota& orig);
    virtual ~CursoNota();
    void SetNota(int nota);
    int GetNota() const;
    void SetCodigo(char* codigo);
    char* GetCodigo() const;
    friend istream & operator >>(istream&,CursoNota&);
    friend ostream & operator <<(ostream&,CursoNota&);
private:
    char* codigo;
    int nota;
};

#endif /* CURSONOTA_H */

