/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * * Author: Daniel Chapi Alejo
 * Codigo: 20140352
 */
#include "Tortuga.h"
#include "Tablero.h"
Tortuga::~Tortuga(){    
}
Tortuga:: Tortuga(){
    this->fila=0;
    this->columna=0;
    this->pluma=1;
    this->orientacion=0;
}
Tortuga::Tortuga(int fila, int columna, int pluma, int orientacion) :
fila(fila), columna(columna), pluma(pluma), orientacion(orientacion) {
}
void Tortuga::SetOrientacion(int orientacion) {
        this->orientacion = orientacion;
}

int Tortuga::GetOrientacion() const {
    return orientacion;
}

void Tortuga::SetPluma(int pluma) {
    this->pluma = pluma;
}

int Tortuga::GetPluma() const {
    return pluma;
}

void Tortuga::SetColumna(int columna) {
    this->columna = columna;
}

int Tortuga::GetColumna() const {
    return columna;
}

void Tortuga:: SetFila(int fila) {
    this->fila = fila;
}

int Tortuga::GetFila() const {
    return fila;
}    

void Tortuga:: dibujar(Tablero& table){
    table.pintar(this->pluma,this->fila,this->columna);
}
void Tortuga::girar_tortuga(int sentido_giro){
    if(sentido_giro==3){
        if(this->orientacion==0) this->orientacion=2;
        else if(this->orientacion==1) this->orientacion=3;
        else if(this->orientacion==2) this->orientacion=1;
        else if(this->orientacion==3) this->orientacion=0;
    }
    else if(sentido_giro==4){
        if(this->orientacion==0) this->orientacion=3;
        else if(this->orientacion==1) this->orientacion=2;
        else if(this->orientacion==2) this->orientacion=0;
        else if(this->orientacion==3) this->orientacion=1;
    }
}
int Tortuga::validar_movimiento(Tablero& table,int distancia){
    if(this->orientacion==0){
        int c= this->columna + distancia;
        table.validar(this->fila,c);
    }
    else if(this->orientacion==1){
        int c= this->columna - distancia;
        table.validar(this->fila,c);
    }
    else if(this->orientacion==2){
        int f= this->fila + distancia;
        table.validar(f,this->columna);
    }
    else if(this->orientacion==3){
        int f= this->fila - distancia;
        table.validar(f,this->columna);
    }
}
void Tortuga::mover(Tablero& table ,int distancia){
    if(this->orientacion==0){
        int c= this->columna + distancia;
        for(int i=0;i<distancia;i++){
            this->columna=this->columna+1;
            if(this->pluma==1) dibujar(table);
        }
        
        
    }
    else if(this->orientacion==1){
        int c= this->columna - distancia;
        for(int i=0;i<distancia;i++){
            this->columna=this->columna-1;
            if(this->pluma==1) dibujar(table);
        }
    }
    else if(this->orientacion==2){
        int f= this->fila + distancia;
        for(int i=0;i<distancia;i++){
            this->fila=this->fila+1;
            if(this->pluma==1) dibujar(table);
        }
    }
    else if(this->orientacion==3){
        int f= this->fila - distancia;
        for(int i=0;i<distancia;i++){
            this->fila=this->fila-1;
            if(this->pluma==1) dibujar(table);
        }
    }
    cout << "orientacion: " << this->orientacion;
    cout << "fila: "<< this->fila << "columna: " <<this->columna << endl;
}
void Tortuga::reset_tortuga(){
    this->fila=0;
    this->columna=0;
    this->pluma=1;
    this->orientacion=0;
    
}
void Tortuga::ejecutar_comando(Tablero& table,int* com){
    cout << "se ejecuta el comando:" << com[0]<< endl;
    if(*com==1) this->pluma=0;
    else if(*com==2) this->pluma=1;
    else if(*com==3) girar_tortuga(3);
    else if(*com==4) girar_tortuga(4);
    else if(*com==5){
        com=com+1;
        if(validar_movimiento(table,*com)) mover(table,*com);        
    }
    else if(*com==6){
        int f= *(com+1);
        int c= *(com+2);
        table.redimensionar(f,c);
    }
    else if(*com==7){
        cout << "Escriba el nombre del archivo donde se va a imprimir"<<endl;
        char arch[100];
        cin >> arch;
        ofstream archOut(arch,ios::out);
        table.imprimir(archOut);
    }
}
void Tortuga::procesar_archivo(ifstream& archIn,Tablero& table){
    int* com = new int[3];
    int dist=0;
    while(archIn >> com[0] ){
        int auxf= this->fila;
        int auxc= this->columna;
        if(com[0]==5) archIn>>com[1];
        else if(com[0]==6) archIn>>com[1]>>com[2];
        ejecutar_comando(table,com);
        
        int dist1= this->fila-auxf;
        int dist2= this->columna-auxc;
        if(dist1>0) dist+=dist1;
        else dist+=dist1*-1;
        if(dist2>0) dist+=dist2;
        else dist+=dist2*-1;
        
    }
    
    cout << dist;
    
}
