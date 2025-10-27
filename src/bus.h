#pragma once
#include <cstdint>
#include "memory.h"

class Bus{
public:
   Bus();
   uint8_t read8(uint32_t addr);
   uint16_t read16(uint32_t addr);
   uint32_t read32(uint32_t addr);

   void write8(uint32_t addr, uint8_t value);
   void write16(uint32_t addr, uint16_t value);
   void write32(uint32_t addr, uint32_t value);

private:
  Memory bios;
  Memory ewram;
  Memory iwram;
};