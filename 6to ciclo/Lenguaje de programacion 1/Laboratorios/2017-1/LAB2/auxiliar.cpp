/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//Karla Isabel Pedraza Salinas
//20141056
#include "tipoStruct.h"
#include "auxiliarSobrecargas.h"
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
void ProcesaFechayHora(){
    int dd,mm,aa,hh,min,seg;
    char c,c2;
    std::cin>>dd;
    c=cin.get();
    cin>>mm;
    c=cin.get();
    cin>>aa;
    
    cin>>ws;
    cin>>hh;
    c=cin.get();
    cin>>min;
    c=cin.get();
    cin>>seg;
    cin>>c>>c2;
    if (c=='P')    hh+=12;
    if (hh==24) hh=0;
    cout<<right<<setw(2)<<setfill('0')<<dd<<'/';
    cout<<right<<setw(2)<<setfill('0')<<mm<<'/';
    cout<<right<<setw(2)<<setfill('0')<<aa<<' ';
    cout<<right<<setw(2)<<setfill('0')<<hh<<':';
    cout<<right<<setw(2)<<setfill('0')<<min<<':';
    cout<<right<<setw(2)<<setfill('0')<<seg;
}

char procesaPalabra(int &cont){
    char c;
    cin>>c;
    while(c!=' ' && c!='\t' && c!='.' && c!=':'){
        cout.put(c);
        cont++;
        c=cin.get();
    }
    return c;
}
void printCar(char c, int n,int b){
    for (int i=0;i<n;i++) cout.put(c);
    if (b==1) cout<<endl;
}

void procesaImagen(){
    int h,w,pintados=0,red=0,blue=0,green=0;
    double gry=0;
    char c;
    Pixel pix;
    cin>>w;c=cin.get();cin>>h;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>pix;
            red+=pix.R;
            blue+=pix.B;
            green+=pix.G;
            
            pix.Gray=0.21*pix.R+0.72*pix.G+0.07*pix.B;
            gry+=pix.Gray;
            
            if(pix.Gray<=90){
                cout<<"# ";
                pintados++;
            }
            else cout<<"  ";
        }
        cout<<endl;
    }
    
    cout<<"Tamano: "<<h<<'x'<<w<<"     ";
    cout<<"Total de pixeles: "<<h*w<<"     ";
    cout<<"Pixeles pintados: "<<pintados<<" ("<<setprecision(4)<<double(pintados)/(h*w)*100<<"%)"<<endl;
    
    cout<<"Promedios: Gray= "<<setw(3)<<setfill('0')<<int(round(gry/(h*w)));
    cout<<" R= "<<setw(3)<<setfill('0')<<int(round(red/(h*w)));
    cout<<" G= "<<setw(3)<<setfill('0')<<int(round(green/(h*w)));
    cout<<" B= "<<setw(3)<<setfill('0')<<int(round(blue/(h*w)))<<endl;
}
