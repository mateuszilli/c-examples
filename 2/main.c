#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	int numero,delet;
	char nome[30];
	float area; 
	int num_moradores;  
	float valor;
}Condominios;

FILE *arq;
Condominios c;

int menu();
void adicionar();
int localizarAp(int y);
void editar();
void excluir();
void listar();

int i;

main(){
    int opc;

	do{
		opc = menu();
		switch(opc){
            case 1:
                adicionar();
            break;
            
            case 2:
                editar();
                system("pause");
			break;
			   
            case 3:
            	excluir();
            	system("pause");
			break;
			
            case 4:
            	listar();
            	system("pause");
            break;
         }

    }while (opc != 0);
}


int menu(){
	int x;
	system("cls"); 
	printf("\t M E N U \n\n");
	printf("1. Adicionar\n");
	printf("2. Editar\n");
	printf("3. Excluir\n");
	printf("4. Listar\n");
	printf("0. Sair\n\n");
	printf("Informe a opcao desejada: ");
	scanf("%d",&x);
	return x;
}


void adicionar(){
	int x; 
	
	system("cls");
	
    arq = fopen("Condominios.dat","a+b");
    if(arq == NULL){
        printf("\nErro ao abrir os dados do condominio!");
        return;
    }
    printf("\nInforme o numero do apartamento: ");
    scanf("%d", &x);
    if(localizarAp(x)==1){
        printf("\nEsse apartamento ja existe!");
    }
    else{
        c.numero = x;
    	printf("\nNome do responsavel: ");
    	fflush(stdin);
		gets(c.nome);
    	printf("\nArea do apartamento: ");
    	scanf("%f",&c.area);
    	printf("\nNumero de moradores: ");
    	scanf("%d",&c.num_moradores);
    	c.delet = 1;
        fwrite(&c,sizeof(Condominios),1,arq);
        printf("\nApartamento cadastrado com sucesso!");
    }
    fclose(arq);
    printf("\n\n");
    system("pause");
}

int localizarAp(int y){
    fread(&c, sizeof(Condominios), 1, arq);
    while(!feof(arq)){
        if(c.numero == y){
            fseek(arq,-sizeof(Condominios),SEEK_CUR);
            return 1;
        }
        fread(&c,sizeof(Condominios), 1, arq);
    }
    return 0;
}

void editar(){
	int edit; 

	listar();
	
    arq = fopen("Condominios.dat","r+");
    if(arq == NULL){
        printf("\nErro ao acessar os dados do condominio!");
        return;
    }
    printf("\nInforme o numero do apartamento que deseja editar: ");
    scanf("%d", &edit);
    if(localizarAp(edit)==1){
		c.numero = edit;
    	printf("\nNome do responsavel: ");
    	fflush(stdin);
		gets(c.nome);
    	printf("\nArea do apartamento: ");
    	scanf("%f",&c.area);
    	printf("\nNumero de moradores: ");
    	scanf("%d",&c.num_moradores);
        fwrite(&c,sizeof(Condominios),1,arq);
        printf("\nEdicao concluida!\n\n");
    }
    else{
        printf("\nOs dados do apartamento não foram encontrados!\n\n");
    }
    fclose(arq);
}

void excluir(){
	int del;
	system("cls");
	
	listar();
	
	arq = fopen("Condominios.dat","r+");
    if(arq == NULL){
        printf("\nErro ao acessar os dados do condominio!");
        return;
    }
    printf("\nInforme o numero do apartamento que deseja excluir: ");
    scanf("%d", &del);
    if(localizarAp(del)==1){
		c.numero = 0;
    	strcpy(c.nome,"\0");
    	c.area = 0;
    	c.num_moradores = 0;
    	c.delet = -1;
        fwrite(&c,sizeof(Condominios),1,arq);
        printf("\nExclusao concluida!\n\n");
    }
    else{
        printf("\nOs dados do apartamento não foram encontrados!\n\n");
    }
    fclose(arq);
	
	
}

void listar(){
	system("cls");
	arq = fopen("Condominios.dat","r");
    if(arq==NULL){
        printf("\nErro ao acessar dados do condominio!");
        return;
    }
    fread(&c, sizeof(Condominios),1,arq);
    while(!feof(arq)){
    	if(c.delet>0){
	    printf("\nNumero do apartamento: %d",c.numero);
	    printf("\nNome do responsavel: %s",c.nome);
	    printf("\nArea do apartamento: %.2f",c.area);
	    printf("\nNumero de moradores: %d",c.num_moradores);
	    printf("\n---------------------------------\n");
		}
	    fread(&c, sizeof(Condominios),1,arq);	
	}
    fclose(arq);
    printf("\n\n");	
}

