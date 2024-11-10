#ifndef PAGAMENTO_H
#define PAGAMENTO_H
#include <ctime>
#include <string>

class Pagamento
{
private:
    int idDoPagamento;
    int idDoPaciente;
    double valorTotal;
    std::string descricaoDoServico;
    std::string metodoDePagamento;
    time_t dataDoServico;
    bool statudDoPagamento;

public:
    Pagamento(int bId, int pId, double amount, std::string description);

    int getIdDoPagamento() const;
    int getIdDoPaciente() const;
    double getValorTotal() const;
    std::string getDescricaoDoServico() const;
    std::string GetMetodoDePagamento() const;
    bool getStatusDoPagamento() const;

    void setMetodoDePagamento(const std::string& method);

    void registrarPagamento(const std::string& method);

    std::string formatarData(const time_t& date) const;

    void imprimitDetalhesDoPagamento() const;
};

#endif //PAGAMENTO_H
