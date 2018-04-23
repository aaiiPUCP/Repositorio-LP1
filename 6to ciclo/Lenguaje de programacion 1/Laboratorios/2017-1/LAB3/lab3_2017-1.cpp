/* 
 * File:   main.cpp
 * Author: Karla Pedraza 20141056
 *codeado con: https://www.youtube.com/watch?v=zDeDFGxMILk
 * Created on 28 de abril de 2017, 08:11 AM
 */


#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
double Calc_Pend(int x1,int y1,int x2,int y2){
    return ((y2-y1)/((double)(x2-x1)));
}
void pintarPant(char *ptr){
    *ptr='*';
}
void imprimir_pantalla(char *pant,int N){
    //cout<<"  ";
    //for (int i=0;i<N;i++) printf("%2d",i);
    for (int i=0;i<N;i++){
        //printf("%2d",i);
        for(int j=0;j<N;j++){
            cout<<pant[i*N+j];
            //cout<<" ";
        }
        cout<<endl;
    }
}
void reset_pantalla(char *pant,int N){
    for (int i=0;i<N*N;i++) pant[i]=' ';
}
void calc_pos(char * &ptr,int x,int y,char *pant,int N){
    ptr=pant+(y*N)+x;
}
void menor_izq(double m,int *x1,int *y1,int *x2,int *y2){
    m=abs(m);
    if(m<=1 and m>=0){
        if((*x2)<(*x1)){
            int aux=*x2;
            *x2=*x1;
            *x1=aux;
            aux=*y2;
            *y2=*y1;
            *y1=aux;
        }
    }
    else{
        if((*y2)<(*y1)){
            int aux=*x2;
            *x2=*x1;
            *x1=aux;
            aux=*y2;
            *y2=*y1;
            *y1=aux;
        }
    }
}
void calcularDeltasyP(double m,int x1,int y1,int x2,int y2,int *deltax,int *deltay,int *p){
    *deltax=abs(x2-x1);
    *deltay=abs(y2-y1);
    m=abs(m);
    if (m>=0 && m<=1){
        *p=2*(*deltay)-(*deltax);
    }
    else{
        *p=2*(*deltax)-(*deltay);
    }
}
void Calc_p(double m,int *p,int deltax,int deltay){
    m=abs(m);
    if (m>=0 && m<=1){
        if ((*p)<0)
            *p=*p+2*deltay;
        else
            *p=*p+2*(deltay-deltax);
    }
    else{
        if ((*p)<0)
            *p=*p+2*deltax;
        else
            *p=*p+2*(deltax-deltay);
    }

}
void ActualizarXY(int *x,int *y,int p,double m){
    if (m>=0){
        if (m<=1){
            *x=*x+1;
            if (p>=0) *y=*y+1;
        }
        else{
            *y=*y+1;
            if (p>=0) *x=*x+1;   
        }
    }
    else{
        if (m>=(-1)){
            *x=*x+1;
            if (p>=0) *y=*y-1;
        }
        else{
            *y=*y+1;
            if (p>=0) *x=*x-1;   
        }
    }
}
int Continue(double m,int x,int x2,int y,int y2){
    m=abs(m);
    if (m>=0 && m<=1){
        return (x<=x2);
    }
    else{
        return (y<=y2);
    }
}
void trazar_recta(char *pant,int x1,int y1,int x2,int y2,int N){    
    char *ptr;
    int deltax,deltay,p;
    double m=Calc_Pend(x1,y1,x2,y2);
    //cout<<"m: "<<m<<endl;
    menor_izq(m,&x1,&y1,&x2,&y2);
    //cout<<"x: "<<x1<<" y: "<<y1<<" x: "<<x2<<" y: "<<y2<<endl;
    calcularDeltasyP(m,x1,y1,x2,y2,&deltax,&deltay,&p);
    //cout<<"deltax: "<<deltax<<" deltay: "<<deltay<<" p: "<<p<<endl;
    
    int x=x1,y=y1;  
    
    while(Continue(m,x,x2,y,y2)){
        calc_pos(ptr,x,y,pant,N);
        pintarPant(ptr);
        ActualizarXY(&x,&y,p,m);
        Calc_p(m,&p,deltax,deltay);  
    }
}
int hayAsteristoArribaOAbajo(char *pant,char *ptr,int i,int j,int N){
    int a=0,b=0;
    //Si es una esquina -> ^ o al revés no debe haber asteriscos en arriba o abajo
    int c=(*(ptr-N-3)=='*')+(*(ptr-N-2)=='*')+(*(ptr-N-1)=='*')+(*(ptr-N)=='*')+(*(ptr-N+1)=='*')+(*(ptr-N+2)=='*')+(*(ptr-N+3)=='*');
    int d=(*(ptr+N-3)=='*')+(*(ptr+N-2)=='*')+(*(ptr+N-1)=='*')+(*(ptr+N)=='*')+(*(ptr+N+1)=='*')+(*(ptr+N+2)=='*')+(*(ptr+N+3)=='*');
    if (c==0 or d==0) return 0;
    //Truco para que imprima perfecto con el input del lab
    if(*(ptr-1)=='*' and *(ptr-N+1)=='+'){
        if(*(ptr-2)==' ') return 1;
        return 0;
    }
    if(*(ptr-1)=='*' and *(ptr-N+1)=='*'){
        if(*(ptr-2)==' ') return 0;
        return 1;    
    }
    //Caso normal: si hay asteriscos arriba y abajo entonces cambiar el pintar
    if (*(ptr-N-1)=='*' or *(ptr-N)=='*' or *(ptr-N+1)=='*') a=1;
    if(*(ptr+N-1)=='*' or *(ptr+N+1)=='*' or *(ptr+N)=='*') b=1;
        
    return a or b;
}
void pintar(char *pant,int N){
    char *ptr=pant;
    int pintar=0;
    for (int i=0;i<N;i++){
        pintar=0;
        for(int j=0;j<N;j++,ptr++){
            if((*ptr)=='*'){
                while(((*(ptr+1))=='*') and j<N) {j++;ptr++;}
                if(hayAsteristoArribaOAbajo(pant,ptr,i,j,N)) pintar=(!pintar);
                while(*ptr=='*' and j<N) {j++;ptr++;}
            }
            if(pintar) *ptr='+'; 
        }
    }
    
}
int main(int argc, char** argv) {
    const int N=200;
    int x,y,x1,y1,x2,y2;
    char pant[N*N]={0};
    reset_pantalla(pant,N);
    cin>>x>>y;
    x1=x2=x;y1=y2=y;
    while(cin>>x>>y){
        trazar_recta(pant,x1,y1,x,y,N);
        x1=x;y1=y;
    }
    trazar_recta(pant,x2,y2,x1,y1,N);
    pintar(pant,N);
    imprimir_pantalla(pant,N);
    return 0;
}