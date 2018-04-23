/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bib_Func_Preg1.h
 * Author: Arian Gallardo 20153227
 *
 * Created on 10 de octubre de 2017, 08:34 AM
 */

#ifndef BIB_FUNC_PREG1_H
#define BIB_FUNC_PREG1_H


inline void impLinea(char c);

template<typename T>
void incrementar(T *&lst, int n, int INC);
template<typename T>
void add(T *&lst, T x, int INC);
void split(char *linea, char **&tokens, int &n);
void leeCursos(int *&codCur, char **&cursos, int **&requisitos);
void imprimirCursos(int *codCur, char **cursos, int **requisitos);


#endif /* BIB_FUNC_PREG1_H */

