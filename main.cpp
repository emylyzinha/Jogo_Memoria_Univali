#include <iostream>
#include <time.h> // habilita a função time
#include <locale.h> // para utilizar acentos e etc - lígua portguesa
#include <cstdlib> // para utilizar system("cls") e system("pause");

using namespace std;

int main()
{
    srand(time(NULL)); // semente randomica gerada a partir da hora do sistema
    
    //matriz principal
    int MP[4][4] = {
        {1,4,5,2},
        {7,2,8,7},
        {3,6,1,4},
        {6,5,3,8}
    };
    
    int numAleatorio, MG[4][4], MJ[4][4], jLinha1, jColuna1, jLinha2, jColuna2, jogadas=1 , peca ;
    bool acertosJ;
    
    //gera numero aleatorio para definir matriz utilizada no tabuleiro
    // função rand gera um número aleatório 
    // mod de 4 para gerar 4 opção de números (0-3)
    // soma + 1 pois as opção que temos são de 1 a 4
    numAleatorio = (rand()%4) + 1; 
    
    //TABULEIRO 1: sem modificações
    // Matriz gabarito = matriz principal
    if(numAleatorio == 1){
        for (int i=0; i<4; i++){ //linha
            for (int j=0; j<4; j++){ // coluna
                MG[i][j] = MP[i][j];
            }
        }
    }
    
    //TABULEIRO 2: transposta
    // Linhas da matriz principal para as colunas da matriz gabarito (troca i e j)
    if(numAleatorio == 2){
        for (int i=0; i<4; i++){ //linha
            for (int j=0; j<4; j++){ // coluna
                MG[j][i] = MP[i][j];
            }
        }
    }
    
    //TABULEIRO 3: inverter linhas
    // Elementos das últimas linhas da matriz principal para as primeiras linhas da matriz gabarito
    // enquanto o k aumenta (linha matriz gabarito) o i diminui (linha matriz principal)
    if(numAleatorio == 3){
        int k = 0;
        for (int i=3; k<4; i--){ //linha
            for (int j=0; j<4; j++){ // coluna
                MG[k][j] = MP[i][j];
            }
            k++;
        }
    }
    
     //TABULEIRO 4: inverter colunas
     // Elementos das últimas colunas da matriz principal para as primeiras colunas da matriz gabarito
    // enquanto o k aumenta (coluna matriz gabarito) o j diminui (coluna matriz principal)
    if(numAleatorio == 4){
        for (int i=0; i<4; i++){ //linha
            int k = 0;
            for (int j=3; k<4; j--){ // coluna
                MG[i][k] = MP[i][j];
                k++;
            }
        }
    }
    
    while(jogadas <= 24){ //jogador tem no máximo 24 jogadas
        
        // apresentar matriz jogo
        cout<<"--------------- TABULEIRO ---------------\n";
        for (int i=0; i<4; i++){ //linha
            for (int j=0; j<4; j++){ // coluna
                cout<<"["<<MJ[i][j]<<"] ";
            }
            cout<<"\n";
        }
        
        //Jogador seleciona a peça 01(linha e coluna)
        cout<<"\n----------- JOGADA "<<jogadas<<": Peça "<<peca<<" -------------\n\nLinha: ";
        cin>>jLinha1;
        cout<<"Coluna: ";
        cin>>jColuna1;
        
        while(jLinha1 > 4 || jLinha1 < 1 || jColuna1 > 4 || jColuna1 < 1){
            system("clear");
            
            cout<<"--------------- TABULEIRO ---------------\n";
            for (int i=0; i<4; i++){ //linha
                for (int j=0; j<4; j++){ // coluna
                    cout<<"["<<MJ[i][j]<<"] ";
                }
                cout<<"\n";
            }
        
            cout<<"\nNão existe carta nesta posição, tente outra...\n";
            cout<<"\n----------- JOGADA "<<jogadas<<": Peça "<<peca<<" -------------\n\nLinha: ";
            cin>>jLinha1;
            cout<<"Coluna: ";
            cin>>jColuna1;
        }
        
        // verifica se a peça já foi selecionada ou acertada
        // jLinha -1 e jColuna-1 pois nosso indices iniciam em 0 e finalizam em 3
        while(MJ[jLinha1-1][jColuna1-1] != 0){
            cout<<"Está carta já está aberta, tente outra...\n";
            cout<<"\n----------- JOGADA "<<jogadas<<": Peça "<<peca<<" -------------\n\nLinha: ";
            cin>>jLinha1;
            cout<<"Coluna: ";
            cin>>jColuna1;
        }
        
        // Atribui valor do gabarito a matriz jogo para apresentar valor selecionado
        MJ[jLinha1-1][jColuna1-1] = MG[jLinha1-1][jColuna1-1];
        
        //defini valor a ser utilizado em nossos indices
        jColuna1--;
        jLinha1--;
        
        //adiciona 1 a peça selecionada na jogada -> 02
        peca++;
        system("clear");

        cout<<"--------------- TABULEIRO ---------------\n";
        // apresentar matriz jogo
        for (int i=0; i<4; i++){ //linha
            for (int j=0; j<4; j++){ // coluna
                cout<<"["<<MJ[i][j]<<"] ";
            }
            cout<<"\n";
        }
        
        //Jogador seleciona a peça 02 (linha e coluna)
        cout<<"\n----------- JOGADA "<<jogadas<<": Peça "<<peca<<" -------------\n\nLinha: ";
        cin>>jLinha2;
        cout<<"Coluna: ";
        cin>>jColuna2;
        
        while(jLinha2 > 4 || jLinha2 < 1 || jColuna2 > 4 || jColuna2 < 1){
            system("clear");
            
            cout<<"--------------- TABULEIRO ---------------\n";
            for (int i=0; i<4; i++){ //linha
                for (int j=0; j<4; j++){ // coluna
                    cout<<"["<<MJ[i][j]<<"] ";
                }
                cout<<"\n";
            }
        
            cout<<"\nNão existe carta nesta posição, tente outra...\n";
            cout<<"\n----------- JOGADA "<<jogadas<<": Peça "<<peca<<" -------------\n\nLinha: ";
            cin>>jLinha2;
            cout<<"Coluna: ";
            cin>>jColuna2;
        }
        
        
        // verifica se a peça já foi selecionada ou acertada
        // jLinha -1 e jColuna-1 pois nosso indices iniciam em 0 e finalizam em 3
        while(MJ[jLinha2-1][jColuna2-1] != 0){
            cout<<"Está carta já está aberta, tente outra...\n";
            cout<<"\n----------- JOGADA "<<jogadas<<": Peça "<<peca<<" -------------\n\nLinha: ";
        cin>>jLinha2;
        cout<<"Coluna: ";
        cin>>jColuna2;
        }
        
        // Atribui valor do gabarito a matriz jogo para apresentar valor selecionado
        MJ[jLinha2-1][jColuna2-1] = MG[jLinha2-1][jColuna2-1];
        
        //defini valor a ser utilizado em nossos indices
        jLinha2--;
        jColuna2--;
        system("clear");
        
        
        cout<<"--------------- TABULEIRO ---------------\n";
        // apresentar matriz jogo
        for (int i=0; i<4; i++){ //linha
            for (int j=0; j<4; j++){ // coluna
                cout<<"["<<MJ[i][j]<<"] ";
            }
            cout<<"\n";
        }
        
        // verifica se o jogador acertou ou não
        if(MJ[jLinha1][jColuna1] != MJ[jLinha2][jColuna2]){ // não acertou -> esconde novamente as cartas
            MJ[jLinha1][jColuna1] = 0;
            MJ[jLinha2][jColuna2] = 0;
            cout<<"\n ERROU!\nSelecione Enter para continuar"<<endl;
            system("read 0 -p");
            system("clear");
        } else if (MJ[jLinha1][jColuna1] == MJ[jLinha2][jColuna2]) { //acertou
            cout<<"\n ACERTOUU!\nSelecione Enter para continuar"<<endl;
            system("read 0 -p");
            system("clear");
        }
        
        //verificar se jogador acertou tudo e ganhou o jogo
        for (int i=0; i<4; i++){ //linha
            for (int j=0; j<4; j++){ // coluna
                if(MJ[i][j] == MG [i][j]){ // matriz jogo e matriz gabarito são iguais 
                    acertosJ = true;
                }else{
                    acertosJ = false; // quando um valor for diferente encerra verificação -> jogador ainda não ganhou
                    break;
                }
            }
            if(acertosJ == false){
                break;
            }
        }
        
        //se ao final da verificação acertosJ é true -> jogador venceu
        if(acertosJ == true){
            cout<<"----------- VOCÊ GANHOU! -----------";
            return 0;
        }
        
        jogadas ++; // contador de jogada
        peca--; // retorna ao valor inicial de peça = 01
        jLinha1; // atribui valor inicial para que entre na lógica utilizada
        jLinha2; // atribui valor inicial para que entre na lógica utilizada
        jColuna1; // atribui valor inicial para que entre na lógica utilizada
        jColuna2; // atribui valor inicial para que entre na lógica utilizada
    }
    
    cout<<"----------- VOCÊ PERDEU! -----------";
    
    return 0;
}
