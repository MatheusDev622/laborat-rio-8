#include <stdio.h>
#include "dados.h"

void salvarDados(informacoes_conta *conta, const char *nomeArquivo) {
    FILE *f = fopen(nomeArquivo, "w");
    if (!f) {
        perror("Erro ao abrir o arquivo para salvar");
        return;
    }

    fprintf(f, "%s", conta->titular);
    fprintf(f, "%d\n", conta->qtd_investimentos);

    for (int i = 0; i < conta->qtd_investimentos; i++) {
        informacoes_financeiras *inv = &conta->investimentos[i];
        fprintf(f, "%s", inv->data);
        fprintf(f, "%.2f\n", inv->valor);
        fprintf(f, "%s", inv->nome);
        fprintf(f, "%s", inv->data_vencimento);
        fprintf(f, "%.2f\n", inv->taxa_juros);
        fprintf(f, "%.2f\n", inv->valor_final);
        fprintf(f, "%d\n", inv->tipo_invest);
    }

    fclose(f);
}

void carregarDados(informacoes_conta *conta, const char *nomeArquivo) {
    FILE *f = fopen(nomeArquivo, "r");
    if (!f) return;

    fgets(conta->titular, TAM, f);
    fscanf(f, "%d\n", &conta->qtd_investimentos);

    for (int i = 0; i < conta->qtd_investimentos; i++) {
        informacoes_financeiras *inv = &conta->investimentos[i];
        fgets(inv->data, TAM, f);
        fscanf(f, "%f\n", &inv->valor);
        fgets(inv->nome, TAM, f);
        fgets(inv->data_vencimento, TAM, f);
        fscanf(f, "%f\n", &inv->taxa_juros);
        fgets(inv->imposto, TAM, f);
        fscanf(f, "%f\n", &inv->valor_final);
        fscanf(f, "%d\n", (int *)&inv->tipo_invest);
    }

    fclose(f);
}