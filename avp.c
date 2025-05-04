/*
** file: avp.c
**
** UC: 21111 - Sistemas Operativos
** e-folio A 2024-25
** Árvore de processos
**
** Utilização: ./avp
** Compilar:   gcc -Wall -std=c99 -o avp avp.c
**
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define NUMERO_ALUNO 1111111 // Número de aluno definido

void imprimeProcesso(char letra) { // Função para imprimir o processo
    printf("Processo %c: PID=%5d PPID=%5d\n",letra, getpid(), getppid());
    fflush(stdout);  // Evita que a mensagem seja duplicada após um fork
}

void problema0() { // Função para o problema 0 (número de aluno par)
    pid_t pidB, pidC, pidD; // Criação de variáveis para os processos filhos

    imprimeProcesso('A'); // Imprime o processo A

    pidB = fork(); // Criação do processo B
    if (pidB == 0) { // Se for o processo B
        imprimeProcesso('B'); // Imprime o processo B
        exit(0); // Encerra o processo B
    }

    wait(NULL); // Espera o processo B terminar

    pidC = fork(); // Criação do processo C
    if (pidC == 0) { // Se for o processo C
        imprimeProcesso('C'); // Imprime o processo C
        
        pid_t pidE = fork(); // Criação do processo E
        if (pidE == 0) { // Se for o processo E
            imprimeProcesso('E'); // Imprime o processo E
            exit(0); // Encerra o processo E
        }
        wait(NULL); // Espera o processo E terminar
        exit(0); // Encerra o processo C
    }

    wait(NULL); // Espera o processo C terminar

    pidD = fork(); // Criação do processo D
    if (pidD == 0) { // Se for o processo D
        imprimeProcesso('D'); // Imprime o processo D
        exit(0); // Encerra o processo D
    }

    wait(NULL); // Espera o processo D terminar

}

void problema1() { // Função para o problema 1 (número de aluno ímpar)
    pid_t pidB, pidC, pidD, pidE; // Criação de variáveis para os processos filhos

    imprimeProcesso('A'); // Imprime o processo A

    pidB = fork(); // Criação do processo B
    if (pidB == 0) { // Se for o processo B
        imprimeProcesso('B'); // Imprime o processo B
        exit(0); // Encerra o processo B
    }

    wait(NULL); // Espera o processo B terminar

    pidC = fork(); // Criação do processo C
    if (pidC == 0) { // Se for o processo C
        imprimeProcesso('C'); // Imprime o processo C
        exit(0); // Encerra o processo C
    }

    wait(NULL); // Espera o processo C terminar

    pidD = fork(); // Criação do processo D
    if (pidD == 0) { // Se for o processo D
        imprimeProcesso('D'); // Imprime o processo D

        pidE = fork(); // Criação do processo E
        if (pidE == 0) { // Se for o processo E
            imprimeProcesso('E'); // Imprime o processo E
            exit(0); // Encerra o processo E
        }
        wait(NULL); // Espera o processo E terminar
        exit(0); // Encerra o processo D
    }

    wait(NULL); // Espera o processo D terminar

}

int main() {

    int numeroAluno = NUMERO_ALUNO; // Armazena o número do aluno

    if (numeroAluno % 2 == 0) { // Se o número do aluno for par
        printf("Problema 0\n"); // Imprime o problema 0
        fflush(stdout);  // Esvazia o buffer antes de criar novos processos
        problema0();
    } else {
        printf("Problema 1\n"); // Imprime o problema 1
        fflush(stdout); // Esvazia o buffer antes de criar novos processos
        problema1();
}

}