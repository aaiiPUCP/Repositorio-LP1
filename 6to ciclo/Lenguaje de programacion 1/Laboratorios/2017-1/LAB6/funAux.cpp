/*
 * Almendra Nuñez Calderon
 * 20120383
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define INC 5
#define MAX 5000

using namespace std;

void memoria_exacta(char ** input, char ** & output, int numElem){
    output = new char*[numElem+1];
    for(int i=0; i<numElem; i++){
        int size = strlen(input[i]) + 1;
        output[i] = new char[size];
        strcpy(output[i], input[i]);
    }
    output[numElem] = NULL;
}

void split_tokens(char * linea, char ** & palabras, int & numPal){
    numPal = 0;
    char * auxPal[200];
    if(!isblank(linea[0])){
        auxPal[numPal] = linea;
        numPal++;
    }
    for(int i=1; linea[i]; i++){
        if(!isblank(linea[i]) && (isblank(linea[i-1]) || linea[i-1] == '\0')){
            auxPal[numPal] = &linea[i];
            numPal++;
        }
        if(isblank(linea[i]) && !isblank(linea[i-1])){
            linea[i] = '\0';
        }
    }
    memoria_exacta(auxPal, palabras, numPal);
}

void split_tokens_delim(char * linea, char ** & palabras, int & numPal, char delim){
    numPal = 0;
    char * auxPal[200];
    if(linea[0] != delim){
        auxPal[numPal] = linea;
        numPal++;
    }
    for(int i=1; linea[i]; i++){
        if(linea[i] != delim && (linea[i-1] == delim || linea[i-1] == '\0')){
            auxPal[numPal] = &linea[i];
            numPal++;
        }
        if(linea[i] == delim && linea[i-1] != delim){
            linea[i] = '\0';
        }
    }
    memoria_exacta(auxPal, palabras, numPal);
}

void incrementar(char ** & lista, int cant){
    if(lista == NULL){
        lista = new char*[INC + 1];
        for(int i=0; i<=INC; i++) lista[i] = NULL;
    }
    else{
        char ** aux = new char*[cant + INC + 1];
        for(int i=0; i<cant; i++) aux[i] = lista[i];
        for(int i=cant; i<=cant + INC; i++) aux[i] = NULL;
        delete [] lista;
        lista = aux;
    }
}

void incrementar(void ** & lista, int cant){
    if(lista == NULL){
        lista = new void*[INC + 1];
        for(int i=0; i<=INC; i++) lista[i] = NULL;
    }
    else{
        void ** aux = new void*[cant + INC + 1];
        for(int i=0; i<cant; i++) aux[i] = lista[i];
        for(int i=cant; i<=cant + INC; i++) aux[i] = NULL;
        delete [] lista;
        lista = aux;
    }
}

void agregarDato(void ** & lista, int cant, void * dato){
    if(lista == NULL){
        incrementar(lista, cant);
        lista[0] = dato;
    }
    else{
        if(cant % INC == 0)
            incrementar(lista, cant);
        lista[cant] = dato;
    }
}

void agregarDato(char ** & lista, int cant, char * dato){
    if(lista == NULL){
        incrementar(lista, cant);
        lista[0] = dato;
    }
    else{
        if(cant % INC == 0)
            incrementar(lista, cant);
        lista[cant] = dato;
    }
}

char ** obtenerListaEtiquetas(char * cad){
    char ** lista = NULL;
    int cant = 0;
    
    char ** tokens;
    int numPal;
    split_tokens_delim(cad, tokens, numPal, ',');
    
    for(int i=0; i<numPal; i++){
        agregarDato(lista, cant, tokens[i]);
        cant++;
    }
    return lista;
}

int * obtenerImagen(char * linea, int total_pix){    
    int * lista = new int[total_pix+1];
    
    for(int i=0; i<total_pix; i++){
        if(linea[i] == '1')
            lista[i] = 1;
        else lista[i] = 0;
    }
    lista[total_pix] = -1;
    return lista;
}

void * obtenerDato(char ** tokens, int num){
    void ** reg = new void*[7];
    
    int * codigo = new int;
    *codigo = atoi(tokens[0]);
    
    int * altura = new int;
    int * ancho = new int;    
    char **tokens_Aux;
    int numPal;
    split_tokens_delim(tokens[num-2],tokens_Aux, numPal, '*');
    *altura = atoi(tokens_Aux[0]);
    *ancho = atoi(tokens_Aux[1]);
    
    int * total_pix = new int;
    *total_pix = (*altura)*(*ancho);        
    
    char ** listaEtiquetas = obtenerListaEtiquetas(tokens[2]);
    int * imagen = obtenerImagen(tokens[4], *total_pix);
    
    reg[0] = codigo;   
    reg[1] = altura;
    reg[2] = ancho;
    reg[3] = total_pix;
    reg[4] = tokens[1];
    reg[5] = listaEtiquetas;
    reg[6] = imagen;
    return reg;    
}

void leerImagenes(void * &imagenes){
    
    char linea[MAX];
    char ** tokens;
    int numPal;
    
    void ** imag = NULL;
    int num = 0;
    
    while(cin.getline(linea, MAX, '\n')){
        split_tokens(linea, tokens, numPal);
        void * dato = obtenerDato(tokens, numPal);
        agregarDato(imag, num, dato);
        num++;
    }
    imagenes = imag;
    
}

void impC(char c, int n){
    for(int i=0; i<n; i++) cout.put(c);
}

void impReg(void ** reg){
    int * codigo = (int *)reg[0];
    cout << "ID: " << setw(3) << *codigo;
    int * alto = (int *)reg[1];
    int * ancho = (int *)reg[2];
    int * total_pix = (int *)reg[3];
    cout.fill('0');
    cout << " | ALTO=" << setw(3) << *alto;
    cout << " | ANCHO=" << setw(3) << *ancho;
    cout << " | TOTAL PIXELES=" << setw(5) << *total_pix << endl;
    cout.fill(' ');
    char * nombre = (char *)reg[4];
    cout << "NOMBRE: " << nombre << endl;
    char ** lista_eti = (char**)reg[5];
    cout << "ETIQUETAS: ";
    for(int i=0; lista_eti[i]; i++) cout << "#" << lista_eti[i] << " ";
    cout << endl;
    impC('-', 60);
    cout << endl;
    int * imagen = (int*)reg[6];
    int cont = 0;
    for(int i=0; imagen[i] != -1; i++){
        if(imagen[i] == 0) cout << " ";
        else cout << "#";
        cont++;
        if(cont == *ancho){
            cout << endl;
            cont = 0;
        }
    }
}

void reporte(void * imagenes){
    cout << "REPORTE DE DIBUJOS" << endl;
    
    void ** img  = (void**)imagenes;
    for(int i=0; img[i]; i++){
        impC('-', 60);
        cout << endl;
        void ** reg = (void**)img[i];
        impReg(reg);
        //cout << endl;
    }
    
}

