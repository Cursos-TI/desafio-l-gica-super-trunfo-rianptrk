#include <stdio.h>

int main() {
    // Variáveis das Cartas
    char  estado_1[3],  estado_2[3];
    char  codigo_1[10], codigo_2[10];
    char  cidade_1[50], cidade_2[50];
    int   populacao_1, populacao_2;
    float area_1, area_2;
    float pib_1, pib_2;
    int   pontos_turisticos_1, pontos_turisticos_2;
    
    // Atributos calculados
    float densidade_populacional1, densidade_populacional2;
    float pib_per_capita1, pib_per_capita2;

    // Variáveis 
    char opcao1, opcao2;
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

    // MENUS 
    printf("\nBem-vindo ao jogo!\n");
    printf("Escolha o primeiro atributo.\n");
    printf("P. População\n");
    printf("A. Área\n");
    printf("I. PIB\n");
    printf("T. Pontos Turísticos\n");
    printf("D. Densidade Populacional\n");
    printf("C. PIB Per Capita\n");
    printf("Escolha a comparação: ");
    scanf(" %c", &opcao1); 

    printf("\nAtenção: Você deve escolher um atributo diferente do primeiro.\n");
    printf("Escolha a segunda comparação: ");
    scanf(" %c", &opcao2);

    if (opcao1 == opcao2) {
        printf("\nErro! Você escolheu o mesmo atributo.\n");
        return 0;
    }

    // Switch para a Opção 1
    switch(opcao1) {
        case 'P': case 'p': peso1_carta1 = populacao_1; peso1_carta2 = populacao_2; break;
        case 'A': case 'a': peso1_carta1 = area_1; peso1_carta2 = area_2; break;
        case 'I': case 'i': peso1_carta1 = pib_1; peso1_carta2 = pib_2; break;
        case 'T': case 't': peso1_carta1 = pontos_turisticos_1; peso1_carta2 = pontos_turisticos_2; break;
        case 'D': case 'd': peso1_carta1 = -densidade_populacional1; peso1_carta2 = -densidade_populacional2; break; 
        case 'C': case 'c': peso1_carta1 = pib_per_capita1; peso1_carta2 = pib_per_capita2; break;
        default: printf("Opção inválida!\n"); return 0;
    }

    // Switch para a Opção 2 
    switch(opcao2) {
        case 'P': case 'p': peso2_carta1 = populacao_1; peso2_carta2 = populacao_2; break;
        case 'A': case 'a': peso2_carta1 = area_1; peso2_carta2 = area_2; break;
        case 'I': case 'i': peso2_carta1 = pib_1; peso2_carta2 = pib_2; break;
        case 'T': case 't': peso2_carta1 = pontos_turisticos_1; peso2_carta2 = pontos_turisticos_2; break;
        case 'D': case 'd': peso2_carta1 = -densidade_populacional1; peso2_carta2 = -densidade_populacional2; break; 
        case 'C': case 'c': peso2_carta1 = pib_per_capita1; peso2_carta2 = pib_per_capita2; break;
        default: printf("Opção inválida!\n"); return 0;
    }

    // Soma das duas propriedades escolhidas
    total_carta1 = peso1_carta1 + peso2_carta1;
    total_carta2 = peso1_carta2 + peso2_carta2;

    // EXIBIÇÃO E DECISÃO TERNÁRIA 
    printf("\n============== RESULTADO FINAL (MESTRE) ==============\n");
    printf("Pontuação Total Combinada da Carta 1 (%s): %.2f\n", cidade_1, total_carta1);
    printf("Pontuação Total Combinada da Carta 2 (%s): %.2f\n", cidade_2, total_carta2);

    // Operador Ternário 
    printf("\nResultado Final: %s\n", 
        (total_carta1 > total_carta2) ? "A PRIMEIRA CARTA VENCEU!" : 
        (total_carta2 > total_carta1) ? "A SEGUNDA CARTA VENCEU!" : "O JOGO TERMINOU EM EMPATE!");

    return 0;
}
