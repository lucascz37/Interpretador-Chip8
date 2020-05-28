#include "Cpu.h"
#include <iostream>
#include <vector>
Cpu::Cpu(std::vector<unsigned int> hexInstuctions): instructions(hexInstuctions)
{
	readInstructions();
}

void Cpu::readInstructions()
{
	for (int i = 0; i < instructions.size(); i+=2) {
		unsigned int codeByte1 = instructions[i] & 0x0f0; // 4 primeiros números do byte
		unsigned int codeByte2 = instructions[i] & 0x0f; // 4 ultimos números do byte
		switch (codeByte1)
		{
		case 0x000:
			std::cout << std::hex <<instructions[i] << " Not Implemented second operator: " << instructions[i + 1] << std::endl;
			break;
		case 0x010:
			std::cout << std::hex << instructions[i] << " Not Implemented second operator: " << instructions[i + 1] << std::endl;
			break;
		case 0x020:
			std::cout << std::hex << instructions[i] << " Not Implemented second operator: " << instructions[i+1] << std::endl;
			break;
		case 0x030:
			std::cout << std::hex << instructions[i] << " Not Implemented second operator: " << instructions[i + 1] << std::endl;
			break;
		case 0x040:
			std::cout << std::hex << instructions[i] << " Not Implemented second operator: " << instructions[i + 1] << std::endl;
			break;
		case 0x050:
			std::cout << std::hex << instructions[i] << " Not Implemented second operator: " << instructions[i + 1] << std::endl;
			break;
		case 0x060:
			std::cout << std::hex << instructions[i] << " Not Implemented second operator: " << instructions[i + 1] << std::endl;
			break;
		case 0x070:
			std::cout << std::hex << instructions[i] << " Not Implemented second operator: " << instructions[i + 1] << std::endl;
			break;
		case 0x080:
			std::cout << std::hex << instructions[i] << " Not Implemented second operator: " << instructions[i + 1] << std::endl;
			break;
		case 0x090:
			std::cout << std::hex << instructions[i] << " Not Implemented second operator: " << instructions[i + 1] << std::endl;
			break;
		case 0x0A0:
			std::cout << std::hex << instructions[i] << " Not Implemented second operator: " << instructions[i + 1] << std::endl;
			break;
		case 0x0B0:
			std::cout << std::hex << instructions[i] << " Not Implemented second operator: " << instructions[i + 1] << std::endl;
			break;
		case 0x0C0:
			std::cout << std::hex << instructions[i] << " Not Implemented second operator: " << instructions[i + 1] << std::endl;
			break;
		case 0x0D0:
			std::cout << std::hex << instructions[i] << " Not Implemented second operator: " << instructions[i + 1] << std::endl;
			break;
		case 0x0E0:
			std::cout << std::hex << instructions[i] << " Not Implemented second operator: " << instructions[i + 1] << std::endl;
			break;
		case 0x0F0:
			std::cout << std::hex << instructions[i] << " Not Implemented second operator: " << instructions[i + 1] << std::endl;
			break;
		default:
			std::cout << std::hex <<instructions[i] << std::endl;
			break;
		}
	}
}
