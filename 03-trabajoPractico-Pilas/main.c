#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "..\libs\pilas\headers\pilas.h"
#include "..\03-trabajoPractico-Pilas\tp_3_pilas.h"
#include "..\libs\validaciones\headers\validaciones_pilas.h"
#define MAX 100

int main() {
    char auxiliar[MAX];
    int casos = 0, opcion = 0, sub = 0, clave, posicion, base, numero, pos1, pos2, cantidad;
    double aux_ejercicio = 0;
    Pila sin_repetidos, sin_clave, sin_clave_recursiva, comunes, invertida;
    Pila p = p_crear();
    Pila p2 = p_crear();
    TipoElemento elemento, elem;
    while(opcion != -1){
        printf("Ingrese el numero del ejercicio deseado (2-8) o -1 para salir del programa\n");
        fgets(auxiliar, MAX, stdin);
        auxiliar[strcspn(auxiliar, "\n")] = '\0';
        aux_ejercicio = validar_numero(auxiliar);
        while(!esEntero(aux_ejercicio)){
            printf("\nDebe ingresar un valor entero. Intento nuevamente.\n");
            fgets(auxiliar, MAX, stdin);
            auxiliar[strcspn(auxiliar, "\n")] = '\0';
            aux_ejercicio = validar_numero(auxiliar);

        }
        opcion = aux_ejercicio;

        vaciar_pila(p);
        vaciar_pila(p2);

        switch(opcion) {
            case 2:
                printf("\nBienvenidx al EJERCICIO 2\n");
                cargarpila(p); 
                getchar();
                while(sub != -1){
                    double aux_casos = 0; 
                    printf("Ingrese el ejercicio deseado (1-6) o -1 para salir del ejercicio 2\n");
                    fgets(auxiliar, MAX, stdin);
                    auxiliar[strcspn(auxiliar, "\n")] = '\0';
                    aux_casos = validar_numero(auxiliar);
                    while(!esEntero(aux_casos)){
                        printf("Debe ingresar un valor entero. Intento nuevamente.\n");
                        printf("Ingrese el ejercicio deseado (1-6) o -1 para salir del ejercicio 2\n");
                        fgets(auxiliar, MAX, stdin);
                        auxiliar[strcspn(auxiliar, "\n")] = '\0';
                        aux_casos = validar_numero(auxiliar);
                    }
                    sub = aux_casos;
                    switch (sub) {
                        case 1:
                        //a
                            printf("1) a. Buscar una clave y determinar si existe en la pila.\n");
                            printf("Ingrese la clave a buscar: ");
                            fgets(auxiliar, MAX, stdin);
                            auxiliar[strcspn(auxiliar, "\n")] = '\0';
                            aux_ejercicio = validar_numero(auxiliar);
                            while(!esEntero(aux_ejercicio)){
                                printf("Debe ingresar un valor entero. Intento nuevamente: \n");
                                printf("Ingrese la clave a buscar: ");
                                fgets(auxiliar, MAX, stdin);
                                auxiliar[strcspn(auxiliar, "\n")] = '\0';
                                aux_ejercicio = validar_numero(auxiliar);
                            }
                            clave = aux_ejercicio;
                            if (p_ej2_existeclave(p, clave)) {
                                printf("La clave %d existe en la pila.\n", clave);
                            } else {
                                printf("La clave %d no existe en la pila.\n", clave);
                            }
                            break;

                        case 2:
                        //b
                            printf("2) b. Colocar un nuevo elemento en una posicion ordinal.\n");
                            printf("Ingrese la posicion ordinal: ");
                            fgets(auxiliar, MAX, stdin);
                            auxiliar[strcspn(auxiliar, "\n")] = '\0';
                            posicion = validar_numero(auxiliar);
                            while(posicion <= 0){
                                printf("La posicion ordinal debe ser un numero natural. Intentelo nuevamente.");
                                fgets(auxiliar, MAX, stdin);
                                auxiliar[strcspn(auxiliar, "\n")] = '\0';
                                posicion = validar_numero(auxiliar);
                            }
                            printf("Ingrese el valor del nuevo elemento: ");
                            fgets(auxiliar, MAX, stdin);
                            auxiliar[strcspn(auxiliar, "\n")] = '\0';
                            clave = validar_numero(auxiliar);
                            elemento = te_crear(clave);
                            p2 = p_ej2_colocarelemento(p, posicion, elemento);
                            if(p_es_vacia(p2)){
                                printf("No se pudo insertar el elemento\n");
                            }else{
                                printf("Pila despues de insertar el elemento:\n");
                                p_mostrar(p2);
                            }
                            
                            break;

                        case 3:
                        //c
                            printf("3) c. Eliminar un elemento dado (primera ocurrencia).\n");
                            printf("Ingrese la clave a eliminar: \n");
                            fgets(auxiliar, MAX, stdin);
                            auxiliar[strcspn(auxiliar, "\n")] = '\0';
                            clave = validar_numero(auxiliar);
                            p2 = p_ej2_eliminarclave(p, clave); 
                            if(!p_es_vacia(p2)){
                                printf("Pila despues de eliminar la clave:\n");
                                p_mostrar(p2);
                            }
                            
                            break;

                        case 4:
                        //d 
                            printf("4) d. Intercambiar los valores de dos posiciones ordinales.\n");
                            printf("Ingrese la primera posicion: \n");
                            fgets(auxiliar, MAX, stdin);
                            auxiliar[strcspn(auxiliar, "\n")] = '\0';
                            pos1  = validar_numero(auxiliar);
                            while(pos1 <= 0){
                                printf("La posicion ordinal debe ser un numero natural. Intentelo nuevamente.\n");
                                fgets(auxiliar, MAX, stdin);
                                auxiliar[strcspn(auxiliar, "\n")] = '\0';
                                pos1 = validar_numero(auxiliar);
                            }
                            printf("Ingrese la segunda posicion: \n");
                            fgets(auxiliar, MAX, stdin);
                            auxiliar[strcspn(auxiliar, "\n")] = '\0';
                            pos2 = validar_numero(auxiliar);
                            while(pos2 <= 0){
                                printf("La posicion ordinal debe ser un numero natural. Intentelo nuevamente.\n");
                                fgets(auxiliar, MAX, stdin);
                                auxiliar[strcspn(auxiliar, "\n")] = '\0';
                                pos2 = validar_numero(auxiliar);
                            }
                            p2 = p_ej2_intercambiarposiciones(p, pos1, pos2);
                            if(!p_es_vacia(p2)){
                                printf("Pila despues de intercambiar posiciones:\n");
                                p_mostrar(p2);
                            }
                            
                            break;

                        case 5:
                        //e
                            printf("5) e. Duplicar el contenido de una pila.\n");
                            p2 = p_ej2_duplicar(p);
                            if(!p_es_vacia(p2)){
                                printf("Pila duplicada:\n");
                                p_mostrar(p2);
                            }
                            
                            break;

                        case 6:
                        //f
                            printf("6) f. Contar los elementos de la pila.\n");
                            cantidad = p_ej2_cantidadelementos(p);
                            printf("La pila tiene %d elementos.\n", cantidad);
                            break;
                        case -1:
                            break;
                        default:
                            printf("Subopcion invalida. Intente nuevamente.\n");
                        }
                }
                getchar();
                printf("\n");
                break;
            case 3:
                printf("\nBienvenidx al EJERCICIO 3\n");
                printf("3. Determinar si dos pilas son exactamente iguales.\n");
                printf("Cargue la primera pila:\n");
                cargarpila(p);
                printf("Cargue la segunda pila:\n");
                cargarpila(p2);
                if (p_ej3_iguales(p, p2)) {
                    printf("Las pilas son iguales.\n");
                } else {
                    printf("Las pilas no son iguales.\n");
                }
                printf("\nComplejidad algoritmica de la funcion es O(n) | n = cantidad de elementos de la pila\n");
                getchar();
                printf("\n");
                break;

            case 4:
                printf("\nBienvenidx al EJERCICIO 4\n");
                printf("4. Convertir un numero decimal a otra base (2-16).\n");
                printf("Ingrese el numero decimal: \n");
                fgets(auxiliar, MAX, stdin);
                auxiliar[strcspn(auxiliar, "\n")] = '\0';
                numero = validar_numero(auxiliar);
                printf("En caso de ser negativo, sera tratado como un positivo.\n");
                
                printf("Ingrese la base (2-16): \n");
                fgets(auxiliar, MAX, stdin);
                auxiliar[strcspn(auxiliar, "\n")] = '\0';
                base = validar_numero(auxiliar);
                if (base < 2 || base > 16) {
                    printf("Base invalida. Debe estar entre 2 y 16.\n");
                } else {
                    char *resultado = p_ej4_cambiarbase(numero, base);
                    printf("El numero en base %d es: %s\n", base, resultado);
                    free(resultado);
                }
                printf("\nComplejidad algoritmica de la funcion es O(log n) | n = cantidad de digitos necesarios para representar el numero en la nueva base.\n");
                getchar();
                printf("\n");
                break;

            case 5:
                printf("\nBienvenidx al EJERCICIO 5\n");
                printf("5. Invertir el contenido de una pila.\n");
                cargarpila(p);
                invertida = p_ej5_invertir(p);
                printf("\nPila original:\n");
                p_mostrar(p);
                printf("\nPila invertida:\n");
                p_mostrar(invertida);
                printf("\nComplejidad algoritmica de la funcion es O(n) | n = cantidad de elementos de la pila\n");
                getchar();
                printf("\n");
                break;

            case 6:
                printf("\nBienvenidx al EJERCICIO 6\n");
                printf("6. Eliminar todas las ocurrencias de un item en una pila.\n");
                
                cargarpila(p);
                getchar();
                printf("Ingrese la clave a eliminar: ");
                fgets(auxiliar, MAX, stdin);
                auxiliar[strcspn(auxiliar, "\n")] = '\0';
                clave = validar_numero(auxiliar);
                //printf("Solucion iterativa: \n");
                sin_clave = p_ej6_eliminarclave(p, clave);
                if(!p_es_vacia(sin_clave)){
                    printf("Solucion iterativa: \n");
                    printf("Pila sin la clave %d:\n", clave);
                    p_mostrar(sin_clave);
                    printf("Complejidad algoritmica de la solucion iterativa es O(n) | n = cantidad de elementos de la pila\n");
                    printf("\n");
                
                
                    printf("Solucion recursiva: \n");
                    sin_clave_recursiva = p_ej6_eliminarclave_r(p, clave);
                    printf("Pila sin la clave %d:\n", clave);
                    p_mostrar(sin_clave_recursiva);
                    printf("Complejidad algoritmica de la solucion recursiva es O(n) | n = cantidad de elementos de la pila\n");
                    getchar();
                    printf("\n");
                }
                break;

            case 7:
                printf("\nBienvenidx al EJERCICIO 7\n");
                printf("7. Determinar los elementos comunes entre dos pilas.\n");
                printf("Cargue la primera pila:\n");
                cargarpila(p);
                printf("Cargue la segunda pila:\n");
                cargarpila(p2);
                comunes = p_ej7_elementoscomunes(p, p2);
                printf("Elementos comunes entre las pilas:\n");
                p_mostrar(comunes);
                printf("\nComplejidad algoritmica es O(n^2) - n = cantidad de elementos de la pila\n");
                getchar();
                printf("\n");
                break;
            case 8:
                printf("\nBienvenidx al EJERCICIO 8\n");
                printf("8. Obtener una pila con valores unicos y su cantidad de repeticiones.\n");
                cargarpila(p);
                sin_repetidos = p_ej8_sacarrepetidos(p);
                printf("Pila sin repetidos (clave:conteo):\n");
                while (!p_es_vacia(sin_repetidos)) {
                    elem = p_desapilar(sin_repetidos);
                    printf("%d:%d ", elem->clave, (int)(intptr_t)elem->valor);
                }
                printf("\nLa complejidad algoritmica de la funcion es O(n) - n = cantidad de elementos de la pila\n");
                getchar();
                printf("\n");
                break;
            case -1:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("\nOpcion invalida. Intente nuevamente.\n");
        }

    } 
    return 0;
}