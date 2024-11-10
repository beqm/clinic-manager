#ifndef EXAME_H
#define EXAME_H

#include <string>
#include <ctime>
#include <iostream>
#include "../ProfissionalSaude/ProfissionalSaude.h"
#include "../Paciente/Paciente.h"

class Exame
{
private:
    std::string tipo;
    std::string descricao;
    time_t data;
    Paciente paciente;
    ProfissionalSaude profissional;
    std::string resultado;

public:
    Exame(const std::string &tipo,
          const std::string &descricao,
          const Paciente &paciente,
          const ProfissionalSaude &profissional);

    std::string getTipo() const;
    std::string getDescricao() const;
    time_t getData() const;
    Paciente getPaciente() const;
    ProfissionalSaude getProfissional() const;
    std::string getResultado() const;

    void setTipo(const std::string &novoTipo);
    void setDescricao(const std::string &novaDescricao);
    void setData(const time_t &novaData);
    void setPaciente(const Paciente &novoPaciente);
    void setProfissional(const ProfissionalSaude &novoProfissional);
    void setResultado(const std::string &novoResultado);

    std::string formatarData(const time_t &data) const;

    void registrarResultado(const std::string &novoResultado);

    void exibirDados() const;
};

#endif // EXAME_H
