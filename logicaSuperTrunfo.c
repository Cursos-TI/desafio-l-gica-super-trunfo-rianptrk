#include <stdio.h>

int main() {

    // Variáveis iniciais.
    char  estado_1[3],  estado_2[3];
    char  codigo_1[10], codigo_2[10];
    char  cidade_1[50], cidade_2[50];
    int   populacao_1, populacao_2;
    float densidade_populacional1, densidade_populacional2;
    float pib_per_capita1, pib_per_capita2; 
    float area_1, area_2;
    float pib_1, pib_2;
    int pontos_turisticos_1, pontos_turisticos_2;
    int pontosCarta1 = 0;
    int pontosCarta2 = 0;

    // Captura de Dados da Carta 1.
    printf("\n========== Primeira Carta ==========\n");

    printf("Estado: ");
    scanf(" %s", estado_1); 

    printf("Codigo: ");
    scanf(" %s", codigo_1);

    printf("Cidade: ");
    scanf(" %s", cidade_1);

    printf("Populacao: ");
    scanf(" %d", &populacao_1);

    printf("Area M²: ");
    scanf(" %f", &area_1);

    printf("PIB: ");
    scanf(" %f", &pib_1);

    printf("Pontos Turisticos: ");
    scanf(" %d", &pontos_turisticos_1);

    // Captura de Dados da Carta 2.
    printf("\n========== Segunda Carta ==========\n");

    printf("Estado: ");
    scanf(" %s", estado_2);

    printf("Codigo: ");
    scanf(" %s", codigo_2);

    printf("Cidade: ");
    scanf(" %s", cidade_2);

    printf("Populacao: ");
    scanf(" %d", &populacao_2);

    printf("Area M²: ");
    scanf(" %f", &area_2);

    printf("PIB: ");
    scanf(" %f", &pib_2);

    printf("Pontos Turisticos: ");
    scanf(" %d", &pontos_turisticos_2);

    // Calcula e Armazena a Densidade Populacional 
    densidade_populacional1 = (float)populacao_1 / area_1;
    densidade_populacional2 = (float)populacao_2 / area_2;

    // Calcula e Armazena o PIB Per Capita 
    pib_per_capita1 = pib_1 / (float)populacao_1;
    pib_per_capita2 = pib_2 / (float)populacao_2;

    // Verifica quem tem a maior População.
    if (populacao_1 > populacao_2) {
        pontosCarta1++;
    }
    else {
        pontosCarta2++;
    }

    // Verifica quem tem a maior Área.
    if (area_1 > area_2) {
        pontosCarta1++;
    }
    else {
        pontosCarta2++;
    }

    // Verifica quem tem maior PIB.
    if (pib_1 > pib_2) {
        pontosCarta1++;
    }
    else {
        pontosCarta2++;
    }

    // Verifica quem tem mais Pontos Turisticos.
    if (pontos_turisticos_1 > pontos_turisticos_2) {
        pontosCarta1++;
    }
    else {
        pontosCarta2++;
    }

    // Verifica quem tem a menor Densidade Populacional 
    // Se a regra do seu trabalho disser que a MAIOR vence, mude o sinal de < para >
    if (densidade_populacional1 < densidade_populacional2) {
        pontosCarta1++;
    }
    else {
        pontosCarta2++;
    }

    // Verifica quem tem o maior PIB Per Capita.
    if (pib_per_capita1 > pib_per_capita2) {
        pontosCarta1++;
    }
    else {
        pontosCarta2++;
    }

    // Exibe os dados capturados de ambas as Cartas.
    printf("\n========== Cartas Cadastradas ========== \n");

    printf("\n\n [Primeira Carta] \n\n");
    printf("Estado: %s\n", estado_1);
    printf("Codigo: %s\n", codigo_1);
    printf("Cidade: %s\n", cidade_1);
    printf("Populacao: %d\n", populacao_1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_populacional1);
    printf("Area M²: %.2f\n", area_1);
    printf("PIB (Produto Interno Bruto): %.2f\n", pib_1);
    printf("PIB Per Capita: R$%.2f\n", pib_per_capita1);
    printf("Pontos Turisticos: %d\n", pontos_turisticos_1);

    printf("\n\n [Segunda Carta] \n\n");
    printf("Estado: %s\n", estado_2);
    printf("Codigo: %s\n", codigo_2);
    printf("Cidade: %s\n", cidade_2);
    printf("Populacao: %d\n", populacao_2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_populacional2); // Corrigido para 2
    printf("Area M²: %.2f\n", area_2);
    printf("PIB (Produto Interno Bruto): %.2f\n", pib_2);
    printf("PIB Per Capita: R$%.2f\n", pib_per_capita2); // Corrigido para 2
    printf("Pontos Turisticos: %d\n", pontos_turisticos_2); // Corrigido para 2

    // Exibe qual carta ganhou o jogo com base nos pontos acumulados.
    printf("\n\n--- Resultado Final ---\n");
    printf("Pontuação - Carta 1: %d pontos | Carta 2: %d pontos\n", pontosCarta1, pontosCarta2);

    if (pontosCarta1 > pontosCarta2) {
        printf("\nVencedor: PRIMEIRA CARTA!\n");
    }
    else if (pontosCarta2 > pontosCarta1) {
        printf("\nVencedor: SEGUNDA CARTA!\n");
    }
    else {
        printf("\nO jogo terminou em EMPATE!\n");
    }

    return 0;
}
