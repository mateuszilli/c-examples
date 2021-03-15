#include "glp.h"

int menu_principal(){
	int opc;
	printf("\n\n\t\t***************************\n");
	printf("\t\t**********  GLP  **********\n");
	printf("\t\t***************************\n");
	printf("\t\t***** 1 - Manutenções *****\n");
	printf("\t\t***** 2 - Clientes    *****\n");
	printf("\t\t***** 3 - Convidados  *****\n");
	printf("\t\t***** 4 - Relatórios  *****\n");
	printf("\t\t***** 0 - Sair        *****\n");
	printf("\t\t***************************\n");
	printf("\t\t***************************\n\n");
	printf("\t\tInforme a opção: ");
	scanf("%d",&opc);
	
	return opc;	
}

int menu_manutencao(){
	int opc;
	system("cls");
	printf("\n\n\t\t*******************************************\n");
	printf("\t\t*****        MANUTENÇÃO GERAL       *******\n");
	printf("\t\t*******************************************\n");
	printf("\t\t*****  1 - Manutenção de Cliente    *******\n");
	printf("\t\t*****  2 - Manutenção de Produtos   *******\n");
	printf("\t\t*****  3 - Manutenção de Convidados *******\n");
	printf("\t\t*****  0 - Retornar                 *******\n");
	printf("\t\t*******************************************\n");
	printf("\t\t*******************************************\n\n\n");
	printf("\t\tInforme a opção: ");
	scanf("%d",&opc);
	
	return opc;	
}


int menu_mancliente(){
	int opc;
	system("cls");
	printf("\n\n\t\t************************************\n");
	printf("\t\t****** MANUTENÇÃO DE CLIENTES ******\n");
	printf("\t\t************************************\n");
	printf("\t\t******    1 - Cadastrar       ******\n");
	printf("\t\t******    2 - Editar          ******\n");
	printf("\t\t******    3 - Excluir         ******\n");
	printf("\t\t******    4 - Listar          ******\n");
	printf("\t\t******    5 - Pesquisar       ******\n");
	printf("\t\t******    0 - Retornar        ******\n");
	printf("\t\t************************************\n");
	printf("\t\t************************************\n\n");
	printf("\t\tInforme a opção: ");
	scanf("%d",&opc);
	
	return opc;	
}

void adicionar_cliente(TCliente Cli){
	FILE *arq;
	int idcli; 
	
	system("cls");
	
	arq = fopen("Clientes.txt","a+");
	if(arq == NULL){
        printf("\nErro ao abrir os dados dos clientes!");
        return;
    }
    
    printf("\nInforme o codigo do cliente: ");
    scanf("%d",&idcli);
    
    if(localizar_cliente(arq,idcli,Cli)==1){
    	system("cls");
        printf("Esse cliente ja está cadastrado!");
    }
    else{
    	system("cls");
    	fflush(stdin);
	    Cli.idcli = idcli;
	    Cli.status = 1;
	    printf("Nome: ");
		gets(Cli.nome);
	    printf("\nCPF: ");
	    gets(Cli.cpf);
		printf("\nEmail: ");
		gets(Cli.email);
		printf("\nCelular: ");
		gets(Cli.cel);
		printf("\nEndereço: ");
		gets(Cli.endereco);
		printf("\nLogin: ");
		gets(Cli.login);
		printf("\nSenha: ");
		gets(Cli.password);
	    fwrite(&Cli,sizeof(TCliente),1,arq);
	    printf("\nCliente cadastrado com sucesso!");
    }
    fclose(arq);
    printf("\n\n");
    system("pause");
}

void editar_cliente(TCliente Cli){
	FILE *arq;
	int edit; 

	listar_cliente(Cli);
	
    arq = fopen("Clientes.txt","r+");
    if(arq == NULL){
        printf("\nErro ao acessar os dados dos clientes!");
        return;
    }
    
    system("cls");
    
    printf("\nInforme o ID do cliente que deseja editar: ");
    scanf("%d", &edit);
    
    if(localizar_cliente(arq,edit,Cli)==1){
		system("cls");
		fflush(stdin);
	    Cli.idcli = edit;
	    Cli.status = 1;
	    printf("Nome: ");
		gets(Cli.nome);
	    printf("\nCPF: ");
		gets(Cli.cpf);
		printf("\nEmail: ");
		gets(Cli.email);
		printf("\nCelular: ");
		gets(Cli.cel);
		printf("\nEndereço: ");
		gets(Cli.endereco);
		printf("\nLogin: ");
		gets(Cli.login);
		printf("\nSenha: ");
		gets(Cli.password);
	    fwrite(&Cli,sizeof(TCliente),1,arq);
	    printf("\nCliente editado com sucesso!");
    }
    else{
        printf("\nOs dados do cliente não foram encontrados!\n\n");
    }
    
    fclose(arq);
    
    printf("\n\n");
    system("pause");
}

void excluir_cliente(TCliente Cli){
	FILE *arq;
	int del;
	
	system("cls");
	
	listar_cliente(Cli);
	
	system("cls");
	
	arq = fopen("Clientes.txt","r+");
    if(arq == NULL){
        printf("\nErro ao acessar os dados dos clientes!");
        return;
    }
    
    printf("\nInforme o ID do cliente que deseja excluir: ");
    scanf("%d", &del);
    
    if(localizar_cliente(arq,del,Cli)==1){
		Cli.status = -1;
		Cli.idcli = del;
		strcpy(Cli.nome,Cli.nome);
		strcpy(Cli.cpf,Cli.cpf);
		strcpy(Cli.cel,Cli.cel);
		strcpy(Cli.email,Cli.email);
		strcpy(Cli.endereco,Cli.endereco);
		strcpy(Cli.login,Cli.login);
		strcpy(Cli.password,Cli.password);
        fwrite(&Cli,sizeof(TCliente),1,arq);
        printf("\nExclusão efetuada com sucesso!\n\n");
    }
    else{
        printf("\nOs dados do cliente não foram encontrados!\n\n");
    }
    
    fclose(arq);
    
    system("pause");
}

