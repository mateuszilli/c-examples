#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
	int idcli;
	char nome[30];
	char cel[30];
	char cpf[30];
	char email[50];
	char endereco[100];
	char login[30];
	char password[30];
	int status;
}TCliente;

typedef struct{
	int idpro;
	char marca[30];
	char descricao[50];
	float valor;
	int status;
}TProduto;

typedef struct{
	int idcon;
	char nome[30];
	char cpf[30];
	char cel[30];
	char email[50];
	char login[30];
	char password[30];
	int status;
}TConvidado;

typedef struct{
	int idcli;
	int ideve;
	char descricao[30];
	char local[30];
	char data[12];
	int status;
}TEvento;

typedef struct{
	int idpre; 
	int ideve;
}TListaPresente;

typedef struct{
	int idcon; 
	int ideve;
}TListaConvidado;

typedef struct{
	int idpre;
	int idcon;
	int ideve;
}TListaFinal;


int menu_principal();

int menu_manutencao();

int menu_mancliente();

void adicionar_cliente(TCliente Cli);

void editar_cliente(TCliente Cli);

void excluir_cliente(TCliente Cli);

void listar_cliente(TCliente Cli);

void pesquisar_cliente(TCliente Cli);

int localizar_cliente(FILE *aux,int x,TCliente Cli);

int menu_manproduto();

void adicionar_produto(TProduto Pro);

void editar_produto(TProduto Pro);

void excluir_produto(TProduto Pro);

void listar_produto(TProduto Pro);

void pesquisar_produto(TProduto Pro);

int localizar_produto(FILE *aux,int x,TProduto Pro);

int menu_manconvidado();

void adicionar_convidado(TConvidado Con);

void editar_convidado(TConvidado Con);

void excluir_convidado(TConvidado Con);

void listar_convidado(TConvidado Con);

void pesquisar_convidado(TConvidado Con);

int localizar_convidado(FILE *aux,int x,TConvidado Con);

int menu_cliente();

int verifica_cliente(TCliente Cliente);

int menu_listpre();

void adicionar_listpre(int cliente, TListaPresente LPre);

void listar_listpre(int cliente, TListaPresente LPre);

int localizar_listpre(int x,int y,TListaPresente LPre);

int menu_listcon();

void adicionar_listcon(int cliente, TListaConvidado LCon);

void listar_listcon(int cliente, TListaConvidado LCon);

int localizar_listcon(int x,int y,TListaConvidado LCon);
	
int menu_evento();

void adicionar_evento(int cliente,TEvento Eve);

void editar_evento(int cliente,TEvento Eve);

void excluir_evento(int cliente,TEvento Eve);

void listar_evento(int cliente,TEvento Eve);

int localizar_evento(FILE *aux,int cliente,int x,TEvento Eve);

int menu_convidado();

int verifica_convidado(TConvidado Con);

void verifica_evento(int convidado,TEvento Eve);

void adquirir_presente(int convidado,TListaFinal LFim);

int menu_relatorio();
