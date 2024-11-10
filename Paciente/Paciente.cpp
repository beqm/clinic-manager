#include "Paciente.h"
#include <iostream>

Paciente::Paciente(const std::string &nome, const std::string &cpf, const std::string &dataNascimento,
                   const std::string &telefone, const std::string &email, const std::string &endereco)
    : nome(nome), cpf(cpf), dataNascimento(dataNascimento), telefone(telefone),
      email(email), endereco(endereco) {}

std::string Paciente::getNome() const { return nome; }
std::string Paciente::getCPF() const { return cpf; }
std::string Paciente::getDataNascimento() const { return dataNascimento; }
std::string Paciente::getTelefone() const { return telefone; }
std::string Paciente::getEmail() const { return email; }
std::string Paciente::getEndereco() const { return endereco; }

void Paciente::definirNome(const std::string &nome) { this->nome = nome; }
void Paciente::definirCpf(const std::string &cpf) { this->cpf = cpf; }
void Paciente::definirDataNascimento(const std::string &dataNascimento) { this->dataNascimento = dataNascimento; }
void Paciente::definirTelefone(const std::string &telefone) { this->telefone = telefone; }
void Paciente::definirEmail(const std::string &email) { this->email = email; }
void Paciente::definirEndereco(const std::string &endereco) { this->endereco = endereco; }

// Função para cadastrar um novo paciente
void Paciente::adicionarPaciente(Paciente *pacientes[], int &nPacientes)
{
  std::string nome, cpf, dataNascimento, telefone, email, endereco;

  std::cin.ignore(); // Limpar o buffer do cin

  std::cout << "Nome: ";
  std::getline(std::cin, nome);

  std::cout << "CPF: ";
  std::getline(std::cin, cpf);

  // Verifica se já existe um paciente com o mesmo CPF
  for (int i = 0; i < nPacientes; i++)
  {
    if (pacientes[i]->getCPF() == cpf)
    {
      std::cout << "Ja existe um paciente com este CPF.\n";
      return; // Sai da função sem adicionar um novo paciente
    }
  }

  std::cout << "Data de nascimento: ";
  std::getline(std::cin, dataNascimento);

  std::cout << "Telefone: ";
  std::getline(std::cin, telefone);

  std::cout << "Email: ";
  std::getline(std::cin, email);

  std::cout << "Endereco: ";
  std::getline(std::cin, endereco);

  // Cria um novo objeto Paciente e armazena no array de pacientes
  pacientes[nPacientes] = new Paciente(nome, cpf, dataNascimento, telefone, email, endereco);
  nPacientes++; // Incrementa o número de pacientes
  std::cout << "Paciente adicionado na lista de pacientes.\n";
}

// Método para imprimir os dados do paciente
void Paciente::printarDados() const
{
  std::cout << "Nome: " << nome << std::endl;
  std::cout << "CPF: " << cpf << std::endl;
  std::cout << "Data de Nascimento: " << dataNascimento << std::endl;
  std::cout << "Telefone: " << telefone << std::endl;
  std::cout << "Email: " << email << std::endl;
  std::cout << "Endereço: " << endereco << std::endl;
}
