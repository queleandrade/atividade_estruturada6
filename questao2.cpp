
#include <iostream>

using namespace std;


struct Aluno {
    int matricula;
    float media;
    Aluno* proximo; // Ponteiro para o próximo aluno na fila
};


void enfileiraAluno(Aluno*& inicio, Aluno*& fim, int matricula, float media) {
    // Cria um novo aluno
    Aluno* novoAluno = new Aluno;
    novoAluno->matricula = matricula;
    novoAluno->media = media;
    novoAluno->proximo = nullptr; // O próximo aluno é inicializado como nullptr

    // Verifica se a fila está vazia
    if (inicio == nullptr) {
        inicio = novoAluno; // O novo aluno é o primeiro da fila
        fim = novoAluno; // O novo aluno também é o último da fila
    } else {
        fim->proximo = novoAluno; // Atualiza o ponteiro do último aluno para o novo aluno
        fim = novoAluno; // Atualiza o ponteiro do último para o novo aluno
    }
}

void imprimeAlunos(const Aluno* inicio) {
    cout << "Alunos na fila:" <<endl;

    const Aluno* atual = inicio; // Ponteiro para percorrer a fila
    while (atual != nullptr) {
        // Imprime os dados do aluno atual
        cout << "Matrícula: " << atual->matricula << ", Média: " << atual->media << endl;
        atual = atual->proximo; // Avança para o próximo aluno
    }

    cout << endl;
}

// Função para desenfileirar os alunos com média igual ou superior a 5
void desenfileiraAlunos(Aluno*& inicio) {
    cout << "Desenfileirando alunos com média igual ou superior a 5:" <<endl;

    while (inicio != nullptr) {
        Aluno* aluno = inicio; // Aponta para o primeiro aluno da fila
        inicio = inicio->proximo; // Atualiza o ponteiro do início para o próximo aluno

        if (aluno->media >= 5.0) {
            // Imprime a matrícula do aluno se a média for igual ou superior a 5
            cout << "Matrícula: " << aluno->matricula <<endl;
        }

        delete aluno; // Libera a memória do aluno desenfileirado, delete -> operador
    }
}

// Função para liberar a memória alocada pela fila
void liberaFila(Aluno*& inicio) {
    while (inicio != nullptr) {
        Aluno* aluno = inicio; // Aponta para o primeiro aluno da fila
        inicio = inicio->proximo; // Atualiza o ponteiro do início para o próximo aluno

        delete aluno; // Libera a memória do aluno
    }
}

int main() {
    int n;
    cout << "Digite a quantidade de alunos: ";
    cin >> n;

    if (n < 0) {
        cout << "Quantidade inválida." << endl;
        return 1;
    }

    Aluno* inicio = nullptr;
    Aluno* fim = nullptr;

    for (int i = 0; i < n; ++i) {
        int matricula;
        float media;

        cout << "Digite a matrícula do aluno " << i + 1 << ": ";
        cin >> matricula;
        cout << "Digite a média do aluno " << i + 1 << ": ";
        cin >> media;

        enfileiraAluno(inicio, fim, matricula, media);
    }

    imprimeAlunos(inicio);
    desenfileiraAlunos(inicio);
    liberaFila(inicio);

    return 0;
}