void listar_cliente(TCliente Cli){
	FILE *arq;
	
	system("cls");
	
	arq = fopen("Clientes.txt","r");
    if(arq==NULL){
        printf("\nErro ao acessar os dados dos clientes!");
        return;
    }
    
    printf("\n\t\t Clientes\n\n");
    fread(&Cli, sizeof(TCliente),1,arq);
    while(!feof(arq)){
    	if(Cli.status > 0){
	    	printf("---------------------------------\n\n");
	    	printf("\tID: [%d]\n",Cli.idcli);
		    printf("\tNome: %s\n",Cli.nome);
		    printf("\tCPF: %s\n",Cli.cpf);
		    printf("\tCel: %s\n",Cli.cel);
		    printf("\tEmail: %s\n",Cli.email);
		    printf("\tEndereço: %s\n",Cli.endereco);
		    printf("\tLogin: %s\n",Cli.login);
		    printf("\tSenha: %s\n",Cli.password);
			printf("\n---------------------------------\n");
		}
	    fread(&Cli, sizeof(TCliente),1,arq);	
	}
    fclose(arq);
    printf("\n\n");	
    system("pause");
}

void pesquisar_cliente(TCliente Cli){
	FILE *arq;
	int aux;
	char pesq[100];
	
	system("cls");
	
	printf("Informe o nome do cliente: ");
	fflush(stdin);
	gets(pesq);
	
	arq = fopen("Clientes.txt","r");
    if(arq==NULL){
        printf("\nErro ao acessar os dados dos clientes!");
        return;
    }

    fread(&Cli, sizeof(TCliente),1,arq);
    while(!feof(arq)){
    	if(stricmp(pesq,Cli.nome) == 0){
	    	printf("---------------------------------\n\n");
	    	printf("\tID: [%d]\n",Cli.idcli);
		    printf("\tNome: %s\n",Cli.nome);
		    printf("\tCPF: %s\n",Cli.cpf);
		    printf("\tCel: %s\n",Cli.cel);
		    printf("\tEmail: %s\n",Cli.email);
		    printf("\tEndereço: %s\n",Cli.endereco);
		    printf("\tLogin: %s\n",Cli.login);
		    printf("\tSenha: %s\n",Cli.password);
			printf("\n---------------------------------\n");
			aux = 1;
		}
	    fread(&Cli, sizeof(TCliente),1,arq);	
	}
    fclose(arq);
    
    if(aux!=1){
    	system("cls");
    	printf("Clientes não encontrado na base de dados!");
	}
    
    printf("\n\n");	
    system("pause");
	
}

int localizar_cliente(FILE *aux,int x,TCliente Cli){
	fread(&Cli, sizeof(TCliente), 1, aux);
    while(!feof(aux)){
        if(Cli.idcli == x){
            fseek(aux,-sizeof(TCliente),SEEK_CUR);
            return 1;
        }
        fread(&Cli, sizeof(TCliente), 1, aux);
    }
    return 0;
}

int menu_manproduto(){
	int opc;
	system("cls");
	printf("\t\t************************************\n");
	printf("\t\t****** MANUTENÇÃO DE PRODUTOS ******\n");
	printf("\t\t************************************\n");
	printf("\t\t********  1 - Cadastrar  ***********\n");
	printf("\t\t********  2 - Editar     ***********\n");
	printf("\t\t********  3 - Excluir    ***********\n");
	printf("\t\t********  4 - Listar     ***********\n");
	printf("\t\t********  5 - Pesquisar  ***********\n");
	printf("\t\t********  0 - Retornar   ***********\n");
	printf("\t\t************************************\n");
	printf("\t\t************************************\n\n");
	printf("\t\tInforme a opção: ");
	scanf("%d",&opc);
	
	return opc;	
}

void adicionar_produto(TProduto Pro){
	FILE *arq;
	int idpro; 
	
	system("cls");
	
	arq = fopen("Produtos.txt","a+");
	if(arq == NULL){
        printf("\nErro ao abrir os dados dos produtos!");
        return;
    }
    
    printf("\nInforme o codigo do produto: ");
    scanf("%d",&idpro);
    
    if(localizar_produto(arq,idpro,Pro)==1){
    	system("cls");
        printf("Esse produto ja está cadastrado!");
    }
    else{
    	system("cls");
    	fflush(stdin);
	    Pro.idpro = idpro;
	    Pro.status = 1;
	    printf("\nMarca: ");
		gets(Pro.marca);
	    printf("\nDescrição: ");
		gets(Pro.descricao);
		printf("\nValor: ");
	    scanf("%f",&Pro.valor);
	    fwrite(&Pro,sizeof(TProduto),1,arq);
	    printf("\nProduto cadastrado com sucesso!");
    }
    fclose(arq);
    printf("\n\n");
    system("pause");
}

void editar_produto(TProduto Pro){
	FILE *arq;
	int edit; 

	listar_produto(Pro);
	
    arq = fopen("Produtos.txt","r+");
    if(arq == NULL){
        printf("\nErro ao acessar os dados dos produtos!");
        return;
    }
    
    system("cls");
    
    printf("\nInforme o ID do produto que deseja editar: ");
    scanf("%d", &edit);
    
    if(localizar_produto(arq,edit,Pro)==1){
		system("cls");
		fflush(stdin);
	    Pro.idpro = edit;
	    Pro.status = 1;
	    printf("\nMarca: ");
		gets(Pro.marca);
	    printf("\nDescrição: ");
		gets(Pro.descricao);
		printf("\nValor: ");
	    scanf("%f",&Pro.valor);
	    fwrite(&Pro,sizeof(TProduto),1,arq);
	    printf("\nProduto editado com sucesso!");
    }
    else{
        printf("\nOs dados do produto não foram encontrados!\n\n");
    }
    
    fclose(arq);
    
    printf("\n\n");
    system("pause");
}

