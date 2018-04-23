/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Daniel Chapi Alejo
 * Codigo: 20140352
 *
 * Created on 9 de junio de 2017, 08:02 AM
 */

#include <cstdlib>
#include <fstream>
#include "Tablero.h"
#include "Tortuga.h"
using namespace std;

/*
 * 
 */
void pruebaTablero(ofstream& arch){
    Tablero table;
    int f,c;
   
    int pluma=1;
    f=0;
    c=0;
    if(table.validar(f,c)){
        table.pintar(pluma,f,c);
    }
    f=50;
    c=10;
    if(table.validar(f,c)){
        table.pintar(pluma,f,c);
    }
    table.imprimir(arch);
}


int main(int argc, char** argv) {
    ifstream archIn("tortuga.txt",ios::in);
    if(!archIn){
    	cerr << "error in" << endl;
    	exit(1);
    }
    ofstream arch("out.txt",ios::out);
    if(!arch){
        cerr<<"el archivo no se pudo abrir"<<endl;
        exit(1);
    }
    //pruebaTablero(arch); //PREGUNTA 1 
    Tortuga tort;
    Tablero tab;
    tort.procesar_archivo(archIn,tab);
    arch.close();
    return 0;
}

