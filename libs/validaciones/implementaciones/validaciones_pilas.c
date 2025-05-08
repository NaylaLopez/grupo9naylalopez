#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "..\..\listas\headers\listas.h"
#include "..\..\colas\headers\colas.h"
#include "..\..\pilas\headers\pilas.h"
#include "..\headers\validaciones_pilas.h"
#include "..\..\tipoElemento\headers\tipo_elemento.h"
static const int TAMANIO_MAXIMO = 10;
#define MAX 100

//---------------------Validaciones Listas------------------------------
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

//----------------------Validaciones Pilas----------------------------------------
void cargarpila(Pila pil) {
    int elemento, tamanio; 
    TipoElemento valor;
    tamanio = pedir_numero_entero("Ingrese el tamanio de la pila: ");
    while(tamanio > MAX || tamanio < 0){
        printf("El tamanio debe ser >= 0 y < 10.\n");
        tamanio = pedir_numero_entero("Ingrese el tamanio de la pila: ");
    }
    
    for(int i = 0; i < tamanio; i++){
        elemento = pedir_numero("Ingrese el valor: ");
        valor = te_crear(elemento);
        p_apilar(pil, valor);
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

//----------------------Validaciones Colas----------------------------------------

Cola c_destruir(Cola c){
    while(!c_es_vacia(c)){
        c_desencolar(c);
    }
    return c;
}

int pedir_numero(const char *mensaje){
    char auxiliar[MAX];
    int numero;
    printf("%s", mensaje);
    fgets(auxiliar, MAX, stdin);
    auxiliar[strcspn(auxiliar, "\n")] = '\0';
    numero = validar_numero(auxiliar);

    return numero;
}

int pedir_numero_entero(const char *mensaje){
    char auxiliar[MAX];
    double numero;
    int solucion;
    printf("%s", mensaje);
    fgets(auxiliar, MAX, stdin);
    auxiliar[strcspn(auxiliar, "\n")] = '\0';
    numero = validar_numero(auxiliar);
    while(esEntero(numero) == false || numero < 0){
        printf("Ingrese un numero natural.\n");
        printf("%s", mensaje);
        fgets(auxiliar, MAX, stdin);
        auxiliar[strcspn(auxiliar, "\n")] = '\0';
        numero = validar_numero(auxiliar);
    }
    solucion = numero;
    return solucion;
}

Cola c_cargar(Cola cola){
    int tamanio, num;
    TipoElemento valor;
    tamanio = pedir_numero("Ingrese el tamanio de la cola: ");
    while(tamanio > MAX || tamanio < 0){
        printf("El tamanio debe ser >= 0 y < 10.\n");
        tamanio = pedir_numero("Ingrese el tamanio de la cola: ");
    }
    for(int i = 0; i < tamanio; i++){
        num = pedir_numero("Ingrese el valor: ");
        valor = te_crear(num);
        c_encolar(cola, valor);
    }
    return cola;
}

Cola c_carga_solo_naturales(Cola cola){
    int tamanio, num;
    TipoElemento valor;
    tamanio = pedir_numero_entero("Ingrese el tamanio de la cola: ");
    while(tamanio > MAX || tamanio < 0){
        printf("El tamanio debe ser >= 0 y < 10.\n");
        tamanio = pedir_numero_entero("Ingrese el tamanio de la cola: ");
    }
    for(int i = 0; i < tamanio; i++){
        num = pedir_numero_entero("Ingrese el valor: ");
        valor = te_crear(num);
        c_encolar(cola, valor);
    }
    return cola;
}

void c_intercambiar(Cola auxiliar, Cola original){
    Cola cola_aux = c_crear();
    TipoElemento te, aux;
    while(!c_es_vacia(auxiliar)){
        te = c_desencolar(auxiliar);
        aux = te_crear(te->clave);
        c_encolar(original, aux);
    }
}
