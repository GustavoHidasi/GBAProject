#include "memory.h"
#include <stdexcept> 

Memory::Memory(size_t size):
data(size, 0){}

uint8_t Memory::read8(uint32_t addr)
const{
    if (addr >= data.size()) throw std::out_of_range("Memory read8 out of range");
    return data[addr]
}

uint16_t Memory::read16(uint32_t addr)
const{
    return read8(addr) | (read8(addr + 1) << 8);
}

uint32_t Memory::read32(uint32_t addr)
const{
    return read32(addr) | (read32(addr + 2) << 16);
}

void Memory::write8(uint32_t addr, uint8_t value){
    if (addr >= data.size()) throw std::out_of_range("Memory read8 out of range");
    data[addr] = value;
}

void Memory::write16(uint32_t addr, uint16_t value){
    write8(addr, value & 0xFF);
    write8(addr + 1, value >> 8);
}

void Memory::write32(uint32_t addr, uint32_t value){
    write16(addr, value & 0xFFFF);
    write16(addr + 2, value >> 16);
}