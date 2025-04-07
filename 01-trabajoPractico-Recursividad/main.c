#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "tp_1_recursividad.h"
#define MAX 100

int main(){
    int ejercicio, n1, n2, tamano, n, nivel, i; 
    char palabra[MAX];
    char numeros[MAX];
    char entrada7[MAX];
    char *resultado;
    int *conjunto;
    int *vec;
    bool valido = false;
    while (ejercicio != -1)
    {   
        printf("Ingrese el número del ejercicio deseado (1-10) o -1 para salir del programa\n");
        scanf("%d", &ejercicio);
        getchar();
        switch(ejercicio){
            case 1: 
            //EJERCICIO 1
                printf("Ingrese una palabra para averiguar si es palindromo o no: ");
                fgets(palabra, MAX, stdin);
                palabra[strcspn(palabra, "\n")] = '\0';
                tamano = strlen(palabra);
                valido = false;
                while (!valido) {
                    valido = true;
                    if (tamano == 0) {
                        valido = false;
                    } else {
                        valido = false;
                        for (i = 0; i < tamano; i++) {
                            if (!isspace((unsigned char)palabra[i])) {
                                valido = true;
                                i = tamano;
                            }
                        }
                    }
                    if (!valido) {
                        printf("La palabra no puede estar vacía ni tener solo espacios. Intente de nuevo: ");
                        fgets(palabra, MAX, stdin);
                        palabra[strcspn(palabra, "\n")] = '\0';
                        tamano = strlen(palabra);
                    }
                } 
                if(palindromo(palabra) == true){
                    printf("VERDADERO. %s es palindromo!\n", palabra);
                }else{
                    printf("FALSO. %s no es palindromo\n", palabra);
                }
                break;
            case 2: 
            //EJERCICIO 2
                printf("Ingrese dos numeros enteros para hallar el producto\n");
                printf("Ingrese el primer numero: "); 
                fgets(numeros, MAX, stdin);
                numeros[strcspn(numeros, "\n")] = '\0';
                valido = false;
                while (!valido){
                    n1 = strtol(numeros, &resultado, 10); 
                    valido = true;
                    if (numeros == resultado || *resultado != '\0'){
                        printf("Ingrese una valor válido: ");
                        fgets(numeros, MAX, stdin);
                        numeros[strcspn(numeros, "\n")] = '\0';
                        valido = false;
                    }
                }
                printf("Ingrese el segundo numero: "); 
                fgets(numeros, MAX, stdin);
                numeros[strcspn(numeros, "\n")] = '\0';
                valido = false;
                while (!valido){
                    n2 = strtol(numeros, &resultado, 10); 
                    valido = true;
                    if (numeros == resultado || *resultado != '\0'){
                        printf("Ingrese una valor válido: ");
                        fgets(numeros, MAX, stdin);
                        numeros[strcspn(numeros, "\n")] = '\0';
                        valido = false;
                    }
                }
                printf("El producto de %d y %d es %d\n", n1, n2, producto(n1, n2));
                break;
            case 3:  
            //EJERCICIO 3
                printf("Ingrese un numero para realizar la serie de Fibonacci\n");
                do {
                    fgets(numeros, MAX, stdin);
                    numeros[strcspn(numeros, "\n")] = '\0';
                    while (*numeros == ' ') memmove(numeros, numeros + 1, strlen(numeros));
                    if (strlen(numeros) == 0 || strspn(numeros, "0123456789") != strlen(numeros)) {
                        printf("Debe ingresar un numero valido mayor o igual a 0: ");
                    }
                } while (strlen(numeros) == 0 || strspn(numeros, "0123456789") != strlen(numeros));
                n1 = atoi(numeros);
                printf("El resultado es %d\n", terminoSeridFibonacci(n1 + 1));
                break;
            case 4: 
            //EJERCICIO 4
                printf("Ingrese dos numeros enteros para hallar el cociente\n");
                do {
                    printf("Ingrese el dividendo (numero entero): ");
                    fgets(numeros, sizeof(numeros), stdin);
                    numeros[strcspn(numeros, "\n")] = '\0';
                    n1 = atoi(numeros);
                } while (strlen(numeros) == 0 || strspn(numeros, "0123456789-") != strlen(numeros));
                do {
                    printf("Ingrese el divisor (numero entero > 0): ");
                    fgets(numeros, sizeof(numeros), stdin);
                    numeros[strcspn(numeros, "\n")] = '\0';
                    n2 = atoi(numeros);
                } while (strlen(numeros) == 0 || strspn(numeros, "0123456789-") != strlen(numeros) || n2 == 0);
                printf("El cociente entre %d y %d es %0.5f\n", n1, n2, division(n1, n2));
                break;
            case 5: 
            //EJERCICIO 5
                do {
                    printf("Ingrese un numero sin espacios y que no comience con 0:\n");
                    fgets(numeros, MAX, stdin);
                    numeros[strcspn(numeros, "\n")] = '\0';
            
                    if (strlen(numeros) == 0 || numeros[0] == '0' || 
                        strspn(numeros, "0123456789") != strlen(numeros) || 
                        strchr(numeros, ' ') != NULL) {
                        printf("Entrada invalida. Debe ingresar solo numeros, sin espacios y sin comenzar con 0.\n");
                    }
            
                } while (strlen(numeros) == 0 || numeros[0] == '0' || 
                        strspn(numeros, "0123456789") != strlen(numeros) || 
                        strchr(numeros, ' ') != NULL);
            
                resultado = agregarSeparadorMiles(numeros);
                printf("%s\n", resultado);
                free(resultado);
                break;
            case 6: 
            //EJERCICIO 6
                do {
                    printf("Ingrese una onda digital: \n");
                    fgets(numeros, MAX, stdin);
                    numeros[strcspn(numeros, "\n")] = '\0';
                    for (int i = 0; numeros[i] != '\0'; i++) {
                        numeros[i] = tolower((unsigned char)numeros[i]);
                    }
                    if (strlen(numeros) == 0 || strspn(numeros, "hl") != strlen(numeros) || strchr(numeros, ' '))
                        printf("Entrada invalida. Solo se permiten caracteres 'h' o 'l' sin espacios.\n");
                } while (strlen(numeros) == 0 || strspn(numeros, "hl") != strlen(numeros) || strchr(numeros, ' '));
            
                resultado = ondaDigital(numeros);
                printf("%s\n", resultado);
                free(resultado);
                break;
           case 7:
           //EJERCICIO 7
                do {
                    printf("Ingrese el nivel de la reunion: ");
                    fgets(entrada7, sizeof(entrada7), stdin);
                    entrada7[strcspn(entrada7, "\n")] = '\0';
            
                    if (strlen(entrada7) == 0 || strspn(entrada7, "0123456789") != strlen(entrada7) || strchr(entrada7, ' ')) {
                        printf("Ingreso invalido. Solo se aceptan numeros enteros positivos sin espacios.\n");
                        nivel = 0;
                    } else {
                        nivel = atoi(entrada7);
                        if (nivel < 1)
                            printf("El numero debe ser mayor o igual a 1.\n");
                    }
                } while (nivel < 1);
            
                printf("Vista frontal de la delegacion:\n");
                char *resultado = reunionMafia(nivel);
                free(resultado);
                break;
            case 8:
            //EJERCICIO 8 
                printf("Ingrese el tamanio del conjunto: ");
                fgets(numeros, MAX, stdin);
                numeros[strcspn(numeros, "\n")] = '\0';
                valido = false;
                while (!valido){
                    valido = true;
                    if(atoi(numeros) == 0 || atoi(numeros) < 0){
                        printf("Ingrese una valor válido: ");
                        fgets(numeros, MAX, stdin);
                        numeros[strcspn(numeros, "\n")] = '\0';
                        valido = false;
                    }
                }
                tamano = atoi(numeros);

                conjunto = malloc(tamano* sizeof(int));
                for (int i = 0; i < tamano; i++) {
                    printf("Ingrese el valor %d del conjunto: ", i+1);
                    fgets(numeros, MAX, stdin);
                    numeros[strcspn(numeros, "\n")] = '\0';
                    valido = false;
                    while (!valido){
                        n1 = strtol(numeros, &resultado, 10); 
                        valido = true;
                        if (numeros == resultado || *resultado != '\0' || n1 < 0) {
                            printf("Ingrese un valor válido: ");
                            fgets(numeros, MAX, stdin);
                            numeros[strcspn(numeros, "\n")] = '\0';
                            valido = false;
                        }
                    }
                    conjunto[i] = n1;
                }

                printf("Ingrese el valor de la suma deseada: ");
                fgets(numeros, MAX, stdin);
                numeros[strcspn(numeros, "\n")] = '\0';
                valido = false;
                while (!valido){
                    valido = true;
                    if(atoi(numeros) == 0 || atoi(numeros) < 0){
                        printf("Ingrese una valor válido: ");
                        fgets(numeros, MAX, stdin);
                        numeros[strcspn(numeros, "\n")] = '\0';
                        valido = false;
                    }
                }
                n = atoi(numeros);
                
                char *salida[MAX]; 
                for (int i = 0; i < MAX; i++) salida[i] = NULL;
            
                subconjuntosQueSumanN(conjunto, tamano, n, salida);            
                printf("Subconjuntos que suman %d:\n", n);
                for (int i = 0; i < 100 && salida[i] != NULL; i++) {
                    printf("%s\n", salida[i]);
                    
                }
                break;
            case 9: 
            //EJERCICIO 9
                printf("Ingrese un numero para saber si es divisible por 7\n");  
                fgets(numeros, MAX, stdin);
                numeros[strcspn(numeros, "\n")] = '\0';
                valido = false;
                while (!valido) {
                    char* endptr;
                    n1 = strtol(numeros, &endptr, 10); 
                    valido = true;
                
                    if (numeros == endptr || *endptr != '\0') {
                        printf("Ingrese un valor válido: ");
                        fgets(numeros, MAX, stdin);
                        numeros[strcspn(numeros, "\n")] = '\0';
                        valido = false;
                    }
                }
                if(divisiblePor7(n1) == true){
                    printf("VERDADERO. %d es divisible por 7!\n", n1);
                }else{
                    printf("FALSO. %d no es divisible por 7\n", n1);
                }

                break;
            case 10: 
            //EJERCICIO 10
                printf("ingrese el valor del numero EXPLOSIVO\n");
                fgets(numeros, MAX, stdin);
                numeros[strcspn(numeros, "\n")] = '\0';
                valido = false;
                while (!valido) {
                    char* endptr;
                    n1 = strtol(numeros, &endptr, 10); 
                    valido = true;
                
                    if (numeros == endptr || *endptr != '\0' || n1 < 0) {
                        printf("Ingrese un valor válido: ");
                        fgets(numeros, MAX, stdin);
                        numeros[strcspn(numeros, "\n")] = '\0';
                        valido = false;
                    }
                }
                printf("ingrese el valor del numero BOMBA\n");
                fgets(numeros, MAX, stdin);
                numeros[strcspn(numeros, "\n")] = '\0';
                valido = false;
                while (!valido) {
                    char* endptr;
                    n2 = strtol(numeros, &endptr, 10); 
                    valido = true;
                
                    if (numeros == endptr || *endptr != '\0' || n2 < 0) {
                        printf("Ingrese un valor válido: ");
                        fgets(numeros, MAX, stdin);
                        numeros[strcspn(numeros, "\n")] = '\0';
                        valido = false;
                    }
                } 
                vec = explosion(n1, n2);
                printf("\nResultado de la explosión:\n");
                i = 0;
                while (vec[i] != -1) {
                    printf("%d ", vec[i]);
                    i++;
                }
                printf("\n");
                free(vec);
                break;
                
            case -1: break;
            default: 
                printf("Ingrese una opcion valida\n");
        }
        
    }
    printf("Adios!!");
    
    

    return 0;
}