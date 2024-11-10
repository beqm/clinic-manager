#ifndef PROFISSIONALSAUDE_H
#define PROFISSIONALSAUDE_H

#include <string>

class ProfissionalSaude
{
private:
    std::string nome;
    std::string cpf;
    std::string especialidade;
    std::string telefone;
    std::string email;
    std::string registroProfissional;

public:
    ProfissionalSaude(const std::string &nome, const std::string &cpf,
                      const std::string &especialidade, const std::string &telefone,
                      const std::string &email, std::string registroProfissional);

    std::string getNome() const;
    std::string getCPF() const;
    std::string getEspecialidade() const;
    std::string getTelefone() const;
    std::string getEmail() const;
    std::string getRegistroProfissional() const;

    void setAvailableHours(const std::string &availableHours);
};

#endif
