#ifndef ORDENACAO_H
#define ORDENACAO_H

#include "estrutura.h"

void ordenarPorValor(informacoes_conta *conta);
void ordenarPorData(informacoes_conta *conta);
void ordenarPorTipo(informacoes_conta *conta);
void agruparPorTipoEOrdenar(informacoes_conta *conta, int ordenarPorValorFlag);
void menuOrdenacao(informacoes_conta *conta);
void imprimir(informacoes_conta conta);

#endif