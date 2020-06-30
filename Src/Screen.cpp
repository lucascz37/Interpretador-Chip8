#include "Screen.h"
#include <iostream>
Screen::Screen(){
	clearScreen();
}

void Screen::clearScreen(){
	for(int i = 0; i < 32; i++){
		for(int j = 0; j < 64; j++){
			screen[i][j] = 0;
		}

	}
}

void Screen::drawnScreen(){
	for(int i = 0; i < 32; i++){
		for(int j = 0; j < 64; j++){
			if(screen[i][j]){
				std::cout << "0 ";
			}else{
				std::cout << "  ";
			}
		}
		std::cout << std::endl;
	}
}

void Screen::setPixel(unsigned int x, unsigned int y, unsigned int value){
	screen[y][x] = value;
}

unsigned int Screen::getPixel(unsigned int x, unsigned int y){
	return screen[y][x];
}
