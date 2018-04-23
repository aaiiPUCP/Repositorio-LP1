/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * Author: Arian Gabriel Gallardo Callalli
 * Codigo: 20153227
 * Salon: V208
 */

#include <cstdlib>
#include <cstdio>


#define MAX_LINEA 100

void ws(int x){
    for(int i = 0 ; i < x; i ++) printf(" ");
}

void fill(char c){
    for(int i = 0; i < MAX_LINEA; i++) printf("%c", c);
    printf("\n");
}

bool is_ws(char c){
    return c == '\n' || c == ' ' || c == '\t' || c == '\r';
}

void impEncPagina(int pag){
    if(pag > 1) fill('-');
    printf("%90s", "Pagina ");
    printf("%d\n", pag);
    printf("FECHA");
    printf("%15s", "HORA");
    printf("%15s", "RETIROS");
    printf("%15s", "DEPOSITOS");
    printf("%15s", "SALDO");
    printf("%25s", "OBSERVACION");
    printf("\n");
    fill('-');
}

float impCliente(char c, char c2){
    printf("CODIGO DE CUENTA");
    printf("%30s", "CLIENTE");
    printf("%30s", "SALDO INICIAL\n");
    ws(3);
    printf("%c", c);
    if(c2 != '\0') c = c2;
    while(!is_ws(c)){
        printf("%c", c);
        scanf("%c", &c);
    }
    scanf(" ");
    int mayus = 1;
    ws(25);
    while(scanf("%c", &c)){
        if(is_ws(c)) break;
        if(c == '/' || c == '-'){
            mayus = 1;
            printf(" "); continue;
        }
        if(mayus){
            if(c >= 'a') printf("%c", c-32);
            else printf("%c", c);
            mayus = 0;
        }
        else{
            if(c <= 'Z') printf("%c", c + 32);
            else printf("%c", c);
        }
    }
    float saldo; scanf(" %f", &saldo);
    return saldo;
}

void impResumen(int cntRet, int cntDep, float totRet, float totDep, float saldo){
    printf("RESUMEN:\n");
    printf("CANTIDAD DE RETIROS: %5d", cntRet);
    printf("%25s %10.2f\n","TOTAL DE RETIROS: ", totRet);
    printf("CANTIDAD DE DEPOSITOS: %5d", cntDep);
    printf("%25s %10.2f\n","TOTAL DE DEPOSITOS: ", totDep);
    printf("SALDO FINAL: %10.2f", saldo);
    printf("%25s", "OBSERVACION FINAL: ");
    if(saldo < 3000 && saldo >= 0) printf("CUENTA BAJO EL MINIMO");
    else if(saldo < 0) printf("CUENTA EN SOBREGIRO");
    printf("\n");
    fill('=');
}

void leeryProcesar(){
    printf("ESTADO DE CUENTAS DEL BANCO ABCD\n");
    fill('=');
    char c;
    while(scanf("%c", &c) != EOF){
        char c2 = '\0';
        float saldo = impCliente(c,c2);
        printf("%20.2f\n", saldo);
        fill('=');
        float totRet = 0.0, totDep =0.0;
        int cntRet = 0, cntDep = 0;
        int dia = -1, mes = -1, anho = -1;
        int mov = 0, prev = 0;
        while(1){
            if(mov == prev){
                impEncPagina(prev/20 + 1);
                prev += 20;
            }
            if(dia == -1) scanf("%d/%d/%d", &dia, &mes, &anho);
            else scanf("%d/%d", &mes, &anho);
            printf("%02d/%02d/%02d", dia, mes, anho);
            int esp = 6;
            int endDia = 0;
            int endCli = 0;
            while(!endDia){
                scanf(" %c", &c);
                if(scanf("%c", &c2) == EOF){
                    endCli = 1;
                    break;
                }
                if(!is_ws(c2)){
                    endCli = 1; //Se da el caso que se lee un nuevo codigo de cliente, con lo cual tenemos que salir
                    break;
                }
                int flagRet = 0;
                if(c == 'R') flagRet = 1;
                int h,m,s;
                while(scanf("%d", &h) > 0){
                    scanf("%c", &c);
                    if(c == '/'){
                        dia = h;
                        endDia ++;
                        break;
                    }
                    if(mov == prev){
                        impEncPagina(prev/20 + 1);
                        prev += 20;
                    }
                    scanf("%d:%d", &m, &s);
                    ws(esp-2);
                    printf("%02d:%02d:%02d", h,m,s);
                    float transac; scanf(" %f", &transac);
                    totRet += flagRet*transac*1.0;
                    totDep += (1 - flagRet)*1.0*transac;
                    cntRet += flagRet; cntDep += (1 - flagRet);
                    if(flagRet) saldo-= transac;
                    else saldo += transac;
                    if(flagRet){
                        printf("%15.2f", transac);
                        printf("%30.2f", saldo);
                    }
                    else{
                        printf("%30.2f", transac);
                        printf("%15.2f", saldo);
                    }
                    if(saldo < 3000 && saldo >= 0) printf("%20s", "BAJO EL MINIMO");
                    else if(saldo < 0) printf("%20s", "EN SOBREGIRO");
                    printf("\n");
                    mov ++;
                    esp = 16;
                }
            }
            if(endCli) break;
        }
        fill('=');
        impResumen(cntRet, cntDep, totRet, totDep , saldo);
    }
}