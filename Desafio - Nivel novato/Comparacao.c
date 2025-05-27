#include <stdio.h>
#include <string.h> // Incluir para usar strcpy, embora não seja mais necessário para a entrada

int main() {
    // --- Declaração das variáveis para Carta 1 ---
    char estado1[3], codigo1[10], nome1[50];
    unsigned long int populacao1;
    float area1, pib1;
    int pontos_turisticos1;
    float densidade1, pib_per_capita1;

    // --- Declaração das variáveis para Carta 2 ---
    char estado2[3], codigo2[10], nome2[50];
    unsigned long int populacao2;
    float area2, pib2;
    int pontos_turisticos2;
    float densidade2, pib_per_capita2;

    // --- Leitura dos dados da Carta 1 pelo usuário ---
    printf("--- Digite os dados da Carta 1 ---\n");
    printf("Estado (ex: SP): ");
    scanf("%2s", estado1); // Limita a leitura a 2 caracteres para evitar overflow
    printf("Codigo (ex: SP01): ");
    scanf("%9s", codigo1); // Limita a leitura a 9 caracteres
    printf("Nome da Cidade: ");
    // Consumir o newline deixado pelo scanf anterior
    getchar(); // ou scanf(" %[^\n]", nome1);
    fgets(nome1, 50, stdin); // Usar fgets para ler nomes com espaços
    nome1[strcspn(nome1, "\n")] = 0; // Remover o newline que fgets pode incluir
    printf("Populacao: ");
    scanf("%lu", &populacao1);
    printf("Area (em km²): ");
    scanf("%f", &area1);
    printf("PIB (em bilhoes de R$): ");
    scanf("%f", &pib1);
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontos_turisticos1);

    // --- Leitura dos dados da Carta 2 pelo usuário ---
    printf("\n--- Digite os dados da Carta 2 ---\n");
    printf("Estado (ex: RJ): ");
    scanf("%2s", estado2);
    printf("Codigo (ex: RJ01): ");
    scanf("%9s", codigo2);
    printf("Nome da Cidade: ");
    getchar(); // Consumir o newline
    fgets(nome2, 50, stdin);
    nome2[strcspn(nome2, "\n")] = 0;
    printf("Populacao: ");
    scanf("%lu", &populacao2);
    printf("Area (em km²): ");
    scanf("%f", &area2);
    printf("PIB (em bilhoes de R$): ");
    scanf("%f", &pib2);
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontos_turisticos2);

    // --- Calculo Densidade Populacional e PIB per Capita ---
    // Certificar que a área não é zero para evitar divisão por zero
    if (area1 > 0) {
        densidade1 = populacao1 / area1;
    } else {
        densidade1 = 0; // Ou tratar como erro
        printf("\nAviso: Area da Carta 1 é zero ou inválida. Densidade definida como 0.\n");
    }
    // Certificar que a população não é zero para evitar divisão por zero
    if (populacao1 > 0) {
        pib_per_capita1 = (pib1 * 1000000000) / populacao1; // PIB convertido de bilhões para reais
    } else {
        pib_per_capita1 = 0; // Ou tratar como erro
        printf("\nAviso: Populacao da Carta 1 é zero ou inválida. PIB per capita definido como 0.\n");
    }

    if (area2 > 0) {
        densidade2 = populacao2 / area2;
    } else {
        densidade2 = 0;
        printf("\nAviso: Area da Carta 2 é zero ou inválida. Densidade definida como 0.\n");
    }
    if (populacao2 > 0) {
        pib_per_capita2 = (pib2 * 1000000000) / populacao2;
    } else {
        pib_per_capita2 = 0;
        printf("\nAviso: Populacao da Carta 2 é zero ou inválida. PIB per capita definido como 0.\n");
    }

    // --- Exibindo os dados calculados ---
    printf("\n====================\n");
    printf("Dados Calculados:\n");
    printf("Carta 1 (%s) - Densidade: %.2f hab/km², PIB per Capita: R$ %.2f\n", nome1, densidade1, pib_per_capita1);
    printf("Carta 2 (%s) - Densidade: %.2f hab/km², PIB per Capita: R$ %.2f\n", nome2, densidade2, pib_per_capita2);

    // --- Comparação de Cartas (Atributo Escolhido: População) ---
    printf("\n====================\n");
    printf("Comparacao de Cartas (Atributo: Populacao):\n");

    // A escolha do atributo continua fixa no código (População)
    printf("Carta 1 - %s (%s): %lu\n", nome1, estado1, populacao1);
    printf("Carta 2 - %s (%s): %lu\n", nome2, estado2, populacao2);

    // Lógica de comparação usando if-else
    if (populacao1 > populacao2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", nome1);
    } else if (populacao2 > populacao1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", nome2);
    } else {
        printf("Resultado: Empate!\n");
    }

    printf("====================\n");

    return 0;
}

