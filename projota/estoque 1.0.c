#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define ProdutosMax 100 // Defiine o maximo de produtos

// Estrutura que representa um produto
typedef struct {
    char nome[50];
    int quantidade, valor, id;
} Produto;

int main() {

    int senha, login;

    printf("##### ID DO USUARIO #####\n");
    scanf("%d", &login);
    
    printf("##### SENHA #####\n");
    scanf("%d", &senha);
    if (login==1234 && senha==1234){

        Produto estoque[ProdutosMax]; // Variavel array que e utilizada para guardar valores
        int produtonum = 0, idTest, nt; // Numeros de produtos do estoque
        int valor, valortotal;

        int opcao;
        do {
            printf("\n##### MENU #####\n");
            printf("1. Adicionar produto\n");
            printf("2. Mostrar estoque\n");
            printf("3. Registrar venda\n");
            printf("0. Sair\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &opcao); // vai ler a opcao para iniciar o switch case

            switch (opcao) {
                case 1: // funcao 1 vai adicionar produtos / quantidade / valor
                    if (produtonum < ProdutosMax) {
                        printf("\nID do produto: ");
                        scanf("%d", &estoque[produtonum].id); // Vai ler o id do produto

                        printf("\nNome do produto: ");
                        scanf("%s", estoque[produtonum].nome); // Vai ler o nome do produto
                    
                        printf("Quantidade: ");
                        scanf("%d", &estoque[produtonum].quantidade); // Vai ler a quantidade de produtos disponiveis
                        
                        printf("Insira o valor: ");
                        scanf("%d", &valor); // Lê o valor do produto
                        
                        estoque[produtonum].valor = valor; // Armazena o valor lido na estrutura do produto
                        produtonum++; // Adicionar mais um numero de produto

                        printf("\n#####Produto registrado com sucesso#####\n");
                    } else {
                        printf("Erro: estoque cheio!\n");
                    }
                    break;
                case 2: // Funcao 2 vai mostrar nome do produto a quantidade disponivel no estoque e o valor
                    printf("\n### Estoque ###\n");
                    for (int i = 0; i < produtonum; i++) {
                        printf("%s - Id: %i Quantidade: %d Valor: %d\n", estoque[i].nome, estoque[i].id, estoque[i].quantidade, estoque[i].valor);
                    }
                    break;
                case 3: // Vai registrar qualquer venda feita printando um comprovante fiscarl
                    printf("\nNome do produto: ");
                    char produtovenda[50];
                    scanf("%s", produtovenda);
                    
                    int quantidadevenda; //variavel responsavel pela quantidade vendida
                    printf("Quantidade: ");
                    scanf("%d", &quantidadevenda);
                    for (int i = 0; i < produtonum; i++) {
                        if (strcmp(estoque[i].nome, produtovenda) == 0) {// strcmp compara duas strings
                            if (estoque[i].quantidade >= quantidadevenda) {//[i] usando para acessar elemento da array
                                estoque[i].quantidade -= quantidadevenda; // Diminue a quantidade do produto no estoque
                                srand(time(0));//Da start no gerador de numeros aleatorios
                                nt= rand() % 99999; //gera numero aleatorio para comprovante fiscal
                                valortotal = estoque[i].valor * quantidadevenda;
                                
                                printf("Venda registrada com sucesso.\n");
                                printf("\n##### Comprovante fiscal#####\n"); // print do comprovante fiscal com informacoes
                                printf("Nome do produto: %s\n", produtovenda);
                                printf("Quantidade Vendida: %d\n", quantidadevenda);
                                printf("Nota fiscal %d\n", nt); //nota fiscal com numero aleatorio para toda vez ser uma nota diferente da outra
                                printf("valor: %d reais \n", valortotal);
                                printf("##### Farmacia Biopark #####\n");
                            } else {
                                printf("Erro: quantidade insuficiente em estoque.\n");
                            }
                            break;
                        }
                    }
                    break;
                case 0: // Sair
                    printf("Saindo...\n");
                    break;
                default:
                    printf("Opcao invalida!\n");
            }
        } while (opcao != 0); // do while voltando apos o switch para novos comandos
    } else {
        printf("Login ou senha incorreto\n"); // id ou senha incorreta printa que o login ou senha estao incorreto
    }

    return 0;
}
