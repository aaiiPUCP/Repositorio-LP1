/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   colaDePrioridadG.h
 * Author: 20141056 Karla Pedraza
 *
 * Created on 2 de junio de 2017, 09:50 AM
 */

#ifndef COLADEPRIORIDADG_H
#define COLADEPRIORIDADG_H

void* leePar();
int compInt(const void*elemA,const void*elemB);
void insertPQ(void *&pq,void *dato,int(*compara)(const void*,const void*));
void crearPQ(void *&pq,void *(*lee)(void),int(*compara)(const void*,const void*));
void impPar(int &num1,void* elem);
void printPQ(void *pq,void(*imprime)(int &,void*));
int isSep(char c);
void memExacta_str(char **input,char **&output,int numElem);
void splitTokens(char *linea,char **&palabras,int n);
void *leeReg();
int compReg(const void*elemA,const void*elemB);
void impReg(int &num,void* elem);

#endif /* COLADEPRIORIDADG_H */