void excluir_produto(TProduto Pro){
	FILE *arq;
	int del;
	
	system("cls");
	
	listar_produto(Pro);
	
	system("cls");
	
	arq = fopen("Produtos.txt","r+");
    if(arq == NULL){
        printf("\nErro ao acessar os dados dos produtos!");
        return;
    }
    
    printf("\nInforme o ID do produto que deseja excluir: ");
    scanf("%d", &del);
    
    if(localizar_produto(arq,del,Pro)==1){
		Pro.status = -1;
		Pro.idpro = del;
		strcpy(Pro.marca,Pro.marca);
		strcpy(Pro.descricao,Pro.descricao);
		Pro.valor = Pro.valor;
        fwrite(&Pro,sizeof(TProduto),1,arq);
        printf("\nExclusão efetuada com sucesso!\n\n");
    }
    else{
        printf("\nOs dados do produto não foram encontrados!\n\n");
    }
    
    fclose(arq);
    
    system("pause");
}

void listar_produto(TProduto Pro){
	FILE *arq;
	
	system("cls");
	
	arq = fopen("Produtos.txt","r");
    if(arq==NULL){
        printf("\nErro ao acessar os dados dos produto!\n\n");
        system("pause");
        return;
    }
    printf("\n\t\t Produtos\n\n");
    fread(&Pro, sizeof(TProduto),1,arq);
    while(!feof(arq)){
    	if(Pro.status > 0){
	    	printf("---------------------------------\n\n");
	    	printf("\tID: [%d]\n",Pro.idpro);
		    printf("\tMarca: %s\n",Pro.marca);
		    printf("\tDescrição: %s\n",Pro.descricao);
		    printf("\tValor: %.2f\n",Pro.valor);
			printf("\n---------------------------------\n");
		}
	    fread(&Pro, sizeof(TProduto),1,arq);	
	}
    fclose(arq);
    printf("\n\n");	
    system("pause");
}

void pesquisar_produto(TProduto Pro){
	FILE *arq;
	int aux;
	char pesq[100];
	
	system("cls");
	
	printf("Informe o nome do produto: ");
	fflush(stdin);
	gets(pesq);
	
	arq = fopen("Produtos.txt","r");
    if(arq==NULL){
        printf("\nErro ao acessar os dados dos produtos!");
        return;
    }

    fread(&Pro, sizeof(TProduto),1,arq);
    while(!feof(arq)){
    	if(strcmp(pesq,Pro.descricao) == 0){
	    	printf("---------------------------------\n\n");
	    	printf("\tID: [%d]\n",Pro.idpro);
		    printf("\tMarca: %s\n",Pro.marca);
		    printf("\tDescrição: %s\n",Pro.descricao);
		    printf("\tValor: %.2f\n",Pro.valor);
			printf("\n---------------------------------\n");
			aux = 1;
		}
	    fread(&Pro, sizeof(TProduto),1,arq);	
	}
    fclose(arq);
    
    if(aux!=1){
    	system("cls");
    	printf("Produto não encontrado na base de dados!");
	}
    
    printf("\n\n");	
    system("pause");
}

int localizar_produto(FILE *aux,int x,TProduto Pro){
	fread(&Pro, sizeof(TProduto), 1, aux);
    while(!feof(aux)){
        if(Pro.idpro == x && Pro.status > 0){
            fseek(aux,-sizeof(TProduto),SEEK_CUR);
            return 1;
        }
        fread(&Pro, sizeof(TProduto), 1, aux);
    }
    return 0;
}

int menu_manconvidado(){
	int opc;
	system("cls");
	printf("\t\t************************************\n");
	printf("\t\t***** MANUTENÇÃO DE CONVIDADOS *****\n");
	printf("\t\t************************************\n");
	printf("\t\t********  1 - Cadastrar  ***********\n");
	printf("\t\t********  2 - Editar     ***********\n");
	printf("\t\t********  3 - Excluir    ***********\n");
	printf("\t\t********  4 - Listar     ***********\n");
	printf("\t\t********  5 - Pesquisar  ***********\n");
	printf("\t\t********  0 - Retornar   ***********\n");
	printf("\t\t************************************\n");
	printf("\t\t************************************\n\n");
	printf("\t\tInforme a opção: ");
	scanf("%d",&opc);
	
	return opc;	
}

void adicionar_convidado(TConvidado Con){
	FILE *arq;
	int idcon; 
	
	system("cls");
	
	arq = fopen("Convidados.txt","a+");
	if(arq == NULL){
        printf("\nErro ao abrir os dados dos convidados!");
        return;
    }
    
    printf("\nInforme o codigo do convidado: ");
    scanf("%d",&idcon);
    
    if(localizar_convidado(arq,idcon,Con)==1){
    	system("cls");
        printf("Esse convidado ja está cadastrado!");
    }
    else{
    	system("cls");
    	fflush(stdin);
	    Con.idcon = idcon;
	    Con.status = 1;
	    printf("Nome: ");
		gets(Con.nome);
	    printf("\nCPF: ");
		gets(Con.cpf);
		printf("\nEmail: ");
		gets(Con.email);
		printf("\nCelular: ");
		gets(Con.cel);
		printf("\nLogin: ");
		gets(Con.login);
		printf("\nSenha: ");
		gets(Con.password);
	    fwrite(&Con,sizeof(TConvidado),1,arq);
	    printf("\nConvidado cadastrado com sucesso!");
    }
    fclose(arq);
    printf("\n\n");
    system("pause");
}

void editar_convidado(TConvidado Con){
	FILE *arq;
	int edit; 

	listar_convidado(Con);
	
    arq = fopen("Convidados.txt","r+");
    if(arq == NULL){
        printf("\nErro ao acessar os dados dos convidados!");
        return;
    }
    
    system("cls");
    
    printf("\nInforme o ID do convidado que deseja editar: ");
    scanf("%d", &edit);
    
    if(localizar_convidado(arq,edit,Con)==1){
		system("cls");
		fflush(stdin);
	    Con.idcon = edit;
	    Con.status = 1;
	    printf("Nome: ");
		gets(Con.nome);
	    printf("\nCPF: ");
		gets(Con.cpf);
		printf("\nEmail: ");
		gets(Con.email);
		printf("\nCelular: ");
		gets(Con.cel);
		printf("\nLogin: ");
		gets(Con.login);
		printf("\nSenha: ");
		gets(Con.password);
	    fwrite(&Con,sizeof(TConvidado),1,arq);
	    printf("\nConvidado editado com sucesso!");
    }
    else{
        printf("\nOs dados do convidado não foram encontrados!\n\n");
    }
    
    fclose(arq);
    
    printf("\n\n");
    system("pause");
}

