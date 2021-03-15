#include<stdio.h>
#include<string.h>
#define T 100
#define R 50

typedef struct{
	float nota;
}Notas;

typedef struct{
	char username[15];
	int senha;
	char nome[30];
	char email[40];
	char telefone[15];
	int idade;
	Notas N[10];
}Alunos;

typedef struct{
	char nome[30];
	char email[40];
	char telefone[15];
}Professor;

typedef struct{
	int numSala,codSerie;
	int qtdnotas;
	Professor P[12];
	Alunos A[50];
}Sala;

typedef struct{
	char serie[30];
	int codSerie;
	char disciplina[20];
}Predefinidos;

Sala S[T];  	 //Sala com associação de alunos e professores.
Predefinidos Predef[T];
/*
Alunos A[T];  	 //Acesso ao aluno, seu perfil e notas.
Professor P[T];  //Acesso a professores, com adição a notas em cada turma, e aluno em determinada disciplina.
Disciplina D[T]; //Disciplinas, associação de alunos e professores.
*/

int idser=0;  //ID Serie
int ids=0; //ID Sala
int ida[T]={0}; //ID Aluno
int idp[T]={0}; //ID Professor
int idn[T]={0}; //ID Nota
float media[R]={0}; //Media dos alunos
int i,j,k,codS=0,codA=0;
int auxResultado=0;


int menu_principal;
int menu_sub;
int menu_sub1;


int menu();
int menu1();
int menu2();
int menu_nota1();
void predefinidos();
void cadastro_turmas();
void editar_turmas();
void excluir_turmas();
void listar_turmas();
void BuscaSerie(int cod);
void pesquisar_turmas();
void cadastro_professor();
void editar_professor();
void excluir_professor();
void listar_professor();
void pesquisar_professor();
void cadastro_alunos();
void editar_alunos();
void excluir_alunos();
void listar_alunos();
void pesquisar_alunos();
void adicionar_notas();
void editar_notas();
void excluir_notas();
void nota_aluno();
void resultado();



main(){
	
	predefinidos();
	
	do{
		menu_principal = menu();
		switch(menu_principal){
			case 1:
				do{
					menu_sub = menu1();
					switch(menu_sub){
						case 1:
							cadastro_turmas();
						break;
						
						case 2:
							editar_turmas();
						break;
						
						case 3:
							excluir_turmas();
						break;
						
						case 4:
							listar_turmas();
							system("pause");
						break;
						
						case 5:
							pesquisar_turmas();
						break;
					}	
				}while(menu_sub != 0);
			break;
			
			case 2:
				do{
					menu_sub = menu1();
					switch(menu_sub){
						case 1:
							cadastro_professor();
						break;
						
						case 2:
							editar_professor();
						break;
						
						case 3:
							excluir_professor();
						break;
						
						case 4:
							listar_professor();
						break;
						
						case 5:
							pesquisar_professor();
						break;
					}	
				}while(menu_sub != 0);	
			break;
			
			case 3:
				do{
					menu_sub = menu1();
					switch(menu_sub){
						case 1:
							cadastro_alunos();
						break;
						
						case 2:
							editar_alunos();
						break;
						
						case 3:
							excluir_alunos();
						break;
						
						case 4:
							listar_alunos();
							system("pause");
						break;
						
						case 5:
							pesquisar_alunos();
						break;
					}	
				}while(menu_sub != 0);	
			break;
			
			case 4:
				do{
					menu_sub = menu2();
					switch(menu_sub){
						case 1:
							do{
								menu_sub1 = menu_nota1();
								switch(menu_sub1){
									case 1:
										adicionar_notas();
									break;
									
									case 2:
										editar_notas();
									break;
									
									case 3:
										excluir_notas();
									break;
								}
							}while(menu_sub1!=0);
						break;
						
						case 2:
							nota_aluno();
						break;
					}	
				}while(menu_sub != 0);	
			break;
			
			case 5:
				resultado();
			break;
		}		
	}while(menu_principal != 0);
	
}


