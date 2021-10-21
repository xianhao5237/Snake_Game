#include "Snake.h"

/**
 * Constructor function that initializes the x and y coordinates of the head of the snake and tail size
 *
 * @param x x coordinate
 * @param y y coordinate
 * @param n size of tail
 */
Snake::Snake(int x, int y, int n) {
	headX = x;
	headY = y;
	tailSize = n;
}

/**
 * Getter function that returns the x coordinate of the head
 *
 * @return x coordinate of snake head
 */
int Snake::getX() {
	return headX;
}

/**
 * Getter function that returns the y coordinate of the head
 *
 * @return y coordinate of snake's head
 */
int Snake::getY() {
	return headY;
}

/**
 * Getter function that returns the size of the tail
 *
 * @return snake's tail size
 */
int Snake::getTail() {
	return tailSize;
}

/**
 * Setter function that sets x coordinate of the head
 *
 * @param x Snake head's x coordinate
 */
void Snake::setX(int x) {
	headX = x;
}

/**
 * Setter function that sets y coordinate of the head
 *
 * @param y Snake head's y coordinate
 */
void Snake::setY(int y) {
	headY = y;
}

/**
 * Setter function that sets the size of the tail
 *
 * @param a Snake's tail size
 */
void Snake::setTailSize(int a) {
	tailSize = a;
}

/**
 * Getter function that returns the x coordinate for a specific tail segment
 *
 * @param index Index for specific tail segment
 * @return x coordinate of tail segment
 */
int Snake::getTailX(int index) {
	return tailX[index];
}

/**
 * Getter function that returns the y coordinate for a specific tail segment
 *
 * @param index Index for specific tail segment
 * @return y coordinate of tail segment
 */
int Snake::getTailY(int index) {
	return tailY[index];
}

/**
 * Setter function that gives a specific tail segment new x coordinate
 *
 * @param index Index for specific tail segment
 * @param x coordinate of tail segment
 */
void Snake::setTailX(int index, int x) {
	tailX[index] = x;
}

/**
 * Setter function that gives a specific tail segment new y coordinate
 *
 * @param index Index for specific tail segment
 * @param y coordinate of tail segment
 */
void Snake::setTailY(int index, int y) {
	tailY[index] = y;
}