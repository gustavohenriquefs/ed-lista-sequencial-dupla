#ifndef DOUBLEVECTOR_H
#define DOUBLEVECTOR_H

class DoubleVector {
  private: 
    int *m_list;
    int m_capacity;
    int m_size;
    int m_head;
    int m_tail; 

  public:
    // Construtor da classe. Deve iniciar todos os atributos da classe
    // de acordo com a descrição acima da lista.
    DoubleVector();

    // Construtor da classe. Aloca o vetor com capacidade n,
    // deixando espaços disponíveis na frente e atrás iguais.
    DoubleVector(int n);

    // Destrutor da classe. Libera memória previamente alocada.
    ~DoubleVector();

    // Retorna o número de elementos na lista.
    int size();

    // Retorna true se a lista estiver vazia e false caso contrário.
    bool empty();

    // Insere o inteiro value ao final da lista.
    void push_back(int value);

    // Remove elemento do final da lista e retorna seu valor.
    int pop_back();

    // Insere o inteiro value no início da lista.
    void push_front(int value);

    // Remove elemento do início da lista e retorna seu valor.
    int pop_front();

    // Retorna o elemento da lista de índice k (Cuidado, é o índice da
    // lista e não do vetor). A função verifica se k está dentro dos limites de elementos
    // válidos. Caso contrário, retorna -1. Obrigatoriamente deve ser O(1).
    int at(unsigned int index);

    // Realiza o deslocamento completo, seja para a direita ou esquerda,
    // de acordo a descrição na Seção 1.1.1.
    // Caso desejem, podem dividir em duas funções: left_shift e right_shift.
    void shift();

    // Realiza o redimensionamento, de acordo a descrição na Seção 1.2.
    void resize();

    // Remove o elemento de índice k da lista (Cuidado, é o índice
    // da lista e não do vetor) de acordo a descrição na Seção 1.1.2.
    // A ordem dos demais elementos da lista devem se manter.
    void remove(unsigned int index);

    // Remove da lista todas as ocorrências de value.
    // A ordem dos demais elementos da lista entre si devem se manter.
    void removeAll(int value);

    // Imprime os elementos da lista.
    void print();

    // Imprime os elementos da lista em ordem reversa.
    void printReverse();

    // Concatena a lista atual com a lista lst passada por parâmetro.
    // A lista lst não é modificada nessa operação.
    // Os elementos de lst serão adicionados na ordem no final da lista do objeto da função.
    void concat(DoubleVector& lst);

    // Determina se a lista passada por parâmetro é igual à lista em questão.
    // Duas listas são iguais se elas possuem o mesmo tamanho
    // e o valor do k-ésimo elemento da primeira lista é igual ao k-ésimo elemento da segunda lista.
    bool equals(DoubleVector& lst);

    void replaceAt(int value, unsigned int index);

    void insert(int value, unsigned int index);

};

#endif