//Karla Isabel Pedraza Salinas 20141056
//humming... https://www.youtube.com/watch?v=la1WfEr60yg
// 
#include <iostream>
#include <cstdio>
#include "auxiliar.h"
#define linea 115
using namespace std;

/*
 * 
 */

int main(int argc, char** argv) {
    int codigo,contImg,len,l,a;
    int dd,mm,aa,hh,min,seg;
    char c,h1,h2,lect;
    
    printf("REPORTE DE DIBUJOS\n");
    printCar('=',linea,1);
    lect=scanf("%d",&codigo);
    //Mientras se haya leído un código
    while(lect==1){
        //Inicializamos el contador de Imagenes por persona
        contImg=0;
        printf("ALUMNO %d: ",codigo);
        //Imprimimos el nombre de la persona hasta encontrar un ':'
        while((c=leerPalabra())!=':')
            if (c==' '||c=='\t') putchar(' ');
        printf("\n");
        printCar('-',linea,1);
        //Mientras no pueda leer un nuevo código
        while((lect=scanf("%d",&codigo))==0){
           //Aumento el contador de imágenes
            contImg++;
           printf("IMAGEN %d            EXT.             CREACION              MODIFICACION                 ETIQUETAS\n",contImg);
           //leemos el nombre de la imagen y su extensión
           len=procesaPalabra(); printCar(' ',20-len,0);
           len=procesaPalabra(); printCar(' ',11-len,0);
           //leemos la fecha y hora de creación en el formato
           scanf("%d/%d/%d %d:%d:%d%c%c",&dd,&mm,&aa,&hh,&min,&seg,&h1,&h2);
           //en caso sea PM cambiamos el valor de la hora
           if(c='P') hh+=12;
           //Imprimimos en el formato adecuado
           printf("%02d/%02d/%2d %02d:%02d:%02d     ",dd,mm,aa,hh,min,seg);
           //Lo mismo con la fecha y hora de creación
           scanf("%d/%d/%d %d:%d:%d%c%c",&dd,&mm,&aa,&hh,&min,&seg,&h1,&h2);
           if(c='P') hh+=12;
           printf("%02d/%02d/%2d %02d:%02d:%02d     ",dd,mm,aa,hh,min,seg);
           //Imprimimos las etiquetas hasta que se lea el ancho y alto
           while(scanf("%d*%d",&l,&a)==0){
               c=leerPalabra();
               if (c==' '||c=='\t')printf(" ");
               if (c==',')printf(", ");
           }
           printf("\n");
           printCar('-',linea,1);
           //Leemos la matriz y generamos las estadísticas
           leerMatriz(l,a);
           printCar('-',linea,1);

        }
    }
    return 0;
}

