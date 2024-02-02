#include<stdio.h>//biblioteca de comunica��o com o usuario
#include<stdlib.h>//biblioteca de aloca��o de mem�ria
#include<locale.h>//biblioteca de aloca��o de texto por regi�o
#include<string.h>//biblioteca de string

int registro() //Fun��o responsavel por cadastrar o usu�rio.
{
	//Inicio da cria��o da vari�vel/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o da vari�vel/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informa�oes do usuario
	scanf("%s", cpf);//%s refere-se a string
	printf("\n");
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores da string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w");//cria o arquivo e o "w" siginifica escrever 
	fprintf(file,cpf);//salvo o valor da vari�vel
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

int consulta()//Fun��o respons�vel por consultar nomes cadastrados
{
	setlocale(LC_ALL, "PORTUGUESE");//Definindo a linguagem
	
	char cpf [40];
	char conteudo[200];
	
	printf("Digitie o cpf a ser consultado:  ");
	scanf("%s",cpf);
	printf("\n");
	
	FILE *file;
	file = fopen(cpf,"r");//Abrir o arquivo CPF e ler
	
	if(file==NULL)//Varida��o para CPF n�o cadastrado
	{
		printf("N�o foi poss�vel abrir esse arquivo, n�o localizado \n");
	}
	 
	 while(fgets(conteudo, 200, file) !=NULL)//Varida��o do enquanto
	 {
	 	printf("Essas s�o as informa��es do usu�rio: ");
	 	printf("%s", conteudo);
	 	printf("\n\n");
	 }
	 
	 system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);//Fun��o deletar	
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL);
	{
		printf("Esse usu�rio n�o existe! \n");
		system("pause");
	}

}




int main()
{
	int opcao=0;	//Definindo a vari�vel
	int x=1;	
	
	for(x=1;x=1;)
	{
		
		system("cls");
		
		
		setlocale(LC_ALL, "PORTUGUESE");
	
		printf("###Cart�rio da EBAC###\n\n");//In�cio do menu
		printf("Escolha a op��o desejada:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");		
		
		printf("Op��o: ");//fim do menu
	
		scanf("%d", &opcao);//armazenando a escolha do usuario
	
		system("cls");
		
		switch(opcao)//inicio da sele��o
		
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
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
		}//fim da sele��o
	}	
}




