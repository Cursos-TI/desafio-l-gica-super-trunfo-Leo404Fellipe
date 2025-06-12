#include <stdio.h>
Jogo de logica
// Função para mostrar o menu e pegar a escolha do usuário
int menu() {
    int opc;
    printf("\nEscolha o que comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Densidade Populacional\n");
    printf("5 - PIB per Capita\n");
    printf("6 - Pontos Turisticos\n");
    printf("7 - Super Poder\n");
    printf("8 - Comparar dois atributos\n");
    printf("0 - Sair\n");
    printf("Opcao: ");
    scanf("%d", &opc);
    return opc;
}

// Função para comparar um atributo (retorna 1 se carta1 vence, 2 se carta2 vence, 0 empate)
// 'menor_eh_melhor' indica se o menor valor vence (ex: densidade populacional)
int comparar_float(float val1, float val2, int menor_eh_melhor) {
    if (val1 == val2) return 0;
    if (menor_eh_melhor)
        return (val1 < val2) ? 1 : 2;
    else
        return (val1 > val2) ? 1 : 2;
}

int comparar_int(int val1, int val2, int menor_eh_melhor) {
    if (val1 == val2) return 0;
    if (menor_eh_melhor)
        return (val1 < val2) ? 1 : 2;
    else
        return (val1 > val2) ? 1 : 2;
}

int comparar_ulong(unsigned long val1, unsigned long val2, int menor_eh_melhor) {
    if (val1 == val2) return 0;
    if (menor_eh_melhor)
        return (val1 < val2) ? 1 : 2;
    else
        return (val1 > val2) ? 1 : 2;
}

