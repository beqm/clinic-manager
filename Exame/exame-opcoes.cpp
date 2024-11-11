#include "exame-opcoes.h"
#include "Exame.h"
#include "../Paciente/Paciente.h"
#include "../ProfissionalSaude/ProfissionalSaude.h"
#include <iostream>
#include <string>

void cadastrarExame(Exame *exames[], int &nExames, Paciente *pacientes[], int &nPacientes,
                    ProfissionalSaude *profissionais[], int &nProfissionais)
{
    std::string tipo, descricao, cpfPaciente, cpfProfissional, resultado;
    Paciente *pacienteEncontrado = nullptr;
    ProfissionalSaude *profissionalEncontrado = nullptr;

    std::cout << "[Cadastrar Exame]" << std::endl;

    std::cin.ignore();

    std::cout << "Tipo: ";
    std::getline(std::cin, tipo);

    std::cout << "Descricao: ";
    std::getline(std::cin, descricao);

    std::cout << "Resultado: ";
    std::getline(std::cin, resultado);

    // Busca do paciente
    if (nPacientes == 0)
    {
        std::cout << "Nao existem pacientes cadastrados.";
        return;
    }

    do
    {
        std::cout << "CPF do paciente: ";
        std::getline(std::cin, cpfPaciente);

        for (int i = 0; i < nPacientes; i++)
        {
            if (pacientes[i]->getCPF() == cpfPaciente)
            {
                pacienteEncontrado = pacientes[i];
                break;
            }
        }

        if (!pacienteEncontrado)
        {
            std::cout << "Paciente nao encontrado! Por favor, insira um CPF valido." << std::endl;
        }
    } while (!pacienteEncontrado);

    // Busca do profissional de saúde
    do
    {
        std::cout << "CPF do profissional de saude: ";
        std::getline(std::cin, cpfProfissional);

        for (int i = 0; i < nProfissionais; i++)
        {
            if (profissionais[i]->getCPF() == cpfProfissional)
            {
                profissionalEncontrado = profissionais[i];
                break;
            }
        }

        if (!profissionalEncontrado)
        {
            std::cout << "Profissional nao encontrado! Por favor, insira um CPF valido." << std::endl;
        }
    } while (!profissionalEncontrado);

    exames[nExames] = new Exame(tipo, descricao, *pacienteEncontrado, *profissionalEncontrado);
    exames[nExames]->setResultado(resultado);
    nExames++;
    std::cout << "Exame registrado com sucesso\n";
}

void listarExames(Exame *exames[], int nExames)
{
    if (nExames == 0)
    {
        std::cout << "\nNao ha exames cadastrados!" << std::endl;
        return;
    }

    std::cout << "\n[Exames]\n";

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
