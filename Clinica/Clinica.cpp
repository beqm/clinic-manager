#include "Clinica.h"
#include <iostream>

// Função para imprimir todos os pacientes cadastrados
void Clinica::printarPacientes() const
{
    if (nPacientes == 0)
    {
        std::cout << "Nenhum paciente cadastrado.\n";
        return;
    }

    for (int i = 0; i < nPacientes; i++)
    {
        // Exibe o CPF e o nome de cada paciente
        pacientes[i]->printarDados();
    }
}

// Função para imprimir todos os profissionais cadastrados
void Clinica::printarProfissionais() const
{
    if (nProfissionais == 0)
    {
        std::cout << "Nenhum profissional cadastrado.\n";
        return;
    }

    for (int i = 0; i < nProfissionais; i++)
    {
        // Exibe o CPF e o nome de cada profissional
        profissionais[i]->printarDados();
    }
}

// Função para imprimir todas as consultas cadastradas
void Clinica::printarConsultas() const
{
    if (nConsultas == 0)
    {
        std::cout << "Nenhuma consulta cadastrada.\n";
        return;
    }

    for (int i = 0; i < nConsultas; i++)
    {
        consultas[nConsultas]->printarDados();
    }
}

// Função para buscar um paciente por CPF e exibir suas informações
void Clinica::buscarPacientePorCPF() const
{
    std::string cpf;
    std::cout << "Digite o CPF do paciente: ";
    std::cin >> cpf;

    for (int i = 0; i < nPacientes; i++)
    {
        if (pacientes[i]->getCPF() == cpf)
        {
            std::cout << "\nPaciente encontrado:\n";
            std::cout << "Nome: " << pacientes[i]->getNome() << "\n";
            std::cout << "CPF: " << pacientes[i]->getCPF() << "\n";
            std::cout << "Data de Nascimento: " << pacientes[i]->getDataNascimento() << "\n";
            std::cout << "Telefone: " << pacientes[i]->getTelefone() << "\n";
            std::cout << "Email: " << pacientes[i]->getEmail() << "\n";
            std::cout << "Endereco: " << pacientes[i]->getEndereco() << "\n";
            return;
        }
    }

    std::cout << "Paciente com o CPF " << cpf << " nao encontrado.\n";
}

// Função para buscar um profissional por CPF e exibir suas informações
void Clinica::buscarProfissionalPorCPF() const
{
    std::string cpf;
    std::cout << "Digite o CPF do profissional: ";
    std::cin >> cpf;

    for (int i = 0; i < nProfissionais; i++)
    {
        if (profissionais[i]->getCPF() == cpf)
        {
            std::cout << "\nProfissional encontrado:\n";
            std::cout << "Nome: " << profissionais[i]->getNome() << "\n";
            std::cout << "CPF: " << profissionais[i]->getCPF() << "\n";
            std::cout << "Especialidade: " << profissionais[i]->getEspecialidade() << "\n";
            std::cout << "Telefone: " << profissionais[i]->getTelefone() << "\n";
            std::cout << "Email: " << profissionais[i]->getEmail() << "\n";
            std::cout << "Registro Profissional: " << profissionais[i]->getRegistroProfissional() << "\n";
            return;
        }
    }

    std::cout << "Profissional com o CPF " << cpf << " nao encontrado.\n";
}

// Função para buscar uma consulta por sala e exibir suas informações
void Clinica::buscarConsultaPorSala() const
{
    std::string sala;
    std::cout << "Digite o nome da sala: ";
    std::cin >> sala;

    for (int i = 0; i < nConsultas; i++)
    {
        if (consultas[i]->getSala() == sala)
        {
            std::cout << "\nConsulta encontrada na sala " << sala << ":\n";
            std::cout << "Data: " << consultas[i]->getData() << "\n";
            std::cout << "Hora: " << consultas[i]->getHora() << "\n";
            std::cout << "Paciente: " << consultas[i]->getPaciente().getNome() << " (CPF: " << consultas[i]->getPaciente().getCPF() << ")\n";
            std::cout << "Profissional: " << consultas[i]->getProfissional().getNome() << " (CPF: " << consultas[i]->getProfissional().getCPF() << ")\n";
            std::cout << "Sala: " << consultas[i]->getSala() << "\n";
            std::cout << "Status: " << consultas[i]->getStatus() << "\n";
            return;
        }
    }

    std::cout << "Consulta na sala " << sala << " nao encontrada.\n";
}

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
        std::cin >> pacienteOpcao;

        switch (pacienteOpcao)
        {
        case 1:
            Paciente::adicionarPaciente(pacientes, nPacientes);
            break;
        case 2:
            printarPacientes();
            break;
        case 3:
            buscarPacientePorCPF();
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
        std::cin >> profissionalOpcao;

        switch (profissionalOpcao)
        {
        case 1:
            ProfissionalSaude::adicionarProfissional(profissionais, nProfissionais, especialidades, nEspecialidades);
            break;
        case 2:
            printarProfissionais();
            break;
        case 3:
            buscarProfissionalPorCPF();
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
        std::cin >> consultaOpcao;

        switch (consultaOpcao)
        {
        case 1:
            Consulta::adicionarConsulta(pacientes, nPacientes, profissionais, nProfissionais, consultas, nConsultas);
            break;
        case 2:
            printarConsultas();
            break;
        case 3:
            buscarConsultaPorSala();
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

void Clinica::listarEspecialidades() const
{
    if (nEspecialidades == 0)
    {
        std::cout << "Nao ha especialidades cadastradas.\n";
        return;
    }

    std::cout << "\nLista de Especialidades:\n";
    for (int i = 0; i < nEspecialidades; i++)
    {
        Especialidade *especialidade = especialidades[i];
        especialidade->printarDados();
    }
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
        std::cin >> especialidadeOpcao;

        switch (especialidadeOpcao)
        {
        case 1:
            Especialidade::adicionarEspecialidade(especialidades, nEspecialidades);
            break;
        case 2:
            listarEspecialidades();
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
    return;
}

// Função para o submenu Especialidade
void Clinica::menuSala()
{
    return;
}

// Função para o submenu Especialidade
void Clinica::menuFornecedor()
{
    return;
}

// Função para o submenu Especialidade
void Clinica::menuPagamento()
{
    return;
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
            menuEquipamento();
            break;
        case 6:
            menuSala();
            break;
        case 7:
            menuFornecedor();
            break;
        case 8:
            menuPagamento();
            break;
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
