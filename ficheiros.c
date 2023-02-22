#include <stdio.h>
#include <string.h>

#include "funcoes.h"
#include "ficheiros.h"
#include "input.h"

/** Função que permite guardar os dados dos Funcionários em ficheiro
 * 
 * @param funcionarios
 * @param file
 */
void guardarFuncionarios(FUNCIONARIOS funcionarios, char *file) {
    FILE *ficheiro = fopen(file, "wb");
    if (ficheiro == NULL) {
        printf(ERRO_FICHEIRO);
    } else {
        fwrite(&funcionarios.contador, sizeof (int), 1, ficheiro);
        fwrite(funcionarios.funcionario, sizeof (FUNCIONARIO), funcionarios.contador, ficheiro);
        printf(MSG_FUNC_GRAVAR);
    }
    fclose(ficheiro);
}

/**Função que permite carregar o ficheiro pretendido
 * 
 * @param funcionarios
 * @param file
 */
void carregarFuncionarios(FUNCIONARIOS *funcionarios, char *file) {

    FILE *ficheiro = fopen(file, "rb");
    if (ficheiro == NULL) {
        printf(ERRO_FICHEIRO);
    } else {

        fread(&funcionarios->contador, sizeof (int), 1, ficheiro);
        FUNCIONARIO *temp = (FUNCIONARIO *) malloc((funcionarios->contador) * sizeof (FUNCIONARIO));

        if (temp != NULL) {
            fread(temp, sizeof (FUNCIONARIO), funcionarios->contador, ficheiro);
            funcionarios->funcionario = temp;
            printf(MSG_SUCESSO);
        }

    }
    fclose(ficheiro);
}

/** Função que exibe a Tabela IRS
 * 
 * @param taxas_retencoes_irs
 */
void carregarTabelaIRS(TAXAS_RETENCOES_IRS *taxas_retencoes_irs, char *file) {
    FILE *fp = fopen(file, "r");
    if (fp != NULL) {
        char line[200];
        if (taxas_retencoes_irs->contador == 0) {
            taxas_retencoes_irs->taxa_retencao_irs = (TAXA_RETENCAO_IRS *) malloc(sizeof (TAXA_RETENCAO_IRS));
        }
        while ((fgets(line, 200, fp)) != NULL) {
            TAXA_RETENCAO_IRS *temp = (TAXA_RETENCAO_IRS *) realloc(taxas_retencoes_irs->taxa_retencao_irs, sizeof (TAXA_RETENCAO_IRS) * (taxas_retencoes_irs->contador + 1));

            if (temp != NULL) {
                taxas_retencoes_irs->taxa_retencao_irs = temp;
            }
            sscanf(line, "%f;%f;%f;%f;%f;%f;%f", &taxas_retencoes_irs->taxa_retencao_irs[taxas_retencoes_irs->contador].renumeracao, &taxas_retencoes_irs->taxa_retencao_irs[taxas_retencoes_irs->contador].numero_dependente_0, &taxas_retencoes_irs->taxa_retencao_irs[taxas_retencoes_irs->contador].numero_dependente_1, &taxas_retencoes_irs->taxa_retencao_irs[taxas_retencoes_irs->contador].numero_dependente_2, &taxas_retencoes_irs->taxa_retencao_irs[taxas_retencoes_irs->contador].numero_dependente_3, &taxas_retencoes_irs->taxa_retencao_irs[taxas_retencoes_irs->contador].numero_dependente_4, &taxas_retencoes_irs->taxa_retencao_irs[taxas_retencoes_irs->contador].numero_dependente_5);
            taxas_retencoes_irs->contador++;
        }
        printf("Tabela importada com sucesso!\n");
        fclose(fp);
    } else {
        perror(file);
    }
}

void print_irs(TAXAS_RETENCOES_IRS tabelas) {

    if (tabelas.contador != 0) {
        printf("Linha\t Salario\t 0 Dependentes\t 1 Dependentes\t 2 Dependentes\t 3 Dependentes\t 4 Dependentes\t 5 Dependentes ou mais\n");
        for (int i = 0; i < tabelas.contador; i++) {
            printf("%-*.2d %-*.2f %-*.2f %-*.2f %-*.2f %-*.2f %-*.2f %-*.2f\n", 10, i, 14, tabelas.taxa_retencao_irs[i].renumeracao, 17, tabelas.taxa_retencao_irs[i].numero_dependente_0, 17, tabelas.taxa_retencao_irs[i].numero_dependente_1, 16, tabelas.taxa_retencao_irs[i].numero_dependente_2, 18, tabelas.taxa_retencao_irs[i].numero_dependente_3, 15, tabelas.taxa_retencao_irs[i].numero_dependente_4, 15, tabelas.taxa_retencao_irs[i].numero_dependente_5);
        }
    } else {
        printf("Tabela IRS não importada.\n");
    }
}

void atualizarirs(TAXA_RETENCAO_IRS *taxa_retencao_irs) {
    printf("\n");
    taxa_retencao_irs->renumeracao = obterFloat(MIN_FLOAT, MAX_FLOAT, OBTER_RENUMERACAO);
    taxa_retencao_irs->numero_dependente_0 = obterFloat(MIN_FLOAT, MAX_FLOAT, OBTER_DEPENDENTE_0);
    taxa_retencao_irs->numero_dependente_1 = obterFloat(MIN_FLOAT, MAX_FLOAT, OBTER_DEPENDENTE_1);
    taxa_retencao_irs->numero_dependente_2 = obterFloat(MIN_FLOAT, MAX_FLOAT, OBTER_DEPENDENTE_2);
    taxa_retencao_irs->numero_dependente_3 = obterFloat(MIN_FLOAT, MAX_FLOAT, OBTER_DEPENDENTE_3);
    taxa_retencao_irs->numero_dependente_4 = obterFloat(MIN_FLOAT, MAX_FLOAT, OBTER_DEPENDENTE_4);
    taxa_retencao_irs->numero_dependente_5 = obterFloat(MIN_FLOAT, MAX_FLOAT, OBTER_DEPENDENTE_5);
}

