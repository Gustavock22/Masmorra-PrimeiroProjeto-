#include <stdio.h>
#include <windows.h> 
#include <conio.h>
#include <locale.h> 
#include <ctype.h>  
#include "structs.h"
#include "define.h"

int botao1 = 0;
int botao2 = 0;





void delay(int segundos) {
    Sleep(segundos * 1000);
}

void setCorTexto(int cor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);
}

void apagartexto() {
    system("cls");
}

void paraMinusculo(char texto[]) {
    for (int i = 0; texto[i] != '\0'; i++) {
        texto[i] = tolower(texto[i]);
    }
}

void MenuPrincipal(){
	printf("\t -------------------------------------\n");
	printf("\t| EXPLORADOR SUPREMO DE MASMORRA SOLO |\n");
	printf("\t -------------------------------------\n\n");
	
	printf("\t\t     --------------\n");
	printf("\t\t    |   1-JOGAR    |\n");
	printf("\t\t     --------------\n");

	printf("\t\t     --------------\n");
	printf("\t\t    |    2-SAIR    |\n");
	printf("\t\t     --------------\n\n");
	printf("Escolha alguma dessas opções para seguir em frente, *deve ser o número que aparece a frente de cada opção*\n");
}

void MenuDuranteJogo(){
	printf("\n[Controles: W/A/S/D = mover, i = inventário, q = sair]\n");
}

void ExplicandoJogo() {
    printf("...\n");
    delay(1);
    printf("Você está me ouvindo?\n");
    delay(2);
    printf("Ótimo. Finalmente você acordou.\n");
    delay(2);
    printf("Me chamo Kairon... o Deus do Tempo.\n");
    delay(2);
    printf("E... bem...\n");
    delay(2);
    printf("Aparentemente eu... *acidentalmente* te atropelei com um dragão do tempo.\n");
    delay(3);
    printf("Foi um erro no espaço-tempo. Juro que não foi pessoal!\n");
    delay(2);
    printf("Enfim... agora você está tecnicamente morto no seu mundo original.\n");
    delay(3);
    printf("Mas, como compensação divina, eu preparei algo especial pra você...\n");
    delay(2);
    printf("Você renascerá em um novo mundo...\n");
    delay(2);
    printf("Com poderes, desafios, e claro... uma MASMORRA INFERNAL pra começar a vida nova!\n");
    delay(3);
    printf("Se conseguir sair de lá com vida, você terá habilidades que nem os deuses ousam carregar.\n");
    delay(3);
    printf("É justo, né?\n");
    delay(2);
    printf("Ah, claro. Antes de começar sua aventura, deseja ouvir as instruções de como sobreviver? Sim ou Não\n");
}

void instrucaoKairon(){
	apagartexto();
	Responder opcao;
	opcao.resposta = 0;
	
	do{
		printf("Para se movimentar você usará W(cima), A(esquerda), S(baixo) e D(direita)\n");
		delay(3);
		printf("A masmorra terá 3 fases, você terá que aguentar...\n");
		delay(2);
		printf("Agora preste muita atenção!\n");
		delay(2);
		printf("# -> representa as paredes,\n. -> representa os lugares que você pode ir\n");
		printf("P -> representa você mesmo,\n] -> representa baús,\nS -> representa saida\n");
		printf("- representa portões,\nT -> representa árvores,\nB -> representa botões\n");
		delay(2);
		printf("i -> para abrir o inventário,e caso você não saiba como usar certo item\n");
		printf("no inventário tem a tecla específica para usar o item ao lado dele\n\n ");
		delay(3);
		printf("Você entendeu o que eu disse?(1 = Sim) ou (2 = Não)\n");
		printf("RESPOSTA: ");
		scanf("%d", &opcao.resposta);
		int c;
        while ((c = getchar()) != '\n' && c != EOF);
		
		if(opcao.resposta > 2 ||opcao.resposta < 1){
			printf("*KAIRON* Apenas 1 para SIM e 2 para NÃO");
			delay(2);
			apagartexto();
			
		}
		if(opcao.resposta == 1){
			printf("Ótimo! Boa sorte!\n");
			delay(2);
			printf("Estou te enviando para a masmorra...");
			delay(4);
		}else if(opcao.resposta == 2){
			apagartexto();
			printf("Então vou repetir...\n");
			delay(2);
			continue;
		}
	}while(opcao.resposta != 1);
	
}

