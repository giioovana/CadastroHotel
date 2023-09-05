//Hotel-final
//03/07/2022
//Giovana Akemi Maeda Mathias
//Lucas Kenji Hayashi
//Pedro Marques Prado
//Professor Eli Banks
//Requisitos: 1, 2 , 3 , 4 , 5 , 6 das especificacoes do Projeto Hotel LIC 
/*
Variaveis A(andar) e Ap(apartamento) usadas nas funcoes para utilizar com as respectivas matrizes
Array Mapa[20][14], usada para organizar e realizar as alteracoes no mapa do hotel
depois a ser apresentado pelo Array Hotel[20][14]
*/
#include <stdio.h>                        //biblioteca padrao utilizada em sala
#include <stdlib.h>                      //para melhor apresentacao do menu, com o comando System("cls")

void fMapa(struct sthot Hotel[20][14]);
void fReserva(struct sthot Hotel[20][14]);
void fCheckin(struct sthot Hotel[20][14]);
void fCheckout(struct sthot Hotel[20][14]);
void fCancelar(struct sthot Hotel[20][14]);
void fInfos(struct sthot Hotel[20][14]);
void fTaxa(struct sthot Hotel[20][14]);
void fSair(struct sthot Hotel[20][14]);

struct sthot 
{
	char status;
	char cpf[12];
	char nome[40]; 
	char ender[40]; 
	char cel[12]; 
	char email[40];
	char Mapa[20][14];
};


main()
{	
	struct sthot Hotel[20][14];
	
	int An, Apt;	//An=linha Apt=coluna
	int menu;

		for(int An=20; An > 1; An--)
			for(int Apt=1; Apt <= 14; Apt++)  //Formacao do mapa previamente, para provavel apresentacao imediata	
				 Hotel[An-1][Apt-1].status = '.';	
		
	do{
	
	printf("     -Seja bem-vindo ao Hotel Transilvania!-\n");
	printf("--------------------------------------------\n");
	printf("[1]: Fazer Check-in\n[2]: Fazer Check-out\n[3]: Reserva de apartamento\n[4]: Cancelar sua reserva\n[5]: Mapa dos apartamentos\n[6]: Informacoes do hospede\n[7]: Mostrar a taxa de ocupacao do hotel\n[8]: Sair do menu\n");
	printf("--------------------------------------------\n");
	printf("\nEscolha uma opcao: ");
	scanf("%d", &menu);                               //menu, com suas opcoes levando as funcoes.
	system("cls");
	switch(menu)
		{
		case 1:
			fCheckin(Hotel);
			break;
		case 2:
			fCheckout(Hotel);
			break;
		case 3:
			fReserva(Hotel);
			break;
		case 4:
			fCancelar(Hotel);
			break;
		case 5:
			fMapa(Hotel);
			break;
		case 6:
			fInfos(Hotel);
			break;
		case 7:
			fTaxa(Hotel);
			break;
		case 8:
			break;
		default:
			printf("\nPor favor, selecione uma opcao valida\n\n");   //Caso nenhuma das opcoes validas.
			break;
		}
	}
	while(menu != 8);
}

//FUNCAO CHECK-IN
void fCheckin(struct sthot Hotel[20][14])
{
	int A, Ap;
	
	printf("Para realizacao do Check-In\n");
	printf("Escolha um andar: ");
	scanf("%d", &A);
	printf("Escolha um apartamento: ");
	scanf("%d",&Ap);
	
	if(A>20 || A<0)
		printf("Andar invalido. Por favor, escolha um andar entre 1 a 20.\n");
	else if(Ap<1 || Ap>14)
		printf("Apartamento invalido. Por favor, escolha um apartamento entre 1 a 14.\n");
	else if(Hotel[A-1][Ap-1].status == 'R' || Hotel[A-1][Ap-1].status == 'O')
		printf("Apartamento indisponivel. Por favor, escolha um apartamento vazio.\n");
	else
	{	
		printf("\nPara realizar o check-in, precisamos de algumas informacoes sobre voce: ");
		printf("\nNome: ");
		scanf("%c", &Hotel[A-1][Ap-1].nome);
		gets(Hotel[A-1][Ap-1].nome);
		printf("\nCPF: ");
		gets(Hotel[A-1][Ap-1].cpf);
		printf("\nCelular: ");
		gets(Hotel[A-1][Ap-1].cel);
		printf("\nEndereco: ");
		gets(Hotel[A-1][Ap-1].ender);
		printf("\nEmail: ");
		gets(Hotel[A-1][Ap-1].email);
		
		printf("Check-in feito com sucesso!\n");
		Hotel[A-1][Ap-1].status = 'O';
	}
	printf("\n");
}

