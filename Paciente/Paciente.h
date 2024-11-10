#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>

class Paciente
{
private:
    std::string nome;
    std::string cpf;
    std::string dataNascimento;
    std::string telefone;
    std::string email;
    std::string endereco;

public:
    Paciente(const std::string &nome, const std::string &cpf, const std::string &dataNascimento,
             const std::string &telefone, const std::string &email, const std::string &endereco);

    // Getters
    std::string getNome() const;
    std::string getCPF() const;
    std::string getDataNascimento() const;
    std::string getTelefone() const;
    std::string getEmail() const;
    std::string getEndereco() const;

    // Setters
    void definirNome(const std::string &nome);
    void definirCpf(const std::string &cpf);
    void definirDataNascimento(const std::string &dataNascimento);
    void definirTelefone(const std::string &telefone);
    void definirEmail(const std::string &email);
    void definirEndereco(const std::string &endereco);
};

#endif
