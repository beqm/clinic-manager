#include "Clinica.h"
#include <iostream>
#include <limits>
#include "../Especialidade/especialidade-opcoes.h"
#include "../Paciente/paciente-opcoes.h"
#include "../Consulta/consulta-opcoes.h"
#include "../ProfissionalSaude/profissional-opcoes.h"
#include "../Equipamento/equipamento-opcoes.h"
#include "../Fornecedor/fornecedor-opcoes.h"
#include "../Sala/sala-opcoes.h"
#include "../Exame/exame-opcoes.h"
#include "../Pagamento/pagamento-opcoes.h"

// Função para o submenu Paciente
void Clinica::menuPaciente()
{
    int pacienteOpcao;
    do
    {
        std::cout << "\n[Menu Paciente]\n";
        std::cout << "[1] Adicionar paciente\n";
        std::cout << "[2] Listar pacientes\n";
        std::cout << "[3] Buscar paciente por CPF\n";
        std::cout << "[4] Voltar ao menu principal\n";
        std::cout << "Opcao: ";

        while (!(std::cin >> pacienteOpcao))
        {
            // Se a entrada não for válida (não for um número inteiro), limpa o erro e solicita nova entrada
            std::cin.clear();                                                   // Limpa o erro de falha de entrada
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora os dados restantes no buffer
            std::cout << "Entrada invalida. Por favor, insira um numero: ";
        }
        switch (pacienteOpcao)
        {
        case 1:
            adicionarPaciente(pacientes, nPacientes);
            break;
        case 2:
            printarPacientes(pacientes, nPacientes);
            break;
        case 3:
            buscarPacientePorCPF(pacientes, nPacientes);
            break;
        case 4:
            std::cout << "Voltando ao menu principal...\n";
            break;
        default:
            std::cout << "Opcao invalida. Tente novamente.\n";
            break;
        }
    } while (pacienteOpcao != 4);
}

// Função para o submenu Profissional
void Clinica::menuProfissional()
{
    int profissionalOpcao;
    do
    {
        std::cout << "\n[Menu Profissional]\n";
        std::cout << "[1] Adicionar profissional\n";
        std::cout << "[2] Listar profissionais\n";
        std::cout << "[3] Buscar profissional por CPF\n";
        std::cout << "[4] Voltar ao menu principal\n";
        std::cout << "Opcao: ";

        while (!(std::cin >> profissionalOpcao))
        {
            // Se a entrada não for válida (não for um número inteiro), limpa o erro e solicita nova entrada
            std::cin.clear();                                                   // Limpa o erro de falha de entrada
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora os dados restantes no buffer
            std::cout << "Entrada invalida. Por favor, insira um numero: ";
        }

        switch (profissionalOpcao)
        {
        case 1:
            adicionarProfissional(profissionais, nProfissionais, especialidades, nEspecialidades);
            break;
        case 2:
            printarProfissionais(profissionais, nProfissionais);
            break;
        case 3:
            buscarProfissionalPorCPF(profissionais, nProfissionais);
            break;
        case 4:
            std::cout << "Voltando ao menu principal...\n";
            break;
        default:
            std::cout << "Opcao invalida. Tente novamente.\n";
            break;
        }
    } while (profissionalOpcao != 4);
}

// Função para o submenu Consulta
void Clinica::menuConsulta()
{
    int consultaOpcao;
    do
    {
        std::cout << "\n[Menu Consulta]\n";
        std::cout << "[1] Adicionar consulta\n";
        std::cout << "[2] Listar consultas\n";
        std::cout << "[3] Buscar consulta por sala\n";
        std::cout << "[4] Voltar ao menu principal\n";
        std::cout << "Opcao: ";

        while (!(std::cin >> consultaOpcao))
        {
            // Se a entrada não for válida (não for um número inteiro), limpa o erro e solicita nova entrada
            std::cin.clear();                                                   // Limpa o erro de falha de entrada
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora os dados restantes no buffer
            std::cout << "Entrada invalida. Por favor, insira um numero: ";
        }

        switch (consultaOpcao)
        {
        case 1:
            adicionarConsulta(pacientes, nPacientes, profissionais, nProfissionais, consultas, nConsultas, salas, nSalas);
            break;
        case 2:
            printarConsultas(consultas, nConsultas);
            break;
        case 3:
            buscarConsultaPorSala(consultas, nConsultas);
            break;
        case 4:
            std::cout << "Voltando ao menu principal...\n";
            break;
        default:
            std::cout << "Opcao invalida. Tente novamente.\n";
            break;
        }
    } while (consultaOpcao != 4);
}

