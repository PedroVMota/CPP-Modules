Claro, aqui está o README completo em português de Portugal, com o conteúdo organizado e traduzido de forma adequada:

---

# Algoritmo PmergeMe

Este repositório contém documentação para o algoritmo `PmergeMe`, disponível em ambas as línguas, inglês e português de Portugal.

## Idiomas Disponíveis

- [Documentação em Inglês](README_EN.md)
- [Documentação em Português](README_PT.md)

---

### README em Inglês (README_EN.md)

*Já fornecido acima.*

---

### README em Português (README_PT.md)

# Algoritmo PmergeMe

## Índice

1. [Introdução](#introdução)
2. [Visão Geral do Algoritmo](#visão-geral-do-algoritmo)
   - 2.1 [Estratégia de Ordenação](#estratégia-de-ordenação)
   - 2.2 [Divisão e Conquista](#divisão-e-conquista)
   - 2.3 [Mesclagem](#mesclagem)
   - 2.4 [Otimização com Insertion Sort](#otimização-com-insertion-sort)
3. [Descrição das Funções](#descrição-das-funções)
   - 3.1 [`merge(int left, int middle, int right)`](#mergeint-left-int-middle-int-right)
   - 3.2 [`insertionSort(int left, int right)`](#insertionsortint-left-int-right)
   - 3.3 [`mergeInsertionSort(int left, int right)`](#mergeinsertionsortint-left-int-right)
   - 3.4 [Construtor `PmergeMe(std::vector<double>& v)`](#construtor-pmergeme)
4. [Visualização Passo a Passo](#visualização-passo-a-passo)
5. [Exemplo de Utilização](#exemplo-de-utilização)
6. [Conclusão](#conclusão)

## Introdução

`PmergeMe` é um algoritmo de ordenação eficiente que combina as técnicas de Merge Sort e Insertion Sort para proporcionar um desempenho otimizado em uma vasta gama de cenários. Este algoritmo é particularmente útil quando o vetor contém subsequências pequenas, nas quais o insertion sort se destaca pela sua eficiência.

## Visão Geral do Algoritmo

### Estratégia de Ordenação

`PmergeMe` utiliza uma abordagem híbrida de ordenação, combinando as forças do **Merge Sort** para grandes conjuntos de dados e do **Insertion Sort** para problemas menores.

### Divisão e Conquista

O algoritmo começa por dividir o vetor original em duas metades. Esta divisão é feita recursivamente até que as subsequências sejam pequenas (≤ 10 elementos).

### Mesclagem

Após a divisão, as subsequências ordenadas são mescladas de volta no vetor original em ordem crescente. O processo de mesclagem é eficiente e garante que o vetor final esteja corretamente ordenado.

### Otimização com Insertion Sort

Para subsequências pequenas, `PmergeMe` utiliza o **Insertion Sort** em vez de continuar a divisão. Isto porque o insertion sort é mais rápido para pequenas quantidades de dados devido ao seu baixo overhead e simplicidade.

## Descrição das Funções

### `merge(int left, int middle, int right)`

- **Objetivo**: Mesclar duas subseções ordenadas do vetor em uma única sequência ordenada.
- **Como Funciona**:
  - A função divide o vetor em dois sub-vetores auxiliares com base nos índices `left`, `middle`, e `right`.
  - Em seguida, combina estes sub-vetores comparando os elementos e inserindo-os de volta no vetor original em ordem crescente.
- **Visualização**: Imagine o vetor original a ser dividido ao meio. A função `merge` pega estas duas partes ordenadas e combina-as como se estivesse a ordenar cartas de baralho.

### `insertionSort(int left, int right)`

- **Objetivo**: Ordenar uma pequena parte do vetor utilizando o algoritmo de insertion sort.
- **Como Funciona**:
  - Para cada elemento, começando pelo segundo, a função compara o elemento com os anteriores.
  - Se o elemento atual for menor, é deslocado para a esquerda até ficar na posição correta.
- **Visualização**: Pense em ordenar cartas na sua mão: cada carta é colocada na posição correta, movendo outras cartas para a direita se necessário.

### `mergeInsertionSort(int left, int right)`

- **Objetivo**: Ordenar o vetor combinando Merge Sort e Insertion Sort para otimizar o desempenho.
- **Como Funciona**:
  - A função verifica o tamanho da subsequência. Se for pequena (≤ 10 elementos), usa o Insertion Sort.
  - Se a subsequência for maior, divide-a ainda mais e aplica o Merge Sort recursivamente antes de mesclar.
- **Visualização**: Imagine dividir repetidamente o vetor até obter subsequências pequenas, depois ordenar e mesclar essas subsequências para formar o vetor final ordenado.

### Construtor `PmergeMe(std::vector<double>& v)`

- **Objetivo**: Inicializar a classe `PmergeMe` e ordenar o vetor fornecido.
- **Como Funciona**:
  - Se o vetor fornecido estiver vazio, uma mensagem de erro é exibida.
  - Caso contrário, o vetor é ordenado utilizando a função `mergeInsertionSort`.
- **Visualização**: Pense nisso como o ponto de partida: ao criar uma instância de `PmergeMe`, o vetor é imediatamente ordenado.

## Visualização Passo a Passo

### Vetor Inicial

```
[38.9, 27.4, 43.3, 3.9, 9.7, 82.1, 10.4, 14.5, 19.2]
```

### Primeira Divisão

```
Esquerda: [38.9, 27.4, 43.3, 3.9, 9.7]
Direita: [82.1, 10.4, 14.5, 19.2]
```

### Divisão Recursiva (Parte Esquerda)

```
Esquerda: [38.9, 27.4, 43.3]
Direita: [3.9, 9.7]
```

### Divisão Recursiva (Esquerda da Esquerda)

```
Esquerda: [38.9, 27.4]
Direita: [43.3]
```

### Insertion Sort (Subsequência Pequena)

```
[27.4, 38.9]
```

### Mesclagem

```
[27.4, 38.9, 43.3]
```

### Insertion Sort (Direita da Esquerda)

```
[3.9, 9.7]
```

### Mesclagem da Parte Esquerda

```
[3.9, 9.7, 27.4, 38.9, 43.3]
```

### Divisão Recursiva (Parte Direita)

```
Esquerda: [82.1, 10.4]
Direita: [14.5, 19.2]
```

### Insertion Sort (Subsequências Pequenas)

```
[10.4, 82.1]
[14.5, 19.2]
```

### Mesclagem da Parte Direita

```
[10.4, 14.5, 19.2, 82.1]
```

### Mesclagem Final

```
[3.9, 9.7, 10.4, 14.5, 19.2, 27.4, 38.9, 43.3, 82.1]
```

## Exemplo de Utilização

Aqui está um exemplo simples de como usar a classe `PmergeMe`:

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<double> vec = {38.9, 27.4, 43.3, 3.9, 9.7, 82.1, 10.4, 14.5, 19.2};

    PmergeMe sorter(vec);

    std::cout << "Vetor ordenado: ";
    for (double num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

**Saída:**

```
Vetor ordenado: 3.9 9.7 10.4 14.5 19.2 27.4 38.9 43.3 82.1
```

## Conclusão

`PmergeMe` oferece uma solução eficiente e prática para a ordenação de vetores, combinando as forças do Merge Sort e do Insertion Sort. Ao aproveitar ambas as abordagens, o algoritmo alcança um desempenho robusto para uma variedade de casos.

---

Este README proporciona uma visão clara e organizada do algoritmo `PmergeMe`, tanto em inglês quanto em português, garantindo que todas as informações necessárias estejam bem apresentadas.