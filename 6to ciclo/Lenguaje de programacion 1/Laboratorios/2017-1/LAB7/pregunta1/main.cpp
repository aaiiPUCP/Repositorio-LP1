/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Karla Isabel Pedraza Salinas
 *
 * Created on 2 de junio de 2017, 08:05 AM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cctype>
#include <iomanip>
#include <fstream>
#include "colaDePrioridadG.h"
//Mi código sí compila con todo en el main :'c
using namespace std;
int main(int argc, char** argv) {
    void *pq=NULL;
    //crearPQ(pq,leePar,compInt);
    //printPQ(pq,impPar);
    crearPQ(pq,leeReg,compReg);
    printPQ(pq,impReg);
    
    return 0;
}

