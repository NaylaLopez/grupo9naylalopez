#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "..\libs\pilas\headers\pilas.h"
#include <string.h>
#include <math.h>
#include "..\libs\validaciones\headers\validaciones_pilas.h"
#include "..\libs\tipoElemento\headers\tipo_elemento.h"
#include "tp_3_pilas.h"

static const int TAMANIO_MAXIMO = 10;

/*EJERCICIO 2*/

//a.
bool p_ej2_existeclave(Pila p, int clave){
    bool resultado = false, apilo = true;
    Pila p_auxiliar = p_crear();
    TipoElemento valor, num;
    while(!p_es_vacia(p)){
        num = p_desapilar(p);
        valor = te_crear(num->clave);
        if(valor->clave == clave){
            resultado = true;
        }  
        apilo = p_apilar(p_auxiliar, valor);
        if(apilo == false){
            printf("No se pudo guardar el elemento.\n");
            return false;
        } 
    }
    p_intercambiar(p, p_auxiliar);
    return resultado;
}

//b.
Pila p_ej2_colocarelemento(Pila p, int posicionordinal, TipoElemento x){
    Pila pila_nueva = p_crear();
    Pila pila_auxiliar = p_crear();
    int tamanio = 1;
    TipoElemento valor, num, aux_valor;
    while(!p_es_vacia(p)){
        num = p_desapilar(p);
        aux_valor = te_crear(num->clave);
        if(tamanio == posicionordinal){
            
            valor = te_crear(x->clave);
            p_apilar(pila_auxiliar, valor);
            valor = te_crear(num->clave);
            p_apilar(pila_auxiliar, valor);   
        }else{
            
            valor = te_crear(num->clave);
            p_apilar(pila_auxiliar, valor);
        }
        tamanio++;
        p_apilar(pila_nueva, aux_valor);
    }
    p_intercambiar(p, pila_nueva);
    p_intercambiar(pila_nueva, pila_auxiliar);
    if(tamanio <= posicionordinal){
        printf("La posicion elegida es mayor que el tamanio de la pila.\n");
        return p_crear();
    }
    return pila_nueva;
}
//c.
Pila p_ej2_eliminarclave(Pila p, int clave){
    Pila pila_auxiliar = p_crear();
    Pila pila_nueva = p_crear();
    bool salir = false;
    TipoElemento valor, num, valor_aux;
    while(!p_es_vacia(p)){
        num = p_desapilar(p);
        valor_aux = te_crear(num->clave);
        if(num->clave == clave && salir == false){
           p_apilar(pila_auxiliar, valor_aux); 
           salir = true;      
        } else {
            valor = te_crear(num->clave);
            p_apilar(pila_nueva, valor);
            p_apilar(pila_auxiliar, valor_aux);
        }
    }
    p_intercambiar(p, pila_auxiliar);    
    if(salir == false){
        printf("El clave no existe en la pila.\n");
        return p_crear();
    }
    return pila_nueva;
}

//d.
Pila p_ej2_intercambiarposiciones(Pila p, int pos1, int pos2){
    Pila pila_nueva = p_crear();
    Pila pila_auxiliar = p_crear();
    int tamanio = 1;
    bool salir = false;
    TipoElemento valor, num, valor_aux;;
    int valor_2, valor_1;
    if(pos1 == pos2){
        return p;
    } 
    while(!p_es_vacia(p)){
        num = p_desapilar(p);
        valor = te_crear(num->clave);
        p_apilar(pila_auxiliar, valor);
        if(tamanio == pos1){
            valor_1 = valor->clave;
        }else if(tamanio == pos2){
            valor_2 = valor->clave;
        }
        tamanio++;
    }
    if(pos1 > tamanio || pos2 > tamanio){
        printf("Los tamanios no son compatibles con el tamanio de la pila.");
        return p_crear();
    }
    tamanio--;
    while(!p_es_vacia(pila_auxiliar)){
        num = p_desapilar(pila_auxiliar);
        valor = te_crear(num->clave);
        valor_aux = te_crear(num->clave);
        if(tamanio == pos1){
            valor = te_crear(valor_2);
            p_apilar(pila_nueva, valor);
        }else if(tamanio == pos2){
            valor = te_crear(valor_1);
            p_apilar(pila_nueva, valor);
        }else{
            p_apilar(pila_nueva, valor);
        }
        tamanio--;
        p_apilar(p, valor_aux);
    }
    return pila_nueva;
}

