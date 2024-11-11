#include "equipamento-opcoes.h"
#include "Equipamento.h"
#include "../Fornecedor/Fornecedor.h"
#include <iostream>

void cadastrarEquipamento(Fornecedor* fornecedores[], int &nFornecedores, Equipamento* equipamentos[], int &nEquipamentos)
{
    std::string nome, tipo, fabricante, frequenciaManutencao, cnpjFornecedor;
    Fornecedor* fornecedorEncontrado = nullptr;

    std::cout << "Cadastrar Equipamento" << std::endl;

    std::cout << "Nome: ";
    std::getline(std::cin, nome);

    std::cout << "Tipo: ";
    std::getline(std::cin, tipo);

    std::cout << "Fabricante: ";
    std::getline(std::cin, fabricante);

    std::cout << "Frequência de manutenção: ";
    std::getline(std::cin, frequenciaManutencao);

    do
    {
        std::cout << "CNPJ do fornecedor: ";
        std::getline(std::cin, cnpjFornecedor);

        // Busca o fornecedor pelo CNPJ
        for (int i = 0; i < nFornecedores; i++)
        {
            if (fornecedores[i]->getCnpj() == cnpjFornecedor)
            {
                fornecedorEncontrado = fornecedores[i];
                break;
            }
        }

        if (!fornecedorEncontrado)
        {
            std::cout << "Fornecedor não encontrado! Por favor, insira um CNPJ válido." << std::endl;
        }
    }
    while (!fornecedorEncontrado);

    equipamentos[nEquipamentos] = new Equipamento(nome, tipo, fabricante, frequenciaManutencao, *fornecedorEncontrado);
    nEquipamentos++;

    std::cout << "\nEquipamento cadastrado com sucesso!" << std::endl;
}

void listarEquipamentos(Equipamento* equipamentos[], int &nEquipamentos)
{
    if (nEquipamentos == 0)
    {
        std::cout << "Nenhum equipamento foi cadastrado" << std::endl;
    }
    else
    {
        std::cout << "Equipamentos cadastrados>" << std::endl;

        for (int i = 0; i < nEquipamentos; i++)
        {
            equipamentos[i]->exibirDados();
        }
    }
}
