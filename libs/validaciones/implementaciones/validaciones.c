#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "..\..\listas\headers\listas.h"
#include "..\..\tipoElemento\headers\tipo_elemento.h"
#include "..\headers\validaciones.h"
#define MAX 100

void cargarLista(Lista lis){
    TipoElemento x;
    int tamanio;
    double aux_tamanio, ejercicio;
    char auxiliar[MAX];
    printf("Ingrese el tamanio de la lista\n");
    fgets(auxiliar, MAX, stdin);
    auxiliar[strcspn(auxiliar, "\n")] = '\0';
    aux_tamanio = validar_numero(auxiliar); 
    while(aux_tamanio <= 0 || aux_tamanio > 100 || !esEntero(aux_tamanio)){
        printf("El tamanio debe ser un valor natural distinto a 0 y menor a 100. Intentelo nuevamente.\n");
        printf("Ingrese el tamanio de la lista\n");
        fgets(auxiliar, MAX, stdin);
        auxiliar[strcspn(auxiliar, "\n")] = '\0';
        aux_tamanio = validar_numero(auxiliar);
    }
    tamanio = aux_tamanio;
    for(int i = 0; i < tamanio; i++){
        printf("Ingrese el valor %d: ", i);
        fgets(auxiliar, MAX, stdin);
        auxiliar[strcspn(auxiliar, "\n")] = '\0';
        ejercicio = validar_numero(auxiliar);
        while(!esEntero(ejercicio)){
            printf("Solo se permiten numeros enteros. Intente nuevamente.\n");
            printf("Ingrese el valor %d: \n", i);
            fgets(auxiliar, MAX, stdin);
            auxiliar[strcspn(auxiliar, "\n")] = '\0';
            ejercicio = validar_numero(auxiliar);
        }
        x = te_crear(ejercicio);
        l_agregar(lis, x);
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
           printf("Opcion no valida. Por favor, ingrese un número: \n");
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