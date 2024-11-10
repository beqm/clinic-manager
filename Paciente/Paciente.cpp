#include "Paciente.h"

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
