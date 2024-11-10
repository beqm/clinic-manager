#include "Especialidade.h"
#include <iostream>

// Construtor da classe Especialidade
Especialidade::Especialidade(const std::string &nome, const std::string &descricao, std::string codigo, int tempo, double valor)
    : nome(nome), descricao(descricao), codigo(codigo), tempo(tempo), valor(valor) {}

// Getters
std::string Especialidade::getNome() const
{
    return nome;
}

std::string Especialidade::getDescricao() const
{
    return descricao;
}

std::string Especialidade::getCodigo() const
{
    return codigo;
}

int Especialidade::getTempo() const
{
    return tempo;
}

double Especialidade::getValor() const
{
    return valor;
}

// Setters
void Especialidade::setNome(const std::string &novoNome)
{
    nome = novoNome;
}

void Especialidade::setDescricao(const std::string &novaDescricao)
{
    descricao = novaDescricao;
}

void Especialidade::setCodigo(std::string novoCodigo)
{
    codigo = novoCodigo;
}

void Especialidade::setTempo(int novoTempo)
{
    tempo = novoTempo;
}

void Especialidade::setValor(double novoValor)
{
    valor = novoValor;
}

// Exibe as informações da especialidade
void Especialidade::printarEspecialidade() const
{
    std::cout << "Especialidade: " << nome << std::endl;
    std::cout << "Descrição: " << descricao << std::endl;
    std::cout << "Código: " << codigo << std::endl;
    std::cout << "Duração média (minutos): " << tempo << std::endl;
    std::cout << "Valor: R$" << valor << std::endl;
}
