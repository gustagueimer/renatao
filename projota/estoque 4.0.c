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
#define VALIDO 0 //define valido como 0
#define INVALIDO 1 //define invalido como 1
#define ANBT UINT CPAGE_UTF8 = 65001; \
             SetConsoleOutputCP(CPAGE_UTF8); //define o bagulhonson pra deixar o terminal mostrar acentos e etc

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
char buildVersion[charConst] = {"0.4.7"}; //variável que armazena o numero da versão da build
char buildDate[charConst] = {"25/06/2024 11:11"}; //variável que armazena a data e hora da versão da build

//definição de variáveis relacionadas a verificação de inputs
char varTemp[charConst] = {'\0'}; //variavel char temporaria usada para validação de input

//definição de variáveis relacionadas a se o programa está rodando e quantas vazes ele já rodou
int isRunning = 0; //variavel que defnie se o programa continuará rodando ou não ||0: roda||any other: não roda||
int timesRunned = 0; //variável que vai guardar o numero de execuções que o programa já teve

// definição das funções //

//função para limpar a variavel temporária
void varTempClean() {
    char varClean[charConst] = {'\0'};
    memcpy(varTemp, varClean, charConst);
}

//funções relacionadas ao sistema de arquivos

    //função que lê o arquivo que armazena o valor de quantas vezes o programa já foi rodado
    int getTimesRunnedValue() {
        FILE *file_timesRunned;
        file_timesRunned = fopen("TimesRunned.txt", "r");
        if (file_timesRunned != NULL) {
            fscanf(file_timesRunned, "%d", &timesRunned);
        }
        fclose(file_timesRunned);
        return 0;
    }

    //função que cria um arquivo com o valor de quantas vezes o programa já foi rodado
    int saveTimesRunnedValue() {
        FILE *file_timesRunned;
        file_timesRunned = fopen("TimesRunned.txt", "w");
        fprintf(file_timesRunned, "%d\n", timesRunned);
        fclose(file_timesRunned);
        return 0;
    }

    //função que lê o arquivo que armazena as informações relacionadas aos usuários
    int getUsersValues(User *usuarios) {
        FILE *file_usuarios;
        file_usuarios = fopen("Usuarios.txt", "r");
        if (file_usuarios != NULL) {
            for (int i=0; i<LimiteMaxUser; i++) {
                fscanf(file_usuarios, "%s", &usuarios[i].user);
                fscanf(file_usuarios, "%s", &usuarios[i].password);
                fscanf(file_usuarios, "%i", &usuarios[i].accessLevel);
            }
        }
        fclose(file_usuarios);
        return 0;
    }

    //função que cria um arquivo com as informações relacionadas aos usuários
    int saveUsersValues(User *usuarios) {
        FILE *file_usuarios;
        file_usuarios = fopen("Usuarios.txt", "w");
        for (int i=0; i<LimiteMaxUser; i++) {
            fprintf(file_usuarios, "%s\n", usuarios[i].user);
            fprintf(file_usuarios, "%s\n", usuarios[i].password);
            fprintf(file_usuarios, "%d\n", usuarios[i].accessLevel);
        }
        fclose(file_usuarios);
        return 0;
    }

    //função que lê o arquivo que armazena os valores das variáveis de contagem
    int getCountsValues(int *userCount, int *produtosCount, int *clientesCount, int *empresasCount) {
        FILE *file_counts;
        file_counts = fopen("Counts.txt", "r");
        if (file_counts != NULL) {
            fscanf(file_counts, "%d", userCount);
            fscanf(file_counts, "%d", produtosCount);
            fscanf(file_counts, "%d", clientesCount);
            fscanf(file_counts, "%d", empresasCount);
        }
        fclose(file_counts);
        return 0;
    }

    //função que cria um arquivo com os valores das variáveis de contagem
    int saveCountsValues(int userCount, int produtosCount, int clientesCount, int empresasCount) {
        FILE *file_counts;
        file_counts = fopen("Counts.txt", "w");
        fprintf(file_counts, "%d\n", userCount);
        fprintf(file_counts, "%d\n", produtosCount);
        fprintf(file_counts, "%d\n", clientesCount);
        fprintf(file_counts, "%d\n", empresasCount);
        fclose(file_counts);
        return 0;
    }

    //função que lê o arquivo que armazena o valor da variável que conta as notas fiscais
    int getNotaFiscalValue(int *notaFiscal) {
        FILE *file_notaFiscal;
        file_notaFiscal = fopen("NotaFiscal.txt", "r");
        if (file_notaFiscal != NULL) {
            fscanf(file_notaFiscal, "%d", notaFiscal);
        }
        fclose(file_notaFiscal);
        return 0;
    }
  
    //função que cria um arquivo com o valor da variável que conta as notas fiscais
    int saveNotaFiscalValue(int notaFiscal) {
        FILE *file_notaFiscal;
        file_notaFiscal = fopen("NotaFiscal.txt", "w");
        fprintf(file_notaFiscal, "%d\n", notaFiscal);
        fclose(file_notaFiscal);
        return 0;
    }

    //função que lê o arquivo que armazena as informações relacionadas a variável de estoque dos produtos
    int getEstoqueValues(Produto *estoque) {
        FILE *file_estoque;
        file_estoque = fopen("Estoque.txt", "r");
        if (file_estoque != NULL) {
            for (int i=0; i<LimiteMax; i++) {
                fscanf(file_estoque, "%s", &estoque[i].nome);
                fscanf(file_estoque, "%i", &estoque[i].id);
                fscanf(file_estoque, "%i", &estoque[i].quantidade);
                fscanf(file_estoque, "%f", &estoque[i].valor);
            }
        }
        fclose(file_estoque);
        return 0;
    }

    //função que cria um arquivo com as informações relacionadas a variável de estoque dos produtos
    int saveEstoqueValues(Produto *estoque) {
        FILE *file_estoque;
        file_estoque = fopen("Estoque.txt", "w");
        for (int i=0; i<LimiteMax; i++) {
            fprintf(file_estoque, "%s\n", estoque[i].nome);
            fprintf(file_estoque, "%d\n", estoque[i].id);
            fprintf(file_estoque, "%d\n", estoque[i].quantidade);
            fprintf(file_estoque, "%f\n", estoque[i].valor);
        }
        fclose(file_estoque);
        return 0;
    }

    //função que lê um arquivocom as informações relacionadas a variável de clientes cadastrados
    int getClientesValues(ClienteCPF *clientes) {
        FILE *file_clientes;
        file_clientes = fopen("Clientes.txt", "r");
        if (file_clientes != NULL) {
            for (int i=0; i<LimiteMax; i++) {
                fscanf(file_clientes, "%s", &clientes[i].nome);
                fscanf(file_clientes, "%d", &clientes[i].cpf);
            }
        }
        fclose(file_clientes);
        return 0;
    }

    //função que cria um arquivo com as informações relacionadas a variável de clientes cadastrados
    int saveClientesValues(ClienteCPF *clientes) {
        FILE *file_clientes;
        file_clientes = fopen("Clientes.txt", "w");
        for (int i=0; i<LimiteMax; i++) {
            fprintf(file_clientes, "%s\n", clientes[i].nome);
            fprintf(file_clientes, "%d\n", clientes[i].cpf);
        }
        fclose(file_clientes);
        return 0;
    }

    //função que lê um arquivo com as infrmações relacionadas a variável de empresas cadastradas
    int getEmpresasValues(ClienteCNPJ *empresas) {
        FILE *file_empresas;
        file_empresas = fopen("Empresas.txt", "r");
        if (file_empresas != NULL) {
            for (int i=0; i<LimiteMax; i++) {
                fscanf(file_empresas, "%s", &empresas[i].RS);
                fscanf(file_empresas, "%i", &empresas[i].cnpj);
                fscanf(file_empresas, "%s", &empresas[i].TF);
            }
        }
        fclose(file_empresas);
        return 0;
    }

    //função que cria um arquivo com as informações relacionadas a variável de empresas cadastradas
    int saveEmpresasValues(ClienteCNPJ *empresas) {
        FILE *file_empresas;
        file_empresas = fopen("Empresas.txt", "w");
        for (int i=0; i<LimiteMax; i++) {
            fprintf(file_empresas, "%s\n", empresas[i].RS);
            fprintf(file_empresas, "%i\n", empresas[i].cnpj);
            fprintf(file_empresas, "%s\n", empresas[i].TF);
        }
        fclose(file_empresas);
        return 0;
    }

