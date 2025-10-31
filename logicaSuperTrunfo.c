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

// Função auxiliar para exibir menu de atributos
void exibirMenu(int excluir) {
    printf("\n=== Escolha um atributo para comparar ===\n");
    if (excluir != 1) printf("1 - População\n");
    if (excluir != 2) printf("2 - Área\n");
    if (excluir != 3) printf("3 - PIB\n");
    if (excluir != 4) printf("4 - Pontos turísticos\n");
    if (excluir != 5) printf("5 - Densidade demográfica\n");
    if (excluir != 6) printf("6 - PIB per capita\n");
    printf("Escolha uma opção: ");
}

// Função para obter o valor numérico de um atributo
double obterValor(Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontos_turisticos;
        case 5: return c.densidade;          // Menor vence
        case 6: return c.pib_per_capita;
        default: return 0;
    }
}

// Função para exibir o nome do atributo
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos turísticos";
        case 5: return "Densidade demográfica";
        case 6: return "PIB per capita";
        default: return "Desconhecido";
    }
}

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
    printf("  População: %d\n", carta1.populacao);
    printf("  Área: %.2f km²\n", carta1.area);
    printf("  PIB: %.2f\n", carta1.pib);
    printf("  Pontos turísticos: %d\n", carta1.pontos_turisticos);
    printf("  Densidade demográfica: %.2f\n", carta1.densidade);
    printf("  PIB per capita: %.2f\n\n", carta1.pib_per_capita);

    printf("Carta 2 - %s (%s):\n", carta2.nome, carta2.estado);
    printf("  População: %d\n", carta2.populacao);
    printf("  Área: %.2f km²\n", carta2.area);
    printf("  PIB: %.2f\n", carta2.pib);
    printf("  Pontos turísticos: %d\n", carta2.pontos_turisticos);
    printf("  Densidade demográfica: %.2f\n", carta2.densidade);
    printf("  PIB per capita: %.2f\n\n", carta2.pib_per_capita);

    // ======= MENU DE ESCOLHA DOS DOIS ATRIBUTOS =======
    int atributo1, atributo2;

    exibirMenu(0);
    scanf("%d", &atributo1);

    exibirMenu(atributo1);
    scanf("%d", &atributo2);

    if (atributo1 < 1 || atributo1 > 6 || atributo2 < 1 || atributo2 > 6 || atributo1 == atributo2) {
        printf("\nOpção inválida! Os atributos devem ser diferentes e válidos (1 a 6).\n");
        return 1;
    }

    // ======= COMPARAÇÃO AVANÇADA =======
    double valor1_c1 = obterValor(carta1, atributo1);
    double valor1_c2 = obterValor(carta2, atributo1);
    double valor2_c1 = obterValor(carta1, atributo2);
    double valor2_c2 = obterValor(carta2, atributo2);

    printf("\n=== Comparação Final ===\n");
    printf("Atributos escolhidos: %s e %s\n", nomeAtributo(atributo1), nomeAtributo(atributo2));

    printf("\n%s:\n", carta1.nome);
    printf("  %s: %.2f\n", nomeAtributo(atributo1), valor1_c1);
    printf("  %s: %.2f\n", nomeAtributo(atributo2), valor2_c1);

    printf("\n%s:\n", carta2.nome);
    printf("  %s: %.2f\n", nomeAtributo(atributo1), valor1_c2);
    printf("  %s: %.2f\n", nomeAtributo(atributo2), valor2_c2);

    // Regras de comparação (densidade é invertida)
    double pontuacao1 = 0, pontuacao2 = 0;

    // Atributo 1
    if (atributo1 == 5)
        (valor1_c1 < valor1_c2) ? (pontuacao1 += 1) : (valor1_c2 < valor1_c1 ? pontuacao2 += 1 : 0);
    else
        (valor1_c1 > valor1_c2) ? (pontuacao1 += 1) : (valor1_c2 > valor1_c1 ? pontuacao2 += 1 : 0);

    // Atributo 2
    if (atributo2 == 5)
        (valor2_c1 < valor2_c2) ? (pontuacao1 += 1) : (valor2_c2 < valor2_c1 ? pontuacao2 += 1 : 0);
    else
        (valor2_c1 > valor2_c2) ? (pontuacao1 += 1) : (valor2_c2 > valor2_c1 ? pontuacao2 += 1 : 0);

    // Soma final dos atributos (para decidir o vencedor em caso de empate de pontos)
    double soma_c1 = valor1_c1 + valor2_c1;
    double soma_c2 = valor1_c2 + valor2_c2;

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", carta1.nome, soma_c1);
    printf("%s: %.2f\n", carta2.nome, soma_c2);

    printf("\n=== Resultado Final ===\n");

    if (soma_c1 > soma_c2)
        printf("🏆 %s venceu a rodada!\n", carta1.nome);
    else if (soma_c2 > soma_c1)
        printf("🏆 %s venceu a rodada!\n", carta2.nome);
    else
        printf("🤝 Empate!\n");

    return 0;
}