void excluir_convidado(TConvidado Con){
	FILE *arq;
	int del;
	
	system("cls");
	
	listar_convidado(Con);
	
	system("cls");
	
	arq = fopen("Convidados.txt","r+");
    if(arq == NULL){
        printf("\nErro ao acessar os dados dos convidado!");
        return;
    }
    
    printf("\nInforme o ID do convidado que deseja excluir: ");
    scanf("%d", &del);
    
    if(localizar_convidado(arq,del,Con)==1){
		Con.status = -1;
		Con.idcon = del;
		strcpy(Con.nome,Con.nome);
		strcpy(Con.cpf,Con.cpf);
		strcpy(Con.cel,Con.cel);
		strcpy(Con.email,Con.email);
		strcpy(Con.login,Con.login);
		strcpy(Con.password,Con.password);
        fwrite(&Con,sizeof(TConvidado),1,arq);
        printf("\nExclusão efetuada com sucesso!\n\n");
    }
    else{
        printf("\nOs dados do convidado não foram encontrados!\n\n");
    }
    
    fclose(arq);
    
    system("pause");
}

void listar_convidado(TConvidado Con){
	FILE *arq;
	
	system("cls");
	
	arq = fopen("Convidados.txt","r");
    if(arq==NULL){
        printf("\nErro ao acessar os dados dos convidados!");
        return;
    }
    printf("\n\t\t Convidados\n\n");
    fread(&Con, sizeof(TConvidado),1,arq);
    while(!feof(arq)){
    	if(Con.status > 0){
	    	printf("---------------------------------\n\n");
	    	printf("\tID: [%d]\n",Con.idcon);
		    printf("\tNome: %s\n",Con.nome);
		    printf("\tCPF: %s\n",Con.cpf);
		    printf("\tCel: %s\n",Con.cel);
		    printf("\tEmail: %s\n",Con.email);
			printf("\n---------------------------------\n");
		}
	    fread(&Con, sizeof(TConvidado),1,arq);	
	}
    fclose(arq);
    printf("\n\n");	
    system("pause");
}

void pesquisar_convidado(TConvidado Con){
	FILE *arq;
	int aux;
	char pesq[100];
	
	system("cls");
	
	printf("Informe o nome do convidado: ");
	fflush(stdin);
	gets(pesq);
	
	arq = fopen("Convidados.txt","r");
    if(arq==NULL){
        printf("\nErro ao acessar os dados dos convidados!");
        return;
    }

    fread(&Con, sizeof(TConvidado),1,arq);
    while(!feof(arq)){
    	if(strcmp(pesq,Con.nome) == 0){
	    	printf("---------------------------------\n\n");
	    	printf("\tID: [%d]\n",Con.idcon);
		    printf("\tNome: %s\n",Con.nome);
		    printf("\tCPF: %s\n",Con.cpf);
		    printf("\tCel: %s\n",Con.cel);
		    printf("\tEmail: %s\n",Con.email);
		    printf("\tLogin: %s\n",Con.login);
		    printf("\tSenha: %s\n",Con.password);
			printf("\n---------------------------------\n");
			aux = 1;
		}
	    fread(&Con, sizeof(TConvidado),1,arq);	
	}
    fclose(arq);
    
    if(aux!=1){
    	system("cls");
    	printf("Convidado não encontrado na base de dados!");
	}
    
    printf("\n\n");	
    system("pause");
}

int localizar_convidado(FILE *aux,int x,TConvidado Con){
	fread(&Con, sizeof(TConvidado), 1, aux);
    while(!feof(aux)){
        if(Con.idcon == x){
            fseek(aux,-sizeof(TConvidado),SEEK_CUR);
            return 1;
        }
        fread(&Con, sizeof(TConvidado), 1, aux);
    }
    return 0;
}

int menu_cliente(){
	int opc;
	system("cls");
	printf("\t\t****************************************************\n");
	printf("\t\t*******                 GLP                  *******\n");
	printf("\t\t****************************************************\n");
	printf("\t\t*******  1 - Gerenciar eventos               *******\n");
	printf("\t\t*******  2 - Gerenciar listas de presentes   *******\n");
	printf("\t\t*******  3 - Gerenciar listas de convidados  *******\n");
	printf("\t\t*******  0 - Retornar                        *******\n");
	printf("\t\t****************************************************\n");
	printf("\t\t****************************************************\n\n");
	printf("\t\tInforme a opção: ");
	scanf("%d",&opc);
	
	return opc;	
}

int verifica_cliente(TCliente Cli){
	FILE *arq;
	char login[10];
	char paswd[10];
	int idcli=0;
	
	system("cls");
	
	fflush(stdin);
	printf("Login: ");
	gets(login);
	printf("Senha: ");
	gets(paswd);
	
	arq = fopen("Clientes.txt","r");
    if(arq==NULL){
        printf("\nErro ao acessar os dados dos clientes!");
        return;
    }
    else{
		fread(&Cli, sizeof(TCliente), 1, arq);
	    while(!feof(arq)){
	        if((Cli.status > 0) &&(strcmp(Cli.login,login) == 0) && (strcmp(Cli.password,paswd) == 0)){
		        idcli = Cli.idcli;
	        }
	        fread(&Cli, sizeof(TCliente), 1, arq);
	    }
	}
	
	fclose(arq);
	
	return idcli;
}

