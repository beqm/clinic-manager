#include "Sala.h"
#include "Equipamento.h"

Sala::Sala(const std::string& numero,
           int andar,
           const std::string& tipo,
           int capacidade)
    : numero(numero),
      andar(andar),
      tipo(tipo),
      disponibilidade(true),
      capacidade(capacidade),
      quantidadeEquipamentos(0)
{
}

std::string Sala::getNumero() const { return numero; }
int Sala::getAndar() const { return andar; }
std::string Sala::getTipo() const { return tipo; }
bool Sala::getDisponibilidade() const { return disponibilidade; }
int Sala::getCapacidade() const { return capacidade; }
int Sala::getQuantidadeEquipamentos() const { return quantidadeEquipamentos; }

void Sala::setNumero(const std::string& novoNumero) { numero = novoNumero; }
void Sala::setAndar(int novoAndar) { andar = novoAndar; }
void Sala::setTipo(const std::string& novoTipo) { tipo = novoTipo; }
void Sala::setDisponibilidade(bool novaDisponibilidade) { disponibilidade = novaDisponibilidade; }
void Sala::setCapacidade(int novaCapacidade) { capacidade = novaCapacidade; }

bool Sala::adicionarEquipamento(const Equipamento& equipamento)
{
    if (quantidadeEquipamentos < 5)
    {
        equipamentos[quantidadeEquipamentos] = equipamento;
        quantidadeEquipamentos++;
        return true;
    }
    return false;
}

bool Sala::removerEquipamento(int indice)
{
    if (indice >= 0 && indice < quantidadeEquipamentos)
    {
        for (int i = indice; i < quantidadeEquipamentos - 1; i++)
        {
            equipamentos[i] = equipamentos[i + 1];
        }
        quantidadeEquipamentos--;
        return true;
    }
    return false;
}

int Sala::buscarEquipamento(const std::string& nome) const
{
    for (int i = 0; i < quantidadeEquipamentos; i++)
    {
        if (equipamentos[i].getNome() == nome)
        {
            return i;
        }
    }
    return -1;
}

void Sala::exibirDados() const
{
    std::cout << "Número: " << numero << std::endl;
    std::cout << "Andar: " << andar << std::endl;
    std::cout << "Tipo: " << tipo << std::endl;
    std::cout << "Disponibilidade: " << (disponibilidade ? "Disponível" : "Ocupada") << std::endl;
    std::cout << "Capacidade: " << capacidade << " pessoas" << std::endl;

    std::cout << "\nEquipamentos (" << quantidadeEquipamentos << "):" << std::endl;
    if (quantidadeEquipamentos == 0)
    {
        std::cout << "  Nenhum equipamento cadastrado" << std::endl;
    }
    else
    {
        for (int i = 0; i < quantidadeEquipamentos; i++)
        {
            std::cout << "\nEquipamento " << (i + 1) << ":" << std::endl;
            equipamentos[i].exibirDados();
        }
    }
}
