#ifndef EQUIPAMENTO_H
#define EQUIPAMENTO_H
#include <string>
#include <ctime>
#include <iostream>
#include "../Fornecedor/Fornecedor.h"

class Equipamento
{
private:
    std::string nome;
    std::string tipo;
    std::string fabricante;
    std::string frequenciaDeManutencao;
    time_t dataDeAquisicao;
    Fornecedor fornecedor;

public:
    Equipamento();

    Equipamento(const std::string& nome,
                const std::string& tipo,
                const std::string& fabricante,
                const std::string& frequenciaDeManutencao,
                const Fornecedor& fornecedor);

    std::string getNome() const;
    std::string getTipo() const;
    std::string getFabricante() const;
    std::string getFrequenciaDeManutencao() const;
    time_t getDataDeAquisicao() const;
    Fornecedor getFornecedor() const;

    void setNome(const std::string& novoNome);
    void setTipo(const std::string& novoTipo);
    void setFabricante(const std::string& novoFabricante);
    void setFrequenciaDeManutencao(const std::string& novaFrequencia);
    void setFornecedor(const Fornecedor& novoFornecedor);
    void setDataDeAquisicao(const time_t& novaData);

    std::string formatarData(const time_t& data) const;

    void exibirDados() const;
};

#endif //EQUIPAMENTO_H
