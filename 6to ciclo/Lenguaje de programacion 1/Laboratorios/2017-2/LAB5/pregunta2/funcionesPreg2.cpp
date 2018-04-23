/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * Author: Arian Gallardo 20153227
 */

void fit(char ** input, char **&output, int numDatos){
    output = new char**[numDatos];
    for(int i = 0 ; i < numDatos ; i ++){
        output[i] = new char[strlen(input[i]) + 1];
        strcpy(output[i], input[i]);
    }
}

void split(char *linea, char **&lstStr, int &numStr){
    numStr = 0;
    char *auxLstStr[100];
    if(!isblank(linea[0])){
        auxLstStr[numStr] = linea; numStr++;
    }
    for(int i = 1; linea[i] != '\0'; i++){
        if(!isblank(linea[i]) &&(isblank(linea[i-1]) || linea[i-1] == '\0')){
            auxLstStr[numStr] = &linea[i];
            numStr++;
        }
        if(isblank(linea[i]) && (!isblank(linea[i-1]) && linea[i-1] != '\0')){
            linea[i] = '\0';
        }
    }
    fit(auxLstStr, lstStr, numStr);
}