int menu(){
	int x;
	system("cls");
	printf("\t\t\t*******************************\n");
	printf("\t\t\t************ MENU *************\n");
	printf("\t\t\t**                           **\n");
	printf("\t\t\t**\t[1] - Turmas         **\n");
	printf("\t\t\t**\t[2] - Professores    **\n");
	printf("\t\t\t**\t[3] - Alunos         **\n");
	printf("\t\t\t**\t[4] - Notas          **\n");
	printf("\t\t\t**\t[5] - Resultados     **\n");
	printf("\t\t\t**\t[0] - Sair           **\n");
	printf("\t\t\t**                           **\n");
	printf("\t\t\t*******************************\n");
	printf("\t\t\t*******************************\n\n");
	printf("\t\t\tInforme a opcao desejada: ");
	scanf("%d",&x);
	return x;
	
}

int menu1(){
	int x;
	system("cls");
	printf("\t\t\t*******************************\n");
	printf("\t\t\t*********** SUB MENU **********\n");
	printf("\t\t\t**                           **\n");
	printf("\t\t\t**\t[1] - Cadastro       **\n");
	printf("\t\t\t**\t[2] - Editar         **\n");
	printf("\t\t\t**\t[3] - Excluir        **\n");
	printf("\t\t\t**\t[4] - Listar         **\n");           
	printf("\t\t\t**\t[5] - Pesquisa       **\n");
	printf("\t\t\t**\t[0] - Sair           **\n");
	printf("\t\t\t**                           **\n");
	printf("\t\t\t*******************************\n");
	printf("\t\t\t*******************************\n\n");
	printf("\t\t\tInforme a opcao desejada: ");
	scanf("%d",&x);
	return x;
}

int menu2(){
	int x;
	system("cls");
	printf("\t\t\t*******************************\n");
	printf("\t\t\t*********** SUB MENU **********\n");
	printf("\t\t\t**                           **\n");
	printf("\t\t\t**    [1] - Professores      **\n");
	printf("\t\t\t**    [2] - Alunos           **\n");
	printf("\t\t\t**    [0] - Sair             **\n");
	printf("\t\t\t**                           **\n");
	printf("\t\t\t*******************************\n");
	printf("\t\t\t*******************************\n\n");
	printf("\t\t\tInforme a opcao desejada: ");
	scanf("%d",&x);
	return x;
}

int menu_nota1(){
	int x;
	system("cls");
	printf("\t\t\t*******************************\n");
	printf("\t\t\t*********** SUB MENU **********\n");
	printf("\t\t\t**                           **\n");
	printf("\t\t\t**     [1] - Adicionar nota  **\n");
	printf("\t\t\t**     [2] - Editar nota     **\n");
	printf("\t\t\t**     [3] - Excluir nota    **\n");
	printf("\t\t\t**     [0] - Sair            **\n");
	printf("\t\t\t**                           **\n");
	printf("\t\t\t*******************************\n");
	printf("\t\t\t*******************************\n\n");
	printf("\t\t\tInforme a opcao desejada: ");
	scanf("%d",&x);
	return x;
}

void predefinidos(){
	system("cls");	
	Predef[idser].codSerie = 1;
	strcpy(Predef[idser].serie,"Primeiro ano");
	idser++;
	Predef[idser].codSerie = 2;
	strcpy(Predef[idser].serie,"Segundo ano");
	idser++;
	Predef[idser].codSerie = 3;
	strcpy(Predef[idser].serie,"Terceiro ano");
	idser++;
	Predef[idser].codSerie = 4;
	strcpy(Predef[idser].serie,"Quarto ano");
	idser++;
	Predef[idser].codSerie = 5;
	strcpy(Predef[idser].serie,"Quinto ano");
	idser++;	
	Predef[idser].codSerie = 6;
	strcpy(Predef[idser].serie,"Sexto ano");
	idser++;
	Predef[idser].codSerie = 7;
	strcpy(Predef[idser].serie,"Setimo ano");
	idser++;
	Predef[idser].codSerie = 8;
	strcpy(Predef[idser].serie,"Oitavo ano");
	idser++;
	Predef[idser].codSerie = 9;
	strcpy(Predef[idser].serie,"Nono ano");
	idser++;
	Predef[idser].codSerie = 10;
	strcpy(Predef[idser].serie,"Primeiro grau");
	idser++;
	Predef[idser].codSerie = 11;
	strcpy(Predef[idser].serie,"Segundo grau");
	idser++;
	Predef[idser].codSerie = 12;
	strcpy(Predef[idser].serie,"Terceiro grau");
	idser++;		
}

