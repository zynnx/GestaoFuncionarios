#include "funcoes.h"
#include "input.h"
#include "ficheiros.h"

/**
 * Imprime todos os dados completos do funcionário
 * @param funcionario
 */
void imprimirFuncionario(FUNCIONARIO funcionario) {
    printf("\nNúmero do Funcionário: %d", funcionario.numeroFuncionario);

    printf("\nNome do Funcionário: %s", funcionario.nome);

    printf("\nData de Nascimento: "
            "\t%d-%d-%d", funcionario.data_nascimento.dia, funcionario.data_nascimento.mes, funcionario.data_nascimento.ano);

    imprimirECivil(funcionario.estadoCivil);

    imprimirCargo(funcionario.cargo);

    printf("Data de entrada na empresa: %d-%d-%d", funcionario.data_ent_empresa.dia, funcionario.data_ent_empresa.mes, funcionario.data_ent_empresa.ano);

    if (funcionario.ativo == 1) {
        printf("\nFuncinario ja não pretence a empresa.");
        printf("\nData de saida da empresa: %d-%d-%d\n", funcionario.data_ext_empresa.dia, funcionario.data_ext_empresa.mes, funcionario.data_ext_empresa.ano);
    }
}

/** Função que procura funcionários pelo número de funcionário na empresa
 * 
 * @param funcionarios
 * @param numero
 * @return i (retorna o número do funcionário)
 */
int procurarFuncionario(FUNCIONARIOS funcionarios, int numero) {
    int i;
    for (i = 0; i < funcionarios.contador; i++) {
        if (funcionarios.funcionario[i].numeroFuncionario == numero) {
            return i;
        }
    }
    return -1;
}

/**Procura os funcionarios e imprime os dados do funcionario
 * 
 * @param funcionarios
 */
void procurarFuncionarios(FUNCIONARIOS funcionarios) {
    int numero = procurarFuncionario(funcionarios, obterInteiro(MIN_NUM_FUNCIONARIO, MAX_NUM_FUNCIONARIO, MSG_OBTER_NUM_FUNCIONARIO));

    if (numero != -1) {
        imprimirFuncionario(funcionarios.funcionario[numero]);
    } else {
        puts(ERRO_FUNCIONARIO_NAO_EXISTE);
    }
}

/**Função que permite aumentar o tamanho da base de dados para ser preenchida por dados de funcionários
 * 
 * @param funcionarios
 */
void memoriaTemporaria(FUNCIONARIOS *funcionarios) {
    FUNCIONARIO *temporario = (FUNCIONARIO *) realloc((funcionarios->funcionario), sizeof (FUNCIONARIO) * (funcionarios->contador + 2));
    if (temporario != NULL) {
        funcionarios->tamanho += 2;
        funcionarios->funcionario = temporario;
    }
}

/**Função que permite inserir os dados do funcionario
 * 
 * @param funcionarios
 * @return 
 */
