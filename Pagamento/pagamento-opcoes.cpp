#include "pagamento-opcoes.h"
#include "Pagamento.h"
#include "../Paciente/Paciente.h"
#include <iostream>
#include <string>

Paciente *encontrarPaciente(Paciente *pacientes[], int numPacientes, std::string cpf)
{
    for (int i = 0; i < numPacientes; i++)
    {
        if (pacientes[i] != nullptr && pacientes[i]->getCPF() == cpf)
        {
            return pacientes[i];
        }
    }
    return nullptr;
}

// Função auxiliar para limpar o buffer do teclado
void limparBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Função auxiliar para validar ID
bool validarId(Pagamento *pagamentos[], int id, int &posicao, int quantidadePagamentos)
{
    for (int i = 0; i < quantidadePagamentos; i++)
    {
        if (pagamentos[i] != nullptr && pagamentos[i]->getIdDoPagamento() == id)
        {
            posicao = i;
            return true;
        }
    }
    return false;
}

void cadastrarPagamento(Pagamento *pagamentos[], int &nPagamentos, Paciente *pacientes[], int &nPacientes)
{
    std::cout << "[Cadastrar Pagamento]\n"
              << std::endl;

    std::cin.ignore();

    std::string idPaciente;
    std::cout << "Digite o CPF do paciente: ";
    std::getline(std::cin, idPaciente);

    // Buscar paciente
    Paciente *paciente = encontrarPaciente(pacientes, nPacientes, idPaciente);
    if (paciente == nullptr)
    {
        std::cout << "Erro: Paciente não encontrado!" << std::endl;
        return;
    }

    // Coletar dados do pagamento
    std::string descricao;
    double valor;
    std::string formaPagamento;

    std::cout << "Descricao do servico: ";
    std::getline(std::cin, descricao);

    std::cout << "Valor total: R$ ";
    std::cin >> valor;

    std::cout << "Forma de pagamento: ";
    std::getline(std::cin, formaPagamento);

    // Criar novo pagamento
    pagamentos[nPagamentos] = new Pagamento(nPagamentos, *paciente, valor, descricao);
    pagamentos[nPagamentos]->registrarPagamento(formaPagamento);
    nPagamentos++;

    std::cout << "\nPagamento cadastrado com sucesso!" << std::endl;
}

// Função para listar todos os pagamentos
void listarPagamentos(Pagamento *pagamentos[], int nPagamentos)
{
    if (nPagamentos == 0)
    {
        std::cout << "\nNão há pagamentos cadastrados!" << std::endl;
        return;
    }

    std::cout << "\n[Pagamentos]\n";

    for (int i = 0; i < nPagamentos; i++)
    {
        if (pagamentos[i] != nullptr)
        {
            std::cout << "\nPagamento " << i + 1 << ":" << std::endl;
            pagamentos[i]->imprimirDetalhesDoPagamento();
            std::cout << "------------------------" << std::endl;
        }
    }
}