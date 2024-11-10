#include <iostream>
#include <cassert>

#include "Consulta/Consulta.h"
#include "Paciente/Paciente.h"
#include "ProfissionalSaude/ProfissionalSaude.h"
#include "Especialidade/Especialidade.h"

int testConsulta()
{
    // Criando um paciente e um profissional para o teste
    Paciente paciente("João Silva", "12345678900", "01/01/1980", "987654321", "joao@email.com", "Rua A, 123");
    ProfissionalSaude profissional("Dr. João", "98765432100", "Cardiologia", "555555555", "dr.joao@email.com", "CRM1234");

    // Criando uma consulta
    Consulta consulta("10/10/2024", "14:00", paciente, profissional, "Sala 1", "Agendada");

    // Verificando se os dados estão corretos
    assert(consulta.getData() == "10/10/2024");
    assert(consulta.getHora() == "14:00");
    assert(consulta.getSala() == "Sala 1");
    assert(consulta.getPaciente().getCPF() == "12345678900");
    assert(consulta.getProfissional().getCPF() == "98765432100");

    std::cout << "Teste de consulta passou com sucesso!" << std::endl;
    return 0; // Retorna 0 se o teste passar
}

int testEspecialidade()
{
    // Criando uma especialidade
    Especialidade especialidade("Cardiologia", "Especialidade de coração", "CARD01", 30, 250.0);

    // Verificando se os dados estão corretos
    assert(especialidade.getNome() == "Cardiologia");
    assert(especialidade.getDescricao() == "Especialidade de coração");
    assert(especialidade.getCodigo() == "CARD01");
    assert(especialidade.getTempo() == 30);
    assert(especialidade.getValor() == 250.0);

    std::cout << "Teste de especialidade passou com sucesso!" << std::endl;
    return 0; // Retorna 0 se o teste passar
}

int testPaciente()
{
    // Criando um objeto Paciente
    Paciente paciente("João Silva", "12345678900", "01/01/1980", "987654321", "joao@email.com", "Rua A, 123");

    // Verificando se os dados estão corretos
    assert(paciente.getNome() == "João Silva");
    assert(paciente.getCPF() == "12345678900");
    assert(paciente.getDataNascimento() == "01/01/1980");
    assert(paciente.getTelefone() == "987654321");
    assert(paciente.getEmail() == "joao@email.com");
    assert(paciente.getEndereco() == "Rua A, 123");

    std::cout << "Teste de paciente passou com sucesso!" << std::endl;
    return 0; // Retorna 0 se o teste passar
}

int testProfissional()
{
    // Criando um objeto ProfissionalSaude
    ProfissionalSaude profissional("Dr. João", "98765432100", "Cardiologia", "555555555", "dr.joao@email.com", "CRM1234");

    // Verificando se os dados estão corretos
    assert(profissional.getNome() == "Dr. João");
    assert(profissional.getCPF() == "98765432100");
    assert(profissional.getEspecialidade() == "Cardiologia");
    assert(profissional.getTelefone() == "555555555");
    assert(profissional.getEmail() == "dr.joao@email.com");
    assert(profissional.getRegistroProfissional() == "CRM1234");

    std::cout << "Teste de profissional passou com sucesso!" << std::endl;
    return 0; // Retorna 0 se o teste passar
}

// Função para rodar todos os testes
int runTests()
{
    int status = 0;

    // Rodando todos os testes, e se algum falhar, o status será 1
    status |= testPaciente();      // Testa Paciente
    status |= testProfissional();  // Testa Profissional de Saúde
    status |= testConsulta();      // Testa Consulta
    status |= testEspecialidade(); // Testa Especialidade

    return status; // Retorna 0 se todos os testes passarem, 1 se algum falhar
}

int main()
{
    // Rodando os testes
    if (runTests() == 0)
    {
        std::cout << "Todos os testes passaram com sucesso!" << std::endl;
    }
    else
    {
        std::cout << "Alguns testes falharam. O programa não será iniciado." << std::endl;
    }

    // Espera uma tecla para fechar o programa
    std::cout << "Pressione qualquer tecla para sair..." << std::endl;
    std::cin.get(); // Aguarda o usuário pressionar uma tecla antes de fechar o programa

    return 0;
}
