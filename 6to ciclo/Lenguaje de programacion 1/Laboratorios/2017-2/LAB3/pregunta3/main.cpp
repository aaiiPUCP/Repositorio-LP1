/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Arian Gallardo 20153227
 *
 * Created on 15 de septiembre de 2017, 09:12 AM
 */

#include <iostream>
#include <iomanip>
#include "vectorLP1.h"

using namespace std;

int main() {
    const int N = 5;
    const double EPS = 1e-5; //Precision
    int x;
    double V[N], A[N], X[N], Y[N]; //X es el mas lejano y Y el mas cercano
    while(cin >> V[0]){
        for(int i = 1 ; i < N; i++) cin >> V[i];
        cin >> x;

        cout << fixed << setprecision(2) << setw(4) << "V(";
        for(int i = 0 ; i < N; i++) cout << fixed << setprecision(2) << setw(6) << V[i];
        cout << ")";
        cout << fixed << setprecision(2) << setw(12) << "||V|| = " << setw(6) << modulo(V,N) << endl;

        double low = 100; //El coseno solo tiene rango de -1 a 1, asi que consideramos un valor grande para calcular el menor al inicio
        double high = -100; //Analogamente para el valor mayor
        for(int tst = 0; tst < x; tst ++){
            for(int i = 0 ; i < N; i++) cin >> A[i];
            double coseno = coseno_angulo(V,A,N);
            if(coseno + EPS< low ){
                for(int i = 0; i < N; i++) X[i] = A[i];
                low = coseno;
            }
            if(coseno> high + EPS){
                for(int i = 0 ; i < N; i++) Y[i] = A[i];
                high = coseno;
            }
        }
        
        cout << fixed << setprecision(2) << setw(4) << "A(";
        for(int i = 0 ; i < N; i++) cout << fixed << setprecision(2) << setw(6) << Y[i];
        cout << ")";
        cout << fixed << setprecision(2) << setw(12) << "||A|| = " << setw(6) << modulo(Y,N) << setw(12) << "cos(VA) = " << setw(6) << high << endl;

        cout << fixed << setprecision(2) << setw(4) << "B(";
        for(int i = 0 ; i < N; i++) cout << fixed << setprecision(2) << setw(6) << X[i];
        cout << ")";
        cout << fixed << setprecision(2) << setw(12) << "||B|| = " << setw(6) << modulo(X,N) << setw(12) << "cos(VB) = " << setw(6) << low << endl;
        cout << endl;
    }
    return 0;
}

