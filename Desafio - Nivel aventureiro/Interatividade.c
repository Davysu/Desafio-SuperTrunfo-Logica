#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Para exit()

int main() {
    // --- Declaração das variáveis para Carta 1 ---
    char estado1[3], codigo1[10], nome1[50];
    unsigned long int populacao1;
    float area1, pib1;
    int pontos_turisticos1;
    float densidade1 = 0, pib_per_capita1 = 0;

    // --- Declaração das variáveis para Carta 2 ---
    char estado2[3], codigo2[10], nome2[50];
    unsigned long int populacao2;
    float area2, pib2;
    int pontos_turisticos2;
    float densidade2 = 0, pib_per_capita2 = 0;

    // --- Leitura dos dados da Carta 1 pelo usuário ---
    printf("--- Digite os dados da Carta 1 ---\n");
    printf("Estado (ex: SP): ");
    scanf("%2s", estado1);
    printf("Codigo (ex: SP01): ");
    scanf("%9s", codigo1);
    printf("Nome da Cidade/Pais: ");
    getchar(); // Consumir o newline deixado pelo scanf anterior
    fgets(nome1, 50, stdin);
    nome1[strcspn(nome1, "\n")] = 0; // Remover o newline
    printf("Populacao: ");
    scanf("%lu", &populacao1);
    printf("Area (em km²): ");
    scanf("%f", &area1);
    printf("PIB (em bilhoes de R$ ou USD): ");
    scanf("%f", &pib1);
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontos_turisticos1);

    // --- Leitura dos dados da Carta 2 pelo usuário ---
    printf("\n--- Digite os dados da Carta 2 ---\n");
    printf("Estado (ex: RJ): ");
    scanf("%2s", estado2);
    printf("Codigo (ex: RJ01): ");
    scanf("%9s", codigo2);
    printf("Nome da Cidade/Pais: ");
    getchar(); // Consumir o newline
    fgets(nome2, 50, stdin);
    nome2[strcspn(nome2, "\n")] = 0;
    printf("Populacao: ");
    scanf("%lu", &populacao2);
    printf("Area (em km²): ");
    scanf("%f", &area2);
    printf("PIB (em bilhoes de R$ ou USD): ");
    scanf("%f", &pib2);
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontos_turisticos2);

    // --- Calculo Densidade Populacional e PIB per Capita ---
    // Realizar cálculos apenas se os denominadores forem válidos
    if (area1 > 0) {
        densidade1 = (float)populacao1 / area1;
    } else {
        printf("\nAviso: Area da Carta 1 invalida (<= 0). Densidade nao calculada.\n");
    }
    if (populacao1 > 0) {
        pib_per_capita1 = (pib1 * 1000000000) / populacao1;
    } else {
        printf("\nAviso: Populacao da Carta 1 invalida (<= 0). PIB per capita nao calculado.\n");
    }

    if (area2 > 0) {
        densidade2 = (float)populacao2 / area2;
    } else {
        printf("\nAviso: Area da Carta 2 invalida (<= 0). Densidade nao calculada.\n");
    }
    if (populacao2 > 0) {
        pib_per_capita2 = (pib2 * 1000000000) / populacao2;
    } else {
        printf("\nAviso: Populacao da Carta 2 invalida (<= 0). PIB per capita nao calculado.\n");
    }

    // --- Menu Interativo para Escolha do Atributo ---
    int escolha;
    printf("\n====================\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1. Populacao\n");
    printf("2. Area\n");
    printf("3. PIB\n");
    printf("4. Pontos Turisticos\n");
    printf("5. Densidade Demografica (Menor vence)\n");
    printf("Opcao: ");
    scanf("%d", &escolha);

    // --- Comparação de Cartas com base na escolha ---
    printf("\n====================\n");
    printf("Comparacao de Cartas:\n");
    printf("Carta 1: %s (%s)\n", nome1, estado1);
    printf("Carta 2: %s (%s)\n", nome2, estado2);
    printf("--------------------\n");

    switch (escolha) {
        case 1: // População
            printf("Atributo: Populacao\n");
            printf("Carta 1: %lu\n", populacao1);
            printf("Carta 2: %lu\n", populacao2);
            if (populacao1 > populacao2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", nome1);
            } else if (populacao2 > populacao1) {
                printf("Resultado: Carta 2 (%s) venceu!\n", nome2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 2: // Área
            printf("Atributo: Area (km²)\n");
            printf("Carta 1: %.2f\n", area1);
            printf("Carta 2: %.2f\n", area2);
            if (area1 > area2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", nome1);
            } else if (area2 > area1) {
                printf("Resultado: Carta 2 (%s) venceu!\n", nome2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3: // PIB
            printf("Atributo: PIB (bilhoes)\n");
            printf("Carta 1: %.2f\n", pib1);
            printf("Carta 2: %.2f\n", pib2);
            if (pib1 > pib2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", nome1);
            } else if (pib2 > pib1) {
                printf("Resultado: Carta 2 (%s) venceu!\n", nome2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4: // Pontos Turísticos
            printf("Atributo: Pontos Turisticos\n");
            printf("Carta 1: %d\n", pontos_turisticos1);
            printf("Carta 2: %d\n", pontos_turisticos2);
            if (pontos_turisticos1 > pontos_turisticos2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", nome1);
            } else if (pontos_turisticos2 > pontos_turisticos1) {
                printf("Resultado: Carta 2 (%s) venceu!\n", nome2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5: // Densidade Demográfica (Menor vence)
            printf("Atributo: Densidade Demografica (hab/km²) - Menor vence\n");
            // Verificar se as densidades foram calculadas
            if (area1 <= 0 || area2 <= 0) {
                 printf("Nao foi possivel comparar Densidade: Area invalida em uma ou ambas as cartas.\n");
            } else {
                printf("Carta 1: %.2f\n", densidade1);
                printf("Carta 2: %.2f\n", densidade2);
                if (densidade1 < densidade2) {
                    printf("Resultado: Carta 1 (%s) venceu!\n", nome1);
                } else if (densidade2 < densidade1) {
                    printf("Resultado: Carta 2 (%s) venceu!\n", nome2);
                } else {
                    printf("Resultado: Empate!\n");
                }
            }
            break;

        default: // Opção inválida
            printf("Opcao invalida! Por favor, escolha um numero entre 1 e 5.\n");
            break;
    }

    printf("====================\n");

    return 0;
}

