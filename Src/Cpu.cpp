#include "Cpu.h"
#include "Screen.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <windows.h>

using namespace std;
Cpu::Cpu(vector<unsigned int> hexInstuctions): instructions(hexInstuctions)
{ 
	I = 0;
	counter = 0;
	currentRoutine = 0;
	 cout << instructions.size() << endl;
}

void Cpu::readInstructions()
{
		unsigned int codeByte1 = instructions[counter] & 0x0f0; // 4 primeiros números do byte
		unsigned int codeByte2 = instructions[counter] & 0x0f; // 4 ultimos números do byte
		unsigned int secondByte = instructions[counter+1]; // Segundo Byte de instruções
		//cout << dec <<counter << endl;
		//cout << hex << instructions[counter] << " second operator: " << secondByte << endl;
		//for(int i = 0; i < 16; i++){
		//	cout << dec <<"V[" << i << "] = " << V[i] << "  ";
		//}
		//	cout << endl;
		switch (codeByte1){
			
		case 0x000:
			if(instructions[counter+1] == 0xe0){
				screen.clearScreen();
			}else if(secondByte == 0xee){
				currentRoutine--;
				counter = subRoutinesAdress[currentRoutine];
			}
			break;
			
		case 0x010:
			counter = (codeByte2*256+secondByte)-512;
			return;
			
		case 0x020:
			subRoutinesAdress[currentRoutine] = counter;
			currentRoutine++;
			counter = (codeByte2*256+secondByte)-512;
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
			V[codeByte2] = V[codeByte2] & 0x0ff;
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
				if((V[codeByte2] & 0b10000000)/128 == 1){
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
			I = (codeByte2*256+secondByte)-512;
			break;
			
		case 0x0B0:
			counter = (codeByte2*256+secondByte)-512 + V[0];
			break;
			
		case 0x0C0:
			V[codeByte2] = (rand() % 256) & secondByte;
			break;
			
		case 0x0D0:
			for(int i = 0; i < (secondByte & 0x0f); i++){
				for(int j = 0; j < 8; j++){
					unsigned int operador =  Pow(2, j);
					unsigned int resultado = (instructions[I+i] & operador) / operador;
					unsigned int cordX = V[codeByte2]+(8-j);
					unsigned int cordY = V[(secondByte & 0x0f0)/16] + i;

					//cout << dec << operador << endl;
					if(cordX > 63){
						cordX -= 63;
					}
					
					if(cordY > 31){
						cordY -= 31;
					}
					
					unsigned int valor = resultado ^ screen.getPixel(cordX, cordY);
					screen.setPixel(cordX, cordY, valor);
				}
			}
			system("cls");
			screen.drawnScreen();
			break;
			
		case 0x0E0:
			if(secondByte == 0x09e){
				cout << V[codeByte2] << endl;
				//if(GetKeyState()& 0x8000)
			}
			break;
			
		case 0x0F0:
			if(secondByte == 0x07){
				cout << "Not Implemented" << endl;
			}else if(secondByte == 0x0A){
				cout << "Not Implemented" << endl;
			}else if(secondByte == 0x015){
				cout << "Not Implemented" << endl;
			}else if(secondByte == 0x018){
				cout << "Not Implemented" << endl;	
			}else if(secondByte == 0x01e){
				I = I + V[codeByte2];
			}else if(secondByte == 0x029){
				cout << "Not Implemented" << endl;
			}else if(secondByte == 0x033){
				cout << "Not Implemented" << endl;	
			}else if(secondByte == 0x055){
				I = I + V[codeByte2];
			}else if(secondByte == 0x065){
				cout << "Not Implemented" << endl;
			}
			break;
			
		default:
			cout << hex <<instructions[counter] << endl;
			break;
		}
		
		if(counter < instructions.size()-1){
			counter += 2;
		}
}

unsigned int Cpu::Pow(int x, int j){
	int base = x;
	//cout << j << endl;
	if(j == 0){
		return 1;
	}
	for(int i = 1; i < j; i++){
		x *= base;
	}
	return x;
}