void cadastro_turmas(){
	int x;
	system("cls");
	printf("\n\n\t\t\tInforme o numero da sala: ");
	scanf("%d",&S[ids].numSala);
	printf("\n\n\t\t\t Cod  | Serie");
	for(i=0;i<idser;i++){
		printf("\n\t\t\t [%d]  | %s",Predef[i].codSerie,Predef[i].serie);
	}
	printf("\n\n\t\t\tInforme o Cod da serie: ");
	scanf("%d",&S[ids].codSerie);
	printf("\n\t\t\tInforme a quantidade de notas para esta sala: ");
	scanf("%d",&S[ids].qtdnotas);
	ids++;
	printf("\n\t\t\tTurma cadastrada!\n\n");
	system("pause");
}

void editar_turmas(){
	system("cls");
	int edit;
	if(ids>0){
		listar_turmas();
		printf("\n\t\t\tInfome o COD da sala que deseja editar:");
		scanf("%d",&edit);
		printf("\n\t\t\tInforme o novo numero da sala:");
		scanf("%d",&S[edit].numSala);
		printf("\n\n\t\t\t Cod  | Serie");
		for(i=0;i<idser;i++){
			printf("\n\t\t\t [%d]  | %s",Predef[i].codSerie,Predef[i].serie);
		}
		printf("\n\n\t\t\tInforme o novo COD da serie:");
		scanf("%d",&S[edit].codSerie);
		printf("\n\t\t\tInforme a nova quantidade de notas para esta sala: ");
		scanf("%d",&S[edit].qtdnotas);
		printf("\n\t\t\tCadastro Editado!\n\n");
		system("pause");
	
	}else{
		printf("\n\t\t\tSala nao cadastrada!\n");
		system("pause");
	}	
}

void excluir_turmas(){
	int del;
	system("cls");
	listar_turmas();
	printf("\n\t\t\tInforme o cod da turma que deseja excluir: ");
	scanf("%d",&del);
	if(del>=0 && del<ids){
		for(i=del;i<ids;i++){
			S[i].numSala = S[i+1].numSala;
			S[i].codSerie = S[i+1].codSerie;
			S[i].qtdnotas = S[i+1].qtdnotas;
			for(j=0;j<idp[i];j++){
				strcpy(S[i].P[j].nome,S[i+1].P[j+1].nome);
				strcpy(S[i].P[j].email,S[i+1].P[j+1].email);
				strcpy(S[i].P[j].telefone,S[i+1].P[j+1].telefone);
			}
			for(j=0;j<ida[i];j++){
				strcpy(S[i].A[j].nome,S[i+1].A[j+1].nome);
				strcpy(S[i].A[j].email,S[i+1].A[j+1].email);
				strcpy(S[i].A[j].telefone,S[i+1].A[j+1].telefone);
				strcpy(S[i].A[j].username,S[i+1].A[j+1].username);
				S[i].A[j].senha = S[i+1].A[j+1].senha;
				S[i].A[j].idade = S[i+1].A[j+1].idade;
				for(k=0;k<idn[j];k++){
						S[i].A[j].N[k].nota = S[i].A[j+1].N[k+1].nota;
				}
				idn[j]--;		
			}	
		}
		ids--;
		idp[del]--;
		ida[del]--;
		printf("\n\t\t\tRegistros da sala excluidos!\n\n");
	}
	else{
		printf("\n\t\t\tCod invalido!\n\n");
	}
	system("pause");
}

