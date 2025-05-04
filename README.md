# e-folio A 2024-25 - Árvore de Processos

Este projeto foi desenvolvido para a unidade curricular **Sistemas Operativos** (UC: 21111) da UAB, no âmbito do e-fólio A 2024-25. O objetivo é criar e visualizar uma árvore de processos em C, utilizando as funções `fork()`, `wait()`, e outras funções POSIX.

## Estrutura do Projeto

- **avp.c**: Código-fonte principal que implementa a criação da árvore de processos.
- **README.md**: Este ficheiro de documentação.

## Compilação

Para compilar o programa, utilize o seguinte comando no terminal Linux ou MacOS:

```bash
gcc -Wall -std=c99 -o avp avp.c
```

## Execução

Após a compilação, execute o programa com:

```bash
./avp
```

## Funcionamento

O programa cria uma árvore de processos baseada no número de aluno definido no código (`NUMERO_ALUNO`).  
- Se o número for ímpar, executa a função `problema1()`.
- Se o número for par, executa a função `problema0()`.

Cada processo imprime o seu identificador (PID) e o identificador do seu processo pai (PPID), permitindo visualizar a hierarquia dos processos.

### Exemplo de saída

```
Problema 1
Processo A: PID=12345 PPID=6789
Processo B: PID=12346 PPID=12345
Processo C: PID=12347 PPID=12345
Processo D: PID=12348 PPID=12345
Processo E: PID=12349 PPID=12348
```

- **A** é o processo principal (pai).
- **B**, **C** e **D** são filhos de **A**.
- **E** é filho de **D**.

## Notas

- O programa deve ser executado num ambiente compatível com POSIX (Linux ou MacOS).
- A ordem de impressão dos processos pode variar devido ao agendamento do sistema operativo, mas a hierarquia será sempre respeitada.

## Autor

- [Seu Nome]
- Número de aluno: 1111111

---