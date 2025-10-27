#include "bus.h"

Bus::Bus()
    : bios(0x4000),     // 16KB
      ewram(0x40000),   // 256KB
      iwram(0x8000)     // 32KB
{}

uint8_t Bus::read8(uint32_t addr) {
    if (addr < 0x00004000) return bios.read8(addr);
    if (addr >= 0x02000000 && addr < 0x02040000) return ewram.read8(addr - 0x02000000);
    if (addr >= 0x03000000 && addr < 0x03008000) return iwram.read8(addr - 0x03000000);
    return 0xFF;
}

uint16_t Bus::read16(uint32_t addr) {
    return read8(addr) | (read8(addr + 1) << 8);
}

uint32_t Bus::read32(uint32_t addr) {
    return read16(addr) | (read16(addr + 2) << 16);
}

void Bus::write8(uint32_t addr, uint8_t value) {
    if (addr >= 0x02000000 && addr < 0x02040000) ewram.write8(addr - 0x02000000, value);
    if (addr >= 0x03000000 && addr < 0x03008000) iwram.write8(addr - 0x03000000, value);
}

void Bus::write16(uint32_t addr, uint16_t value) {
    write8(addr, value & 0xFF);
    write8(addr + 1, value >> 8);
}

void Bus::write32(uint32_t addr, uint32_t value) {
    write16(addr, value & 0xFFFF);
    write16(addr + 2, value >> 16);
}