//e.
Pila p_ej2_duplicar(Pila p){
    Pila pila_duplicada = p_crear();
    Pila pila_auxiliar = p_crear();
    int tamanio = 0;
    TipoElemento valor, num, valor_duplicado;
    while(!p_es_vacia(p)){
        num = p_desapilar(p);
        valor = te_crear(num->clave); 
        valor_duplicado = te_crear(num->clave); 
        p_apilar(pila_auxiliar, valor);
        p_apilar(pila_auxiliar, valor_duplicado);
        p_apilar(pila_duplicada, valor);
        tamanio = tamanio + 2;
    }
    p_intercambiar(p, pila_duplicada);
    p_intercambiar(pila_duplicada, pila_auxiliar);
    if(tamanio > TAMANIO_MAXIMO){
        printf("La cantidad de elementos supera la capacidad de la pila.\n");
        return p_crear();
    }
    return pila_duplicada;
}

//f.
int p_ej2_cantidadelementos(Pila p){
    int cantidad = 0;
    Pila p_auxiliar = p_crear();
    TipoElemento num, valor;
    while(!p_es_vacia(p)){
        num = p_desapilar(p);
        valor = te_crear(num->clave);
        p_apilar(p_auxiliar, valor);
        cantidad++;
    }
    p_intercambiar(p, p_auxiliar);
    return cantidad;
}

/*EJERCICIO 3*/

bool p_ej3_iguales(Pila p1, Pila p2){
    bool iguales = true;
    Pila p_auxiliar = p_crear();
    TipoElemento elemento_p1, elemento_p2, aux_1, aux_2;
    while(!p_es_vacia(p1)){
        if(p_es_vacia(p2)){
            printf("Las longitudes no son iguales.\n");
            return iguales = false;
        }
        elemento_p1 = p_desapilar(p1);
        aux_1 = te_crear(elemento_p1->clave);
        elemento_p2 = p_desapilar(p2);
        aux_2 = te_crear(elemento_p2->clave);
        if(aux_1->clave != aux_2->clave){
            iguales = false;
        }
        
        p_apilar(p_auxiliar, aux_1); 
        p_apilar(p_auxiliar, aux_2); 
    }
    if(!p_es_vacia(p2)){
        printf("Las longitudes no son iguales.\n");
        return iguales = false;
    }
    while(!p_es_vacia(p_auxiliar)){
        aux_2 = p_desapilar(p_auxiliar);
        elemento_p2 = te_crear(aux_2->clave);
        p_apilar(p2, elemento_p2);
        aux_1 = p_desapilar(p_auxiliar);
        elemento_p1 = te_crear(aux_1->clave);
        p_apilar(p1, elemento_p1);
    }
    return iguales;
}

/*EJERCICIO 4*/
#define MAX_STR 10
char*  p_ej4_cambiarbase(int nrobasedecimal, int nrootrabase){
    int resto, cont = 1;
    Pila pila = p_crear();
    TipoElemento num;

    if (nrobasedecimal < 0) {
        nrobasedecimal = -nrobasedecimal;  // Hacer el numero positivo para la conversion
    }

    while(nrobasedecimal >= nrootrabase){
        resto = nrobasedecimal % nrootrabase;
        nrobasedecimal = nrobasedecimal / nrootrabase;
        num = te_crear(resto);
        p_apilar(pila, num);
        cont++;
    }
    num = te_crear(nrobasedecimal);
    p_apilar(pila, num);
    char *resultado= (char*)malloc(cont+2);
    char *auxiliar = resultado;

    while(!p_es_vacia(pila)){
        num = p_desapilar(pila);
        int clave = num->clave;
        char digito = (clave < 10) ? ('0' + clave) : ('A' + (clave - 10));
        *auxiliar = digito;
        auxiliar++;
    }
    *auxiliar = '\0';
    return resultado;
}

