#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Função para trocar dois elementos
void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para encontrar a mediana de três valores
int mediana(int a, int b, int c) {
    if ((a >= b && a <= c) || (a <= b && a >= c)) return a;
    if ((b >= a && b <= c) || (b <= a && b >= c)) return b;
    return c;
}

// Função de partição do Quick Sort
int particao(int *lista, int baixo, int alto, long long *comparacoes, long long *trocas) {
    int meio = baixo + (alto - baixo) / 2;
    int pivo = mediana(lista[baixo], lista[meio], lista[alto]); // Escolhe a mediana como pivô
    if (pivo == lista[meio]) troca(&lista[meio], &lista[alto]); // Mover o pivô para o final
    else if (pivo == lista[baixo]) troca(&lista[baixo], &lista[alto]);

    int i = baixo - 1;

    for (int j = baixo; j < alto; j++) {
        (*comparacoes)++;  // Contagem de comparações
        if (lista[j] < pivo) {
            i++;
            troca(&lista[i], &lista[j]);
            (*trocas)++;  // Contagem de trocas
        }
    }
    troca(&lista[i + 1], &lista[alto]);
    (*trocas)++;  // Contagem de trocas
    return i + 1;
}

// Função Quick Sort com contagem de comparações e trocas
void quick_sort(int *lista, int baixo, int alto, long long *comparacoes, long long *trocas) {
    if (baixo < alto) {
        int pi = particao(lista, baixo, alto, comparacoes, trocas);

        // Ordenar recursivamente as duas metades
        quick_sort(lista, baixo, pi - 1, comparacoes, trocas);
        quick_sort(lista, pi + 1, alto, comparacoes, trocas);
    }
}

// Função para ler lista de um arquivo .txt
int* ler_lista_de_arquivo(const char *nome_arquivo, int tamanho) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        exit(1);
    }

    int *lista = (int*)malloc(tamanho * sizeof(int));
    for (int i = 0; i < tamanho; i++) {
        fscanf(arquivo, "%d", &lista[i]);
    }

    fclose(arquivo);
    return lista;
}

// Função para testar o Quick Sort e exibir as métricas
void testar_quick_sort(int *lista, int tamanho, const char* nome_lista) {
    printf("\nOrdenando a lista %s usando Quick Sort...\n", nome_lista);

    // Copiar a lista para não alterar a original
    int *lista_copia = (int*)malloc(tamanho * sizeof(int));
    for (int i = 0; i < tamanho; i++) {
        lista_copia[i] = lista[i];
    }

    long long comparacoes = 0, trocas = 0;
    clock_t inicio = clock();  // Inicio da medição do tempo

    // Chamar o Quick Sort
    quick_sort(lista_copia, 0, tamanho - 1, &comparacoes, &trocas);

    clock_t fim = clock();  // Fim da medição do tempo
    double tempo_execucao = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;  // Convertendo para milissegundos

    // Exibir resultados
    printf("Tempo de Execução: %.4f ms\n", tempo_execucao);
    printf("Número de Comparações: %lld\n", comparacoes);
    printf("Número de Trocas: %lld\n", trocas);
    printf("----------------------------------------\n");

    free(lista_copia);  // Liberar memória da cópia da lista
}

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    // Tamanhos das listas
    int mil = 1000;
    int dezMil = 10000;
    int cinquentaMil = 50000;
    int cemMil = 100000;

    // Ler listas de arquivos .txt dentro da pasta "listas"
    int *MilAleatoria = ler_lista_de_arquivo("listas/lista_aleatoria_1000.txt", mil);
    int *MilOrdenada = ler_lista_de_arquivo("listas/lista_ordenada_1000.txt", mil);
    int *MilInversa = ler_lista_de_arquivo("listas/lista_inversa_1000.txt", mil);

    int *DezAleatoria = ler_lista_de_arquivo("listas/lista_aleatoria_10000.txt", dezMil);
    int *DezOrdenada = ler_lista_de_arquivo("listas/lista_ordenada_10000.txt", dezMil);
    int *DezInversa = ler_lista_de_arquivo("listas/lista_inversa_10000.txt", dezMil);

    int *CinquentaAleatoria = ler_lista_de_arquivo("listas/lista_aleatoria_50000.txt", cinquentaMil);
    int *CinquentaOrdenada = ler_lista_de_arquivo("listas/lista_ordenada_50000.txt", cinquentaMil);
    int *CinquentaInversa = ler_lista_de_arquivo("listas/lista_inversa_50000.txt", cinquentaMil);

    int *CemAleatoria = ler_lista_de_arquivo("listas/lista_aleatoria_100000.txt", cemMil);
    int *CemOrdenada = ler_lista_de_arquivo("listas/lista_ordenada_100000.txt", cemMil);
    int *CemInversa = ler_lista_de_arquivo("listas/lista_inversa_100000.txt", cemMil);

    // Testar o Quick Sort com listas de tamanho 1.000
    testar_quick_sort(MilAleatoria, mil, "Aleatória de 1.000 elementos");
    testar_quick_sort(MilOrdenada, mil, "Ordenada de 1.000 elementos");
    testar_quick_sort(MilInversa, mil, "Inversa de 1.000 elementos");

    // Testar o Quick Sort com listas de tamanho 10.000
    testar_quick_sort(DezAleatoria, dezMil, "Aleatória de 10.000 elementos");
    testar_quick_sort(DezOrdenada, dezMil, "Ordenada de 10.000 elementos");
    testar_quick_sort(DezInversa, dezMil, "Inversa de 10.000 elementos");

    // Testar o Quick Sort com listas de tamanho 50.000
    testar_quick_sort(CinquentaAleatoria, cinquentaMil, "Aleatória de 50.000 elementos");
    testar_quick_sort(CinquentaOrdenada, cinquentaMil, "Ordenada de 50.000 elementos");
    testar_quick_sort(CinquentaInversa, cinquentaMil, "Inversa de 50.000 elementos");

    // Testar o Quick Sort com listas de tamanho 100.000
    testar_quick_sort(CemAleatoria, cemMil, "Aleatória de 100.000 elementos");
    testar_quick_sort(CemOrdenada, cemMil, "Ordenada de 100.000 elementos");
    testar_quick_sort(CemInversa, cemMil, "Inversa de 100.000 elementos");

    // Liberar a memória das listas lidas
    free(MilAleatoria);
    free(MilOrdenada);
    free(MilInversa);

    free(DezAleatoria);
    free(DezOrdenada);
    free(DezInversa);

    free(CinquentaAleatoria);
    free(CinquentaOrdenada);
    free(CinquentaInversa);

    free(CemAleatoria);
    free(CemOrdenada);
    free(CemInversa);

    return 0;
}
