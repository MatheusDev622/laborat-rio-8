#ifndef DADOS_H
#define DADOS_H

#include "estrutura.h"

void salvarDados(informacoes_conta *conta, const char *nomeArquivo);
void carregarDados(informacoes_conta *conta, const char *nomeArquivo);

#endif