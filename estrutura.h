#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#define TAM 100
#define MAX_REG 10

typedef enum {
    PREFIXADO,
    IPCA,
    SELIC,
    CDI
} TipoInvestimento;

typedef struct {
    char data[TAM];
    float valor;
    char nome[TAM];
    char data_vencimento[TAM];
    float taxa_juros;
    char imposto[TAM];
    float valor_final;
    TipoInvestimento tipo_invest;
} informacoes_financeiras;

typedef struct {
    char titular[TAM];
    informacoes_financeiras investimentos[MAX_REG];
    int qtd_investimentos;
} informacoes_conta;

#endif