//FUNCAO CHECK-OUT
void fCheckout(struct sthot Hotel[20][14])
{
	int A, Ap;
	printf("Para realizar o Check-Out, informe:\n");
	printf("Seu andar: ");
	scanf("%d", &A);
	printf("Seu apartamento: ");
	scanf("%d",&Ap);
	
	if(A>20 || A<1)
		printf("\nAndar invalido. Por favor, escolha um andar entre 1 a 20.\n");
	else if(Ap<0 || Ap>14)
		printf("\nApartamento invalido. Por favor, escolha um apartamento entre 1 a 14.\n");
	else if(Hotel[A-1][Ap-1].status == '.')
		printf("\nApartamento ja desocupado.\n");
	else
		{
		printf("\nCheckout feito com sucesso!\n");
		Hotel[A-1][Ap-1].status = '.';
		}
	printf("\n");
}

//FUNCAO RESERVAR APARTAMENTO
void fReserva(struct sthot Hotel[20][14])
{
	int A, Ap, A1, Ap1;
	int X = 0; //variavel cujo resultado e booleano, para apresentacao dos erros necessarios na tela
	printf("Para realizar sua reserva, escolha:\n");
	printf("Andar: ");
	scanf("%d", &A);
	printf("Apartamento: ");
	scanf("%d", &Ap);
	
		for(A1=20; A1 > 0; A1--)
		for(Ap1=1; Ap1 <= 14; Ap1++)
		{
			if(Hotel[A-1][Ap-1].status == 'R')
				X = 1;
			else if(Hotel[A-1][Ap-1].status == 'O')
				X = 2;
		}
	
	if(A>20 || A<0)
		printf("Andar invalido. Por favor, escolha um andar entre 1 a 20.\n");
    else if(Ap<1 || Ap>14)
		printf("Apartamento invalido. Por favor, escolha um apartamento entre 1 a 14.\n");
	else if(X == 1)
		printf("Apartamento ja reservado. Por favor, escolha um apartamento livre\n");
	else if(X == 2)
		printf("Apartamento ja ocupado. Por favor, escolha um apartamento livre\n");
	else
	{
		printf("\nPrecisamos de algumas informacoes sobre voce para concluir a reserva: ");
		printf("\nNome: ");
		scanf("%c", &Hotel[A-1][Ap-1].nome);
		gets(Hotel[A-1][Ap-1].nome);
		printf("\nCPF: ");
		gets(Hotel[A-1][Ap-1].cpf);
		printf("\nCelular: ");
		gets(Hotel[A-1][Ap-1].cel);
		printf("\nEndereco: ");
		gets(Hotel[A-1][Ap-1].ender);
		printf("\nEmail: ");
		gets(Hotel[A-1][Ap-1].email);
	
	printf("Reserva feita com sucesso!\n");
	}

	if(X==1 || X==2)
	{	
		A1 = A;
		Ap1 = Ap;
	}
	Hotel[A-1][Ap-1].status = 'R';
	printf("\n");
	
}

