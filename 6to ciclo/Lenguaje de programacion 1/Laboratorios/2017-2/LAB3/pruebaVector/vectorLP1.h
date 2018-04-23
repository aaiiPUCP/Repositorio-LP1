/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vectorLP1.h
 * Author: Arian Gallardo 20153227
 *
 * Created on 15 de septiembre de 2017, 08:40 AM
 */

#ifndef VECTORLP1_H
#define VECTORLP1_H


void suma(double*, double*, double*, int);

void resta(double*, double*, double*, int);

void prod_escalar(double, double*, double*, int);

double modulo (double*, int);

void vector_unitario(double*, double*, int);

double producto_punto(double*, double*, int);

double coseno_angulo(double*, double*, int);

void proyeccion (double*, double*, double*, int);

//4 sobrecargas 

void suma(double, double, double, double, double&, double&);

void resta(double, double, double, double, double&, double&);

void prod_escalar(double, double, double, double&, double&);

double modulo(double, double);



#endif /* VECTORLP1_H */

