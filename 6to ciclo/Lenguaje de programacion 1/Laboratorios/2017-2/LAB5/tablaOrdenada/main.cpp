/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Arian Gabriel Gallardo Callalli 20153227
 *
 * Created on 29 de septiembre de 2017, 08:09 AM
 */

#include <iostream>
#include "funcionesPreg1.h"

using namespace std;

int main() {
    char **datos, **indicador;
    int *indices;
    
    leeYCrearTablas(datos, indices, indicador);
    imprimeOrdenado(datos, indices, indicador);
    return 0;
}

