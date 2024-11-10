#include "Especialidade.h"
#include <iostream>

bool isNumeric(const std::string &str)
{
    for (char c : str)
    {
        if (!std::isdigit(c) && c != '.')
        { // Verifica se o caractere é dígito ou ponto (para valores decimais)
            return false;
        }
    }
    return true;
}

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
void Especialidade::printarDados() const
{
    std::cout << "Especialidade: " << nome << std::endl;
    std::cout << "Descrição: " << descricao << std::endl;
    std::cout << "Código: " << codigo << std::endl;
    std::cout << "Duração média (minutos): " << tempo << std::endl;
    std::cout << "Valor: R$" << valor << std::endl;
}

void Especialidade::adicionarEspecialidade(Especialidade *especialidades[], int &nEspecialidades)
{
    std::string nome, descricao, codigo, tempoStr, valorStr;
    int tempo;
    double valor;

    std::cout << "Digite o nome da especialidade: ";
    std::cin.ignore(); // Limpar o buffer de entrada
    std::getline(std::cin, nome);

    std::cout << "Digite a descricao da especialidade: ";
    std::getline(std::cin, descricao);

    std::cout << "Digite o codigo da especialidade: ";
    std::cin >> codigo;

    // Verifica se o código é válido
    if (codigo.empty())
    {
        std::cout << "O codigo não pode ser vazio.\n";
        return;
    }

    // Solicita o tempo médio de duração da consulta, garantindo que seja um número maior que 0
    do
    {
        std::cout << "Digite o tempo medio de duração da consulta em minutos: ";
        std::cin >> tempoStr;

        if (!isNumeric(tempoStr))
        {
            std::cout << "Por favor, insira um numero valido para o tempo.\n";
            continue;
        }

        tempo = std::stoi(tempoStr); // Converte a string para inteiro
        if (tempo <= 0)
        {
            std::cout << "O tempo deve ser maior que 0.\n";
        }

    } while (tempo <= 0);

    // Solicita o valor da consulta, garantindo que seja um número maior que 0
    do
    {
        std::cout << "Digite o valor da consulta (maior que 0): ";
        std::cin >> valorStr;

        if (!isNumeric(valorStr))
        {
            std::cout << "Por favor, insira um número válido para o valor.\n";
            continue;
        }

        valor = std::stod(valorStr); // Converte a string para double
        if (valor <= 0)
        {
            std::cout << "O valor deve ser maior que 0.\n";
        }

    } while (valor <= 0);

    // Cria uma nova especialidade com os dados fornecidos
    especialidades[nEspecialidades] = new Especialidade(nome, descricao, codigo, tempo, valor);
    nEspecialidades++;

    std::cout << "Especialidade '" << nome << "' adicionada com sucesso.\n";
}
