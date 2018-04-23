/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Karla Isabel Pedraza Salinas 20141056
 *https://www.youtube.com/watch?v=9jK-NcRmVcw
 * Created on 11 de julio de 2017, 08:04 AM
 */

#include <cstdlib>
#include "Regular.h"
#include "Intercambio.h"
#include "Alumno.h"
#include <iostream>
#include <fstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Alumno* student;
    ifstream archAlumno("Alumnos.csv",ios::in);
    if(!archAlumno){
        cerr<<"ERROR ARCH IN"<<endl;
        exit(1);
    }
    ofstream archRep("Reporte1.txt",ios::out);
    if(!archRep){
        cerr<<"ERROR ARCH OUT"<<endl;
        exit(1);
    }
    char c;
    while(1){
        archAlumno>>ws;
        if(archAlumno.eof()) break;
        archAlumno>>c;archAlumno.get();
        if(c=='R')
            student=new Regular;
        else
            student=new Intercambio;
        student->leerDatos(archAlumno);
        student->imprimirDatos(archRep);
        archRep<<endl;
    }
    return 0;
}