void OuvirExplicacao() {
    char resposta[TAMANHO_RESPOSTA];
    Responder opcao;

    while (1) {
        opcao.resposta = 0;

        printf("\nRESPOSTA-> ");
        scanf("%s", resposta);

        paraMinusculo(resposta);

        for (int i = 0; resposta[i] != '\0'; i++) {
            if (isdigit(resposta[i])) {
                opcao.resposta++;
            }
        }

        if (strlen(resposta) > 5) {
            opcao.resposta++;
        }

        if (opcao.resposta > 0) {
            printf("*KAIRON* Você não pode colocar números ou frases malucas. Responda apenas com 'sim' ou 'nao'.\n");
            delay(3);
            
            continue;
        }
    	if (strcmp(resposta, "sair") == 0){
    		printf("Saindo do jogo...");
    		delay(2);
    		exit(0);
		}
    
        if (strcmp(resposta, "sim") == 0) {
            printf("*KAIRON* Você é inteligente, então prepare-se e preste muita atenção...\n");
            delay(2);
            break;
        } else if (strcmp(resposta, "nao") == 0) {
            printf("*KAIRON* Hmph! Vamos ver por quanto tempo você ficará vivo...\n");
            delay(2);
            break;
        } else {
            printf("*KAIRON* Eu não entendi... diga apenas 'sim' ou 'nao'.\n");
            delay(2);
        }
    }
}

void SaindoMasmorra(){
	printf("Você abre a porta e consegue escapar da masmorra!\n");
	delay(3);
	printf("FIM ");
	delay(1);
	printf("DE ");
	delay(1);
	printf("JOGO");
	delay(1);
}


void creditos() {
    apagartexto();
    printf("========================================\n");
    printf("             CREDITOS FINAIS            \n");
    printf("========================================\n\n");
    delay(1);

    printf("Programador Chefe............. Gustavo\n"); 
	delay(1.5);
    printf("Roteirista Principal.......... Gustavo\n"); 
	delay(1.5);
    printf("Diretor Criativo.............. Gustavo\n"); 
	delay(1.5);
    printf("Designer de Personagens....... Gustavo\n"); 
	delay(1.5);
    printf("Designer de Niveis............ Gustavo\n");
	delay(1.5);
    printf("Engenheiro de Som............. Gustavo\n");
	delay(1.5);
    printf("Produtor Executivo............ Gustavo\n");
	delay(1.5);
    printf("Testes de Qualidade........... Gustavo\n"); 
	delay(1.5);
    printf("Marketing e Divulgação........ Gustavo\n"); 
	delay(1.5);
    printf("Suporte Técnico............... Gustavo\n"); 
	delay(1.5);
    printf("Patrocinador Oficial.......... Gustavo\n"); 
	delay(1.5);
    printf("Inspiração.................... Gustavo\n"); 
	delay(2);
	printf("\n========================================\n");
    printf("        Obrigado por jogar! :D\n");
    printf("========================================\n");

    printf("\nPressione ENTER para sair...");
    getchar();
    
}


void Mapa1(char mapa[][9]) {
    char preenchido[8][9] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', 'P', '.', '.', '#', '.', '.', '.', '#'},
        {'#', '.', '#', '.', '#', '.', '#', '.', '#'},
        {'#', '.', '#', '.', '.', '.', '#', '.', '#'},
        {'#', '.', '#', '#', '#', '.', '#', '.', '#'},
        {'#', '.', '.', '.', '#', '.', '.', '.', '#'},
        {'#', '#', '#', ']', '#', '#', '#', 'S', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 9; j++) {
            mapa[i][j] = preenchido[i][j];
        }
    }
}

void Mapa2(char mapa[][9]) {
    char preenchido[8][9] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '.', '.', '.', '#', '.', 'P', '.', '#'},
        {'#', '.', 'T', '.', 'T', '.', '#', '.', '#'},
        {'#', '.', '#', '.', '.', '.', '#', '.', '#'},
        {'#', '.', '#', '#', '#', '.', '#', 'T', '#'},
        {'#', '.', '.', '.', '#', '.', 'T', 'T', '#'},
        {'#', 'T', 'T', ']', '#', '#', 'T', 'S', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 9; j++) {
            mapa[i][j] = preenchido[i][j];
        }
    }
}

