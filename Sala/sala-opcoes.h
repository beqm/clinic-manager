#ifndef SALA_OPCOES_H
#define SALA_OPCOES_H
#include "Sala.h"
#include "../Equipamento/Equipamento.h"

void cadastrarSala(Sala* salas[], int& nSalas);

void listarSalas(Sala* salas[], int nSalas);

void adicionarEquipamentoSala(Sala* salas[], int nSalas, Equipamento* equipamentos[], int nEquipamentos);

void removerEquipamentoSala(Sala* salas[], int nSalas);

#endif //SALA_OPCOES_H
