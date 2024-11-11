#ifndef CONSULTA_OPCOES_H
#define CONSULTA_OPCOES_H

#include "../Consulta/Consulta.h"

// Função para imprimir todas as consultas cadastradas
void printarConsultas(Consulta *consultas[], int &nConsultas);

// Função para buscar uma consulta por sala e exibir suas informações
void buscarConsultaPorSala(Consulta *consultas[], int &nConsultas);

void adicionarConsulta(Paciente *pacientes[], int &nPacientes, ProfissionalSaude *profissionais[], int &nProfissionais, Consulta *consultas[], int &nConsultas, Sala *salas[], int &nSalas);

#endif // CONSULTA_OPCOES_H
