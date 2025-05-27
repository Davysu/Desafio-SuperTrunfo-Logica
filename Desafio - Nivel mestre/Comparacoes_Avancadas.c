#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Para exit() e outras funções
#include <limits.h> // Para INT_MAX

// Constantes para os atributos (melhora a legibilidade)
#define POPULACAO 1
#define AREA 2
#define PIB 3
#define PONTOS_TURISTICOS 4
#define DENSIDADE 5

// Função auxiliar para limpar o buffer de entrada (evita problemas com scanf)
void limpar_buffer_entrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função auxiliar para obter o nome do atributo com base no código
const char* obter_nome_atributo(int codigo_atributo) {
    switch (codigo_atributo) {
        case POPULACAO: return "Populacao";
        case AREA: return "Area (km²)";
        case PIB: return "PIB (bilhoes)";
        case PONTOS_TURISTICOS: return "Pontos Turisticos";
        case DENSIDADE: return "Densidade Demografica (hab/km²)";
        default: return "Desconhecido";
    }
}

// Função auxiliar para obter o valor de um atributo específico de uma carta
// Retorna um valor double para acomodar floats e ints. Retorna -1.0 em caso de erro.
double obter_valor_atributo(int codigo_atributo, 
                             unsigned long int populacao, float area, float pib, int pontos_turisticos,
                             float densidade) {
    switch (codigo_atributo) {
        case POPULACAO:
            return (double)populacao;
        case AREA:
            return (double)area;
        case PIB:
            return (double)pib;
        case PONTOS_TURISTICOS:
            return (double)pontos_turisticos;
        case DENSIDADE:
            // A densidade já foi calculada antes, mas verificamos a área novamente por segurança
            if (area > 0) {
                return (double)densidade;
            } else {
                printf("Erro: Nao e possivel usar Densidade pois a Area e invalida.\n");
                return -1.0; // Indica erro
            }
        default:
            return -1.0; // Código de atributo inválido
    }
}

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
    limpar_buffer_entrada();
    printf("Codigo (ex: SP01): ");
    scanf("%9s", codigo1);
    limpar_buffer_entrada();
    printf("Nome da Cidade/Pais: ");
    fgets(nome1, 50, stdin);
    nome1[strcspn(nome1, "\n")] = 0;
    printf("Populacao: ");
    while (scanf("%lu", &populacao1) != 1) { // Validação básica de entrada numérica
        printf("Entrada invalida. Digite um numero para Populacao: ");
        limpar_buffer_entrada();
    }
    limpar_buffer_entrada();
    printf("Area (em km²): ");
    while (scanf("%f", &area1) != 1 || area1 <= 0) { // Valida número e se é positivo
        printf("Entrada invalida. Digite um numero positivo para Area: ");
        limpar_buffer_entrada();
    }
    limpar_buffer_entrada();
    printf("PIB (em bilhoes de R$ ou USD): ");
     while (scanf("%f", &pib1) != 1) {
        printf("Entrada invalida. Digite um numero para PIB: ");
        limpar_buffer_entrada();
    }
    limpar_buffer_entrada();
    printf("Numero de Pontos Turisticos: ");
    while (scanf("%d", &pontos_turisticos1) != 1) {
        printf("Entrada invalida. Digite um numero para Pontos Turisticos: ");
        limpar_buffer_entrada();
    }
    limpar_buffer_entrada();

    // --- Leitura dos dados da Carta 2 pelo usuário ---
    printf("\n--- Digite os dados da Carta 2 ---\n");
    printf("Estado (ex: RJ): ");
    scanf("%2s", estado2);
    limpar_buffer_entrada();
    printf("Codigo (ex: RJ01): ");
    scanf("%9s", codigo2);
    limpar_buffer_entrada();
    printf("Nome da Cidade/Pais: ");
    fgets(nome2, 50, stdin);
    nome2[strcspn(nome2, "\n")] = 0;
    printf("Populacao: ");
    while (scanf("%lu", &populacao2) != 1) {
        printf("Entrada invalida. Digite um numero para Populacao: ");
        limpar_buffer_entrada();
    }
    limpar_buffer_entrada();
    printf("Area (em km²): ");
    while (scanf("%f", &area2) != 1 || area2 <= 0) {
        printf("Entrada invalida. Digite um numero positivo para Area: ");
        limpar_buffer_entrada();
    }
    limpar_buffer_entrada();
    printf("PIB (em bilhoes de R$ ou USD): ");
    while (scanf("%f", &pib2) != 1) {
        printf("Entrada invalida. Digite um numero para PIB: ");
        limpar_buffer_entrada();
    }
    limpar_buffer_entrada();
    printf("Numero de Pontos Turisticos: ");
    while (scanf("%d", &pontos_turisticos2) != 1) {
        printf("Entrada invalida. Digite um numero para Pontos Turisticos: ");
        limpar_buffer_entrada();
    }
    limpar_buffer_entrada();

    // --- Calculo Densidade Populacional e PIB per Capita ---
    // Cálculos feitos aqui para estarem disponíveis caso Densidade seja escolhida
    if (area1 > 0) densidade1 = (float)populacao1 / area1;
    if (populacao1 > 0) pib_per_capita1 = (pib1 * 1000000000) / populacao1;
    if (area2 > 0) densidade2 = (float)populacao2 / area2;
    if (populacao2 > 0) pib_per_capita2 = (pib2 * 1000000000) / populacao2;

    // --- Escolha dos Dois Atributos --- 
    int escolha1 = 0, escolha2 = 0;
    int atributos_disponiveis[] = {POPULACAO, AREA, PIB, PONTOS_TURISTICOS, DENSIDADE};
    int num_atributos = sizeof(atributos_disponiveis) / sizeof(atributos_disponiveis[0]);

    // Menu para o primeiro atributo
    printf("\n====================\n");
    printf("Escolha o PRIMEIRO atributo para comparar:\n");
    for (int i = 0; i < num_atributos; i++) {
        printf("%d. %s\n", atributos_disponiveis[i], obter_nome_atributo(atributos_disponiveis[i]));
    }
    printf("Opcao 1: ");
    while (scanf("%d", &escolha1) != 1 || (escolha1 < 1 || escolha1 > num_atributos)) {
        printf("Opcao invalida. Escolha um numero entre 1 e %d: ", num_atributos);
        limpar_buffer_entrada();
    }
    limpar_buffer_entrada();

    // Menu dinâmico para o segundo atributo
    printf("\nEscolha o SEGUNDO atributo para comparar (diferente de %s):\n", obter_nome_atributo(escolha1));
    int contador_opcoes = 0;
    int mapeamento_opcoes[num_atributos]; // Mapeia opção do menu para código do atributo

    for (int i = 0; i < num_atributos; i++) {
        if (atributos_disponiveis[i] != escolha1) {
            contador_opcoes++;
            printf("%d. %s\n", contador_opcoes, obter_nome_atributo(atributos_disponiveis[i]));
            mapeamento_opcoes[contador_opcoes] = atributos_disponiveis[i]; // Guarda o código real
        }
    }
    printf("Opcao 2: ");
    int opcao_menu2;
    while (scanf("%d", &opcao_menu2) != 1 || (opcao_menu2 < 1 || opcao_menu2 > contador_opcoes)) {
        printf("Opcao invalida. Escolha um numero entre 1 e %d: ", contador_opcoes);
        limpar_buffer_entrada();
    }
    limpar_buffer_entrada();
    escolha2 = mapeamento_opcoes[opcao_menu2]; // Obtém o código real do atributo

    // --- Obter valores dos atributos escolhidos --- 
    double valor1_atr1 = obter_valor_atributo(escolha1, populacao1, area1, pib1, pontos_turisticos1, densidade1);
    double valor1_atr2 = obter_valor_atributo(escolha2, populacao1, area1, pib1, pontos_turisticos1, densidade1);
    double valor2_atr1 = obter_valor_atributo(escolha1, populacao2, area2, pib2, pontos_turisticos2, densidade2);
    double valor2_atr2 = obter_valor_atributo(escolha2, populacao2, area2, pib2, pontos_turisticos2, densidade2);

    // Verificar se houve erro ao obter algum valor (ex: área inválida para densidade)
    if (valor1_atr1 < 0 || valor1_atr2 < 0 || valor2_atr1 < 0 || valor2_atr2 < 0) {
        printf("\nErro ao obter valores dos atributos. Comparacao cancelada.\n");
        return 1; // Termina o programa com erro
    }

    // --- Calcular Somas Ponderadas (Considerando regra da Densidade) ---
    // Para simplificar a soma, vamos 'normalizar' a pontuação da densidade.
    // Se densidade for escolhida, o 'ponto' vai para quem tem MENOS.
    // Podemos fazer isso invertendo a comparação ou ajustando os valores antes de somar.

    double pontos1_atr1 = valor1_atr1;
    double pontos2_atr1 = valor2_atr1;
    if (escolha1 == DENSIDADE) {
        // Inverte a lógica: quem tem menos 'ganha' mais pontos (simulado)
        // Se valor1 < valor2, pontos1 > pontos2. Usamos um truque simples:
        pontos1_atr1 = (valor1_atr1 != valor2_atr1) ? (valor2_atr1) : valor1_atr1; // Troca se diferente
        pontos2_atr1 = (valor1_atr1 != valor2_atr1) ? (valor1_atr1) : valor2_atr1;
    }

    double pontos1_atr2 = valor1_atr2;
    double pontos2_atr2 = valor2_atr2;
     if (escolha2 == DENSIDADE) {
        pontos1_atr2 = (valor1_atr2 != valor2_atr2) ? (valor2_atr2) : valor1_atr2;
        pontos2_atr2 = (valor1_atr2 != valor2_atr2) ? (valor1_atr2) : valor2_atr2;
    }

    // Calcular as somas dos 'pontos' (valores originais ou invertidos para densidade)
    double soma1 = pontos1_atr1 + pontos1_atr2;
    double soma2 = pontos2_atr1 + pontos2_atr2;

    // --- Exibição Detalhada do Resultado ---
    printf("\n====================\n");
    printf("Resultado da Comparacao:\n");
    printf("Carta 1: %s (%s)\n", nome1, estado1);
    printf("Carta 2: %s (%s)\n", nome2, estado2);
    printf("--------------------\n");
    printf("Atributo 1: %s\n", obter_nome_atributo(escolha1));
    printf("  -> Carta 1: %.2f\n", valor1_atr1);
    printf("  -> Carta 2: %.2f\n", valor2_atr1);
    printf("Atributo 2: %s\n", obter_nome_atributo(escolha2));
    printf("  -> Carta 1: %.2f\n", valor1_atr2);
    printf("  -> Carta 2: %.2f\n", valor2_atr2);
    printf("--------------------\n");
    printf("Soma Ponderada Carta 1: %.2f\n", soma1);
    printf("Soma Ponderada Carta 2: %.2f\n", soma2);
    printf("--------------------\n");

    // Determinar Vencedor com base na Soma
    if (soma1 > soma2) {
        printf("Resultado Final: Carta 1 (%s) venceu!\n", nome1);
    } else if (soma2 > soma1) {
        printf("Resultado Final: Carta 2 (%s) venceu!\n", nome2);
    } else {
        printf("Resultado Final: Empate!\n");
    }

    printf("====================\n");

    return 0;
}