void inserirFuncionario(FUNCIONARIOS *funcionarios) { //dados funcionario

    if (funcionarios->contador == funcionarios->tamanho) {
        memoriaTemporaria(funcionarios);
    }
    funcionarios->funcionario[funcionarios->contador].ativo = 0;
    puts("Inserir Dados do Funcionário \n");
    
    //número do Funcionário na empresa
    int numero_funcionario = obterInteiro(MIN_NUM_FUNCIONARIO, MAX_NUM_FUNCIONARIO, MSG_OBTER_NUM_FUNCIONARIO);
    
    // verificar se funcionario existe
    if (procurarFuncionario(*funcionarios, numero_funcionario) == -1) {
        // recolher dados pessoais
        
        //nome
        funcionarios->funcionario[funcionarios->contador].numeroFuncionario = numero_funcionario;
        lerString(funcionarios->funcionario[funcionarios->contador].nome, MAX_NOME_FUNCIONARIO, MSG_OBTER_NOME);

        //estado civil
        funcionarios->funcionario[funcionarios->contador].estadoCivil = estadoCivil();

            
        printf("\nData de Nascimento: \n");
        funcionarios->funcionario[funcionarios->contador].data_nascimento.ano = obterInteiro(MIN_ANO, MAX_ANO, OBTER_ANO);
        funcionarios->funcionario[funcionarios->contador].data_nascimento.mes = obterInteiro(MIN_MES, MAX_MES, OBTER_MES);
        if (funcionarios->funcionario[funcionarios->contador].data_nascimento.mes == FEVEREIRO) {
            funcionarios->funcionario[funcionarios->contador].data_nascimento.dia = obterInteiro(MIN_DIA, MAX_DIA_FEV, OBTER_DIA);
        } else {
            funcionarios->funcionario[funcionarios->contador].data_nascimento.dia = obterInteiro(MIN_DIA, MAX_DIA, OBTER_DIA);
        }

        //número do telemóvel    
        printf("\n");
        funcionarios->funcionario[funcionarios->contador].numeroTele = obterInteiro(MIN_NUM_TELE, MAX_NUM_TELE, OBTER_NUM_TELE);

        //número de filhos
        printf("\n");
        funcionarios->funcionario[funcionarios->contador].dependentes = obterInteiro(MIN_FILHOS, MAX_FILHOS, OBTER_NFILHOS);

        // recolher dados relativos a empresa - TODO: Alterar variaveis
        
        //cargo do funcionário na empresa
        funcionarios->funcionario[funcionarios->contador].cargo = cargoEmpresa();

        //quanto recebe por hora
        printf("\n");
        funcionarios->funcionario[funcionarios->contador].receberHora = obterInteiro(MIN_ORDENADO_H, MAX_ORDENADO_H, OBTER_ORDENADO_H);
        
        if (funcionarios->funcionario[funcionarios->contador].cargo == ADMINISTRADOR) {
            puts(SUB_ALIMEN_ADMIN);
        } else if (funcionarios->funcionario[funcionarios->contador].cargo == CHEFE) {
            puts(SUB_ALIMEN_CHEFE);
        } else {
            puts(SUB_ALIMEN_FUNCIONARIO);
        }

        //data de entrada    
        printf("\nData de Entrada na Empresa: \n");
        
            funcionarios->funcionario[funcionarios->contador].data_ent_empresa.ano = obterInteiro(INICIO_EMPRESA, MAX_ANO, OBTER_ANO);
            
        
        funcionarios->funcionario[funcionarios->contador].data_ent_empresa.mes = obterInteiro(MIN_MES, MAX_MES, OBTER_MES);
        if (funcionarios->funcionario[funcionarios->contador].data_ent_empresa.mes == FEVEREIRO) {
            funcionarios->funcionario[funcionarios->contador].data_ent_empresa.dia = obterInteiro(MIN_DIA, MAX_DIA_FEV, OBTER_DIA);
        } else {
            funcionarios->funcionario[funcionarios->contador].data_ent_empresa.dia = obterInteiro(MIN_DIA, MAX_DIA, OBTER_DIA);
        }
        funcionarios->contador++;
    }
}

/**Função que permite atualizar/editar dados de funcionário
 * 
 * @param funcionário
 */
void atualizarFuncionario(FUNCIONARIO * funcionario) {

    lerString((*funcionario).nome, MAX_NOME_FUNCIONARIO, MSG_OBTER_NOME);

    printf("\n");
    estadoCivil((*funcionario).estadoCivil);

    printf("\n");
    (*funcionario).data_nascimento.ano = obterInteiro(MIN_ANO, MAX_ANO, OBTER_ANO);
    (*funcionario).data_nascimento.mes = obterInteiro(MIN_MES, MAX_MES, OBTER_MES);
    if ((*funcionario).data_nascimento.mes = obterInteiro(MIN_MES, MAX_MES, OBTER_MES) == 2) {
        (*funcionario).data_nascimento.dia = obterInteiro(MIN_DIA, MAX_DIA_FEV, OBTER_DIA);
    } else {
        (*funcionario).data_nascimento.dia = obterInteiro(MIN_DIA, MAX_DIA, OBTER_DIA);
    }

    printf("\n");
    (*funcionario).numeroTele = obterInteiro(MIN_NUM_TELE, MAX_NUM_TELE, OBTER_NUM_TELE);

    printf("\n");
    (*funcionario).dependentes = obterInteiro(MIN_FILHOS, MAX_FILHOS, OBTER_NFILHOS);

    printf("\n");
    cargoEmpresa((*funcionario).cargo);

    printf("\n");
    (*funcionario).receberHora = obterInteiro(MIN_ORDENADO_H, MAX_ORDENADO_H, OBTER_ORDENADO_H);

    printf("\n");
    (*funcionario).data_ent_empresa.ano = obterInteiro(INICIO_EMPRESA, MAX_ANO, OBTER_ANO);
    (*funcionario).data_ent_empresa.mes = obterInteiro(MIN_MES, MAX_MES, OBTER_MES);
    if ((*funcionario).data_ent_empresa.mes == FEVEREIRO) {
        (*funcionario).data_ent_empresa.dia = obterInteiro(MIN_DIA, MAX_DIA_FEV, OBTER_DIA);
    } else {
        (*funcionario).data_ent_empresa.dia = obterInteiro(MIN_DIA, MAX_DIA, OBTER_DIA);
    }

}