//função que valida um input apenas numérico
int validateInput(char *input, int size) {
    for (int i=0;i<size;i++) { //for que vai percorrer o array da variável informada como parâmetro com base no tamanho passado como parametro
        // debuggng // printf("input[%d]: %c\n", i, input[i]);
        if(!isdigit(input[i]) && (input[i] != '\0')) { //if confere se existe algum caracter no array que não seja um digito enquanto não chegar no caracter nulo (fim da string)
            if (!ispunct(input[i]) && (input[i] != '\0')) { //caso exista um caractere que não seja um digito, passa pra esse if que confere se existe algum caractere que não seja um caractere de pontuação enquanto não chegar no digito nulo (usado pra pegar numeros decimais)
                printf("input invalido!\n"); //case exista qualquer caractere que não seja um digito ou um caractere de pontuação, informa natela que o input é invalido 
                varTempClean(); //chama a função que limpa a variável temporária 
                // debugging // printf("vartemp: %s\n", input);
            return INVALIDO; //retorna invalido como resultado da verificação
            }
        }
        // debugging // printf("ainda no for\n");
    }
    // debugging // printf("saiu do for\n");
    return VALIDO; //caso não exista qualquer caractere diferente de digitos e pontuações, retorna valido como resultado da verificação
}

//função de login
int login(User *usuario) {
    char tempUser[charConst]; //variável temporária pra pegar o id/login/username e fazer a comparação com a base de dados
    char tempPassword[charConst]; //variável temporária pra pegar a senha e fazer a comparação com a base de dados
    printf("\n##### ID DO USUARIO #####\n");
    scanf("%s", tempUser); //lê o id/login/username do usuário na variável temporaria
    printf("##### SENHA #####\n");
    scanf("%s", tempPassword); //lê a senha do usuário na variável temporária
    for (int i = 0; i < LimiteMaxUser; i++) { //estrutura for pra percorrer o array de usuários
        if (strcmp(tempUser, usuario[i].user) == 0) { //if comparando o id do usuário informado com a base de dados, caso encontre o usuário, procede pra checkagem de senha
            if (strcmp(tempPassword, usuario[i].password) == 0) { //compara a senha informada com a senha do usuário encontrado na base de dados, caso esteja correta, procede para retornar sucesso
                if (usuario[i].accessLevel == 2) { //checa se o usuário encontrado tem nivel de accesso de administrador ou não
                    printf("\nlogado com sucesso!\n"); //mensagem de login bem sucedido
                    return 2; //retorna 2 (login admin bem sucedido)
                }
                printf("\nlogado com sucesso!\n"); //mensagem de login bem sucedido
                return 0; //retorna 0 (login bem sucedido)
            }
        }
    }
    printf("\nusuário ou senha incorretos"); //mensagem de erro de login
    return 1; //retorna 1 (login mal sucedido)
}

//função que cadastra o primeiro usuário do sistema (admin)
int registrarAdmin(User *usuario, int *userCount) {
    printf("\n#### CADASTRAMENTO DE ADMIN ####\n");
    printf("informe o login do administrador - "); //pede pro usuário definir o id/login/username do primeiro usuário
    scanf("%s", usuario[0].user); //lê o input do usuário
    printf("informe a senha do administrador - "); //pede pro usuário definir a senha do primeiro usuário
    scanf("%s", usuario[0].password); //lê a senha definida
    usuario[0].accessLevel = 2; //garante o nivel de acesso de administrador para o primeiro usuário cadastrado automaticamente
    puts("\nadiministrador registrado com sucesso"); //printa na tela que a operação foi bem sucedida
    *userCount = *userCount + 1; //sobe o contador de usuários cadastrados (0 -> 1)
    return 0;
}

//função que cadastra um novo usuário no sistema
int registrarUsuario(User *usuario, int *userCount) {
    int tempOpcao; //varivale temporaria para escolher uma opção
    int tempCount = *userCount; //gambiarra pq usar o parametro pra definir a posição do array não estava funcionando por algum ferrenho motivo
    printf("\n#### CADASTRAMENTO DE USUÁRIO ####\n");
    printf("informe o login do novo usuário - "); //pede pro usuário definir o id/login/username do novo usuario
    scanf("%s", usuario[tempCount].user); //lê o login inserido na seção de nome da variavel de usuarios
    printf("informe a senha do novo usuário - "); //pede pro usuário definir a senha do novo usuário
    scanf("%s", usuario[tempCount].password); //lê a senha inserida pelo usuário na seção de senha da variavel de usuários
    //loop pra repetir o pedido de input até o usuário inserir uma opção valida
    do {
        printf("informe o nivel de acesso do novo usuário\n"); //pede pro usuário definir o nivel de acesso do novo usuário
        printf("1. normal\n");
        printf("2. administador");
        //verificação de input
        do {
            printf("\nEscolha uma opção: "); 
            scanf("%s", &varTemp); //lê o input em uma variável string temporaria
        } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
        tempOpcao = atoi(varTemp); //converte o input na variável string para a variavél de destino
        varTempClean(); //função que limpa a variável temporária após a mesma já ter sido utilizada 
        switch (tempOpcao) { //switch do menu de opções disponíveis
            case 1: usuario[tempCount].accessLevel = 1; tempOpcao = -1; break; //define o novo usuário com o nivel de accesso de usuário normal e redefine a variável temporária de opção pra -1
            case 2: usuario[tempCount].accessLevel = 2; tempOpcao = -1; break; //define o novo usuário com o nivel de accesso de administrador e redefine a variável temporária de opção pra -1
            default: puts("opção invalida"); break; //bota na tela que a opção escolhida é invalida
        }
    } while (tempOpcao != -1); //fecha o loop do menu quando a variável temporária de seleção e opção for -1
    puts("usuário registrado com sucesso"); //informa na tela que o cadastro do novo usuário foi bem sucedido;
    *userCount += 1; //sobe o contador de usuários cadastrados
    return 0;
}

