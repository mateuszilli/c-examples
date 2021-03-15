/*4. Faça um programa de calculadora simples com as seguintes operações possíveis: adição, subtração, multiplicação e divisão. 
O programa inicia apresentando ao usuário um menu de opções como mostrado abaixo: 

**********************************
* Calculadora. Opções possíveis:
* 1. Adição
* 2. Subtração
* 3. Multiplicação
* 4. Divisão
* 0. Sair do programa
**********************************

Entre com sua opcao:
Crie uma função que apresenta o menu inicial acima e retorna a opção do usuário para o programa principal.
Esta opção é então analisada e o programa principal chama as funções de adição, subtração, multiplicação e divisão conforme a opção do usuário.
Se a opção for inválida, informe ao usuário e peça a ele para entrar com uma opção válida.
Após a execução da operação o programa volta a apresentar o menu inicial até que o usuário encerre o programa com a opção 0.*/

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
 






