#include <stdbool.h>
#include "..\..\pilas\headers\pilas.h"
#include "..\..\tipoElemento\headers\tipo_elemento.h"
#ifndef VALIDACIONES_H
#define VALIDACIONES_H

void cargarpila(Pila pil);
void limpiar_buffer();

double validar_numero(char *valor);
bool esEntero(double valor);
void p_intercambiar(Pila p1, Pila p2);
void vaciar_pila(Pila p);

#endif