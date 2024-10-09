\documentclass[a4paper,12pt]{article}
\usepackage[utf8]{inputenc}
\usepackage[brazil]{babel}
\usepackage{amsmath}
\usepackage{graphicx}
\usepackage{hyperref}

\title{Relatório: Análise Empírica de Algoritmos de Ordenação}
\author{João Victor Walcacer Giani e Daniel Nolêto Maciel Luz}
\date{\today}

\begin{document}

\maketitle

\newpage

\section{Introdução}

A ordenação de dados é uma tarefa fundamental em ciência da computação, tendo uma ampla aplicação em diversas áreas como banco de dados, algoritmos de busca, e em sistemas que necessitam de respostas eficientes e rápidas. Uma ordenação eficiente é crucial para otimizar o desempenho de um sistema, especialmente quando se trabalha com grandes volumes de dados. Vários algoritmos de ordenação foram desenvolvidos ao longo do tempo, cada um com suas características, pontos fortes e fracos, sendo utilizados conforme a necessidade do problema a ser resolvido.

Este trabalho tem como objetivo realizar uma análise comparativa dos algoritmos de ordenação \textit{Bubble Sort}, \textit{Selection Sort}, \textit{Insertion Sort}, \textit{Merge Sort}, \textit{Quick Sort} e \textit{Heap Sort}. A análise será feita tanto do ponto de vista teórico quanto prático, observando o desempenho de cada algoritmo com diferentes tamanhos de listas e distribuições de dados (ordenados, inversamente ordenados e aleatórios). Além disso, serão medidos o tempo de execução, o número de comparações e o número de trocas efetuadas por cada algoritmo.

\section{Revisão Teórica}

Nesta seção, serão descritos os algoritmos de ordenação implementados neste trabalho, abordando suas características principais: complexidade, se são in-place e sua estabilidade.

\subsection{Bubble Sort}
O \textit{Bubble Sort} é um algoritmo de ordenação simples que compara pares de elementos adjacentes e os troca se estiverem na ordem errada. Este processo é repetido até que a lista esteja ordenada.

\begin{itemize}
    \item \textbf{Complexidade:} A complexidade de tempo do \textit{Bubble Sort} no melhor caso é $O(n)$, quando a lista já está ordenada. Nos casos médio e pior, a complexidade é $O(n^2)$.
    \item \textbf{In-place:} Sim, o \textit{Bubble Sort} é um algoritmo in-place, pois não requer memória adicional significativa além da utilizada pela própria lista.
    \item \textbf{Estabilidade:} Sim, o \textit{Bubble Sort} é estável, já que ele preserva a ordem relativa dos elementos com chaves iguais.
\end{itemize}

\subsection{Selection Sort}
O \textit{Selection Sort} funciona selecionando o menor (ou maior) elemento de uma lista e o colocando na posição correta. Este processo é repetido até que a lista esteja ordenada.

\begin{itemize}
    \item \textbf{Complexidade:} A complexidade de tempo do \textit{Selection Sort} é $O(n^2)$ em todos os casos, já que sempre é necessário percorrer a lista para encontrar o menor elemento.
    \item \textbf{In-place:} Sim, o \textit{Selection Sort} é in-place, pois a ordenação ocorre dentro do próprio array.
    \item \textbf{Estabilidade:} Não, o \textit{Selection Sort} não é estável, pois pode trocar elementos iguais, alterando sua ordem relativa.
\end{itemize}

\subsection{Insertion Sort}
O \textit{Insertion Sort} ordena a lista construindo uma sublista ordenada à esquerda, inserindo elementos da lista desordenada à direita em suas posições corretas.

\begin{itemize}
    \item \textbf{Complexidade:} A complexidade de tempo no melhor caso é $O(n)$, quando a lista já está ordenada. No caso médio e pior, a complexidade é $O(n^2)$.
    \item \textbf{In-place:} Sim, o \textit{Insertion Sort} é in-place, pois não requer espaço adicional significativo.
    \item \textbf{Estabilidade:} Sim, o \textit{Insertion Sort} é estável, já que preserva a ordem relativa dos elementos iguais.
\end{itemize}

\subsection{Merge Sort}
O \textit{Merge Sort} é um algoritmo de ordenação baseado na técnica de divisão e conquista. Ele divide a lista em duas sublistas, ordena-as recursivamente e, em seguida, as mescla de volta em uma lista ordenada.

\begin{itemize}
    \item \textbf{Complexidade:} A complexidade de tempo do \textit{Merge Sort} é $O(n \log n)$ em todos os casos, devido à divisão recursiva da lista.
    \item \textbf{In-place:} Não, o \textit{Merge Sort} não é in-place, pois requer espaço adicional para armazenar as sublistas temporárias durante o processo de merge.
    \item \textbf{Estabilidade:} Sim, o \textit{Merge Sort} é estável, pois preserva a ordem relativa dos elementos iguais durante o processo de merge.
\end{itemize}

\subsection{Quick Sort}
O \textit{Quick Sort} também usa a técnica de divisão e conquista, escolhendo um elemento como pivô e particionando a lista em sublistas com elementos menores e maiores que o pivô. O processo é repetido recursivamente.