//função que faz o print de uma nota fiscal
void impressorNotaFiscal(char nome[], int qnt, int nfCount, float valorTotal, float valorTotalFinal, int desconto) {
    time_t hora = time(NULL); //variável relacionada com a hora da emissão da nota fiscal
    printf("Venda registrada com sucesso.\n");
    printf("\n##### Comprovante Fiscal #####\n"); 
    printf("Nome do Produto:         %s\n", nome);
    printf("Quantidade Vendida:          %i\n", qnt); 
    printf("Valor:                 R$%.2f\n", valorTotal);
    printf("Valor Desconto:        R$%.2f\n", (valorTotal * desconto) / 100);
    printf("Valor Final:           R$%.2f\n", valorTotalFinal);
    printf("       Nota Fiscal n°%i        \n", nfCount); 
    printf("   %s", asctime(localtime(&hora)));
    printf("#####  Farmacia Biopark  #####\n");
}

//função que adiciona produtos
int adicionarProdutos(Produto *produtos, int idTest, int contadorProdutos) {
    float valor = 0; //variavel que pega o valor de um produto no cadastro de produtos e depois passa pra variavel do produto
    //verificação de input
    do {
        printf("\ninsira o ID do novo produto - "); //pede pro usuário inserir o id do novo produto
        scanf("%s", &varTemp); //lê o input em uma variável string temporaria
    } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
    idTest = atoi(varTemp); //converte o input na variável string para a variavél de destino
    varTempClean();//função que limpa a variável temporária após a mesma já ter sido utilizada
    for (int i=0; i<LimiteMax; i++) { //confere se a id do produto já existe
        if (produtos[i].id == idTest) { //se a id do produto já existe, ele pede a quantidade a ser adicionada a tal produto
            printf("\nErro: ID já existente");
            return 1;
        }
    }
    //for que percorre a lista de ids dos produtos a procura de um 0 (espaço de produto não utilizado)
    for (int i=0; i<=LimiteMax; i++) {
        if (produtos[i].id == 0) {
            contadorProdutos = i;
            break;
        } else {
            contadorProdutos++;
        }
    }
    if (contadorProdutos < LimiteMax) { // se a quantidade de produtos for menor que o limite, ele procede, caso contrário, informa que o estoque está cheio
        if (idTest != 0) { // se o comparador de id for diferente de 0, ele avança pro cadastro do produto
            produtos[contadorProdutos].id = idTest; // define a id do produto

            printf("\nNome do produto: ");
            scanf("%s", produtos[contadorProdutos].nome); // Vai ler o nome do produto
                          
            //verificação de input
            do {
                printf("Insira o valor do produto: R$"); //pede pro usuário defirnir o valor do novo produto
                scanf("%s", &varTemp); //lê o input em uma variável string temporaria
            } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
            valor = atof(varTemp); //converte o input na variável string para a variavél de destino
            varTempClean(); //função que limpa a variável temporária após a mesma já ter sido utilizada
                        
            produtos[contadorProdutos].valor = valor; // Armazena o valor lido na estrutura do produto
            contadorProdutos = 0; // redefine o contador de produtos para zero 
            idTest = 0; // reseta o idTest

            printf("\n#####Produto registrado com sucesso#####\n"); //informa na tela que o produto foi registrado com sucesso 
        } else {
            printf("ERRO: ID NÃO PODE SER 0");
        }
    } else {
        printf("Erro: estoque cheio!\n");
    }
    return 0;
}

//função que remove produtos cadastrados
int removerProdutos(Produto *produtos, int idTest) {
    //verificação de input
    do {
        printf("\ninsira o ID do produto - "); //pede pro usuário informar o id do produto a ser deletado
        scanf("%s", &varTemp); //lê o input em uma variável string temporaria
    } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
    idTest = atoi(varTemp); //converte o input na variável string para a variavél de destino
    varTempClean(); //função que limpa a variável temporária após a mesma já ter sido utilizada
    int selecaoRemover = 0;
    for (int i=0; i<LimiteMax; i++) {
        if (produtos[i].id == idTest) { //se a id do produto já existe, ele pede a quantidade a ser adicionada a tal produto
            selecaoRemover = i;
            idTest = 0;
            break;
        } 
    }
    if (idTest != 0) {
        printf("\nERRO: ID NÃO EXISTENTE\n");
        return 1;
    }
    printf("\n####Certeza que deseja remover %s? (não poderá ser desfeito)####\n", produtos[selecaoRemover].nome); //informa na tela o nome do produto a ser removido e o fato de ser uma mudança permanente
    printf("1. Sim\n");
    printf("0. Não\n");
    int opcaoRemover = 0;
    //verificação de input
    do { 
        do {
            printf("Escolha uma opção: "); //pede pro usuário escolher uma opção
            scanf("%s", &varTemp); //lê o input em uma variável string temporaria
        } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
        opcaoRemover = atoi(varTemp); //converte o input na variável string para a variavél de destino
        varTempClean(); //função que limpa a variável temporária após a mesma já ter sido utilizada
        switch (opcaoRemover) {
            case 1: //case 1 realiza o processo de remoção do produto
                produtos[selecaoRemover].id = 0; //redefine o id do produto escolhido pra 0 (id = 0 -> espaço de produto inutilizado)
                produtos[selecaoRemover].quantidade = 0; //redefine a quantidade do produto escolhido pra 0;
                printf("\nProduto removido com sucesso\n"); //informa na tela que o produto foi removido com sucesso
                break;
            case 0: break; //não faz nada e apenas serve como opção de retorno caso haja desistencia no meio do processo de remoção do produto
            default: printf("\nopção invalida\n"); //informa que a opção informada é invalida
        }
    } while ((opcaoRemover != 0) && (opcaoRemover != 1)); //do while repetindo o menu até uma opção valida ser selecionada
    return 0;
}

