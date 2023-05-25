#include <iostream>

using namespace std;


struct No {
    int valor; // Valor inteiro armazenado no nó
    No* proximo; // Ponteiro para o próximo nó na fila
};

// Função para enfileirar um valor na fila
void enfileira(No*& inicio, No*& fim, int valor) {
    // Cria um novo nó
    No* novoNo = new No;
    novoNo->valor = valor;
    novoNo->proximo = nullptr;

    // Verifica se a fila está vazia
    if (inicio == nullptr) {
        inicio = novoNo; // O novo nó é o primeiro da fila
        fim = novoNo; // O novo nó também é o último da fila
    } else {
        fim->proximo = novoNo; // Atualiza o ponteiro do último nó para o novo nó
        fim = novoNo; // Atualiza o ponteiro do último para o novo nó
    }
}

// Função para desenfileirar o primeiro valor da fila
int desenfileira(No*& inicio) {
    if (inicio == nullptr) {
        cout << "Fila vazia." <<endl;
        return -1;
    }

    No* noRemovido = inicio; // Aponta para o primeiro nó da fila
    int valor = noRemovido->valor; // Armazena o valor do primeiro nó
    inicio = inicio->proximo; // Atualiza o ponteiro do início para o próximo nó
    delete noRemovido; // Libera a memória do primeiro nó

    return valor; // Retorna o valor desenfileirado
}

// Função para imprimir os valores da fila
void imprimeFila(const No* inicio) {
    cout << "Elementos na fila:" <<endl;

    const No* atual = inicio; // Ponteiro para percorrer a fila
    while (atual != nullptr) {
        cout << atual->valor << " "; // Imprime o valor do nó atual
        atual = atual->proximo; // Avança para o próximo nó
    }

    std::cout << std::endl;
}

// Função para contar o número de elementos na fila
int contaElementos(const No* inicio) {
    int contador = 0;
    const No* atual = inicio; // Ponteiro para percorrer a fila
    while (atual != nullptr) {
        contador++;
        atual = atual->proximo; // Avança para o próximo nó
    }
    return contador;
}

// Função para desenfileirar e imprimir apenas os valores pares da fila
void desenfileiraPares(No*& inicio) {
    cout << "Desenfileirando elementos pares:" <<endl;

    while (inicio != nullptr) {
        int valor = desenfileira(inicio); // Desenfileira o primeiro valor da fila
        if (valor % 2 == 0) { 
            cout << "Elemento desenfileirado: " << valor <<endl; 
        }
    }
}


void liberaFila(No*& inicio) {
    while (inicio != nullptr) {
        No* noRemovido = inicio; // Aponta para o primeiro nó da fila a ser removido
        inicio = inicio->proximo; // Atualiza o ponteiro do início para o próximo nó
        delete noRemovido; // Libera a memória do nó removido
    }
}

int main() {
    No* inicio = nullptr;
    No* fim = nullptr;

    cout << "Digite os valores para enfileirar (valor negativo ou nulo para encerrar):" <<endl;
    int valor;
    do {
        cout << "Valor: ";
        cin >> valor;

        if (valor > 0) {
            enfileira(inicio, fim, valor);
        }
    } while (valor > 0);

    imprimeFila(inicio);

    if (inicio != nullptr) {
        int elementoDesenfileirado = desenfileira(inicio);
        cout << "Elemento desenfileirado: " << elementoDesenfileirado <<endl;
    }

    int numElementos = contaElementos(inicio);
    cout << "Número de elementos na fila: " << numElementos <<endl;

    desenfileiraPares(inicio);

    liberaFila(inicio);

    return 0;
}
