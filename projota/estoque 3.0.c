#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// Defiine o máximo de produtos/clientes que pode ser cadastrados
#define LimiteMax 100
#define LimiteMaxRelatório 200
#define ANBT UINT CPAGE_UTF8 = 65001; \
             SetConsoleOutputCP(CPAGE_UTF8); 

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
} ClienteCPF;

typedef struct {
    char nome[50];
    int cnpj;
} ClienteCNPJ;

typedef struct {
    char nome[50];
    int cnpj;
} Fornecedor;

typedef struct {
    char user[64];
    char password[64];
} User;

// definição de variáveis globais //

    //definição de variáveis relacionadas ao login
    User usuario[LimiteMax]; //variavel array que contém os usuários registrados no sistema

    //definição de variaveis relacionadas ao estoque
    Produto estoque[LimiteMax]; // Variavel array que é utilizada para guardar valores
    int produtonum = 0, idTest, nf = 0; // Numeros de produtos do estoque
    float valor, valorTotal;

    //definição de variaveis relacionadas aos clientes
    ClienteCPF clienteFísico[LimiteMax]; // Variavel array que é utilizada para guardar informações de clientes tipo pessoa física
    ClienteCNPJ clienteJurídico[LimiteMax];
    int clientenum = 0, cpfTest, validacaoCliente = 0; //contador de clientes cadastardos / variavel usada pra conferir se existe um cliente cadastrado
        

// definição das funções //

//função de login
int login() {
    char tempUser[64], tempPassword[64];
    printf("##### ID DO USUARIO #####\n");
    scanf("%s", tempUser); //pega o id do usuário
    printf("##### SENHA #####\n");
    scanf("%s", tempPassword); // pega a senha do usuário
    for (int i = 0; i < LimiteMax; i++) {
        if (strcmp(tempUser, usuario[i].user) == 0) {
            for (int i = 0; i < LimiteMax; i++) {
                if (strcmp(tempPassword, usuario[i].password) == 0) {
                    printf("logado com sussexo");
                    return 0;
                }
            }
        }
    }
    printf("usuário ou senha incorretos");
    return 1;
}

//função que faz o print de uma nota fiscal
void notaFiscal(char nome[], time_t data, int qnt, int nf, float valor) {
    printf("Venda registrada com sucesso.\n");
    printf("\n##### Comprovante fiscal#####\n"); 
    printf("Nome do produto: %s\n", nome);
    printf("Quantidade Vendida: %i\n", qnt); 
    printf("valor: %.2f reais \n", valor);
    printf("Nota fiscal n° %i\n", nf); 
    printf("data da emissão: %s", asctime(localtime(&data)));
    printf("##### Farmacia Biopark #####\n");
}

//função que adiciona produtos
int adicionarProdutos() {
    printf("\nID do produto: ");
    scanf("%i", &idTest); //pega o id do produto
    for (int i=0; i <= LimiteMax; i++) { //confere se a id do produto já existe
        if (estoque[i].id == idTest) { //se a id do produto já existe, ele pede a quantidade a ser adicionada a tal produto
            printf("\nErro: ID já existente");
            return 1;
        }
    }
    for (int i = 0; i <= LimiteMax; i++) {
        if (estoque[i].id == 0) {
            produtonum = i;
            break;
        } else {
            produtonum++;
        }
    }
    if (produtonum < LimiteMax) { // se a quantidade de produtos for menor que o limite, ele procede, caso contrário, informa que o estoque está cheio
        if (idTest != 0) { // se o comparador de id for diferente de 0, ele avança pro cadastro do produto
            estoque[produtonum].id = idTest; // define a id do produto

            printf("\nNome do produto: ");
            scanf("%s", estoque[produtonum].nome); // Vai ler o nome do produto
                          
            printf("Insira o valor do produto: R$");
            scanf("%f", &valor); // Lê o valor do produto
                        
            estoque[produtonum].valor = valor; // Armazena o valor lido na estrutura do produto
            produtonum = 0; // Adicionar mais um numero de produto
            idTest = 0; // reseta o idTest

            printf("\n#####Produto registrado com sucesso#####\n");   
        } else {
            printf("ERRO: ID NÃO PODE SER 0");
        }
    } else {
        printf("Erro: estoque cheio!\n");
    }
    return 0;
}

