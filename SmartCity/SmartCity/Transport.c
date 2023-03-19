/*****************************************************************//**
 * \file   Transport.c
 * \brief  Transport functions
 * 
 * \author Gabriel
 * \date   March 2023
 *********************************************************************/
#include "Stuff.h"
/*
void addTransporte(Transporte* transport, int* numtransports, char* id, char* tipo, float carga, float custo, char* geocodigo) {
    // aloca espaço para o novo transporte
    transport = (Transporte*)realloc(transport, (*numtransports + 1) * sizeof(Transporte));

    // preenche os dados do novo transporte
    Transporte newTransporte;
    newTransporte.id = id;
    newTransporte.tipo = tipo;
    newTransporte.carga = carga;
    newTransporte.custo = custo;
    newTransporte.geocodigo = geocodigo;

    // adiciona o novo transporte ao final do array
    transport[*numtransports] = newTransporte;

    // incrementa o número de transportes no array
    *numtransports += 1;
    
}*/
void addTransporte(Transporte* transportes, int* numtransportes, char* id, char* tipo, float carga, float custo, char* geocodigo) {
    if (*numtransportes < MAX_VEHICLES) {
        Transporte novoTransporte;
        strncpy(novoTransporte.id, id, MAX_VEHICLES);
        strncpy(novoTransporte.tipo, tipo, MAX_VEHICLES);
        novoTransporte.carga = carga;
        novoTransporte.custo = custo;
        strncpy(novoTransporte.geocodigo, geocodigo, MAX_VEHICLES);
        transportes[*numtransportes] = novoTransporte;
        (*numtransportes)++;
    }
    else {
        printf("Não é possível adicionar mais transportes.\n");
    }
}

void removerTransporte(Transporte* transportes, int* numTransportes, char* id) {
    // Encontra o índice do transporte com o ID correspondente
    int indice = -1;
    for (int i = 0; i < *numTransportes; i++) {
        if (strcmp(transportes[i].id, id) == 0) {
            indice = i;
            break;
        }
    }

    // Se o transporte foi encontrado, mova-o para o final do array
    if (indice >= 0) {
        transportes[indice] = transportes[*numTransportes - 1];
        (*numTransportes)--;

        // Libera o espaço ocupado pelo último transporte
        transportes = (Transporte*)realloc(transportes, (*numTransportes) * sizeof(Transporte));
    }
}

void alterarTransporte(Transporte* transportes, int numTransportes, int index, char* NovoID, float NovoCusto) {
    // Verifica se o índice fornecido está dentro do intervalo válido
    if (index < 0 || index >= numTransportes) {
        printf("Indice de transporte invalido!\n");
        return;
    }

    // Altera os dados do transporte
    strcpy(transportes[index].id, NovoID);
    transportes[index].custo = NovoCusto;
}