#pragma once
#include <vector>
#include <iostream>
class Cpu
{
	public:
		Cpu(std::vector<unsigned int> hexInstuctions);
	private:
		void readInstructions();
		std::vector<unsigned int> instructions;
		unsigned int v[16]; //Registradores (o Chip8 possui 16)
		unsigned int I; //Registrador usado para guardar endereços de memoria;
};

