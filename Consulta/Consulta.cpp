#include "Consulta.h"
#include <iostream>

// Construtor da classe Consulta
Consulta::Consulta(std::string data, std::string hora, Paciente paciente, ProfissionalSaude profissional,
                   const std::string &sala, const std::string &status)
    : data(data), hora(hora), paciente(paciente), profissional(profissional), sala(sala), status(status) {}

// Getters
std::string Consulta::getData() const
{
  return data;
}

std::string Consulta::getHora() const
{
  return hora;
}

std::string Consulta::getSala() const
{
  return sala;
}

Paciente Consulta::getPaciente() const
{
  return paciente; // Obtém o paciente
}

ProfissionalSaude Consulta::getProfissional() const
{
  return profissional; // Obtém o CPF do profissional de saúde
}

std::string Consulta::getStatus() const
{
  return status;
}

// Setter
void Consulta::setStatus(const std::string &newStatus)
{
  status = newStatus;
}

// Função para adicionar uma nova consulta
void Consulta::adicionarConsulta(Paciente *pacientes[], int &nPacientes, ProfissionalSaude *profissionais[], int &nProfissionais, Consulta *consultas[], int &nConsultas)
{
  std::string data, hora, cpfPaciente, cpfProfissional, sala, status;

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

  std::cout << "Sala da consulta: ";
  std::getline(std::cin, sala);

  std::cout << "Status da consulta: ";
  std::getline(std::cin, status);

  // Cria um novo objeto Consulta e adiciona ao array de consultas
  consultas[nConsultas] = new Consulta(data, hora, *paciente, *profissional, sala, status);
  nConsultas++; // Incrementa o número de consultas
  std::cout << "Consulta adicionada com sucesso.\n";
}

// Função para imprimir os dados da consulta
void Consulta::printarDados() const
{
  std::cout << "Data: " << data << std::endl;
  std::cout << "Hora: " << hora << std::endl;
  std::cout << "Sala: " << sala << std::endl;
  std::cout << "Status: " << status << std::endl;

  std::cout << "Paciente: " << paciente.getNome() << std::endl;
  std::cout << "Profissional: " << profissional.getNome() << std::endl;
}
