#include <iostream>
#include "../Consulta/Consulta.h"
#include "../Sala/Sala.h"

// Função para adicionar uma nova consulta
void adicionarConsulta(Paciente *pacientes[], int &nPacientes, ProfissionalSaude *profissionais[], int &nProfissionais, Consulta *consultas[], int &nConsultas, Sala *salas[], int &nSalas)
{
    std::string data, hora, cpfPaciente, cpfProfissional, status;
    std::string numeroSala;

    std::cout << "[Cadastrar Sala]" << std::endl;

    std::cin.ignore(); // Limpar o buffer do cin

    std::cout << "Data da consulta: ";
    std::getline(std::cin, data);

    std::cout << "Hora da consulta: ";
    std::getline(std::cin, hora);

    std::cout << "CPF do paciente: ";
    std::getline(std::cin, cpfPaciente);

    Paciente *paciente = nullptr;
    for (int i = 0; i < nPacientes; i++)
    {
        if (pacientes[i]->getCPF() == cpfPaciente)
        {
            paciente = pacientes[i];
            break;
        }
    }
    if (!paciente)
    {
        std::cout << "Paciente nao encontrado.\n";
        return;
    }

    std::cout << "CPF do profissional: ";
    std::getline(std::cin, cpfProfissional);

    ProfissionalSaude *profissional = nullptr;
    for (int i = 0; i < nProfissionais; i++)
    {
        if (profissionais[i]->getCPF() == cpfProfissional)
        {
            profissional = profissionais[i];
            break;
        }
    }
    if (!profissional)
    {
        std::cout << "Profissional nao encontrado.\n";
        return;
    }

    std::cout << "Numero da sala: ";
    std::cin >> numeroSala;
    Sala *sala = nullptr;
    for (int i = 0; i < nSalas; i++)
    {
        if (salas[i]->getNumero() == numeroSala)
        {
            sala = salas[i];
            break;
        }
    }
    if (!sala)
    {
        std::cout << "Sala nao encontrada.\n";
        return;
    }

    std::cin.ignore(); // Limpar o buffer antes de ler o status
    std::cout << "Status da consulta: ";
    std::getline(std::cin, status);

    // Cria um novo objeto Consulta e adiciona ao array de consultas
    consultas[nConsultas] = new Consulta(data, hora, *paciente, *profissional, numeroSala, status);
    consultas[nConsultas]->printarDados();
    nConsultas++; // Incrementa o número de consultas
    std::cout << "Consulta adicionada com sucesso.\n";
}

// Função para imprimir todas as consultas cadastradas
void printarConsultas(Consulta *consultas[], int &nConsultas)
{
    if (nConsultas == 0)
    {
        std::cout << "Nenhuma consulta cadastrada.\n";
        return;
    }

    std::cout << "\n[Consultas]\n";

    for (int i = 0; i < nConsultas; i++)
    {
        consultas[i]->printarDados();
    }
}

// Função para buscar uma consulta por sala e exibir suas informações
void buscarConsultaPorSala(Consulta *consultas[], int &nConsultas)
{
    std::string sala;
    std::cout << "Digite o nome da sala: ";
    std::cin >> sala;

    for (int i = 0; i < nConsultas; i++)
    {
        if (consultas[i]->getSala() == sala)
        {
            std::cout << "\nConsulta encontrada na sala " << sala << ":\n";
            std::cout << "Data: " << consultas[i]->getData() << "\n";
            std::cout << "Hora: " << consultas[i]->getHora() << "\n";
            std::cout << "Paciente: " << consultas[i]->getPaciente().getNome() << " (CPF: " << consultas[i]->getPaciente().getCPF() << ")\n";
            std::cout << "Profissional: " << consultas[i]->getProfissional().getNome() << " (CPF: " << consultas[i]->getProfissional().getCPF() << ")\n";
            std::cout << "Sala: " << consultas[i]->getSala() << "\n";
            std::cout << "Status: " << consultas[i]->getStatus() << "\n";
            return;
        }
    }

    std::cout << "Consulta na sala " << sala << " nao encontrada.\n";
}