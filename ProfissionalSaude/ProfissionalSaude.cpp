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

// Função para cadastrar um novo profissional de saúde
void ProfissionalSaude::adicionarProfissional(ProfissionalSaude *profissionais[], int &nProfissionais, Especialidade *especialidades[], int &nEspecialidades)
{
  std::string nome, cpf, telefone, email, registroProfissional, codigoEspecialidade;

  std::cin.ignore(); // Limpar o buffer do cin

  std::cout << "Nome: ";
  std::getline(std::cin, nome);

  std::cout << "CPF: ";
  std::getline(std::cin, cpf);

  // Verifica se já existe um profissional com o mesmo CPF
  for (int i = 0; i < nProfissionais; i++)
  {
    if (profissionais[i]->getCPF() == cpf)
    {
      std::cout << "Ja existe um profissional com este CPF.\n";
      return; // Sai da função sem adicionar um novo profissional
    }
  }

  // Solicita o código da especialidade
  std::cout << "Digite o codigo da especialidade: ";
  std::cin >> codigoEspecialidade;

  // Verifica se o código da especialidade existe
  Especialidade *especialidadeEncontrada = nullptr;

  for (int i = 0; i < nEspecialidades; i++)
  {
    if (especialidades[i]->getCodigo() == codigoEspecialidade)
    {
      especialidadeEncontrada = especialidades[i];
      break; // Especialidade encontrada, sai do loop
    }
  }

  // Se não encontrar a especialidade, retorna
  if (especialidadeEncontrada == nullptr)
  {
    std::cout << "Nao foi encontrada uma especialidade com o codigo fornecido.\n";
    return;
  }

  // Se encontrou a especialidade, atribui o nome da especialidade ao profissional
  std::string especialidadeNome = especialidadeEncontrada->getNome();

  // Solicita os demais dados do profissional
  std::cout << "Telefone: ";
  std::cin.ignore(); // Limpar o buffer
  std::getline(std::cin, telefone);

  std::cout << "Email: ";
  std::getline(std::cin, email);

  std::cout << "Registro Profissional: ";
  std::getline(std::cin, registroProfissional);

  // Cria um novo objeto ProfissionalSaude e armazena no array de profissionais
  profissionais[nProfissionais] = new ProfissionalSaude(nome, cpf, especialidadeNome, telefone, email, registroProfissional);
  nProfissionais++; // Incrementa o número de profissionais
  std::cout << "Profissional adicionado com sucesso.\n";
}

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