---

# Repositório do Trabalho de Análise de Algoritmos de Ordenação

Este repositório contém os arquivos relacionados ao trabalho de análise de algoritmos de ordenação realizado no contexto da disciplina de Projeto e Análise de Algoritmos (PAA). Abaixo estão os principais arquivos e pastas do projeto, juntamente com as descrições.

# O Trabalho foi desenvolvido pelos alunos: João Victor Walcacer Giani e Daniel Nolêto Maciel Luz

## Conteúdo

- **Relatório**: Relatório explicando os experimentos e resultados obtidos com os algoritmos de ordenação. O relatório foi disponibilizado em formato .pdf e .tex, e foi disponibilizado também o link para o relatório no OverLeaf
  - [Relatório.pdf](https://github.com/joaovictorwg/PAA/blob/main/trabalho-ordenacao-algoritmos/Relatorio.pdf)
  - [Relatório.tex](https://github.com/joaovictorwg/PAA/blob/main/trabalho-ordenacao-algoritmos/relatorio.tex)
  - [Relatório no Overleaf](https://www.overleaf.com/read/qxvqhjfsczmz#56b596)

- **Listas de Teste**: Conjunto de listas usadas para testar os algoritmos de ordenação com diferentes cenários (aleatórias, ordenadas e inversamente ordenadas).
  - [Listas de Teste](https://github.com/joaovictorwg/PAA/tree/main/trabalho-ordenacao-algoritmos/listas)

- **Implementações dos Algoritmos de Ordenação**:
  - [Bubble Sort](https://github.com/joaovictorwg/PAA/blob/main/trabalho-ordenacao-algoritmos/bubbleSort.c)
  - [Selection Sort](https://github.com/joaovictorwg/PAA/blob/main/trabalho-ordenacao-algoritmos/selectionSort.c)
  - [Insertion Sort](https://github.com/joaovictorwg/PAA/blob/main/trabalho-ordenacao-algoritmos/insertionSort.c)
  - [Merge Sort](https://github.com/joaovictorwg/PAA/blob/main/trabalho-ordenacao-algoritmos/mergeSort.c)
  - [Quick Sort](https://github.com/joaovictorwg/PAA/blob/main/trabalho-ordenacao-algoritmos/quickSort.c)
  - [Heap Sort](https://github.com/joaovictorwg/PAA/blob/main/trabalho-ordenacao-algoritmos/heapSort.c)

- **Dados de Execução e Métricas**: Arquivo CSV contendo os tempos de execução, número de comparações e trocas realizadas pelos algoritmos.
  - [algorithms_comparison.csv](https://github.com/joaovictorwg/PAA/blob/main/trabalho-ordenacao-algoritmos/algorithms_comparison.csv)

- **Código para Gerar Gráficos**: Script em Python (Jupyter Notebook) que gera gráficos com base nos dados de execução.
  - [graficos.ipynb](https://github.com/joaovictorwg/PAA/blob/main/trabalho-ordenacao-algoritmos/graficos.ipynb)

## Como Usar

1. Clone o repositório para sua máquina local:
   ```bash
   git clone https://github.com/joaovictorwg/PAA.git
   ```

2. Navegue até a pasta do trabalho de algoritmos de ordenação:
   ```bash
   cd PAA/trabalho-ordenacao-algoritmos
   ```

3. Para compilar e executar os algoritmos em C, utilize um compilador como o `gcc`:
   ```bash
   gcc bubbleSort.c -o bubbleSort
   ./bubbleSort
   ```

4. Para visualizar os gráficos, abra o arquivo `graficos.ipynb` com um ambiente Jupyter.

## Estrutura do Repositório

- `Relatorio.pdf`: Documento contendo a descrição dos algoritmos, os resultados obtidos e a análise comparativa.
- `listas/`: Pastas com listas de números (aleatórios, ordenados e inversos) usados para testar os algoritmos.
- Arquivos `.c`: Implementações dos algoritmos de ordenação.
- `algorithms_comparison.csv`: Dados de execução dos algoritmos.
- `graficos.ipynb`: Código para gerar gráficos com base nos dados de execução.

---
