#include <stdbool.h>
#include "..\..\pilas\headers\pilas.h"
#include "..\..\colas\headers\colas.h"
#include "..\..\tipoElemento\headers\tipo_elemento.h"
#ifndef VALIDACIONES_H
#define VALIDACIONES_H

//-------Validaciones Pilas-------
void cargarpila(Pila pil);
void limpiar_buffer();

double validar_numero(char *valor);
bool esEntero(double valor);
void p_intercambiar(Pila p1, Pila p2);
void vaciar_pila(Pila p);

//-------Validaciones Colas-------
void c_intercambiar(Cola auxiliar, Cola original);
Cola c_cargar(Cola cola);
Cola c_destruir(Cola c);
int pedir_numero(const char *mensaje);
Cola c_carga_solo_naturales(Cola cola);
int pedir_numero_entero(const char *mensaje);
#endif