#ifndef CLINICA_H
#define CLINICA_H

#include <iostream>
#include <string>
#include "../Paciente/Paciente.h"
#include "../ProfissionalSaude/ProfissionalSaude.h"
#include "../Especialidade/Especialidade.h"
#include "../Consulta/Consulta.h" // Inclusão da classe Consulta

class Clinica
{
private:
    Paciente *pacientes[100];
    ProfissionalSaude *profissionais[100];
    Consulta *consultas[100];           // Array para armazenar consultas
    Especialidade *especialidades[100]; // Array para armazenar especialidades
    int nPacientes = 0;
    int nProfissionais = 0;
    int nConsultas = 0;
    int nEspecialidades = 0;

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
    void adicionarConsulta();      // Função para adicionar consulta
    void printarConsultas() const; // Função para imprimir consultas
    void start();                  // Menu para interagir com o sistema
    ~Clinica();                    // Destrutor para liberar a memória
};

#endif
