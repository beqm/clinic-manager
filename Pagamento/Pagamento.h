#ifndef PAGAMENTO_H
#define PAGAMENTO_H
#include <ctime>
#include <string>
#include "../Paciente/Paciente.h"

class Pagamento
{
private:
    int idDoPagamento;
    Paciente paciente;
    double valorTotal;
    std::string descricaoDoServico;
    std::string metodoDePagamento;
    time_t dataDoServico;
    bool statudDoPagamento;

public:
    Pagamento();
    Pagamento(int bId, Paciente pac, double amount, std::string description);

    int getIdDoPagamento() const;
    Paciente getPaciente() const;
    double getValorTotal() const;
    std::string getDescricaoDoServico() const;
    std::string GetMetodoDePagamento() const;
    bool getStatusDoPagamento() const;

    void setMetodoDePagamento(const std::string& method);

    void registrarPagamento(const std::string& method);

    std::string formatarData(const time_t& date) const;

    void imprimirDetalhesDoPagamento() const;
};

#endif //PAGAMENTO_H
