#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include "ficheiros.h"
#include  "Menu.h"


int main(int argc, char** argv) {
    int menu;
    logMsg(MSG_INICIAR, MSG_FILE);
    MENU_PRINCIPAL(menu);
    
    return (EXIT_SUCCESS);
}

