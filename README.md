# e-folio A 2024-25 - Process Tree

This project was developed for the course **Operating Systems** (UC: 21111) at UAB, as part of e-folio A 2024-25. The goal is to create and visualize a process tree in C, using `fork()`, `wait()`, and other POSIX functions.

## Project Structure

- **avp.c**: Main source code implementing the process tree.
- **README.md**: This documentation file.

## Compilation

To compile the program, use the following command in a Linux or macOS terminal:

```bash
gcc -Wall -std=c99 -o avp avp.c
```

## Execution

After compilation, run the program with:

```bash
./avp
```

## How it Works

The program creates a process tree based on the student number defined in the code (`NUMERO_ALUNO`).  
- If the number is odd, it runs the `problema1()` function.
- If the number is even, it runs the `problema0()` function.

Each process prints its identifier (PID) and its parent process identifier (PPID), allowing you to visualize the process hierarchy.

### Example Output

```
Problema 1
Process A: PID=12345 PPID=6789
Process B: PID=12346 PPID=12345
Process C: PID=12347 PPID=12345
Process D: PID=12348 PPID=12345
Process E: PID=12349 PPID=12348
```

- **A** is the main (parent) process.
- **B**, **C**, and **D** are direct children of **A**.
- **E** is a child of **D**.

## Notes

- The program must be run in a POSIX-compatible environment (Linux or macOS).
- The order in which processes are printed may vary due to the operating system scheduler, but the hierarchy will always be correct.

## Author

- [Your Name]
- Student number: 1111111

---