int removerProdutos() {
    printf("\ninsira o ID do produto - ");
    scanf("%i", &idTest);
    int selecaoRemover = 0;
    for (int i=0;i<LimiteMax;i++) {
        if (estoque[i].id == idTest) { //se a id do produto já existe, ele pede a quantidade a ser adicionada a tal produto
            selecaoRemover = i;
            idTest = 0;
            break;
        } 
    }
    if (idTest != 0) {
        printf("\nERRO: ID NÃO EXISTENTE\n");
        return 1;
    }
    printf("\n####Certeza que deseja remover %s? (não poderá ser desfeito)####\n", estoque[selecaoRemover].nome);
    printf("1. Sim\n");
    printf("0. Não\n");
    int opcaoRemover = 0;
    scanf("%i", &opcaoRemover);
    switch (opcaoRemover) {
        case 1: estoque[selecaoRemover].id = 0; estoque[selecaoRemover].quantidade = 0; printf("\nProduto removido com sucesso\n"); break;
        case 0: break;
        default: printf("\nopção invalida\n");
    }
    return 0;
}


int atualizarQuantidade() {
    printf("\nID do produto: ");
    scanf("%i", &idTest); //pega o id do produto
    for (int i=0; i <= LimiteMax; i++) { //confere se a id do produto já existe
        if (estoque[i].id == idTest) { //se a id do produto já existe, ele pede a quantidade a ser adicionada a tal produto
            printf("\nInsira a quantidade a ser adicionada - ");
            scanf("%i", &idTest); //lê a quantidade nova a ser adicionada
            estoque[i].quantidade = estoque[i].quantidade + idTest; //adiciona a quantidade nova a quanitdade já existente
            idTest = 0; //reseta o comparador de id pra 0 e fecha o for
            printf("\n#####Quantidade atualizada com sucesso#####\n");
            return 0;
        }
    }
    if (idTest != 0) {
        printf("erro: produto inexistente");
        idTest = 0;
    }
    return 0;
}

//função que exibe o estoque
void exibirEstoque() {
    printf("\n### Estoque ###\n");
    for (int i = 0; i < LimiteMax; i++) {
        if (estoque[i].id != 0) {
            printf("%s - Id: %i Quantidade: %d Valor: R$%.2f\n", estoque[i].nome, estoque[i].id, estoque[i].quantidade, estoque[i].valor);
        }
    }
}

//função que adiciona clientes
void cadastrarCPF() {
    printf("\ninsira o nome do cliente: ");
    scanf("%s", clienteFísico[clientenum].nome); //pega o nome do cliente

    printf("insira o cpf do cliente (somente numeros): ");
    scanf("%i",&cpfTest); //pega o cpf do cliente

    for (int x = 0; x < LimiteMax; x++) { // pega o cpf do cliente e compara se já existe outro cliente com o mesmo cpf
        if (clienteFísico[x].cpf == cpfTest) {
            validacaoCliente = 1; // define a validação para 1 caso exista outro cliente com o mesmo cpf
            break;
        }
    }
    if (validacaoCliente == 1) { // caso exista outro cliente com o mesmo cpf, informa erro
        printf("\nErro: cpf ja cadastrado.\n");
    } else { // caso não exista outro cliente com o mesmo cpf, informa sucesso
        clienteFísico[clientenum].cpf = cpfTest;
        printf("\n#####Cliente cadastrado com sucesso#####\n");
        clientenum++; // Incrementa o clientenum
    }
    validacaoCliente = 0;// Reseta o valor da validação para 0
}

//função que realiza vendas
int realizarVenda() {
    for (int i=0; i < LimiteMax; i++) { //confere se existe qualquer cliente cadastrado
        if (clienteFísico[i].cpf != 0) {
            validacaoCliente = 1; //define a variavel de checagem de cliente para 1
            break; // sai do for
        }
    }
    if (validacaoCliente != 1) { //caso a variavel de checagem esteja default, executa um mensagem de erro e encerra o case
        printf("\nErro: Nenhum cliente cadastrado\n");
        printf("Por favor cadastre um cliente\n");
    } 
    //adendo: a integração do cliente na venda ainda não foi completamente implementada//
    printf("\nID do produto: ");
    scanf("%i", &idTest);// pega a id do produto
    for (int i=0; i <= LimiteMax; i++) { //confere se a id do produto existe
        if (estoque[i].id == idTest) { //se a id do produto existe, ele pede a quantidade a ser vendida
            int quantidadeVenda; //variavel responsavel pela quantidade vendida
            printf("Quantidade: ");
            scanf("%d", &quantidadeVenda);
            if (estoque[i].quantidade >= quantidadeVenda) {//[i] usando para acessar elemento da array, confere se a quantidade de estoque do produto é maior ou igual a quantidade de venda
                estoque[i].quantidade -= quantidadeVenda; // Diminue a quantidade do produto no estoque
                srand(time(0));//Da start no gerador de numeros aleatorios
                nf = nf + 1;
                valorTotal = estoque[i].valor * quantidadeVenda; //calcula o valor total da venda
                time_t hora = time(NULL);
                notaFiscal(estoque[i].nome, quantidadeVenda, nf, valorTotal, hora); //chama a função que escreve a nota fiscal;
                idTest = 0; //reseta o idTest para 0;
                break; //sai do for
            } else {
                printf("Erro: quantidade insuficiente em estoque.\n"); //caso a quantidade de venda for maior que a do estoque, escreve uma mensagem de erro e sai do case
                idTest = 0; //reseta o idTest pra 0
                break; //sai do for
            }
        }
    }
    if (idTest != 0) { //checa se o id é diferente de zero, caso seja, produz uma mensagem de erro
        printf("Erro: Produto Inexistente.\n");
        idTest = 0; //reseta o idTest
    }
    return 0;
}

