#include <stdio.h>// biblioteca da comunicaçao pelo usuario 
#include <stdlib.h> // biblioteca de alteraçao de espaço em memoria 
#include <locale.h> // biblioteca de texto por regiao 
#include <string.h> // biblioteca responsavel por cuidar das strings 
int registro() // função responsavel por cadastradar os usuarios 
{
  // inicio criaçao variavel/strings
  char arquivo[40];
  char cpf[40];
  char nome[40];
  char sobrenome[40];
  char cargo[40];
  // final da criaçao de string e variavel
  printf ("digite o cpf a ser cadastrado:"); // coletando informaçoes do usuario 
scanf ("%s", cpf); // %s refere-se a string
strcpy(arquivo, cpf); // responsavel por copiar os valores das strings 
  FILE *file; // cria arquivo
  file= fopen (arquivo, "w"); // cria arquivo e o w significa escrever 
  fprintf(file, cpf); // salva o valor da variavel 
  fclose(file); // fecha o arquivo 
  
  file = fopen (arquivo, "a");
  fprintf (file, ",");
  fclose (file);
  
  printf ("digite o nome a ser cadastrado:");
 scanf ("%s", nome);
 
 file = fopen(arquivo, "a");
 fprintf (file, nome);
 fclose (file);
 
 file = fopen (arquivo,"a");
 fprintf (file, ",");
 fclose (file);
 
 printf ("digite o sobrenome a ser cadastrado:");
 scanf ("%s" , sobrenome);
 
 file =fopen (arquivo, "a");
 fprintf (file, sobrenome);
 fclose (file);
 
 printf ("digite o cargo a ser cadastrado: ");
 scanf ("%s" , cargo);
 
 file = fopen (arquivo, "a");
 fprintf (file, cargo);
 fclose (file);
 
 system ("pause");
 
}
int consulta()
{
 char cpf [40];
 char conteudo [200];
  printf ("digite o cpf a ser consultado: ");
  scanf ("%s" , cpf);
  
  FILE *file; 
  file = fopen (cpf, "r");
  if (file == NULL)
  {
printf ( "Nao foi possivel abrir o arquivo, nao localizado. \n");
  }
  while(fgets(conteudo, 200, file) != NULL)
{
	printf("\nEssas sao as informaçoes do usuario: ");
	printf("%s", conteudo);
	printf("\n\n");
}
  	
system ("pause");
  
}

int deletar()
{
   char cpf[40];
   printf ("digite o cpf a ser cancelado: ");
   scanf ("%s, cpf");
   
   remove (cpf);
   FILE *file;
   file = fopen (cpf, "r");
   if (file == NULL);
   {
     printf ("O usuario nao se encontra no sistema! .\n");
     system ("pause");
   }
}

int main ()
       {
           int opcao=0; // Definindo Variaveis 
           int laco=1;
           
           for (laco=1; laco=1;)
{
           setlocale(LC_ALL, "PORTUGUESE"); // definindo linguagem 
           
           printf("### cartório da EBAC ###\n\n"); // inicio menu
           printf("escolha a opção desejada do menu:\n\n");
           printf("\t1 - Registrar nomes \n");
           printf("\t2 - Consultar nomes \n");
           printf("\t3 - Deletar nomes \n\n\n"); 
           printf("opcao: "); // fim menu
           
           scanf ("%d", &opcao); // armazanando a escolha de usuario
           
           system ("clear");
           
           switch (opcao)
           {
               case 1:
              registro(); // chamada de funçao 
               break;
               
               case 2: 
              consulta();
               break;
              deletar();
               case 3: 
               
               break;
               
               default:
               
               printf ("essa opção nao esta disponivel\n");
               system ("pause");
               break;
           } // fim da seleçao 
           
           
  }           
           
       }
       
