#include "Exame.h"

#include <string>
#include <ctime>
#include <iostream>
#include "../ProfissionalSaude/ProfissionalSaude.h"
#include "../Paciente/Paciente.h"

Exame::Exame() {}

Exame::Exame(const std::string& tipo,
             const std::string& descricao,
             const Paciente& paciente,
             const ProfissionalSaude& profissional)
    : tipo(tipo),
      descricao(descricao),
      paciente(paciente),
      profissional(profissional)
{
    time(&data);
    resultado = "Pendente";
}

std::string Exame::getTipo() const { return tipo; }
std::string Exame::getDescricao() const { return descricao; }
time_t Exame::getData() const { return data; }
Paciente Exame::getPaciente() const { return paciente; }
ProfissionalSaude Exame::getProfissional() const { return profissional; }
std::string Exame::getResultado() const { return resultado; }

void Exame::setTipo(const std::string& novoTipo) { tipo = novoTipo; }
void Exame::setDescricao(const std::string& novaDescricao) { descricao = novaDescricao; }
void Exame::setData(const time_t& novaData) { data = novaData; }
void Exame::setPaciente(const Paciente& novoPaciente) { paciente = novoPaciente; }
void Exame::setProfissional(const ProfissionalSaude& novoProfissional) { profissional = novoProfissional; }
void Exame::setResultado(const std::string& novoResultado) { resultado = novoResultado; }

std::string Exame::formatarData(const time_t& data) const
{
    char buffer[26];
    struct tm* timeinfo = localtime(&data);
    strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", timeinfo);
    return std::string(buffer);
}

void Exame::registrarResultado(const std::string& novoResultado)
{
    resultado = novoResultado;
}

void Exame::exibirDados() const
{
    std::cout << "Tipo do Exame: " << tipo << std::endl;
    std::cout << "Descrição: " << descricao << std::endl;
    std::cout << "Data: " << formatarData(data) << std::endl;
    std::cout << "\nDados do Paciente:" << std::endl;
    std::cout << "  ID: " << paciente.getId() << std::endl;
    std::cout << "  Nome: " << paciente.getNome() << std::endl;
    std::cout << "\nMédico Responsável:" << std::endl;
    std::cout << "  ID: " << profissional.getId() << std::endl;
    std::cout << "  Nome: " << profissional.getNome() << std::endl;
    std::cout << "\nResultado: " << resultado << std::endl;
}