// Função para o submenu Especialidade
void Clinica::menuEspecialidade()
{
    int especialidadeOpcao;
    do
    {
        std::cout << "\n[Menu Especialidade]\n";
        std::cout << "[1] Adicionar especialidade\n";
        std::cout << "[2] Listar especialidades\n";
        std::cout << "[3] Voltar ao menu principal\n";
        std::cout << "Opcao: ";

        while (!(std::cin >> especialidadeOpcao))
        {
            // Se a entrada não for válida (não for um número inteiro), limpa o erro e solicita nova entrada
            std::cin.clear();                                                   // Limpa o erro de falha de entrada
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora os dados restantes no buffer
            std::cout << "Entrada invalida. Por favor, insira um numero: ";
        }

        switch (especialidadeOpcao)
        {
        case 1:
            adicionarEspecialidade(especialidades, nEspecialidades);
            break;
        case 2:
            listarEspecialidades(especialidades, nEspecialidades);
            break;
        case 3:
            std::cout << "Voltando ao menu principal...\n";
            break;
        default:
            std::cout << "Opcao invalida. Tente novamente.\n";
            break;
        }
    } while (especialidadeOpcao != 3);
}

// Função para o submenu Especialidade
void Clinica::menuEquipamento()
{
    int equipamentoOpcao;
    do
    {
        std::cout << "\n[Menu Equipamento]\n";
        std::cout << "[1] Adicionar equipamento\n";
        std::cout << "[2] Listar equipamentos\n";
        std::cout << "[3] Voltar ao menu principal\n";
        std::cout << "Opcao: ";

        while (!(std::cin >> equipamentoOpcao))
        {
            // Se a entrada não for válida (não for um número inteiro), limpa o erro e solicita nova entrada
            std::cin.clear();                                                   // Limpa o erro de falha de entrada
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora os dados restantes no buffer
            std::cout << "Entrada invalida. Por favor, insira um numero: ";
        }

        switch (equipamentoOpcao)
        {
        case 1:
            cadastrarEquipamento(fornecedores, nFornecedores, equipamentos, nEquipamentos);
            break;
        case 2:
            listarEquipamentos(equipamentos, nEquipamentos);
            break;
        case 3:
            adicionarEquipamentoSala(salas, nSalas, equipamentos, nEquipamentos);
            break;
        case 4:
            std::cout << "Voltando ao menu principal...\n";
            break;
        default:
            std::cout << "Opcao invalida. Tente novamente.\n";
            break;
        }
    } while (equipamentoOpcao != 3);
}

// Função para o submenu Especialidade
void Clinica::menuSala()
{
    int salaOpcao;
    do
    {
        std::cout << "\n[Menu Sala]\n";
        std::cout << "[1] Adicionar sala\n";
        std::cout << "[2] Listar salas\n";
        std::cout << "[3] Adicionar equipamentos a salas\n";
        std::cout << "[4] Voltar ao menu principal\n";
        std::cout << "Opcao: ";

        // Verificação da entrada
        while (!(std::cin >> salaOpcao))
        {
            // Se a entrada não for válida (não for um número inteiro), limpa o erro e solicita nova entrada
            std::cin.clear();                                                   // Limpa o erro de falha de entrada
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora os dados restantes no buffer
            std::cout << "Entrada invalida. Por favor, insira um numero: ";
        }

        switch (salaOpcao)
        {
        case 1:
            cadastrarSala(salas, nSalas);
            break;
        case 2:
            listarSalas(salas, nSalas);
            break;
        case 3:
            adicionarEquipamentoSala(salas, nSalas, equipamentos, nEquipamentos);
            break;
        case 4:
            std::cout << "Voltando ao menu principal...\n";
            break;
        default:
            std::cout << "Opcao invalida. Tente novamente.\n";
            break;
        }
    } while (salaOpcao != 4);
}

// Função para o submenu Especialidade
void Clinica::menuFornecedor()
{
    int fornecedorOpcao;
    do
    {
        std::cout << "\n[Menu Fornecedor]\n";
        std::cout << "[1] Adicionar Fornecedor\n";
        std::cout << "[2] Listar fornecedores\n";
        std::cout << "[3] Voltar ao menu principal\n";
        std::cout << "Opcao: ";

        // Verificação da entrada
        while (!(std::cin >> fornecedorOpcao))
        {
            // Se a entrada não for válida (não for um número inteiro), limpa o erro e solicita nova entrada
            std::cin.clear();                                                   // Limpa o erro de falha de entrada
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora os dados restantes no buffer
            std::cout << "Entrada invalida. Por favor, insira um numero: ";
        }

        switch (fornecedorOpcao)
        {
        case 1:
            cadastrarFornecedor(fornecedores, nFornecedores);
            break;
        case 2:
            listarFornecedores(fornecedores, nFornecedores);
            break;
        case 3:
            std::cout << "Voltando ao menu principal...\n";
            break;
        default:
            std::cout << "Opcao invalida. Tente novamente.\n";
            break;
        }
    } while (fornecedorOpcao != 3);
}

