#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// Defiine o máximo de produtos/clientes que pode ser cadastrados
#define charConst 64 //define a constante do maximo de caracteres por string
#define LimiteMax 100 //define a constante que representa o limite maximo de muita coisa
#define LimiteMaxUser 10 //define a constante que representa o limite maximo de usuarios
#define LimiteMaxRelatório 200 //define a constante que representa o limite maximo de relatórios
#define VALIDO 0
#define INVALIDO 1
#define ANBT UINT CPAGE_UTF8 = 65001; \
             SetConsoleOutputCP(CPAGE_UTF8); 

// Estrutura que representa um produto
typedef struct {
    char nome[charConst]; //elemento que representa o nome do produto
    float valor; //elemento que representa o valor de uma unidade do produto
    int quantidade; //elemento que representa a quantidade disponível do produto
    int id; //elemento que representa o id do produto
} Produto;

// Estrutura que representa um cliente
typedef struct { 
    char nome[charConst]; //elemento que representa o nome do cliente;
    int cpf; //elemento que representa o cpf do cliente;
} ClienteCPF;

// Estrutura que representa uma empresa
typedef struct {
    char RS[charConst]; //elemento que representa a razão social da empresa 
    char TF[charConst]; //elemento que representa o telefone da empresa
    int cnpj; //elemento que representa o cnpj da empresa
} ClienteCNPJ;

// Estrutura que representa um fornecedor
typedef struct {
    char nome[charConst];
    int cnpj;
} Fornecedor;

// Estrutura que representa uma empresa
typedef struct {
    char user[charConst]; //elemento que representa o login/id do usuário
    char password[charConst]; //elemento que representa a senha do usuário
    int accessLevel; //elemento que define o nível de acesso do usuário |1 = normal|2= admin|
} User;

// Estrutura de relatório
typedef struct {
    char nomeProduto[charConst]; //elemento que armazena o nome do produto
    int idProduto; //elemento que armazena o id do produto
    int quantidadeVendida; //elemento que armazena a quantidade vendida
    float valor; //elemento que armazena o valor pelo qual foi vendido
    int notaFiscal; //elemento que armaena a nota fiscal da venda
    time_t dataVenda; //elemento que armazena a data da venda
} Relatotio;

// definição de variáveis globais //

    //definição de variaveis relacionadas a versão do programa
    char buildVersion[charConst] = {"0.4.2"};
    char buildDate[charConst] = {"17/06/2024 14:50"};

    //definição de variaveis relacionadas ao estoque
    Produto estoque[LimiteMax]; // Variavel array que é utilizada para guardar valores
    int produtonum = 0, idTest, nf = 0; // Numeros de produtos do estoque
    float valor, valorTotal;

    //definição de variaveis relacionadas aos clientes
    ClienteCPF clienteFísico[LimiteMax]; //Variavel array que é utilizada para guardar informações de clientes tipo pessoa física
    ClienteCNPJ clienteJurídico[LimiteMax]; //Variavel array que é utilizada para guardar informações de clientes tipo pessoa juridica
    int clientenum = 0; //contador de clientes cadastardos
    int cpfTest=0; //variavel usada pra conferir se existe um cliente cadastrado
    int validacaoCliente = 0;

    ClienteCNPJ empresa[LimiteMax];
    int empresanum = 0; //contador de clientes cnpj cadastardos
    int cnpjTest = 0; //variavel usada pra conferir se existe um cliente cnpj cadastrado
    int validacaoEmpresa = 0; 
      
    char varTemp[charConst] = {'\0'}; //variavel char temporaria usada para validação de input
    int isRunning = 0; //variavel que defnie se o programa continuará rodando ou não ||0: roda||any other: não roda||

// definição das funções //

//função para limpar a variavel temporária
void varTempClean() {
    char varClean[charConst] = {'\0'};
    memcpy(varTemp, varClean, charConst);
}

//função que valida um input apenas numérico
int validateInput(char *input, int size) {
    for (int i=0;i<size;i++) {
        // debuggng // printf("input[%d]: %c\n", i, input[i]);
        if(!isdigit(input[i]) && (input[i] != '\0')) {
            printf("input invalido!\n");
            varTempClean();
            // debugging // printf("vartemp: %s\n", input);
            return INVALIDO;
        }
        // debugging // printf("ainda no for\n");
    }
    // debugging // printf("saiu do for\n");
    return VALIDO;
}

