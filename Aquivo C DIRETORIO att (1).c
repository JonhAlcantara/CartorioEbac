#include <stdio.h>   // biblioteca da comunicação com o usuário
#include <stdlib.h>  // biblioteca de alteração de espaço em memória
#include <locale.h>  // biblioteca de texto por região
#include <string.h>  // biblioteca responsável por cuidar das strings

int registro() // função responsável por cadastrar os usuários
{
    // início criação de variáveis/strings
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // fim da criação de strings e variáveis

    printf("Digite o CPF a ser cadastrado: "); // coletando informações do usuário
    scanf("%s", cpf); // %s refere-se a string
    strcpy(arquivo, cpf); // responsável por copiar os valores das strings

    FILE *file; // cria ponteiro para arquivo
    file = fopen(arquivo, "w"); // cria arquivo com nome igual ao CPF e abre no modo escrita
    fprintf(file, cpf); // salva o valor da variável
    fclose(file); // fecha o arquivo

    file = fopen(arquivo, "a"); // abre arquivo para adicionar conteúdo ao final
    fprintf(file, ","); // adiciona uma vírgula
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome); // coleta o nome

    file = fopen(arquivo, "a"); // abre novamente para adicionar o nome
    fprintf(file, nome); // escreve o nome no arquivo
    fclose(file);

    file = fopen(arquivo, "a"); // abre novamente
    fprintf(file, ","); // adiciona mais uma vírgula
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome); // coleta o sobrenome

    file = fopen(arquivo, "a"); // abre o arquivo
    fprintf(file, sobrenome); // escreve o sobrenome
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo); // coleta o cargo

    file = fopen(arquivo, "a"); // abre o arquivo
    fprintf(file, cargo); // escreve o cargo
    fclose(file); // fecha o arquivo

    system("pause"); // pausa o sistema
    return 0; // finaliza a função
}

int consulta() // função responsável por consultar dados cadastrados
{
    char cpf[40]; // variável para CPF
    char conteudo[200]; // conteúdo do arquivo

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf); // coleta o CPF

    FILE *file;
    file = fopen(cpf, "r"); // tenta abrir o arquivo com o nome do CPF

    if (file == NULL) // se não encontrar o arquivo
    {
        printf("Não foi possível abrir o arquivo, não localizado.\n");
    }
    else
    {
        while (fgets(conteudo, 200, file) != NULL) // lê linha por linha do arquivo
        {
            printf("\nEssas são as informações do usuário: ");
            printf("%s", conteudo); // imprime o conteúdo
            printf("\n\n");
        }
        fclose(file); // fecha o arquivo
    }

    system("pause"); // pausa o sistema
    return 0; // finaliza a função
}

int deletar() // função responsável por deletar cadastro
{
    char cpf[40]; // variável para CPF
    printf("Digite o CPF a ser cancelado: ");
    scanf("%s", cpf); // coleta o CPF

    remove(cpf); // remove o arquivo com o nome igual ao CPF

    FILE *file;
    file = fopen(cpf, "r"); // tenta reabrir para confirmar se foi deletado
    if (file == NULL) // se não encontrar o arquivo
    {
        printf("O usuário não se encontra no sistema!\n");
    }
    else
    {
        fclose(file); // fecha o arquivo caso ainda exista
    }

    system("pause"); // pausa o sistema
    return 0; // finaliza a função
}

int main() // função principal do programa
{
    int opcao = 0; // definindo variáveis
    int laco = 1;
    char senhadigitada[20]; // senha digitada pelo usuário
    int comparacao; // resultado da comparação entre senha e valor esperado

    printf("### Cartório da EBAC ###\n\n"); // título
    printf("Login de administrador!\n\nDigite a sua senha: ");
    scanf("%s", senhadigitada); // entrada da senha

    comparacao = strcmp(senhadigitada, "admin"); // compara senha digitada com "admin"

    if (comparacao == 0) // se senha estiver correta
    {
        system("cls"); // limpa tela

        for (laco = 1; laco = 1;) // laço infinito (estrutura proposital)
        {
            setlocale(LC_ALL, "PORTUGUESE"); // definindo linguagem para português

            printf("### Cartório da EBAC ###\n\n"); // início menu
            printf("Escolha a opção desejada do menu:\n\n");
            printf("\t1 - Registrar nomes\n");
            printf("\t2 - Consultar nomes\n");
            printf("\t3 - Deletar nomes\n");
            printf("\t4 - Sair\n\n");
            printf("Opção: "); // fim do menu

            scanf("%d", &opcao); // armazena a escolha do usuário

            system("clear"); // limpa a tela (em sistemas Unix)

            switch (opcao) // verifica a opção escolhida
            {
                case 1:
                    registro(); // chama a função de registro
                    break;

                case 2:
                    consulta(); // chama a função de consulta
                    break;

                case 3:
                    deletar(); // chama a função de deletar
                    break;

                case 4:
                    printf("Obrigado por visualizar o sistema!\n"); // mensagem de despedida
                    return 0; // encerra o programa
                    break;

                default: // se o usuário digitar algo inválido
                    printf("Essa opção não está disponível\n");
                    system("pause"); // pausa o sistema
                    break;
            }
        }
    }

    return 0; // final geral do programa
}