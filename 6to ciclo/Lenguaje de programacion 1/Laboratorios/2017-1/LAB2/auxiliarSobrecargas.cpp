/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//Karla Isabel Pedraza Salinas
//20141056
#include "tipoStruct.h"
#include <iostream>

std::istream & operator >> (std::istream &cin,Pixel &p){
    char c1,c2,c3;
    std::cin>>c1>>c2>>c3;
    p.R=int(c1);
    p.B=int(c2);
    p.G=int(c3);
    return cin;
}