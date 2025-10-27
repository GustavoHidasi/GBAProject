#pragma once
#include <cstdint>
#include <array>

class Bus;

class CPU{ 
public:
   CPU(Bus* bus);
   

   void reset();
   void step();
private:
  Bus* bus;

  std::array<uint32_t, 16>registers;
  uint32_t cpsr;

  void execute(uint32_t opcode);
};