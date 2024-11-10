#include "Equipamento.h"
#include <string>
#include <ctime>
#include <iostream>
#include "../Fornecedor/Fornecedor.h"

Equipamento::Equipamento() {}

Equipamento::Equipamento(const std::string &nome,
                         const std::string &tipo,
                         const std::string &fabricante,
                         const std::string &frequenciaDeManutencao,
                         const Fornecedor &fornecedor)
    : nome(nome),
      tipo(tipo),
      fabricante(fabricante),
      frequenciaDeManutencao(frequenciaDeManutencao),
      fornecedor(fornecedor)
{
    time(&dataDeAquisicao);
}

std::string Equipamento::getNome() const { return nome; }
std::string Equipamento::getTipo() const { return tipo; }
std::string Equipamento::getFabricante() const { return fabricante; }
std::string Equipamento::getFrequenciaDeManutencao() const { return frequenciaDeManutencao; }
time_t Equipamento::getDataDeAquisicao() const { return dataDeAquisicao; }
Fornecedor Equipamento::getFornecedor() const { return fornecedor; }

void Equipamento::setNome(const std::string &novoNome) { nome = novoNome; }
void Equipamento::setTipo(const std::string &novoTipo) { tipo = novoTipo; }
void Equipamento::setFabricante(const std::string &novoFabricante) { fabricante = novoFabricante; }

void Equipamento::setFrequenciaDeManutencao(const std::string &novaFrequencia)
{
    frequenciaDeManutencao = novaFrequencia;
}

void Equipamento::setFornecedor(const Fornecedor &novoFornecedor) { fornecedor = novoFornecedor; }
void Equipamento::setDataDeAquisicao(const time_t &novaData) { dataDeAquisicao = novaData; }

std::string Equipamento::formatarData(const time_t &data) const
{
    char buffer[26];
    struct tm *timeinfo = localtime(&data);
    strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", timeinfo);
    return std::string(buffer);
}

void Equipamento::exibirDados() const
{
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Tipo: " << tipo << std::endl;
    std::cout << "Fabricante: " << fabricante << std::endl;
    std::cout << "Frequência de Manutenção: " << frequenciaDeManutencao << std::endl;
    std::cout << "Data de Aquisição: " << formatarData(dataDeAquisicao) << std::endl;
    std::cout << "\nDados do Fornecedor:" << std::endl;
    fornecedor.exibirDados();
}
