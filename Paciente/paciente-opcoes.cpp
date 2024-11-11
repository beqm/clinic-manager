#include <iostream>
#include "../Paciente/Paciente.h"

// Função para cadastrar um novo paciente
void adicionarPaciente(Paciente *pacientes[], int &nPacientes)
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
void printarPacientes(Paciente *pacientes[], int &nPacientes)
{
    if (nPacientes == 0)
    {
        std::cout << "Nenhum paciente cadastrado.\n";
        return;
    }
    std::cout << "\n[Pacientes]\n";
    for (int i = 0; i < nPacientes; i++)
    {
        // Exibe o CPF e o nome de cada paciente
        pacientes[i]->printarDados();
    }
}

// Função para buscar um paciente por CPF e exibir suas informações
void buscarPacientePorCPF(Paciente *pacientes[], int &nPacientes)
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