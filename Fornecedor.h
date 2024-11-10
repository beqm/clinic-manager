#ifndef FORNECEDOR_H
#define FORNECEDOR_H
#include <string>
#include <iostream>

class Fornecedor
{
private:
    std::string nome;
    std::string cnpj;
    std::string telefone;
    std::string email;
    std::string endereco;
    std::string tipoDeProduto;

public:
    Fornecedor();

    Fornecedor(const std::string& nome,
               const std::string& cnpj,
               const std::string& telefone,
               const std::string& email,
               const std::string& endereco,
               const std::string& tipoDeProduto);

    std::string getNome() const;
    std::string getCnpj() const;
    std::string getTelefone() const;
    std::string getEmail() const;
    std::string getEndereco() const;
    std::string getTipoDeProduto() const;

    void setNome(const std::string& novoNome);
    void setCnpj(const std::string& novoCnpj);
    void setTelefone(const std::string& novoTelefone);
    void setEmail(const std::string& novoEmail);
    void setEndereco(const std::string& novoEndereco);
    void setTipoDeProduto(const std::string& novoTipo);

    void exibirDados() const;
};

#endif //FORNECEDOR_H
