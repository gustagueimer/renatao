#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define ProdutosMax 100 // Defiine o maximo de produtos

// Estrutura que representa um produto
typedef struct {
    char nome[50];
    float valor;
    int quantidade, id;
} Produto;

// Estrutura que representa um cliente
typedef struct {
    char nome[50];
    int cpf;
} Cliente;

void notaFiscal(char nome[], int qnt, int nf, float valor) {
    printf("Venda registrada com sucesso.\n");
    printf("\n##### Comprovante fiscal#####\n"); // print do comprovante fiscal com informacoes
    printf("Nome do produto: %s\n", nome);
    printf("Quantidade Vendida: %i\n", qnt);
    printf("Nota fiscal %i\n", nf); //nota fiscal com numero aleatorio para toda vez ser uma nota diferente da outra
    printf("valor: %f reais \n", valor);
    printf("##### Farmacia Biopark #####\n");
}

int main() {

    int senha, login;

    printf("##### ID DO USUARIO #####\n");
    scanf("%d", &login);
    
    printf("##### SENHA #####\n");
    scanf("%d", &senha);
    if (login==1234 && senha==1234){

        //definição de variaveis relacionadas ao estoque
        Produto estoque[ProdutosMax]; // Variavel array que é utilizada para guardar valores
        int produtonum = 0, idTest, nf; // Numeros de produtos do estoque
        float valor, valorTotal;

        //definição de variaveis relacionadas aos clientes
        Cliente cliente[ProdutosMax]; // Variavel array que é utilizada para guardar informações de clientes
        int clientenum = 0, validacaoCliente = 0; //contador de clientes cadastardos / variavel usada pra conferir se existe um cliente cadastrado

        for (int i; i < ProdutosMax; i++)  { //pequena função para limpar o lixo da memória dos cpfs dos clientes
            cliente[i].cpf = 0;
        }

        int opcao;
        do {
            printf("\n##### MENU #####\n"); //menu principal
            printf("1. Adicionar produto\n");
            printf("2. Cadatrar clientes\n");
            printf("3. Mostrar estoque\n");
            printf("4. Registrar venda\n");
            printf("0. Sair\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &opcao); // vai ler a opcao para iniciar o switch case

            switch (opcao) {
                case 1: // função 1 vai adicionar produtos / quantidade / valor
                    printf("\nID do produto: ");
                    scanf("%i", &idTest); //pega o id do produto
                    for (int i=0; i <= ProdutosMax; i++) { //confere se a id do produto já existe
                        if (estoque[i].id == idTest) { //se a id do produto já existe, ele pede a quantidade a ser adicionada a tal produto
                            printf("\nInsira a quantidade a ser adicionada - ");
                            scanf("%i", &idTest); //lê a quantidade nova a ser adicionada
                            estoque[i].quantidade = estoque[i].quantidade + idTest; //adiciona a quantidade nova a quanitdade já existente
                            idTest = 0; //reseta o comparador de id pra 0 e fecha o for
                            printf("\n#####Quantidade atualizada com sucesso#####\n");   
                            break;
                        }
                    }
                    if (produtonum < ProdutosMax) { // se a quantidade de produtos for menor que o limite, ele procede, caso contrário, informa que o estoque está cheio
                        if (idTest != 0) { // se o comparador de id for diferente de 0, ele avança pro cadastro do produto
                            estoque[produtonum].id = idTest; // define a id do produto

                            printf("\nNome do produto: ");
                            scanf("%s", estoque[produtonum].nome); // Vai ler o nome do produto
                    
                            printf("Quantidade: ");
                            scanf("%d", &estoque[produtonum].quantidade); // Vai ler a quantidade de produtos disponiveis
                        
                            printf("Insira o valor: R$");
                            scanf("%f", &valor); // Lê o valor do produto
                        
                            estoque[produtonum].valor = valor; // Armazena o valor lido na estrutura do produto
                            produtonum++; // Adicionar mais um numero de produto
                            idTest = 0; // reseta o idTest

                            printf("\n#####Produto registrado com sucesso#####\n");   
                        }
                    } else {
                        printf("Erro: estoque cheio!\n");
                    }
                    break;
                case 2:



                    break;
                case 3: // Função 3 vai mostrar o id do produto, o nome do produto, a quantidade disponivel no estoque e o valor
                    printf("\n### Estoque ###\n");
                    for (int i = 0; i < produtonum; i++) {
                        printf("%s - Id: %i Quantidade: %d Valor: R$%.2f\n", estoque[i].nome, estoque[i].id, estoque[i].quantidade, estoque[i].valor);
                    }
                    break;
                case 4: // Função 4 vai registrar qualquer venda feita printando uma nota fiscal 
                    for (int i=0; i < ProdutosMax; i++) { //confere se existe qualquer cliente cadastrado
                       if (cliente[i].cpf != 0) {
                       validacaoCliente = 1; //define a variavel de checagem de cliente para 1
                       break;
                       }
                    }
                    if (validacaoCliente != 1) { //caso a variavel de checagem esteja default, executa um mensagem de erro e encerra o case
                        printf("\nErro: Nenhum cliente cadastrado\n");
                        printf("Favor cadastrar um cliente\n");
                        break;
                    } 
                    printf("\nID do produto: ");
                    scanf("%i", &idTest);// pega a id do produto
                    for (int i=0; i <= ProdutosMax; i++) { //confere se a id do produto existe
                        if (estoque[i].id == idTest) { //se a id do produto já existe, ele pede a quantidade a ser adicionada a tal produto
                            int quantidadeVenda; //variavel responsavel pela quantidade vendida
                            printf("Quantidade: ");
                            scanf("%d", &quantidadeVenda);
                            if (estoque[i].quantidade >= quantidadeVenda) {//[i] usando para acessar elemento da array, confere se a quantidade de estoque do produto é maior ou igual a quantidade de venda
                                estoque[i].quantidade -= quantidadeVenda; // Diminue a quantidade do produto no estoque
                                srand(time(0));//Da start no gerador de numeros aleatorios
                                nf= rand() % 99999; //gera numero aleatorio para comprovante fiscal
                                valorTotal = estoque[i].valor * quantidadeVenda; //calcula o valor total da venda
                                notaFiscal(estoque[i].nome, quantidadeVenda, nf, valorTotal); //chama a função que escreve a nota fiscal;
                                idTest = 0; //reseta o idTest para 0;
                                break; //sai do case
                            } else {
                                printf("Erro: quantidade insuficiente em estoque.\n"); //caso a quantidade de venda for maior que a do estoque, escreve uma mensagem de erro e sai do case
                                idTest = 0; //reseta o idTest pra 0
                                break; //sai do case
                            }
                        }
                    }
                    if (idTest != 0) { //checa se o id é diferente de zero, caso seja, produz uma mensagem de erro
                        printf("Erro: Produto Inexistente.\n");
                        idTest = 0; //reseta o idTest
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