#ifndef DATA_H
#define DATA_H

#include "estrutura.h"

extern char dataAtual[TAM];

void inicializarDataAtual();
int calcularDias(const char *data_inicio, const char *data_fim);

#endif