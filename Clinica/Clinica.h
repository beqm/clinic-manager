#ifndef CLINICA_H
#define CLINICA_H

#include <iostream>
#include <string>
#include "../Paciente/Paciente.h"
#include "../ProfissionalSaude/ProfissionalSaude.h"
#include "../Especialidade/Especialidade.h"
#include "../Consulta/Consulta.h"
#include "../Equipamento/Equipamento.h"
#include "../Sala/Sala.h"

class Clinica
{
private:
    Paciente *pacientes[100];
    ProfissionalSaude *profissionais[100];
    Consulta *consultas[100];
    Especialidade *especialidades[100];
    Equipamento *equipamentos[100];
    Sala *salas[100];
    int nPacientes = 0;
    int nProfissionais = 0;
    int nConsultas = 0;
    int nEspecialidades = 0;
    int nEquipamentos = 0;
    int nSalas = 0;

public:
    void adicionarPaciente();
    void printarPacientes() const;
    void buscarConsultaPorSala() const;
    void buscarProfissionalPorCPF() const;
    void buscarPacientePorCPF() const;
    void menuPaciente();
    void adicionarEspecialidade();
    void listarEspecialidades() const;
    void menuEspecialidade();
    void menuProfissional();
    void menuConsulta();
    void adicionarProfissional();
    void printarProfissionais() const;
    void adicionarConsulta();
    void printarConsultas() const;
    void menuSala();
    void menuPagamento();
    void menuFornecedor();
    void menuEquipamento();
    void start();
    ~Clinica();
};

#endif
