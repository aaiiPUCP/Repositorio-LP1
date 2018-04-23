/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Karla Isabel Pedraza Salinas 20141056
 *
 * Created on 11 de julio de 2017, 08:04 AM
 */

#include <cstdlib>
#include "Matricula.h"
#include <iostream>
#include <fstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    ifstream archAlumno("Alumnos.csv",ios::in);
    if(!archAlumno){
        cerr<<"ERROR ARCH ALUMNOS"<<endl;
        exit(1);
    }
    ifstream archNotas("Notas.csv",ios::in);
    if(!archNotas){
        cerr<<"ERROR ARCH NOTAS"<<endl;
        exit(1);
    }
    ifstream archCursos("Cursos.csv",ios::in);
    if(!archCursos){
        cerr<<"ERROR ARCH CURSOS"<<endl;
        exit(1);
    }
    ofstream archRep("Reporte3.txt",ios::out);
    if(!archRep){
        cerr<<"ERROR ARCH OUT"<<endl;
        exit(1);
    }
    Matricula mat;
    mat.leerAlumnos(archAlumno);
    mat.leerCursosNotas(archNotas);
    mat.leerCursos(archCursos);
    mat.imprimirReporte(archRep);
    return 0;
}

