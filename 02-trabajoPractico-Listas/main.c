#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "..\libs\listas\headers\listas.h"
#include "..\02-trabajoPractico-Listas\tp_2_listas_1.h"
#include "..\libs\validaciones\headers\validaciones.h"
#define MAX 100

int main(){
    Lista resultados = l_crear();
    char auxiliar[MAX];
    int ejercicio = 0, casos = 0;
    double aux_ejercicio = 0;
    while(ejercicio != -1){
        printf("Ingrese el número del ejercicio deseado (2-6) o -1 para salir del programa\n");
        fgets(auxiliar, MAX, stdin);
        auxiliar[strcspn(auxiliar, "\n")] = '\0';
        aux_ejercicio = validar_numero(auxiliar);
        while(!esEntero(aux_ejercicio)){
            printf("Debe ingresar un valor entero. Intento nuevamente.\n");
            printf("Ingrese el número del ejercicio deseado (2-6) o -1 para salir del programa\n");
            fgets(auxiliar, MAX, stdin);
            auxiliar[strcspn(auxiliar, "\n")] = '\0';
            aux_ejercicio = validar_numero(auxiliar);
        }
        ejercicio = aux_ejercicio;
        switch(ejercicio){
            case 2:
            //EJERCIO 2
                printf("\nBienvenidx al EJERCICIO 2\n");
                float promedio_1, promedio_2;
                ResultadoValorMinimo minimo;
                Lista l1 = l_crear();
                Lista l2 = l_crear();
                printf("Carga de la primera lista.\n"); 
                cargarLista(l1); 
                printf("Carga de la segunda lista.\n");
                cargarLista(l2);
                while(casos != -1){
                    double aux_casos = 0; 
                    printf("Ingrese el ejercicio deseado (1-5) o -1 para salir del ejercicio 2\n");
                    fgets(auxiliar, MAX, stdin);
                    auxiliar[strcspn(auxiliar, "\n")] = '\0';
                    aux_casos = validar_numero(auxiliar);
                    while(!esEntero(aux_casos)){
                        printf("Debe ingresar un valor entero. Intento nuevamente.\n");
                        printf("Ingrese el ejercicio deseado (1-5) o -1 para salir del ejercicio 2\n");
                        fgets(auxiliar, MAX, stdin);
                        auxiliar[strcspn(auxiliar, "\n")] = '\0';
                        aux_casos = validar_numero(auxiliar);
                    }
                    casos = aux_casos;                    
                    switch (casos)
                    {
                        case 1:  
                        //a
                            resultados = verElementosQueNoSeRepiten(l2, l1);
                            if(l_es_vacia(resultados)){
                                printf("No hay elementos faltantes de la lista 1 en la lista 2.\n");
                            } else {
                                printf("Valores de lista 2 que no estan en lista 1.\n");
                                l_mostrar(resultados);
                            }                         
                            break;
                        case 2:
                        //b 
                            resultados = verElementosQueNoSeRepiten(l1, l2);
                            if(l_es_vacia(resultados)){
                                printf("No hay elementos faltantes de la lista 2 en la lista 1.\n");
                            } else {
                                printf("Valores de lista 1 que no estan en lista 2.\n");
                                l_mostrar(resultados);
                            }
                            break;
                        case 3:
                        //c
                            resultados = verElementosRepetidos(l1, l2);
                            if(l_es_vacia(resultados)){
                                printf("No hay elementos repetidos.\n");
                            } else {
                                printf("Valores que se repiten en ambas listas.\n");
                                l_mostrar(resultados);
                            }
                                        
                            break;
                        case 4: 
                        //d 
                            promedio_1 = promedio(l1);
                            printf("El promedio de la lista 1 es: %0.2f\n", promedio_1);
                            promedio_2 = promedio(l2);
                            printf("El promedio de la lista 2 es: %0.2f\n", promedio_2);
                            break;
                        case 5:
                        //e 
                            minimo = valorMinimo(l1, l2);
                            printf("El valor minimo de la lista 1 es: %d y su posicion ordinal es: %d\n", minimo.valor, minimo.pos + 1);
                            printf("El valor minimo de la lista 2 es: %d y su posicion ordinal es: %d\n", minimo.valor_2, minimo.pos_2 + 1);
                            break;
                        case -1: 
                            break;
                        default: printf("Por favor, ingrese una opcion valida\n");
                    }
                }
                printf("\n");
                break;
            case 3:
            //EJERCIO 3 
                Lista l3 = l_crear();
                Lista l4 = l_crear();
                printf("\nBienvenidx al EJERCICIO 3\n");
                printf("Carga de la primera lista.\n");
                cargarLista(l3);
                printf("Carga de la segunda lista.\n");
                cargarLista(l4);
                ResultadosMul solucion;
                solucion = multiplo(l3, l4);
                if(solucion.esMultiplo == true){
                    printf("l2 es multiplo de l1.\n");
                    if(solucion.escalar == true){
                        printf("El valor escalar es %d\n", solucion.numEscalar);
                    } else {
                        printf("No hay numero escalar.\n");
                    }
                }else{
                    printf("l2 NO es multiplo de l1.\n");
                }
                printf("\n");
                break;
            case 4:
            //EJERCIO 4
                Lista l5 = l_crear();
                Lista l6 = l_crear();
                printf("\nBienvenidx al EJERCICIO 4\n");
                printf("Recuerde que las listas deben ser de igual tamanio.\n");
                printf("Carga de la primera lista.\n");
                cargarLista(l5);
                printf("Carga de la segunda lista.\n");
                cargarLista(l6);
                while(l_longitud(l5) != l_longitud(l6)){
                    printf("Las longitudes de las listas no pueden ser distintas. Intentelo nuevamente.\n");
                    printf("Carga de la primera lista.\n");
                    cargarLista(l5);
                    printf("Carga de la segunda lista.\n");
                    cargarLista(l6);
                }
                int result;
                result = CompararListas(l5, l6);
                if(result == 1){
                    printf("Lista 1 > Lista 2\n");
                }else if(result == 0){
                    printf("Lista 1 < Lista 2\n");
                }else{
                    printf("Son iguales\n");
                }
                printf("La complejidad algoritmica del ejercicio es Lineal 'O(n)'\n");
                printf("\n");
                break;
            case 5:
            //EJERCIO 5
                Lista l7 = l_crear();
                Lista l8 = l_crear();
                int x;
                printf("\nBienvenidx al EJERCICIO 5\n");
                Iterador it;
                TipoElemento valor;
                double polinomio, aux_poli, x1, x2, intervalo;
                
                hacerPolinomio(l7);
                printf("Ingrese el valor de la X: ");
                fgets(auxiliar, MAX, stdin);
                auxiliar[strcspn(auxiliar, "\n")] = '\0';
                x = validar_numero(auxiliar);
                polinomio = evaluarPolinomio(l7, x);
                printf("El resultado del polinomio es: %0.2f\n", polinomio);
                
                printf("Ingrese el valor inicial del rango: \n");
                fgets(auxiliar, MAX, stdin);
                auxiliar[strcspn(auxiliar, "\n")] = '\0';
                x1 = validar_numero(auxiliar);
                
                printf("Ingrese el valor final del rango: \n");
                fgets(auxiliar, MAX, stdin);
                auxiliar[strcspn(auxiliar, "\n")] = '\0';
                x2 = validar_numero(auxiliar);
                
                printf("Ingrese el intervalo: \n");
                fgets(auxiliar, MAX, stdin);
                auxiliar[strcspn(auxiliar, "\n")] = '\0';
                intervalo = validar_numero(auxiliar);
                while(intervalo < 0){
                    printf("El intervalo no puede ser negativo. Intentelo nuevamente.");
                    printf("Ingrese el intervalo: \n");
                    fgets(auxiliar, MAX, stdin);
                    auxiliar[strcspn(auxiliar, "\n")] = '\0';
                    intervalo = validar_numero(auxiliar);
                }

                printf("Los resultado del polinomio en el rango es: \n");
                
                l8 = calcularRango(l7, x1, x2, intervalo);
                it = iterador(l8);
                while(hay_siguiente(it)==true){
                    valor = siguiente(it);
                    aux_poli = *((float*)valor->valor);
                    printf("%0.2f\t", aux_poli);
                }
                printf("\n");
                break;   
            case 6:
            //EJERCIO 6
                Lista l9 = l_crear();
                Lista l10 = l_crear();
                printf("\nBienvenidx al EJERCICIO 6\n");
                printf("Carga de la primera lista.\n");
                cargarLista(l9);
                printf("Carga de la segunda lista.\n"); 
                cargarLista(l10);
                bool resultado = esSublista(l9, l10);
                if (resultado == true) {
                    printf("\nl2 es sublista de l1.\n");
                } else {
                    printf("\nl2 no es sublista de l1.\n");
                }
                printf("La complejidad algoritmica del ejercicio es Cuadratica\n");
                printf("\n");
                break;
            case -1: break;
            default:
                printf("\nPor favor, ingrese una opcion valida\n");
        }
    
    }
    printf("¡Hasta la proxima!");

    return 0;
}

