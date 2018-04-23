/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//Karla Isabel Pedraza Salinas
//20141056
//La La Lab https://www.youtube.com/watch?v=MmKlaGpmYig
/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 21 de abril de 2017, 08:07 AM
 */

#include <iostream>
#include <iomanip>
#include "auxiliar.h"
#include "auxiliarSobrecargas.h"
#include "tipoStruct.h"
#define MAX 100
using namespace std;

int main(int argc, char** argv) {
    int codigo,cont;
    char c,c2,c3;
    cout<<"REPORTE DE DIBUJOS"<<endl;
    printCar('=',MAX,1);
    c2=cin.peek();
    while(!cin.eof() && isdigit(c2)){
        cin>>codigo;
        cout<<"ALUMNO "<<codigo<<": ";
        cont=0;
        while(procesaPalabra(cont)!=':'){
            cout.put(' ');
        }
        cout<<endl;
        int nimagen=0;
        
        c2=cin.peek();
        while(!cin.eof() && !isdigit(c2)){
            nimagen++;
            printCar('-',MAX,1);
            cout<<"IMAGEN ";
            cout<<left<<setfill(' ')<<setw(13)<<nimagen;
            cout<<setfill(' ')<<setw(21)<<left<<"EXT.";
            cout<<setfill(' ')<<setw(21)<<left<<"CREACION";
            cout<<"MODIFICACION"<<endl;
            cont=0;procesaPalabra(cont);
            printCar(' ',20-cont,0);
            cont=0;procesaPalabra(cont);
            printCar(' ',15-cont,0);
            ProcesaFechayHora();
            printCar(' ',5,0);
            ProcesaFechayHora();
            cout<<endl;
            printCar('-',MAX,1);
            procesaImagen();
            cin>>ws;
            c2=cin.peek();
        }
        //cin.clear();
        printCar('-',MAX,1);
        
    }
    return 0;
}

