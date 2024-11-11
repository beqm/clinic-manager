#ifndef CONSULTA_H
#define CONSULTA_H

#include <string>
#include "../Paciente/Paciente.h"
#include "../ProfissionalSaude/ProfissionalSaude.h"

class Consulta
{
private:
    std::string data;
    std::string hora;
    Paciente paciente;
    ProfissionalSaude profissional;
    std::string sala;
    std::string status;

public:
    Consulta(std::string data, std::string hora, Paciente paciente, ProfissionalSaude profissional,
             const std::string &sala, const std::string &status);

    Paciente getPaciente() const;
    ProfissionalSaude getProfissional() const;
    std::string getData() const;
    std::string getHora() const;
    std::string getStatus() const;
    std::string getSala() const;
    std::string getNotas() const;

    void setStatus(const std::string &status);
    void printarDados() const;
};

#endif
