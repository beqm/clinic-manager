#include "exame-opcoes.h"
#include "Exame.h"
#include "../Paciente/Paciente.h"
#include "../ProfissionalSaude/ProfissionalSaude.h"
#include <iostream>
#include <string>

void cadastrarExame(Exame* exames[], int &nExames, Paciente* pacientes[], int &nPacientes,
                     ProfissionalSaude* profissionais[], int &nProfissionais)
{
    std::string tipo, descricao, cpfPaciente, cpfProfissional, resultado;
    Paciente* pacienteEncontrado = nullptr;
    ProfissionalSaude* profissionalEncontrado = nullptr;

    std::cout << "Cadastrar Exame" << std::endl;

    std::cout << "Tipo: ";
    std::getline(std::cin, tipo);

    std::cout << "Descrição: ";
    std::getline(std::cin, descricao);

    std::cout << "Resultado: ";
    std::getline(std::cin, resultado);

    // Busca do paciente
    do
    {
        std::cout << "CPF do paciente: ";
        std::getline(std::cin, cpfPaciente);

        for (int i = 0; i < nPacientes; i++)
        {
            if (pacientes[i]->getCpf() == cpfPaciente)
            {
                pacienteEncontrado = pacientes[i];
                break;
            }
        }

        if (!pacienteEncontrado)
        {
            std::cout << "Paciente não encontrado! Por favor, insira um CPF válido." << std::endl;
        }
    }
    while (!pacienteEncontrado);

    // Busca do profissional de saúde
    do
    {
        std::cout << "CPF do profissional de saúde: ";
        std::getline(std::cin, cpfProfissional);

        for (int i = 0; i < nProfissionais; i++)
        {
            if (profissionais[i]->getCpf() == cpfProfissional)
            {
                profissionalEncontrado = profissionais[i];
                break;
            }
        }

        if (!profissionalEncontrado)
        {
            std::cout << "Profissional não encontrado! Por favor, insira um CPF válido." << std::endl;
        }
    }
    while (!profissionalEncontrado);

    exames[nExames] = new Exame(tipo, descricao, *pacienteEncontrado, *profissionalEncontrado);
    exames[nExames]->setResultado(resultado);
    nExames++;
}

void listarExames(Exame* exames[], int nExames)
{
    if (nExames == 0)
    {
        std::cout << "\nNão há exames cadastrados!" << std::endl;
        return;
    }

    std::cout << "Lista de exames" << std::endl;

    for (int i = 0; i < nExames; i++)
    {
        if (exames[i] != nullptr)
        {
            std::cout << "\nExame " << i + 1 << ":" << std::endl;
            exames[i]->exibirDados();
            std::cout << "------------------------" << std::endl;
        }
    }
}
