/*****************************************************************//**
 * \file   Gestor.c
 * \brief  Gestor functions
 * 
 * \author Gabriel
 * \date   March 2023
 *********************************************************************/
#include "Stuff.h"

 // Adiciona um novo gestor ao array de gestores
void addGestor(Gestor* gestores, int* numgestores, char* username, char* password, char* nome, char* email) {
    if (*numgestores < MAX_GESTOR) {
        Gestor novoGestor;
        strncpy(novoGestor.username, username, MAX_GESTOR);
        strncpy(novoGestor.password, password, MAX_GESTOR);
        strncpy(novoGestor.nome, nome, MAX_GESTOR);
        strncpy(novoGestor.email, email, MAX_GESTOR);
        gestores[*numgestores] = novoGestor;
        (*numgestores)++;
    }
    else {
        printf("Não é possível adicionar mais gestores.\n");
    }
}

void removerGestor(Gestor* gestores, int* numGestores, char* username) {
    // Encontra o índice do gestor com o nome de usuário correspondente
    int indice = -1;
    for (int i = 0; i < *numGestores; i++) {
        if (strcmp(gestores[i].username, username) == 0) {
            indice = i;
            break;
        }
    }

    // Se o gestor foi encontrado, mova-o para o final do array
    if (indice >= 0) {
        gestores[indice] = gestores[*numGestores - 1];
        (*numGestores)--;

        // Libera o espaço ocupado pelo último gestor
        gestores = (Gestor*)realloc(gestores, (*numGestores) * sizeof(Gestor));
    }
}

void alterarGestor(Gestor* gestores, int numGestores, int index, char* novoNome, char* novoEmail) {
    // Verifica se o índice fornecido está dentro do intervalo válido
    if (index < 0 || index >= numGestores) {
        printf("Indice de gestor invalido!\n");
        return;
    }

    // Altera os dados do gestor
    strcpy(gestores[index].nome, novoNome);
    strcpy(gestores[index].email, novoEmail);
}

