#include <stdio.h>

enum Op { LOAD, ADD, PRINT, HALT };
struct CPU {
    int registers[8];
    int memory[256];
    int pc;           // program counter — tracks which instruction we're on
};


int main() {
    // --- SYNTAX REFERENCE ---
    // Variables:      int x = 5;   char c = 'a';   float f = 3.14;
    // Arrays:         int arr[8] = {0};             // all zeros
    //                 arr[0] = 99;                  // set element
    //                 arr[0];                       // get element
    // Printf:         %d = int,  %c = char,  %f = float,  %s = string
    //                 printf("val: %d\n", x);
    // For loop:       for (int i = 0; i < 8; i++) { }
    // If/else:        if (x == 5) { } else { }
    // Function:       int add(int a, int b) { return a + b; }
    // Struct:         struct CPU { int regs[8]; int memory[256]; };
    // Enum:           enum Op { LOAD, ADD, PRINT, HALT };
    // -------------------------


    //create a cpu struct and initialize fill everything inside to 0
    struct CPU cpu = {0};

    //hard coded program
    int program[] = { LOAD, 0, 5,  LOAD, 1, 10,  ADD, 0, 1, 2,  PRINT, 2,  HALT };
    int len_program = sizeof(program) / sizeof(program[0]);

    //copy the program into memory
    for (int i = 0; i < len_program; i++) {
        cpu.memory[i] = program[i];
    }

           
    // print registers
    printf("=== REGISTERS ===\n");
    for (int i = 0; i < 8; i++) {
        printf("R%d: %d\n", i, cpu.registers[i]);
    }

    // print first 16 slots of memory
    printf("\n=== MEMORY (first 16) ===\n");
    for (int i = 0; i < 16; i++) {
        printf("[%d]: %d\n", i, cpu.memory[i]);
    }

    printf("\nPC: %d\n", cpu.pc);

    return 0;
}
