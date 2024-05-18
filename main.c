#include "colecao.c"

typedef struct {
    char marca[30];
    int codigoNumerico;
    float valor;
} pacotedCafe;
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
int telainicial();
gCofo *colecao = NULL;
int compint(void *key, void * pacote) {
    pacotedCafe *g;
    g = (pacotedCafe*) pacote;
    int *key_codigoNumerico = (int*) key;
    if(key != NULL) {
        if(pacote != NULL) {
            if(*key_codigoNumerico == g->codigoNumerico){
                return TRUE;
            }
        }
}
return FALSE;
}
int compFloat(void *key, void * pacote) {
    pacotedCafe *g;
    g = (pacotedCafe*) pacote;
    float *key_codigoNumerico = (float*) key;
    if(key != NULL) {
        if(pacote != NULL) {
            if(*key_codigoNumerico == g->valor){
                return TRUE;
            }
        }

}
return FALSE;
}
int compChar(void *key, void * pacote) {
    pacotedCafe *g;
    g = (pacotedCafe*) pacote;
    char *key_codigoNumerico = (char*) key;
    if(key != NULL) {
        if(pacote != NULL) {
            if(strcmp(key, g->marca) == 0){
                return TRUE;
            }
        }
        
}
return FALSE;
}


int main() {
    int opcao1;

    do {
        int opcao2 = telainicial();
        switch (opcao2) {  
            case 1: {
                if (colecao != NULL) {
                printf("Erro: colecao ja foi inicializada.\n");
                break;
                } 
                int quantidadeElm = 0;
                printf("Digite o tamanho da colecao: \n");
                if (scanf("%d", &quantidadeElm) != 1) {
                    printf("Opcao invalida. Tente novamente.\n");
                    limparBuffer(); // Limpar o buffer de entrada
            }
                if(colecao = gcofCreate(quantidadeElm)) {
                    printf("Colecao criado com sucesso!!!\n");
                }
                else {
                    printf("Nao foi possivel criar a colecao!!\n");
                }
                break;
            }
            case 2: {
            if (colecao == NULL) {
                printf("Erro: colecao nao inicializada.\n");
                break;
            }
            int num=0;
            pacotedCafe *novoCafe;
            novoCafe = (pacotedCafe*)malloc(sizeof(pacotedCafe));
            printf("Digite a marca: \n");
            scanf("%s", novoCafe->marca);
            printf("Digite o codigo numerico: \n");
            if (scanf("%d", &(novoCafe->codigoNumerico)) != 1) {
                printf("Opcao invalida. Este item nao sera adicionado.\n");
                limparBuffer();// Limpar o buffer de entrada
                break;
                }   
            novoCafe->codigoNumerico = abs(novoCafe->codigoNumerico);
            printf("Digite o valor em reais: \n");
            if(scanf("%f", &(novoCafe->valor)) != 1) {
                printf("Opcao invalida. Tente novamente.\n");
                limparBuffer();
                break; // Limpar o buffer de entrada
            }
            novoCafe->valor = abs(novoCafe->valor);
            gcofInsert(colecao, (void*)novoCafe);
            break;
            }
            case 3: {
                if (colecao == NULL) {
                    printf("Erro: colecao nao inicializada.\n");
                    break;
                }
                int opcao = 0;
                printf("1 - para remover pela marca\n");
                printf("2 - para remover pelo codigo numerico\n");
                printf("3 - para remover pelo codigo valor\n");
                if (scanf("%d", &opcao) != 1) {
                printf("Opcao invalida. Tente novamente.\n");
                limparBuffer(); // Limpar o buffer de entrada
            }
                switch (opcao) {
                    case 1: {
                        char marca[30];
                         printf("Digite a marca do pacote a ser removido: \n");
                         scanf("%s", marca);
                          pacotedCafe *pacoteRemovido = (pacotedCafe *)gcofRemove(colecao, marca, compChar);
                          if (pacoteRemovido != NULL) {
                            printf("Pacote com a marca %s removido com sucesso.\n", marca);
                            free(pacoteRemovido); 
                           }
                           else {
                            printf("Pacote com a marca %s nao encontrado na colecao.\n", marca);
                           }
                         

                        break;
                    }
                    case 2: {
                        int codigo = 0;
                        printf("Digite o codigo numerico do pacote a ser removido: \n");
                        if (scanf("%d", &codigo) != 1) {
                            printf("Opcao invalida. Tente novamente.\n");
                            limparBuffer(); // Limpar o buffer de entrada
                        }
                        pacotedCafe *pacoteRemovido = (pacotedCafe *)gcofRemove(colecao, &codigo, compint);
                        if (pacoteRemovido != NULL) {
                             printf("Pacote com o codigo numerico %d removido com sucesso.\n", codigo);
                             free(pacoteRemovido); 
                        }
                        else {
                            printf("Pacote com o codigo numerico %d nao encontrado na colecao.\n", codigo);
                        }
                        break;
                    }
                    case 3: {
                        float codigo = 0;
                        printf("Digite o valor do pacote a ser removido: \n");
                        if (scanf("%f", &codigo) != 1) {
                            printf("Opcao invalida. Tente novamente.\n");
                            limparBuffer(); // Limpar o buffer de entrada
                        }
                        pacotedCafe *pacoteRemovido = (pacotedCafe *)gcofRemove(colecao, &codigo, compFloat);
                        if (pacoteRemovido != NULL) {
                             printf("Pacote com o codigo numerico %.2f removido com sucesso.\n", codigo);
                             free(pacoteRemovido); 
                        }
                        else {
                            printf("Pacote com o codigo numerico %.2f nao encontrado na colecao.\n", codigo);
                        }
                        break;
                    }
                    default:
                        printf("Opcao invalida.\n");
                        break;
                }
                break;
            }
            case 4: {
                if (colecao != NULL) {
                    printf("Pacotes de cafe na colecao:\n");
                    pacotedCafe *pacote = gcofGetFirst(colecao);
                    int i = 1; 
                    while (pacote != NULL) {
                        printf("Pacote %d:\n", i);
                        printf("Marca: %s\n", pacote->marca);
                        printf("Codigo Numerico: %d\n", pacote->codigoNumerico);
                        printf("Valor: %.2f\n", pacote->valor);
                        pacote = gcofGetNext(colecao);
                        i++; 
                    }
                }
                else{
                    printf("Colecao nao inicializada!!!\n");
                }
                break;
            }
            case 5: {
                int opcao = 0;
                printf("1 - para pesquisar pela marca\n");
                printf("2 - para pesquisar pelo codigo numerico\n");
                printf("3 - para pesquisar pelo codigo valor\n");
                if(scanf("%d", &opcao) != 1) {
                    printf("Opcao invalida. Tente novamente.\n");
                    limparBuffer(); // Limpar o buffer de entrada
                }
                switch (opcao) {
                    case 1: {
                        char marca[30];
                        printf("Digite a marca do pacote a ser pesquisado: \n");
                        scanf("%s", marca);
                        pacotedCafe *pacoteEncontrado = (pacotedCafe *)gcofQuery(colecao, marca, compChar);
                        if (pacoteEncontrado != NULL) {
                            printf("Pacote encontrado: %s\n", pacoteEncontrado->marca);
                            printf("Marca: %s\n", pacoteEncontrado->marca);
                            printf("Codigo Numerico: %d \n", pacoteEncontrado->codigoNumerico);
                            printf("Valor: %.2f \n", pacoteEncontrado->valor);
                        }
                        else {
                            printf("Pacote com a marca %s nao encontrado na colecao.\n", marca);
                        }
                        break;
                    }
                    case 2: {
                    int codigo = 0;
                    printf("Digite o codigo numerico do pacote a ser pesquisado: \n");
                    if(scanf("%d", &codigo) != 1) {
                        printf("Opcao invalida. Tente novamente.\n");
                        limparBuffer(); // Limpar o buffer de entrada'
                    }
                    pacotedCafe *pacoteEncontrado = (pacotedCafe *)gcofQuery(colecao, &codigo, compint);
                    if(pacoteEncontrado != NULL) {
                        printf("Pacote encontrado com codigo numerico: %d\n", pacoteEncontrado->codigoNumerico);
                        printf("Marca: %s\n", pacoteEncontrado->marca);
                        printf("Codigo Numerico: %d \n", pacoteEncontrado->codigoNumerico);
                        printf("Valor: %.2f \n", pacoteEncontrado->valor);
                    }
                    else {
                        printf("Pacote com o codigo numerico %d nao encontrado na colecao.\n", codigo);
                    }
                    break;
                    } 
                    case 3: {
                        float valor = 0.0;
                        printf("Digite o valor do pacote a ser pesquisado: \n");
                        if(scanf("%f", &valor)!= 1) {
                            printf("Opcao invalida. Tente novamente.\n");
                            limparBuffer(); // Limpar o buffer de entrada'
                        }
                        pacotedCafe *pacoteEncontrado = (pacotedCafe *)gcofQuery(colecao, &valor, compFloat);
                        if (pacoteEncontrado != NULL) {
                            printf("Pacote encontrado com valor: %.2f\n", pacoteEncontrado->valor);
                            printf("Marca: %s\n", pacoteEncontrado->marca);
                            printf("Codigo Numerico: %d \n", pacoteEncontrado->codigoNumerico);
                            printf("Valor: %.2f \n", pacoteEncontrado->valor);
                        }
                        else {
                            printf("Pacote com o valor %.2f nao encontrado na colecao.\n", valor);
                        }
                        break;
                    }
                    default:
                        printf("Opcao invalida.\n");
                        break;

                }
                break;
            }
            case 6: {
                if (gcofDestroy(colecao)) {
                    printf("A colecao foi destruida\n"); 
                    colecao =NULL;
                }
                else {
                    printf("Colecao nao destruida\n");
                }
                break;
            }
            case 7: {
                if (colecao == NULL) {
                    printf("Erro: colecao nao inicializada.\n");
                    break;
            }           
                gcofEmpty(colecao);
                printf("Colecao esvaziada: \n");
                break;
            }

            case 8: {
                printf("Saindo do programa...\n");
                exit(1);
            }
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }

    } while (1);
}

int telainicial() {
    int opcao = 0;
    printf("---------------- Bem vindo ao cofo que armazena pacotes de cafe ----------------\n");
    printf("Digite 1 - para criar uma colecao\n");
    printf("Digite 2 - para inserir pacotes de cafes na colecao\n");
    printf("Digite 3 - para remover algum pacote de cafe da colecao\n");
    printf("Digite 4 - para listar os pacotes de cafe da colecao\n");
    printf("Digite 5 - para consultar algum pacote de cafe da colecao\n");
    printf("Digite 6 - para para destruir a colecao\n");
    printf("Digite 7 - para para esvaziar a colecao\n");
    printf("Digite 8 - para sair\n");
    if(scanf("%d", &opcao)!=1) {
        printf("Opcao invalida. Tente novamente.\n");
        limparBuffer(); // Limpar o buffer de entrada'
                        }
    return opcao;
}