//função que atualiza a quantidade de produtos (só adiciona na verdade)
int atualizarQuantidade(Produto *produtos, int idTest) {
    //verificação de input
    do {
        printf("\ninsira o ID do produto - "); //pede pro usuário inserir o id do produto a ser adicionado 
        scanf("%s", &varTemp); //lê o input em uma variável string temporaria
    } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
    idTest = atoi(varTemp); //converte o input na variável string para a variavél de destino
    varTempClean(); //função que limpa a variável temporária após a mesma já ter sido utilizada
    for (int i=0; i<LimiteMax; i++) { //confere se a id do produto já existe
        if (produtos[i].id == idTest) { //se a id do produto já existe, ele pede a quantidade a ser adicionada a tal produto
            //lê a quantidade nova a ser adicionada
            int quantidadeAdicionada = 0;
            //verificação de input
            do { 
                printf("\nInsira a quantidade a ser adicionada - "); //pede pro usuário informar a quantidade a ser adicionada
                scanf("%s", &varTemp); //lê o input em uma variável string temporaria
            } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
            quantidadeAdicionada = atoi(varTemp); //converte o input na variável string para a variavél de destino
            varTempClean(); //função que limpa a variável temporária após a mesma já ter sido utilizada
            produtos[i].quantidade = produtos[i].quantidade + quantidadeAdicionada; //adiciona a quantidade nova a quanitdade já existente
            idTest = 0; //reseta o comparador de id para 0
            printf("\n#####Quantidade atualizada com sucesso#####\n"); //informa na tela uma mensagem de sucesso na atualização da quantidade do produto
            return 0; 
        }
    }
    if (idTest != 0) {
        printf("erro: produto inexistente"); //informa na tela uma mensagem de erro na atualização da quantidade do produto
        idTest = 0; //reseta o comparador de id para 0
    }
    return 0;
}

//função que exibe o estoque
void exibirEstoque(Produto *estoque) {
    printf("\n#### ESTOQUE ####\n");
    for (int i=0; i<LimiteMax; i++) {
        if (estoque[i].id != 0) {
            printf("%s - Id: %i Quantidade: %d Valor: R$%.2f\n", estoque[i].nome, estoque[i].id, estoque[i].quantidade, estoque[i].valor);
        }
    }
}

//Função para exibir clientes cadastrados
void exibirClientes(ClienteCPF *cliente) {
    printf("\n#### CLIENTES CADASTRADOS ####\n");
    for (int i = 0; i<LimiteMax; i++) {
        if (cliente[i].cpf != 0) {
            printf("Nome do cliente: %s CPF do cliente: %d\n", cliente[i].nome, cliente[i].cpf);
        }
    }
}

//Função para exibir empresas cadastradas
void exibirEmpresas(ClienteCNPJ *empresa) {
    printf("\n#### EMPRESAS CADASTRADAS ####\n");
    for (int i=0; i<LimiteMax; i++) {
        if (empresa[i].cnpj != 0) {
            printf("Razão Social da empresa: %s CNPJ: %d\n", empresa[i].RS, empresa[i].cnpj);
        }
    }
}

//função para exibir usuários cadastrados
void exibirUsuarios(User *usuario) {
    printf("\n#### USUÁRIOS CADASTRADOS ####\n");
    for (int i=0; i<LimiteMaxUser; i++) {
        if (strcmp(usuario[i].user, "inutilizado") != 0) {
            printf("user: %s Senha: %s Nível de acesso: %i\n", usuario[i].user, usuario[i].password, usuario[i].accessLevel);
        }
    }
}

//função que procura se um cliente tem certo cpf
int cpfFinder(ClienteCPF *cliente, int cpf) {
    for (int i=0; i<LimiteMax; i++) { // pega o cpf do cliente e compara se já existe outro cliente com o mesmo cpf
        if (cliente[i].cpf == cpf) {
            return 0; //retorna 0 caso a função encontre um cliente com o mesmo cpf informado como parâmetro
        }
    }
    return 1; //retorna 1 caso a função não encontre um cliente com o mesmo cpf informado como parâmetro
}

//função que produra se uma empresa tem certo cpf
int cnpjFinder(ClienteCNPJ *empresa, int cnpj) {
    for (int i=0; i<LimiteMax; i++) { // pega o cnpj da empresa e compara se já existe outra empresa com o mesmo cnpj
        if (empresa[i].cnpj == cnpj) { 
            return 0; //retorna 0 caso a função encontre uma empresa com o mesmo cnpj informado como parâmetro
        }
    }
    return 1; //retorna 1 caso a função não encontre uma empresa com o mesmo cpnj informado como parâmetro
}

//função que adiciona clientes
int cadastrarCPF(ClienteCPF *cliente, int *contadorClientes) {
    int cpfTest=0; //variavel usada pra conferir se existe um cliente cadastrado com tal cpf
    int contadorTempC = *contadorClientes; //variável temporária que pega o valor do contador de clientes já cadastrados para poder usar como posição do array na variável de clientes
    printf("\ninsira o nome do cliente: "); //pede pro usuário informar o nome do cliente 
    scanf("%s", &cliente[contadorTempC].nome); //guarda o nome do cliente cadastrado no elemento de nomes da variável de clientes
    //verificação de input
    do {
            printf("insira o cpf do cliente (somente numeros): "); //pede pro usuário inserir apenas os numeros do cpf do cliente
            scanf("%s", &varTemp); //lê o input em uma variável string temporaria
    } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
    cpfTest = atoi(varTemp); //converte o input na variável string para a variavél de destino
    varTempClean(); //função que limpa a variável temporária após a mesma já ter sido utilizada
    if (cpfFinder(cliente, cpfTest) == 0) { //if chama a função de procurar cpfs nos clientes cadastrados
        printf("\nErro: cpf ja cadastrado.\n"); //caso exista outro cliente com o mesmo cpf, informa na tela um erro
        return 1; //retorna 1 caso a operação de cadastro de cliente não seja bem sucedida
    } else { // caso não exista outro cliente com o mesmo cpf, informa sucesso
        cliente[contadorTempC].cpf = cpfTest; //passa o cpf da variável de comparação para o elemento de cpf da variável de clientes
        printf("\n#####Cliente cadastrado com sucesso#####\n"); //informa na tela que a operação de cadastro de cliente doi bem sucedida
        *contadorClientes += 1; // Incrementa o clientenum
    }
    return 0; //retorna 0 caso a operação de cadastro de cliente seja bem sucedida
}

