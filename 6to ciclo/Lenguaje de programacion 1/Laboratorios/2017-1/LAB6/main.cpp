/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Almendra Nuñez C
 * 20120383
 *
 * Created on 26 de mayo de 2017, 08:00 AM
 */

#include <cstdio>
#include <cstdlib>
#include "funAux.h"

using namespace std;

int main(int argc, char** argv) {        
    void * imagenes;
    
    leerImagenes(imagenes);
    reporte(imagenes);
    
    return 0;
}

