#include "Clinica.h"
#include <iostream>

bool isNumeric(const std::string &str)
{
    for (char c : str)
    {
        if (!std::isdigit(c) && c != '.')
        { // Verifica se o caractere é dígito ou ponto (para valores decimais)
            return false;
        }
    }
    return true;
}

// Função para cadastrar um novo paciente
void Clinica::adicionarPaciente()
{
    std::string nome, cpf, dataNascimento, telefone, email, endereco;

    std::cin.ignore(); // Limpar o buffer do cin

    std::cout << "Nome: ";
    std::getline(std::cin, nome);

    std::cout << "CPF: ";
    std::getline(std::cin, cpf);

    // Verifica se já existe um paciente com o mesmo CPF
    for (int i = 0; i < nPacientes; i++)
    {
        if (pacientes[i]->getCPF() == cpf)
        {
            std::cout << "Ja existe um paciente com este CPF.\n";
            return; // Sai da função sem adicionar um novo paciente
        }
    }

    std::cout << "Data de nascimento: ";
    std::getline(std::cin, dataNascimento);

    std::cout << "Telefone: ";
    std::getline(std::cin, telefone);

    std::cout << "Email: ";
    std::getline(std::cin, email);

    std::cout << "Endereco: ";
    std::getline(std::cin, endereco);

    // Cria um novo objeto Paciente e armazena no array de pacientes
    pacientes[nPacientes] = new Paciente(nome, cpf, dataNascimento, telefone, email, endereco);
    nPacientes++; // Incrementa o número de pacientes
    std::cout << "Paciente adicionado na lista de pacientes.\n";
}

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
        std::cout << "CPF: " << pacientes[i]->getCPF() << ", Nome: " << pacientes[i]->getNome() << "\n";
    }
}

// Função para cadastrar um novo profissional de saúde
void Clinica::adicionarProfissional()
{
    std::string nome, cpf, telefone, email, registroProfissional, codigoEspecialidade;

    std::cin.ignore(); // Limpar o buffer do cin

    std::cout << "Nome: ";
    std::getline(std::cin, nome);

    std::cout << "CPF: ";
    std::getline(std::cin, cpf);

    // Verifica se já existe um profissional com o mesmo CPF
    for (int i = 0; i < nProfissionais; i++)
    {
        if (profissionais[i]->getCPF() == cpf)
        {
            std::cout << "Ja existe um profissional com este CPF.\n";
            return; // Sai da função sem adicionar um novo profissional
        }
    }

    // Solicita o código da especialidade
    std::cout << "Digite o codigo da especialidade: ";
    std::cin >> codigoEspecialidade;

    // Verifica se o código da especialidade existe
    Especialidade *especialidadeEncontrada = nullptr;

    for (int i = 0; i < nEspecialidades; i++)
    {
        if (especialidades[i]->getCodigo() == codigoEspecialidade)
        {
            especialidadeEncontrada = especialidades[i];
            break; // Especialidade encontrada, sai do loop
        }
    }

    // Se não encontrar a especialidade, retorna
    if (especialidadeEncontrada == nullptr)
    {
        std::cout << "Nao foi encontrada uma especialidade com o codigo fornecido.\n";
        return;
    }

    // Se encontrou a especialidade, atribui o nome da especialidade ao profissional
    std::string especialidadeNome = especialidadeEncontrada->getNome();

    // Solicita os demais dados do profissional
    std::cout << "Telefone: ";
    std::cin.ignore(); // Limpar o buffer
    std::getline(std::cin, telefone);

    std::cout << "Email: ";
    std::getline(std::cin, email);

    std::cout << "Registro Profissional: ";
    std::getline(std::cin, registroProfissional);

    // Cria um novo objeto ProfissionalSaude e armazena no array de profissionais
    profissionais[nProfissionais] = new ProfissionalSaude(nome, cpf, especialidadeNome, telefone, email, registroProfissional);
    nProfissionais++; // Incrementa o número de profissionais
    std::cout << "Profissional adicionado com sucesso.\n";
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
        std::cout << "CPF: " << profissionais[i]->getCPF() << ", Nome: " << profissionais[i]->getNome() << "\n";
    }
}

