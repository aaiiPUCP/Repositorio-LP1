/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 10 de noviembre de 2017, 08:05 AM
 */

#include <iostream>
#include "Cadena.h"

using namespace std;

#define MAX_CAR 60

inline void impLinea(){
    for(int i = 0 ; i < MAX_CAR; i++) cout << "-";
    cout << endl;
}

int main() {
    Cadena cad01;
    cout << "Prueba de la libreria Cadena.h // Arian Gallardo" << endl;
    impLinea();
    
    cout << "Inicializacion" << endl;
    impLinea();
    cout << "Cadena Inicializada con Constructor \"Cadena cad01\":" << endl;
    cout << "La cadena es nula? " << ((cad01.getCadena()) ? "NO" : "SI") << endl;
    cout << "Longitud de la cadena: " << cad01.length() << endl;
    cout << "Capacidad de la cadena: " << cad01.getCapacidad() << endl;
    impLinea();
    Cadena cad02("Ana Roncal");
    cout << "Cadena Inicializada con Constructor \"Cadena cad02(const char*)\":" << endl;
    cout << "La cadena es: " << (cad02.getCadena()) << endl;
    cout << "Longitud de la cadena: " << cad02.length() << endl;
    cout << "Capacidad de la cadena: " << cad02.getCapacidad() << endl;
    impLinea();
    Cadena cad03(10);
    cout << "Cadena Inicializada con Constructor \"Cadena cad03(const int)\":" << endl;
    cout << "La cadena es: " << (cad03.getCadena()) << endl;
    cout << "Longitud de la cadena: " << cad03.length() << endl;
    cout << "Capacidad de la cadena: " << cad03.getCapacidad() << endl;
    impLinea();
    Cadena cad04 = cad02;
    cout << "Cadena Inicializada con Constructor \"Cadena cad04 = cad02\":" << endl;
    cout << "La cadena es: " << (cad04.getCadena()) << endl;
    cout << "Longitud de la cadena: " << cad04.length() << endl;
    cout << "Capacidad de la cadena: " << cad04.getCapacidad() << endl;
    impLinea();
    
    cout <<"Asignacion" << endl;
    impLinea();
    Cadena cad;
    cad.assign("Valentina");
    cout << "Cadena asignada: " << cad.getCadena() << endl;
    cout << "Longitud de la cadena: " << cad.length() << endl;
    cout << "Capacidad de la cadena: " << cad.getCapacidad() << endl;
    impLinea();
    cad.assign(cad02);
    cout << "Cadena asignada: " << cad.getCadena() << endl;
    cout << "Longitud de la cadena: " << cad.length() << endl;
    cout << "Capacidad de la cadena: " << cad.getCapacidad() << endl;
    impLinea();
    cad = "Valentina";
    cout << "Cadena asignada: " << cad.getCadena() << endl;
    cout << "Longitud de la cadena: " << cad.length() << endl;
    cout << "Capacidad de la cadena: " << cad.getCapacidad() << endl;
    impLinea();
    cad = cad02;
    cout << "Cadena asignada: " << cad.getCadena() << endl;
    cout << "Longitud de la cadena: " << cad.length() << endl;
    cout << "Capacidad de la cadena: " << cad.getCapacidad() << endl;
    impLinea();
    
    cout <<"Agregacion" << endl;
    impLinea();
    cad.assign("Hola soy ");
    cad.append("Valentina");
    cout << "Cadena asignada: " << cad.getCadena() << endl;
    cout << "Longitud de la cadena: " << cad.length() << endl;
    cout << "Capacidad de la cadena: " << cad.getCapacidad() << endl;
    impLinea();
    cad.assign("Hola soy ");
    cad += cad02;
    cout << "Cadena asignada: " << cad.getCadena() << endl;
    cout << "Longitud de la cadena: " << cad.length() << endl;
    cout << "Capacidad de la cadena: " << cad.getCapacidad() << endl;
    impLinea();
    
    cout << "Concatenacion" << endl;
    impLinea();
    Cadena aux(" es una buena profesora.");
    cad = cad02 + aux;
    cout << "Cadena asignada: " << cad.getCadena() << endl;
    cout << "Longitud de la cadena: " << cad.length() << endl;
    cout << "Capacidad de la cadena: " << cad.getCapacidad() << endl;
    impLinea();
    
    cout << "Comparacion" << endl;
    impLinea();
    aux = "Ana Roncla";
    cad = "Ana Roncal";
    cout << "Comparando con metodo compare " << aux.getCadena() << " y " << "Naomi" << ": " << aux.compare("Naomi") << endl;
    impLinea();
    cout << "Comparando con metodo compare " << aux.getCadena() << " y " << cad.getCadena() << ": " << aux.compare(cad) << endl;
    impLinea();
    cout << "Comparando con == " << aux.getCadena() << " y " << cad.getCadena() << ": " << (aux == cad) << endl;
    impLinea();
    cout << "Comparando con >" << aux.getCadena() << " y " << cad.getCadena() << ": " << (aux > cad) << endl;
    impLinea();
    cout << "Comparando con <" << aux.getCadena() << " y " << cad.getCadena() << ": " << (aux < cad) << endl;
    impLinea();
    
    cout << "Otros metodos" << endl;
    impLinea();
    cout << "Longitud de la cadena cad: " << cad.length() << endl;
    impLinea();
    aux = "Miguel Guanira";
    cout << "Usaremos el metodo swap: " << endl;
    cout << "Cadena asignada en cad: " << cad.getCadena() << endl;
    cout << "Longitud de la cadena cad: " << cad.length() << endl;
    cout << "Capacidad de la cadena cad: " << cad.getCapacidad() << endl;
    cout << endl;
    cout << "Cadena asignada en aux: " << aux.getCadena() << endl;
    cout << "Longitud de la cadena aux: " << aux.length() << endl;
    cout << "Capacidad de la cadena aux: " << aux.getCapacidad() << endl;
    cout << "LET'S SWAP!" << endl;
    cad.swap(aux);
    cout << "Cadena asignada en cad: " << cad.getCadena() << endl;
    cout << "Longitud de la cadena cad: " << cad.length() << endl;
    cout << "Capacidad de la cadena cad: " << cad.getCapacidad() << endl;
    cout << endl;
    cout << "Cadena asignada en aux: " << aux.getCadena() << endl;
    cout << "Longitud de la cadena aux: " << aux.length() << endl;
    cout << "Capacidad de la cadena aux: " << aux.getCapacidad() << endl;
    impLinea();
    cout << "Imprimiendo la cadena cad con el metodo PRINT: ";
    cad.print();
    return 0;
}

