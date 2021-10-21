/*
 * Header file that contains function and variable declarations for the Snake class
 */
#pragma once

class Snake {
	int headX, headY;
	int tailSize;
	int tailX[500], tailY[500];

public:
	Snake(int x, int y, int n);

	int getX();
	int getY();
	int getTail();
	int getTailX(int index);
	int getTailY(int index);

	void setTailSize(int a);
	void setX(int x);
	void setY(int y);
	void setTailX(int index, int x);
	void setTailY(int index, int y);
};