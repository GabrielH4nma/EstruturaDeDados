/*****************************************************************//**
 * \file   Client.c
 * \brief  Client functions
 * 
 * \author Gabriel
 * \date   March 2023
 *********************************************************************/
#include "Stuff.h"

 // Adiciona um novo cliente ao array de clientes
void addCliente(Cliente* clientes, int* numclientes, char* nif, char* nome, char* morada, float saldo) {
    if (*numclientes < MAX_CLIENTS) {
        Cliente novoCliente;
        strncpy(novoCliente.nif, nif, MAX_CLIENTS);
        strncpy(novoCliente.nome, nome, MAX_CLIENTS);
        strncpy(novoCliente.morada, morada, MAX_CLIENTS);
        novoCliente.saldo = saldo;
        clientes[*numclientes] = novoCliente;
        (*numclientes)++;
    }
    else {
        printf("Não é possível adicionar mais clientes.\n");
    }
}

void removerCliente(Cliente* clientes, int* numClientes, char* nif) {
    // Encontra o índice do cliente com o NIF correspondente
    int indice = -1;
    for (int i = 0; i < *numClientes; i++) {
        if (strcmp(clientes[i].nif, nif) == 0) {
            indice = i;
            break;
        }
    }

    // Se o cliente foi encontrado, mova-o para o final do array
    if (indice >= 0) {
        clientes[indice] = clientes[*numClientes - 1];
        (*numClientes)--;

        // Libera o espaço ocupado pelo último cliente
        clientes = (Cliente*)realloc(clientes, (*numClientes) * sizeof(Cliente));
    }
}

void alterarCliente(Cliente* clientes, int numClientes, int index, char* novoNome, char* novaMorada, float novoSaldo) {
    // Verifica se o índice fornecido está dentro do intervalo válido
    if (index < 0 || index >= numClientes) {
        printf("Indice de cliente invalido!\n");
        return;
    }

    // Altera os dados do cliente
    strcpy(clientes[index].nome, novoNome);
    strcpy(clientes[index].morada, novaMorada);
    clientes[index].saldo = novoSaldo;
}