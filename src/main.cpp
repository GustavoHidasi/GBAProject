#include "cpu.h"
#include "bus.h"
#include <iostream>

int main(){
    Bus bus;
    CPU cpu(&bus);

    bus.write32(0x00000000,0xE3A00001);
    cpu.step();

    return 0;
}