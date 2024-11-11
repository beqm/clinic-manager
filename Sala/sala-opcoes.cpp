#include "sala-opcoes.h"
#include "Sala.h"
#include "../Equipamento/Equipamento.h"
#include <iostream>
#include <limits>

void cadastrarSala(Sala* salas[], int& nSalas) {
    std::string numero, tipo;
    int andar, capacidade;

    std::cout << "Cadastrar Sala" << std::endl;

    std::cout << "Número da sala: ";
    std::getline(std::cin, numero);

    std::cout << "Andar: ";
    std::cin >> andar;

    std::cin.ignore();

    std::cout << "Tipo da sala: ";
    std::getline(std::cin, tipo);

    std::cout << "Capacidade: ";
    std::cin >> capacidade;

    salas[nSalas] = new Sala(numero, andar, tipo, capacidade);
    nSalas++;

    std::cout << "\nSala cadastrada com sucesso!" << std::endl;
}

void listarSalas(Sala* salas[], int nSalas) {
    if(nSalas == 0) {
        std::cout << "\nNenhuma sala cadastrada!" << std::endl;
        return;
    }

    std::cout << "Salas:" << std::endl;

    for(int i = 0; i < nSalas; i++) {
        std::cout << "\nSala #" << (i + 1) << std::endl;
        std::cout << "------------------------" << std::endl;
        salas[i]->exibirDados();
        std::cout << "------------------------" << std::endl;
    }
}

void adicionarEquipamentoSala(Sala* salas[], int nSalas, Equipamento* equipamentos[], int nEquipamentos) {
    if(nSalas == 0) {
        std::cout << "\nNenhuma sala cadastrada!" << std::endl;
        return;
    }

    if(nEquipamentos == 0) {
        std::cout << "\nNenhum equipamento cadastrado!" << std::endl;
        return;
    }

    int numSala, numEquipamento;

    std::cout << "Adicionar Equipamento à Sala" << std::endl;

    // Lista as salas disponíveis
    for(int i = 0; i < nSalas; i++) {
        std::cout << "\nSala #" << (i + 1) << std::endl;
        std::cout << "Número: " << salas[i]->getNumero() << std::endl;
        std::cout << "Tipo: " << salas[i]->getTipo() << std::endl;
        std::cout << "Equipamentos: " << salas[i]->getQuantidadeEquipamentos() << "/5" << std::endl;
    }

    do {
        std::cout << "\nSelecione o número da sala (1-" << nSalas << "): ";
        std::cin >> numSala;

        if(std::cin.fail() || numSala < 1 || numSala > nSalas) {
            std::cout << "Número de sala inválido!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        break;
    } while(true);

    // Verifica se a sala está cheia
    if(salas[numSala-1]->getQuantidadeEquipamentos() >= 5) {
        std::cout << "Esta sala já atingiu o limite máximo de equipamentos!" << std::endl;
        return;
    }

    // Lista os equipamentos disponíveis
    std::cout << "\nEquipamentos disponíveis:" << std::endl;
    for(int i = 0; i < nEquipamentos; i++) {
        std::cout << "\nEquipamento #" << (i + 1) << std::endl;
        std::cout << "Nome: " << equipamentos[i]->getNome() << std::endl;
        std::cout << "Tipo: " << equipamentos[i]->getTipo() << std::endl;
    }

    do {
        std::cout << "\nSelecione o número do equipamento (1-" << nEquipamentos << "): ";
        std::cin >> numEquipamento;

        if(std::cin.fail() || numEquipamento < 1 || numEquipamento > nEquipamentos) {
            std::cout << "Número de equipamento inválido!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        break;
    } while(true);

    if(salas[numSala-1]->adicionarEquipamento(*equipamentos[numEquipamento-1])) {
        std::cout << "Equipamento adicionado com sucesso!" << std::endl;
    } else {
        std::cout << "Não foi possível adicionar o equipamento à sala!" << std::endl;
    }
}

void removerEquipamentoSala(Sala* salas[], int nSalas) {
    if(nSalas == 0) {
        std::cout << "\nNenhuma sala cadastrada!" << std::endl;
        return;
    }

    int numSala, numEquipamento;

    std::cout << "\n=== Remover Equipamento da Sala ===" << std::endl;

    // Lista as salas com seus equipamentos
    for(int i = 0; i < nSalas; i++) {
        std::cout << "\nSala #" << (i + 1) << std::endl;
        std::cout << "Número: " << salas[i]->getNumero() << std::endl;
        std::cout << "Quantidade de equipamentos: " << salas[i]->getQuantidadeEquipamentos() << std::endl;
        salas[i]->exibirDados();
    }

    do {
        std::cout << "\nSelecione o número da sala (1-" << nSalas << "): ";
        std::cin >> numSala;

        if(std::cin.fail() || numSala < 1 || numSala > nSalas) {
            std::cout << "Número de sala inválido!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if(salas[numSala-1]->getQuantidadeEquipamentos() == 0) {
            std::cout << "Esta sala não possui equipamentos!" << std::endl;
            return;
        }
        break;
    } while(true);

    do {
        std::cout << "Selecione o número do equipamento para remover (1-"
                 << salas[numSala-1]->getQuantidadeEquipamentos() << "): ";
        std::cin >> numEquipamento;

        if(std::cin.fail() || numEquipamento < 1 ||
           numEquipamento > salas[numSala-1]->getQuantidadeEquipamentos()) {
            std::cout << "Número de equipamento inválido!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        break;
    } while(true);

    if(salas[numSala-1]->removerEquipamento(numEquipamento-1)) {
        std::cout << "Equipamento removido com sucesso!" << std::endl;
    } else {
        std::cout << "Não foi possível remover o equipamento!" << std::endl;
    }
}