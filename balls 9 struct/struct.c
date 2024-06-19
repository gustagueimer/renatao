#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Defiine o máximo de produtos/clientes que pode ser cadastrados
#define charConst 64 //define a constante do maximo de caracteres por string
#define LimiteMaxUser 10 //define a constante que representa o limite maximo de usuarios
#define ANBT UINT CPAGE_UTF8 = 65001; \
             SetConsoleOutputCP(CPAGE_UTF8); 

// Estrutura que representa uma pessoa
typedef struct {
    char nome[charConst]; //elemento que representa a razão social da empresa 
    char telefone[charConst]; //elemento que representa o telefone da empresa
    char endereco[charConst]; //elemento que representa o cnpj da empresa
} pessoa;

//função que adiciona pessoas
int cadastrarPessoas(pessoa *pessoas) {
    for (int i=0;i<LimiteMaxUser;i++) {
        printf("\ninsira o nome da pessoa: ");
        fgets(pessoas[i].nome, charConst, stdin); //pega o nome do cliente
        printf("insira o telefone ((xx) xxxx-xxxx) - ");
        fgets(pessoas[i].telefone, charConst, stdin);
        printf("insira o endereço - ");
        fgets(pessoas[i].endereco, charConst, stdin);
        printf("pessoa cadastrada com sussexo\n");
    }
    return 0;
}

//função que procura a pessoa com base no nome inserido pelo usuário
int findPessoaByName(pessoa *pessoas) {
    char buffer[charConst];
    printf("insira o nome da pessoa\n");
    fgets(buffer, charConst, stdin);
    for (int i=0;i<LimiteMaxUser;i++) {
        if (strcmp(buffer, pessoas[i].nome) == 0) {
            printf("pessoa encontrada!\n\n");
            printf("nome: %stelefone: %sendereço: %s\n", pessoas[i].nome, pessoas[i].telefone, pessoas[i].endereco);
            return 0;
        } else {
            printf("pesquisando...\n");
        }
    }
    printf("pessoa não encontrada na base de dados.\n\n");
    return 1;
}

//função que mostra toda a base de dados
int showAll(pessoa *pessoas) {
    printf("Lista de contatos salvos:\n");
    for (int i=0;i<LimiteMaxUser;i++) {
        printf("%i - nome: %stelefone: %sendereço: %s\n", i+1, pessoas[i].nome, pessoas[i].telefone, pessoas[i].endereco);
    }
    return 0;
}

//função main 
int main() {
    ANBT;
    pessoa pessoas[LimiteMaxUser];
    cadastrarPessoas(pessoas);
    for (int i=0;i<LimiteMaxUser;i++) {
        findPessoaByName(pessoas);
    }
    showAll(pessoas);
    system("pause");
    return 0;
}
