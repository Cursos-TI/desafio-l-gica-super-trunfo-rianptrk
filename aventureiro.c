#include <stdio.h>

int main() {
    // Variáveis iniciais
    char  estado_1[3],  estado_2[3];
    char  codigo_1[10], codigo_2[10];
    char  cidade_1[50], cidade_2[50];
    int   populacao_1, populacao_2;
    float densidade_populacional1, densidade_populacional2;
    float pib_per_capita1, pib_per_capita2; 
    float area_1, area_2;
    float pib_1, pib_2;
    int   pontos_turisticos_1, pontos_turisticos_2;
    int   opcao; // Variável para o menu

    // Captura de Dados da Carta 1
    printf("\n========== Primeira Carta ==========\n");
    printf("Estado: "); scanf(" %s", estado_1); 
    printf("Codigo: "); scanf(" %s", codigo_1);
    printf("Cidade: "); scanf(" %s", cidade_1);
    printf("Populacao: "); scanf(" %d", &populacao_1);
    printf("Area Km²: "); scanf(" %f", &area_1);
    printf("PIB: "); scanf(" %f", &pib_1);
    printf("Pontos Turisticos: "); scanf(" %d", &pontos_turisticos_1);

    // Captura de Dados da Carta 2
    printf("\n========== Segunda Carta ==========\n");
    printf("Estado: "); scanf(" %s", estado_2);
    printf("Codigo: "); scanf(" %s", codigo_2);
    printf("Cidade: "); scanf(" %s", cidade_2);
    printf("Populacao: "); scanf(" %d", &populacao_2);
    printf("Area Km²: "); scanf(" %f", &area_2);
    printf("PIB: "); scanf(" %f", &pib_2);
    printf("Pontos Turisticos: "); scanf(" %d", &pontos_turisticos_2);

    // Cálculos
    densidade_populacional1 = (float)populacao_1 / area_1;
    densidade_populacional2 = (float)populacao_2 / area_2;
    pib_per_capita1 = pib_1 / (float)populacao_1;
    pib_per_capita2 = pib_2 / (float)populacao_2;

    // Menu Interativo (Nível Aventureiro)
    printf("\n========== MENU DE COMPARAÇÃO (AVENTUREIRO) ==========\n");
    printf("Escolha o atributo para comparar as cartas:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional\n6 - PIB Per Capita\n");
    printf("Digite a sua opção (1-6): ");
    scanf("%d", &opcao);

    printf("\n--- Resultado da Comparação ---\n");

    switch (opcao) {
        case 1:
            if (populacao_1 > populacao_2) printf("Vencedor: CARTA 1 (%s)!\n", cidade_1);
            else if (populacao_2 > populacao_1) printf("Vencedor: CARTA 2 (%s)!\n", cidade_2);
            else printf("Empate na População!\n");
            break;
        case 2:
            if (area_1 > area_2) printf("Vencedor: CARTA 1 (%s)!\n", cidade_1);
            else if (area_2 > area_1) printf("Vencedor: CARTA 2 (%s)!\n", cidade_2);
            else printf("Empate na Área!\n");
            break;
        case 3:
            if (pib_1 > pib_2) printf("Vencedor: CARTA 1 (%s)!\n", cidade_1);
            else if (pib_2 > pib_1) printf("Vencedor: CARTA 2 (%s)!\n", cidade_2);
            else printf("Empate no PIB!\n");
            break;
        case 4:
            if (pontos_turisticos_1 > pontos_turisticos_2) printf("Vencedor: CARTA 1 (%s)!\n", cidade_1);
            else if (pontos_turisticos_2 > pontos_turisticos_1) printf("Vencedor: CARTA 2 (%s)!\n", cidade_2);
            else printf("Empate nos Pontos Turísticos!\n");
            break;
        case 5: // MENOR VENCE
            if (densidade_populacional1 < densidade_populacional2) printf("Vencedor: CARTA 1 (%s)!\n", cidade_1);
            else if (densidade_populacional2 < densidade_populacional1) printf("Vencedor: CARTA 2 (%s)!\n", cidade_2);
            else printf("Empate na Densidade!\n");
            break;
        case 6:
            if (pib_per_capita1 > pib_per_capita2) printf("Vencedor: CARTA 1 (%s)!\n", cidade_1);
            else if (pib_per_capita2 > pib_per_capita1) printf("Vencedor: CARTA 2 (%s)!\n", cidade_2);
            else printf("Empate no PIB Per Capita!\n");
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }
    return 0;
}
