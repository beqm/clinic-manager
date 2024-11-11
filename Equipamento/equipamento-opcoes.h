#ifndef EQUIPAMENTO_OPCOES_H
#define EQUIPAMENTO_OPCOES_H

#include "Equipamento.h"
#include "../Fornecedor/Fornecedor.h"

void cadastrarEquipamento(Fornecedor* fornecedores[], int &nFornecedores, Equipamento* equipamentos[], int &nEquipamentos);

void listarEquipamentos(Equipamento* equipamentos[], int &nEquipamentos);

#endif //EQUIPAMENTO_OPCOES_H
