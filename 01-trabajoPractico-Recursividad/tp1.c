#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "tp_1_recursividad.h"

//EJERCICIO 1
bool palindromo(char *vec){
    int i = strlen(vec);
    if(i <= 1){ 
        return true;
    }
    if(tolower(vec[0]) != tolower(vec[i - 1])){
        return false;
    }
    char temp = vec[i - 1];
    vec[i - 1] = '\0';

    bool resultado = palindromo(vec + 1);

    vec[i - 1] = temp;

    return resultado;
}

//EJERCICIO 2
int producto(int m, int n){
    if(n == 0){
        return 0;
    }
    if(n < 0){ 
        return -producto(m, -n);
    } else {
        return m + producto(m, (n - 1));
    }
}

//EJERCICIO 3
int terminoSeridFibonacci(int k) {
    if (k == 1 || k == 2) {
        return 1;
    }
    return terminoSeridFibonacci(k - 1) + terminoSeridFibonacci(k - 2);
}

//EJERCICIO 4
float division(int m, int n) {
    if (m < n) {
    
        if (m != 0) {
            return (m * 100000.0f / n) / 100000.0f;
        }
        return 0;
    }
    return 1 + division(m - n, n);
}

//EJERCICIO 5
void aux(char *nuevo, const char *original, int tam, int inicio, int cont){
    if (original[inicio] == '\0') {
        return;
    }
    if(cont == 3){
        nuevo[tam] = '.';
        aux(nuevo, original, tam - 1, inicio, 0);
    } else{
        nuevo[tam] = original[inicio];  
        aux(nuevo, original, tam - 1, inicio + 1, cont + 1);
    }
}

void invertido(char vector[], int inicio, int final){
    char aux;
    if(inicio >= final){
        return;
    }
    aux = vector[final];
    vector[final] = vector[inicio];
    vector[inicio] = aux;
    invertido(vector, inicio + 1, final - 1);

}

char *agregarSeparadorMiles( char *vec){
    int tamaño_original, num_puntos, nuevo_tamaño;
    tamaño_original = strlen(vec);
    num_puntos = (tamaño_original - 1) / 3;
    nuevo_tamaño = tamaño_original + num_puntos;
    

    char *vec_nuevo = malloc(tamaño_original + 1);
    if (!vec_nuevo) return NULL;

    strcpy(vec_nuevo, vec);
    invertido(vec_nuevo, 0, tamaño_original - 1);

    char *vec_miles = malloc(nuevo_tamaño + 1);
    if (!vec_miles) return NULL;

    aux(vec_miles, vec_nuevo, nuevo_tamaño - 1, 0, 0); 

    vec_miles[nuevo_tamaño] = '\0';
    free(vec_nuevo);
    return vec_miles;
}

//EJERCICIO 6
void ondaDigitalAux(char string[], char *vector, int i) {
    if (string[i] == '\0'){
        return;
    } 
    if (i > 0 && string[i] != string[i - 1]) {
        *vector = '|';
        vector++;
    }

    if (tolower(string[i]) == 'l') {
        *vector = '_';
    } else if (tolower(string[i]) == 'h') {
        *vector = '-';
    }

    ondaDigitalAux(string, vector + 1 ,i + 1);
}

char *ondaDigital(char string[]) {
    int tamanio = strlen(string);
    char *vector_ondas = malloc(tamanio*2);
    ondaDigitalAux(string, vector_ondas, 0);
    return vector_ondas; 
}



//EJERCICIO 7
char *reunionMafia(int nivel) {
    static int nivelMax = 0;
    if (!nivelMax) nivelMax = nivel;

    if (nivel == 1) {
        char *base = malloc(6);
        if (base) strcpy(base, "(-.-)");

        int espacios = (5 + (nivelMax - 1) * 6 - 5) / 2;
        while (espacios--) printf(" ");
        printf("%s\n", base);

        return base;
    }

    char *anterior = reunionMafia(nivel - 1);
    char *resultado = malloc(strlen(anterior) + 7);
    if (resultado) sprintf(resultado, "(-.%s.-)", anterior);

    int espacios = (5 + (nivelMax - 1) * 6 - strlen(resultado)) / 2;
    while (espacios--) printf(" ");
    printf("%s\n", resultado);

    free(anterior);
    if (nivel == nivelMax) nivelMax = 0;
    return resultado;
}

//EJERCICIO 8
void subconjuntosQueSumanN(int conjunto[], int tamano, int n, char **output) {
    
    static int actual[100];       
    static int indiceActual = 0;  
    static int posSalida = 0;     
    static int iniciado = 0;      
    static int tamanoOriginal = 0; 

   
    if (!iniciado) {
        iniciado = 1;
        posSalida = 0;
        indiceActual = 0;
        tamanoOriginal = tamano;
    }

    
    if (n == 0) {
        char buffer[256];
        int pos = 0;
        pos += sprintf(buffer + pos, "{");
        for (int i = 0; i < indiceActual; i++) {
            pos += sprintf(buffer + pos, "%d", actual[i]);
            if (i < indiceActual - 1)
                pos += sprintf(buffer + pos, ", ");
        }
        sprintf(buffer + pos, "}");
        output[posSalida] = malloc(strlen(buffer) + 1);
        strcpy(output[posSalida], buffer);
        posSalida++;
       
        if (tamano == tamanoOriginal) { 
            iniciado = 0;
        }
        return;
    }

    
    if (tamano == 0 || n < 0) {
        if (tamano == tamanoOriginal) { 
            iniciado = 0;
        }
        return;
    }

    
    actual[indiceActual] = conjunto[0];
    indiceActual++;
    subconjuntosQueSumanN(conjunto + 1, tamano - 1, n - conjunto[0], output);
    indiceActual--; 

    
    subconjuntosQueSumanN(conjunto + 1, tamano - 1, n, output);

    
    if (tamano == tamanoOriginal) {
        iniciado = 0;
    }
}

//EJERCICIO 9
bool divisiblePor7(int num){
    if (num <= 70){ 
        if(num % 7 == 0 || num == 0){ 
            return true; 
        } else { 
            return false; 
        } 
    } 
    int valor = (num % 10)*2; 
    int nuevo_num = num / 10; 
    int n = nuevo_num - valor; 
    return divisiblePor7(n); 
}

//EJERCICIO 10
#define MAX 100

int bomba(int n, int b, int *vec, int tamaño, int *cont){
    if(n <= b){
        *(vec + tamaño) = n;
        (*cont)++;
        return n; 
    }
    int b1 = n / b;
    int b2 = n - b1;
    bomba(b1, b, vec, tamaño++, cont); 
    bomba(b2, b, vec, tamaño++, cont);
}

int *explosion(int n, int b){
    int tamaño = 0;
    int cont = 0; 
    int *vec = (int *)malloc(MAX * sizeof(int));
    bomba(n, b, vec, tamaño, &cont);
    *(vec + cont) = -1;
    return vec;
}
   