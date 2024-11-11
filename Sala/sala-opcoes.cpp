#include "sala-opcoes.h"
#include "Sala.h"
#include "../Equipamento/Equipamento.h"
#include <iostream>
#include <limits>

void cadastrarSala(Sala *salas[], int &nSalas)
{
    std::string numero, tipo;
    int andar, capacidade;

    std::cout << "[Cadastrar Sala]" << std::endl;
    std::cin.ignore(); // Limpar o buffer de entrada

    std::cout << "Numero da sala: ";
    std::getline(std::cin, numero);

    // Loop para garantir uma entrada válida para o andar
    while (true)
    {
        std::cout << "Andar: ";
        std::cin >> andar;

        if (std::cin.fail())
        {
            std::cin.clear();                                                   // Limpar o estado de erro
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorar o restante da entrada
            std::cout << "Por favor, insira um numero válido no campo andar.\n";
        }
        else
        {
            break; // Se a entrada for válida, sair do loop
        }
    }

    // Limpar o buffer antes de ler o tipo da sala
    std::cin.ignore();

    std::cout << "Tipo da sala: ";
    std::getline(std::cin, tipo);

    // Loop para garantir uma entrada válida para a capacidade
    while (true)
    {
        std::cout << "Capacidade: ";
        std::cin >> capacidade;

        if (std::cin.fail())
        {
            std::cin.clear();                                                   // Limpar o estado de erro
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorar o restante da entrada
            std::cout << "Por favor, insira um numero válido no campo capacidade.\n";
        }
        else
        {
            break; // Se a entrada for válida, sair do loop
        }
    }

    // Cadastrar a sala
    salas[nSalas] = new Sala(numero, andar, tipo, capacidade);
    nSalas++;

    std::cout << "\nSala cadastrada com sucesso!" << std::endl;
}

void listarSalas(Sala *salas[], int nSalas)
{
    if (nSalas == 0)
    {
        std::cout << "\nNenhuma sala cadastrada!" << std::endl;
        return;
    }

    std::cout << "\n[Salas]\n";

    for (int i = 0; i < nSalas; i++)
    {
        std::cout << "\nSala #" << (i + 1) << std::endl;
        std::cout << "------------------------" << std::endl;
        salas[i]->exibirDados();
        std::cout << "------------------------" << std::endl;
    }
}

void adicionarEquipamentoSala(Sala *salas[], int nSalas, Equipamento *equipamentos[], int nEquipamentos)
{
    if (nSalas == 0)
    {
        std::cout << "\nNenhuma sala cadastrada!" << std::endl;
        return;
    }

    if (nEquipamentos == 0)
    {
        std::cout << "\nNenhum equipamento cadastrado!" << std::endl;
        return;
    }

    int numSala, numEquipamento;

    std::cout << "Adicionar Equipamento na Sala" << std::endl;

    // Lista as salas disponíveis
    for (int i = 0; i < nSalas; i++)
    {
        std::cout << "\nSala #" << (i + 1) << std::endl;
        std::cout << "Numero: " << salas[i]->getNumero() << std::endl;
        std::cout << "Tipo: " << salas[i]->getTipo() << std::endl;
        std::cout << "Equipamentos: " << salas[i]->getQuantidadeEquipamentos() << "/5" << std::endl;
    }

    do
    {
        std::cout << "\nSelecione o numero da sala (1-" << nSalas << "): ";
        std::cin >> numSala;

        if (std::cin.fail() || numSala < 1 || numSala > nSalas)
        {
            std::cout << "Numero de sala invalido!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        break;
    } while (true);

    // Verifica se a sala está cheia
    if (salas[numSala - 1]->getQuantidadeEquipamentos() >= 5)
    {
        std::cout << "Esta sala já atingiu o limite máximo de equipamentos!" << std::endl;
        return;
    }

    // Lista os equipamentos disponíveis
    std::cout << "\nEquipamentos disponiveis:" << std::endl;
    for (int i = 0; i < nEquipamentos; i++)
    {
        std::cout << "\nEquipamento #" << (i + 1) << std::endl;
        std::cout << "Nome: " << equipamentos[i]->getNome() << std::endl;
        std::cout << "Tipo: " << equipamentos[i]->getTipo() << std::endl;
    }

    do
    {
        std::cout << "\nSelecione o numero do equipamento (1-" << nEquipamentos << "): ";
        std::cin >> numEquipamento;

        if (std::cin.fail() || numEquipamento < 1 || numEquipamento > nEquipamentos)
        {
            std::cout << "Numero de equipamento invalido!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        break;
    } while (true);

    if (salas[numSala - 1]->adicionarEquipamento(*equipamentos[numEquipamento - 1]))
    {
        std::cout << "Equipamento adicionado com sucesso!" << std::endl;
    }
    else
    {
        std::cout << "Nao foi possível adicionar o equipamento na sala!" << std::endl;
    }
}

void removerEquipamentoSala(Sala *salas[], int nSalas)
{
    if (nSalas == 0)
    {
        std::cout << "\nNenhuma sala cadastrada!" << std::endl;
        return;
    }

    int numSala, numEquipamento;

    std::cout << "\n=== Remover Equipamento da Sala ===" << std::endl;

    // Lista as salas com seus equipamentos
    for (int i = 0; i < nSalas; i++)
    {
        std::cout << "\nSala #" << (i + 1) << std::endl;
        std::cout << "Número: " << salas[i]->getNumero() << std::endl;
        std::cout << "Quantidade de equipamentos: " << salas[i]->getQuantidadeEquipamentos() << std::endl;
        salas[i]->exibirDados();
    }

    do
    {
        std::cout << "\nSelecione o numero da sala (1-" << nSalas << "): ";
        std::cin >> numSala;

        if (std::cin.fail() || numSala < 1 || numSala > nSalas)
        {
            std::cout << "Numero de sala invalido!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (salas[numSala - 1]->getQuantidadeEquipamentos() == 0)
        {
            std::cout << "Esta sala não possui equipamentos!" << std::endl;
            return;
        }
        break;
    } while (true);

    do
    {
        std::cout << "Selecione o nymero do equipamento para remover (1-"
                  << salas[numSala - 1]->getQuantidadeEquipamentos() << "): ";
        std::cin >> numEquipamento;

        if (std::cin.fail() || numEquipamento < 1 ||
            numEquipamento > salas[numSala - 1]->getQuantidadeEquipamentos())
        {
            std::cout << "Nymero de equipamento invalido!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        break;
    } while (true);

    if (salas[numSala - 1]->removerEquipamento(numEquipamento - 1))
    {
        std::cout << "Equipamento removido com sucesso!" << std::endl;
    }
    else
    {
        std::cout << "Nao foi possível remover o equipamento!" << std::endl;
    }
}