/**Função que permite procurar se o funcionário existe, antes de editar os seus dados
 * e atualiza dados de funcionário já existentes
 * @param funcionarios
 */
void atualizarFuncionarios(FUNCIONARIOS * funcionarios) {
    if ((*funcionarios).contador >= 1) {
        int numero = procurarFuncionario(*funcionarios, obterInteiro(MIN_NUM_FUNCIONARIO, MAX_NUM_FUNCIONARIO, MSG_OBTER_NUM_FUNCIONARIO));

        if (numero != -1) {
            atualizarFuncionario(&(*funcionarios).funcionario[numero]);
        } else {
            puts(ERRO_FUNCIONARIO_NAO_EXISTE);
        }
    } else {
        puts(ERRO_FUNCIONARIO);
    }

    printf("\nPressione ENTER para retornar ao Menu...");
    getchar();
    clrscr();
}

/**Função que questiona o utilizador a data de saída do funcionário
 * 
 * @param funcionarios
 */
void removerFuncionario(FUNCIONARIO * funcionario) {
    printf("\nNome do Funcionário: %s\n", (*funcionario).nome);
    (*funcionario).ativo = 1;
    (*funcionario).data_ext_empresa.ano = obterInteiro(INICIO_EMPRESA, MAX_ANO, OBTER_ANO);
    (*funcionario).data_ext_empresa.mes = obterInteiro(MIN_MES, MAX_MES, OBTER_MES);
    if ((*funcionario).data_ext_empresa.mes == 2) {
        (*funcionario).data_ext_empresa.dia = obterInteiro(MIN_DIA, MAX_DIA_FEV, OBTER_DIA);
    } else {
        (*funcionario).data_ext_empresa.dia = obterInteiro(MIN_DIA, MAX_DIA, OBTER_DIA);
    }
}

/**Função que permite remover o funcionário
 * 
 * @param funcionarios
 */
void removerFuncionarios(FUNCIONARIOS * funcionarios) {
    if ((*funcionarios).contador >= 1) {
        int numero = procurarFuncionario(*funcionarios, obterInteiro(MIN_NUM_FUNCIONARIO, MAX_NUM_FUNCIONARIO, MSG_OBTER_NUM_FUNCIONARIO));
        if (numero != -1) {
            removerFuncionario(&(*funcionarios).funcionario[numero]);
        } else {
            puts(ERRO_FUNCIONARIO_NAO_EXISTE);
        }
    } else {
        puts(ERRO_FUNCIONARIO);
    }
    printf("\nPressione ENTER para retornar ao Menu...");
    getchar();
    clrscr();

}

/** Função que procura todos os funcionarios existentes na empresa e imprime todos os funcionarios
 * 
 * @param funcionarios
 */
void listarFuncionarios(FUNCIONARIOS funcionarios) {
    clrscr();
    if (funcionarios.contador >= 1) {
        printf("DADOS DE FUNCIONÁRIO\n");
        printf("____________________\n\n");
        if (funcionarios.contador > 0) {
            int i;
            for (i = 0; i < funcionarios.contador; i++) {
                imprimirFuncionario(funcionarios.funcionario[i]);
                printf("\n_______________________________________\n");
            }
        } else {
            puts(ERRO_LISTA_VAZIA);
        }
    } else {
        puts(ERRO_FUNCIONARIO);
    }
    printf("\nPressione ENTER para retornar ao Menu...");
    getchar();
    clrscr();
}

/** Função que procura o número de funcionário para os vencimentos
 * 
 * @param funcionarios
 * @return  o cargo do funcionario , nome
 */
