/**
 * @file banking.c
 * @author Gonzalo Márquez de Torres (i02matog@uco.es)
 * @brief Archivo main de la kata correspondiente a la cartilla bancaria
 * @version 0.1
 * @date 2024-03-05
 * @copyright Copyright (c) 2024
 */

// INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "funciones.c"

// PALETA DE COLORES DE LA TERMINAL
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[39m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_BLACK "\x1B[34m"

/**
 * @name main
 * @brief Funcion main del codigo
 * @return int 
 * Devolverá -1, en caso de que haya algún error.
 */
int main(){
    // APERTURA DEL FICHERO PARA COMPROBACION DE VALORES
    FILE* f;
    if((f=fopen("cartilla.txt", "rb")) == NULL){
        printf("El fichero a abrir no existe.\n");
        return -1;
    }    

    // LECTURA DEL FICHERO Y OBTENCIÓN DE VALOR TOTAL
    f = fopen("cartilla.txt", "r");
    char fecha[256], motivo[256];
    float media, total;
    while(fscanf(f, "%s %f %f %s\n", fecha, &media, &total, motivo) != EOF){}
    fclose(f);

    // TIEMPO 
    char output[10];
    time_t tiempo = time(NULL);
    struct tm *tlocal = localtime(&tiempo);
    strftime(output, 10, "%d/%m/%y", tlocal);

    int valor = 5;
    while(valor != 0){
        printf("Introduce el número de la accion que desea realizar: \n");
        printf("    1. Introducir dinero.\n");
        printf("    2. Sacar dinero.\n");
        printf("    3. Imprimir por pantalla.\n");
        printf("    0. Salir.\n");
        printf("En el momento que desee salir, debe activar la opción para realizar la copia de seguridad.\n");
        printf("¿Cuál opción desea seleccionar? ");
        scanf("%d", &valor);
        printf("\n");        

        // VALOR 1: INGRESO DE DINERO
        if(valor == 1){                        
            ingresoDinero(output, total);                      
        }

        // VALOR 2: RETIRADA DE DINERO
        if(valor == 2){            
            retiradaDinero(output, total);            
        }

        // VALOR 3: IMPRIMIR VALORES POR PANTALLA
        if(valor == 3){
            imprimirValores();
        }

        // VALOR 0: SALIR + COPIA DE SEGURIDAD
        if(valor == 0){
            copiaSeguridad();
            printf("¡Vuelva cuando quiera!\n");
        }
    }
    return 0;    
}