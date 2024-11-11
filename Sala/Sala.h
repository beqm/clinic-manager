#ifndef SALA_H
#define SALA_H
#include <string>
#include <iostream>
#include "../Equipamento/Equipamento.h"

class Sala
{
private:
    std::string numero;
    int andar;
    std::string tipo;
    bool disponibilidade;
    int capacidade;
    Equipamento equipamentos[5];
    int quantidadeEquipamentos;

public:
    Sala();
    Sala(const std::string& numero,
         int andar,
         const std::string& tipo,
         int capacidade);

    std::string getNumero() const;
    int getAndar() const;
    std::string getTipo() const;
    bool getDisponibilidade() const;
    int getCapacidade() const;
    int getQuantidadeEquipamentos() const;

    void setNumero(const std::string& novoNumero);
    void setAndar(int novoAndar);
    void setTipo(const std::string& novoTipo);
    void setDisponibilidade(bool novaDisponibilidade);
    void setCapacidade(int novaCapacidade);

    bool adicionarEquipamento(const Equipamento& equipamento);

    bool removerEquipamento(int indice);

    int buscarEquipamento(const std::string& nome) const;

    void exibirDados() const;
};

#endif //SALA_H
