#include <csdint> // look into this

class chip8 {
    public:
        uint8_t register[16]{};
        uint8_t memory[4096]{};
        uint16_t indexReg{};
        uint16_t programCount{};
        uint16_t stack[16]{};
        uint8_t stackPoint{};
        uint8_t delayTimer{};
        uint8_t soundTimer{};
        uint8_t inputKeys[16]{}; 
        uint32_t video[64 * 32]{};
        uint16_t opcode;
}