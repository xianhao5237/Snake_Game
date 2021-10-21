#include "Food.h"

/**
 * Constructor function that initializes the width and height of the field and the coordinates
 *
 * @param w Width of field
 * @param h Height of field
 */
Food::Food(int w, int h) {
	width = w;
	height = h;
	posX = -1;
	posY = -1;
}

/**
 * Getter function that returns the x coordinate of the food
 *
 * @return x coordinate 
 */
int Food::getPosX() {
	return posX;
}

/**
 * Getter function that returns the y coordinate of the food
 *
 * @return y coordinate
 */
int Food::getPosY() {
	return posY;
}

/**
 * This function generates random x and y coordinates for the food within the width and height
 */
void Food::randomFood() {
	srand((unsigned)time(0));
	posX = rand() % width;
	posY = rand() % height;
}