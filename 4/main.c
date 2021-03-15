#include "glp.h"

main(){
	TCliente Cliente;
	TConvidado Convidado;
	TProduto Produto;
	TEvento Evento;
	TListaPresente ListaPresente;
	TListaConvidado ListaConvidado;
	TListaFinal ListaFinal;
	
	int acesso=0;
	setlocale(LC_ALL,"portuguese");
	
	int menuprincipal=0,menumanutencao=0,menumancliente=0,menumanproduto=0,menumanconvidado=0,menucliente=0,menuconvidado=0,menuevento=0,menulistpre=0,menulistcon=0,menurelatorio=0;
	
	do{
		menuprincipal = menu_principal();
		
		switch(menuprincipal){
			
			case 1:
				
				do{
					menumanutencao = menu_manutencao();
			
					switch(menumanutencao){
						
						case 1:
							do{
								menumancliente = menu_mancliente();
								
								switch(menumancliente){
									case 1:
										adicionar_cliente(Cliente);
									break;
								
									case 2:
										editar_cliente(Cliente);
									break;
								
									case 3:
										excluir_cliente(Cliente);
									break;
								
									case 4:
										listar_cliente(Cliente);
									break;
							
									case 5:
										pesquisar_cliente(Cliente);
									break;
								}
							}while(menumancliente!=0);
						break;	
						
						case 2:
							do{
								menumanproduto = menu_manproduto();
								
								switch(menumanproduto){
									case 1:
										adicionar_produto(Produto);
									break;
								
									case 2:
										editar_produto(Produto);
									break;
								
									case 3:
										excluir_produto(Produto);
									break;
								
									case 4:
										listar_produto(Produto);
									break;
									
									case 5:
										pesquisar_produto(Produto);
									break;
								}
							}while(menumanproduto!=0);
						break;
							
						case 3:
							do{
								menumanconvidado = menu_manconvidado();
								
								switch(menumanconvidado){
									case 1:
										adicionar_convidado(Convidado);
									break;
								
									case 2:
										editar_convidado(Convidado);
									break;
								
									case 3:
										excluir_convidado(Convidado);
									break;
								
									case 4:
										listar_convidado(Convidado);
									break;
								
									case 5:
										pesquisar_convidado(Convidado);
									break;
								}
							}while(menumanconvidado!=0);
						break;
					}
				}while(menumanutencao!=0);
			break;
				
				
			case 2:
				
				acesso = verifica_cliente(Cliente);
				
				if(acesso != 0){

				do{
					
					menucliente = menu_cliente();
					
					switch(menucliente){
						
						case 1: 
						
							do{
								menuevento = menu_evento();
								
								switch(menuevento){
									case 1:
										adicionar_evento(acesso,Evento);
									break;
								
									case 2:
										editar_evento(acesso,Evento);
									break;
								
									case 3:
										excluir_evento(acesso,Evento);
									break;
								
									case 4:
										listar_evento(acesso,Evento);
									break;
								}
							}while(menuevento!=0);
						break;
						
						case 2:
							
							do{
								menulistpre = menu_listpre();
							
								switch(menulistpre){
									case 1:
										adicionar_listpre(acesso,ListaPresente);
									break;
								
									case 2:
										listar_listpre(acesso,ListaPresente);
									break;
								}
							}while(menulistpre!=0);
						break;
						
						case 3:
							
							do{
								menulistcon = menu_listcon();
								
								switch(menulistcon){
									case 1:
										adicionar_listcon(acesso,ListaConvidado);
									break;
									
									case 2:
										listar_listcon(acesso,ListaConvidado);
									break;
								}
							}while(menulistcon!=0);
						break;
					}
				}while(menucliente!=0);
				}	
			break;	
			
			
			case 3:
				
				acesso = verifica_convidado(Convidado);
				
				if(acesso != 0){
					
				do{
					menuconvidado = menu_convidado();
					
					switch(menuconvidado){
						
						case 1:
							verifica_evento(acesso,Evento);
						break;
					
						case 2:
							adquirir_presente(acesso,ListaFinal);
						break;
					}
				}while(menuconvidado!=0);	
				}
			break;
			
			case 4:
				do{
					menurelatorio = menu_relatorio();
			
					switch(menurelatorio){
						case 1:
						break;
				
						case 2:
						break;
					}
				}while(menurelatorio!=0);
			break;
		}	
	}while(menuprincipal!=0);

}
