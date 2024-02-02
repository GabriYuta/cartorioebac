#include<stdio.h>//biblioteca de comunicação com o usuario
#include<stdlib.h>//biblioteca de alocação de memória
#include<locale.h>//biblioteca de alocação de texto por região
#include<string.h>//biblioteca de string

int registro() //Função responsavel por cadastrar o usuário.
{
	//Inicio da criação da variável/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação da variável/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informaçoes do usuario
	scanf("%s", cpf);//%s refere-se a string
	printf("\n");
	
	strcpy(arquivo, cpf); //responsável por copiar os valores da string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w");//cria o arquivo e o "w" siginifica escrever 
	fprintf(file,cpf);//salvo o valor da variável
	fclose(file);//fecha o arquivo
	
	file =  fopen(arquivo, "a");//abrir o arquivo e o "a" significa atualizar
	fprintf(file, ",");//incluindo uma ","
	fclose(file);//fecha o arquivo
		
	printf("Digite o Nome a ser cadastrado: ");
	scanf("%s",nome);
	printf("\n");
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file =  fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	printf("\n");
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file =  fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	printf("\n");
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");//pausa a pagina
	
}

int consulta()//Função responsável por consultar nomes cadastrados
{
	setlocale(LC_ALL, "PORTUGUESE");//Definindo a linguagem
	
	char cpf [40];
	char conteudo[200];
	
	printf("Digitie o cpf a ser consultado:  ");
	scanf("%s",cpf);
	printf("\n");
	
	FILE *file;
	file = fopen(cpf,"r");//Abrir o arquivo CPF e ler
	
	if(file==NULL)//Varidação para CPF não cadastrado
	{
		printf("Não foi possível abrir esse arquivo, não localizado \n");
	}
	 
	 while(fgets(conteudo, 200, file) !=NULL)//Varidação do enquanto
	 {
	 	printf("Essas são as informações do usuário: ");
	 	printf("%s", conteudo);
	 	printf("\n\n");
	 }
	 
	 system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);//Função deletar	
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL);
	{
		printf("Esse usuário não existe! \n");
		system("pause");
	}

}




int main()
{
	int opcao=0;	//Definindo a variável
	int x=1;	
	
	for(x=1;x=1;)
	{
		
		system("cls");
		
		
		setlocale(LC_ALL, "PORTUGUESE");
	
		printf("###Cartório da EBAC###\n\n");//Início do menu
		printf("Escolha a opção desejada:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");		
		
		printf("Opção: ");//fim do menu
	
		scanf("%d", &opcao);//armazenando a escolha do usuario
	
		system("cls");
		
		switch(opcao)//inicio da seleção
		
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por ultilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
		}//fim da seleção
	}	
}




