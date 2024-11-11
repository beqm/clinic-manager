#include "Fornecedor.h"

Fornecedor::Fornecedor()
{
}

Fornecedor::Fornecedor(const std::string& nome,
                       const std::string& cnpj,
                       const std::string& telefone,
                       const std::string& email,
                       const std::string& endereco,
                       const std::string& tipoDeProduto)
    : nome(nome),
      cnpj(cnpj),
      telefone(telefone),
      email(email),
      endereco(endereco),
      tipoDeProduto(tipoDeProduto)
{
}

std::string Fornecedor::getNome() const { return nome; }
std::string Fornecedor::getCnpj() const { return cnpj; }
std::string Fornecedor::getTelefone() const { return telefone; }
std::string Fornecedor::getEmail() const { return email; }
std::string Fornecedor::getEndereco() const { return endereco; }
std::string Fornecedor::getTipoDeProduto() const { return tipoDeProduto; }

void Fornecedor::setNome(const std::string& novoNome) { nome = novoNome; }
void Fornecedor::setCnpj(const std::string& novoCnpj) { cnpj = novoCnpj; }
void Fornecedor::setTelefone(const std::string& novoTelefone) { telefone = novoTelefone; }
void Fornecedor::setEmail(const std::string& novoEmail) { email = novoEmail; }
void Fornecedor::setEndereco(const std::string& novoEndereco) { endereco = novoEndereco; }
void Fornecedor::setTipoDeProduto(const std::string& novoTipo) { tipoDeProduto = novoTipo; }

void Fornecedor::exibirDados() const
{
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "CNPJ: " << cnpj << std::endl;
    std::cout << "Telefone: " << telefone << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Endereço: " << endereco << std::endl;
    std::cout << "Tipo de Produto: " << tipoDeProduto << std::endl;
}
