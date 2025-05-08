#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "tp_4_colas.h"
#include "..\libs\colas\headers\colas.h"
#include "..\libs\pilas\headers\pilas.h"
#include "..\libs\listas\headers\listas.h"
//#include "..\libs\validaciones\headers\validaciones.h"
#include "..\libs\validaciones\headers\validaciones_pilas.h"


//EJERCICIO 2

//a.
bool c_ej2_existeclave(Cola c, int clave){
    Cola cola_aux = c_crear();
    TipoElemento te, aux;
    bool resul = false;
    while(!c_es_vacia(c)){
        te = c_desencolar(c);
        aux = te_crear(te->clave);
        if(aux->clave == clave){
            resul = true;
        }
        c_encolar(cola_aux, aux);
    }
    c_intercambiar(cola_aux, c);
    return resul;
}

//b.
Cola c_ej2_colarelemento(Cola c, int posicionordinal, TipoElemento X){
    Cola cola_aux = c_crear();
    Cola cola_nueva = c_crear();
    TipoElemento te, aux, valor;
    int pos = 1;
    if(c_es_llena(c)){
        printf("La cola esta llena.\n");
        return c;
    }
    while(!c_es_vacia(c)){
        te = c_desencolar(c);
        aux = te_crear(te->clave);
        valor = te_crear(te->clave);
        if(pos == posicionordinal){
            c_encolar(cola_nueva, X);
        }
        c_encolar(cola_nueva, valor);
        c_encolar(cola_aux, aux);
        pos++;
    }
    c_intercambiar(cola_aux, c);
    if(pos <= posicionordinal){
        printf("La posicion es mayor al tamanio de la cola.\n");
        return c;
    }
    return cola_nueva;
}

//c.
Cola c_ej2_sacarelemento(Cola c, int clave){
    Cola cola_aux = c_crear();
    Cola cola_nueva = c_crear();
    TipoElemento te, aux, valor;
    bool x = false;
    while(!c_es_vacia(c)){
        te = c_desencolar(c);
        aux = te_crear(te->clave);
        valor = te_crear(te->clave);
        if(aux->clave != clave){
            c_encolar(cola_nueva, valor);  
        }
        if(aux->clave == clave){
            x = true;
        }
        c_encolar(cola_aux, aux);
    }

    c_intercambiar(cola_aux, c);
    
    if(x == false){
        printf("La clave no existe en la cola.\n");
        return cola_nueva;
    } 
    if(c_es_vacia(cola_nueva)){
            printf("Todos los elementos eran la clave.\n");
            return cola_nueva;
    }
    return cola_nueva;  
}

//d.
int c_ej2_contarelementos(Cola c){
    Cola cola_aux = c_crear();
    TipoElemento te, aux;
    int resul = 0;
    if(c_es_vacia(c)){
        return resul;
    }    
    while(!c_es_vacia(c)){
        te = c_desencolar(c);
        aux = te_crear(te->clave);
        c_encolar(cola_aux, aux);
        resul++;
    }
    c_intercambiar(cola_aux, c);
    return resul;
}

//e.
Cola c_ej2_copiar(Cola c){
    Cola cola_copia = c_crear();
    Cola cola_aux = c_crear();
    TipoElemento te, aux; 
    if(c_es_vacia(c)){
        return c;
    }  
    while(!c_es_vacia(c)){
        te = c_desencolar(c);
        aux = te_crear(te->clave);
        c_encolar(cola_aux, aux); 
        c_encolar(cola_copia, te);
    }
    c_intercambiar(cola_aux, c);
    return cola_copia;
}

//f.
Cola c_ej2_invertir(Cola c){
    Pila pila_aux = p_crear();
    Cola cola_aux = c_crear();
    TipoElemento Paux, Caux, te;
    if(c_es_vacia(c)){
        return cola_aux;
    }
    while(!c_es_vacia(c)){
        te = c_desencolar(c);
        Paux = te_crear(te->clave);
        p_apilar(pila_aux, Paux); 
        c_encolar(cola_aux, te);
    }
    c_intercambiar(cola_aux, c);
    while(!p_es_vacia(pila_aux)){
        Paux = p_desapilar(pila_aux);
        Caux = te_crear(Paux->clave);
        c_encolar(cola_aux, Caux);
    }
    return cola_aux;
}

