#include <csdint>
#include <chrono>
#include <random>

class Chip8 {
    Chip8()
        : randGen(std::chrono::system_clock::now().time_since_epoch().count()) {
        
        randByte = std::uniform_int_distribution<uint8_t>(0, 255U);
    }

    public:
        uint8_t registers[16]{};
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

        std::default_random_engine randGen;
        std::uniform_int_distribution<uint8_t> randByte;


}
