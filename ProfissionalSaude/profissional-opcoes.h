#ifndef PROFISSIONAL_OPCOES_H
#define PROFISSIONAL_OPCOES_H

#include "../ProfissionalSaude/ProfissionalSaude.h"
#include "../ProfissionalSaude/profissional-opcoes.h"

// Função para imprimir todos os profissionais cadastrados
void printarProfissionais(ProfissionalSaude *profissionais[], int &nProfissionais);

// Função para buscar um profissional por CPF e exibir suas informações
void buscarProfissionalPorCPF(ProfissionalSaude *profissionais[], int &nProfissionais);
void adicionarProfissional(ProfissionalSaude *profissionais[], int &nProfissionais, Especialidade *especialidades[], int &nEspecialidades);
#endif // PROFISSIONAL_OPCOES_H