//Função para adicionar CNPJ
int cadastrarCNPJ (ClienteCNPJ *empresa, int *contadorEmpresas) {
    int cnpjTest = 0; //variavel usada pra conferir se existe um cliente cnpj cadastrado
    int contadorTempE = *contadorEmpresas; //variável temporária que pega o valor de empresas já cadastradas para poder usar como posição do array na váriavel de empresas
    printf("\nInsira a Razao Social da empresa: "); //pede pro usuário informar o nome da empresa
    scanf("%s", &empresa[contadorTempE].RS); //pega o nome da empresa
    //verificação de input
    do {
        printf("\nCNPJ (somente numeros): "); //pede pro usuário informar o cnpj da empresa
        scanf("%s", &varTemp); //lê o input em uma variável string temporaria
    } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
    cnpjTest = atoi(varTemp); //converte o input na variável string para a variavél de destino
    varTempClean(); //função que limpa a variável temporária após a mesma já ter sido utilizada
    if (cnpjFinder(empresa, cnpjTest) == 0) { //if chama a função de procurar cnpjs nas empresas cadastradas
        printf("\nErro: CNPJ ja cadastrado.\n"); //caso exista outra empresa com o mesmo cnpj, informa na tela um erro
        return 1; //retorna 1 caso a operação de cadastro de empresa não seja bem sucedido
    } else { // caso não exista outra empresa com o mesmo cnpj, informa sucesso
        empresa[contadorTempE].cnpj = cnpjTest; //passa o cpnj na variável placeholder pra seção de cnpj da variável de empresas cadstradas
        printf("\nTelefone ((xx) xxxx-xxxx): "); //pede pro usuário informar o telefone da empresa
        scanf("%s", &empresa[contadorTempE].TF); //lê o telefone como string no elemento de telefone da variável de empresas cadastradas
        printf("\n#####Empresa cadastrada com sucesso#####\n"); //informa na tela que o cadastro da empresa foi bem sucedido
        *contadorEmpresas += 1; // adiciona no contador de empresas cadastradas
    }
    return 0; //retorna 0 caso a operação de cadastro de empresa seja bem sucedida
}

