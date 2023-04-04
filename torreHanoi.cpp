#include <iostream>
#include <math.h>
#include <stack> 
using namespace std;

void moveDisco(int discos, char origem, char destino, char auxiliar) { 
    if (discos==1) {
        cout << "Mova o disco 1 da Torre " << origem << " para Torre " << destino << endl;
        return;
    }
    moveDisco(discos-1, origem, auxiliar, destino);
    cout << "Mova o disco " << discos << " da Torre " << origem << " para Torre " << destino << endl;
    moveDisco(discos-1, auxiliar, destino, origem);
}

void jogarHanoi(int discos, int minMov, int maxMov) {
    stack<int> torre[3];
    int movimentos = 0;
    
    for (int i = discos; i >= 1; i--) { 
        torre[0].push(i); 
    }
    
    cout << "\n\n";
    while (torre[2].size() < discos) { 
        for (int i = discos - 1; i >= 0; i--) {
            for (int j = 0; j < 3; j++) {
                if (torre[j].size() > i) {
                    cout << (torre[j].top(), '*') << "   ";
                } else 
                    cout << "|   ";
            }
            cout << endl;
        }
        cout << "--- --- ---\n";
        cout << " A   B   C \n";
        
        int origem, destino;
        cout << "\n(Torre A = 1, Torre B = 2, Torre C = 3, Sair = 4)\n";
        cout << "Escolha de qual Torre sera tirado o disco: " ;
        cin >> origem;
        if (origem == 4) return;
        cout << "Escolha qual Torre o disco vai ser colocado: ";
        cin >> destino;
        if (destino == 4) return;
        origem--, destino--;
        
        if (origem < 0 || origem > 2 || destino < 0 || destino > 2 || torre[origem].empty() || (!torre[destino].empty() && torre[destino].top() < torre[origem].top())) { 
            movimentos++;
            cout << "\n\nMovimento inválido! Por favor, verifique sua escolha.\n\n";
            cout << "Movimentos realizados: " << movimentos << "\nMáximo de movimentos: "<< maxMov <<"\n\n";
            continue;
        }

        torre[destino].push(torre[origem].top());
        torre[origem].pop();
        movimentos++;
    
        if (movimentos==maxMov) {
            cout << "\n\nVocê perdeu. Que pena! \nNumero de movimentos: " << movimentos << "!\n";
            return;
        } else {
            cout << "\n\nO Disco foi movido da Torre " << origem + 1 << " para Torre " << destino + 1 << "!\n";
            cout << "Movimentos realizados: " << movimentos << "\nMáximo de movimentos: "<< minMov + 3 <<"\n\n";
        } 
    }
    cout << "Jogo Resolvido em " << movimentos << " movimentos!" << endl;
}



void menuDeJogo(int discos, int opcao, int minMov, int maxMov) {
    while (true) { 
        cout << "TORRE DE HANÓI \n1. Jogar Hanói. \n2. Mostrar Movimentos. \n3. Sair. \nEscolha uma opção: ";
        cin >> opcao;
        
        if (opcao==1) {
            jogarHanoi(discos, minMov, maxMov);
            break;
        } else if (opcao==2) {
            moveDisco(discos, 'A', 'C', 'B');
            break;
        } else if (opcao==3) {
            cout << "\nAté logo!";
            break;
        } else {
            cout<< "\nEscolha uma opção Válida!\n\n";
        }
    }
}

int main() {
    int discos, opcao, minMov, maxMov;
    cout << "TORRE DE HANÓI \n\nDigite o número de discos: ";
    cin >> discos;
    minMov = pow(2,discos) - 1;
    maxMov = minMov + 3;
    cout << "Mínimo de movimentos: "<< minMov << "\n\n";
    
    menuDeJogo(discos, opcao, minMov, maxMov);
    
    return 0;
}