#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Fun��o Bubble Sort com contagem de compara��es e trocas
void bubble_sort(int *lista, int n, long long *comparacoes, long long *trocas) {
    *comparacoes = 0;
    *trocas = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            (*comparacoes)++;  // registrar as compara��es
            if (lista[j] > lista[j + 1]) {
                // Troca de elementos
                int temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
                (*trocas)++;  // registrar as trocas
            }
        }
    }
}

// fun��o para gerar uma c�pia da lista
int* copiar_lista(int *lista, int tamanho) {
    int *nova_lista = (int*)malloc(tamanho * sizeof(int));
    for (int i = 0; i < tamanho; i++) {
        nova_lista[i] = lista[i];
    }
    return nova_lista;
}

// fun��o para testar o Bubble Sort e exibir as m�tricas
void testar_bubble_sort(int *lista, int tamanho, const char* nome_lista) {
    printf("\nOrdenando a lista %s usando Bubble Sort...\n", nome_lista);

    // Copiar a lista para n�o alterar a original
    int *lista_copia = copiar_lista(lista, tamanho);

    long long comparacoes = 0, trocas = 0;
    clock_t inicio = clock();  // inicio da medi��o do tempo

    // Chamar o Bubble Sort
    bubble_sort(lista_copia, tamanho, &comparacoes, &trocas);

    clock_t fim = clock();  // fim da medi��o do tempo
    double tempo_execucao = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;  // Convertendo para milissegundos

    // Exibir resultados
    printf("Tempo de Execu��o: %.4f ms\n", tempo_execucao);
    printf("N�mero de Compara��es: %lld\n", comparacoes);
    printf("N�mero de Trocas: %lld\n", trocas);
    printf("----------------------------------------\n");

    free(lista_copia);  // liberar mem�ria da c�pia da lista
}

// fun��o para gerar listas
void gerar_listas(int tamanho, int **lista_aleatoria, int **lista_ordenada, int **lista_inversa) {
    *lista_aleatoria = (int*)malloc(tamanho * sizeof(int));
    *lista_ordenada = (int*)malloc(tamanho * sizeof(int));
    *lista_inversa = (int*)malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++) {
        (*lista_aleatoria)[i] = rand() % tamanho + 1;
    }

    // Gerar lista ordenada
    for (int i = 0; i < tamanho; i++) {
        (*lista_ordenada)[i] = i + 1;
    }

    // Gerar lista inversamente ordenada
    for (int i = 0; i < tamanho; i++) {
        (*lista_inversa)[i] = tamanho - i;
    }

}

int main() {
    srand(time(NULL));  // inicializar a semente do gerador de n�meros aleat�rios

    setlocale(LC_ALL, "Portuguese_Brazil");
    // Tamanhos das listas
    int mil = 1000;
    int dezMil = 10000;
    int cinquentaMil = 50000;
    int cemMil = 100000;

    int *MilAleatoria, *MilOrdenada, *MilInversa;
    int *DezAleatoria, *DezOrdenada, *DezInversa;
    int *CinquentaAleatoria, *CinquentaOrdenada, *CinquentaInversa;
    int *CemAleatoria, *CemOrdenada, *CemInversa;

    // Gerar listas de tamanhos variados
    gerar_listas(mil, &MilAleatoria, &MilOrdenada, &MilInversa);
    gerar_listas(dezMil, &DezAleatoria, &DezOrdenada, &DezInversa);
    gerar_listas(cinquentaMil, &CinquentaAleatoria, &CinquentaOrdenada, &CinquentaInversa);
    gerar_listas(cemMil, &CemAleatoria, &CemOrdenada, &CemInversa);

    // Testar o Bubble Sort com listas de tamanho 1.000
    testar_bubble_sort(MilAleatoria, mil, "Aleat�ria de 1.000 elementos");
    testar_bubble_sort(MilOrdenada, mil, "Ordenada de 1.000 elementos");
    testar_bubble_sort(MilInversa, mil, "Inversa de 1.000 elementos");

    // Testar o Bubble Sort com listas de tamanho 10.000
    testar_bubble_sort(DezAleatoria, dezMil, "Aleat�ria de 10.000 elementos");
    testar_bubble_sort(DezOrdenada, dezMil, "Ordenada de 10.000 elementos");
    testar_bubble_sort(DezInversa, dezMil, "Inversa de 10.000 elementos");

    // Testar o Bubble Sort com listas de tamanho 50.000
    testar_bubble_sort(CinquentaAleatoria, cinquentaMil, "Aleat�ria de 50.000 elementos");
    testar_bubble_sort(CinquentaOrdenada, cinquentaMil, "Ordenada de 50.000 elementos");
    testar_bubble_sort(CinquentaInversa, cinquentaMil, "Inversa de 50.000 elementos");

    

    // Testar o Bubble Sort com listas de tamanho 100.000
    testar_bubble_sort(CemAleatoria, cemMil, "Aleat�ria de 100.000 elementos");
    testar_bubble_sort(CemOrdenada, cemMil, "Ordenada de 100.000 elementos");
    testar_bubble_sort(CemInversa, cemMil, "Inversa de 100.000 elementos");

    // Liberar mem�ria alocada
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
