#include <stdio.h>
#include <math.h>
#include <string.h>
#include "atualizacao.h"
#include "data.h"

void atualizarInvestimento(informacoes_financeiras *inv) {
    int dias = calcularDias(inv->data, dataAtual);
    float taxaAnual = inv->taxa_juros / 100.0;
    float taxaDiaria = pow(1 + taxaAnual, 1.0 / 365.0) - 1;
    float valorBruto = inv->valor * pow(1 + taxaDiaria, dias);

    float imposto = 0.0;
    if (strcmp(inv->imposto, "IR\n") == 0 || strcmp(inv->imposto, "IR") == 0) {
        if (dias <= 180) imposto = 0.225;
        else if (dias <= 360) imposto = 0.20;
        else if (dias <= 720) imposto = 0.175;
        else imposto = 0.15;
    }

    float rendimento = valorBruto - inv->valor;
    float valorLiquido = valorBruto - (rendimento * imposto);
    inv->valor_final = valorLiquido;
}

void imprimirValorBrutoTotal(informacoes_conta conta) {
    float total = 0.0;
    for (int i = 0; i < conta.qtd_investimentos; i++) {
        int dias = calcularDias(conta.investimentos[i].data, dataAtual);
        float taxaAnual = conta.investimentos[i].taxa_juros / 100.0;
        float taxaDiaria = pow(1 + taxaAnual, 1.0 / 365.0) - 1;
        float valorBruto = conta.investimentos[i].valor * pow(1 + taxaDiaria, dias);
        total += valorBruto;
    }
    printf("\n\tValor bruto total: R$ %.2f", total);
}

void imprimirValorLiquidoTotal(informacoes_conta conta) {
    float total = 0.0;
    for (int i = 0; i < conta.qtd_investimentos; i++) {
        total += conta.investimentos[i].valor_final;
    }
    printf("\nValor líquido total: R$ %.2f\n", total);
}