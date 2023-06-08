#include <conio.h>  // para utilizar a função de parada getch
#include <time.h> // para sortear
#include <iostream>   //escrever os códigos em c++
using namespace std;

#define l 5     //define a quantidade de linha da matriz
#define c 5     //define a quantidade de coluna da matriz

//declaração de funçoes
//as funcões completas estão após o int main
void imprimeMenu();         //imprime o menu principal, de início (novo jogo,sobre o jogo,entre outros)
void imprimeMenuNivel();       //imprime os níveis do jogo para o usuário escolher qual ele quer jogar
void imprimecm(char cm[l][c]);      //imprime a matriz do campo minado
void imprimeaux(char aux[l][c]);    //imprime a matriz auxiliar, on de o jogador faz as suas jogadas
int verificaIgualdade(char aux[l][c], char cm[l][c], int linha, int coluna);    //verifica se onde o usuário jogou tem bomba ou mina

int main()
{   setlocale(LC_ALL, "Portuguese");    //biblioteca do programa entender português , acentos e afins
	char cm[l][c], aux[l][c];           // 0 para campo limpo; B para minas
    int s=0, igual=0, linha=0,coluna=0, acertos=0;      //s= sorteio das bombas
    unsigned seed=time(0);
    srand(seed);
    int opcao,opcao2;       //ler as opções dos 2 menus
    string nome;            // ler o nome do usuário
    int minas=0;            //quantidade de minas que vai ter no nível, cada nível tem uma quantidade definida, por isso declarei a variável com 0
    char jn;                // caso o usuário queira jogar novamente ou ao menos voltar ao menu do jogo


	cout << "\t\t\t\t\tSEJA BEM-VINDO(A) AO CAMPO MINADO\t\t\t\t\t" << endl << endl;        //boas vindas ao jogo
    do{        // condição do switch case do primeiro menu, se caso o usuário digitar um número inválido
    imprimeMenu();    //impressão do menu principal
    cout << endl << endl;    //quebra linha
    cout << "Digite a opção desejada: ";  //pede o usuário para escolher uma opção do menu
    cin >> opcao;       //programa ler a opção que o usuário digitou
    system("cls");     //limpa a tela

    cout << "\t\t\t\t\t*****CAMPO MINADO*****\t\t\t\t\t" << endl << endl;       //nome do jogo
    switch(opcao){
    case 1:     //caso o usuário escolha novo jogo
    cout << "Digite teu nome: ";        //pedi para o usuário digitar o seu nome
    cin >> nome;        //programa lê o nome
    system("cls");      //limpar a tela

    cout << "\n\n\t\t" << nome << ",escolha o nível que deseja jogar: " << endl << endl << endl;    //pergunta o usuário qual nível ele quer jogar
    imprimeMenuNivel();     //imprime o menu de nível e mostra ao usuário

    cout << "\n\nDigite o nível que deseja jogar(1,2,3,4): ";       //usuário digita o nível que deseja
    cin >> opcao2;      //programa lê o nível que o usuário digitou
    system("cls");      //limpa a tela

    if(opcao2 > 1 || opcao2 <4 ){       //validando caso o usuário digite um número inválido
        if(opcao2 == 1){    //primeiro nível
		cout << "Nivel Iniciante, há 3 minas no tabuleiro \n\n";    //informa o usuário quantas minas há no tabuleiro
		minas = 3;      //quantidade de minas
		system("pause");        //pausa para o usuário ler o cout
        system ("cls");     //limpa a tela
	}
    else if(opcao2 == 2){   //segundo nível
        cout << "Nivel Fácil, há 6 minas no tabuleiro \n\n";     //informa o usuário quantas minas há no tabuleiro
        minas = 6; //quantidade de minas
        system("pause");    //pausa para o usuário ler o cout
        system ("cls");      // limpa a tela
    }
    else if (opcao2 == 3){  //terceiro nível
        cout << "Nivel Intermediário, há 9 minas no tabuleiro \n\n"; //informa o usuário quantas minas há no tabuleiro
        minas = 9;  //quantidade de minas
        system("pause");    //pausa para o usuário ler o cout
        system ("cls");      // limpa a tela
    }

    else{       //executa o último nível
        cout << "Nivel Difícil, há 3 minas no tabuleiro \n\n"; ////informa o usuário quantas minas há no tabuleiro
        minas = 12; //quantidade de minas
        system("pause");   //pausa para o usuário ler o cout
        system ("cls"); // limpa a tela
        }
    }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Inicializa Campo Minado
    for (int i=0; i<l; i++) {
        for (int j=0; j<c; j++) {
            cm[i][j] = '0';
            aux[i][j] = ' ';    //matriz auxiliar, pode ser adicionada separadamente, mas, encurta código colocando junto a principal
        }
    }

    // Sorteio das minas
    for (s=1; s<=minas; s++) { // cada nível uma quantidade de minas, então sorteará quantidades diferentes e minas
        cm[rand()%l][rand()%c] = 'B';   //quando encontrar a bomba irá aparecer um B
    }

    while (igual != 0 || acertos < 3) {         //em 3 jogadas, se o usuário não jogar em bomba, ganhará, caso contrário, perderá
        system("cls");      //limpa a tela
        imprimeaux(aux);        //começa a colocar em prática as jogadas com a matriz auxiliar
        cout << "\nQuantidade de jogadas que você acertou: " << acertos << endl;      //jogadas que o usuário acertou
        cout << "\nInforme a linha: ";        //linha que o usuário quer jogar
        cin >> linha;       //programa le a linha
        cout << "\nInforme a coluna: ";         //coluna que o usuário quer jogar
        cin >> coluna;      //programa le a coluna
        aux[linha][coluna] = '0';       //caso o usuário nn acerte bomba, aparecerá o 0
        igual = verificaIgualdade(aux, cm, linha, coluna); // 1 campo limpo, 0 encontrou uma mina

        if (igual == 0) {
            cout << "Encontrou uma mina\n\n";
            cout << "     VOCÊ PERDEU       \n\n";  // caso o usuário acerte uma mina, ele perderá
            break;  //para de executar o programa
        } else {
            cout << "Campo limpo."; // usuário continua jogando, pois não acertou a mina
            acertos+=1;     // continuação do jogo
        }
        if (acertos == 3) {
            cout << "\n\nVOCÊ GANHOU, MANDOU BEM!!!";   //jogou 3 vezes e não encontrou nenhuma mina, ganhou o jogo
            break;  //para de executar o programa
        }
    }
    system("pause");        //pausa para o usuário ler os cout
    system("cls");          //limpa a tela
    cout << "\n\t\tAgora, veja onde estavam todas as bombas: \n\n";     //mostra ao usuário onde estavam as bombas, independente se ele ganhou ou perdeu, sempre irá mostrar
    imprimecm(cm);      //mostrando na matriz onde estavam as bombas

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    cout << "\n\nDeseja jogar novamente (s/n)? ";       //caso o usuário deseje jogar novamente
    cin >> jn;      //ler se o usuário deseja ou não jogar novamente
    switch(jn){     //executando o que o usuário desejou
    case 's':       //caso ele queira jogar novamente
        main();         //irá voltar ao menu principal e repitirá o processo
    getch();        //parada
    break;      //parando de executar o case
    case 'n':       //caso o usuário deseja parar de jogar
        return 0;       //saindo do jogo
    getch();        //parada
    break;      //para de executar o case
    system("cls");      //limpa a tela
    }
    break;      //para o case 1 aberto dentro do menu principal, novo jogo

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    case 2:     // segundo caso do menu principal
    system("cls");      //limpa  a tela
    //mostrando ao usuário como funciona o jogo
    cout << "O Campo Minado é um jogo aparentemente simples de memória e raciocínio";
    cout << "O objetivo do Campo Minado é revelar os quadrados vazios e com números,evitando aqueles que escondem bombas";
    cout << "Você pode revelar o que existe em um quadrado, ditando a linha e a coluna. Se você revelar uma bomba, voce perdera";

    cout << "\n\nAgora que ja sabe um pouco sobre o jogo, deseja jogar?"; // caso o usuário queira jogar depois da informação sobre o jogo
    cin >> jn;      //ler se o usuário deseja ou não jogar
    switch(jn){     //executando o que o usuário desejou
    case 's':       //caso ele queira jogar novamente
        main();         //irá voltar ao menu principal e repitirá o processo
    getch();        //parada
    break;      //parando de executar o case
    case 'n':       //caso o usuário deseja parar de jogar
        return 0;       //saindo do jogo
    getch();        //parada
    break;      //para de executar o case
    system("cls");      //limpa a tela
    }
    break;      //para o case 1 aberto dentro do menu principal, novo jogo

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    case 3:     //terceiro caso do menu principal
    system("cls");      //limpa a tela
    cout << "Jogo criado por Samyra Giovana, 18. Aluna do curso SI-IFMG (Sistemas de Informação)";      //informações sobre quem criou o jogo
    break;      //para de executar o case

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    case 4:     //quarto caso do menu principal
    system("cls");      //limpar a tela
    cout << "Volte sempre\n";       //mensagem exibida se usuário escolher sair
    break;      //para de executar o case

    default: cout << "Opcao invalida\n";        //caso a opção digitada seja inválida
    system("pause");        //pausa para o usuário ler
    system("cls");      //limpa a tela
    }
    }while (opcao<1 || opcao>4);        //caso seja opção inválida voltará ao menu novamente
    system("pause");        //pausa para o usuário ler,ver
    return 0;       //fecha o programa
    }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  void imprimeMenu() {          //função que contém o menu principal
    cout << " +-+-+-+-Campo Minado-+-+-+-+\n";
    cout << " |                         |\n";
    cout << " |      MENU PRINCIPAL     |\n";
    cout << " |                         |\n";
    cout << " | (1) Novo Jogo           |\n";
    cout << " | (2) Sobre o jogo        |\n";
    cout << " | (3) Sobre o criador     |\n";
    cout << " | (4) Sair                |\n";
    cout << " |                         |\n";
    cout << " +-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void imprimeMenuNivel() {           //função que contém os níveis
    cout << " +-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
    cout << " |                         |\n";
    cout << " |         NÍVEIS          |\n";
    cout << " |                         |\n";
    cout << " | (1) Iniciante           |\n";
    cout << " | (2) Fácil               |\n";
    cout << " | (3) Intermediário       |\n";
    cout << " | (4) Difícil             |\n";
    cout << " |                         |\n";
    cout << " +-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void imprimecm(char cm[l][c]) {     //função de criação da matriz do campo minado
    cout << "Campo Minado: \n";     //nome da matriz
    for (int i=0; i<l; i++) {
        for (int j=0; j<c; j++) {
            cout << cm[i][j] << " | ";      //imprime a matriz e as linhas dela
        }
        cout << endl;       //quebra de linha
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void imprimeaux(char aux[l][c]) {       //função que contém a matriz que o jogador joga, a auxiliar
    cout << "Matriz Auxiliar: \n";      //nome da matriz
    for (int i=0; i<l; i++) {
        for (int j=0; j<c; j++) {
            cout << aux[i][j] << " | ";     //imprime a matriz e as linhas dela
        }
        cout << endl;           //quebra de linha
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int verificaIgualdade(char aux[l][c], char cm[l][c], int linha, int coluna) {   //função que compara a matriz do campo com a auxiliar, a medida que o jogar vai jogando
    if (aux[linha][coluna] == cm[linha][coluna]) {  // Compara se a posição da matriz campo_minado correspondente também possui um 0
        return 1; // campo limpo
    } else {
        aux[linha][coluna] = cm[linha][coluna]; // Atualiza a auxiliar para B na posição que o usuário informou, pois há uma mina
        return 0; // mina
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
