#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
#include "input.h"
#include "ficheiros.h"
#include "vencimentos.h"

/**função que permite o cálculo do vencimento do funcionário
 * 
 * @param funcionario
 */
void calculoVencimentos(FUNCIONARIOS funcionario) {
    float venciBruto, venciLiquido, horasTrabalho, diasTrabalho, horasFimSemana, subsiAlimentacao, encargoFonte, encargo_p, totalValorLiquido = 0, TotalValorEmpresa, encargoTotal;
    char ext;
    int i = 0;
    int idFuncionario;
    if (funcionario.contador >= 1) {

        idFuncionario = procurarFuncionariosVencimentos(funcionario);

        do {
            for (i = 1; i <= MAX_MES; i++) {
                imprimirMeses(i);

                horasTrabalho = obterFloat(MIN_HORAS, MAX_HORAS, OBTER_HORAS_TRABALHO);

                do {
                    printf("Trabalhou em algum dia de fim de semana [S/N]?");
                    scanf("%c", &ext);
                } while (ext != 'n' && ext != 'N' && ext != 'S' && ext != 's');


                if (ext == 's' && ext != 'S') {
                    horasFimSemana = obterFloat(MIN_HORAS, MAX_HORAS_FIMSEMANA, OBTER_HORAS_FIMSEMANA);
                }

                horasTrabalho += horasFimSemana;
                diasTrabalho = horasTrabalho / 8;

                printf("Trabalhou %g dias este mês\n", diasTrabalho);


                switch (funcionario.funcionario[idFuncionario].cargo) {
                    case ADMINISTRADOR:

                        venciLiquido = (diasTrabalho * funcionario.funcionario->receberHora);
                        subsiAlimentacao = MAX_SUB_ALIMEN * diasTrabalho;

                        if (diasTrabalho >= 17 && diasTrabalho < 20) {
                            venciLiquido += venciLiquido * BONUSS;
                        } else {
                            venciLiquido += venciLiquido * BONUSV;
                        }
                        venciBruto = venciLiquido + subsiAlimentacao;
                        if (venciLiquido < 1000) {
                            venciLiquido -= (venciLiquido * 0.1);
                        } else if (venciLiquido >= 1000 || venciLiquido < 2500) {
                            venciLiquido -= (venciLiquido * 0.2);
                        } else {
                            venciLiquido -= (venciLiquido * 0.3);
                        }

                        encargoFonte = venciLiquido * 0.09;
                        encargo_p = venciBruto * 0.21;

                        break;

                    case CHEFE:

                        venciLiquido = (diasTrabalho * funcionario.funcionario->receberHora);

                        subsiAlimentacao = MAX_SUB_ALIMEN * diasTrabalho;

                        if (diasTrabalho >= 17 && diasTrabalho < 20) {
                            venciLiquido += venciLiquido * BONUSS;
                        } else {
                            venciLiquido += venciLiquido * BONUSV;
                        }
                        venciBruto = venciLiquido + subsiAlimentacao;
                        if (venciLiquido < 1000) {
                            venciLiquido -= (venciLiquido * 0.1);
                        } else if (venciLiquido >= 1000 || venciLiquido < 2500) {
                            venciLiquido -= (venciLiquido * 0.2);
                        } else {
                            venciLiquido -= (venciLiquido * 0.3);
                        }
                        encargoFonte = venciLiquido * 0.11;
                        encargo_p = venciBruto * 0.2375;
                        break;

                    case FUNCIONARIOSS:

                        venciLiquido = (diasTrabalho * funcionario.funcionario->receberHora);

                        subsiAlimentacao = MIN_SUB_ALIMEN * diasTrabalho;

                        if (diasTrabalho >= 17 && diasTrabalho < 20) {
                            venciLiquido += venciLiquido * BONUSS;
                        } else {
                            venciLiquido += venciLiquido * BONUSV;
                        }
                        venciBruto = venciLiquido + subsiAlimentacao;
                        if (venciLiquido < 1000) {
                            venciLiquido -= (venciLiquido * 0.1);
                        } else if (venciLiquido >= 1000 || venciLiquido < 2500) {
                            venciLiquido -= (venciLiquido * 0.2);
                        } else {
                            venciLiquido -= (venciLiquido * 0.3);
                        }
                        encargoFonte = venciLiquido * 0.11;
                        encargo_p = venciBruto * 0.2375;

                        break;
                    default:
                        printf("Funcionário não encontrado\n");
                        MENU_PRINCIPAL();
                        break;
                }
                
                totalValorLiquido = venciBruto;

                printf("O valor líquido a receber: %.2f€\n", venciLiquido + subsiAlimentacao);
                printf("O valor Ilíquido a receber: %.2f€\n", venciBruto);
                printf("O valor subsídio de alimentação: %.2f€\n", subsiAlimentacao);
                printf("O valor retido na fonte IRS: %.2f€\n", encargoFonte);
                printf("O valor entrege a Segurança Social: %.2f€\n", encargo_p);
                encargo_p += encargoFonte;
                TotalValorEmpresa = encargo_p + venciBruto;
                printf("O valor entrege à Segurança Social(ambos): %.2f€\n", encargo_p);
                printf("O valor e total para a empresa: %.2f€\n", TotalValorEmpresa);

                do {
                    printf("Deseja continuar [s/n]:\n");
                    scanf(" %c", &ext);
                } while (ext != 'n' && ext != 'N' && ext != 'S' && ext != 's');

                encargoTotal += TotalValorEmpresa;
                totalValorLiquido += venciBruto;

                if (ext == 'n' || ext == 'N') {
                    break;
                }
            }
        } while (ext == 'S' || ext == 's');

        printf("O Valor Líquido Anual a receber: %.2f€\n", totalValorLiquido);
        printf("O Encargo Total Anual com Salários: %.2f€\n", encargoTotal);
    } else {
        puts(ERRO_FUNCIONARIO);
    }
    getchar();
    clrscr();
}

