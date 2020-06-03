#include "Cpu.h"
#include <iostream>
#include <vector>
Cpu::Cpu(std::vector<unsigned int> hexInstuctions): instructions(hexInstuctions)
{
	I = 0;
	counter = 0;
	currentRoutine = 0;
	std:: cout << instructions.size() << std::endl;
}

void Cpu::readInstructions()
{
		unsigned int codeByte1 = instructions[counter] & 0x0f0; // 4 primeiros números do byte
		unsigned int codeByte2 = instructions[counter] & 0x0f; // 4 ultimos números do byte
		unsigned int secondByte = instructions[counter+1]; // Segundo Byte de instruções
		for(int i = 0; i < 16; i++){
			std::cout << "V[" << i << "] = " << V[i] << "  ";
		}
			std::cout << std::endl;
		switch (codeByte1){
			
		case 0x000:
			if(instructions[counter+1] == 0xe0){
				std::cout << "Clear Screen" << std::endl;
			}else if(secondByte == 0xee){
				currentRoutine--;
				counter = subRoutinesAdress[currentRoutine];
				std::cout << "Return" << std::endl;	
			}
			break;
			
		case 0x010:
			counter = codeByte2*16+secondByte;
			std::cout << "Jump"  << counter << std::endl;
			return;
			
		case 0x020:
			std::cout << "Subroutine" << std::endl;	
			subRoutinesAdress[currentRoutine] = counter;
			currentRoutine++;
			counter = codeByte2*16+secondByte;
			return;
			
		case 0x030:
			if(V[codeByte2] == secondByte){
				counter += 2;
			}
			break;
			
		case 0x040:
			if(V[codeByte2] != secondByte){
				counter += 2;
			}
			break;
			
		case 0x050:
			if(V[codeByte2] == V[(secondByte & 0x0f0)/16]){
				counter += 2;
			}
			break;
			
		case 0x060:
			V[codeByte2] = secondByte;
			break;
			
		case 0x070:
			V[codeByte2] += secondByte;
			break;
			
		case 0x080:
			{
				unsigned int option = secondByte & 0x0f;
			if(option == 0x01){
				V[codeByte2] = V[codeByte2] | V[(secondByte & 0x0f0)/16];
			}else if(option == 0x02){
				V[codeByte2] = V[codeByte2] & V[(secondByte & 0x0f0)/16];
			}else if(option == 0x03){
				V[codeByte2] = V[codeByte2] ^ V[(secondByte & 0x0f0)/16];
			}else if(option == 0x04){
				V[codeByte2] += V[(secondByte & 0x0f0)/16];
				if(V[codeByte2] > 255){
					V[15] = 0;
					V[codeByte2] = V[codeByte2] & 0x0ff;
				}else{
					V[15] = 1;
				}
			}else if(option == 0x05){
				if(V[codeByte2] > V[(secondByte & 0x0f0)/16]){
					V[15] = 1;
				}else{
					V[15] = 0;
				}
				V[codeByte2] = V[codeByte2] -  V[(secondByte & 0x0f0)/16];
				V[codeByte2] = V[codeByte2] & 0x0ff;
			}else if(option == 0x06){
				if((V[codeByte2] & 0b01 == 1 )){
					V[15] = 1;
				}else{
					V[15] = 0;
				}
				V[codeByte2] = V[codeByte2]/2;
			}else if(option == 0x07){
				if(V[codeByte2] > V[(secondByte & 0x0f0)/16]){
					V[15] = 0;
				}else{
					V[15] = 1;
				}
				V[codeByte2] = V[(secondByte & 0x0f0)/16] - V[codeByte2] ;
				V[codeByte2] = V[codeByte2] & 0x0ff;
			}else if(option == 0x0e){
				if((V[codeByte2] & 0b10000000)/128) == 1){
					V[15] = 1;
				}else{
					V[15] = 0;
				}
				V[codeByte2] *= 2;
				V[codeByte2] = V[codeByte2] & 0x0ff;
			}
		}
			break;
			
		case 0x090:
			if(V[codeByte2] !=  V[(secondByte & 0x0f0)/16]){
				counter += 2;
			}
			break;
			
		case 0x0A0:
			std::cout << std::hex << instructions[counter] << " Not Implemented second operator: " << instructions[counter + 1] << std::endl;
			break;
			
		case 0x0B0:
			std::cout << std::hex << instructions[counter] << " Not Implemented second operator: " << instructions[counter + 1] << std::endl;
			break;
			
		case 0x0C0:
			std::cout << std::hex << instructions[counter] << " Not Implemented second operator: " << instructions[counter + 1] << std::endl;
			break;
			
		case 0x0D0:
			std::cout << std::hex << instructions[counter] << " Not Implemented second operator: " << instructions[counter + 1] << std::endl;
			break;
			
		case 0x0E0:
			std::cout << std::hex << instructions[counter] << " Not Implemented second operator: " << instructions[counter + 1] << std::endl;
			break;
			
		case 0x0F0:
			std::cout << std::hex << instructions[counter] << " Not Implemented second operator: " << instructions[counter + 1] << std::endl;
			break;
			
		default:
			std::cout << std::hex <<instructions[counter] << std::endl;
			break;
		}
		
		if(counter < instructions.size()-1){
			counter += 2;
		}
}