//FUNCAO CANCELAR RESERVA
void fCancelar(struct sthot Hotel[20][14])
{
	int A, Ap;
	printf("Para cancelar sua reserva, informe:\n");
	printf("Andar: ");
	scanf("%d", &A);
	printf("Apartamento: ");
	scanf("%d",&Ap);
	
	if(A>20 || A<1)
		printf("Andar invalido. Por favor, escolha um andar entre 1 a 20.\n");
	else if(Ap<0 || Ap>14)
		printf("Apartamento invalido. Por favor, escolha um apartamento entre 1 a 14.\n");
	else if(Hotel[A-1][Ap-1].status == '.')
		printf("Apartamento ja desocupado\n");
	else
		{
		printf("Reserva cancelada com sucesso!\n");
		Hotel[A-1][Ap-1].status = '.';
		}
	printf("\n\n");
}

//FUNCAO - APRESENTACAO DO MAPA
void fMapa(struct sthot Hotel[20][14])
{	
	
	printf("[R]: Reservado	[O]: Ocupado	[.]: Livre\n");
	printf("----------------------------------------------\n");
	int A, Ap;
	
	for(A=20; A > 0; A--)
		for(Ap=1; Ap <= 14; Ap++)
		{
			if(Hotel[A-1][Ap-1].status == 'R')
				Hotel[A-1][Ap-1].status = 'R';        //apresentacao do mapa, primeiramente o gerando com suas informacoes
			else if(Hotel[A-1][Ap-1].status == 'O')   //e o apresentando em seguida
				Hotel[A-1][Ap-1].status = 'O';
			else
				Hotel[A-1][Ap-1].status = '.';	
		}
			
	printf("\t");
	for(Ap=1; Ap <= 14; Ap++)
		printf("%2d ", Ap);
	printf("\n\n");
		
	//apresentacao da matriz
	for(A=20; A > 0 ; A--)
		{
		printf("%2d\t", A);	
		for(Ap=1; Ap <= 14; Ap++)
			printf("%2c ", Hotel[A-1][Ap-1].status);
		printf("\n");
		}
		printf("\n\n");
}

//FUNCAO INFORMACOES DO HOSPEDE 
void fInfos(struct sthot Hotel[20][14])
{
	int A, Ap;
	printf("Para verificar suas informacoes, indique:\n");
	printf("O andar da sua reserva: ");
	scanf("%d", &A);
	printf("O apartamento da sua reserva: ");
	scanf("%d", &Ap);
	
	if(	Hotel[A-1][Ap-1].status != '.' )
	{
	printf("Informacoes do hospede:\n");
	printf("Andar: %d\tApartamento: %d\n",A,Ap);
	printf("Nome:%s\n", Hotel[A-1][Ap-1].nome);
	printf("CPF:%s\n", Hotel[A-1][Ap-1].cpf);              //de acordo com o apartamento reservado,
	printf("Endereco:%s\n", Hotel[A-1][Ap-1].ender);       //e indicado as informacoes registradas no check - in
	printf("Celular:%s\n", Hotel[A-1][Ap-1].cel);          //nome,cpf,endereco,celular e email
	printf("Email:%s\n", Hotel[A-1][Ap-1].email);
	printf("\n");
	}
	else
		printf("Apartamento desocupado.\n\n");
}

//FUNCAO TAXA DE OCUPACAO 
void fTaxa(struct sthot Hotel[20][14])
{
	int An,Apt;
	float Taxa,contO,contR;
	contO = 0;contR = 0;
	for(int An=20; An > 0; An--) //gerando a matriz, o espaco que estiver ocupado 'O' ou reservado 'R', o contador sera aumentado
		for(int Apt=1; Apt <= 14; Apt++)   //para ser usado no calculo da taxa, simples regra de 3,multiplicando 
			{                              //a porcentagem maxima pela quantidade de ocupacoes(cont),e dividindo pelo maximo(280).
			if(Hotel[An-1][Apt-1].status == 'O')
				contO = contO + 1;
			if(Hotel[An-1][Apt-1].status == 'R')
				contR = contR + 1;
			}
	Taxa = (100 * contO) / 280;
	printf("Taxa de ocupacao do hotel : %.2f %%\n\n",Taxa);
	Taxa = (100 * contR) / 280;
	printf("Taxa de reserva do hotel : %.2f %%\n\n",Taxa);	
}