int menu_listpre(){
	int opc;
	system("cls");
	printf("\t\t****************************************\n");
	printf("\t\t*******    LISTA DE PRESENTES   *******\n");
	printf("\t\t****************************************\n");
	printf("\t\t*******     1 - Criar            *******\n");
	printf("\t\t*******     2 - Listar           *******\n");
	printf("\t\t*******     0 - Retornar         *******\n");
	printf("\t\t****************************************\n");
	printf("\t\t****************************************\n\n");
	printf("\t\tInforme a opção: ");
	scanf("%d",&opc);
	
	return opc;	
}

void adicionar_listpre(int cliente,TListaPresente LPre){
	FILE *arq1;
	FILE *arq2;
	int ideve;
	
	system("cls");
	
	arq1 = fopen("Eventos.txt","r");
	
	if(arq1 == NULL){
		printf("\nErro ao abrir os dados do evento!\n\n");
        system("pause");
        return;
	}
	
	printf("Informe o ID do evento que deseja adicionar uma lista de presentes: ");
	scanf("%d",&ideve);
	
	TEvento Eve;
	
	if((localizar_evento(arq1,cliente,ideve,Eve)==1) && (localizar_listpre(ideve,0,LPre) == 0)){
		TProduto Pro;
		int idpro,opc=0;
		FILE *aux;
		
		fclose(arq1);
		
		do{
			listar_produto(Pro);
			
			printf("\nInforme o ID do produto que deseja adicionar: ");
			scanf("%d",&idpro);
			
			aux = fopen("Produtos.txt","r");
			if(aux == NULL){
				system("cls");
				printf("Erro ao abrir os dados dos produtos!\n\n");
		        system("pause");
        		return;
			}
			
			if(localizar_produto(aux,idpro,Pro)==1){
				
				arq2 = fopen("ListaPresentes.txt","r+");

				if(arq2 == NULL){
					printf("\nErro ao abrir os dados da lista!\n\n");
			        system("pause");
		        	return;
				}
				else{
					LPre.idpre = idpro;
					LPre.ideve = ideve;
			    	fwrite(&LPre,sizeof(TListaPresente),1,arq2);
			    	fclose(arq2);
				}
			}
			else{
				system("cls");
				printf("Produto não encontrado!\n\n");
				system("pause");
			}
			fclose(aux);
			
			system("cls");
			printf("Informe 1 para adicionar mais produtos, ou 0 para fechar a lista: ");
			scanf("%d",&opc);
	    }while(opc!=0);
    }
	else{
		system("cls");
		printf("Evento não encontrado!\n\n");
	}	
	
	system("pause");
}

void listar_listpre(int cliente, TListaPresente LPre){
	FILE *arq1;
	FILE *arq2;
	FILE *arq3;
	int ideve;
	
	TEvento Eve;
	
	system("cls");
	printf("Informe o ID do evento que deseja listar a Lista de Presentes: ");
	scanf("%d",&ideve);
	
	arq1 = fopen("Eventos.txt","r");
	
	if(arq1 == NULL){
		system("cls");
		printf("\nErro ao abrir os dados do evento!\n\n");
        system("pause");
        return;
	}
	
	if(localizar_evento(arq1,cliente,ideve,Eve)==1){
		TProduto Pro;
		
		system("cls");
		
		fread(&Eve, sizeof(TEvento),1,arq1);
    	while(!feof(arq1)){
	    	if(Eve.ideve == ideve){
		    	printf("---------------------------------\n\n");
				printf("\tNome: %s",Eve.descricao);
				printf("\tData: %s\n",Eve.data);
				printf("\tLocal: %s\n",Eve.local);
				printf("\n---------------------------------\n");
			}
	    	fread(&Eve, sizeof(TEvento),1,arq1);	
		}
		fclose(arq1);
		
		arq2 = fopen("ListaPresentes.txt","r");
		if(arq1 == NULL){
			system("cls");
			printf("\nErro ao abrir os dados da lista de presentes!\n\n");
	        system("pause");
        	return;
		}
		
		arq3 = fopen("Produtos.txt","r");
		if(arq1 == NULL){
			system("cls");
			printf("\nErro ao abrir os dados dos produtos!\n\n");
	        system("pause");
	        return;
		}
		
		fread(&LPre,sizeof(TListaPresente),1,arq2);
		while(!feof(arq2)){
			fread(&Pro,sizeof(TProduto),1,arq3);
			while(!feof(arq3)){
				if(LPre.ideve == ideve){
					if(LPre.idpre == Pro.idpro){
						printf("---------------------------------\n\n");
						printf("\tID: [%d]\n",Pro.idpro);
						printf("\tMarca: %s\n",Pro.marca);
						printf("\tDescrição: %s\n",Pro.descricao);
						printf("\tValor: %.2f\n",Pro.valor);
						printf("\n---------------------------------\n");
					}
					fread(&Pro,sizeof(TProduto),1,arq3);
				}
			}
			fread(&LPre,sizeof(TListaPresente),1,arq2);
		}	
		fclose(arq3);
		fclose(arq2);		
	}
	else{
		fclose(arq1);
		system("cls");
		printf("Evento não encontrado!\n\n");
	}
	
	system("pause");
}

int localizar_listpre(int x,int y,TListaPresente LPre){
	FILE *aux;
	
	aux = fopen("ListaPresentes.txt","r");
	if(aux == NULL){
	    printf("\nErro ao abrir os dados da lista!\n\n");
	    system("pause");
	    return;
	}
	
	if(y!=0){
		fread(&LPre, sizeof(TListaPresente),1,aux);
	    while(!feof(aux)){
	        if((LPre.ideve == x) && (LPre.idpre ==y)){
	            fseek(aux,-sizeof(TListaPresente),SEEK_CUR);
	            fclose(aux);
	            return 2;
	        }
	        fread(&LPre, sizeof(TListaPresente), 1, aux);
	    }
	}
	else{
		fread(&LPre, sizeof(TListaPresente),1,aux);
	    while(!feof(aux)){
	        if(LPre.ideve == x){
	            fseek(aux,-sizeof(TListaPresente),SEEK_CUR);
	            fclose(aux);
	            return 1;
	        }
	        fread(&LPre, sizeof(TListaPresente), 1, aux);
	    }
	}
	fclose(aux);
    return 0;
}
	
