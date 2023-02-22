#ifndef TESTE_H
#define TESTE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef __cplusplus
extern "C" {
#endif

    void clrscr();
    void cleanInputBuffer();
    int obterInteiro(int minValor, int maxValor, char *msg);
    float obterFloat(float minValor, float maxValor, char *msg);
    void lerString(char *string, unsigned int tamanho, char *msg);



#ifdef __cplusplus
}
#endif

#endif /* TESTE_H */

