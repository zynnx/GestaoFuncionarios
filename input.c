#include <stdlib.h>
#include <stdio.h>
#include "input.h"
#include "funcoes.h"

/**
 * permite que o ecrã seja limpo 
 */
void clrscr() {
    system("clear");
}

/**
 * função que permite que limpe os dados da memória 
 */
void cleanInputBuffer() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

/**
 * Função que permite obter o número que o usuário insere (em Inteiro)
 * @param minValor
 * @param maxValor
 * @param msg
 * @return valor (valor introduzido pelo usuário)
 */
int obterInteiro(int minValor, int maxValor, char *msg) {
    int valor;
    printf(msg);
    while (scanf("%d", &valor) != 1 || valor < minValor || valor > maxValor) {
        puts(VALOR_INVALIDO);
        cleanInputBuffer();
        printf(msg);
    }
    cleanInputBuffer();
    return valor;
}

/**
 * Função que permite obter o número que o usuário insere (em Float)
 * @param minValor
 * @param maxValor
 * @param msg
 * @return valor
 */
float obterFloat(float minValor, float maxValor, char *msg) {
    float valor;
    printf(msg);
    while (scanf("%f", &valor) != 1 || valor < minValor || valor > maxValor) {
        puts(VALOR_INVALIDO);
        cleanInputBuffer();
        printf(msg);
    }
    cleanInputBuffer();
    return valor;
}

/**
 * Função que permite obter uma string que o usuário insere 
 * @param string
 * @param tamanho
 * @param msg
 */
void lerString(char *string, unsigned int tamanho, char *msg) {
    printf(msg);
    if (fgets(string, tamanho, stdin) != NULL) {
        unsigned int len = strlen(string) - 1;
        if (string[len] == '\n') {
            string[len] = '\0';
        } else {
            cleanInputBuffer();
        }
    }
}