//função de login
int login(User *usuario) {
    char tempUser[charConst], tempPassword[charConst];
    printf("##### ID DO USUARIO #####\n");
    scanf("%s", tempUser); //pega o id do usuário
    printf("##### SENHA #####\n");
    scanf("%s", tempPassword); // pega a senha do usuário
    for (int i = 0; i < LimiteMaxUser; i++) { //estrutura for pra percorrer o array de usuários
        if (strcmp(tempUser, usuario[i].user) == 0) { //if comparando o id do usuário informado com a base de dados, caso encontre o usuário, procede pra checkagem de senha
            if (strcmp(tempPassword, usuario[i].password) == 0) { //compara a senha informada com a senha do usuário encontrado na base de dados, caso esteja correta, procede para retornar sucesso
                if (usuario[i].accessLevel == 2) {
                    printf("logado com sussexo"); //mensagem de login bem sucedido
                    return 2; //retorna 2 (login admin bem sucedido)
                }
                printf("logado com sussexo"); //mensagem de login bem sucedido
                return 0; //retorna 0 (login bem sucedido)
            }
        }
    }
    printf("usuário ou senha incorretos"); //mensagem de erro de login
    return 1; //retorna 1 (login mal sucedido)
}

//função que cadastra o primeiro usuário do sistema (admin)
int registrarAdmin(User *usuario, int *userCount) {
    int tempOpcao;
    printf("#### CADASTRAMENTO DE ADMIN ####\n");
    printf("informe o login do administrador - ");
    scanf("%s", usuario[0].user);
    printf("informe a senha do administrador - ");
    scanf("%s", usuario[0].password);
    usuario[0].accessLevel = 2;
    puts("adiministrador registrado com sucesso");
    userCount++;
    return 0;
}

