#include "Fornecedor.h"
#include "fornecedor-opcoes.h"
#include <iostream>
#include <string>

void cadastrarFornecedor(Fornecedor* fornecedores[], int& nFornecedores)
{
    std::string nome, cnpj, telefone, email, endereco, tipoDeProduto;

    std::cout << "Cadastrar Fornecedor\n" << std::endl;

    std::cout << "Nome: ";
    getline(std::cin, nome);

    std::cout << "CNPJ: ";
    getline(std::cin, cnpj);

    std::cout << "Telefone: ";
    getline(std::cin, telefone);

    std::cout << "Email: ";
    getline(std::cin, email);

    std::cout << "Endereco: ";
    getline(std::cin, endereco);

    std::cout << "Tipo de produto: ";
    getline(std::cin, tipoDeProduto);

    fornecedores[nFornecedores] = new Fornecedor(nome,
                                                 cnpj,
                                                 telefone,
                                                 email,
                                                 endereco,
                                                 tipoDeProduto);
    nFornecedores++;

    std::cout << "Fornecedor cadastrado com sucesso." << std::endl;
}

void mostrarFornecedor(Fornecedor* fornecedor)
{
    std::cout << "Dados do Fornecedor " << fornecedor->getNome() << std::endl;
    fornecedor->exibirDados();
}

void listarFornecedores(Fornecedor* fornecedores[], int nFornecedores)
{
    if (nFornecedores == 0)
    {
        std::cout << "Nenhum fornecedor foi cadastrado" << std::endl;
    }
    else
    {
        std::cout << "Fornecedores cadastrados" << std::endl;

        for (int i = 0; i < nFornecedores; i++)
        {
            fornecedores[i]->exibirDados();
        }
    }
}

void editarFornecedor(Fornecedor* fornecedores[], int nFornecedores)
{
    std::string cnpjDoFornecedor;
    std::cout << "Digite o CPF do fornecedor: ";
    std::getline(std::cin, cnpjDoFornecedor);

    // Buscar o fornecedor
    Fornecedor* fornecedor = nullptr;
    for (int i = 0; i < nFornecedores; i++)
    {
        if (fornecedores[i]->getCnpj() == cnpjDoFornecedor)
        {
            fornecedor = fornecedores[i];
            break;
        }
    }
    if (!fornecedor)
    {
        std::cout << "Fornecedor não encontrado.\n";
        return;
    }

    std::string nome, cnpj, telefone, email, endereco, tipoDeProduto;

    std::cin.ignore();

    std::cout << "Editar Fornecedor " << fornecedor->getNome() << " (CNPJ: " << fornecedor->getCnpj() << ")." <<
        std::endl;

    std::cout << "Nome: ";
    getline(std::cin, nome);
    if (!nome.empty()) fornecedor->setNome(nome);

    std::cout << "CNPJ: ";
    getline(std::cin, cnpj);
    if (!cnpj.empty()) fornecedor->setCnpj(cnpj);

    std::cout << "Telefone: ";
    getline(std::cin, telefone);
    if (!telefone.empty()) fornecedor->setTelefone(telefone);

    std::cout << "Email: ";
    getline(std::cin, email);
    if (!email.empty()) fornecedor->setEmail(email);

    std::cout << "Endereco: ";
    getline(std::cin, endereco);
    if (!endereco.empty()) fornecedor->setEndereco(endereco);

    std::cout << "Tipo de produto: ";
    getline(std::cin, tipoDeProduto);
    if (!tipoDeProduto.empty()) fornecedor->setTipoDeProduto(tipoDeProduto);

    std::cout << "Fornecedor editado com sucesso." << std::endl;
}
