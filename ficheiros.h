#ifndef FICHEIROS_H
#define FICHEIROS_H

#include <stdio.h>
#include <string.h>

// DEFINEs relativos às Tabelas de IRS
#ifdef __cplusplus
extern "C" {
#endif
#define MSG_SUCESSO                 "O Ficheiro foi lido com sucesso."
#define MSG_FUNC_LISTAR             "Listou os funcionários"
#define MSG_FUNC_GRAVAR             "Gravou os funcionários em ficheiros"
#define MSG_FUNC_IMPORTAR           "Importou funcionários de ficheiros"
#define MSG_GUARDAR                 "Guardar Funcionários em que ficheiro: "
#define MSG_IMPORTAR                "Importar Funcionários de ficheiro: "
#define MSG_SAIR_MENU               "Voltou ao menu Anterior"
#define MSG_IMPORTAR_TAB_IRS        "Importar tabelas de IRS de ficheiro."    
#define MSG_IMPORTAR_TAB_SOL        "Importar Tabela IRS de solteiro: "
#define MSG_IMPORTAR_TAB_CAS1       "Importar Tabela IRS de casado 1 titular: "
#define MSG_IMPORTAR_TAB_CAS2       "Importar Tabela IRS de casado 2 titular: "
#define MSG_EDITAR_TAB_IRS          "Editar tabelas de IRS."
#define MSG_EDITAR_TAB_SOL          "Editar Tabela IRS de solteiro: "
#define MSG_EDITAR_TAB_CAS1         "Editar Tabela IRS de casado 1 titular: "
#define MSG_EDITAR_TAB_CAS2         "Editar Tabela IRS de casado 2 titular: "
#define MSG_REMOVER_TAB_IRS         "Remover tabelas de IRS."
#define MSG_REMOVER_TAB_SOL         "Remover Tabela IRS de solteiro: "
#define MSG_REMOVER_TAB_CAS1        "Remover Tabela IRS de casado 1 titular: "
#define MSG_REMOVER_TAB_CAS2        "Remover Tabela IRS de casado 2 titular: "
#define MSG_LISTAR_TAB_IRS          "Listar tabelas de IRS."
#define MSG_LISTAR_TAB_SOL          "Listar Tabela IRS de solteiro: "
#define MSG_LISTAR_TAB_CAS1         "Listar Tabela IRS de casado 1 titular: "
#define MSG_LISTAR_TAB_CAS2         "Listar Tabela IRS de casado 2 titular: "
#define MSG_IMPORTAR_TAB_SS         "Importar tabelas de Seguranca Social de ficheiro."
#define MSG_EDITAR_TAB_SS           "Editar tabelas de Seguranca Social de ficheiro."
#define MSG_REMOVER_TAB_SS          "Remover tabelas de Seguranca Social de ficheiro."
#define MSG_LISTAR_TAB_SS           "Listar tabelas de Seguranca Social de ficheiro."
#define MSG_OBTER_NUM_LINHA         "Número de Linha: "
#define ERRO_LINHA_NAO_EXISTE       "A Linha não existe na Tabela de Retenção de IRS."
#define ERRO_TABELA                 "Não existem Tabelas de Retenção de IRS."
#define MAX_FLOAT                   900000
#define MIN_FLOAT                   0
#define OBTER_RENUMERACAO           "Renumeração:"
#define OBTER_DEPENDENTE_0          "0 dependentes:"
#define OBTER_DEPENDENTE_1          "1 dependentes:"
#define OBTER_DEPENDENTE_2          "2 dependentes:"
#define OBTER_DEPENDENTE_3          "3 dependentes:"
#define OBTER_DEPENDENTE_4          "4 dependentes:"
#define OBTER_DEPENDENTE_5          "5 ou mais dependentes:"   
#define MSG_FUNC_GRAVAR_IRS         "Gravou com sucesso"    
    
    typedef struct {
        int mes;
        int dias;
        int dias_fins_de_semana;
        float meios_dias;
        int faltas;
        float salario_liquido;
        float salario_iliquido;
    } PROCESSAMENTO_SALARIAL;
    
    typedef enum {
        CASADO_1_TITULAR=1 ,CASADO_2_TITULAR ,NAO_CASADO=2 
    } TIPO_RETENCAO_IRS;
    
    typedef struct {
        float renumeracao;
        TIPO_RETENCAO_IRS tipo;
        float numero_dependente_0;
        float numero_dependente_1;
        float numero_dependente_2;
        float numero_dependente_3;
        float numero_dependente_4;
        float numero_dependente_5;
    } TAXA_RETENCAO_IRS;
    
    typedef struct {
        int contador;
        TAXA_RETENCAO_IRS *taxa_retencao_irs;
    } TAXAS_RETENCOES_IRS;
    
   typedef struct {
        float entidade_empregadora_geral, entidade_empregadora_gerencia;
        float trabalhador_geral, trabalhador_gerencia;
    } TAXA_CONTRIBUTIVA;

    typedef struct {
        int contador;
        TAXA_CONTRIBUTIVA *segurancaSocial;
    } SSOCIAL;

    void guardarFuncionarios(FUNCIONARIOS funcionarios, char *file);
    void carregarFuncionarios(FUNCIONARIOS *funcionarios, char *file);
    void print_irs(TAXAS_RETENCOES_IRS tabelas);
    void carregarTabelaIRS(TAXAS_RETENCOES_IRS *taxas_retencoes_irs, char *file);
    void print_seg_social(SSOCIAL taxa);
    void carregarTabelaSS(SSOCIAL *taxaContributiva, char *file);
    void atualizar_irs(TAXAS_RETENCOES_IRS *taxas_retencoes_irs);
    void guardar_irs(TAXAS_RETENCOES_IRS taxas_retencoes_irs, char *file);


#ifdef __cplusplus
}
#endif

#endif /* FICHEIROS_H */

