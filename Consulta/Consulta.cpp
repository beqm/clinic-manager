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
