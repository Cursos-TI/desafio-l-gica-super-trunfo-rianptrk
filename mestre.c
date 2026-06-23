#include <stdio.h>

int main() {
    // Variáveis iniciais 
    char  estado_1[3],  estado_2[3];
    char  codigo_1[10], codigo_2[10];
    char  cidade_1[50], cidade_2[50];
    int   populacao_1, populacao_2;
    float area_1, area_2;
    float pib_1, pib_2;
    int   pontos_turisticos_1, pontos_turisticos_2;
    
    // Atributos calculados automaticamente
    float densidade_populacional1, densidade_populacional2;
    float pib_per_capita1, pib_per_capita2;

    // Variáveis novas para o Nível Mestre 
    int opcao1, opcao2;
    float peso1_carta1 = 0, peso1_carta2 = 0;
    float peso2_carta1 = 0, peso2_carta2 = 0;
    float total_carta1 = 0, total_carta2 = 0;

    // CAPTURA DE DADOS 
    printf("\n========== Cadastrar Carta 1 ==========\n");
    printf("Estado (Ex: A): "); scanf(" %s", estado_1);
    printf("Código (Ex: A01): "); scanf(" %s", codigo_1);
    printf("Cidade: "); scanf(" %s", cidade_1);
    printf("População: "); scanf(" %d", &populacao_1);
    printf("Área Km²: "); scanf(" %f", &area_1);
    printf("PIB: "); scanf(" %f", &pib_1);
    printf("Pontos Turísticos: "); scanf(" %d", &pontos_turisticos_1);

    printf("\n========== Cadastrar Carta 2 ==========\n");
    printf("Estado (Ex: B): "); scanf(" %s", estado_2);
    printf("Código (Ex: B02): "); scanf(" %s", codigo_2);
    printf("Cidade: "); scanf(" %s", cidade_2);
    printf("População: "); scanf(" %d", &populacao_2);
    printf("Área Km²: "); scanf(" %f", &area_2);
    printf("PIB: "); scanf(" %f", &pib_2);
    printf("Pontos Turísticos: "); scanf(" %d", &pontos_turisticos_2);

    // CÁLCULOS AUTOMÁTICOS 
    densidade_populacional1 = (float)populacao_1 / area_1;
    densidade_populacional2 = (float)populacao_2 / area_2;
    pib_per_capita1 = pib_1 / (float)populacao_1;
    pib_per_capita2 = pib_2 / (float)populacao_2;

    // MENUS DINÂMICOS 
    printf("\n========== MENU SUPER TRUNFO (NÍVEL MESTRE) ==========\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional\n6 - PIB Per Capita\n");
    
    printf("\nEscolha o PRIMEIRO atributo para comparação (1-6): ");
    scanf("%d", &opcao1);
    
    printf("Escolha o SEGUNDO atributo para comparação (1-6): ");
    scanf("%d", &opcao2);

    // Validação para garantir que os atributos são diferentes
    if (opcao1 == opcao2) {
        printf("\n[Erro] Não pode escolher o mesmo atributo duas vezes. Reinicie o programa.\n");
        return 0;
    }

    //  Atribuição de pesos para o ATRIBUTO 1 
    switch(opcao1) {
        case 1: peso1_carta1 = populacao_1; peso1_carta2 = populacao_2; break;
        case 2: peso1_carta1 = area_1; peso1_carta2 = area_2; break;
        case 3: peso1_carta1 = pib_1; peso1_carta2 = pib_2; break;
        case 4: peso1_carta1 = pontos_turisticos_1; peso1_carta2 = pontos_turisticos_2; break;
        // Na densidade multiplicamos por -1 porque o MENOR valor deve vencer (regra especial)
        case 5: peso1_carta1 = -densidade_populacional1; peso1_carta2 = -densidade_populacional2; break; 
        case 6: peso1_carta1 = pib_per_capita1; peso1_carta2 = pib_per_capita2; break;
        default: printf("Opção 1 inválida!\n"); return 0;
    }

    //  Atribuição de pesos para o ATRIBUTO 2 
    switch(opcao2) {
        case 1: peso2_carta1 = populacao_1; peso2_carta2 = populacao_2; break;
        case 2: peso2_carta1 = area_1; peso2_carta2 = area_2; break;
        case 3: peso2_carta1 = pib_1; peso2_carta2 = pib_2; break;
        case 4: peso2_carta1 = pontos_turisticos_1; peso2_carta2 = pontos_turisticos_2; break;
        case 5: peso2_carta1 = -densidade_populacional1; peso2_carta2 = -densidade_populacional2; break; 
        case 6: peso2_carta1 = pib_per_capita1; peso2_carta2 = pib_per_capita2; break;
        default: printf("Opção 2 inválida!\n"); return 0;
    }

    // Soma dos atributos escolhidos para gerar a pontuação final de cada carta
    total_carta1 = peso1_carta1 + peso2_carta1;
    total_carta2 = peso1_carta2 + peso2_carta2;

    // EXIBIÇÃO E DECISÃO (Operador Ternário) 
    printf("\n============== RESULTADO FINAL (MESTRE) ==============\n");
    printf("Pontuação Total Combinada da Carta 1 (%s): %.2f\n", cidade_1, total_carta1);
    printf("Pontuação Total Combinada da Carta 2 (%s): %.2f\n", cidade_2, total_carta2);

    // Uso de Operadores Ternários encadeados 
    printf("\nResultado Final: %s\n", 
        (total_carta1 > total_carta2) ? "A PRIMEIRA CARTA VENCEU!" : 
        (total_carta2 > total_carta1) ? "A SEGUNDA CARTA VENCEU!" : "O JOGO TERMINOU EM EMPATE!");

    return 0;
}