//função do menu
void menu() {
    int opcao;
    int subOpcao;
    do {
        printf("\n##### MENU #####\n"); //menu principal
        printf("1. Gerenciar estoque\n");
        printf("2. Gerenciar clientes\n");
        printf("4. Registrar venda\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao); // vai ler a opcao para iniciar o switch case
        switch (opcao) {
            case 1: //abre o submenu relacionado a produtos
                do {
                    printf("\n##### MENU - ESTOQUE #####\n"); //menu principal
                    printf("1. Adicionar produto\n");
                    printf("2. Remover produto\n");
                    printf("3. Atualizar quantidade\n");
                    printf("4. Mostrar estoque\n");
                    printf("5. Gerar relatótio\n");
                    printf("0. Voltar\n");
                    printf("Escolha uma opcao: ");
                    scanf("%d", &subOpcao);
                    switch (subOpcao) {
                        case 1: adicionarProdutos(); break;
                        case 2: removerProdutos(); break; 
                        case 3: atualizarQuantidade(); break;
                        case 4: exibirEstoque(); break;
                        case 5: printf("\nAinda não implementado\n"); break;
                        case 0: break;
                        default: printf("Opcao invalida!\n");
                    }
                } while (subOpcao != 0);
                break; 
            case 2: //abre o submenu relacionado a clientes                    
                do {
                    printf("\n##### MENU - CLIENTES #####\n"); //menu principal
                    printf("1. Cadastrar pessoa física\n");
                    printf("2. Cadastrar pessoa juridíca\n");
                    printf("3. Mostrar lista de cadastros\n");
                    printf("0. Voltar\n");
                    printf("Escolha uma opcao: ");
                    scanf("%d", &subOpcao);
                    switch (subOpcao) {
                        case 1: cadastrarCPF(); break;
                        case 2: printf("\nAinda não implementado\n"); break;
                        case 3: do {
                                    printf("\n##### MOSTRAR LISTA DE CADASTROS #####\n"); //menu principal
                                    printf("1. Mostrar pessoas físicas\n");
                                    printf("2. Mostrar pessoas juridícas\n");
                                    printf("0. Voltar\n");
                                    printf("Escolha uma opcao: ");
                                    scanf("%d", &subOpcao);
                                    switch (subOpcao) {
                                        case 1: printf("\nAinda não implementado\n"); break;
                                        case 2: printf("\nAinda não implementado\n"); break;
                                        case 0: break;
                                        default: printf("Opcao invalida!\n");
                                    }
                                } while (subOpcao != 0); subOpcao = 1; break;
                        case 0: break;
                        default: printf("Opcao invalida!\n");
                    }
                } while (subOpcao != 0);
                break;
            case 4: //chama a função de venda 
                realizarVenda();    
                break; 
            case 0: // Sair
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0); // do while voltando apos o switch para novos comandos
}

int main() {
    ANBT;
    for (int i; i < LimiteMax; i++)  { //pequena função para limpar o lixo da memória dos cpfs dos clientes
        clienteFísico[i].cpf = 0;
        clienteJurídico[i].cnpj = 0;
    }
    int userTest = 0;
    for (int i; i < LimiteMax; i++) {
        if (strcmp(usuario[i].user, "") == 1) {
            userTest = 1;
            break;
        }
    }
    if (userTest == 0) {
        printf("cadastre o primeiro usuário (automáticamente admin)\n");
        printf("Usuario - ");
        scanf("%s", usuario[0].user);
        printf("Senha - ");
        scanf("%s", usuario[0].password);
    }
    int logon = login();
    if (logon == 0) {
        menu();    
    }
    return 0;
}

//ideias//
//dividir o estoque em submenus - joia
//adicionar cadastro de fornecedores
//dividir o cadastro e a atualização de estoque
//adicionar esquema de validade
//não limitar a venda ao cliente cadastrado, separar opções
//adicionar valor ao cliente cadastrado
//cadastrar cpnj
//trocar nf rand por nf count++ - joia
//melhorar aquele login pelo amor de Deus - feito
