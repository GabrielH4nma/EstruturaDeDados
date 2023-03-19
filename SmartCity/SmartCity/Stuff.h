/*****************************************************************//**
 * \file   Stuff.h
 * \brief  Client/Transport/Gestor info
 * 
 * \author Gabriel
 * \date   March 2023
 *********************************************************************/
 // Este é um arquivo de cabeçalho que impede várias inclusões do mesmo cabeçalho.
 // Se não estiver definido, então está definido e tudo no cabeçalho é incluído.
#pragma once

#ifndef DATA_H
#define DATA_H

// Forward declarations of struct types
typedef struct Cliente Cliente;
typedef struct Gestor Gestor;
typedef struct Transporte Transporte;

// Include standard input/output library, standard library and string library.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for the maximum size of a string and the maximum number of clients and vehicles.
#define MAX_GESTOR 256
#define MAX_CLIENTS 100
#define MAX_VEHICLES 100

// Define a structure for a client, which contains their tax identification number, name, address and balance.
typedef struct {
	char nif[MAX_CLIENTS];
	char nome[MAX_CLIENTS];
	char morada[MAX_CLIENTS];
	float saldo;
} Cliente;

// Define a structure for an electric mobility device, which contains its id, type, load, cost and geo code.
typedef struct {
	char id[MAX_VEHICLES];
	char tipo[MAX_VEHICLES];
	float carga;
	float custo;
	char geocodigo[MAX_VEHICLES];
} Transporte;

// Define a structure for a manager, which contains their username, password, name and email.
typedef struct {
	char username[MAX_GESTOR];
	char password[MAX_GESTOR];
	char nome[MAX_GESTOR];
	char email[MAX_GESTOR];
} Gestor;

#endif