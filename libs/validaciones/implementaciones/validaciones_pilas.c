#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "..\..\pilas\headers\pilas.h"
#include "..\..\tipoElemento\headers\tipo_elemento.h"
#include "..\headers\validaciones_pilas.h"


static const int TAMANIO_MAXIMO = 10;
#define MAX 100

void cargarpila(Pila pil) {
    int tamanio, valor;
    char entrada[MAX];

    printf("Ingrese el tamanio de la pila: \n");
    while (scanf("%d", &tamanio) != 1 || tamanio <= 0 || tamanio > TAMANIO_MAXIMO) { 
        printf("Tamanio invalido. Por favor, ingrese un numero entero positivo menor a 10: \n");
        limpiar_buffer();
    }

    printf("Ingrese los elementos de la pila (solo numeros):\n");
    for (int i = 0; i < tamanio; i++) {
        printf("Elemento %d: ", i + 1);
        while (true) {
            scanf("%s", entrada);
            char *endptr;
            valor = strtol(entrada, &endptr, 10); 
            if (*endptr == '\0') {
                break; 
            } else {
                printf("Entrada invalida. Por favor, ingrese un numero: \n");
            }
        }
        TipoElemento e = te_crear(valor);
        p_apilar(pil, e);
    }
}

void limpiar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); 
}

void vaciar_pila(Pila p) {
    while (!p_es_vacia(p)) {
        p_desapilar(p);
    }
}

double validar_numero(char *valor){
    char *resultado;
    double n1;
    bool valido = false;
    while (!valido){
       n1 = strtod(valor, &resultado); 
       valido = true;
       if (valor == resultado || *resultado != '\0'){
           printf("Opcion no valida. Por favor, ingrese un numero: \n");
           fgets(valor, MAX, stdin);
           valor[strcspn(valor, "\n")] = '\0';
           valido = false;
       }
    }
    return n1;
}

bool esEntero(double valor){
    return valor == (double)(long)valor;
}

void p_intercambiar(Pila p_original, Pila p_aux){
    TipoElemento n_orig, n_aux;
    bool salir = true;
    while(!p_es_vacia(p_aux)){
        n_aux = p_desapilar(p_aux);
        n_orig = te_crear(n_aux->clave);
        salir = p_apilar(p_original, n_orig);
        if(salir == false){
            printf("No se pudo guardar el elemento.\n");
            return;
        }
    }
}



