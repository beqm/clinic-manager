#include "ProfissionalSaude.h"

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
