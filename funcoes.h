#ifndef FUNCOES_H
#define FUNCOES_H

#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



#define MAX_TAMANHO                 100     //número de caractéres máximos
#define VALOR_INVALIDO              "O valor inserido é inválido."
#define ERRO_FUNCIONARIO_NAO_EXISTE "O Funcionário não existe na lista."
#define ERRO_FUNCIONARIO            "Não existem Funcionários."
#define ERRO_LISTA_VAZIA            "A lista de Funcionário está vazia."
#define ERRO_LISTA_CHEIA            "A lista de Funcionário está cheia."
#define ERRO_FUNCIONARIO_EXISTE     "O número de Funcionário já se encontra atribuído."
#define ERRO_FICHEIRO               "Erro no ficheiro! Volte a tentar.\n"                      

#define MIN_NUM_FUNCIONARIO         1
#define MAX_NUM_FUNCIONARIO         9999
#define MSG_OBTER_NUM_FUNCIONARIO   "Número do Funcionário: "
    

#define MAX_NOME_FUNCIONARIO        30
#define MSG_OBTER_NOME              "Nome: "
    
#define MIN_DIA                     1
#define MAX_DIA                     31
#define MAX_DIA_FEV                 29
#define OBTER_DIA                   "Dia: "
#define OBTER_MES                   "Mês: "
#define OBTER_ANO                   "Ano: "

#define MIN_MES                     1
#define MAX_MES                     12

#define MIN_ANO                     1950
#define INICIO_EMPRESA              2010
#define MAX_ANO                     2021

#define MIN_ESTADOCIVIL             0
#define MAX_ESTADOCIVIL             3
#define OBTER_ESTADOCIVIL           "Insira o Estado Civil : "

#define MIN_CARGO                   0
#define MAX_CARGO                   2
#define OBTER_CARGO                 "Insira o Cargo: "

#define MIN_ORDENADO_H              4
#define MAX_ORDENADO_H              100
#define OBTER_ORDENADO_H            "Insira o quanto recebe a Hora: "

#define SUB_ALIMEN_ADMIN            "Recebe de Subsídio de Alimentaçao por dia: 7.5€"
#define SUB_ALIMEN_CHEFE            "Recebe de Subsídio de Alimentaçao por dia: 7.5€"
#define SUB_ALIMEN_FUNCIONARIO      "Recebe de Subsídio de Alimentaçao por dia: 5€"


#define MIN_FILHOS                  0
#define MAX_FILHOS                  10
#define OBTER_NFILHOS               "Insira o número de dependentes: "   

#define MIN_NUM_TELE                910000000
#define MAX_NUM_TELE                969999999
#define OBTER_NUM_TELE              "Insira o número de telemovel: " 

#define MSG_FILE                    "log.txt"
#define MSG_INICIAR                 "Iniciou o Programa"
#define MSG_FUNC_MENU               "Menu de Funcionário"
#define MSG_FUNC_CRIAR              "Criou Funcionário"
#define MSG_FUNC_EDITAR             "Editar Funcionário"
#define MSG_FUNC_REMOVER            "Remover Funcionário"

#define MSG_SALARIOS                "Processar Salário"
#define MSG_TABELA_SS               "Menu da SS"
#define MSG_TABBELA_IRS             "Menu do IRS"
#define MSG_SAIR                    "Saiu do Programa"

#define MSG_ERRO_INVALIDO           "Introduziu um número invalido"   
#define MSG_OPTION                  "Escolha uma opção: "

    typedef enum {
        ADMINISTRADOR, CHEFE, FUNCIONARIOSS
    } CARGO;

    typedef enum {
        SOLTEIRO, CASADO, DIVORCIADO, VIUVO
    } ESTADOCIVIL;

    typedef enum {
        JANEIRO=1, FEVEREIRO=2, MARCO=3, ABRIL=4, MAIO=5, JUNHO=6, JULHO=7, AGOSTO=8, SETEMBRO=9, OUTUBRO=10, NOVEMBRO=11, DEZEMBRO=12
    } MESES_ANO;
    
    typedef enum {
        ATIVO, NAOATIVO
    } ACTIVO;
    
    typedef struct {
        float dias, dias_fim_semana;
        MESES_ANO nome_mes;
    } VENCIMENTO;
    
    typedef struct {
        int ano, mes, dia;
    } DATA;

    typedef struct {
        int numeroFuncionario, receberHora, dependentes, numeroTele;
        char nome[40];
        ESTADOCIVIL estadoCivil;
        DATA data_nascimento, data_ent_empresa, data_ext_empresa;
        CARGO cargo;
        ACTIVO ativo;
    } FUNCIONARIO;

    typedef struct {
        int contador, tamanho;
        FUNCIONARIO *funcionario;
    } FUNCIONARIOS;
    
    
    
    
 
    void logMsg(char *msg, char *filename);
    void inserirFuncionario(FUNCIONARIOS *funcionario);
    void procurarFuncionarios(FUNCIONARIOS funcionario);
    void atualizarFuncionarios(FUNCIONARIOS *funcionario);
    void removerFuncionarios(FUNCIONARIOS *funcionarios);
    void listarFuncionarios(FUNCIONARIOS funcionario);
    void MENU_PRINCIPAL();
    int obterInteiro(int minValor, int maxValor, char *msg);
    int procurarFuncionariosVencimentos(FUNCIONARIOS funcionarios);
    void imprimirFuncionarioVencimentos(FUNCIONARIO funcionario);
    int estadoCivil();
    int cargoEmpresa();
    void imprimirCargo(int cargoID);
    void imprimirECivil(int estadoCivil);
    void imprimirMeses(int mes);
    void funcMaisVelho(FUNCIONARIOS *funcionarios);
    void funcMaisNovo(FUNCIONARIOS * funcionarios);

#ifdef __cplusplus
}
#endif

#endif /* FUNCOES_H */