int menu_listcon(){
	int opc;
	system("cls");
	printf("\t\t***************************************\n");
	printf("\t\t******     LISTA DE CONVIDADOS    *****\n");
	printf("\t\t***************************************\n");
	printf("\t\t******       1 - Criar            *****\n");
	printf("\t\t******       2 - Listar           *****\n");
	printf("\t\t******       0 - Retornar         *****\n");
	printf("\t\t***************************************\n");
	printf("\t\t***************************************\n\n");
	printf("\t\tInforme a opção: ");
	scanf("%d",&opc);
	
	return opc;	
}


void adicionar_listcon(int cliente, TListaConvidado LCon){
	FILE *arq1;
	FILE *arq2;
	int ideve;
	
	system("cls");
	
	arq1 = fopen("Eventos.txt","r");
	
	if(arq1 == NULL){
		printf("\nErro ao abrir os dados do evento!\n\n");
        system("pause");
        return;
	}
	
	printf("Informe o ID do evento que deseja adicionar uma lista de convidados: ");
	scanf("%d",&ideve);
	
	TEvento Eve;
	
	if((localizar_evento(arq1,cliente,ideve,Eve)==1) && (localizar_listcon(ideve,0,LCon) == 0)){
		
		TConvidado Con;
		int idcon,opc=0;
		FILE *aux;
		
		fclose(arq1);
		
		do{
			listar_convidado(Con);
			
			printf("\nInforme o ID do convidado que deseja adicionar: ");
			scanf("%d",&idcon);
			
			aux = fopen("Convidados.txt","r");
			if(aux == NULL){
				system("cls");
				printf("Erro ao abrir os dados dos convidados!\n\n");
		        system("pause");
        		return;
			}
			
			if((localizar_convidado(aux,idcon,Con)==1) && (localizar_listcon(ideve,idcon,LCon)==0)){
				
				arq2 = fopen("ListaConvidados.txt","r+");

				if(arq2 == NULL){
					printf("\nErro ao abrir os dados da lista!\n\n");
			        system("pause");
		        	return;
				}
				else{
					LCon.idcon = idcon;
					LCon.ideve = ideve;
			    	fwrite(&LCon,sizeof(TListaConvidado),1,arq2);
			    	fclose(arq2);
				}
			}
			else{
				system("cls");
				printf("Convidado não encontrado!\n\n");
				system("pause");
			}
			fclose(aux);
			
			system("cls");
			printf("Informe 1 para adicionar mais convidados, ou 0 para fechar a lista: ");
			scanf("%d",&opc);
	    }while(opc!=0);
    }
	else{
		fclose(arq1);
		system("cls");
		printf("Evento não encontrado!\n\n");
		system("pause");
	}	
}

void listar_listcon(int cliente, TListaConvidado LCon){
	FILE *arq1;
	FILE *arq2;
	FILE *arq3;
	int ideve;
	
	TEvento Eve;
	
	system("cls");
	printf("Informe o ID do evento que deseja listar a Lista de Convidados: ");
	scanf("%d",&ideve);
	
	arq1 = fopen("Eventos.txt","r");
	
	if(arq1 == NULL){
		system("cls");
		printf("\nErro ao abrir os dados do evento!\n\n");
        system("pause");
        return;
	}
	
	if(localizar_evento(arq1,cliente,ideve,Eve)==1){
		TConvidado Con;
		
		system("cls");
		
		fread(&Eve, sizeof(TEvento),1,arq1);
    	while(!feof(arq1)){
	    	if(Eve.ideve == ideve){
		    	printf("---------------------------------\n\n");
				printf("\tNome: %s",Eve.descricao);
				printf("\tData: %s\n",Eve.data);
				printf("\tLocal: %s\n",Eve.local);
				printf("\n---------------------------------\n");
			}
	    	fread(&Eve, sizeof(TEvento),1,arq1);	
		}
		fclose(arq1);
		
		arq2 = fopen("ListaConvidados.txt","r");
		if(arq1 == NULL){
			system("cls");
			printf("\nErro ao abrir os dados da lista de convidados!\n\n");
	        system("pause");
        	return;
		}
		
		arq3 = fopen("Convidados.txt","r");
		if(arq1 == NULL){
			system("cls");
			printf("\nErro ao abrir os dados dos convidados!\n\n");
	        system("pause");
	        return;
		}
		
		fread(&LCon,sizeof(TListaConvidado),1,arq2);
		while(!feof(arq2)){
			fread(&Con,sizeof(TConvidado),1,arq3);
			while(!feof(arq3)){
				if(LCon.ideve == ideve){
					if(LCon.idcon == Con.idcon){
						printf("---------------------------------\n\n");
						printf("\tID: [%d]\n",Con.idcon);
					    printf("\tNome: %s\n",Con.nome);
					    printf("\tCPF: %s\n",Con.cpf);
					    printf("\tCel: %s\n",Con.cel);
					    printf("\tEmail: %s\n",Con.email);
						printf("\n---------------------------------\n");
					}
					fread(&Con,sizeof(TConvidado),1,arq3);
				}
			}
			fread(&LCon,sizeof(TListaConvidado),1,arq2);
		}	
		fclose(arq3);
		fclose(arq2);		
	}
	else{
		fclose(arq1);
		system("cls");
		printf("Evento não encontrado!\n\n");
	}
	system("pause");	
}

int localizar_listcon(int x,int y,TListaConvidado LCon){
	FILE *aux;
	
	aux = fopen("ListaConvidados.txt","r");
	if(aux == NULL){
	    printf("\nErro ao abrir os dados da lista!\n\n");
	    system("pause");
	    return;
	}
	
	if(y!=0){
		fread(&LCon, sizeof(TListaConvidado),1,aux);
	    while(!feof(aux)){
	        if((LCon.ideve == x) && (LCon.idcon == y)){
	        	fseek(aux,-sizeof(TListaConvidado),SEEK_CUR);
	        	fclose(aux);
	            return 2;
			}
	        fread(&LCon, sizeof(TListaConvidado), 1, aux);
	    }
	}
	else{
		fread(&LCon, sizeof(TListaConvidado),1,aux);
	    while(!feof(aux)){
	        if(LCon.ideve == x){
	            fseek(aux,-sizeof(TListaPresente),SEEK_CUR);
	            fclose(aux);
	            return 1;
	        }
	        fread(&LCon, sizeof(TListaConvidado), 1, aux);
	    }
	}
	fclose(aux);
    return 0;
}