int procurarFuncionariosVencimentos(FUNCIONARIOS funcionarios) {

    int numero = procurarFuncionario(funcionarios, obterInteiro(MIN_NUM_FUNCIONARIO, MAX_NUM_FUNCIONARIO, MSG_OBTER_NUM_FUNCIONARIO));

    if (numero != -1) {
        imprimirFuncionarioVencimentos(funcionarios.funcionario[numero]);

    } else {
        puts(ERRO_FUNCIONARIO_NAO_EXISTE);
        printf("\nPressione ENTER para retornar ao Menu...");
        getchar();
        clrscr();
        MENU_PRINCIPAL();
    }
    return numero;
}

/** Função que permite imprimir o nome do funcionário e o cargo
 * 
 * @param funcionario
 */
void imprimirFuncionarioVencimentos(FUNCIONARIO funcionario) {
    printf("\n%s\n", funcionario.nome);
    imprimirCargo(funcionario.cargo);

}

/** Função que permite guardar num ficheiro todas as ações executadas pelo o usuário no programa
 * 
 * @param msg
 * @param filename
 */
void logMsg(char *msg, char *filename) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "%d-%02d-%02d %02d:%02d:%02d - %s\n", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec, msg);

    fclose(fp);
}

/** Função que mostra ao usuário o estado que civil que escolheu
 *  
 * @param estadoCivil
 */
void imprimirECivil(int estadoCivil) {
    switch (estadoCivil) {
        case SOLTEIRO:
            printf("\nEstado Civil: Solteiro\n");
            break;
        case CASADO:
            printf("\nEstado Civil: Casado\n");
            break;
        case DIVORCIADO:
            printf("\nEstado Civil: Divorciado\n");
            break;
        case VIUVO:
            printf("\nEstado Civil: Viúvo\n");
            break;
        default:
            printf("\nO número que introduzio não é valido\n");
            break;
    }
}

/** Função que permite ao usuário escolher o Estado Civil
 * 
 * @return 
 */
int estadoCivil() {
    int escolha;
    puts("\n0 - Solteiro"
            "\n1 - Casado"
            "\n2 - Divorciado"
            "\n3 - Viúvo");

    escolha = obterInteiro(MIN_ESTADOCIVIL, MAX_ESTADOCIVIL, OBTER_ESTADOCIVIL);

    switch (escolha) {
        case SOLTEIRO:
            printf("-> Solteiro\n");
            break;
        case CASADO:
            printf("-> Casado\n");
            break;
        case DIVORCIADO:
            printf("-> Divorciado\n");
            break;
        case VIUVO:
            printf("-> Viúvo\n");
            break;
        default:
            printf("\nO número que introduzio não é válido\n"); 
            break;
    }
    return escolha;
}

/** Função que mostra ao usuário o que escolheu no Cargo
 * 
 * @param cargoID
 */
void imprimirCargo(int cargoID) {

    switch (cargoID) {
        case ADMINISTRADOR:
            printf("Cargo: Administrador\n");
            break;
        case CHEFE:
            printf("Cargo: Chefe\n");
            break;
        case FUNCIONARIOSS:
            printf("Cargo: Funcionário\n");
            break;
        default:
            printf("O número que introduzio não é válido\n");
            break;
    }
}

/** Função que mostra os cargos existentes na empresa
 * 
 * @return imprime o cargo selecionado 
 */
int cargoEmpresa() {

    int escolha;
    puts("\n0 - Administrador"
            "\n1 - Chefe"
            "\n2 - Funcionário");

    escolha = obterInteiro(MIN_CARGO, MAX_CARGO, OBTER_CARGO);
    imprimirCargo(escolha);
    return escolha;
}

/** Função que imprime os meses do ano
 * 
 * @param mes
 */
void imprimirMeses(int mes) {
    switch (mes) {
        case JANEIRO:
            printf("\nJaneiro\n");
            break;
        case FEVEREIRO:
            printf("\nFevereiro\n");
            break;
        case MARCO:
            printf("\nMarço\n");
            break;
        case ABRIL:
            printf("\nAbril\n");
            break;
        case MAIO:
            printf("\nMaio\n");
            break;
        case JUNHO:
            printf("\nJunho\n");
            break;
        case JULHO:
            printf("\nJulho\n");
            break;
        case AGOSTO:
            printf("\nAgosto\n");
            break;
        case SETEMBRO:
            printf("\nSetembro\n");
            break;
        case OUTUBRO:
            printf("\nOutubro\n");
            break;
        case NOVEMBRO:
            printf("\nNovembro\n");
            break;
        case DEZEMBRO:
            printf("\nDezembro\n");
            break;
    }
    
}