//EJERCICIO 3
bool c_ej3_iguales(Cola c1, Cola c2){
    Cola cola_aux = c_crear();
    TipoElemento te1, te2, aux1, aux2;
    bool iguales = true;
    if(c_ej2_contarelementos(c1) != c_ej2_contarelementos(c2)){
        printf("Las colas no tienen la misma longitud.\n");
        return false;
    }else{
        int cantidad = c_ej2_contarelementos(c1);
        for(int i = 0; i < cantidad; i++){
            te1 = c_desencolar(c1);
            te2 = c_desencolar(c2);
            aux1 = te_crear(te1->clave);
            aux2 = te_crear(te2->clave);
            c_encolar(cola_aux, aux1);
            if(te1->clave != te2->clave){
                iguales = false;
            }
            c_encolar(c1, te1);
            c_encolar(c2, te2);
        }
    }
    return iguales;
}

//EJERCICIO 4
Cola  c_ej4_colanorepetidos(Cola c){
    Cola cola_aux = c_crear();
    Cola cola_nueva = c_crear();
    Cola cola_resultado = c_crear();
    bool boleano = false;
    int primeravuelta = 0;
    TipoElemento te, teaux, teaux1, teaux2;
    while (!c_es_vacia(c))
    {
        te = c_desencolar(c);
        teaux2 = te_crear(te->clave);
        if (primeravuelta != 1)
        {
            c_encolar(cola_aux, te);
        }
        while (!c_es_vacia(c))
        {
            teaux = c_desencolar(c);
            teaux1 =te_crear(teaux->clave);
            if (te->clave != teaux->clave)
            {
                c_encolar(cola_nueva, teaux1);
            }else boleano = true;
            if (primeravuelta != 1)
            {
                c_encolar(cola_aux, teaux);
            }
        }
        primeravuelta = 1;
        if (!boleano)
        {
            c_encolar(cola_resultado, teaux2);
        }
        c_intercambiar(cola_nueva, c);
        boleano = false;       
    }
    c_intercambiar(cola_aux, c);
    return cola_resultado; 
}

//EJERCICIO 5 
Cola c_ej5_divisortotal(Cola c){
    Cola ColaAux = c_crear();
    Cola ColaResultado = c_crear();
    Cola ColaDuplicada = c_crear();
    TipoElemento te; 
    TipoElemento aux; //para guardar los elementos en pila auxiliar
    TipoElemento resul; //Para guardar los datos en la cola resultado
    TipoElemento dupli;
    int Max = 0, Min, contador_actual, mitad, resto, cantidad;
    bool salir = false;
    cantidad = c_ej2_contarelementos(c);
    //Obtengo el %50 y redondeo para arriba
    mitad = (cantidad % 2 == 0) ? cantidad / 2 : (cantidad / 2) + 1;
//---------Buscar el MAX y MIN y copio en ColaAux para no perder la cola------
    aux = c_recuperar(c);
    Min = aux->clave;
    while(!c_es_vacia(c)){
        aux = c_desencolar(c);
        if(aux->clave < Min){
            Min = aux->clave;
        }
        if(aux->clave > Max){
            Max = aux->clave;
        }
        //para la pila auxiliar
        te = te_crear(aux->clave); 
        c_encolar(ColaAux, te);
        //para la duplicada
        dupli = te_crear(aux->clave);
        c_encolar(ColaDuplicada, dupli);
    }
    Max = Max/2;
    c_intercambiar(ColaAux, c);
//------------Evaluo los divisores parciales-----------
    for(int divisor = Max; divisor > Min; divisor--){
        int contador = 0;
        while(!c_es_vacia(c)) {
            aux = c_desencolar(c);
            if (aux->clave % divisor == 0){
                contador++;
            } 
            c_encolar(ColaAux, aux);
        }
        c_intercambiar(ColaAux, c);
        if(contador >= mitad){
            bool *es_parcial = malloc(sizeof(bool));
            *es_parcial = false;
            te = te_crear_con_valor(divisor, es_parcial);
            c_encolar(ColaResultado, te);
        }
    }
//------------Evaluo el divisor total-------------
        while(!c_es_vacia(c) && salir != true){
            aux = c_desencolar(c);
            resto = aux->clave % Min;
            if(resto != 0){
                salir = true;
            }
            te = te_crear(aux->clave);
            c_encolar(ColaAux, te);  
        }
//----------no pierdo la pila original------------
        c_intercambiar(ColaAux, c);
        if(salir != true){
            bool *es_total = malloc(sizeof(bool));
            *es_total = true;
            resul = te_crear_con_valor(Min, es_total); 
            c_encolar(ColaResultado, resul);
        }
        return ColaResultado;
}

