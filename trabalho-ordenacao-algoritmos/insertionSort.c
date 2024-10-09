#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

// Função de Insertion Sort com contagem de comparações e trocas
void insertion_sort(int *vetor, int tamanho, long long *comparacoes, long long *trocas) {
    for (int i = 1; i < tamanho; i++) {
        int chave = vetor[i];
        int j = i - 1;

        (*comparacoes)++;  // Conta a primeira comparação
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
            (*comparacoes)++;  // Conta as comparações no laço while
            (*trocas)++;  // Conta as trocas de posição
        }
        vetor[j + 1] = chave;
    }
}

// Função para testar o Insertion Sort e medir tempo, comparações e trocas
void testar_insertion_sort(int *lista, int tamanho, const char *descricao) {
    long long comparacoes = 0;  // Inicializa contagem de comparações
    long long trocas = 0;  // Inicializa contagem de trocas
    
    printf("Ordenando lista %s...\n", descricao);

    clock_t inicio = clock();  // Captura o tempo inicial

    insertion_sort(lista, tamanho, &comparacoes, &trocas);  // Ordena a lista

    clock_t fim = clock();  // Captura o tempo final
    double tempo_gasto = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;  // Tempo em milissegundos

    // Exibe as métricas
    printf("Métricas para a lista %s:\n", descricao);
    printf("Tempo de execução: %f milissegundos\n", tempo_gasto);
    printf("Número de comparações: %lld\n", comparacoes);
    printf("Número de trocas: %lld\n\n", trocas);
}

// Função para ler a lista de um arquivo .txt
int* ler_lista_de_arquivo(const char *nome_arquivo, int tamanho) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return NULL;
    }

    int *lista = (int*)malloc(tamanho * sizeof(int));
    for (int i = 0; i < tamanho; i++) {
        fscanf(arquivo, "%d", &lista[i]);
    }

    fclose(arquivo);
    return lista;
}

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    // Tamanhos das listas
    int mil = 1000;
    int dezMil = 10000;
    int cinquentaMil = 50000;
    int cemMil = 100000;

    // Ler listas de arquivos .txt
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

    // Testar o Insertion Sort com listas de tamanho 1.000
    testar_insertion_sort(MilAleatoria, mil, "Aleatória de 1.000 elementos");
    testar_insertion_sort(MilOrdenada, mil, "Ordenada de 1.000 elementos");
    testar_insertion_sort(MilInversa, mil, "Inversa de 1.000 elementos");

    // Testar o Insertion Sort com listas de tamanho 10.000
    testar_insertion_sort(DezAleatoria, dezMil, "Aleatória de 10.000 elementos");
    testar_insertion_sort(DezOrdenada, dezMil, "Ordenada de 10.000 elementos");
    testar_insertion_sort(DezInversa, dezMil, "Inversa de 10.000 elementos");

    // Testar o Insertion Sort com listas de tamanho 50.000
    testar_insertion_sort(CinquentaAleatoria, cinquentaMil, "Aleatória de 50.000 elementos");
    testar_insertion_sort(CinquentaOrdenada, cinquentaMil, "Ordenada de 50.000 elementos");
    testar_insertion_sort(CinquentaInversa, cinquentaMil, "Inversa de 50.000 elementos");

    // Testar o Insertion Sort com listas de tamanho 100.000
    testar_insertion_sort(CemAleatoria, cemMil, "Aleatória de 100.000 elementos");
    testar_insertion_sort(CemOrdenada, cemMil, "Ordenada de 100.000 elementos");
    testar_insertion_sort(CemInversa, cemMil, "Inversa de 100.000 elementos");

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
