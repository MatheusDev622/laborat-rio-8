#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estrutura.h"
#include "dados.h"
#include "data.h"
#include "atualizacao.h"
#include "ordenacao.h"

void menuPrincipal(informacoes_conta *conta) {
    int opcao;

    while (1) {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Adicionar investimento\n");
        printf("2. Editar investimento\n");
        printf("3. Ver investimentos\n");
        printf("4. Deletar investimento\n");
        printf("5. Ordenar investimentos\n");
        printf("6. Ver valor bruto e líquido\n");
        printf("7. Limpar todos os dados (resetar)\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                if (conta->qtd_investimentos >= MAX_REG) {
                    printf("\n⚠️ Limite de %d investimentos atingido.\n", MAX_REG);
                    break;
                }
                {
                    int i = conta->qtd_investimentos;
                    printf("\n--- Novo Investimento ---\n");
                    printf("Digite a data: ");
                    fgets(conta->investimentos[i].data, TAM, stdin);
                    printf("Digite o valor: R$ ");
                    scanf("%f", &conta->investimentos[i].valor);
                    getchar();
                    printf("Digite o tipo do investimento: ");
                    fgets(conta->investimentos[i].tipo, TAM, stdin);
                    printf("Digite o nome do papel/ativo: ");
                    fgets(conta->investimentos[i].nome, TAM, stdin);
                    printf("Digite a data de vencimento: ");
                    fgets(conta->investimentos[i].data_vencimento, TAM, stdin);
                    printf("Digite a taxa de juros: ");
                    scanf("%f", &conta->investimentos[i].taxa_juros);
                    getchar();
                    printf("Digite o tipo de imposto: ");
                    fgets(conta->investimentos[i].imposto, TAM, stdin);
                    printf("Tipo investimento (0-Prefixado, 1-IPCA+, 2-Selic, 3-CDI): ");
                    scanf("%d", (int *)&conta->investimentos[i].tipo_invest);
                    getchar();

                    atualizarInvestimento(&conta->investimentos[i]);
                    conta->qtd_investimentos++;
                }
                break;

            case 2:
                if (conta->qtd_investimentos == 0) {
                    printf("Nenhum investimento para editar.\n");
                    break;
                }
                printf("Digite o índice do investimento para editar: ");
                int idx;
                scanf("%d", &idx);
                getchar();
                if (idx < 1 || idx > conta->qtd_investimentos) {
                    printf("Índice inválido.\n");
                    break;
                }
                idx--;
                printf("Editando investimento %d:\n", idx + 1);
                printf("Digite a nova data: ");
                fgets(conta->investimentos[idx].data, TAM, stdin);
                printf("Digite o novo valor: R$ ");
                scanf("%f", &conta->investimentos[idx].valor);
                getchar();
                printf("Digite o novo tipo: ");
                fgets(conta->investimentos[idx].tipo, TAM, stdin);
                printf("Digite o novo nome: ");
                fgets(conta->investimentos[idx].nome, TAM, stdin);
                printf("Digite a nova data de vencimento: ");
                fgets(conta->investimentos[idx].data_vencimento, TAM, stdin);
                printf("Digite a nova taxa de juros: ");
                scanf("%f", &conta->investimentos[idx].taxa_juros);
                getchar();
                printf("Digite o novo tipo de imposto: ");
                fgets(conta->investimentos[idx].imposto, TAM, stdin);
                printf("Tipo investimento (0-Prefixado, 1-IPCA+, 2-Selic, 3-CDI): ");
                scanf("%d", (int *)&conta->investimentos[idx].tipo_invest);
                getchar();

                atualizarInvestimento(&conta->investimentos[idx]);
                break;

            case 3:
                imprimir(*conta);
                break;

            case 4:
                printf("Digite o índice do investimento a deletar: ");
                int del;
                scanf("%d", &del);
                getchar();
                if (del < 1 || del > conta->qtd_investimentos) {
                    printf("Índice inválido.\n");
                    break;
                }
                for (int j = del - 1; j < conta->qtd_investimentos - 1; j++) {
                    conta->investimentos[j] = conta->investimentos[j + 1];
                }
                conta->qtd_investimentos--;
                printf("Investimento deletado.\n");
                break;

            case 5:
                menuOrdenacao(conta);
                break;

            case 6:
                imprimirValorBrutoTotal(*conta);
                imprimirValorLiquidoTotal(*conta);
                break;

            case 7:
                conta->qtd_investimentos = 0;
                printf("Digite o nome do titular da conta: ");
                fgets(conta->titular, TAM, stdin);
                salvarDados(conta, "dados.txt");
                printf("Todos os dados foram apagados.\n");
                break;

            case 0:
                salvarDados(conta, "dados.txt");
                printf("Encerrando programa.\n");
                return;

            default:
                printf("Opção inválida.\n");
        }
    }
}

int main() {
    informacoes_conta conta;
    inicializarDataAtual();
    carregarDados(&conta, "dados.txt");

    if (conta.qtd_investimentos == 0) {
        printf("Digite o nome do titular da conta: ");
        fgets(conta.titular, TAM, stdin);
    }

    menuPrincipal(&conta);
    return 0;
}