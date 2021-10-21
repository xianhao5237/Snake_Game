/*
 * Header file that contains function and variable declarations for the Food class
 */
#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

class Food {
	int posX, posY;
	int width, height;

public:
	Food(int w, int h);

	int getPosX();
	int getPosY();
	void randomFood();
};