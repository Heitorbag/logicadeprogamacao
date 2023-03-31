#include <iostream>
#include <math.h>
#include <stack> 
using namespace std;


// utiliza recursão para saber os movimentos corretos
void moveDisco(int discos, char origem, char destino, char auxiliar) { 
    if (discos==1) {
        cout << "Mova o disco 1 da Torre " << origem << " para Torre " << destino << endl;
        return;
    }
    moveDisco(discos-1, origem, auxiliar, destino);
    cout << "Mova o disco " << discos << " da Torre " << origem << " para Torre " << destino << endl;
    moveDisco(discos-1, auxiliar, destino, origem);
}

// utiliza pilha para realizar o jogo
void jogarHanoi(int discos) {
    stack<int> torre[3];
    int movimentos = 0;
    
    // coloca todos os discos na torre 1
    for (int i = discos; i >= 1; i--) { 
        torre[0].push(i); 
    }
    
    // loop ate a torre3 ter o numero total de discos
    while (torre[2].size() < discos) { 
        int origem, destino;
        cout << "\n\nMover disco de qual Torre para qual Torre? \n(Torre A = 1, Torre B = 2, Torre C = 3): ";
        cin >> origem >> destino;
        origem--, destino--;
        
        // verifica se é possivel realizar a mudança
        if (origem < 0 || origem > 2 || destino < 0 || destino > 2 || torre[origem].empty() || (!torre[destino].empty() && torre[destino].top() < torre[origem].top())) { 
            cout << "\n\nMovimento inválido! Por favor, selecione uma torre válida e verifique se o disco que você quer mover é o topo da torre.\n\n";
            movimentos++;
            continue;
        }
        
        // realiza a mudança dos discos entre as torres
        torre[destino].push(torre[origem].top());
        torre[origem].pop();
        cout << "\n\nO Disco foi movido da Torre " << origem + 1 << " para Torre " << destino + 1 << "!\n\n";
        movimentos++;
    }
    cout << "Jogo Resolvido em " << movimentos << " movimentos!" << endl;
}

int main() {
    int discos, opcao;
    cout << "TORRE DE HANÓI \n\nDigite o número de discos: ";
    cin >> discos;
    cout << "Mínimo de movimentos: "<< pow(2,discos) - 1 << "\n\n"; // calcula os movimentos necessarios
    
    while (true) { 
        cout << "TORRE DE HANÓI \n1. Jogar Hanói. \n2. Mostrar Movimentos. \nEscolha uma opção: ";
        cin >> opcao;

        if (opcao==1) {
            jogarHanoi(discos);
            break;
        } else if (opcao==2) {
            moveDisco(discos, 'A', 'C', 'B');
            break;
        } else {
            cout<< "\n\nEscolha uma opção Válida!\n\n";
        }
    }
    
    return 0;
}