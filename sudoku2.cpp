#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int matriz[9][9];

int tabuleiro1[9][9]={{0,7,0,4,0,0,5,0,0},{0,1,0,3,2,0,0,8,4},{9,0,0,0,6,1,0,0,0},{0,0,5,0,8,0,0,2,9},{0,2,9,7,0,5,1,6,0},{6,8,0,0,4,0,7,0,0},{0,0,0,8,1,0,0,0,7},{8,0,0,0,5,4,0,3,0},{0,0,2,0,0,3,0,4,0}};

int tabuleiro2[9][9]={{0,0,8,4,7,0,3,0,6},{0,6,0,0,0,2,0,1,0},{2,4,0,5,0,0,0,0,8},{0,0,9,1,5,0,4,0,3},{0,7,0,0,0,0,0,5,0},{5,0,4,0,8,3,2,0,0},{7,0,0,0,0,6,0,8,5},{0,9,0,7,0,0,0,3,0},{6,0,2,0,9,5,1,0,0}};

int tabuleiro3[9][9]={{1,0,0,3,0,0,9,2,0},{3,0,0,4,0,0,8,5,0},{6,0,0,9,0,1,0,7,0},{4,7,9,0,1,0,0,0,0},{0,0,2,0,6,0,1,0,0},{0,0,0,0,8,0,4,3,7},{0,5,0,8,0,7,0,0,2},{0,8,4,0,0,2,0,0,3},{0,6,3,0,0,5,0,0,9}};
    
int tabuleiro4[9][9]={{5,3,4,6,7,8,9,1,2},{6,7,2,1,9,5,3,4,8},{1,9,8,3,4,2,5,6,7},{8,5,9,7,6,1,4,2,3},{4,2,6,8,5,3,7,9,1},{7,1,3,9,2,4,8,5,6},{0,6,1,5,3,7,2,8,4},{0,8,7,4,1,9,6,3,5},{0,4,5,2,8,6,1,7,9}};


int linha, coluna, valor, opcao;
bool aindaEstaValido=true;
bool ganhou=false;


void tabuleiro()
{
    int w = 1, a , b, c;
    c=0;
    cout<<"  ---------- SUDOKU -----------"<<"\n";
    cout<<"   1  2  3   4  5  6   7  8  9 "<<"\n";
    cout<<" [-----------------------------]"<<"\n";
    for(int i=0;i<9;i++)
    {
        cout<<w<<"[";
        w++;
        a=0,b=0;
        for(int j=0;j<9;j++)
        {
            if(a==3)
            {
                if(b==36) 
                {
                    a=0,b=0;
                } else {
                    cout<<"|";
                    a=0;
                }
            }
            if (matriz[i][j]==0)
            {
                a++,b+=4,c+=4;
                cout<<" "<<" "<<" ";
            } else {
                a++,b+=4,c+=4;
                cout<<" "<<matriz[i][j]<<" ";
            }
        }
        cout<<"]";
        cout<<"\n";
        if(c==108)
        {
            cout<<" [-----------------------------]"<<"\n"; 
            c=0;
        }
    }
}