//função que cadastra um novo usuário no sistema
int registrarUsuario(User *usuario, int *userCount) {
    int tempOpcao;
    int tempCount = *userCount;
    printf("#### CADASTRAMENTO DE USUÁRIO ####\n");
    printf("informe o login do novo usuário - ");
    scanf("%s", usuario[tempCount].user);
    printf("informe a senha do novo usuário - ");
    scanf("%s", usuario[tempCount].password);
    do {
        printf("informe o nivel de acesso do novo usuário\n1. normal\n2. administador\nEscolha uma opção: ");
        scanf("%d", &tempOpcao);
        switch (tempOpcao) {
            case 1: usuario[tempCount].accessLevel = 1; tempOpcao = -1; break;
            case 2: usuario[tempCount].accessLevel = 2; tempOpcao = -1; break;
            default: puts("opção invalida"); break;
        }
    } while (tempOpcao != -1);
    puts("usuário registrado com sucesso");
    userCount++;
    return 0;
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
    for (int i=0; i<LimiteMax; i++) { //confere se a id do produto já existe
        if (estoque[i].id == idTest) { //se a id do produto já existe, ele pede a quantidade a ser adicionada a tal produto
            printf("\nErro: ID já existente");
            return 1;
        }
    }
    for (int i=0; i<LimiteMax; i++) {
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

//função que remove produtos cadastrados
int removerProdutos() {
    printf("\ninsira o ID do produto - ");
    scanf("%i", &idTest);
    int selecaoRemover = 0;
    for (int i=0; i<LimiteMax; i++) {
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
    printf("Escolha uma opção: ");
    int opcaoRemover = 0;
    scanf("%i", &opcaoRemover);
    switch (opcaoRemover) {
        case 1: estoque[selecaoRemover].id = 0; estoque[selecaoRemover].quantidade = 0; printf("\nProduto removido com sucesso\n"); break;
        case 0: break;
        default: printf("\nopção invalida\n");
    }
    return 0;
}

//função que atualiza a quantidade de produtos (só adiciona na verdade)
int atualizarQuantidade() {
    printf("\nID do produto: ");
    scanf("%i", &idTest); //pega o id do produto
    for (int i=0; i<LimiteMax; i++) { //confere se a id do produto já existe
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
void exibirEstoque(Produto *estoque) {
    printf("\n### Estoque ###\n");
    for (int i = 0; i <LimiteMax; i++) {
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

    for (int x=0; x <LimiteMax; x++) { // pega o cpf do cliente e compara se já existe outro cliente com o mesmo cpf
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

//Função para adicionar CNPJ
void cadastrarCNPJ () {
    printf("\nRazao Social: ");
    scanf("%s", empresa[empresanum].RS); //pega o nome da empresa
    printf("\nCNPJ (somente numeros): ");
    scanf("%i",&cnpjTest); //pega o cnpj da empresa 
    printf("\nTelefone (somente numeros): ");
    scanf("%s", &empresa[empresanum].TF);
    for (int z=0; z<LimiteMax; z++) { // pega o cnpj da empresa e compara se já existe outra empresa com o mesmo cnpj
        if (empresa[z].cnpj == cnpjTest) {
            printf("Testando: %i", empresa[z].cnpj);
            validacaoEmpresa = 1; // define a validação para 1 caso exista outro cliente com o mesmo cnpj
            break;
        }
    }
    if (validacaoEmpresa == 1) { // caso exista outra empresa com o mesmo CNPJ, informa erro
        printf("\nErro: CNPJ ja cadastrado.\n");
    }
    else { // caso não exista outra empresa com o mesmo cnpj, informa sucesso
        empresa[empresanum].cnpj = cnpjTest;
        printf("\n#####Empresa cadastrada com sucesso#####\n");
        empresanum++; // Incrementa o Empresanum
    }
    validacaoEmpresa = 0;// Reseta o valor da validação para 0
}

//função que realiza vendas
int realizarVenda() {
    for (int i=0; i<LimiteMax; i++) { //confere se existe qualquer cliente cadastrado
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
    for (int i=0; i<LimiteMax; i++) { //confere se a id do produto existe
        if (estoque[i].id == idTest) { //se a id do produto existe, ele pede a quantidade a ser vendida
            int quantidadeVenda; //variavel responsavel pela quantidade vendida
            printf("Quantidade: ");
            scanf("%d", &quantidadeVenda);
            if (estoque[i].quantidade >= quantidadeVenda) {//[i] usando para acessar elemento da array, confere se a quantidade de estoque do produto é maior ou igual a quantidade de venda
                estoque[i].quantidade -= quantidadeVenda; // Diminue a quantidade do produto no estoque
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

//função do menu (administrador)
void menuAdmin(User *usuario, int *userCount) {
    int opcao;
    int subOpcao;
    do {
        printf("\n##### MENU #####\n"); //menu principal
        printf("1. Gerenciar estoque\n");
        printf("2. Gerenciar clientes\n");
        printf("3. Registrar venda\n");
        printf("0. Sair\n");
        do {
            printf("Escolha uma opcao: ");
            scanf("%s", &varTemp);
        } while (validateInput(varTemp, charConst) == INVALIDO);
        opcao = atoi(varTemp);
        varTempClean();
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
                    do {
                        printf("Escolha uma opcao: ");
                        scanf("%s", &varTemp);
                    } while (validateInput(varTemp, charConst) == INVALIDO);
                    subOpcao = atoi(varTemp);
                    varTempClean(); 
                    switch (subOpcao) {
                        case 1: adicionarProdutos(); break;
                        case 2: removerProdutos(); break; 
                        case 3: atualizarQuantidade(); break;
                        case 4: exibirEstoque(estoque); break;
                        case 5: printf("\nAinda não implementado\n"); break;
                        case 0: break;
                        default: printf("Opcao invalida!\n");
                    }
                } while (subOpcao != 0);
                break; 
            case 2: //abre o submenu relacionado a clientes                    
                do {
                    printf("\n##### MENU - PESSOAS #####\n"); //menu principal
                    printf("1. Cadastrar pessoa física\n");
                    printf("2. Cadastrar pessoa juridíca\n");
                    printf("3. Mostrar lista de cadastros\n");
                    printf("4. Cadastrar novo usuário\n");
                    printf("0. Voltar\n");
                    do {
                        printf("Escolha uma opcao: ");
                        scanf("%s", &varTemp);
                    } while (validateInput(varTemp, charConst) == INVALIDO);
                    subOpcao = atoi(varTemp);
                    varTempClean();
                    switch (subOpcao) {
                        case 1: cadastrarCPF(); break;
                        case 2: cadastrarCNPJ(); break;
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
                        case 4: registrarUsuario(usuario, userCount); break;
                        case 0: break;
                        default: printf("Opcao invalida!\n");
                    }
                } while (subOpcao != 0);
                break;
            case 3: //chama a função de venda 
                realizarVenda();    
                break; 
            case 0: // Sair
                do {
                    printf("\n##### SAIR #####\n");
                    printf("1. Trocar usuário\n");
                    printf("2. Fechar o programa\n");
                    do {
                        printf("Escolha uma opcao: ");
                        scanf("%s", &varTemp);
                    } while (validateInput(varTemp, charConst) == INVALIDO);
                    subOpcao = atoi(varTemp);
                    varTempClean();
                    switch (subOpcao) {
                        case 1: printf("Saindo...\n"); break;
                        case 2: printf("Fechando...\n"); isRunning = 1; break;
                        default: printf("Opção invalida!\n");
                    }
                } while ((subOpcao != 1) && (subOpcao != 2));
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0); // do while voltando apos o switch para novos comandos
}

//função do menu (padrão)
void menuDefault(User *usuario, int *userCount) {
    int opcao;
    int subOpcao;
    do {
        printf("\n##### MENU #####\n"); //menu principal
        printf("1. Gerenciar estoque\n");
        printf("2. Gerenciar pessoas\n");
        printf("3. Registrar venda\n");
        printf("0. Sair\n");
        do {
            printf("Escolha uma opcao: ");
            scanf("%s", &varTemp);
        } while (validateInput(varTemp, charConst) == INVALIDO);
        opcao = atoi(varTemp);
        varTempClean();
        switch (opcao) {
            case 1: //abre o submenu relacionado a produtos
                do {
                    printf("\n##### MENU - ESTOQUE #####\n"); //menu principal
                    printf("1. Adicionar produto\n");
                    printf("2. Remover produto\n");
                    printf("3. Atualizar quantidade\n");
                    printf("4. Mostrar estoque\n");
                    printf("0. Voltar\n");
                    do {
                        printf("Escolha uma opcao: ");
                        scanf("%s", &varTemp);
                    } while (validateInput(varTemp, charConst) == INVALIDO);
                    subOpcao = atoi(varTemp);
                    varTempClean(); 
                    switch (subOpcao) {
                        case 1: adicionarProdutos(); break;
                        case 2: removerProdutos(); break; 
                        case 3: atualizarQuantidade(); break;
                        case 4: exibirEstoque(estoque); break;
                        case 0: break;
                        default: printf("Opcao invalida!\n");
                    }
                } while (subOpcao != 0);
                break; 
            case 2: //abre o submenu relacionado a clientes                    
                do {
                    printf("\n##### MENU - PESSOAS #####\n"); //menu principal
                    printf("1. Cadastrar pessoa física\n");
                    printf("2. Cadastrar pessoa juridíca\n");
                    printf("3. Mostrar lista de cadastros\n");
                    printf("0. Voltar\n");
                    do {
                        printf("Escolha uma opcao: ");
                        scanf("%s", &varTemp);
                    } while (validateInput(varTemp, charConst) == INVALIDO);
                    subOpcao = atoi(varTemp);
                    varTempClean();
                    switch (subOpcao) {
                        case 1: cadastrarCPF(); break;
                        case 2: cadastrarCNPJ(); break;
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
            case 3: //chama a função de venda 
                realizarVenda();    
                break; 
            case 0: // Sair
                do {
                    printf("##### SAIR #####");
                    printf("1. Trocar usuário\n");
                    printf("2. Fechar o programa");
                    do {
                        printf("Escolha uma opcao: ");
                        scanf("%s", &varTemp);
                    } while (validateInput(varTemp, charConst) == INVALIDO);
                    subOpcao = atoi(varTemp);
                    varTempClean();
                    switch (subOpcao) {
                        case 1: printf("Saindo...\n"); break;
                        case 2: printf("Fechando...\n"); isRunning = 1; break;
                        default: printf("Opção invalida!\n");
                    }
                } while ((subOpcao != 1) || (subOpcao !=2));
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0); // do while voltando apos o switch para novos comandos
}

//função que pede se o usuário quer fechar o programa ou tentar o login novamente
int retry(int retry) {
    do {
        printf("\ntentar novamente?\n");
        printf("1. sim\n");
        printf("2. não\n");
        do {
            printf("Escolha uma opcao: ");
            scanf("%s", &varTemp);
        } while (validateInput(varTemp, charConst) == INVALIDO);
        retry = atoi(varTemp);
        varTempClean();
        switch (retry) {
            case 1: break;
            case 2: isRunning = 1; break;
            default: printf("opção invalida!\n");
                     retry = 0;
        } 
    } while (retry == 0);
    return 0;
}

//função que mostra a versão da build do programa e sua data
void disclaimer() {
    printf("######## ESTOQUE 4.0 ########\n");
    printf("build: %s\n", buildVersion);
    printf("date: %s\n", buildDate);
    printf("Todos os direitos reservados.\n");
    printf("#############################\n\n");
}

int main() {
    ANBT;
    disclaimer();
    //definição de variáveis relacionadas ao login
    int userCount = 0; //variavel que conta quantos usuários cadstrados existem
    User usuario[LimiteMaxUser]; //variavel array que contém os usuários registrados no sistema
    
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
        printf("Nenhum usuário registrado, favor registrar um usuário\n\n");
        registrarAdmin(usuario, &userCount);
    }
    do {
            int logon = login(usuario);
            int tryAgain = 0;
            switch (logon) {
                case 0: menuDefault(usuario, &userCount); break;
                case 2: menuAdmin(usuario, &userCount); break; 
                default: retry(&tryAgain);
            }
    } while (isRunning == 0);
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