int menu_evento(){
	int opc;
	system("cls");
	printf("\t\t************************************\n");
	printf("\t\t*****  MANUTENÇÃO DE EVENTOS  ******\n");
	printf("\t\t************************************\n");
	printf("\t\t*****      1 - Criar          ******\n");
	printf("\t\t*****      2 - Editar         ******\n");
	printf("\t\t*****      3 - Excluir        ******\n");
	printf("\t\t*****      4 - Listar         ******\n");
	printf("\t\t*****      0 - Retornar       ******\n");
	printf("\t\t************************************\n");
	printf("\t\t************************************\n\n");
	printf("\t\tInforme a opção: ");
	scanf("%d",&opc);
	
	return opc;	
}

void adicionar_evento(int cliente, TEvento Eve){
	FILE *arq;
	int ideve; 
	
	system("cls");
	
	arq = fopen("Eventos.txt","a+");
	if(arq == NULL){
        printf("\nErro ao abrir os dados dos eventos!\n\n");
        system("pause");
        return;
    }
    
    printf("\nInforme o codigo do evento: ");
    scanf("%d",&ideve);
    
    if(localizar_evento(arq,0,ideve,Eve)==1){
    	system("cls");
        printf("Esse evento ja está cadastrado!");
    }
    else{
    	system("cls");
    	fflush(stdin);
    	Eve.idcli = cliente;
    	Eve.ideve = ideve;
	    Eve.status = 1;
	    printf("\nDescrição: ");
		gets(Eve.descricao);
	    printf("\nLocal: ");
		gets(Eve.local);
		printf("\nData (DD/MM/AAAA): ");
		gets(Eve.data);
	    fwrite(&Eve,sizeof(TEvento),1,arq);
	    printf("\nEvento cadastrado com sucesso!");
    }
    fclose(arq);
    printf("\n\n");
    system("pause");
}

void editar_evento(int cliente,TEvento Eve){
	FILE *arq;
	int edit; 

	listar_evento(cliente,Eve);
	
    arq = fopen("Eventos.txt","r+");
    if(arq == NULL){
        printf("\nErro ao acessar os dados dos eventos!\n\n");
        system("pause");
        return;
    }
    
    system("cls");
    
    printf("\nInforme o ID do evento que deseja editar: ");
    scanf("%d", &edit);
    
    if(localizar_evento(arq,cliente,edit,Eve)==1){
    	system("cls");
    	fflush(stdin);
    	Eve.idcli = cliente;
		Eve.ideve = edit;
	    Eve.status = 1;
	    printf("\nDescrição: ");
		gets(Eve.descricao);
	    printf("\nLocal: ");
		gets(Eve.local);
		printf("\nData (DD/MM/AAAA): ");
		gets(Eve.data);
	    fwrite(&Eve,sizeof(TEvento),1,arq);
	    printf("\nEvento alterado com sucesso!");
    }
    else{
        printf("\nOs dados do evento não foram encontrados!\n\n");
    }
    
    fclose(arq);
    
    printf("\n\n");
    system("pause");
}

void excluir_evento(int cliente,TEvento Eve){
	FILE *arq;
	int del;
	
	system("cls");
	
	listar_evento(cliente,Eve);
	
	system("cls");
	
	arq = fopen("Eventos.txt","r+");
    if(arq == NULL){
        printf("\nErro ao acessar os dados dos eventos!\n\n");
        system("pause");
        return;
    }
    
    printf("\nInforme o ID do evento que deseja excluir: ");
    scanf("%d", &del);
    
    if(localizar_evento(arq,cliente,del,Eve)==1){
		Eve.idcli = cliente;
		Eve.ideve = del;
		Eve.status = -1;
		strcpy(Eve.descricao,Eve.descricao);
	    strcpy(Eve.local,Eve.local);
		strcpy(Eve.data,Eve.data);
        fwrite(&Eve,sizeof(TEvento),1,arq);
        printf("\nExclusão efetuada com sucesso!\n\n");
    }
    else{
        printf("\nOs dados do evento não foram encontrados!\n\n");
    }
    
    fclose(arq);
    
    system("pause");
}

void listar_evento(int cliente,TEvento Eve){
	FILE *arq;
	
	system("cls");
	
	arq = fopen("Eventos.txt","r");
    if(arq==NULL){
        printf("\nErro ao acessar os dados dos eventos!");
        return;
    }
    printf("\n\t\tEventos\n\n");
    fread(&Eve, sizeof(TEvento),1,arq);
    while(!feof(arq)){
    	if((Eve.status > 0) && (Eve.idcli == cliente)){
	    	printf("---------------------------------\n\n");
	    	printf("\tID: [%d]\n",Eve.ideve);
		    printf("\tNome: %s\n",Eve.descricao);
		    printf("\tLocal: %s\n",Eve.local);
		    printf("\tData: %s\n",Eve.data);
			printf("\n---------------------------------\n");
		}
	    fread(&Eve, sizeof(TEvento),1,arq);	
	}
    fclose(arq);
    printf("\n\n");	
    system("pause");
}

int localizar_evento(FILE *aux,int cliente,int x,TEvento Eve){
	
	if(cliente!=0){
		fread(&Eve, sizeof(TEvento), 1, aux);
	    while(!feof(aux)){
	        if((Eve.ideve == x) && (Eve.idcli == cliente)){
	            fseek(aux,-sizeof(TEvento),SEEK_CUR);
	            return 2;
	        }
	        fread(&Eve, sizeof(TEvento), 1, aux);
	    }
	}
	else{
		fread(&Eve, sizeof(TEvento), 1, aux);
	    while(!feof(aux)){
	        if(Eve.ideve == x){
	            fseek(aux,-sizeof(TEvento),SEEK_CUR);
	            return 1;
	        }
	        fread(&Eve, sizeof(TEvento), 1, aux);
	    }
	}
    return 0;
}

