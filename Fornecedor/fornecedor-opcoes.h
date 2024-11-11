#ifndef FORNECEDOR_OPCOES_H
#define FORNECEDOR_OPCOES_H

#include "Fornecedor.h"

void cadastrarFornecedor(Fornecedor* fornecedores[], int& nFornecedores);

void mostrarFornecedor(Fornecedor* fornecedor);

void listarFornecedores(Fornecedor* fornecedores[], int nFornecedores);

void editarFornecedor(std::string cnpj, Fornecedor* fornecedores[], int nFornecedores);

#endif //FORNECEDOR_OPCOES_H
