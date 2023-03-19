/*****************************************************************//**
 * \file   SmartCity.c
 * \brief  Main do program
 * 
 * \author Gabriel
 * \date   March 2023
 *********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stuff.h"

int main() {
	// cria um array de Transporte
	Transporte* transport = NULL;
	Cliente clientes[MAX_CLIENTS];
	int numclientes = 0;
	Gestor gestores[MAX_GESTOR];
	int numgestores = 0;
	int numtransports = 0;

	// lê os dados de um arquivo binário
	//char* filename = "transport.bin";
	//readTransporteFromFile(filename, transport, numtransports);

	// adiciona um novo Transporte
	addTransporte(transport, &numtransports, "123114142", "ss", 1.50, 22.9, "234512");
	// adiciona um novo Cliente e Gestor
	addCliente(clientes, &numclientes, "12345612319", "João Silva", "Rua A, nº 919191911", 1000.0);
	addGestor(gestores, &numgestores, "admin", "1234", "Administrador", "admin@admin.com");
	/*
	// imprime as informações de cada Transporte
	for (int i = 0; i < numtransports; i++) {
		printMobility(&transport[i]);
	}

	// atualiza os dados de um transport
	int transportIndex = 3;
	transport[transportIndex].carga = 30;
	updateMobility(&transport[transportIndex]);

	// escreve as mobilidades em um arquivo binário
	writeMobilitiesToFile(filename, transport, numtransports);

	// libera a memória alocada
	free(transport);*/
}
