#ifndef ESPECIALIDADE_H
#define ESPECIALIDADE_H

#include <string>

class Especialidade
{
private:
    std::string nome;
    std::string descricao;
    std::string codigo;
    int tempo;    // Tempo médio de duração da consulta em minutos
    double valor; // Valor da consulta

public:
    // Construtor
    Especialidade(const std::string &nome, const std::string &descricao, std::string codigo, int tempo, double valor);

    // Getters
    std::string getNome() const;
    std::string getDescricao() const;
    std::string getCodigo() const;
    int getTempo() const;
    double getValor() const;

    // Setters
    void setNome(const std::string &nome);
    void setDescricao(const std::string &descricao);
    void setCodigo(std::string codigo);
    void setTempo(int tempo);
    void setValor(double valor);

    // Exibe as informações da especialidade (opcional para debug ou visualização)
    void printarDados() const;
    static void adicionarEspecialidade(Especialidade *especialidades[], int &nEspecialidades);
};

#endif