/**Função que permite procurar se a tabela irs existe, antes de editar os seus dados
 * @param funcionarios
 */
void atualizar_irs(TAXAS_RETENCOES_IRS *taxas_retencoes_irs) {

    if (taxas_retencoes_irs->contador >= 1) {
        char numero = obterInteiro(MIN_NUM_FUNCIONARIO, MAX_NUM_FUNCIONARIO, MSG_OBTER_NUM_LINHA);

        if (numero != -1) {
            atualizarirs(&taxas_retencoes_irs->taxa_retencao_irs[numero]);
        } else {
            puts(ERRO_LINHA_NAO_EXISTE);
        }
    } else {
        puts(ERRO_TABELA);
    }

    printf("\nPressione ENTER para retornar ao Menu...");
    getchar();
    clrscr();
}

void carregarTabelaSS(SSOCIAL *taxa, char *file) {

    FILE *ficheiro = fopen(file, "r");

    if (ficheiro != NULL) {
        char line[200];
        while ((fgets(line, sizeof (line), ficheiro)) != NULL) {
            TAXA_CONTRIBUTIVA *temp = (TAXA_CONTRIBUTIVA *) realloc(taxa->segurancaSocial, sizeof (TAXA_CONTRIBUTIVA) * (taxa->contador + 1));
            if (temp != NULL) {
                taxa->segurancaSocial = temp;
            }
            sscanf(line, "%f;%f;%f;%f", &taxa->segurancaSocial[taxa->contador].entidade_empregadora_geral, &taxa->segurancaSocial[taxa->contador].entidade_empregadora_gerencia, &taxa->segurancaSocial[taxa->contador].trabalhador_geral, &taxa->segurancaSocial[taxa->contador].trabalhador_gerencia);
            taxa->contador++;
        }
        printf("Tabela importada com sucesso!\n");
        fclose(ficheiro);
    } else {
        perror(file);
    }
}

void print_seg_social(SSOCIAL taxa) {

    if (taxa.contador != 0) {
        printf("\tENTIDADE EMPREGADORA\t\t\t  TRABALHADOR\t ");
        printf("Funcionarios\t  Administraçao\t\t Funcionarios\t  Administraçao\t\n");
        for (int i = 0; i < taxa.contador; i++) {
            printf("%-*.2f %-*.2f %-*.2f %-*.2f\n", 8, taxa.segurancaSocial[i].entidade_empregadora_geral, 16, taxa.segurancaSocial[i].entidade_empregadora_gerencia, 16, taxa.segurancaSocial[i].trabalhador_geral, 16, taxa.segurancaSocial[i].trabalhador_gerencia);
        }
    } else {
        printf("Tabela IRS não importada.\n");
    }
}

void funcMaisVelho(FUNCIONARIOS *funcionarios) {
    int i, maiorIdade = MAX_ANO, numFunc;

    if ((*funcionarios).contador >= 1) {
        for (i = 0; i < funcionarios->contador; i++) {
            if (maiorIdade > funcionarios->funcionario[i].data_nascimento.ano) {
                maiorIdade = funcionarios->funcionario[i].data_nascimento.ano;
                numFunc = funcionarios->funcionario[i].numeroFuncionario;
            }
        }

        printf("Funcionário Mais Velho da Empresa:\n");
        printf("\nNúmero do Funcionário: %d \n", numFunc);
        printf("Ano em que nasceu: %d", maiorIdade);

    }
    else {
        puts(ERRO_FUNCIONARIO);
    }

}

void funcMaisNovo(FUNCIONARIOS * funcionarios) {
    int i, menorIdade = MIN_ANO, numFunc;

    if ((*funcionarios).contador >= 1) {

        for (i = 0; i < funcionarios->contador; i++) {
            if (menorIdade < funcionarios->funcionario[i].data_nascimento.ano) {
                menorIdade = funcionarios->funcionario[i].data_nascimento.ano;
                numFunc = funcionarios->funcionario[i].numeroFuncionario;

            }
        }

        printf("\nFuncionário Mais Novo da Empresa:\n");
        printf("\nNúmero do Funcionário: %d \n", numFunc);
        printf("Ano em que nasceu: %d", menorIdade);

    } else {
        puts(ERRO_FUNCIONARIO);
    }
}

void guardar_irs(TAXAS_RETENCOES_IRS taxas_retencoes_irs, char *file) {
    FILE *ficheiro = fopen(file, "wb");
    if (ficheiro == NULL) {
        printf(ERRO_FICHEIRO);
    } else {
        fwrite(&taxas_retencoes_irs.contador, sizeof (int), 1, ficheiro);
        fwrite(taxas_retencoes_irs.taxa_retencao_irs, sizeof (TAXA_RETENCAO_IRS), taxas_retencoes_irs.contador, ficheiro);
        printf(MSG_FUNC_GRAVAR_IRS);
    }

    fclose(ficheiro);
}