//EJERCICIO 6

Lista c_ej6_comunesapilaycola(Pila p, Cola c){
    Cola c_aux = c_crear();
    Pila p_aux = p_crear();
    Lista l_resultado = l_crear();
    TipoElemento te_cola, v_cola, te_pila, v_pila, nuevo;
    int pos_pila = 1, pos_cola;
    char *posiciones;
    p_intercambiar(p_aux, p); 
    while(!p_es_vacia(p_aux)){
        te_pila = p_desapilar(p_aux);
        v_pila = te_crear(te_pila->clave);
        pos_cola = 1;
        while(!c_es_vacia(c)){
            te_cola = c_desencolar(c);
            v_cola = te_crear(te_cola->clave);

            if(v_pila->clave == v_cola->clave){
                posiciones = malloc(sizeof(char)*20);
                sprintf(posiciones, "%d : %d", pos_pila, pos_cola);
                nuevo = te_crear_con_valor(v_pila->clave, posiciones);
                l_agregar(l_resultado, nuevo);
            }
            c_encolar(c_aux, v_cola);
            pos_cola++;
        }
        c_intercambiar(c_aux, c);
        p_apilar(p, te_pila);
        pos_pila++;
    }
    return l_resultado;
}

//EJERCICIO 7

Cola c_ej7_atenderclientes(Cola c1, Cola c2, Cola c3, int tiempoatencion){
    Cola c1_copia = c_ej2_copiar(c1);
    Cola c2_copia = c_ej2_copiar(c2);
    Cola c3_copia = c_ej2_copiar(c3);
    Cola cola_resultados = c_crear();

    int cliente_actual_n1 = 1;
    int cliente_actual_n2 = 1;
    int cliente_actual_n3 = 1;

    while(!c_es_vacia(c1_copia) || !c_es_vacia(c2_copia) || !c_es_vacia(c3_copia)){     
        //cliente 1
        if(!c_es_vacia(c1_copia)){
            TipoElemento cliente_1 = c_recuperar(c1_copia);
            cliente_1->clave -= tiempoatencion;
            if(cliente_1->clave <= 0){
                //guardo
                int *atendido_c1 = (int*) malloc(sizeof(int));
                *atendido_c1 = 1;
                TipoElemento ya_atendido_c1 = te_crear_con_valor(cliente_actual_n1, atendido_c1);
                c_encolar(cola_resultados, ya_atendido_c1);
                c_desencolar(c1_copia);
                cliente_actual_n1++;
            }
        }

        //cliente 2
        if(!c_es_vacia(c2_copia)){
            TipoElemento cliente_2 = c_recuperar(c2_copia);
            cliente_2->clave -= tiempoatencion;
            if(cliente_2->clave <= 0){
                //guardo
                int *atendido_c2 = (int*) malloc(sizeof(int));
                *atendido_c2 = 2;
                TipoElemento ya_atendido_c2 = te_crear_con_valor(cliente_actual_n2, atendido_c2);
                c_encolar(cola_resultados, ya_atendido_c2);
                c_desencolar(c2_copia);
                cliente_actual_n2++;
            }
        }

        //cliente 3
        if(!c_es_vacia(c3_copia)){
            TipoElemento cliente_3 = c_recuperar(c3_copia);
            cliente_3->clave -= tiempoatencion;
            if(cliente_3->clave <= 0){
                //guardo
                int *atendido_c3 = (int*) malloc(sizeof(int));
                *atendido_c3 = 3;
                TipoElemento ya_atendido_c3 = te_crear_con_valor(cliente_actual_n3, atendido_c3);
                c_encolar(cola_resultados, ya_atendido_c3);
                c_desencolar(c3_copia);
                cliente_actual_n3++;
            }
        }
    }
    return cola_resultados;
}