void Mapa3(char mapa[][9]) {
    char preenchido[8][9] = {
        {'#','#','#','#','#','#','#','#','#'},
        {'#','P','.','.','#','.','T','B','#'},
        {'#','.','#','.','#','T','.','T','#'},
        {'#','.','#','.','.','.','#','.','#'},
        {'#','.','#','#','#','.','#','.','#'},
        {'#','.','T','T','.','-','.','-','#'},
        {'#','#','#','B','#',']','#','S','#'},
        {'#','#','#','#','#','#','#','#','#'}
    };

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 9; j++) {
            mapa[i][j] = preenchido[i][j];
        }
    }
}


Inventario layoutInv(Inventario inv) {
    setCorTexto(11);
    printf("\n======= INVENTÁRIO =======\n");
    setCorTexto(7); 
    
    int vazio = 1;
    
    for (int i = 0; i < TAMANHO_INV; i++) {
        if (inv.Inv[i] != 0) {
            vazio = 0;
            setCorTexto(14);
            printf("[%02d] ", i + 1);
            
            switch (inv.Inv[i]) {
                case CORDA: printf("Corda\n"); break;
                case MACHADO: printf("Machado -'m'\n"); break;
                case CHAVE_MESTRA: printf("Chave Mestra"); break;
                default: printf("Item desconhecido\n"); break;
            }
        }
    }

    if (vazio) {
        setCorTexto(8);
        printf("(Inventário vazio)\n");
    }

    printf("\nPressione qualquer tecla para voltar.\n");
    getch();

    setCorTexto(7);
    printf("==========================\n");

    return inv;
}

void mostrarMapa(char mapa[][9], int linhas, int colunas) {
    apagartexto();

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            char c = mapa[i][j];

            switch (c) {
            case '#': setCorTexto(8); break;
            case '.': setCorTexto(14); break;
            case 'P': setCorTexto(11); break;
            case 'S': setCorTexto(12); break;
            case ']': setCorTexto(5); break;
            case 'T': setCorTexto(2); break;
            case 'B': setCorTexto(15); break;
            case '-': setCorTexto(6); break;
            default:  setCorTexto(7); break;
            }

            printf("%c ", c);
        }
        printf("\n");
    }

    setCorTexto(7);
}

Posicao encontrarJogador(char mapa[][9], int linhas, int colunas) {
    Posicao pos;
    pos.x = -1;
    pos.y = -1;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (mapa[i][j] == 'P') {
                pos.x = i;
                pos.y = j;
                return pos;
            }
        }
    }
    return pos;
}

Inventario Itens(Inventario inv, char mapa[][9], int JogadorPosX, int JogadorPosY ){
	 if (mapa[JogadorPosX][JogadorPosY] == ']') {
                printf("\nVocê encontrou um baú!!\n");
                delay(2);
                if (inv.Inv[0] != CORDA) { 
                    printf("Jogador encontrou CORDA!!\n");
                    delay(2);
                    inv.Inv[0] = CORDA;
                } else if (inv.Inv[1] != MACHADO) { 
                    printf("Jogador encontrou MACHADO!!\n");
                    delay(2);
                    inv.Inv[1] = MACHADO;
                } else if (inv.Inv[2] != CHAVE_MESTRA) {
                    printf("Você achou a CHAVE MESTRA!\n");
                    delay(2);
                    inv.Inv[2] = CHAVE_MESTRA;
                }
                delay(2);
            }
            return inv;
}

void atualizarMapa(char mapa[][9], int jogadorX, int jogadorY, int JogadorPosX, int JogadorPosY) {
    mapa[jogadorX][jogadorY] = '.';
    mapa[JogadorPosX][JogadorPosY] = 'P';
}


