#include <iostream>
#include "../ProfissionalSaude/ProfissionalSaude.h"

// Função para cadastrar um novo profissional de saúde
void adicionarProfissional(ProfissionalSaude *profissionais[], int &nProfissionais, Especialidade *especialidades[], int &nEspecialidades)
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
void printarProfissionais(ProfissionalSaude *profissionais[], int &nProfissionais)
{
    if (nProfissionais == 0)
    {
        std::cout << "Nenhum profissional cadastrado.\n";
        return;
    }
    std::cout << "\n[Profissionais]\n";
    for (int i = 0; i < nProfissionais; i++)
    {
        // Exibe o CPF e o nome de cada profissional
        profissionais[i]->printarDados();
    }
}

// Função para buscar um profissional por CPF e exibir suas informações
void buscarProfissionalPorCPF(ProfissionalSaude *profissionais[], int &nProfissionais)
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