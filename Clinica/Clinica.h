#ifndef CLINICA_H
#define CLINICA_H

#include <iostream>
#include <string>
#include "../Paciente/Paciente.h"
#include "../ProfissionalSaude/ProfissionalSaude.h"
#include "../Especialidade/Especialidade.h"
#include "../Consulta/Consulta.h"
#include "../Equipamento/Equipamento.h"
#include "../Fornecedor/Fornecedor.h"
#include "../Pagamento/Pagamento.h"
#include "../Sala/Sala.h"
#include "../Exame/Exame.h"

class Clinica
{
private:
    Paciente *pacientes[100];
    ProfissionalSaude *profissionais[100];
    Consulta *consultas[100];
    Especialidade *especialidades[100];
    Equipamento *equipamentos[100];
    Fornecedor *fornecedores[100];
    Pagamento *pagamentos[100];
    Exame *exames[100];
    Sala *salas[100];
    int nPacientes = 0;
    int nProfissionais = 0;
    int nConsultas = 0;
    int nEspecialidades = 0;
    int nEquipamentos = 0;
    int nFornecedores = 0;
    int nPagamentos = 0;
    int nSalas = 0;
    int nExames = 0;

public:
    void menuPaciente();
    void menuEspecialidade();
    void menuProfissional();
    void menuConsulta();
    void menuSala();
    void menuPagamento();
    void menuFornecedor();
    void menuEquipamento();
    void menuExame();
    void start();
    ~Clinica();
};

#endif
