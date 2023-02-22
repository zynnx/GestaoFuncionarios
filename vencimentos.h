#ifndef VENCIMENTOS_H
#define VENCIMENTOS_H

#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    
#define HORAS_TRABALHO              8
#define MIN_HORAS                   0
#define MAX_HORAS                   230
#define MAX_HORAS_FIMSEMANA         100
#define OBTER_HORAS_TRABALHO        "Horas que trabalhou:"
#define OBTER_HORAS_FIMSEMANA       "Horas que trabalhou no fim de semana:"
#define MIN_SUB_ALIMEN              5
#define MAX_SUB_ALIMEN              7.5
#define BONUSV                      0.05
#define BONUSS                      0.02
    
    
void calculoVencimentos(FUNCIONARIOS funcionario);



#ifdef __cplusplus
}
#endif

#endif /* VENCIMENTOS_H */