void verificaMatriz()
{
    int linhaBlocoInicio=0;
    int colunaBlocoInicio=0;
    int linhaBlocoFim=0;
    int colunaBlocoFim=0;
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            if(matriz[i][j]!=0)
            {
                for(int linha=0; linha<9; linha++)
                {
                    if(matriz[linha][j]!=0 && matriz[i][j]==matriz[linha][j] && (i!=linha) )
                    {
                        aindaEstaValido=false;
                        break;
                    }
                } 
                if(aindaEstaValido==false)  break;
                
                for(int coluna=0; coluna<9; coluna++)
                {
                    if(matriz[i][coluna]!=0 && matriz[i][j]==matriz[i][coluna]&& (j!=coluna))
                    {
                        aindaEstaValido=false;
                        break;
                        }
                }
                if(aindaEstaValido==false)  break;
            
                if((i>=0 && i<=2) && (j>=0 && j<=2)){ 
                    linhaBlocoInicio=0;
                    linhaBlocoFim=2;
                    colunaBlocoInicio=0;
                    colunaBlocoFim=2;
                }
                    
                if((i>=0 && i<=2) && (j>=3 && j<=5)){ 
                    linhaBlocoInicio=0;
                    linhaBlocoFim=2;
                    colunaBlocoInicio=3;
                    colunaBlocoFim=5;
                }
                    
                if((i>=0 && i<=2) && (j>=6 && j<=8)){ 
                    linhaBlocoInicio=0;
                    linhaBlocoFim=2;
                    colunaBlocoInicio=6;
                    colunaBlocoFim=8;
                }
                    
                if((i>=3 && i<=5) && (j>=0 && j<=2)){ 
                    linhaBlocoInicio=3;
                    linhaBlocoFim=5;
                    colunaBlocoInicio=0;
                    colunaBlocoFim=2;
                }
                    
                if((i>=3 && i<=5) && (j>=3 && j<=5)){ 
                    linhaBlocoInicio=3;
                    linhaBlocoFim=5;
                    colunaBlocoInicio=3;
                    colunaBlocoFim=5;
                }
                    
                if((i>=3 && i<=5) && (j>=6 && j<=8)){ 
                    linhaBlocoInicio=3;
                    linhaBlocoFim=5;
                    colunaBlocoInicio=6;
                    colunaBlocoFim=8;
                }
                    
                if((i>=6 && i<=8) && (j>=0 && j<=2)){ 
                    linhaBlocoInicio=6;
                    linhaBlocoFim=8;
                    colunaBlocoInicio=0;
                    colunaBlocoFim=2;
                }
                    
                if((i>=6 && i<=8) && (j>=3 && j<=5)){ 
                    linhaBlocoInicio=6;
                    linhaBlocoFim=8;
                    colunaBlocoInicio=3;
                    colunaBlocoFim=5;
                }
                    
                if((i>=6 && i<=8) && (j>=6 && j<=8)){ 
                    linhaBlocoInicio=6;
                    linhaBlocoFim=8;
                    colunaBlocoInicio=6;
                    colunaBlocoFim=8;
                }
                   
                for(int a=linhaBlocoInicio; a<=linhaBlocoFim; a++)
                {
                    for(int b=colunaBlocoInicio; b<=colunaBlocoFim; b++)
                    {
                        if(i==a && j==b) continue;
                        if(matriz[a][b]!=0 && matriz[i][j]==matriz[a][b])
                        {
                            aindaEstaValido=false;
                            break;
                        }
                    }
                }
            if(aindaEstaValido==false)  break;
            }
        if(aindaEstaValido==false)  break;
        }
    }
}


void verificaGanhou()
{
    int fx;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(matriz[i][j]!=0) 
            {
                fx+=1;
            }
        }
    }
    if(fx==90) 
    {
        ganhou=true;
    } else {
        fx=0;
    }
}


void prencherMatriz()
{
    if(coluna >= 1 && coluna <= 9 && linha >= 1 && linha <= 9 && valor > 0 && valor <= 9) 
    {
        coluna--,linha--;
        if(matriz[coluna][linha]==0)
        { 
            matriz[coluna][linha]=valor;
        } else {
        cout<<"\n"<<"Escolha errada. Tente Novamente!"<<"\n";
        }
    } else {
        cout<<"\n"<<"Escolha errada. Tente Novamente!"<<"\n";
    }

}


int main()
{
    srand(time(0));
    int random = rand()%4;
    
    switch (random) {

        case 0:
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    matriz[i][j]= tabuleiro1[i][j];
                }
            }
            break;

        case 1:
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    matriz[i][j]= tabuleiro2[i][j];
                }
            }
            break;

        case 2:
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    matriz[i][j]= tabuleiro3[i][j];
                }
            }
            break;
            
        case 3:
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    matriz[i][j]= tabuleiro4[i][j];
                }
            }
            break;
    }                   
 
    while(ganhou!=true && aindaEstaValido==true) {
        
    tabuleiro();
    
    cout<<"Escolha uma COLUNA e LINHA: ";
    cin>>linha >> coluna;
    cout<<"Escolha um Número: ";
    cin>>valor; 

    prencherMatriz();

    verificaMatriz();
    
    verificaGanhou();
    }
    
    
    if(aindaEstaValido==false)
    {
        matriz[coluna][linha]=0;
        cout<<"\nLamentável voçê falhou em completar o SUDOKU!\n1. Tentar Novamente. \n2. Exibir Tabuleiro. \n3. Sair. \nEscolha uma Opção: ";
        cin>>opcao;
    }
    
    if(ganhou==true)
    {
        cout<<"\nParabéns voçê completou o SUDOKU!\n1. Tentar Novamente. \n2. Exibir Tabuleiro. \n3. Sair. \nEscolha uma Opção: ";
        cin>>opcao;
    }
    
    if(opcao==1)
    {
        aindaEstaValido=true;
        main();
    } 
    else if(opcao==2) {
        tabuleiro();
        return 0;
    }
    else if(opcao==3) {
        return 0;
    } 

    return 0;
}