void listar_turmas(){
	system("cls");
	
	for(i=0;i<ids;i++){
		printf("\t\t\t****************************************");
		printf("\n\t\t\t**                                    **");
		printf("\n\t\t\t**       Codigo da sala: [%d]          **",i);
		printf("\n\t\t\t**       Numero da sala: [%d]         **",S[i].numSala);
		BuscaSerie(S[i].codSerie);
		printf("\n\t\t\t**                                    **\n");
		printf("\t\t\t****************************************\n\n");
	}
	printf("\n");
}
void pesquisar_turmas(){
	int search=0,aux=0;
	system("cls");
	printf("\t\t\tInforme o numero da sala que deseja pesquisar: ");
	scanf("%d",&search);
	
	for(i=0;i<ids;i++){
		if(search==S[i].numSala){
			printf("\t\t\t****************************************");
			printf("\n\t\t\t**                                    **");
			printf("\n\t\t\t**       Codigo da sala: [%d]          **",i);
			printf("\n\t\t\t**       Numero da sala: [%d]         **",S[i].numSala);
			BuscaSerie(S[i].codSerie);
			printf("\n\t\t\t**                                    **\n");
			printf("\t\t\t****************************************\n\n");
			aux=1;
		}	
	}
	
	if(aux==0){
		printf("\n\t\t\tNao foram encontrados registro com o a sala numero %d\n\n",search);
	}
	system("pause");
	
}

void BuscaSerie(int cod){
    int x;

    for(x=0;x<idser;x++){
        if (Predef[x].codSerie==cod){
            printf("\n\t\t\t**       Serie: %s           **",Predef[x].serie);
            x = idser;
        }
    }
}

void cadastro_professor(){
	int x;
	system("cls");
	if(ids>0){
		listar_turmas();
		printf("\t\t\tInforme o Cod da sala para cadastrar o professor: ");
		scanf("%d",&x);
		system("cls");
		printf("\t\t\tInforme o nome do professor: ");
		fflush(stdin);
		gets(S[x].P[idp[x]].nome);
		printf("\n\t\t\tInforme o email: ");
		fflush(stdin);
		gets(S[x].P[idp[x]].email);
		printf("\n\t\t\tInforme o numero de telefone: ");
		fflush(stdin);
		gets(S[x].P[idp[x]].telefone);
		idp[x]++;
		printf("\n\t\t\tProfessor cadastrado!\n\n");
	}
	else{
		printf("\n\t\t\tCadastre uma turma antes de adicionar professores!\n");
	}
	system("pause");
}

