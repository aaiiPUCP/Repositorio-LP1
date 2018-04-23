/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * 20141056 Pedraza Salinas Karla
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cctype>
#include <iomanip>
#include <fstream>
#include "colaDePrioridadG.h"
using namespace std;

/*
 * 
 */
void* leePar(){
    int auxprior,auxnum;
    char c;
    if(!(cin>>auxprior>>c>>auxnum)) return NULL;
    int *prior=new int;
    int *elem=new int;
    *prior=auxprior;
    *elem=auxnum;
    void **par=new void*[2];
    par[0]=prior;
    par[1]=elem;
    return par;
}
int compInt(const void*elemA,const void*elemB){
    void**valorA=(void**)elemA;
    int *priorA=(int*)(valorA[0]);
    void**valorB=(void**)elemB;
    int *priorB=(int*)(valorB[0]);
    return (*priorA-*priorB);
}
void insertPQ(void *&pq,void *dato,int(*compara)(const void*,const void*)){
    void **nuevoNodo=new void*[2];
    nuevoNodo[0]=dato;
    if(pq==NULL){
        pq=nuevoNodo;
        nuevoNodo[1]=NULL;
    }
    else{
        void **recNodo=(void**)pq;
        void **nodoAnt=NULL;
        while(recNodo!=NULL){
            if((compara(recNodo[0],nuevoNodo[0]))<0)break;
            nodoAnt=recNodo;
            recNodo=(void**)recNodo[1];
        }
        if(nodoAnt==NULL)
            pq=nuevoNodo;
        else
            nodoAnt[1]=nuevoNodo;
        nuevoNodo[1]=recNodo;
    }
}
void crearPQ(void *&pq,void *(*lee)(void),int(*compara)(const void*,const void*)){
    while(1){
        void*dato=lee();
        if (dato==NULL) break;
        insertPQ(pq,dato,compInt);
    }
}
void impPar(int &num1,void* elem){
    void **reg=(void**)elem;
    int *prior=(int*)reg[0];
    int *num=(int*)reg[1];
    cout<<"("<<*prior<<", "<<*num<<")"<<endl;
}
void printPQ(void *pq,void(*imprime)(int &,void*)){
    int cont=1;
    void**recNodo=(void**)pq;
    int tiempo=0;
    while(1){
        if(recNodo==NULL) break;
        cout<<cont++<<". "<<endl;
        imprime(tiempo,recNodo[0]);
        recNodo=(void**)recNodo[1];
    }
}
int isSep(char c){
    if(isblank(c) or c==',') return 1;
    return 0;
}
void memExacta_str(char **input,char **&output,int numElem){
    output=new char*[numElem+1];
    for(int i=0;i<numElem;i++){
        int size=strlen(input[i])+1;
        output[i]=new char[size];
        strcpy(output[i],input[i]);
    }
    output[numElem]=NULL;
}
void splitTokens(char *linea,char **&palabras,int n){
    int numPal=0;
    char *auxPal[100];
    if(!isSep(linea[0])){
        auxPal[numPal]=linea;
        numPal++;
    }
    for(int i=1;linea[i]!='\0';i++){
        if(!isSep(linea[i])and(isSep(linea[i-1])or linea[i-1]=='\0')){
            auxPal[numPal]=&linea[i];
            numPal++;
        }
        if(isSep(linea[i]) and !isSep(linea[i-1]))
            linea[i]='\0';
        if(numPal==n) break;
    }
    memExacta_str(auxPal,palabras,numPal);
}
void *leeReg(){
    char aux[300];
    if(!cin.getline(aux,300,'\n')or strlen(aux)==0) return NULL;
    char**tokens;int numTok=0;
    splitTokens(aux,tokens,-1);
    for(;tokens[numTok];numTok++);
    
    char* dni=tokens[0];
    char* cond=tokens[numTok-1];
    
    int* tiempo=new int;
    *tiempo=atoi(tokens[numTok-2]);
    
    int lenNomb=0;
    for(int i=1;i<numTok-2;i++) lenNomb+=strlen(tokens[i])+1;
    
    char *nombre=new char[lenNomb];
    strcpy(nombre,tokens[1]);
    for(int i=2;i<numTok-2;i++){
        strcat(nombre," ");
        strcat(nombre,tokens[i]);
    }
    //reg
    void**reg=new void*[5];
    int *prior=new int;
    *prior=strcmp(cond,"embarazada")*5+strcmp(cond,"anciano")*4+strcmp(cond,"discapacitado")*3+strcmp(cond,"bebe")*2+strcmp(cond,"normal")*1;
    reg[0]=prior;
    reg[1]=dni;
    reg[2]=nombre;
    reg[3]=tiempo;
    reg[4]=cond;
    return reg;
}
int compReg(const void*elemA,const void*elemB){
    void**valorA=(void**)elemA;
    int *priorA=(int*)(valorA[0]);
    
    void**valorB=(void**)elemB;
    int *priorB=(int*)(valorB[0]);
    return (*priorA-*priorB+1);
}
void impReg(int &num,void* elem){
    void **reg=(void**)elem;
    char *dni=(char*)reg[1];
    char *nombre=(char*)reg[2];
    int *tiempo=(int*)reg[3];
    char *cond=(char*)reg[4];
    
    cout<<"  Dni:"<<*dni<<endl;
    cout<<"  Nombre:"<<nombre<<endl;
    cout<<"  Tiempo de transaccion:"<<*tiempo<<endl;
    cout<<"  Condicion:"<<cond<<endl;
    num+=*tiempo;
    cout<<"  Tiempo que permaneció en la cola:"<<num<<endl;     
}