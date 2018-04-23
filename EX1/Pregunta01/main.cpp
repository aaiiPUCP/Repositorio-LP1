/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Arian Gallardo 20153227
 *
 * Created on 10 de octubre de 2017, 08:08 AM
 */

#include <iostream>
#include <cstring>
#include <cctype>
#include <iomanip>
#include <cstdio>
#include "Bib_Func_Preg1.h"

using namespace std;

int main() {
    int *codCur, **requisitos;
    char **cursos;
    leeCursos(codCur, cursos, requisitos);
    imprimirCursos(codCur, cursos, requisitos);
    return 0;
}

