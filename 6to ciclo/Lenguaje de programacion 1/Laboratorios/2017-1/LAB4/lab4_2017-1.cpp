/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * Karla Isabel Pedraza Salinas 20141056
 * Hey, chill out
 *codeado con: https://www.youtube.com/watch?v=woqVai-V3_4
 */

#include <iostream>
#define INC 5
using namespace std;
template<typename T>
void incrementar(T* &datos,int numDatos,int &size){
    if(datos==NULL) datos=new T[INC];
    else{
        T *auxDatos=new T[size+INC];
        for(int i=0;i<numDatos;i++) auxDatos[i]=datos[i];
        delete []datos;
        datos=auxDatos;
    }
    size+=INC;
}
void desplazar(int *&ini,int *&fin,int *&anexo,double *&tiempo,int &numAnexo,int &size2,int indice,int numUnidad){
   if(numAnexo==size2){
       int s=size2;
        incrementar(anexo,numAnexo,s);
        incrementar(tiempo,numAnexo,size2);
    }
   for(int i=numAnexo;i>fin[indice];i--){
       anexo[i]=anexo[i-1];
       tiempo[i]=tiempo[i-1];
   }
   //fin[indice]++;
   for(int i=indice+1;i<numUnidad;i++){
       ini[i]++;
       fin[i]++;
   }
}
int UnidadEnArreglo(int *unidad,int auxUni,int numUnidad){
    for(int i=0;i<numUnidad;i++){
        if(unidad[i]==auxUni) return i;
    }
    return -1;
}
void leerDatos(int *&unidad,int *&ini,int *&fin,int *&anexo,double *&tiempo,int &numUnidad,int &numAnexo){
    unidad=NULL;anexo=NULL;tiempo=NULL;ini=NULL;fin=NULL;
    int sizeU=0,size2=0;
    int indice,indDesplazar;
    int auxUni,auxAne; double auxTiempo;
    while(cin>>auxUni>>auxAne>>auxTiempo){
        if((indice=UnidadEnArreglo(unidad,auxUni,numUnidad))!=-1){   
            indDesplazar=fin[indice]+1;
            desplazar(ini,fin,anexo,tiempo,numAnexo,size2,indice,numUnidad);
            numAnexo++;
            fin[indice]++;
            anexo[indDesplazar]=auxAne;
            tiempo[indDesplazar]=auxTiempo;
        }
        else{
            if(numUnidad==sizeU){
                int s1,s2;s1=sizeU;s2=sizeU;
                incrementar(unidad,numUnidad,s1);
                incrementar(ini,numUnidad,s2);
                incrementar(fin,numUnidad,sizeU);
            }
            unidad[numUnidad]=auxUni;
            if(numAnexo==size2){
                int s=size2;
                incrementar(anexo,numAnexo,s);
                incrementar(tiempo,numAnexo,size2);
            }
            ini[numUnidad]=numAnexo;
            fin[numUnidad++]=numAnexo;
            anexo[numAnexo]=auxAne;
            tiempo[numAnexo++]=auxTiempo;  
        }       
    }
    return;
}
void imprimirDatos(int *unidad,int *ini,int *fin,int *anexo,double *tiempo,int numUnidad,int numAnexo){
    for(int i=0;i<numUnidad;i++){
        cout<<i+1<<") Unidad: "<<unidad[i]<<endl;
        cout<<"   Indice inicial: "<<ini[i]<<endl;
        cout<<"   Indice final: "<<fin[i]<<endl;
        cout<<"   Llamadas:"<<endl;
        cout<<"   Anexo       Tiempo"<<endl;
        for(int j=ini[i];j<=fin[i];j++)
            cout<<"   "<<j-ini[i]+1<<") "<<anexo[j]<<"     "<<tiempo[j]<<endl;
    }
}

void desplazarAnexo(int *ini,int *fin,int *&anexo,double *&tiempo,int &numAnexo,int indiceUnidad,int indiceDesplazar,int numUnidad){
   for(int i=indiceDesplazar;i<numAnexo;i++){
       anexo[i]=anexo[i+1];
       tiempo[i]=tiempo[i+1];
   }
   numAnexo--;
   fin[indiceUnidad]--;
   for(int i=indiceUnidad+1;i<numUnidad;i++){
       ini[i]--;fin[i]--;
   }

}
void reajustar(int *&anexo,double *&tiempo,int numAnexo){
    int *auxanexo= new int[numAnexo];
    double *auxtiempo= new double[numAnexo];
    for(int i=0;i<numAnexo;i++){
        auxanexo[i]=anexo[i];
        auxtiempo[i]=tiempo[i];
    }
    delete []anexo;
    delete []tiempo;
    anexo=auxanexo;
    tiempo=auxtiempo;
}
void deleteAnexosRepetidos(int *ini,int *fin,int *&anexo,double *&tiempo,int numUnidad,int &numAnexo){
    for(int i=0;i<numUnidad;i++){
        for(int j=ini[i];j<fin[i];j++){
            int unico=anexo[j];
            for(int k=j+1;k<=fin[i];k++){
                if(anexo[k]==unico){
                    tiempo[j]+=tiempo[k];
                    desplazarAnexo(ini,fin,anexo,tiempo,numAnexo,i,k,numUnidad);
                    k--;
                }
            }
               
        }    
    }
    reajustar(anexo,tiempo,numAnexo);
}
int main(int argc, char** argv) {
    int *unidad,*ini,*fin,*anexo;
    int numUnidad=0,numAnexo=0;
    double *tiempo;
    leerDatos(unidad,ini,fin,anexo,tiempo,numUnidad,numAnexo);
    deleteAnexosRepetidos(ini,fin,anexo,tiempo,numUnidad,numAnexo);    
    imprimirDatos(unidad,ini,fin,anexo,tiempo,numUnidad,numAnexo);
    return 0;
}