// Função para adicionar uma nova consulta
void Clinica::adicionarConsulta()
{
    std::string data, hora, cpfPaciente, cpfProfissional, sala, status;

    std::cin.ignore(); // Limpar o buffer do cin

    std::cout << "Data da consulta: ";
    std::getline(std::cin, data);

    std::cout << "Hora da consulta: ";
    std::getline(std::cin, hora);

    std::cout << "CPF do paciente: ";
    std::getline(std::cin, cpfPaciente);

    Paciente *paciente = nullptr;
    for (int i = 0; i < nPacientes; i++)
    {
        if (pacientes[i]->getCPF() == cpfPaciente)
        {
            paciente = pacientes[i];
            break;
        }
    }
    if (!paciente)
    {
        std::cout << "Paciente nao encontrado.\n";
        return;
    }

    std::cout << "CPF do profissional: ";
    std::getline(std::cin, cpfProfissional);

    ProfissionalSaude *profissional = nullptr;
    for (int i = 0; i < nProfissionais; i++)
    {
        if (profissionais[i]->getCPF() == cpfProfissional)
        {
            profissional = profissionais[i];
            break;
        }
    }
    if (!profissional)
    {
        std::cout << "Profissional nao encontrado.\n";
        return;
    }

    std::cout << "Sala da consulta: ";
    std::getline(std::cin, sala);

    std::cout << "Status da consulta: ";
    std::getline(std::cin, status);

    // Cria um novo objeto Consulta e adiciona ao array de consultas
    consultas[nConsultas] = new Consulta(data, hora, *paciente, *profissional, sala, status);
    nConsultas++; // Incrementa o número de consultas
    std::cout << "Consulta adicionada com sucesso.\n";
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
        std::cout << "Consulta " << (i + 1) << ":\n";
        std::cout << "Data: " << consultas[i]->getData() << "\n";
        std::cout << "Hora: " << consultas[i]->getHora() << "\n";
        std::cout << "Paciente CPF: " << consultas[i]->getPaciente().getNome() << "\n";
        std::cout << "Profissional CPF: " << consultas[i]->getProfissional().getNome() << "\n";
        std::cout << "Sala: " << consultas[i]->getSala() << "\n";
        std::cout << "Status: " << consultas[i]->getStatus() << "\n\n";
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
            adicionarPaciente();
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
            adicionarProfissional();
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
            adicionarConsulta();
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

void Clinica::adicionarEspecialidade()
{
    std::string nome, descricao, codigo, tempoStr, valorStr;
    int tempo;
    double valor;

    std::cout << "Digite o nome da especialidade: ";
    std::cin.ignore(); // Limpar o buffer de entrada
    std::getline(std::cin, nome);

    std::cout << "Digite a descricao da especialidade: ";
    std::getline(std::cin, descricao);

    std::cout << "Digite o codigo da especialidade: ";
    std::cin >> codigo;

    // Verifica se o código é válido
    if (codigo.empty())
    {
        std::cout << "O codigo não pode ser vazio.\n";
        return;
    }

    // Solicita o tempo médio de duração da consulta, garantindo que seja um número maior que 0
    do
    {
        std::cout << "Digite o tempo medio de duração da consulta em minutos: ";
        std::cin >> tempoStr;

        if (!isNumeric(tempoStr))
        {
            std::cout << "Por favor, insira um numero valido para o tempo.\n";
            continue;
        }

        tempo = std::stoi(tempoStr); // Converte a string para inteiro
        if (tempo <= 0)
        {
            std::cout << "O tempo deve ser maior que 0.\n";
        }

    } while (tempo <= 0);

    // Solicita o valor da consulta, garantindo que seja um número maior que 0
    do
    {
        std::cout << "Digite o valor da consulta (maior que 0): ";
        std::cin >> valorStr;

        if (!isNumeric(valorStr))
        {
            std::cout << "Por favor, insira um número válido para o valor.\n";
            continue;
        }

        valor = std::stod(valorStr); // Converte a string para double
        if (valor <= 0)
        {
            std::cout << "O valor deve ser maior que 0.\n";
        }

    } while (valor <= 0);

    // Cria uma nova especialidade com os dados fornecidos
    especialidades[nEspecialidades] = new Especialidade(nome, descricao, codigo, tempo, valor);
    nEspecialidades++;

    std::cout << "Especialidade '" << nome << "' adicionada com sucesso.\n";
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
        std::cout << i + 1 << ". "
                  << "Nome: " << especialidade->getNome()
                  << ", Codigo: " << especialidade->getCodigo()
                  << ", Valor: R$ " << especialidade->getValor()
                  << ", Tempo: " << especialidade->getTempo() << " minutos\n";
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
            adicionarEspecialidade();
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
