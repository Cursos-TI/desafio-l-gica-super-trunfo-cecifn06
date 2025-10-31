#include <stdio.h>
#include <string.h>

#define NAME_LEN 64

typedef struct {
    char estado[NAME_LEN];
    char codigo[NAME_LEN];
    char nome[NAME_LEN];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    double densidade;
    double pib_per_capita;
} Carta;

int main(void) {
    Carta carta1, carta2;

    // Cadastro das Cartas
    printf("--- Cadastro da Carta 1 ---\n");
    printf("Estado: ");
    scanf("%63s", carta1.estado);
    printf("Código da carta: ");
    scanf("%63s", carta1.codigo);
    printf("Nome da cidade: ");
    scanf("%63s", carta1.nome);
    printf("População: ");
    scanf("%d", &carta1.populacao);
    printf("Área (km²): ");
    scanf("%f", &carta1.area);
    printf("PIB: ");
    scanf("%f", &carta1.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta1.pontos_turisticos);

    printf("\n--- Cadastro da Carta 2 ---\n");
    printf("Estado: ");
    scanf("%63s", carta2.estado);
    printf("Código da carta: ");
    scanf("%63s", carta2.codigo);
    printf("Nome da cidade: ");
    scanf("%63s", carta2.nome);
    printf("População: ");
    scanf("%d", &carta2.populacao);
    printf("Área (km²): ");
    scanf("%f", &carta2.area);
    printf("PIB: ");
    scanf("%f", &carta2.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta2.pontos_turisticos);

    // Cálculo de densidade e PIB per capita
    carta1.densidade = carta1.populacao / carta1.area;
    carta1.pib_per_capita = carta1.pib / carta1.populacao;

    carta2.densidade = carta2.populacao / carta2.area;
    carta2.pib_per_capita = carta2.pib / carta2.populacao;

    // Exibição das cartas
    printf("\n=== Cartas cadastradas ===\n\n");

    printf("Carta 1 - %s (%s):\n", carta1.nome, carta1.estado);
    printf("  Código: %s\n", carta1.codigo);
    printf("  População: %d\n", carta1.populacao);
    printf("  Área: %.2f km²\n", carta1.area);
    printf("  PIB: %.2f\n", carta1.pib);
    printf("  Pontos turísticos: %d\n", carta1.pontos_turisticos);
    printf("  Densidade populacional: %.2f hab/km²\n", carta1.densidade);
    printf("  PIB per capita: %.2f\n\n", carta1.pib_per_capita);

    printf("Carta 2 - %s (%s):\n", carta2.nome, carta2.estado);
    printf("  Código: %s\n", carta2.codigo);
    printf("  População: %d\n", carta2.populacao);
    printf("  Área: %.2f km²\n", carta2.area);
    printf("  PIB: %.2f\n", carta2.pib);
    printf("  Pontos turísticos: %d\n", carta2.pontos_turisticos);
    printf("  Densidade populacional: %.2f hab/km²\n", carta2.densidade);
    printf("  PIB per capita: %.2f\n\n", carta2.pib_per_capita);

    // ====== MENU INTERATIVO ======
    int opcao;
    printf("\n=== Escolha o atributo para comparar ===\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos turísticos\n");
    printf("5 - Densidade demográfica\n");
    printf("6 - PIB per capita\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    printf("\n=== Resultado da Comparação ===\n");
    switch (opcao) {
        case 1:
            printf("Atributo: População\n");
            printf("%s: %d habitantes\n", carta1.nome, carta1.populacao);
            printf("%s: %d habitantes\n", carta2.nome, carta2.populacao);
            if (carta1.populacao > carta2.populacao)
                printf("Vencedor: %s!\n", carta1.nome);
            else if (carta2.populacao > carta1.populacao)
                printf("Vencedor: %s!\n", carta2.nome);
            else
                printf("Empate!\n");
            break;

        case 2:
            printf("Atributo: Área\n");
            printf("%s: %.2f km²\n", carta1.nome, carta1.area);
            printf("%s: %.2f km²\n", carta2.nome, carta2.area);
            if (carta1.area > carta2.area)
                printf("Vencedor: %s!\n", carta1.nome);
            else if (carta2.area > carta1.area)
                printf("Vencedor: %s!\n", carta2.nome);
            else
                printf("Empate!\n");
            break;

        case 3:
            printf("Atributo: PIB\n");
            printf("%s: %.2f\n", carta1.nome, carta1.pib);
            printf("%s: %.2f\n", carta2.nome, carta2.pib);
            if (carta1.pib > carta2.pib)
                printf("Vencedor: %s!\n", carta1.nome);
            else if (carta2.pib > carta1.pib)
                printf("Vencedor: %s!\n", carta2.nome);
            else
                printf("Empate!\n");
            break;

        case 4:
            printf("Atributo: Pontos turísticos\n");
            printf("%s: %d pontos\n", carta1.nome, carta1.pontos_turisticos);
            printf("%s: %d pontos\n", carta2.nome, carta2.pontos_turisticos);
            if (carta1.pontos_turisticos > carta2.pontos_turisticos)
                printf("Vencedor: %s!\n", carta1.nome);
            else if (carta2.pontos_turisticos > carta1.pontos_turisticos)
                printf("Vencedor: %s!\n", carta2.nome);
            else
                printf("Empate!\n");
            break;

        case 5:
            printf("Atributo: Densidade demográfica\n");
            printf("%s: %.2f hab/km²\n", carta1.nome, carta1.densidade);
            printf("%s: %.2f hab/km²\n", carta2.nome, carta2.densidade);
            if (carta1.densidade < carta2.densidade)
                printf("Vencedor: %s!\n", carta1.nome);
            else if (carta2.densidade < carta1.densidade)
                printf("Vencedor: %s!\n", carta2.nome);
            else
                printf("Empate!\n");
            break;

        case 6:
            printf("Atributo: PIB per capita\n");
            printf("%s: %.2f\n", carta1.nome, carta1.pib_per_capita);
            printf("%s: %.2f\n", carta2.nome, carta2.pib_per_capita);
            if (carta1.pib_per_capita > carta2.pib_per_capita)
                printf("Vencedor: %s!\n", carta1.nome);
            else if (carta2.pib_per_capita > carta1.pib_per_capita)
                printf("Vencedor: %s!\n", carta2.nome);
            else
                printf("Empate!\n");
            break;

        default:
            printf("Opção inválida! Tente novamente.\n");
    }

    return 0;
}
