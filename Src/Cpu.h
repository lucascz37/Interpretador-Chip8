#pragma once
#include <vector>
#include <iostream>
class Cpu
{
	public:
		Cpu(std::vector<unsigned int> hexInstuctions);
		void readInstructions();
	private:
		std::vector<unsigned int> instructions;
		unsigned int V[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //Registradores (o Chip8 possui 16)  
		unsigned int I; //Registrador usado para guardar endereços de memoria;
		unsigned int counter; //Contador do programa
		unsigned int subRoutinesAdress[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; // Ambos arrays iniciados com 0 para garantir o valor na memoria
		unsigned int currentRoutine;
};