void editar_professor(){
	int y,x;
	system("cls");
	
	if(ids>0){
		listar_turmas();
		printf("\n\t\t\tInforme o COD da sala do professor:");
		scanf("%d",&x);
	
		if(idp>0){
			listar_professor();
			printf(" \n\t\t\tInforme  qual professor deseja editar:");
			scanf("%d",&y);
			system("cls");
			printf("\n\t\t\tInforme o nome do professor:");
			fflush(stdin);
			gets(S[x].P[y].nome);
			printf("\n\t\t\tInforme o email:");
			fflush(stdin);
			gets(S[x].P[y].email);
			printf("\n\t\t\tInforme o telefone:");
			fflush(stdin);
			gets(S[x].P[y].telefone);
			printf("\n\t\t\tCadastro Editado!!\n\n");
			system("pause");
		}
		else{
			printf("\n\t\t\tNao existem professores cadastrados!");
			system("pause");
		}
	}
	else{
		printf(" \n\t\t\tNao existem salas cadastradas!");
		system("pause");
	}
}
void excluir_professor(){
	int del,x;
	system("cls");
	
	if(ids>0){
		listar_turmas();
		printf("\n\t\t\tInforme o COD da sala do professor:");
		scanf("%d",&x);
	
		if(idp[x]>0){
			listar_professor();
			printf(" \n\t\t\tInforme qual professor deseja excluir: ");
			scanf("%d",&del);
			system("cls");
			if(del>=0 && del<idp[x]){
				for(i=del;i<idp[x];i++){
					strcpy(S[x].P[del].nome,S[x].P[del+1].nome);
					strcpy(S[x].P[del].email,S[x].P[del+1].email);
					strcpy(S[x].P[del].telefone,S[x].P[del+1].telefone);
				}
				idp[del]--;
				printf("\n\t\t\tRegistros do professor excluidos!\n\n");
				system("pause");
			}
		}
		else{
			printf("\n\t\t\tNao existem professores cadastrados!");
			system("pause");
		}
	}
	else{
		printf(" \n\t\t\tNao existem salas cadastradas!");
		system("pause");
	}
	
}
void listar_professor(){
	int x;
	system("cls");
	listar_turmas();
	system("cls");
	for(j=0;j<ids;j++){
		if(idp[j]!=0){
			printf("\n\t\t\tSala [%d]",S[j].numSala);
			printf("\n\t\t\t---------------------------------------------");
			for(i=0;i<idp[j];i++){
				printf("Cod [%d]",i);
				printf("\n\t\t\tNome: %s",S[j].P[i].nome);
				printf("\n\t\t\tE-mail: %s",S[j].P[i].email);
				printf("\n\t\t\tNumero de telefone: %s",S[j].P[i].telefone);
				printf("\n\t\t\t---------------------------------------------\n");
			}
		}
	}
	system("pause");
}

void pesquisar_professor(){
	char search[30];
	int aux=0;
	system("cls");
	printf("\t\t\tInforme o professor que deseja pesquisar: ");
	fflush(stdin);
	gets(search);
	
	for(i=0;i<ids;i++){
		for(j=0;j<idp[i];j++){
			if(strcmp(S[i].P[j].nome,search)==0){
				aux=1;
				printf("\t\t\tSala do professor: %d",S[i].numSala);
				printf("\n\t\t\tNome: %s",S[i].P[j].nome);
				printf("\n\t\t\tE-mail: %s",S[i].P[j].email);
				printf("\n\t\t\tNumero de telefone: %s\n\n",S[i].P[j].telefone);
			}
		}
	}
	
	if(aux==0){
		printf("\n\t\t\tNao foram encontrados registro do professor: %s\n\n",search);
	}
	system("pause");
}

void cadastro_alunos(){
	int x,y=1;
	system("cls");
	if(ids>0){
		listar_turmas();
		printf("\t\t\tInforme o Cod da sala que deseja adicionar alunos: ");
		scanf("%d",&x);
		while(y==1){
			system("cls");
			printf("\t\t\tNome: ");
			fflush(stdin);
			gets(S[x].A[ida[x]].nome);
			printf("\n\t\t\tIdade: ");
			scanf("%d",&S[x].A[ida[x]].idade);
			printf("\n\t\t\tE-Mail: ");
			fflush(stdin);
			gets(S[x].A[ida[x]].email);
			printf("\n\t\t\tTelefone: ");
			fflush(stdin);
			gets(S[x].A[ida[x]].telefone);
			printf("\n\t\t\tInforme um nome de usuario: ");
			fflush(stdin);
			gets(S[x].A[ida[x]].username);
			printf("\n\t\t\tInforme uma senha: ");
			scanf("%d",&S[x].A[ida[x]].senha);
			ida[x]++;
			printf("\n\t\t\tDeseja cadastrar mais alunos nessa sala?\n");
			printf("\t\t\tDigite [1] para continuar cadastrando ou [0] para sair!\n");
			scanf("%d",&y);
		}
	}
	else{
		printf("\n\t\t\tCadastre uma turma antes de adicionar alunos!\n");
	}
	printf("\n");
	system("pause");
}

