#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* estrutura de um contato*/
struct contato {
  char nome[256];
  char telefone[20];
  char email[256];
  struct contato* next;
}; typedef struct contato contato;

void adiciona_contato(contato** head, contato info){
  /*
  Input:
    um ponteiro para o ponteiro cabeça (para podermos mudar o ponteiro em si)
    um ponteiro para o nome (já que é um array)
  Output:um ponteiro para o contato.
  */
  contato* pessoa = malloc(sizeof(contato)); //criamos um contato, cujo o ponteiro é pessoa
  strcpy(pessoa->nome, info.nome); //copiamos as informações de info para pessoa 
  strcpy(pessoa->telefone, info.telefone);
  strcpy(pessoa->email, info.email);

  pessoa->next = NULL; //próximo contato é Nulo

  if (*head==NULL){ //se não existem contatos
    *head = pessoa; //então head aponta para o primeiro contato
  } else {
    contato* temp = *head;
    while(temp->next!=NULL){
      temp=temp->next;
    }
    temp->next = pessoa;
  }
}

void edita_contato(contato** head){
	contato info;
	
  if (*head==NULL){ /*se não existem contatos*/
    printf("Não há nenhum contato adicionado\n");
  } else {
		int i;
		printf("Selecione o contato você gostaria de alterar de acordo com o número associado a ele.");
		scanf("\n%d", &i); /*lê o índice que o usuário quer editar*/
    contato *temp = *head; //cria um ponteiro temporário que eh iniciado em head
    while(i!= 1){ 
      temp = temp->next;
      i--;
    }
    printf("Digite o nome do contato:\n");
  	fgetc(stdin);
  	fgets(info.nome, sizeof(info.nome), stdin);
  	// fgets retorna a entrada com quebra de linha no final, a expressão abaixo corrige isso encontrando a posição de \n e definindo como \0
  	info.nome[strcspn(info.nome, "\n")] = '\0';

  	printf("Digite o telefone do contato: ");
  	fgets(info.telefone, sizeof(info.telefone), stdin);
  	info.telefone[strcspn(info.telefone, "\n")] = '\0';

  	printf("Digite o email do contato: ");
  	fgets(info.email, sizeof(info.email), stdin);
  	info.email[strcspn(info.email, "\n")] = '\0';
		
  	strcpy(temp->nome, info.nome); //copiamos as informações de info para pessoa
  	strcpy(temp->telefone, info.telefone);
  	strcpy(temp->email, info.email);
		
  }

} 

void deleta_contato(contato** head){
  if (*head==NULL){ /*se não existem contatos*/
    printf("Não há nenhum contato adicionado\n");
  } 
  else 
  {
    int i;
    printf("qual contato você gostaria de deletar?\n");
    scanf("%d", &i); /*leia o índice que o usuário quer deletar*/
    contato* temp = *head; /*cria um ponteiro temporário*/
    if (i == 1)
    { /*se o usuário quiser deletar o primerio contato*/
      *head = temp->next; /*o head aponta para o segundo elemento*/
      free(temp); /*liberamos a memória alocada ao primeiro elemento*/
    } 
    else 
    {
      while(i!=2)
      {
        temp = temp->next;
        i--;
      }
      contato* copia = temp->next;
      free(temp->next);
      temp->next = copia->next;
    }
  }
}

void pesquisa_contato(contato** head){
  
  if (*head==NULL){ /*se não existem contatos*/
    printf("Não ha nenhum contato adicionado\n");
  } else {
		int i=1;
		printf("\nSelecione o contato voce gostaria de pesquisar de acordo com o numero associado a ele.\n");

		scanf("\n%d", &i); /*lê o índice que o usuário quer pesquisar*/
    contato *temp = *head; /*ponteiro temporário aponta para o começo da lista*/
    printf("Contato %d\n", i); /* imprime Contato i*/
    while(i!= 1){ /*Vai acessando a lista encadeada até o i selecionado*/
      temp = temp->next;
      i--;
    }
    printf("Nome: %s\n", temp->nome); /* imprime o dado nome do ponteiro*/
    printf("Telefone: %s\n", temp->telefone); /* imprime o dado telefone do ponteiro*/
    printf("Email: %s\n", temp->email); /* imprime o dado email do ponteiro*/
    printf("---------\n");
		
  }
}

void lista_contatos(contato** head){
  int i=1;
  if (*head==NULL){ /*se não existem contatos*/
    printf("Nao ha nenhum contato adicionado\n");
  } else {
    contato* temp = *head; /*criamos um ponteiro temporário*/
    printf("---------\n");
    while(temp != NULL){ /*enquanto o ponteiro não for o último*/
      printf("Contato %d\n", i);
      printf("Nome: %s\n", temp->nome);
      printf("Telefone: %s\n", temp->telefone);
      printf("Email: %s\n", temp->email);
      printf("---------\n");
      temp = temp->next; /*atualize o ponteiro*/
      i++;
    }
    printf("Acabou a lista!\n");
  }
  
}

void lista_opcoes(){
  printf("\nEscolha uma opcao:\n");
  printf("1 - Adicionar um contato\n");
  printf("2 - Deletar um contato\n");
  printf("3 - Listar contatos\n");
  printf("4 - Editar um contato\n");
  printf("5 - busque um contato\n");
  printf("0 - Sair do programa\n");
}

contato entrada(){
  contato info;

  printf("Digite o nome do contato: ");
  fgetc(stdin);
  fgets(info.nome, sizeof(info.nome), stdin);
  // fgets retorna a entrada com quebra de linha no final, a expressão abaixo corrige isso encontrando a posição de \n e definindo como \0
  info.nome[strcspn(info.nome, "\n")] = '\0';

  printf("Digite o telefone do contato: ");
  fgets(info.telefone, sizeof(info.telefone), stdin);
  info.telefone[strcspn(info.telefone, "\n")] = '\0';

  printf("Digite o email do contato: ");
  fgets(info.email, sizeof(info.email), stdin);
  info.email[strcspn(info.email, "\n")] = '\0';

  return info;
}

void opcao_escolhida(int opcao, contato** head){
  //1 - adicionar
  //2 - deletar
  //3 - pesquisar
  //4 - editar
  //5 - pesquisar
  //0 - sair
  switch (opcao)
    {
      case 1:
        //ficar atento, porque se for para windows tem que usar "cls" ao invés de "clear"
        system("clear");
        printf("Voce escolheu a opcao: %d\n",opcao);
        contato pessoa = entrada();
        adiciona_contato(head, pessoa);
      break;
        
      case 2:
        system("clear");
        printf("Voce escolheu a opcao: %d\n",opcao);
				int i;
        lista_contatos(head);
        deleta_contato(head);
        system("clear");
        lista_contatos(head);
      break;

      case 3:
        system("clear");
        printf("Voce escolheu a opcao: %d\n", opcao);
        lista_contatos(head);
      break;

      case 4:
        system("clear");
        printf("Voce escolheu a opcao: %d\n",opcao);
        edita_contato(head);
      break;

      case 5:
        system("clear");
        printf("Voce escolheu a opcao: %d\n",opcao);
        pesquisa_contato(head);
      break;

      case 0:
        exit(0);
      break;

      default:
      system("clear");
      printf("A opçao %d e Invalida!\n", opcao);
    }
}

int main() {
  contato* head = NULL; /*definimos o começo da lista encadeada*/

  lista_opcoes();

  int opcao;
  while (scanf("%d",&opcao) != EOF){
    opcao_escolhida(opcao, &head);
    
    lista_opcoes();
  }
}