void Clinica::menuExame()
{
    int fornecedorOpcao;
    do
    {
        std::cout << "\n[Menu Exame]\n";
        std::cout << "[1] Cadastrar Exame\n";
        std::cout << "[2] Listar Exames\n";
        std::cout << "[3] Voltar ao menu principal\n";
        std::cout << "Opcao: ";

        // Verificação da entrada
        while (!(std::cin >> fornecedorOpcao))
        {
            // Se a entrada não for válida (não for um número inteiro), limpa o erro e solicita nova entrada
            std::cin.clear();                                                   // Limpa o erro de falha de entrada
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora os dados restantes no buffer
            std::cout << "Entrada invalida. Por favor, insira um numero: ";
        }

        switch (fornecedorOpcao)
        {
        case 1:
            cadastrarExame(exames, nExames, pacientes, nPacientes, profissionais, nProfissionais);
            break;
        case 2:
            listarExames(exames, nExames);
            break;
        case 3:
            std::cout << "Voltando ao menu principal...\n";
            break;
        default:
            std::cout << "Opcao invalida. Tente novamente.\n";
            break;
        }
    } while (fornecedorOpcao != 3);
}

void Clinica::menuPagamento()
{
    int fornecedorOpcao;
    do
    {
        std::cout << "\n[Menu Pagamento]\n";
        std::cout << "[1] Cadastrar Pagamento\n";
        std::cout << "[2] Listar Pagamentos\n";
        std::cout << "[3] Voltar ao menu principal\n";
        std::cout << "Opcao: ";

        while (!(std::cin >> fornecedorOpcao))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada invalida. Por favor, insira um numero: ";
        }

        switch (fornecedorOpcao)
        {
        case 1:
            cadastrarPagamento(pagamentos, nPagamentos, pacientes, nPacientes);
            break;
        case 2:
            listarPagamentos(pagamentos, nPagamentos);
            break;
        case 3:
            std::cout << "Voltando ao menu principal...\n";
            break;
        default:
            std::cout << "Opcao invalida. Tente novamente.\n";
            break;
        }
    } while (fornecedorOpcao != 3);
}

// Função para iniciar o sistema da clínica e exibir o menu principal
void Clinica::start()
{
    std::string escolhaStr;
    int escolha;

    do
    {
        // Exibe o menu principal
        std::cout << "\n[Sistema Clinica]\n";
        std::cout << "[1] Paciente\n";
        std::cout << "[2] Profissional\n";
        std::cout << "[3] Consulta\n";
        std::cout << "[4] Especialidade\n";
        std::cout << "[5] Sala\n";
        std::cout << "[6] Equipamento\n";
        std::cout << "[7] Fornecedor\n";
        std::cout << "[8] Exame\n";
        std::cout << "[9] Pagamentos\n";
        std::cout << "[10] Sair\n";

        std::cout << "Opcao: ";
        std::cin >> escolhaStr;

        try
        {
            escolha = std::stoi(escolhaStr); // Tenta converter para int
        }
        catch (const std::invalid_argument &e)
        {
            std::cout << "Entrada invalida! Por favor, insira um numero.\n";
            continue; // Recomeça o loop para pedir a entrada novamente
        }

        switch (escolha)
        {
        case 1: // Menu Paciente
            menuPaciente();
            break;

        case 2: // Menu Profissional
            menuProfissional();
            break;

        case 3: // Menu Consulta
            menuConsulta();
            break;

        case 4: // Menu Especialidade
            menuEspecialidade();
            break;
        case 5:
            menuSala();
            break;
        case 6:
            menuEquipamento();
            break;
        case 7:
            menuFornecedor();
            break;
        case 8:
            menuExame();
            break;
        case 9:
            menuPagamento();
        case 10:
            std::cout << "Saindo do sistema...\n";
            break;

        default:
            std::cout << "Opcao invalida. Tente novamente.\n";
            break;
        }
    } while (escolha != 10); // O loop continua até que o usuário escolha sair
}

// Destrutor para liberar a memória alocada para os pacientes, profissionais e consultas
Clinica::~Clinica()
{
    // Libera a memória dos pacientes
    for (int i = 0; i < nPacientes; i++)
    {
        delete pacientes[i];
    }

    // Libera a memória dos profissionais
    for (int i = 0; i < nProfissionais; i++)
    {
        delete profissionais[i];
    }

    // Libera a memória das consultas
    for (Consulta *consulta : consultas)
    {
        delete consulta;
    }
}
