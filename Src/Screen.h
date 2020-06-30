#ifndef SCREEN_H
#define SCREEN_H

class Screen
{
	public:
		Screen();
		void setPixel(unsigned int x, unsigned int y, unsigned int value);
		void clearScreen();
		void drawnScreen();
		unsigned int getPixel(unsigned int x, unsigned int y);
	private:
		unsigned int screen [32][64] = {};
};

#endif
