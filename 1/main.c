/*4. Fa�a um programa de calculadora simples com as seguintes opera��es poss�veis: adi��o, subtra��o, multiplica��o e divis�o. 
O programa inicia apresentando ao usu�rio um menu de op��es como mostrado abaixo: 

**********************************
* Calculadora. Op��es poss�veis:
* 1. Adi��o
* 2. Subtra��o
* 3. Multiplica��o
* 4. Divis�o
* 0. Sair do programa
**********************************

Entre com sua opcao:
Crie uma fun��o que apresenta o menu inicial acima e retorna a op��o do usu�rio para o programa principal.
Esta op��o � ent�o analisada e o programa principal chama as fun��es de adi��o, subtra��o, multiplica��o e divis�o conforme a op��o do usu�rio.
Se a op��o for inv�lida, informe ao usu�rio e pe�a a ele para entrar com uma op��o v�lida.
Ap�s a execu��o da opera��o o programa volta a apresentar o menu inicial at� que o usu�rio encerre o programa com a op��o 0.*/

#include<stdio.h>
#include <stdlib.h>

int f_menu();

float f_soma();

float f_subtr();

float f_multip();

float f_divis();

main(){
	
	int menu;
	float resultado=0;

	do{
		menu = f_menu();
		
		switch(menu){
			case 1:
				resultado =	f_soma();
				printf("\nO resultado e: %.2f\n\n",resultado);
				getch();
				system("cls");	
			break;
			
			case 2:
				resultado =	f_subtr();
				printf("\nO resultado e: %.2f\n\n",resultado);
				getch();
				system("cls");
			break;
			
			case 3: 
				resultado =	f_multip();
				printf("\nO resultado e: %.2f\n\n",resultado);
				getch();
				system("cls");
			break;
			
			case 4:
				resultado =	f_divis();
				printf("\nO resultado e: %.2f\n\n",resultado);
				getch();
				system("cls");
			break;
		}	
	}while(menu!=0);
}

int f_menu(){
	int x;
		printf("\t***********************************\n");
		printf("\t*      C A L C U L A D O R A      *\n");
		printf("\t***********************************\n");
		printf("\t* 1. Adicao                    (+)*\n");
		printf("\t* 2. Subtracao                 (-)*\n");
		printf("\t* 3. Multiplicacao             (x)*\n");
		printf("\t* 4. Divisao                   (/)*\n");
		printf("\t* 0. Sair do programa             *\n");
		printf("\t***********************************\n");
		printf("\nInforme a operacao desejada: ");
		scanf("%d",&x);
		
	return x;	
}

float f_soma(){
	float x,y,result;

	printf("\nInforme o primeiro numero da operacao: ");
	scanf("%f",&x);
	printf("\nInforme o segundo numero: ");
	scanf("%f",&y);
	
	result = x + y;
	
	return result;
}

float f_subtr(){
	float x,y,result;
	
	printf("\nInforme o primeiro numero da operacao: ");
	scanf("%f",&x);
	printf("\nInforme o segundo numero: ");
	scanf("%f",&y);
	
	result = x - y;
	
	return result;
}

float f_multip(){
	float x,y,result;
	
	printf("\nInforme o primeiro numero da operacao: ");
	scanf("%f",&x);
	printf("\nInforme o segundo numero: ");
	scanf("%f",&y);
	
	result = x * y;
	
	return result;
}

float f_divis(){
	float x,y,result;
	
	printf("\nInforme o primeiro numero da operacao: ");
	scanf("%f",&x);
	printf("\nInforme o segundo numero: ");
	scanf("%f",&y);
	
	result = x / y;
	
	return result;
}
 






