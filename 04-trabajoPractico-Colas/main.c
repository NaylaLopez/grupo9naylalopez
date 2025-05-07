#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "..\libs\colas\headers\colas.h"
#include "..\libs\pilas\headers\pilas.h"
#include "..\libs\listas\headers\listas.h"
#include "..\04-trabajoPractico-Colas\tp_4_colas.h"
#include "..\libs\validaciones\headers\validaciones.h"
#include "..\libs\validaciones\headers\validaciones_pilas.h"



int main(){
    int ejercicio = 0, subejercicio = 0, valor, posicion, valor_aux;
    double valor_tiempo;
    bool n;
    char *char_posiciones;
    Cola c = c_crear();
    Cola c_2 = c_crear();
    Cola c_3 = c_crear();
    Cola c_resultado = c_crear();
    Lista l_resultado = l_crear();
    Pila p = p_crear();
    TipoElemento x; 
    Iterador ite;
    while(ejercicio != -1){
        ejercicio = pedir_numero("Ingrese el ejercicio (2-7) o -1 para salir: \n");
        switch (ejercicio)
        {
        case 2: printf("Ejercicio 2\n");
            printf("Cargue la cola que se usara en los siguientes ejercicios.\n");
            c_cargar(c);
            while(subejercicio != -1){
                int subejercicio = pedir_numero("Ingrese un subejercicio (1-6) o -1 para salir: \n");
                switch (subejercicio)
                {
                case 1: printf("a. Informar si un elemento dado se encuentra en la cola.\n");
                    valor = pedir_numero("Ingrese el valor a buscar: ");
                    if(c_ej2_existeclave(c, valor) == true){
                        printf("El valor se encuentra en la cola.\n");
                    }else{
                        printf("El valor no se encuentra en la cola.\n");
                    }
                    break;
                case 2: printf("b. Agregar un nuevo elemento en una posicion dada.\n");
                        posicion = pedir_numero("Ingrese la posicion: \n");
                        valor = pedir_numero("Ingrese el elemento: \n");
                        x = te_crear(valor);
                        c_resultado = c_ej2_colarelemento(c, posicion, x);
                        printf("Nueva cola: \n");
                        c_mostrar(c_resultado);
                    break;
                case 3: printf("c. Dado un elemento sacarlo de la cola todas las veces que aparezca\n");
                        valor = pedir_numero("Ingrese el elemento: \n");
                        c_resultado = c_ej2_sacarelemento(c, valor);
                        printf("Nueva cola: \n");
                        c_mostrar(c_resultado);
                        c_destruir(c_resultado);
                    break;
                case 4: printf("d. Contar los elementos de la cola.\n");
                        valor = c_ej2_contarelementos(c);
                        printf("La cantidad de elementos es: %d \n", valor);
                    break;
                case 5: printf("e. Realizar una función que realice una copia de una cola\n");
                        c_resultado = c_ej2_copiar(c);
                        printf("Copia de la cola: \n");
                        c_mostrar(c_resultado);
                        printf("Cola original: \n");
                        c_mostrar(c);
                        c_destruir(c_resultado);
                    break;
                case 6: printf("f. Invertir el contenido de una cola sin destruir la cola original.\n");
                        c_resultado = c_ej2_invertir(c);
                        printf("Cola invertida: \n");
                        c_mostrar(c_resultado);
                        c_destruir(c_resultado);
                    break;
                case -1: printf("Saliendo del ejercicio 2...\n");
                    break;
                default: printf("Ingrese una opcion dentro del rango definido.\n");
                    break;
                }
            }
            break;
        case 3: printf("Ejercicio 3\n");
                printf("Cargue la cola 1.\n");
                c_cargar(c);    
                printf("Cargue la cola 2.\n");
                c_cargar(c_2);  
                if(c_ej3_iguales(c, c_2) == true){
                    printf("Las listas son iguales.\n");
                }else{
                    printf("Las listas no son iguales.\n");
                }
                c_destruir(c);
                c_destruir(c_2);
            break;
        case 4: printf("Ejercicio 4\n");
                printf("Cargue la cola.\n");
                c_cargar(c); 
                printf("Cola resultante: \n");
                c_resultado = c_ej4_colanorepetidos(c);
                c_mostrar(c_resultado);
                c_destruir(c_resultado);
            break;
        case 5: printf("Ejercicio 5\n");
                printf("Cargue la cola.\n");
                c_cargar(c);
                c_resultado = c_ej5_divisortotal(c);
                if(c_es_vacia(c_resultado)){
                    printf("COLA VACIA\n");
                }else{
                    while(!c_es_vacia(c_resultado)){
                        x = c_desencolar(c_resultado);
                        n = (*(bool*)x->valor);
                        if(n == true){
                            printf("Valor Total %d\n", x->clave); 
                        }else{
                            printf("Valor/es Parciales %d\n", x->clave); 
                        }
                    }
                }
            break;
        case 6: printf("Ejercicio 6\n");
                printf("Cargue la pila.\n");
                cargarpila(p);
                printf("Cargue la cola.\n");
                c_cargar(c);
                l_resultado = c_ej6_comunesapilaycola(p, c);
                ite = iterador(l_resultado);
                while(hay_siguiente(ite)){
                    x = siguiente(ite);
                    char_posiciones = (char*)x->valor;
                    printf("Clave : Pila : Cola \n");
                    printf("%d : %s\n", x->clave, char_posiciones);
                }
            break;    
        case 7: printf("Ejercicio 7\n");
                printf("Cargue la cola 1.\n");
                c_carga_solo_naturales(c);    
                printf("Cargue la cola 2.\n");
                c_carga_solo_naturales(c_2); 
                printf("Cargue la cola 3.\n");
                c_carga_solo_naturales(c_3);
                valor_tiempo = pedir_numero_entero("Ingrese el tiempo de atencion: \n");
                //validar que el tiempo no sea 0 ni negativo
                while(esEntero(valor_tiempo) == false || valor <= 0){
                    printf("Ingrese un numero natural.\n");
                    valor_tiempo = pedir_numero_entero("Ingrese el tiempo de atencion: \n");
                }
                valor = valor_tiempo;
                c_resultado = c_ej7_atenderclientes(c, c_2, c_3, valor);
                while (!c_es_vacia(c_resultado)) {
                    x = c_desencolar(c_resultado);
                    valor_aux = *((int*)x->valor);
                    printf("Cliente %d || Cola %d \n", x->clave, valor_aux);
                }
                c_destruir(c_resultado);
            break;
        case -1: printf("Saliendo del programa...\n");
            break;
        default: printf("Ingrese una opcion dentro del rango definido.\n");
            break;
        }
    }
    return 0;
}