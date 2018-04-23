#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

void memExacta(char ***input, char***&output, int numElem){
    output = new char**[numElem+1];
    for(int i = 0; i < numElem; i++){
        output[i] = input[i];
    }
    output[numElem] = NULL;
}

void memExacta(char **input, char**&output, int numElem){
    output = new char*[numElem+1];
    for(int i = 0; i < numElem; i++){
        int size = strlen(input[i]) + 1;
        output[i] = new char[size];
        strcpy(output[i],input[i]);
    }
    output[numElem] = NULL;
}

bool isSeparador(char c){
    if( isblank(c) or c == ',' or c == '.' or c == ':' or c == ';' or c == '(' or c == ')' or c == '?')
        return true;
    else return false;
}

void splitTokens(char *linea, char **&palabras, int n = -1){
    int numPal = 0;
    char *auxPal[5000];
    if(!isSeparador(linea[0])){
        auxPal[numPal] = linea;
        numPal++;
    }
    for(int i = 1; linea[i] != '\0'; i++){
        if(!isSeparador(linea[i]) and ( isSeparador(linea[i-1]) or linea[i-1] == '\0' ) ){
            auxPal[numPal++] = &linea[i];
        }
        if(isSeparador(linea[i]) and !isSeparador(linea[i-1]) )
            linea[i] = '\0';
        if(numPal == n) break;
    }
    memExacta(auxPal,palabras,numPal);
}

bool pertenece(char *word, char **palabras, int numElem){
    for(int i = 0; i < numElem; i++)
        if( strcmp(word,palabras[i]) == 0 ) return true;
    return false;
}

void cambiar(char**palabras,int i, int j){
    char *aux;
    aux=palabras[i];
    palabras[i] = palabras [j];
    palabras[j] = aux;
} 

void quicksort(char**palabras,int izq, int der){
    int limite;
    if (izq>=der) return;
    cambiar(palabras,izq,(izq+der)/2);
    limite= izq;
    for(int i=izq+1; i <=der; i++)
        if(strcmp(palabras[i],palabras[izq]) < 0)
            cambiar(palabras,++limite,i);
    cambiar(palabras,izq, limite);
    quicksort(palabras,izq,limite-1);
    quicksort(palabras, limite+1, der);
}


void leerTweets(char ***&tweets, char **&users, char **&hashtags){
    char linea[5000];
    char **auxTweets[5000],*auxUsers[5000],*auxHash[5000];
    int numTw = 0, numUsers = 0, numHash = 0;
    while(cin.getline(linea,5000,'\n')){
        if(strcmp(linea,"0") == 0) break;
        char **palabras;
        splitTokens(linea,palabras,2);
        auxTweets[numTw] = new char*[2];
        auxTweets[numTw][0] = palabras[0];
        auxTweets[numTw][1] = palabras[1];
        numTw++;
        strcpy(linea,palabras[1]);
        delete []palabras;
        splitTokens(linea,palabras);
        for(int i = 0; palabras[i] != NULL; i++){
            if(palabras[i][0] == '#'){
                if(!pertenece(palabras[i],auxHash,numHash)){
                    auxHash[numHash++] = palabras[i];
                }
            }else if(palabras[i][0] == '@'){
                if(!pertenece(palabras[i],auxUsers,numUsers)){
                    auxUsers[numUsers++] = palabras[i];
                }
            }else delete [] palabras[i];
        }
    }
    memExacta(auxUsers,users,numUsers);
    memExacta(auxHash,hashtags,numHash);
    memExacta(auxTweets,tweets,numTw);
    quicksort(users,0,numUsers-1);
    quicksort(hashtags,0,numHash-1);
}

void reporteLectura(char ***tweets,char **users, char**hashtags){
    int numTw = 0, numUsers = 0, numHash = 0;
    while( tweets[numTw] != NULL ) numTw++;
    while( users[numUsers] != NULL ) numUsers++;
    while( hashtags[numHash] != NULL ) numHash++;
    cout << "Total de tweets: " << numTw << endl;
    cout << "Total de usuarios mencionados: " << numUsers << endl;
    cout << "Lista de usuarios: " << endl;
    for(int i = 0; i < numUsers; i++)
        cout << users[i] << " ";
    cout << endl;
    // hashtags
    cout << "Total de hashtags: " << numHash << endl;
    cout << "Lista de hashtags: " << endl;
    for(int i = 0; i < numHash; i++)
        cout << hashtags[i] << " ";
    cout << endl;
}
/*
bool estaEnTweet(char *word, char*linea){
    char **palabras;
    splitTokens(linea,palabras);
    for(int i = 0; palabras[i] != NULL; i++){
        if(strcmp(palabras[i],word) == 0) return true;
    }
    return false;
}*/

bool estaEnTweet(char *word, char *tweet){
    int l1 = strlen(word);
    int l2 = strlen(tweet);
    for(int i = 0; i <= l2-l1; i++){
	if(tweet[i] == word[0])
            for(int j = 1; j < l1 and tweet[i+j] == word[j]; j++)
                if(j == l1-1) return true;
    }
    return false;
}

void generarIndices(char ***tweets,char **users, char **hashtags, int**&indexUsers, int**&indexHashtags){
    int numTw = 0, numUsers = 0, numHash = 0;
    while(tweets[numTw] != NULL) numTw++;
    while(users[numUsers] != NULL) numUsers++;
    while(hashtags[numHash] != NULL) numHash++;
    indexUsers = new int*[numUsers+1];
    indexHashtags = new int*[numHash+1];
    indexUsers[numUsers] = NULL;
    indexHashtags[numHash] = NULL;
    char auxLinea[5000];
    for(int i = 0; i < numUsers; i++){
        int aux[5000], cant = 0;
        for(int j = 0; j < numTw; j++){
            strcpy(auxLinea,tweets[j][1]);
            if( estaEnTweet(users[i],auxLinea) )
                aux[cant++] = j;
        }
        indexUsers[i] = new int[cant+1];
        for(int j = 0; j < cant; j++)
            indexUsers[i][j] = aux[j];
        indexUsers[i][cant] = -1;
    }
    
    for(int i = 0; i < numHash; i++){
        int aux[5000], cant = 0;
        for(int j = 0; j < numTw; j++){
            strcpy(auxLinea,tweets[j][1]);
            if( estaEnTweet(hashtags[i],auxLinea) )
                aux[cant++] = j;
        }
        indexHashtags[i] = new int[cant+1];
        for(int j = 0; j < cant; j++)
            indexHashtags[i][j] = aux[j];
        indexHashtags[i][cant] = -1;
    } 
    
    for(int i = 0; i < numUsers; i++){
        cout << users[i] << endl;
        for(int j = 0; indexUsers[i][j] != -1; j++)
            cout << indexUsers[i][j] << " ";
        cout << endl;
    }
    
    for(int i = 0; i < numHash; i++){
        cout << hashtags[i] << endl;
        for(int j = 0; indexHashtags[i][j] != -1; j++)
            cout << indexHashtags[i][j] << " ";
        cout << endl;
    }
}

int main(int argc, char** argv) {

    char ***tweets,**users,**hashtags;
    int **indexUsers,**indexHashtags;
    leerTweets(tweets,users,hashtags);
    reporteLectura(tweets,users,hashtags);
    generarIndices(tweets,users,hashtags,indexUsers,indexHashtags);
    //buscarEnIndices(tweets,users,hashtags,indexUsers,indexHashtags);
    return 0;
}