void editar_alunos(){
	system("cls");
	int x,y;
		
	if(ids>0){
		listar_turmas();
		printf("\n\t\t\tInforme o COD da sala do aluno:");
		scanf("%d",&x);
	
		if(ida[x]>0){
			listar_alunos();
			printf("\n\t\t\tInforme  qual aluno deseja editar:");
			scanf("%d",&y);
			system("cls");
			printf("\n\t\t\tInforme o nome do aluno:");
			fflush(stdin);
			gets(S[x].A[y].nome);
			printf("\n\t\t\tInforme a idade do aluno:");
			scanf("%d",&S[x].A[y].idade);
			printf("\n\t\t\tInforme o email do aluno:");
			fflush(stdin);
			gets(S[x].A[y].email);
			printf("\n\t\t\tInforme o telefone do aluno:");
			fflush(stdin);
			gets(S[x].A[y].telefone);
			printf("\n\t\t\tInforme um nome de usuario do aluno:");
			fflush(stdin);
			gets(S[x].A[y].username);
			printf("\n\t\t\tInforme a nova senha do aluno:");
			scanf("%d",&S[x].A[y].senha);
			printf("\t\t\tCadastro Editado!!");
			system("pause");
		}
		else{
			printf("\n\t\t\tNao existem alunos cadastrados!");
			system("pause");
		}
	}
	else{
		printf(" \n\t\t\tNao existem salas cadastradas!");
		system("pause");
	}
}
void excluir_alunos(){
	int del,x;
	system("cls");
	
	if(ids>0){
		listar_turmas();
		printf("\n\t\t\tInforme o COD da sala do aluno:");
		scanf("%d",&x);
	
		if(ida[x]>0){
			printf("\n\t\t\tSala {%d}\n\n",S[x].numSala);
			printf("\t\t\t************************************************************\n");
			for(i=0;i<ida[x];i++){
				printf("\n   \t\t\tMatricula[%d]\n",i);
				printf("\t\t\tNome: %s \t\tIdade: %d\n",S[x].A[i].nome,S[x].A[i].idade);
				printf("\t\t\tE-Mail: %s \tTelefone: %s\n",S[x].A[i].email,S[x].A[i].telefone);
				printf("\n\t\t\t------------------------------------------------------------\n");
			}
			printf("\n\t\t\t************************************************************\n");
			printf(" \n\t\t\tInforme  qual aluno deseja excluir: ");
			scanf("%d",&del);
			system("cls");
			if(del>=0 && del<ida[x]){
				for(i=del;i<ida[x];i++){
					strcpy(S[x].A[i].nome,S[x].A[i+1].nome);
					strcpy(S[x].A[i].email,S[x].A[i+1].email);
					strcpy(S[x].A[i].telefone,S[x].A[i+1].telefone);
					strcpy(S[x].A[i].username,S[x].A[i+1].username);
					S[x].A[i].senha = S[x].A[i+1].senha;
					S[x].A[i].idade = S[x].A[i+1].idade;
					idn[del] = idn[del+1];
					for(j=0;j<idn[i];j++){
						S[x].A[del].N[j].nota = S[x].A[del+1].N[j+1].nota;
					}
					idn[i]--;
				}
				ida[x]--;
				printf("\n\t\t\tRegistros do aluno excluidos!\n\n");
			}
			else{
				printf("\n\t\t\tCodigo invalido!\n\n");
			}
		}
		else{
			printf("\n\t\t\tNao existem alunos cadastrados!\n\n");
		}
	}
	else{
		printf(" \n\t\t\tNao existem salas cadastradas!\n\n");
	}
	system("pause");
}

