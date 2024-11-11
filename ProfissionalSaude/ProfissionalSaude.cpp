#include "ProfissionalSaude.h"

#include <iostream>

ProfissionalSaude::ProfissionalSaude(const std::string &n, const std::string &c,
                                     const std::string &e, const std::string &t,
                                     const std::string &mail, const std::string r)
    : nome(n), cpf(c), especialidade(e),
      telefone(t), email(mail), registroProfissional(r) {}

std::string ProfissionalSaude::getCPF() const { return cpf; }
std::string ProfissionalSaude::getNome() const { return nome; }
std::string ProfissionalSaude::getEspecialidade() const { return especialidade; }
std::string ProfissionalSaude::getRegistroProfissional() const { return registroProfissional; }
std::string ProfissionalSaude::getTelefone() const { return telefone; }
std::string ProfissionalSaude::getEmail() const { return email; }

// Método para imprimir os dados do profissional de saúde
void ProfissionalSaude::printarDados() const
{
  std::cout << "Nome: " << nome << std::endl;
  std::cout << "CPF: " << cpf << std::endl;
  std::cout << "Especialidade: " << especialidade << std::endl;
  std::cout << "Telefone: " << telefone << std::endl;
  std::cout << "Email: " << email << std::endl;
  std::cout << "Registro Profissional: " << registroProfissional << std::endl;
}