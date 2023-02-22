#ifndef MENU_H
#define MENU_H

#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
#include "input.h"
#include "vencimentos.h"
#include "ficheiros.h"

    /** Função que possui o Menu do Programa
     * 
     */
    void MENU_PRINCIPAL() {
        int escolha;
        char resposta, ficheiro[MAX_TAMANHO];
        FUNCIONARIOS funcionarios = {.contador = 0, .tamanho = 0};
        TAXAS_RETENCOES_IRS taxas[3];
        taxas[0].contador = 0;
        taxas[1].contador = 0;
        taxas[2].contador = 0;
        SSOCIAL ssocial = {.contador = 0};

        do {
            puts("\n----------------->Menu<-----------------"
                    "\n1 - Gerir Funcionarios"
                    "\n2 - Consultar Salarios"
                    "\n3 - Tabelas IRS"
                    "\n4 - Tabelas Seguranca Social"
                    "\n0 - Sair do programa");

            escolha = obterInteiro(0, 4, MSG_OPTION);

            switch (escolha) {
                case 1:
                    clrscr();

                    do {
                        puts("\n----------------->Menu Funcionarios<-----------------"
                                "\n1 - Criar Novo Funcionário"
                                "\n2 - Editar Funcionário"
                                "\n3 - Remover Funcionário"
                                "\n4 - Listar Funcionários"
                                "\n5 - Importar Base de Dados"
                                "\n6 - Gravar Funcionários em Ficheiro"
                                "\n7 - Mais Listagens"
                                "\n9 - Voltar ao Menu Anterior");


                        escolha = obterInteiro(1, 9, MSG_OPTION);
                        logMsg(MSG_FUNC_MENU, MSG_FILE);
                        switch (escolha) {
                            case 1:
                                do {
                                    clrscr();
                                    printf("Criar:\n");
                                    inserirFuncionario(&funcionarios);
                                    printf("Deseja adicionar mais funcionários (S/N)? ");
                                    scanf(" %c", &resposta);
                                    while (resposta != 'S' && resposta != 's' && resposta != 'N' && resposta != 'n') {
                                        scanf(" %c", &resposta);
                                    }
                                } while (resposta == 'S' || resposta == 's');
                                logMsg(MSG_FUNC_CRIAR, MSG_FILE);
                                clrscr();
                                break;

                            case 2:
                                clrscr();
                                printf("Editar:\n");
                                atualizarFuncionarios(&funcionarios);
                                logMsg(MSG_FUNC_EDITAR, MSG_FILE);
                                break;

                            case 3:
                                clrscr();
                                printf("Remover:\n");
                                removerFuncionarios(&funcionarios);
                                logMsg(MSG_FUNC_REMOVER, MSG_FILE);
                                break;

                            case 4:
                                printf("Consultar:\n");
                                listarFuncionarios(funcionarios);
                                logMsg(MSG_FUNC_LISTAR, MSG_FILE);
                                break;

                            case 5:
                                lerString(ficheiro, MAX_TAMANHO, MSG_IMPORTAR);
                                carregarFuncionarios(&funcionarios, ficheiro);
                                logMsg(MSG_FUNC_IMPORTAR, MSG_FILE);
                                break;

                            case 6:
                                lerString(ficheiro, MAX_TAMANHO, MSG_GUARDAR);
                                guardarFuncionarios(funcionarios, ficheiro);
                                logMsg(MSG_FUNC_GRAVAR, MSG_FILE);
                                break;
                            
                            case 7:
                                clrscr();
                                funcMaisVelho(&funcionarios);
                                printf("\n__________________________\n");
                                funcMaisNovo(&funcionarios);
                                printf("\n__________________________\n");
                                printf("\n\n\n\nPressione ENTER para retornar ao Menu...");
                                getchar();
                                clrscr();
                                break;
                            case 9:
                                logMsg(MSG_SAIR_MENU, MSG_FILE);
                                break;

                            default:
                                printf("\nO número que introduziu não é válido\n");
                                logMsg(MSG_ERRO_INVALIDO, MSG_FILE);
                                break;
                        }
                        clrscr();
                    } while (escolha != 9);
                    break;

                case 2:
                    clrscr();
                    printf("Consultar Salários:\n");
                    calculoVencimentos(funcionarios);
                    logMsg(MSG_SALARIOS, MSG_FILE);
                    break;

                case 3:
                    clrscr();
                    do {
                        puts("\n----------------->Menu Tabelas IRS<-----------------"
                                "\n1 - Importar Tabelas"
                                "\n2 - Editar Tabelas"
                                "\n3 - Remover Tabelas"
                                "\n4 - Listar Tabelas"
                                "\n5 - guardar IRS"
                                "\n9 - Voltar Menu Anterior");

                        escolha = obterInteiro(1, 9, MSG_OPTION);

                        switch (escolha) {
                            case 1:
                                clrscr();
                                do {
                                    puts("\n----------------->Importar Tabelas IRS<-----------------"
                                            "\n1 - Tabela Solteiro"
                                            "\n2 - Tabela Casado 1 Titular"
                                            "\n3 - Tabela Casado 2 Titular"
                                            "\n9 - Voltar Menu Anterior");
                                    
                                    escolha = obterInteiro(1, 9, MSG_OPTION);
                                    
                                    switch (escolha) {
                                        case 1:
                                            lerString(ficheiro, MAX_TAMANHO, MSG_IMPORTAR_TAB_SOL);
                                            carregarTabelaIRS(&taxas[0], ficheiro);
                                            logMsg(MSG_IMPORTAR_TAB_SOL, MSG_FILE);
                                            break;
                                        case 2:
                                            lerString(ficheiro, MAX_TAMANHO, MSG_IMPORTAR_TAB_SOL);
                                            carregarTabelaIRS(&taxas[1], ficheiro);
                                            logMsg(MSG_IMPORTAR_TAB_SOL, MSG_FILE);
                                            break;
                                        case 3:
                                            lerString(ficheiro, MAX_TAMANHO, MSG_IMPORTAR_TAB_SOL);
                                            carregarTabelaIRS(&taxas[2], ficheiro);
                                            logMsg(MSG_IMPORTAR_TAB_SOL, MSG_FILE);
                                            break;
                                        case 9:
                                            clrscr();
                                            logMsg(MSG_SAIR_MENU, MSG_FILE);
                                            break;
                                        default:
                                            printf("\nO número que introduziu não é válido\n");
                                            logMsg(MSG_ERRO_INVALIDO, MSG_FILE);
                                            break;
                                    }
                                } while (escolha != 9);
                                logMsg(MSG_IMPORTAR_TAB_IRS, MSG_FILE);
                                break;
                            case 2:
                                clrscr();
                                do {
                                    puts("\n----------------->Editar Tabelas IRS<-----------------"
                                            "\n1 - Editar Tabela Solteiro"
                                            "\n2 - Editar Tabela Casado 1 Titular"
                                            "\n3 - Editar Tabela Casado 2 Titular"
                                            "\n9 - Voltar Menu Anterior");
                                    
                                    escolha = obterInteiro(1, 9, MSG_OPTION);
                                    switch (escolha) {
                                        case 1:
                                            atualizar_irs(&taxas[0]);
                                            logMsg(MSG_EDITAR_TAB_SOL, MSG_FILE);
                                            break;
                                        case 2:
                                            atualizar_irs(&taxas[1]);
                                            logMsg(MSG_EDITAR_TAB_CAS1, MSG_FILE);
                                            break;
                                        case 3:
                                            atualizar_irs(&taxas[2]);
                                            logMsg(MSG_EDITAR_TAB_CAS2, MSG_FILE);
                                            break;
                                        case 9:
                                            clrscr();
                                            logMsg(MSG_SAIR_MENU, MSG_FILE);
                                            break;
                                        default:
                                            printf("\nO número que introduziu não é válido\n");
                                            logMsg(MSG_ERRO_INVALIDO, MSG_FILE);
                                            break;
                                    }
                                } while (escolha != 9);
                                logMsg(MSG_EDITAR_TAB_IRS, MSG_FILE);
                                break;
                            case 3:
                                clrscr();
                                do {
                                    puts("\n----------------->Remover Tabelas IRS<-----------------"
                                            "\n1 - Remover Tabela Solteiro"
                                            "\n2 - Remover Casado 1 Titular"
                                            "\n3 - Remover Casado 2 Titular"
                                            "\n9 - Voltar Menu Anterior");
                                    escolha = obterInteiro(1, 9, MSG_OPTION);
                                    switch (escolha) {
                                        case 1:
                                            //
                                            logMsg(MSG_REMOVER_TAB_SOL, MSG_FILE);
                                            break;
                                        case 2:
                                            //
                                            logMsg(MSG_REMOVER_TAB_CAS1, MSG_FILE);
                                            break;
                                        case 3:
                                            //
                                            logMsg(MSG_REMOVER_TAB_CAS2, MSG_FILE);
                                            break;
                                        case 9:
                                            clrscr();
                                            logMsg(MSG_SAIR_MENU, MSG_FILE);
                                            break;
                                        default:
                                            printf("\nO número que introduziu não é válido\n");
                                            logMsg(MSG_ERRO_INVALIDO, MSG_FILE);
                                            break;
                                    }
                                } while (escolha != 9);
                                logMsg(MSG_REMOVER_TAB_IRS, MSG_FILE);
                                break;
                            case 4:
                                clrscr();
                                do {
                                    puts("\n----------------->Listar Tabelas IRS<-----------------"
                                            "\n1 - Listar Tabela Solteiro"
                                            "\n2 - Listar Tabela Casado 1 Titular"
                                            "\n3 - Listar Tabela Casado 2 Titular"
                                            "\n9 - Voltar Menu Anterior");
                                    escolha = obterInteiro(1, 9, MSG_OPTION);
                                    switch (escolha) {
                                        case 1:
                                            print_irs(taxas[0]);
                                            logMsg(MSG_LISTAR_TAB_SOL, MSG_FILE);
                                            break;
                                        case 2:
                                            print_irs(taxas[1]);
                                            logMsg(MSG_LISTAR_TAB_CAS1, MSG_FILE);
                                            break;
                                        case 3:
                                            print_irs(taxas[2]);
                                            logMsg(MSG_LISTAR_TAB_CAS2, MSG_FILE);
                                            break;
                                        case 9:
                                            clrscr();
                                            logMsg(MSG_SAIR_MENU, MSG_FILE);
                                            break;
                                        default:
                                            printf("\nO número que introduziu não é válido\n");
                                            logMsg(MSG_ERRO_INVALIDO, MSG_FILE);
                                            break;
                                    }
                                } while (escolha != 9);
                                logMsg(MSG_LISTAR_TAB_IRS, MSG_FILE);
                                break;
                            case 5: 
                                lerString(ficheiro, MAX_TAMANHO, MSG_IMPORTAR_TAB_SOL);         
                                guardar_irs(taxas[3], ficheiro);
                            case 9:
                                clrscr();
                                logMsg(MSG_SAIR_MENU, MSG_FILE);
                                break;
                            default:
                                printf("\nO número que introduziu não é válido\n");
                                logMsg(MSG_ERRO_INVALIDO, MSG_FILE);
                                break;
                        }
                    } while (escolha != 9);
                    break;
                case 4:
                    clrscr();
                    do {
                        puts("\n----------------->Menu Tabelas Seguranca Social<-----------------"
                                "\n1 - Importar Tabela"
                                "\n2 - Editar Tabela"
                                "\n3 - Remover Tabela"
                                "\n4 - Listar Tabela"
                                "\n9 - Voltar Menu Anterior");

                        escolha = obterInteiro(1, 9, MSG_OPTION);

                        switch (escolha) {
                            case 1:
                                clrscr();
                                lerString(ficheiro, MAX_TAMANHO, MSG_IMPORTAR_TAB_SOL);
                                carregarTabelaSS(&ssocial, ficheiro);
                                logMsg(MSG_IMPORTAR_TAB_SS, MSG_FILE);
                                break;
                            case 2:
                                clrscr();

                                logMsg(MSG_EDITAR_TAB_SS, MSG_FILE);
                                break;
                            case 3:
                                clrscr();
                                
                                logMsg(MSG_REMOVER_TAB_SS, MSG_FILE);
                                break;
                            case 4:
                                clrscr();
                                print_seg_social(ssocial);
                                logMsg(MSG_LISTAR_TAB_SS, MSG_FILE);
                                break;
                            case 9:
                                clrscr();
                                logMsg(MSG_SAIR_MENU, MSG_FILE);
                                break;
                            default:
                                printf("\nO número que introduzio não é valido\n");
                                logMsg(MSG_ERRO_INVALIDO, MSG_FILE);
                                break;
                        }
                    } while (escolha != 9);
                    logMsg(MSG_SAIR_MENU, MSG_FILE);
                    break;
                case 0:
                    logMsg(MSG_SAIR, MSG_FILE);
                    break;
                default:
                    printf("\nO número que introduzio não é valido\n");
                    logMsg(MSG_ERRO_INVALIDO, MSG_FILE);
                    break;
            }
        } while (escolha != 0);
    }





#ifdef __cplusplus
}
#endif

#endif /* MENU_H */