int main() {
    // Declaração das variáveis da carta 1
    char estado1, codigo1[5], nome1[50];
    unsigned long pop1;
    float area1, pib1;
    int pontos1;

    // Declaração das variáveis da carta 2
    char estado2, codigo2[5], nome2[50];
    unsigned long pop2;
    float area2, pib2;
    int pontos2;

    // Variáveis para cálculos extras
    float dens1, dens2;
    float pibCap1, pibCap2;
    float poder1, poder2;

    printf("Cadastro da Carta 1:\n");
    printf("Digite o Estado (uma letra de A a H): ");
    scanf(" %c", &estado1);

    printf("Digite o Codigo da Carta (ex: A01): ");
    scanf("%4s", codigo1);

    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", nome1);

    printf("Digite a Populacao: ");
    scanf("%lu", &pop1);

    printf("Digite a Area (km²): ");
    scanf("%f", &area1);

    printf("Digite o PIB (bilhoes): ");
    scanf("%f", &pib1);

    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &pontos1);

    printf("\nCadastro da Carta 2:\n");
    printf("Digite o Estado (uma letra de A a H): ");
    scanf(" %c", &estado2);

    printf("Digite o Codigo da Carta (ex: B02): ");
    scanf("%4s", codigo2);

    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", nome2);

    printf("Digite a Populacao: ");
    scanf("%lu", &pop2);

    printf("Digite a Area (km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB (bilhoes): ");
    scanf("%f", &pib2);

    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &pontos2);

    // Calculando densidade populacional e PIB per capita
    dens1 = pop1 / area1;
    dens2 = pop2 / area2;

    pibCap1 = pib1 / pop1;
    pibCap2 = pib2 / pop2;

    // Calculando super poder (com densidade invertida)
    poder1 = pop1 + area1 + pib1 + pontos1 + pibCap1 + (1.0f / dens1);
    poder2 = pop2 + area2 + pib2 + pontos2 + pibCap2 + (1.0f / dens2);

    // Mostrar as cartas completas
    printf("\n--- Carta 1 ---\n");
    printf("Estado: %c\nCodigo: %s\nNome: %s\nPopulacao: %lu\nArea: %.2f km²\nPIB: %.2f bilhoes\nPontos Turisticos: %d\nDensidade Populacional: %.2f\nPIB per Capita: %.8f\nSuper Poder: %.2f\n",
        estado1, codigo1, nome1, pop1, area1, pib1, pontos1, dens1, pibCap1, poder1);

    printf("\n--- Carta 2 ---\n");
    printf("Estado: %c\nCodigo: %s\nNome: %s\nPopulacao: %lu\nArea: %.2f km²\nPIB: %.2f bilhoes\nPontos Turisticos: %d\nDensidade Populacional: %.2f\nPIB per Capita: %.8f\nSuper Poder: %.2f\n",
        estado2, codigo2, nome2, pop2, area2, pib2, pontos2, dens2, pibCap2, poder2);

    int opcao;
    do {
        opcao = menu();

        if (opcao >=1 && opcao <=7) {
            int vencedor = 0;
            // Só para simplificar, mapeamos a opção para os valores corretos
            switch (opcao) {
                case 1: // Populacao
                    vencedor = comparar_ulong(pop1, pop2, 0);
                    break;
                case 2: // Area
                    vencedor = comparar_float(area1, area2, 0);
                    break;
                case 3: // PIB
                    vencedor = comparar_float(pib1, pib2, 0);
                    break;
                case 4: // Densidade Populacional (menor vence)
                    vencedor = comparar_float(dens1, dens2, 1);
                    break;
                case 5: // PIB per Capita
                    vencedor = comparar_float(pibCap1, pibCap2, 0);
                    break;
                case 6: // Pontos Turisticos
                    vencedor = comparar_int(pontos1, pontos2, 0);
                    break;
                case 7: // Super Poder
                    vencedor = comparar_float(poder1, poder2, 0);
                    break;
            }

            if (vencedor == 0)
                printf("Empate nessa comparacao!\n");
            else
                printf("Carta %d venceu essa comparacao!\n", vencedor);
        }
        else if (opcao == 8) {
            // Comparar dois atributos escolhidos
            int atr1, atr2;
            printf("Escolha o primeiro atributo para comparar (1 a 7): ");
            scanf("%d", &atr1);
            printf("Escolha o segundo atributo para comparar (1 a 7): ");
            scanf("%d", &atr2);

            int vencedor1 = 0, vencedor2 = 0;
            // Função para comparar de forma repetida
            // Populacao (1)
            if (atr1 == 1) vencedor1 = comparar_ulong(pop1, pop2, 0);
            else if (atr1 == 2) vencedor1 = comparar_float(area1, area2, 0);
            else if (atr1 == 3) vencedor1 = comparar_float(pib1, pib2, 0);
            else if (atr1 == 4) vencedor1 = comparar_float(dens1, dens2, 1);
            else if (atr1 == 5) vencedor1 = comparar_float(pibCap1, pibCap2, 0);
            else if (atr1 == 6) vencedor1 = comparar_int(pontos1, pontos2, 0);
            else if (atr1 == 7) vencedor1 = comparar_float(poder1, poder2, 0);

            if (atr2 == 1) vencedor2 = comparar_ulong(pop1, pop2, 0);
            else if (atr2 == 2) vencedor2 = comparar_float(area1, area2, 0);
            else if (atr2 == 3) vencedor2 = comparar_float(pib1, pib2, 0);
            else if (atr2 == 4) vencedor2 = comparar_float(dens1, dens2, 1);
            else if (atr2 == 5) vencedor2 = comparar_float(pibCap1, pibCap2, 0);
            else if (atr2 == 6) vencedor2 = comparar_int(pontos1, pontos2, 0);
            else if (atr2 == 7) vencedor2 = comparar_float(poder1, poder2, 0);

            printf("\nResultado da primeira comparacao (atributo %d): ", atr1);
            if (vencedor1 == 0) printf("Empate!\n");
            else printf("Carta %d venceu!\n", vencedor1);

            printf("Resultado da segunda comparacao (atributo %d): ", atr2);
            if (vencedor2 == 0) printf("Empate!\n");
            else printf("Carta %d venceu!\n", vencedor2);

            // Decidir vencedor final baseado nas duas comparações
            if (vencedor1 == vencedor2) {
                if (vencedor1 == 0)
                    printf("Empate geral! Voces sao igualmente fortes!\n");
                else
                    printf("Carta %d venceu no geral!\n", vencedor1);
            }
            else {
                // Se um venceu uma e o outro venceu outra, empate geral
                printf("Comparacoes divergentes! Empate geral!\n");
            }

        }
        else if (opcao != 0) {
            printf("Opcao invalida, tente novamente.\n");
        }

    } while (opcao != 0);

    printf("Fim do programa. Obrigado por jogar!\n");
    return 0;
}