//função que realiza vendas
int realizarVenda(Produto *produtos, int idTest, int *notaFiscal, ClienteCPF *clientes, ClienteCNPJ *empresas) {
    int desconto = 0; //variável que vai segurar o valor da porcentagem de desconto na venda
    printf("\n#### REALIZAÇÃO DE VENDA ####\n");
    //adendo: a integração do cliente na venda ainda não foi completamente implementada//
    int tempOpcao = 0; //variável temporária de seleção de opção
    int clienteFinder = 0; //variável temporária que segura um valor para ser comparado com cpfs e cpnjs
    printf("cliente ou empresa cadastrada?\n"); //menuzinho que pede pro usuário se ele vai realizar a venda para u cliente ou empresa já cadastrada
    printf("1. Sim\n");
    printf("2. Não");
    //verificação de input
    do {
        do {
            printf("\nEscolha uma opção: "); //pede pro usuário informar o id do produto a ser vendido
            scanf("%s", &varTemp); //lê o input em uma variável string temporaria
        } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
        tempOpcao = atoi(varTemp); //converte o input na variável string para a variavél de destino
        varTempClean(); //função que limpa a variável temporária após a mesma já ter sido utilizada
        switch (tempOpcao) {
            case 1: //caso que vai definir a porcentagem de desconto na venda
                //verificação de input
                do {
                    printf("\nInsira o CPF/CNPJ: "); //pede pro usuário informar o id do produto a ser vendido
                    scanf("%s", &varTemp); //lê o input em uma variável string temporaria
                } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
                clienteFinder = atoi(varTemp); //converte o input na variável string para a variavél de destino
                varTempClean(); //função que limpa a variável temporária após a mesma já ter sido utilizada
                for (int i=0; i<LimiteMax; i++) { //for usado para percorrer os arrays de clientes e empresas
                    if (clientes[i].cpf == clienteFinder) { //if compara se o valor informado pelo usuário é igual algum cpf dos clientes cadastrados
                        desconto = 10; //se o valor informado pelo usuário for encontrado no banco de cpfs, o desconto será de 10%
                        break; //sai do for
                    } else if (empresas[i].cnpj == clienteFinder) { //if compara se o valor informado pelo usuário é igual algum cnpj das empresas cadastradas
                        desconto = 30; //se o valor informado pelo usuário for encontrado no banco de cnpjs, o desconto será de 30%
                        break; //sai do for
                    } else if (i == (LimiteMax - 1)) { //if abre o erro caso o for chege no fim limite de tamanho dos arrays sem ter encontrado nenhum cpf ou cnpj compatível
                        printf("Erro: Nenhum cliente ou empresa encontrados\n"); //informa na tela um erro falando que nenhum cpf ou cnpj igual o inserido pelo usuário foi encontrado nos dados
                        return 1; //encerra a venda como uma execução mal sucedida
                    }
                }
                tempOpcao = 2; //define a variável temporária de seleção de opção para 2 para fechar o do while
                break; //fecha do switch
            case 2: break; //fecha o switch
            default: printf("Opção inválida\n"); //informa na tela que a opção escolhida não é valida
        }
    } while (tempOpcao != 2); //vai repetir esse menu de seleção do modo da venda até o usuário informar uma opção correta
    //verificação de input
    do {
        printf("\nID do produto: "); //pede pro usuário informar o id do produto a ser vendido
        scanf("%s", &varTemp); //lê o input em uma variável string temporaria
    } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
    idTest = atoi(varTemp); //converte o input na variável string para a variavél de destino
    varTempClean(); //função que limpa a variável temporária após a mesma já ter sido utilizada
    for (int i=0; i<LimiteMax; i++) { //confere se a id do produto existe
        if (produtos[i].id == idTest) { //se a id do produto existe, ele pede a quantidade a ser vendida
            int quantidadeVenda; //variavel responsavel pela quantidade vendida
            //verificação de input
            do {
                printf("Quantidade: "); //pede pro usuário informar a quantidade do produto a ser vendida
                scanf("%s", &varTemp); //lê o input em uma variável string temporaria
            } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
            quantidadeVenda = atoi(varTemp); //converte o input na variável string para a variavél de destino
            varTempClean(); //função que limpa a variável temporária após a mesma já ter sido utilizada
            if (produtos[i].quantidade >= quantidadeVenda) {//[i] usando para acessar elemento da array, confere se a quantidade de estoque do produto é maior ou igual a quantidade de venda
                produtos[i].quantidade -= quantidadeVenda; // Diminue a quantidade do produto no estoque
                *notaFiscal += 1; //sobe o contador de notas fiscais emitidas
                float valorTotal; //variavel que vai conter o valor total da venda de um produto antes do desconto
                float valorTotalFinal; //variável que vai conter o valor total da venda de um produto após o desconto 
                valorTotal = produtos[i].valor * quantidadeVenda; //calcula o valor total da venda
                valorTotalFinal = valorTotal - ((valorTotal * desconto) / 100); //aplica o desconto no valor total da venda
                impressorNotaFiscal(produtos[i].nome, quantidadeVenda, *notaFiscal, valorTotal, valorTotalFinal, desconto); //chama a função que escreve a nota fiscal;
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
        printf("Erro: Produto Inexistente.\n"); //informa na tela um erro
        return 1;
    }
    return 0;
}

//função do menu (administrador)
void menuAdmin(User *usuario, int *userCount, Produto *produtos, int contadorProdutos, int idTest, int *NF, ClienteCPF *clientes, int *contadorClientes, ClienteCNPJ *empresas, int *contadorEmpresas) {
    int opcao; //variavél que segura o valor referente a uma opção do menu
    int subOpcao; //variável que segura o valor referente a uma opção dos submenus
    do { //do while do menu principal
        printf("\n##### MENU #####\n");
        printf("1. Gerenciar estoque\n");
        printf("2. Gerenciar clientes\n");
        printf("3. Realizar venda\n");
        printf("0. Sair\n");
        //verificação de input
        do {
            printf("Escolha uma opcao: "); //pede pro usuário digitar uma opção
            scanf("%s", &varTemp); //lê o input em uma variável string temporaria
        } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
        opcao = atoi(varTemp); //converte o input na variável string para a variavél de destino
        varTempClean(); //função que limpa a variável temporária após a mesma já ter sido utilizada
        switch (opcao) {
            case 1: //abre o submenu relacionado a produtos
                do {
                    printf("\n##### MENU - ESTOQUE #####\n"); 
                    printf("1. Adicionar produto\n");
                    printf("2. Remover produto\n");
                    printf("3. Atualizar quantidade\n");
                    printf("4. Mostrar estoque\n");
                    printf("5. Gerar relatótio\n");
                    printf("0. Voltar\n");
                    //verificação de input
                    do {
                        printf("Escolha uma opcao: "); //pede pro usuário digitar uma opção
                        scanf("%s", &varTemp); //lê o input em uma variável string temporaria
                    } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
                    subOpcao = atoi(varTemp); //converte o input na variável string para a variavél de destino
                    varTempClean(); //função que limpa a variável temporária após a mesma já ter sido utilizada
                    switch (subOpcao) {
                        case 1: adicionarProdutos(produtos, idTest, contadorProdutos); break; //chama a função que adiciona produtos novos
                        case 2: removerProdutos(produtos, idTest); break; //chama a função que remove produtos já cadastrados
                        case 3: atualizarQuantidade(produtos, idTest); break; //chama a função que atualiza a quantidade de produtos já adicionados
                        case 4: exibirEstoque(produtos); break; //chama a função que exibe o estoque de produtos cadastrados
                        case 5: printf("\nAinda não implementado\n"); break; //adendo: falta fazer ainda
                        case 0: break; //faz o break do switch e volta pro menu principal
                        default: printf("Opcao invalida!\n"); //informa na tela que a opção escolhida é invalida
                    }
                } while (subOpcao != 0); //repete o submenu enquanto a variável do submenu não for zero
                break; // sai do switch do menu principal
            case 2: //abre o submenu relacionado a clientes                    
                do {
                    printf("\n##### MENU - PESSOAS #####\n"); 
                    printf("1. Cadastrar pessoa física\n");
                    printf("2. Cadastrar pessoa juridíca\n");
                    printf("3. Mostrar lista de cadastros\n");
                    printf("4. Cadastrar novo usuário\n");
                    printf("0. Voltar\n");
                    //verificação de input
                    do {
                        printf("Escolha uma opcao: ");
                        scanf("%s", &varTemp); //lê o input em uma variável string temporaria
                    } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
                    subOpcao = atoi(varTemp); //converte o input na variável string para a variavél de destino
                    varTempClean(); //função que limpa a variável temporária após a mesma já ter sido utilizada
                    switch (subOpcao) {
                        case 1: cadastrarCPF(clientes, contadorClientes); break; //chama a função que faz o cadastro de um cliente
                        case 2: cadastrarCNPJ(empresas, contadorEmpresas); break; //chama a função qur faz o cadastro de uma empresa
                        case 3: do { //abre um subsubmenu relacionado a exibição dos cadastros de pessoas, empresas e usuários
                                    printf("\n##### MOSTRAR LISTA DE CADASTROS #####\n"); 
                                    printf("1. Mostrar clientes\n");
                                    printf("2. Mostrar empresas\n");
                                    printf("3. Mostrar usuários\n");
                                    printf("0. Voltar\n");
                                    //verificação de input
                                    do {
                                        printf("Escolha uma opcao: "); //pede pro usuário digitar uma opção
                                        scanf("%s", &varTemp); //lê o input em uma variável string temporaria
                                    } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
                                    subOpcao = atoi(varTemp); //converte o input na variável string para a variavél de destino
                                    switch (subOpcao) {
                                        case 1: exibirClientes(clientes); break; //chama a função que mostra os clientes cadastrados
                                        case 2: exibirEmpresas(empresas); break; //chama a função que mostra as empresas cadastradas
                                        case 3: exibirUsuarios(usuario); break; //chama a função que mostra os usuários cadastrados
                                        case 0: break; //faz o break do switch do subsubmenu
                                        default: printf("Opcao invalida!\n"); //infoma na tela que a opção escolhida é invalida
                                    }
                                } while (subOpcao != 0); //do while do subsubmenu vai repetir o mesmo enquanto a variável do submenu não for 0
                                subOpcao = 1; //redefine a variável do submenu pra 1 pra voltar no submenu e não fechar o mesmo direto
                                break; //sai do switch do submenu
                        case 4: registrarUsuario(usuario, userCount); break; //chama a função que cadastra novos usuários no sistema (exclusivo admin)
                        case 0: break; //sai do switch do submenu
                        default: printf("Opcao invalida!\n"); //informa na tela que a opção escolhida é invalida
                    }
                } while (subOpcao != 0); //do while do submenu repete o mesmo enquanto a variável do submenu for diferente de 0
                break; //sai do switch do menu principal
            case 3: //chama a função de venda 
                realizarVenda(produtos, idTest, NF, clientes, empresas);    
                break; //sai do switch do menu principal
            case 0: //abre o submenu com as opções para sair/fechar o sistema
                do {
                    printf("\n##### SAIR #####\n");
                    printf("1. Trocar usuário\n");
                    printf("2. Fechar o programa\n");
                    printf("0. Voltar\n");
                    //verificação de input
                    do {
                        printf("Escolha uma opcao: ");
                        scanf("%s", &varTemp); //lê o input em uma variável string temporaria
                    } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
                    subOpcao = atoi(varTemp); //converte o input na variável string para a variavél de destino
                    varTempClean(); //função que limpa a variável temporária após a mesma já ter sido utilizada
                    switch (subOpcao) {
                        case 1: printf("Saindo...\n"); break; //informa na tela que esta saindo do usuário logado e fecha os menus
                        case 2: printf("Fechando...\n"); isRunning = 1; break; //informa na tela que o programa está fechando e fecha os menus
                        case 0: opcao = 1; break; //define a variável de opção do menu como 1 para retornar e não fechar o menu principal e fecha o submenu
                        default: printf("Opção invalida!\n"); //informa na tela que a opção informada é invalida
                    }
                } while ((subOpcao != 1) && (subOpcao != 2) && (subOpcao != 0)); //do while do submenu repete enquanto a variável do submenu não for 1, 2 ou 0
                break; //sai do switch do menu principal
            default:
                printf("Opcao invalida!\n"); //informa na tela que a opção informada é invalida
        }
    } while (opcao != 0); //do while repete o menu enquanto a variável de opção do menu não for igual a zero
}

//função do menu (padrão)
void menuDefault(Produto *produtos, int contadorProdutos, int idTest, int *NF, ClienteCPF *clientes, int *contadorClientes, ClienteCNPJ *empresas, int *contadorEmpresas) {
    int opcao; //variavél que segura o valor referente a uma opção do menu
    int subOpcao; //variável que segura o valor referente a uma opção dos submenus
    do { //do while do menu principal
        printf("\n##### MENU #####\n");
        printf("1. Gerenciar estoque\n");
        printf("2. Gerenciar clientes\n");
        printf("3. Realizar venda\n");
        printf("0. Sair\n");
        //verificação de input
        do {
            printf("Escolha uma opcao: "); //pede pro usuário digitar uma opção
            scanf("%s", &varTemp); //lê o input em uma variável string temporaria
        } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
        opcao = atoi(varTemp); //converte o input na variável string para a variavél de destino
        varTempClean(); //função que limpa a variável temporária após a mesma já ter sido utilizada
        switch (opcao) {
            case 1: //abre o submenu relacionado a produtos
                do {
                    printf("\n##### MENU - ESTOQUE #####\n"); 
                    printf("1. Adicionar produto\n");
                    printf("2. Remover produto\n");
                    printf("3. Atualizar quantidade\n");
                    printf("4. Mostrar estoque\n");
                    printf("0. Voltar\n");
                    //verificação de input
                    do {
                        printf("Escolha uma opcao: "); //pede pro usuário digitar uma opção
                        scanf("%s", &varTemp); //lê o input em uma variável string temporaria
                    } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
                    subOpcao = atoi(varTemp); //converte o input na variável string para a variavél de destino
                    varTempClean(); //função que limpa a variável temporária após a mesma já ter sido utilizada
                    switch (subOpcao) {
                        case 1: adicionarProdutos(produtos, idTest, contadorProdutos); break; //chama a função que adiciona produtos novos
                        case 2: removerProdutos(produtos, idTest); break; //chama a função que remove produtos já cadastrados
                        case 3: atualizarQuantidade(produtos, idTest); break; //chama a função que atualiza a quantidade de produtos já adicionados
                        case 4: exibirEstoque(produtos); break; //chama a função que exibe o estoque de produtos cadastrados
                        case 0: break; //faz o break do switch e volta pro menu principal
                        default: printf("Opcao invalida!\n"); //informa na tela que a opção escolhida é invalida
                    }
                } while (subOpcao != 0); //repete o submenu enquanto a variável do submenu não for zero
                break; // sai do switch do menu principal
            case 2: //abre o submenu relacionado a clientes                    
                do {
                    printf("\n##### MENU - PESSOAS #####\n"); 
                    printf("1. Cadastrar pessoa física\n");
                    printf("2. Cadastrar pessoa juridíca\n");
                    printf("3. Mostrar lista de cadastros\n");
                    printf("0. Voltar\n");
                    //verificação de input
                    do {
                        printf("Escolha uma opcao: ");
                        scanf("%s", &varTemp); //lê o input em uma variável string temporaria
                    } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
                    subOpcao = atoi(varTemp); //converte o input na variável string para a variavél de destino
                    varTempClean(); //função que limpa a variável temporária após a mesma já ter sido utilizada
                    switch (subOpcao) {
                        case 1: cadastrarCPF(clientes, contadorClientes); break; //chama a função que faz o cadastro de um cliente
                        case 2: cadastrarCNPJ(empresas, contadorEmpresas); break; //chama a função qur faz o cadastro de uma empresa
                        case 3: do { //abre um subsubmenu relacionado a exibição dos cadastros de pessoas, empresas e usuários
                                    printf("\n##### MOSTRAR LISTA DE CADASTROS #####\n"); 
                                    printf("1. Mostrar pessoas físicas\n");
                                    printf("2. Mostrar pessoas juridícas\n");
                                    printf("0. Voltar\n");
                                    //verificação de input
                                    do {
                                        printf("Escolha uma opcao: "); //pede pro usuário digitar uma opção
                                        scanf("%s", &varTemp); //lê o input em uma variável string temporaria
                                    } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
                                    subOpcao = atoi(varTemp); //converte o input na variável string para a variavél de destino
                                    switch (subOpcao) {
                                        case 1: exibirClientes(clientes); break; //chama a função que mostra os clientes cadastrados
                                        case 2: exibirEmpresas(empresas); break; //chama a função que mostra as empresas cadastradas
                                        case 0: break; //faz o break do switch do subsubmenu
                                        default: printf("Opcao invalida!\n"); //infoma na tela que a opção escolhida é invalida
                                    }
                                } while (subOpcao != 0); //do while do subsubmenu vai repetir o mesmo enquanto a variável do submenu não for 0
                                subOpcao = 1; //redefine a variável do submenu pra 1 pra voltar no submenu e não fechar o mesmo direto
                                break; //sai do switch do submenu
                        case 0: break; //sai do switch do submenu
                        default: printf("Opcao invalida!\n"); //informa na tela que a opção escolhida é invalida
                    }
                } while (subOpcao != 0); //do while do submenu repete o mesmo enquanto a variável do submenu for diferente de 0
                break; //sai do switch do menu principal
            case 3: //chama a função de venda 
                realizarVenda(produtos, idTest, NF, clientes, empresas);    
                break; //sai do switch do menu principal
            case 0: //abre o submenu com as opções para sair/fechar o sistema
                do {
                    printf("\n##### SAIR #####\n");
                    printf("1. Trocar usuário\n");
                    printf("2. Fechar o programa\n");
                    printf("0. Voltar\n");
                    //verificação de input
                    do {
                        printf("Escolha uma opcao: ");
                        scanf("%s", &varTemp); //lê o input em uma variável string temporaria
                    } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
                    subOpcao = atoi(varTemp); //converte o input na variável string para a variavél de destino
                    varTempClean(); //função que limpa a variável temporária após a mesma já ter sido utilizada
                    switch (subOpcao) {
                        case 1: printf("Saindo...\n"); break; //informa na tela que esta saindo do usuário logado e fecha os menus
                        case 2: printf("Fechando...\n"); isRunning = 1; break; //informa na tela que o programa está fechando e fecha os menus
                        case 0: opcao = 1; break; //define a variável de opção do menu como 1 para retornar e não fechar o menu principal e fecha o submenu
                        default: printf("Opção invalida!\n"); //informa na tela que a opção informada é invalida
                    }
                } while ((subOpcao != 1) && (subOpcao != 2) && (subOpcao != 0)); //do while do submenu repete enquanto a variável do submenu não for 1, 2 ou 0
                break; //sai do switch do menu principal
            default:
                printf("Opcao invalida!\n"); //informa na tela que a opção informada é invalida
        }
    } while (opcao != 0); //do while repete o menu enquanto a variável de opção do menu não for igual a zero
}

//função que pede se o usuário quer fechar o programa ou tentar o login novamente
int retry() {
    int retry = 0; //variável que serve para selecionar uma opção do menu de tentar novamente
    do { //abre um menuzinho de opções relacionadas a repetir o login
        printf("\ntentar novamente?\n");
        printf("1. sim\n");
        printf("2. não\n");
        //verificação de input
        do { 
            printf("Escolha uma opcao: "); //pede pro usuário informar uma opção
            scanf("%s", &varTemp); //lê o input em uma variável string temporaria
        } while (validateInput(varTemp, charConst) == INVALIDO); //repete o do while caso a função de validação retorne invalido
        retry = atoi(varTemp); //converte o input na variável string para a variavél de destino
        varTempClean(); //função que limpa a variável temporária após a mesma já ter sido utilizada
        switch (retry) {
            case 1: break; //fehca o switch e encerra a função sem mudar o valor da variável que determina se o programa deve rodar de novo
            case 2: isRunning = 1; break; //muda o valor da variável que determina se o programa deve rodar de novo, sai do switch e encerra a função
            default: printf("opção invalida!\n"); //informa na tela que a opção escolhida é invalida
                     retry = 0; //redefine o valor da variável de tentar novamente para 0 fazendo o do while repetir
        } 
    } while (retry == 0); //do while do menuzinho de tentar novamnete repete caso a variável de tentar novamente seja igual a 0
    return 0;
}

//função que aceita uma estrutura de usuário e uma string "nome" e verifica se existe uma string identica ao "nome" na estrutura de usuário
int comparacaoUsuarios(User *usuario, char *comparativo) {
    for (int i; i < LimiteMaxUser; i++) {
        if (strcmp(usuario[i].user, comparativo) == 1) {
            return 1;
        }
    }
    return 0;
}

//função que mostra a versão da build do programa e sua data
void disclaimer() {
    printf("########## ESTOQUE 4.0 ##########\n");
    printf("  build: %s\n", buildVersion);
    printf("  date: %s\n", buildDate);
    printf("  Todos os direitos reservados.\n");
    printf("#################################\n");
}

//função que limpa tudo de todas as variáveis que armazenam os bagulhonsons
int limpadorGeral(User *usuarios, Produto *produtos, ClienteCPF *clientes, ClienteCNPJ *empresas) {
    for (int g=0; g<LimiteMaxUser; g++) {
        strcpy(usuarios[g].user, "inutilizado");
        strcpy(usuarios[g].password, "inutilizado");
        usuarios[g].accessLevel = 0;
    }
    for (int i=0; i<LimiteMax; i++) { 
        strcpy(produtos[i].nome, "inutilizado");
        produtos[i].id = 0;
        produtos[i].quantidade = 0;
        produtos[i].valor = 0;
        strcpy(clientes[i].nome, "inutilizado");
        clientes[i].cpf = 0;
        strcpy(empresas[i].RS, "inutilizado");
        empresas[i].cnpj = 0;
        strcpy(empresas[i].TF, "inutilizado");
    }
    return 0;
}

int main() {

    //funções à serem aplicadas quando o programa abre
    ANBT; //define o console pra aceitar acentos e outros bagulhonsons
    disclaimer(); //bota na tela um disclaimer com a versão do estoque, a versão da build e sua data

    //definição de variáveis relacionadas ao login
    int userCount = 0; //variavel que conta quantos usuários cadstrados existem
    User usuario[LimiteMaxUser]; //variavel array que contém os usuários registrados no sistema
    
    //definição de variaveis relacionadas ao estoque
    Produto estoque[LimiteMax]; // Variavel array que é utilizada para guardar valores
    int produtonum = 0; //variavel utilizada para contar o numero de produtos já cadastrados
    int idTest = 0; //variavel utilizada para pegar o id inserido pelo usuário e comparar com a lista de ids dos produtos
    int NF = 0; // Numeros de produtos do estoque

    //definição de variaveis relacionadas aos clientes
    ClienteCPF clientesPessoas[LimiteMax]; //Variavel array que é utilizada para guardar informações de clientes tipo pessoa física
    int clientenum = 0; //contador de clientes cadastardos

    //definição de variavéis relacionadas as empresas
    ClienteCNPJ clientesEmpresas[LimiteMax]; //Variavel array que é utilizada para guardar informações de clientes tipo pessoa juridica
    int empresanum = 0; //contador de clientes cnpj cadastardos

    //chama a função que confere se o programa já foi aberto alguma outra vez
    getTimesRunnedValue();
  
    if (timesRunned == 0) {
        limpadorGeral(usuario, estoque, clientesPessoas, clientesEmpresas);
        if (comparacaoUsuarios(usuario, "") == 0) {
            printf("\nNenhum usuário registrado, favor registrar um usuário\n");
            registrarAdmin(usuario, &userCount);
        }
    } else {
        getUsersValues(usuario);
        getCountsValues(&userCount, &produtonum, &clientenum, &empresanum);
        getNotaFiscalValue(&NF);
        getEstoqueValues(estoque);
        getClientesValues(clientesPessoas);
        getEmpresasValues(clientesEmpresas);
    }
    
    do {
        int logon = login(usuario);
        switch (logon) {
            case 0: menuDefault(estoque, produtonum, idTest, &NF, clientesPessoas, &clientenum, clientesEmpresas, &empresanum); break;
            case 2: menuAdmin(usuario, &userCount, estoque, produtonum, idTest, &NF, clientesPessoas, &clientenum, clientesEmpresas, &empresanum); break; 
            default: retry();
        }
    } while (isRunning == 0);

    //salvamento dos valores das variáveis em arquivos
    timesRunned++;
    saveTimesRunnedValue();
    saveUsersValues(usuario);
    saveCountsValues(userCount, produtonum, clientenum, empresanum);
    saveNotaFiscalValue(NF);
    saveEstoqueValues(estoque);
    saveClientesValues(clientesPessoas);
    saveEmpresasValues(clientesEmpresas);
    return 0;
}

//ideias//
//adicionar cadastro de fornecedores
//não limitar a venda ao cliente cadastrado, separar opções
//adicionar valor ao cliente cadastrado
