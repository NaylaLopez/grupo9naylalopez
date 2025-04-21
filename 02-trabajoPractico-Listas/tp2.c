#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "..\libs\listas\headers\listas.h"
#include <string.h>
#include <math.h>
#include "..\libs\validaciones\headers\validaciones.h"
#include "..\libs\tipoElemento\headers\tipo_elemento.h"
#include "tp_2_listas_1.h"
#define MAX 100

//EJERCICIO 2

//a y b
Lista verElementosQueNoSeRepiten(Lista l1, Lista l2){
    Lista lista = l_crear(); 
    Iterador n1 = iterador(l1);
    while(hay_siguiente(n1)){ 
        TipoElemento valor1 = siguiente(n1);
        if(!l_buscar(l2, valor1->clave)){
            l_agregar(lista, valor1);
        }
    }
    return lista;
}

//c.
Lista verElementosRepetidos(Lista l1, Lista l2){
    Lista lista = l_crear(); 
    Iterador n1 = iterador(l1);
    while(hay_siguiente(n1)){
        TipoElemento valor1 = siguiente(n1);
        if(l_buscar(l2, valor1->clave)){
            l_agregar(lista, valor1);
        }
    }
    return lista;
}

//d.
float promedio(Lista l1){
    int suma = 0;
    int cantidad = l_longitud(l1);
    TipoElemento valor;
    Iterador n1 = iterador(l1);
    while(hay_siguiente(n1)){
        valor = siguiente(n1);
        suma += valor->clave;
    }
    return suma/cantidad;
}

//e.
TipoElemento minimo(Lista l1, int *cont){
    int contador = 0;
    *cont = 0;
    Iterador n1 = iterador(l1);
    if (!hay_siguiente(n1)) return NULL; 
    TipoElemento valor1 = siguiente(n1);
    TipoElemento aux = te_crear(valor1->clave);
    while(hay_siguiente(n1)){
        valor1 = siguiente(n1);
        contador++;
        if(aux->clave > valor1->clave){
            aux->clave = valor1->clave;
            *cont = contador;
        } 
    }
    return aux;
}

ResultadoValorMinimo valorMinimo(Lista l1, Lista l2){
    ResultadoValorMinimo result;
    TipoElemento lista1;
    TipoElemento lista2;
    int cont;
    int cont2;

    lista1 = minimo(l1, &cont);
    result.valor = lista1->clave;
    result.pos = cont;

    lista2 = minimo(l2, &cont2);
    result.valor_2 = lista2->clave;
    result.pos_2 = cont2;

    return result;
}

//EJERCICIO 3 

ResultadosMul multiplo(Lista l1, Lista l2){
    bool aux = true;
    int escalar;
    ResultadosMul solucion;
    solucion.esMultiplo = true;
    solucion.escalar = true;
    Iterador n1, n2;    
    n1 = iterador(l1);
    n2 = iterador(l2);
    TipoElemento valor_1 = siguiente(n1);
    TipoElemento valor_2 = siguiente(n2);
    
    if(valor_1->clave == 0){
        printf("No se puede dividir por cero.");
        solucion.esMultiplo = false;
        solucion.escalar = false;
        aux = false;
    } else {
        escalar = valor_2->clave / valor_1->clave;
    }
    while(hay_siguiente(n1) == true && hay_siguiente(n2) == true && aux == true){ 
        valor_1 = siguiente(n1);
        valor_2 = siguiente(n2);
        if(valor_1->clave != 0){
            if(valor_2->clave % valor_1->clave != 0){
            solucion.esMultiplo = false;
            aux = false;
            }
            if(escalar != valor_2->clave / valor_1->clave){
                escalar = -1;
                solucion.escalar = false;
            }
        } else {
            printf("No se puede dividir por cero.");
            aux = false;
            solucion.esMultiplo = false;
        }
        
    }
    solucion.numEscalar = escalar;
    return solucion;

}

//EJERCICIO 4

int CompararListas(Lista l1, Lista L2){
    int cont_l1 = 0, cont_l2 = 0, resul = -1;
    Iterador n1, n2;    
    n1 = iterador(l1);
    n2 = iterador(L2);
    TipoElemento valor_1, valor_2;
    while(hay_siguiente(n1) == true && hay_siguiente(n2) == true){
        valor_1 = siguiente(n1);
        valor_2 = siguiente(n2);
        if(valor_1->clave > valor_2->clave){
            cont_l1++;
        }else if(valor_1->clave < valor_2->clave){
            cont_l2++;
        } else {
            resul = 2;
        }
    
    }
    if(cont_l1 > cont_l2){
        resul = 1;
    } else if(cont_l1 < cont_l2){
        resul = 0;
    }
    return resul;

}

//EJERCICIO 5

void hacerPolinomio(Lista list){
    char auxiliar[MAX];
    double grado;
    float* coeficiente;
    TipoElemento x;
    printf("Ingrese el grado del polinomio: \n");
    fgets(auxiliar, MAX, stdin);
    auxiliar[strcspn(auxiliar, "\n")] = '\0';
    grado = validar_numero(auxiliar);
    while(grado < 0 || !esEntero(grado)){
        printf("El grado del polinomio debe ser un numero natural. Intentelo nuevamente\n");
        printf("Ingrese el grado del polinomio: \n");
        fgets(auxiliar, MAX, stdin);
        auxiliar[strcspn(auxiliar, "\n")] = '\0';
        grado = validar_numero(auxiliar);
    }
    for(int i = 0; i <= grado; i++){
        coeficiente = (float*)malloc(sizeof(float));
        printf("Ingresa el coeficiente %d: ", i);
        fgets(auxiliar, MAX, stdin);
        auxiliar[strcspn(auxiliar, "\n")] = '\0';
        *coeficiente = validar_numero(auxiliar);
        x = te_crear_con_valor(i, coeficiente);
        l_agregar(list, x);
    }
}

float evaluarPolinomio(Lista list, float x){
    float resultado = 0; 
    Iterador n;
    n = iterador(list);
    TipoElemento coeficiente; 
    while(hay_siguiente(n)==true){
        coeficiente = siguiente(n);
        resultado += *((float*)coeficiente->valor)*pow(x, coeficiente->clave);
    }
    return resultado;
}

Lista calcularRango(Lista list, double x, double y, double sumando){ 
    Lista resultado = l_crear();
    float* valor;
    int aux = 0;
    float n1;
    TipoElemento p;
    for(float i = x; i <= y; i+=sumando){
        valor = (float*)malloc(sizeof(float));
        *valor = evaluarPolinomio(list, i);
        p = te_crear_con_valor(aux, valor);
        l_agregar(resultado, p);
        aux++;
    }
    return resultado;
}

//EJERCICIO 6 

bool esSublista(Lista l1, Lista l2){
    bool aux = true;
    bool resultado = true;
    Iterador n1, n2;    
    TipoElemento valor_1, valor_2;
    n2 = iterador(l2); 
    while (hay_siguiente(n2) && aux == true) {
        valor_2 = siguiente(n2);
        aux = false;        
        n1 = iterador(l1);          
        while (hay_siguiente(n1) && aux == false) {
            valor_1 = siguiente(n1);
            if (valor_2->clave == valor_1->clave) {
                aux = true;
            }
        }
        if (aux == false) {
            resultado = false; 
        }
    }
    return resultado;
}
