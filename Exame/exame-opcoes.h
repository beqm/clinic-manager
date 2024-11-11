#ifndef EXAME_OPCOES_H
#define EXAME_OPCOES_H

#include "Exame.h"
#include "../Paciente/Paciente.h"
#include "../ProfissionalSaude/ProfissionalSaude.h"

void cadastrarExame(Exame* exames[], int &nExames, Paciente* pacientes[], int &nPacientes,
                     ProfissionalSaude* profissionais[], int &nProfissionais);

void listarExames(Exame* exames[], int nExames);

#endif //EXAME_OPCOES_H
