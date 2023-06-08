#include <conio.h>  // para utilizar a fun��o de parada getch
#include <time.h> // para sortear
#include <iostream>   //escrever os c�digos em c++
using namespace std;

#define l 5     //define a quantidade de linha da matriz
#define c 5     //define a quantidade de coluna da matriz

//declara��o de fun�oes
//as func�es completas est�o ap�s o int main
void imprimeMenu();         //imprime o menu principal, de in�cio (novo jogo,sobre o jogo,entre outros)
void imprimeMenuNivel();       //imprime os n�veis do jogo para o usu�rio escolher qual ele quer jogar
void imprimecm(char cm[l][c]);      //imprime a matriz do campo minado
void imprimeaux(char aux[l][c]);    //imprime a matriz auxiliar, on de o jogador faz as suas jogadas
int verificaIgualdade(char aux[l][c], char cm[l][c], int linha, int coluna);    //verifica se onde o usu�rio jogou tem bomba ou mina

int main()
{   setlocale(LC_ALL, "Portuguese");    //biblioteca do programa entender portugu�s , acentos e afins
	char cm[l][c], aux[l][c];           // 0 para campo limpo; B para minas
    int s=0, igual=0, linha=0,coluna=0, acertos=0;      //s= sorteio das bombas
    unsigned seed=time(0);
    srand(seed);
    int opcao,opcao2;       //ler as op��es dos 2 menus
    string nome;            // ler o nome do usu�rio
    int minas=0;            //quantidade de minas que vai ter no n�vel, cada n�vel tem uma quantidade definida, por isso declarei a vari�vel com 0
    char jn;                // caso o usu�rio queira jogar novamente ou ao menos voltar ao menu do jogo


	cout << "\t\t\t\t\tSEJA BEM-VINDO(A) AO CAMPO MINADO\t\t\t\t\t" << endl << endl;        //boas vindas ao jogo
    do{        // condi��o do switch case do primeiro menu, se caso o usu�rio digitar um n�mero inv�lido
    imprimeMenu();    //impress�o do menu principal
    cout << endl << endl;    //quebra linha
    cout << "Digite a op��o desejada: ";  //pede o usu�rio para escolher uma op��o do menu
    cin >> opcao;       //programa ler a op��o que o usu�rio digitou
    system("cls");     //limpa a tela

    cout << "\t\t\t\t\t*****CAMPO MINADO*****\t\t\t\t\t" << endl << endl;       //nome do jogo
    switch(opcao){
    case 1:     //caso o usu�rio escolha novo jogo
    cout << "Digite teu nome: ";        //pedi para o usu�rio digitar o seu nome
    cin >> nome;        //programa l� o nome
    system("cls");      //limpar a tela

    cout << "\n\n\t\t" << nome << ",escolha o n�vel que deseja jogar: " << endl << endl << endl;    //pergunta o usu�rio qual n�vel ele quer jogar
    imprimeMenuNivel();     //imprime o menu de n�vel e mostra ao usu�rio

    cout << "\n\nDigite o n�vel que deseja jogar(1,2,3,4): ";       //usu�rio digita o n�vel que deseja
    cin >> opcao2;      //programa l� o n�vel que o usu�rio digitou
    system("cls");      //limpa a tela

    if(opcao2 > 1 || opcao2 <4 ){       //validando caso o usu�rio digite um n�mero inv�lido
        if(opcao2 == 1){    //primeiro n�vel
		cout << "Nivel Iniciante, h� 3 minas no tabuleiro \n\n";    //informa o usu�rio quantas minas h� no tabuleiro
		minas = 3;      //quantidade de minas
		system("pause");        //pausa para o usu�rio ler o cout
        system ("cls");     //limpa a tela
	}
    else if(opcao2 == 2){   //segundo n�vel
        cout << "Nivel F�cil, h� 6 minas no tabuleiro \n\n";     //informa o usu�rio quantas minas h� no tabuleiro
        minas = 6; //quantidade de minas
        system("pause");    //pausa para o usu�rio ler o cout
        system ("cls");      // limpa a tela
    }
    else if (opcao2 == 3){  //terceiro n�vel
        cout << "Nivel Intermedi�rio, h� 9 minas no tabuleiro \n\n"; //informa o usu�rio quantas minas h� no tabuleiro
        minas = 9;  //quantidade de minas
        system("pause");    //pausa para o usu�rio ler o cout
        system ("cls");      // limpa a tela
    }

    else{       //executa o �ltimo n�vel
        cout << "Nivel Dif�cil, h� 3 minas no tabuleiro \n\n"; ////informa o usu�rio quantas minas h� no tabuleiro
        minas = 12; //quantidade de minas
        system("pause");   //pausa para o usu�rio ler o cout
        system ("cls"); // limpa a tela
        }
    }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Inicializa Campo Minado
    for (int i=0; i<l; i++) {
        for (int j=0; j<c; j++) {
            cm[i][j] = '0';
            aux[i][j] = ' ';    //matriz auxiliar, pode ser adicionada separadamente, mas, encurta c�digo colocando junto a principal
        }
    }

    // Sorteio das minas
    for (s=1; s<=minas; s++) { // cada n�vel uma quantidade de minas, ent�o sortear� quantidades diferentes e minas
        cm[rand()%l][rand()%c] = 'B';   //quando encontrar a bomba ir� aparecer um B
    }

    while (igual != 0 || acertos < 3) {         //em 3 jogadas, se o usu�rio n�o jogar em bomba, ganhar�, caso contr�rio, perder�
        system("cls");      //limpa a tela
        imprimeaux(aux);        //come�a a colocar em pr�tica as jogadas com a matriz auxiliar
        cout << "\nQuantidade de jogadas que voc� acertou: " << acertos << endl;      //jogadas que o usu�rio acertou
        cout << "\nInforme a linha: ";        //linha que o usu�rio quer jogar
        cin >> linha;       //programa le a linha
        cout << "\nInforme a coluna: ";         //coluna que o usu�rio quer jogar
        cin >> coluna;      //programa le a coluna
        aux[linha][coluna] = '0';       //caso o usu�rio nn acerte bomba, aparecer� o 0
        igual = verificaIgualdade(aux, cm, linha, coluna); // 1 campo limpo, 0 encontrou uma mina

        if (igual == 0) {
            cout << "Encontrou uma mina\n\n";
            cout << "     VOC� PERDEU       \n\n";  // caso o usu�rio acerte uma mina, ele perder�
            break;  //para de executar o programa
        } else {
            cout << "Campo limpo."; // usu�rio continua jogando, pois n�o acertou a mina
            acertos+=1;     // continua��o do jogo
        }
        if (acertos == 3) {
            cout << "\n\nVOC� GANHOU, MANDOU BEM!!!";   //jogou 3 vezes e n�o encontrou nenhuma mina, ganhou o jogo
            break;  //para de executar o programa
        }
    }
    system("pause");        //pausa para o usu�rio ler os cout
    system("cls");          //limpa a tela
    cout << "\n\t\tAgora, veja onde estavam todas as bombas: \n\n";     //mostra ao usu�rio onde estavam as bombas, independente se ele ganhou ou perdeu, sempre ir� mostrar
    imprimecm(cm);      //mostrando na matriz onde estavam as bombas

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    cout << "\n\nDeseja jogar novamente (s/n)? ";       //caso o usu�rio deseje jogar novamente
    cin >> jn;      //ler se o usu�rio deseja ou n�o jogar novamente
    switch(jn){     //executando o que o usu�rio desejou
    case 's':       //caso ele queira jogar novamente
        main();         //ir� voltar ao menu principal e repitir� o processo
    getch();        //parada
    break;      //parando de executar o case
    case 'n':       //caso o usu�rio deseja parar de jogar
        return 0;       //saindo do jogo
    getch();        //parada
    break;      //para de executar o case
    system("cls");      //limpa a tela
    }
    break;      //para o case 1 aberto dentro do menu principal, novo jogo

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    case 2:     // segundo caso do menu principal
    system("cls");      //limpa  a tela
    //mostrando ao usu�rio como funciona o jogo
    cout << "O Campo Minado � um jogo aparentemente simples de mem�ria e racioc�nio";
    cout << "O objetivo do Campo Minado � revelar os quadrados vazios e com n�meros,evitando aqueles que escondem bombas";
    cout << "Voc� pode revelar o que existe em um quadrado, ditando a linha e a coluna. Se voc� revelar uma bomba, voce perdera";

    cout << "\n\nAgora que ja sabe um pouco sobre o jogo, deseja jogar?"; // caso o usu�rio queira jogar depois da informa��o sobre o jogo
    cin >> jn;      //ler se o usu�rio deseja ou n�o jogar
    switch(jn){     //executando o que o usu�rio desejou
    case 's':       //caso ele queira jogar novamente
        main();         //ir� voltar ao menu principal e repitir� o processo
    getch();        //parada
    break;      //parando de executar o case
    case 'n':       //caso o usu�rio deseja parar de jogar
        return 0;       //saindo do jogo
    getch();        //parada
    break;      //para de executar o case
    system("cls");      //limpa a tela
    }
    break;      //para o case 1 aberto dentro do menu principal, novo jogo

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    case 3:     //terceiro caso do menu principal
    system("cls");      //limpa a tela
    cout << "Jogo criado por Samyra Giovana, 18. Aluna do curso SI-IFMG (Sistemas de Informa��o)";      //informa��es sobre quem criou o jogo
    break;      //para de executar o case

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    case 4:     //quarto caso do menu principal
    system("cls");      //limpar a tela
    cout << "Volte sempre\n";       //mensagem exibida se usu�rio escolher sair
    break;      //para de executar o case

    default: cout << "Opcao invalida\n";        //caso a op��o digitada seja inv�lida
    system("pause");        //pausa para o usu�rio ler
    system("cls");      //limpa a tela
    }
    }while (opcao<1 || opcao>4);        //caso seja op��o inv�lida voltar� ao menu novamente
    system("pause");        //pausa para o usu�rio ler,ver
    return 0;       //fecha o programa
    }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  void imprimeMenu() {          //fun��o que cont�m o menu principal
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

void imprimeMenuNivel() {           //fun��o que cont�m os n�veis
    cout << " +-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
    cout << " |                         |\n";
    cout << " |         N�VEIS          |\n";
    cout << " |                         |\n";
    cout << " | (1) Iniciante           |\n";
    cout << " | (2) F�cil               |\n";
    cout << " | (3) Intermedi�rio       |\n";
    cout << " | (4) Dif�cil             |\n";
    cout << " |                         |\n";
    cout << " +-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void imprimecm(char cm[l][c]) {     //fun��o de cria��o da matriz do campo minado
    cout << "Campo Minado: \n";     //nome da matriz
    for (int i=0; i<l; i++) {
        for (int j=0; j<c; j++) {
            cout << cm[i][j] << " | ";      //imprime a matriz e as linhas dela
        }
        cout << endl;       //quebra de linha
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void imprimeaux(char aux[l][c]) {       //fun��o que cont�m a matriz que o jogador joga, a auxiliar
    cout << "Matriz Auxiliar: \n";      //nome da matriz
    for (int i=0; i<l; i++) {
        for (int j=0; j<c; j++) {
            cout << aux[i][j] << " | ";     //imprime a matriz e as linhas dela
        }
        cout << endl;           //quebra de linha
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int verificaIgualdade(char aux[l][c], char cm[l][c], int linha, int coluna) {   //fun��o que compara a matriz do campo com a auxiliar, a medida que o jogar vai jogando
    if (aux[linha][coluna] == cm[linha][coluna]) {  // Compara se a posi��o da matriz campo_minado correspondente tamb�m possui um 0
        return 1; // campo limpo
    } else {
        aux[linha][coluna] = cm[linha][coluna]; // Atualiza a auxiliar para B na posi��o que o usu�rio informou, pois h� uma mina
        return 0; // mina
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