/*EJERCICIO 5*/

Pila  p_ej5_invertir(Pila p){
    Pila p_auxiliar = p_crear();
    Pila p_nuevo = p_crear();
    TipoElemento num, valor, valor_aux;
    while(!p_es_vacia(p)){
        num = p_desapilar(p);
        valor = te_crear(num->clave);
        valor_aux = te_crear(num->clave);
        p_apilar(p_nuevo, valor);
        p_apilar(p_auxiliar, valor_aux);
    }
    p_intercambiar(p, p_auxiliar);
    return p_nuevo;
}

/*EJERCICIO 6*/

//SOLUCION ITERATIVA
Pila p_ej6_eliminarclave(Pila p, int clave){
    Pila pila_auxiliar = p_crear();
    Pila pila_nueva = p_crear();
    TipoElemento valor, num, valor_aux;
    bool aux = false;
    while(!p_es_vacia(p)){
        num = p_desapilar(p);
        valor_aux = te_crear(num->clave);
        p_apilar(pila_auxiliar, valor_aux);
    }

    while(!p_es_vacia(pila_auxiliar)){
        num = p_desapilar(pila_auxiliar);
        valor_aux = te_crear(num->clave);
        if(num->clave == clave){
           p_apilar(p, valor_aux);    
           aux = true;
        } else {
            valor = te_crear(num->clave);
            p_apilar(pila_nueva, valor);

            p_apilar(p, valor_aux);
        }
        
    }   
    if(aux == false){
        printf("El valor no se encuentra en la pila.\n");
        return p_crear();
    }
    return pila_nueva;
}

//SOLUCION RECURIVA
Pila p_ej6_eliminarclave_r(Pila p, int clave){
    if(p_es_vacia(p)){
        return p_crear(); 
    }
    TipoElemento num = p_desapilar(p);
    Pila pila_nueva = p_ej6_eliminarclave_r(p, clave); 

    if(num->clave != clave){
        TipoElemento valor = te_crear(num->clave); 
        p_apilar(pila_nueva, valor);    
    }       
    p_apilar(p, num); 
    return pila_nueva;
}

/*EJERCICIO 7*/

Pila p_ej7_elementoscomunes(Pila p1, Pila p2) {
    Pila p_solucion = p_crear();
    Pila p_aux1 = p_crear();
    Pila p_aux2 = p_crear();
    TipoElemento valor1, valor2, aux;

    while(!p_es_vacia(p1)) {
        valor1 = p_desapilar(p1);
        bool encontrado = false;
        while(!p_es_vacia(p2)) {
            valor2 = p_desapilar(p2);
            if(valor2->clave == valor1->clave) {
                encontrado = true;
            }
            p_apilar(p_aux2, valor2);
        }
        p_intercambiar(p2, p_aux2);
        if(encontrado) {
            aux = te_crear(valor1->clave);
            p_apilar(p_solucion, aux);
        }
        while(!p_es_vacia(p1)) {
            valor2 = p_desapilar(p1);
            if(valor2->clave != valor1->clave) {
                p_apilar(p_aux1, valor2);
            }
        }
        p_intercambiar(p1, p_aux1);
    }

    return p_solucion;
}

/*EJERCICIO 8*/
Pila p_ej8_sacarrepetidos(Pila p) {
    Pila aux = p_crear();
    Pila resultado = p_crear();
    int conteos[100] = {0}; 
    while(!p_es_vacia(p)) {
        TipoElemento elem = p_desapilar(p);
        conteos[elem->clave]++;
        p_apilar(aux, elem);
    }
    while(!p_es_vacia(aux)) {
        TipoElemento elem = p_desapilar(aux);
        p_apilar(p, elem);
    }
    for(int i = 0; i < 100; i++) {
        if(conteos[i] > 0) {
            TipoElemento nuevo = te_crear_con_valor(i, (void*)(intptr_t)conteos[i]);
            p_apilar(resultado, nuevo);
        }
    }
    return resultado;
}