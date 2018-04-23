//Karla Isabel Pedraza Salinas 20141056
#include <iostream>
#include <cstdio>
#include "auxiliar.h"
char leerPalabra(){
    char c;
    scanf(" %c",&c);
    while(c!=' ' && c!=EOF && c!='\t' && c!='\n' && c!='.' && c!=':' && c!=','){
        putchar(c);
        c= getchar();
    }
    return c;
}
void printCar(char c,int n,int a){
    int i;
    for (i=0;i<n;i++) putchar(c);
    //El último parámetro me sirve para saber si al final quiero imprimir un salto de línea
    if (a==1) printf("\n");
}
int procesaPalabra(){
    char c;
    int count=0,fin;
    fin=scanf(" %c",&c);
    if (fin==EOF || fin==0) return 0;
    while(c!=' ' && c!='\t' && c!='.'){
        count++;
        putchar(c);
        c=getchar();
    }
    return count;
}
void leerMatriz(int l,int a){
    //inicializo el valor del contador de pixeles
    int i,j,contpix=0,n;
    for(i=0;i<a;i++){
        for(j=0;j<l;j++){
            scanf(" %1d",&n);
            //printf("%d",j);
            //Si es cero imprimo el trazo
            if (n==0){
                putchar('#');
                //y aumento el valor de los pinteles pintados
                contpix++;
            }
            else
                putchar(' ');
            putchar(' ');
        }
        printf("\n");
    }
    //calculo el porcentaje con el contador y el total
    float porcentaje=(float(contpix))/(l*a)*100;
    printf("Tamaño: %d*%d      Total de pixeles: %5d    Pixeles pintados: %5d (%.2f",l,a,l*a,contpix,porcentaje);
    putchar('%');printf(")\n");
}