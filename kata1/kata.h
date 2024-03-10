#ifndef KATA_H
#define KATA_H
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[39m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_BLACK "\x1B[34m"
using namespace std;

/*
    0=?
    1=muerto
    2=vivo
*/

class Kata{
    private:
        int matriz[3][3];
        int numVivos=0, numMuertos=0;
    public:
        inline Kata(){srand(time(NULL));
        for(int i=0; i<2; i++){
        matriz[i][0]=0;
        matriz[i][1]=0;
        matriz[i][2]=0;}};
        inline int getValor(int a, int b) {return matriz[a][b];};
        inline void setValor(int valor, int a, int b){matriz[a][b]=valor;};
        void contarPoblacion(){
            for(int i=0; i<3; i++){
            int j=0;
            while(j<=2){
                if(i!=1 && j!=1){
                    if(matriz[i][j]==1){
                        numMuertos++;
                    }
                    if(matriz[i][j]==2){
                        numVivos++;
                    }
                }
                j++;              
            }
            }
        };
        void aplicarReglas(){
            if(matriz[1][1]==1){
                if(numVivos==3){
                    matriz[1][1]=2;
                }
            }
            if(matriz[1][1]==2){
                if(numVivos==2 || numVivos==3){
                    matriz[1][1]=2;
                }
                if(numVivos!=2 || numVivos!=3){
                    matriz[1][1]=1;
                }
            }
        };
        inline void reset(){numVivos=0;numMuertos=0;};
        void prinft(){
            cout<<"\n";
            cout<<comprobarColor(0, 0)<<ANSI_COLOR_RESET<<"|"<<comprobarColor(0, 1)<<ANSI_COLOR_RESET<<"|"<<comprobarColor(0, 2)<<ANSI_COLOR_RESET<<"\n";
            cout<<comprobarColor(1, 0)<<ANSI_COLOR_RESET<<"|"<<comprobarColor(1, 1)<<ANSI_COLOR_RESET<<"|"<<comprobarColor(1, 2)<<ANSI_COLOR_RESET<<"\n";
            cout<<comprobarColor(2, 0)<<ANSI_COLOR_RESET<<"|"<<comprobarColor(2, 1)<<ANSI_COLOR_RESET<<"|"<<comprobarColor(2, 2)<<ANSI_COLOR_RESET<<"\n";
            cout<<"\n";
        }
        void cambio(){
            cout<<" ||| \n";
            cout<<" |v| \n";
            cout<<" |"<<comprobarColor(1,1)<<ANSI_COLOR_RESET<<"| \n";
        }
        void getRandom(int a, int b){
            if(a==1 && b==1){
                matriz[a][b]=(rand()%2)+1;
            }
            if(a!=1 && b!=1){
                matriz[a][b]=(rand()%3);
            }
        };
        int comprobarColor(int a, int b){
            if(matriz[a][b]==0){
                cout<<ANSI_COLOR_BLACK;
                return matriz[a][b];
            }   
            if(matriz[a][b]==1){
                cout<<ANSI_COLOR_RED;
                return matriz[a][b];
            }   
            if(matriz[a][b]==2){
                cout<<ANSI_COLOR_GREEN;
                return matriz[a][b];
            }           
            return 1;
        };
};

#endif















