#include <iostream>
#include <fstream>
#include <vector>
#include "Cpu.h"
using namespace std;

vector<unsigned int> readFile() {
    ifstream rom("C://Users//lucas//Downloads//Fishie.ch8", ifstream::binary); //Local do rom 
    rom.seekg(0, rom.end);
    int length = rom.tellg();
    length += 0x200;
    rom.seekg(0, rom.beg);
    char* binary = new char[length];
    vector<unsigned int> hexInstructions(length);
    rom.read(binary, length);
    rom.close();        //Carregando Arquivo

    for (int i = 0; i < length; i++) {
        hexInstructions[i] = (unsigned int)(unsigned char)binary[i];  //Convertendo para facilitar leitura.
    }
   
    return hexInstructions;
}


int main()
{
	Cpu chip8(readFile());
	while(true){
		chip8.readInstructions();
    	int x;
		cin >> x;
	}
    
    return 0;
}