Inventario jogar(char mapa[][9], int linhas, int colunas, Inventario inv) {
    int cont = 0;
    Posicao jogador = encontrarJogador(mapa, linhas, colunas);
    Responder decisao;

    mostrarMapa(mapa, linhas, colunas);
    
    MenuDuranteJogo();
    
	if (cont == 0) {
	    printf("\nEssa é a primeira sala, mas parece que não tem muita coisa aqui.\n");
		}
	    
    while (1) {
        char tecla = getch();

        if (tecla == 'q') {
            break;
        }

        if (tecla == 'i') {
            apagartexto();
            inv = layoutInv(inv);
            mostrarMapa(mapa, linhas, colunas);
            MenuDuranteJogo();
            continue;
        }

        if (tecla == 'm') {
            if (inv.Inv[1] == MACHADO) {
                int encontrouArvore = 0;
                int dx[] = {-1, 1, 0, 0};
                int dy[] = {0, 0, -1, 1};
                
                for (int i = 0; i < 4; i++) {
                    int ax = jogador.x + dx[i];
                    int ay = jogador.y + dy[i];
                    if (ax >= 0 && ax < linhas && ay >= 0 && ay < colunas) {
                        if (mapa[ax][ay] == 'T') {
                            mapa[ax][ay] = '.';
                            encontrouArvore = 1;
                        }
                    }
                }

                if (encontrouArvore) {
                    printf("Você derrubou uma árvore e limpou o caminho!\n");
                } else {
                    printf("Não há árvores perto para cortar.\n");
                }
            } else {
                printf("Você não tem um machado para cortar árvores.\n");
            }
            delay(2);
            mostrarMapa(mapa, linhas, colunas);
            MenuDuranteJogo();
            continue;
        }

        int JogadorPosX = jogador.x;
        int JogadorPosY = jogador.y;

        switch (tecla) {
            case 'w': JogadorPosX = jogador.x - 1; break;
            case 's': JogadorPosX = jogador.x + 1; break;
            case 'a': JogadorPosY = jogador.y - 1; break;
            case 'd': JogadorPosY = jogador.y + 1; break;
            default: continue;
        }

        if ((JogadorPosX >= 0 && JogadorPosX < linhas && JogadorPosY >= 0 && JogadorPosY < colunas && mapa[JogadorPosX][JogadorPosY] != '#') && 
            (JogadorPosX >= 0 && JogadorPosX < linhas && JogadorPosY >= 0 && JogadorPosY < colunas && mapa[JogadorPosX][JogadorPosY] != 'T') &&
			(JogadorPosX >= 0 && JogadorPosX < linhas && JogadorPosY >= 0 && JogadorPosY < colunas && mapa[JogadorPosX][JogadorPosY] != '-')){

            if (mapa[JogadorPosX][JogadorPosY] == 'S' && cont < 2) {
                int respostaValida = 0;
                while (!respostaValida) {
                    printf("\nVocê chegou em uma parte em que a subida é muito alta!\n");
                    delay(2);
                    printf("A saída para a próxima sala é logo ali!\n");
                    delay(2);
                    printf("Aperte 1 para usar a corda: ");
                    scanf("%d", &decisao.resposta);
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF);

                    if (decisao.resposta == 1) {
                        respostaValida = 1;
                        if (inv.Inv[0] != CORDA) {
                            printf("O Jogador não possui CORDA ainda...\n");
                            delay(2);
                            break;
                        } else {
                            printf("O Jogador prende a corda, sobe e chega na outra sala!\n");
                            delay(3);

                            if (cont == 0) { 
							    cont++;
							    Mapa2(mapa);
							    jogador = encontrarJogador(mapa, linhas, colunas);
							    mostrarMapa(mapa, linhas, colunas);
							    printf("Olha, parece que tem árvores aqui. Será que podemos derrubá-las?\n");
							} else if (cont == 1) { 
							    cont++;
							    Mapa3(mapa);
							    jogador = encontrarJogador(mapa, linhas, colunas);
							    mostrarMapa(mapa, linhas, colunas);
							    printf("Parece que essa é mais complicada. Tem portões bloqueando a passagem e parece que há botões escondidos.\n");
							}
                        }
                    } else {
                        printf("Resposta inválida. Apenas aperte 1 para usar a corda.\n");
                        delay(2);
                    }
                }
                continue;
            }
            
	        if (mapa[JogadorPosX][JogadorPosY] == 'B') {
			    printf("\nVocê encontrou um botão...\n");
			    delay(2);
			    printf("Acione o botão, aperte 1: ");
			    scanf("%d", &decisao.resposta);
			    int c;
			    while ((c = getchar()) != '\n' && c != EOF);
			    
			    if(decisao.resposta != 1){
			    	printf("\nVocê não ativou o botão...\n");
			    		JogadorPosX = jogador.x;
    					JogadorPosY = jogador.y;
				}
			
			    if (decisao.resposta == 1) {
			        if (JogadorPosX == 6 && JogadorPosY == 3) { 
			            botao1++;
			            delay(1);
			            printf("\nVocê acionou o botão 1\n");
			            if(botao2 == 0){
			            	printf("Falta apenas 1 botão\n");
						}else{
							printf("Não falta mais nenhum botão\n");
						}
			            delay(2);
			        } else if (JogadorPosX == 1 && JogadorPosY == 7) {
			            botao2++;
			            delay(1);
			            printf("\nVocê acionou o botão 2\n");
			            if(botao1 == 0){
			            	printf("Falta apenas 1 botão\n");
						}else{
							printf("Não falta mais nenhum botão\n");
						}
			            delay(3);
			        }
			    }
			}

					
			if(botao1 == 1 && botao2 == 1){
				printf("\nVocê acionou todos os botões\n");
				delay(2);
				printf("Abrindo todos os portões!\n");
				delay(3);
				
				mapa[5][5] = '.';
				mapa[5][7] = '.';
				
				botao1 = 0;
    			botao2 = 0;
    			
    			
			}
			
			if(cont == 2){
				if (mapa[JogadorPosX][JogadorPosY] == 'S'){
					printf("\nVocê está diante da porta de saída da masmorra\n");
					delay(2);
					printf("Para abri-la é necessário a CHAVE MESTRA!\n");
					delay(2);
					
					if(inv.Inv[2] != CHAVE_MESTRA){
						printf("Porém, você não a possui ainda...\n");
						delay(2);
						JogadorPosX = jogador.x;
    					JogadorPosY = jogador.y;
						
					}else{
						printf("E você a possui!\n");
						delay(1);
						printf("Bravo guerreiro, para abrir a porta clique no 1: ");
						scanf("%d", &decisao.resposta);
						int c;
						while ((c = getchar()) != '\n' && c != EOF);
						
						if(decisao.resposta == 1){
							apagartexto();
							SaindoMasmorra();
							creditos();
							exit(0);
						}else{
							printf("O jogador tenta abrir a porta porém não consegue...\n");
							delay(2);
							printf("Clique apenas no 1 para abrir a porta...\n");
							JogadorPosX = jogador.x;
    						JogadorPosY = jogador.y;
							mostrarMapa(mapa, linhas, colunas); 
    						MenuDuranteJogo();
						}
                  
   
						
					}
				}
			}
            

            inv = Itens(inv,mapa, JogadorPosX, JogadorPosY );

          	atualizarMapa(mapa, jogador.x, jogador.y, JogadorPosX, JogadorPosY);

            jogador.x = JogadorPosX;
            jogador.y = JogadorPosY;
        }

        mostrarMapa(mapa, linhas, colunas);
        MenuDuranteJogo();
    }


    printf("Jogo finalizado.\n");
    delay(2);
    exit(0);

    return inv; 
}

void historinhaJogo(){
	ExplicandoJogo();
	OuvirExplicacao();
	instrucaoKairon();
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    Responder opcao;

    Inventario adicionar = {0};
    char mapa[8][9];
    int linhas = 8, colunas = 9;

    Mapa1(mapa);
    do{
    	
		MenuPrincipal();
		printf("ESCOLHA-> ");
		scanf("%d", &opcao.resposta);
	
		if(opcao.resposta < 1 || opcao.resposta > 2){
			apagartexto();
			printf("Use apenas 1 ou 2...\n");
			continue;
		}
		
		
		if(opcao.resposta == 1){
			printf("Iniciando jogo...");
			delay(2);
			apagartexto();
			historinhaJogo();
			adicionar = jogar(mapa, linhas, colunas, adicionar);
		}else if(opcao.resposta == 2){
			printf("Finalizando jogo...");
			break;
		}
    	
	}while(opcao.resposta != 2);
	
   

    return 0;
}

