#include <csdint> // look into this
#include <fstream>

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

const unsigned int startAddress = 0x200;

void Chip8::LoadROM(char const* filename) {
    std::ifstream file(filename, std::ios::binary | std::ios::ate);

    if (file.is_open()){
        std::streampos size = file.tellg();
        char* buffer = new char[size];

        file.seekg(0, std::ios::beg);
        file.read(buffer, size);
        file.close()

        for (long i = 0; i < size; i++) {
            memory[startAddress + 1] = buffer[i];
        }

        delete[] buffer;
    }
}

Chip8::Chip8() {
    // Initialise PC
    pc = startAddress;
}