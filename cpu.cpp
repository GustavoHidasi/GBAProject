#include "cpu.h"
#include "bus.h"
#include <iostream>

CPU::CPU(Bus*bus) : bus(bus){
    reset();
}

void CPU::reset() {
    registers.fill(0);
    cpsr = 0;

}

void CPU::step(){
    uint32_t pc = registers[15];
    uint32_t opcode = bus ->read32(pc);
    registers[15] += 4;
    execute(opcode)
}

void CPU::execute(uint32_t opcode){
    std::cout << "Executando opcode: 0x"

              << std::hex << opcode << std::dec << std::endl;
}