\begin{itemize}
    \item \textbf{Complexidade:} A complexidade de tempo no melhor e médio caso é $O(n \log n)$, mas no pior caso, quando o pivô escolhido não é o ideal, a complexidade pode ser $O(n^2)$.
    \item \textbf{In-place:} Sim, o \textit{Quick Sort} é in-place, já que a ordenação ocorre dentro do próprio array sem necessidade de memória extra significativa.
    \item \textbf{Estabilidade:} Não, o \textit{Quick Sort} não é estável, pois a troca de elementos pode alterar a ordem relativa de elementos iguais.
\end{itemize}

\subsection{Heap Sort}
O \textit{Heap Sort} utiliza uma estrutura de dados chamada heap (máximo ou mínimo) para organizar os elementos. O algoritmo constrói um heap a partir da lista e, em seguida, extrai os elementos em ordem.

\begin{itemize}
    \item \textbf{Complexidade:} A complexidade de tempo do \textit{Heap Sort} é $O(n \log n)$ em todos os casos, devido à operação de construção e remoção do heap.
    \item \textbf{In-place:} Sim, o \textit{Heap Sort} é in-place, já que ele ordena a lista sem usar memória adicional significativa.
    \item \textbf{Estabilidade:} Não, o \textit{Heap Sort} não é estável, pois a ordem relativa de elementos iguais pode ser alterada durante a organização do heap.
\end{itemize}


\section{Metodologia}

A seguir, são descritos os aspectos referentes ao ambiente de teste e ao procedimento utilizado para a realização dos experimentos.

\subsection{Ambiente de Teste}

\subsubsection{Hardware}
O hardware utilizado para a execução dos algoritmos de ordenação foi um notebook \textit{Nitro 5} da \textit{Acer} com as seguintes especificações: processador \textit{Intel(R) Core(TM) i7-10750H CPU @ 2.60GHz 2.59 GHz}, 24GB de memória RAM, armazenamento em SSD de 480GB e uma placa de vídeo dedicada \textit{GTX 1650} com 4GB de VRAM.

\subsubsection{Software}
O ambiente de desenvolvimento escolhido foi o \textit{Visual Studio Code}, utilizando o \textit{Windows} como sistema operacional. A linguagem de programação adotada foi \textit{C}, devido à sua eficiência e velocidade de execução. Inicialmente, tentamos utilizar \textit{Python} para a implementação, mas os tempos de execução observados eram muito maiores (mais de dez vezes mais lentos) em comparação ao \textit{C}.

\subsection{Procedimentos}

Para medir o tempo de execução dos algoritmos, utilizamos a biblioteca \texttt{time.h} da linguagem \textit{C}, convertendo os tempos para milissegundos. Além disso, para contar o número de comparações e trocas efetuadas por cada algoritmo, foram criadas duas variáveis: \textbf{comparacoes}, que era incrementada em +1 a cada comparação realizada, e \textbf{trocas}, que também era incrementada em +1 a cada troca de elementos efetuada pelo algoritmo.


\subsection{Implementação dos Algoritmos}

A implementação dos algoritmos seguiu um padrão geral em C, com foco na eficiência e clareza do código. Inicialmente, foram realizadas pesquisas teóricas sobre o funcionamento de cada algoritmo, seguidas da prática com a codificação. Todos os algoritmos compartilham uma estrutura similar, onde a entrada é lida a partir de arquivos \texttt{.txt}, contendo listas geradas previamente. Essas listas são utilizadas para garantir consistência nos testes de desempenho, com diferentes padrões de ordenação: listas aleatórias, já ordenadas e inversamente ordenadas. 

Para o controle de versão, utilizamos o Git, e todo o repositório com o código-fonte está disponível no GitHub, acessível pelo link abaixo:

\begin{itemize}
    \item \url{https://github.com/SEU_REPOSITORIO}
\end{itemize}

\subsection{Medição das Métricas}

Para a avaliação do desempenho dos algoritmos, foram medidas três métricas principais: tempo de execução, número de comparações e número de trocas realizadas durante o processo de ordenação. Essas métricas foram implementadas diretamente no código, com contadores dedicados para comparações e trocas, além da utilização da função \texttt{clock()} da biblioteca \texttt{time.h} para medir o tempo de execução.

O procedimento para medir essas métricas foi o seguinte: 
\begin{enumerate}
    \item As listas de entrada foram lidas de arquivos \texttt{.txt}, sendo que cada algoritmo processa as mesmas listas em diferentes formatos (aleatória, ordenada e inversa).
    \item Durante a execução de cada algoritmo, incrementamos contadores para cada comparação entre elementos e para cada troca realizada.
    \item O tempo de execução foi capturado marcando o início e o término de cada execução com a função \texttt{clock()}, e o resultado foi convertido para milissegundos para maior precisão.
\end{enumerate}

Dessa forma, foi possível comparar o desempenho dos diferentes algoritmos com base nos padrões de listas utilizados, proporcionando uma análise detalhada de cada implementação.


\end{document}
