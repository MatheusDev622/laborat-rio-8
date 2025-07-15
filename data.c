#include <stdio.h>
#include <time.h>
#include "data.h"

char dataAtual[TAM];

void inicializarDataAtual() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    snprintf(dataAtual, TAM, "%02d/%02d/%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

int calcularDias(const char *data_inicio, const char *data_fim) {
    struct tm inicio = {0}, fim = {0};
    sscanf(data_inicio, "%d/%d/%d", &inicio.tm_mday, &inicio.tm_mon, &inicio.tm_year);
    sscanf(data_fim,    "%d/%d/%d", &fim.tm_mday,    &fim.tm_mon,    &fim.tm_year);
    inicio.tm_mon -= 1; fim.tm_mon -= 1;
    inicio.tm_year -= 1900; fim.tm_year -= 1900;
    time_t t_inicio = mktime(&inicio);
    time_t t_fim = mktime(&fim);
    double segundos = difftime(t_fim, t_inicio);
    return segundos / (60 * 60 * 24);
}