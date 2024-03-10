/**
 * @file funciones.c
 * @author Gonzalo Márquez de Torres (i02matog@uco.es)
 * @brief Archivo funciones de la kata correspondiente a la cartilla bancaria
 * @version 0.1
 * @date 2024-03-05
 * @copyright Copyright (c) 2024
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// PALETA DE COLORES DE LA TERMINAL
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[39m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_BLACK "\x1B[34m"

/**
 * @name ingresoDinero
 * @brief Ingreso de dinero introduciendo el valor y la fecha de este.
 * @param fecha Fecha del ingreso
 * @param total Dinero total introducido
 * @return none
 */
void ingresoDinero(char fecha[], float total){
    float dinero;
    char motivo[256];
    printf("Introduce el valor que desea introducir: ");           
    scanf("%f", &dinero);
    int opcion;
    while(opcion != 1 && opcion != 2){
        printf("¿Corresponde con la paga mensual? Si es asi, pulse 1. En caso contrario 2: ");        
        scanf("%d", &opcion);
        if(opcion == 1){
            strcpy(motivo, "PAGA_MENSUAL");
        }
        if(opcion == 2){
            strcpy(motivo, "OTRO");
        }
        else{
            printf("Introduce un valor correcto.\n");
        }
    }
    printf("La cantidad es " ANSI_COLOR_GREEN "%.2f" ANSI_COLOR_RESET ".\n\n", dinero);
    float sumatorio = total + dinero;
    FILE* f;
    f=fopen("cartilla.txt", "a+");
    fprintf(f, "%s +%.2f %.2f %s\n", fecha, dinero, sumatorio, motivo);
    fclose(f);
}

/**
 * @name retiradaDinero
 * @brief Retirada de dinero introduciendo el valor y la fecha de este.
 * @param fecha Fecha del ingreso
 * @param total Dinero total introducido
 * @return none
 */
void retiradaDinero(char fecha[], float total){
    float dinero = -1;
    char motivo[256];

    //Introduccion del dinero (RESTRICCION dinero > 0)
    printf("Introduce el valor del saldo que desea retirar: ");           
    while(dinero > 0){
        scanf("%f", &dinero);
        if(dinero <= 0){
            printf("Introduce un valor positivo.\n");
        }
    }

    int opcion;
    while(opcion != 1 && opcion != 2 && opcion != 3){
        printf("Indica cual es el motivo de su retirada:\n");        
        printf("    1. Compra\n");        
        printf("    2. Gasto Diario\n");        
        printf("    3. Otro\n");        
        scanf("%d", &opcion);
        if(opcion == 1){
            strcpy(motivo, "COMPRA");
        }
        if(opcion == 2){
            strcpy(motivo, "GASTO_DIARIO");
        }
        if(opcion == 3){
            strcpy(motivo, "OTRO");
        }
        else{
            printf("Introduce un valor correcto.\n");
        }
    }
    float sumatorio = total-dinero;
    FILE* f;
    f=fopen("cartilla.txt", "a+");
    fprintf(f, "%s -%.2f %.2f %s\n", fecha, dinero, sumatorio, motivo);
    fclose(f);
}

/**
 * @name imprimirValores
 * @brief Imprimir valores de la cartilla
 * @return none
 */
void imprimirValores(){

    int contador = 1;
    char fecha[256], motivo[256];
    float valor, total;

    // Lectura del fichero más obtencion de datos
    FILE* f;
    f = fopen("cartilla.txt", "r");
    while(fscanf(f, "%s %f %f %s\n", fecha, &valor, &total, motivo) != EOF){
        
        printf("%d. %s ", contador, fecha);
        contador++;

        // Variacion del color depende de la accion realizada
        if(valor > 0){
            printf(ANSI_COLOR_GREEN "+%.2f"  ANSI_COLOR_RESET " -> ", valor);
        }
        if(valor < 0){
            printf(ANSI_COLOR_RED "%.2f"  ANSI_COLOR_RESET " -> ", valor);
        }

        // Recalca ademas si el saldo de la cuenta es negativo
        if(total > 0){
            printf("%.2f" , total);
        }
        if(total < 0){
            printf(ANSI_COLOR_RED "%.2f" ANSI_COLOR_RESET , total);
        }
        printf(" %s\n", motivo);     
    }
    fclose(f);
}

/**
 * @name copiaSeguridad
 * @brief Realizacion de copia de seguridad en otro archivo por medio de fecha
 * @param fecha Fecha de realizacion de la copia, fecha de hoy
 * @return none
 */
void copiaSeguridad(){
    
    // Para evitar problemas con las // de la fecha vuelvo a obtener la fecha sin barras
    char fechaSinBarras[8];
    time_t tiempo = time(NULL);
    struct tm *tlocal = localtime(&tiempo);
    strftime(fechaSinBarras, 8, "%d%m%y", tlocal);

    // Modificacion del nombre del archivo de la copia de seguridad
    FILE *f1, *f2;
    char nombre[256], nombre2[256];
    strcpy(nombre, "copias/copiaSeg");
    strcpy(nombre2, ".txt");
    strcat(nombre, fechaSinBarras);
    strcat(nombre, nombre2);
    
    f1 = fopen("cartilla.txt", "r");
    f2 = fopen(nombre, "w");
    char fecha[256], motivo[256];
    float valor, total;

    // Realización de la copia de seguridad
    while(fscanf(f1, "%s %f %f %s\n", fecha, &valor, &total, motivo) != EOF){
        fprintf(f2, "%s %.2f %.2f %s\n", fecha, valor, total, motivo);   
    }

    fclose(f1);
    fclose(f2);

    printf("¡Copia de seguridad realizada con éxito!\n");
}