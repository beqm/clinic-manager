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
