#include "Pagamento.h"
#include <string>
#include <chrono>
#include <iostream>

Pagamento::Pagamento(int bId, int pId, double amount, std::string description)
    : idDoPagamento(bId),
      idDoPaciente(pId),
      valorTotal(amount),
      descricaoDoServico(description),
      statudDoPagamento(false)
{
    time(&dataDoServico);
}

int Pagamento::getIdDoPagamento() const { return idDoPagamento; }
int Pagamento::getIdDoPaciente() const { return idDoPaciente; }
double Pagamento::getValorTotal() const { return valorTotal; }
std::string Pagamento::getDescricaoDoServico() const { return descricaoDoServico; }
std::string Pagamento::GetMetodoDePagamento() const { return metodoDePagamento; }
bool Pagamento::getStatusDoPagamento() const { return statudDoPagamento; }

void Pagamento::setMetodoDePagamento(const std::string& method) { metodoDePagamento = method; }

void Pagamento::registrarPagamento(const std::string& method)
{
    statudDoPagamento = true;
    metodoDePagamento = method;
}

std::string Pagamento::formatarData(const time_t& date) const
{
    char buffer[26];
    struct tm* timeinfo = localtime(&date);
    strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", timeinfo);
    return std::string(buffer);
}

void Pagamento::imprimitDetalhesDoPagamento() const
{
    std::cout << "ID da Cobrança: " << idDoPagamento << std::endl;
    std::cout << "ID do Paciente: " << idDoPaciente << std::endl;
    std::cout << "Valor Total: R$ " << valorTotal << std::endl;
    std::cout << "Descrição: " << descricaoDoServico << std::endl;
    std::cout << "Data do Serviço: " << formatarData(dataDoServico) << std::endl;
    std::cout << "Status: " << (statudDoPagamento ? "Pago" : "Pendente") << std::endl;

    if (statudDoPagamento)
    {
        std::cout << "Método de Pagamento: " << metodoDePagamento << std::endl;
    }
}