#ifndef PAGAMENTO_OPCOES_H
#define PAGAMENTO_OPCOES_H
#include <iostream>
#include <limits>
#include "Pagamento.h"
#include "../Paciente/Paciente.h"

Paciente* encontrarPaciente(Paciente* pacientes[], int numPacientes, std::string cpf);

void limparBuffer();

bool validarId(Pagamento* pagamentos[], int id, int& posicao, int quantidadePagamentos);

void cadastrarPagamento(Pagamento* pagamentos[], int& nPagamentos, Paciente* pacientes[], int& nPacientes);

void listarPagamentos(Pagamento* pagamentos[], int nPagamentos);

#endif //PAGAMENTO_OPCOES_H
