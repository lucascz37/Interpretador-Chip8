#pragma once
#include <vector>
#include <iostream>
#include "Screen.h"
class Cpu
{
	public:
		Cpu(std::vector<unsigned int> hexInstuctions);
		void readInstructions();
	private:
		unsigned int Pow(int x, int j);
		std::vector<unsigned int> instructions;
		unsigned int V[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //Registradores (o Chip8 possui 16)  
		unsigned int I; //Registrador usado para guardar endereços de memoria;
		unsigned int counter; //Contador do programa
		unsigned int subRoutinesAdress[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; // Ambos arrays iniciados com 0 para garantir o valor na memoria
		unsigned int currentRoutine;
		Screen screen;
};