void listar_alunos(){
	int x;
	system("cls");
	listar_turmas();
	printf("\t\t\tInforme o Cod da sala que deseja listar os alunos: ");
	scanf("%d",&x);
	system("cls");
	if(ida[x]!=0){
		printf("\n\t\t\tSala {%d}\n\n",S[x].numSala);
		printf("\t\t\t***********************************************\n");
		for(i=0;i<ida[x];i++){
			printf("\n\t\t\tMatricula[%d]\n",i);
			printf("\t\t\tNome: %s \t\tIdade: %d\n",S[x].A[i].nome,S[x].A[i].idade);
			printf("\t\t\tE-Mail: %s \tTelefone: %s\n",S[x].A[i].email,S[x].A[i].telefone);
			printf("\n\t\t\t-----------------------------------------------\n");
		}
		printf("\n\t\t\t***********************************************\n");
	}
}
void pesquisar_alunos(){
	char search[30];
	int aux=0;
	system("cls");
	printf("\t\t\tInforme o aluno que deseja pesquisar: ");
	fflush(stdin);
	gets(search);
	
	for(i=0;i<ids;i++){
		for(j=0;j<ida[i];j++){
			if(strcmp(S[i].A[j].nome,search)==0){
				aux=1;
				printf("\n\n\t\t\tSala do aluno: %d",S[i].numSala);
				printf("\n\t\t\tMatricula[%d]\n",j);
				printf("\t\t\tNome: %s \t\tIdade: %d\n",S[i].A[j].nome,S[i].A[j].idade);
				printf("\t\t\tE-Mail: %s \tTelefone: %s\n",S[i].A[j].email,S[i].A[j].telefone);
			}
		}
	}
	
	if(aux==0){
		printf("\n\t\t\tNao foram encontrados registro do aluno: %s\n\n",search);
	}
	system("pause");
}

void adicionar_notas(){
	int x,y,aux;
	system("cls");
	listar_turmas();
	printf("\t\t\tInforme o Cod da sala: ");
	scanf("%d",&x);
	system("cls");
	printf("\n\t\t\tSala: {%d}",S[x].numSala);
	for(i=0;i<ida[x];i++){
		printf("\n\t\t\t   Matricula[%d]\n",i);
		printf("\t\t\tNome: %s\n",S[x].A[i].nome);
		printf("\n\t\t\t--------------------------------------------------\n");
	}
	printf("\n\t\t\tInforme o Cod do aluno: ");
	scanf("%d",&y);
	do{
		system("cls");
		printf("\t\t\tInforme a nota: ");
		scanf("%f",&S[x].A[y].N[idn[y]].nota);
		idn[y]++;
		printf("\n\t\t\tDeseja cadastrar mais notas?\n");
		printf("\t\t\tDigite [0] para sair ou [1] para adicionar mais notas!\n");
		scanf("%d",&aux);	
	}while(aux!=0);
	
}

void editar_notas(){
	int x,edit;
	system("cls");
	listar_turmas();
	printf("\t\t\tInforme o Cod da sala: ");
	scanf("%d",&x);
	printf("\n\t\t\tSala: {%d}",S[x].numSala);
	for(i=0;i<ida[x];i++){
		printf("\n\t\t\t   Matricula[%d]\n",i);
		printf("\t\t\tNome: %s\n",S[x].A[i].nome);
		printf("\n\t\t\t--------------------------------------------------\n");
	}
	printf("\n\t\t\tInforme o Cod do aluno que deseja editar as notas: ");
	scanf("%d",&edit);
	system("cls");
	if(edit>=0 && edit<ida[x]){
		for(i=0;i<idn[edit];i++){
			printf("\t\t\tNota %d: ",i);
			scanf("%f",&S[x].A[edit].N[i].nota);
		}
	printf("\n\t\t\tEdicao concluida!\n\n");
	system("pause");
	}
	else{
		printf("\n\t\t\tAluno nao existente!\n\n");
		system("pause");
	}	
}

