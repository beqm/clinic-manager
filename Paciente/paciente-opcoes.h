#ifndef PACIENTE_OPCOES_H
#define PACIENTE_OPCOES_H

#include "../Paciente/Paciente.h"
#include "../Paciente/paciente-opcoes.h"

void adicionarPaciente(Paciente *pacientes[], int &nPacientes);

// Função para imprimir todos os pacientes cadastrados
void printarPacientes(Paciente *pacientes[], int &nPacientes);

// Função para buscar um paciente por CPF e exibir suas informações
void buscarPacientePorCPF(Paciente *pacientes[], int &nPacientes);

#endif // PACIENTE_OPCOES_H