int menu_convidado(){
	int opc;
	system("cls");
	printf("\t\t*********************************************\n");
	printf("\t\t******        ÁREA DO CONVIDADO        ******\n");
	printf("\t\t*********************************************\n");
	printf("\t\t******    1 - Verificar evento         ******\n");
	printf("\t\t******    2 - Adquirir presente        ******\n");
	printf("\t\t******    0 - Retornar                 ******\n");
	printf("\t\t*********************************************\n");
	printf("\t\t*********************************************\n\n");
	printf("\t\tInforme a opção: ");
	scanf("%d",&opc);
	
	return opc;	
}

int verifica_convidado(TConvidado Con){
	FILE *arq;
	char login[10];
	char paswd[10];
	int idcon=0;
	
	system("cls");
	
	fflush(stdin);
	printf("Login: ");
	gets(login);
	printf("Senha: ");
	gets(paswd);
	
	arq = fopen("Convidados.txt","r");
    if(arq==NULL){
        printf("\nErro ao acessar os dados dos convidados!");
        return;
    }
    else{
		fread(&Con, sizeof(TConvidado), 1, arq);
	    while(!feof(arq)){
	        if((Con.status > 0) &&(strcmp(Con.login,login) == 0) && (strcmp(Con.password,paswd) == 0)){
		        idcon = Con.status;
	        }
	        fread(&Con, sizeof(TConvidado), 1, arq);
	    }
	}
	
	fclose(arq);
	
	return idcon;
}

void verifica_evento(int convidado,TEvento Eve){
	FILE *arq1;
	TListaConvidado LCon;
	int ideve=0;
	
	system("cls");
	
	arq1 = fopen("Eventos.txt","r");
    if(arq1==NULL){
        printf("Erro ao acessar os dados dos eventos!\n\n");
        system("pause");
        return;
    }
    printf("\n\t\tEventos\n\n");
    fread(&Eve, sizeof(TEvento),1,arq1);
    while(!feof(arq1)){
    	if(localizar_listcon(Eve.ideve,convidado,LCon)==2){
	    	printf("---------------------------------\n\n");
	    	printf("\tID: [%d]\n",Eve.ideve);
		    printf("\tNome: %s\n",Eve.descricao);
		    printf("\tLocal: %s\n",Eve.local);
		    printf("\tData: %s\n",Eve.data);
			printf("\n---------------------------------\n");
		}
	    fread(&Eve, sizeof(TEvento),1,arq1);	
	}
    fclose(arq1);
    printf("\n\n");	
    system("pause");
	
}

void adquirir_presente(int convidado,TListaFinal LFim){
	FILE *arq1;
	FILE *arq2;
	FILE *arq3;
	
	TEvento Eve;
	TListaPresente LPre;
	TListaConvidado LCon;
	int ideve=0;
	int idpro=0;
	
	verifica_evento(convidado,Eve);
	
	printf("Informe o ID do evento que deseja adquirir um presente: ");
	scanf("%d",&ideve);
	
	system("cls");
	
	if((localizar_listpre(ideve,0,LPre)==1) && (localizar_listcon(ideve,convidado,LCon)==2)){
		
		arq2 = fopen("ListaPresentes.txt","r");
		if(arq1 == NULL){
			system("cls");
			printf("\nErro ao abrir os dados da lista de presentes!\n\n");
	        system("pause");
        	return;
		}
		
		arq3 = fopen("Produtos.txt","r");
		if(arq1 == NULL){
			system("cls");
			printf("\nErro ao abrir os dados dos produtos!\n\n");
	        system("pause");
	        return;
		}
		
		TProduto Pro;
		
		fread(&LPre,sizeof(TListaPresente),1,arq2);
		while(!feof(arq2)){
			fread(&Pro,sizeof(TProduto),1,arq3);
			while(!feof(arq3)){
				if(LPre.ideve == ideve){
					if(LPre.idpre == Pro.idpro){
						printf("---------------------------------\n\n");
						printf("\tID: [%d]\n",Pro.idpro);
						printf("\tMarca: %s\n",Pro.marca);
						printf("\tDescrição: %s\n",Pro.descricao);
						printf("\tValor: %.2f\n",Pro.valor);
						printf("\n---------------------------------\n");
					}
					fread(&Pro,sizeof(TProduto),1,arq3);
				}
			}
			fread(&LPre,sizeof(TListaPresente),1,arq2);
		}	
		fclose(arq3);
		fclose(arq2);	
		
		printf("Informe o ID do presente que deseja adicionar: ");
		scanf("%d",&idpro);
		
		if(localizar_listpre(ideve,idpro,LPre)==2){
			
			arq1 = fopen("ListaFinal.txt","a+");
			if(arq1==NULL){
				printf("\nErro ao acessar os dados da lista\n\n!");
				system("pause");
	        	return;
			}
			else{
				LFim.ideve = ideve;
				LFim.idcon = convidado;
				LFim.idpre = idpro;
				fwrite(&LFim,sizeof(TListaFinal),1,arq1);	
			}
		}
	}
	
	fclose(arq1);
	system("pause");
	
}

int menu_relatorio(){
	int opc;
	system("cls");
	printf("\n\n\t\t************************************\n");
	printf("\t\t******          GLP            *****\n");
	printf("\t\t************************************\n");
	printf("\t\t******  1 - Gerar Lista Final  *****\n");
	printf("\t\t******  2 - Listar             *****\n");
	printf("\t\t******  3 - Ordenar            *****\n");
	printf("\t\t******  0 - Sair               *****\n");
	printf("\t\t************************************\n");
	printf("\t\t************************************\n\n");
	printf("\t\tInforme a opção: ");
	scanf("%d",&opc);
	
	return opc;	
}