void excluir_notas(){
	int x,y,del;
	system("cls");
	listar_turmas();
	printf("\t\t\tInforme o Cod da sala: ");
	scanf("%d",&x);
	system("cls");
	printf("\n\t\t\tSala: {%d}",S[x].numSala);
	for(i=0;i<ida[x];i++){
		printf("\n\t\t\t   Matricula[%d]\n",i);
		printf("\t\t\tNome: %s\n",S[x].A[i].nome);
		printf("\n\t\t\t-----------------------------------------------------\n");
	}
	printf("\n\t\t\tInforme o Cod do aluno: ");
	scanf("%d",&y);
	for(i=0;i<idn[y];i++){
		printf("\n\t\t\tNota %d: %.2f\n\n",i,S[x].A[y].N[i].nota);
	}
	printf("\t\t\tInforme o Cod da nota que deseja excluir: ");
	scanf("%d",&del);
	system("cls");
	if(del>=0 && del<idn[y]){
		for(i=del;i<idn[y];i++){
			S[x].A[y].N[i].nota = S[x].A[y].N[i+1].nota;
		}
		idn[y]--;
		printf("\n\t\t\tExclusao concluida!\n\n");
		system("pause");
	}
	else{
		printf("\n\t\t\tNota inexistente!\n\n");
		system("pause");
	}
}

void nota_aluno(){
	char login[20];
	int password,x=0;
	system("cls");
	printf("\t\t\tNome de Usuario: ");
	fflush(stdin);
	gets(login);
	printf("\t\t\tSenha: ");
	scanf("%d",&password);
	
	for(j=0;j<ids;j++){
		for(i=0;i<ida[x];i++){
			if(strcmp(S[j].A[i].username,login)==0){
				if(S[j].A[i].senha==password){
					x=1;
					printf("\t\t\tInformacoes do aluno: \n\n");
					printf("\t\t\t   Matricula[%d]\n",i);
					printf("\t\t\tNome: %s \t\tIdade: %d\n",S[j].A[i].nome,S[j].A[i].idade);
					printf("\t\t\tE-Mail: %s \tTelefone: %s\n",S[j].A[i].email,S[j].A[i].telefone);
					for(k=0;k<idn[i];k++){
						printf("\n\t\t\tNota %d: %.2f\n",k+1,S[j].A[i].N[k].nota);
					}
				}
			}
		}
	}
	if(x=0){
		printf("\t\t\tNome de usuario ou senha incorretos!\n");
	}
	printf("\n\n");
	system("pause");	
}

void resultado(){
	float x;
	int	aux=0,auxResult=0;
	system("cls");
	if(ids>0){
		for(j=0;j<ids;j++){
			if(idp[j]>0){
				for(i=0;i<ida[j];i++){
					if(ida[i]>0){
						for(k=0;k<idn[i];k++){
							if(idn[k]>0){
								aux = 1;
							}
						}
					}
				}
			}
		}
	}
	if(aux==1){
		if(auxResult==0){
			auxResult=1;
			for(j=0;j<ids;j++){
				for(i=0;i<ida[j];i++){
					x=0;
					for(k=0;k<idn[i];k++){
						x += S[j].A[i].N[k].nota;
					}
					media[i]=(x/S[j].qtdnotas);
					if(media[i]>10){
						media[i] = 10.00;
					}	
				}
			}
		}
		printf("\t\t\t\tResultado Final: \n\n");
		printf("\t\t\tAprovado(AP)\tReprovado(RP)\n\n");
		for(j=0;j<ids;j++){
			for(i=0;i<ida[j];i++){
				printf("\t\t\tCodigo:%d\n\t\tNome: %s\n",i,S[j].A[i].nome);
				for(k=0;k<idn[i];k++){
					printf("\t\t\tNota %d: %.2f\n",k+1,S[j].A[i].N[k].nota);		
				}
				printf("\t\t\tMedia: %.2f\t\t",media[i]);
				if(media[i]<7){
					printf("(RP)\n\n");
				}
				else{
					printf("(AP)\n\n");
				}
			}
		}
	}
	else{
		printf("\t\t\tAinda nao e possivel obter o resultado final!\n\n");
	}
	
	system("pause");
}
