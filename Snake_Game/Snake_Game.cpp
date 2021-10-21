/**
* Program Name: Snake Game
*
* Purpose: This program allows the user to play a game of Snake. You can control 
* the head of the snake with W,A,S,D and the tail will follow. Each time you eat 
* a food your score goes up by 10 and your tail grows by 1. If you hit your tail 
* or the wall you lose.
*
* Author: Xianhao Zhou
*
* Start Date: May 20, 2020
*
* End Date: June 11, 2020
*/
#include "Functions.h"
#include "Food.h"
#include "Snake.h"

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string>

bool gameOver;
int score = 0;
const int HEIGHT = 20; //dimensions of field
const int WIDTH = 50;

enum Directon { //direction that snake is going
	STOP, UP, DOWN, LEFT, RIGHT
};
Directon dir;

std::string field[HEIGHT][WIDTH]; //2D array that represents field
Food food(WIDTH, HEIGHT); //create food
Snake snake(WIDTH / 2, HEIGHT / 2, 0); //create snake

/**
 * Function that disables the blinking cursor. Taken from 
 * https://stackoverflow.com/questions/18028808/remove-blinking-underscore-on-console-cmd-prompt
 * 
 * @param showFlag boolean to enable or disable cursor
 */
void ShowConsoleCursor(bool showFlag) {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

/**
 * Function that sets up the game by disabling the cursor, updating 
 * the field and creating the first food.
 */
void setupGame() {
	ShowConsoleCursor(false);
	gameOver = false;
	updateField();

	do { //new food in random space until it is a empty space
		food.randomFood();
	} while (!emptySpace(food.getPosX(), food.getPosY()));
}

/**
 * Function that updates each String value in the 2D array
 */
void updateField() {
	for (int i = 0; i < HEIGHT; i++) { //loop through array
		for (int j = 0; j < WIDTH; j++) {

			if (i == 0 || i == HEIGHT - 1) { //top and bottom walls
				field[i][j] = "*";
			}
			else if (j == 0) { //left wall
				field[i][j] = "|";
			}
			else if (j == WIDTH - 1) { //right wall
				field[i][j] = "|";
			}
			else { //rest is empty space
				field[i][j] = " ";
			}

			if (j == food.getPosX() && i == food.getPosY()) { //food
				field[i][j] = "o";
			}

			if (j == snake.getX() && i == snake.getY()) { //snake head
				field[i][j] = "@";
			}

			for (int k = 0; k < snake.getTail(); k++) { //snake tail
				if (j == snake.getTailX(k) && i == snake.getTailY(k)) {
					field[i][j] = "O";
				}
			}

		}
	}
}

/**
 * Funtion that outputs the field to the console
 */
void drawField() {
	system("cls");
	for (int i = 0; i < HEIGHT; i++) { //loop through 2D array and print values
		for (int j = 0; j < WIDTH; j++) {
			std::cout << field[i][j];
		}
		std::cout << "\n";
	}
}

/**
 * Function that gets user input to controll the snake
 */
void input() {

	if (_kbhit()) { //if key is pressed
		switch (_getch()) { //change direction based on which key
		case 'w':
			if (dir != DOWN)
				dir = UP;
			break;
		case 's':
			if (dir != UP)
				dir = DOWN;
			break;
		case 'a':
			if (dir != RIGHT)
				dir = LEFT;
			break;
		case 'd':
			if (dir != LEFT)
				dir = RIGHT;
			break;
		default:
			break;
		}
	}

}

/**
 * Function that moves snake based on the direction variable
 */
void moveSnake() {
	switch (dir) { 
	case UP:
		snake.setY(snake.getY() - 1);
		break;
	case DOWN:
		snake.setY(snake.getY() + 1);
		break;
	case LEFT:
		snake.setX(snake.getX() - 1);
		break;
	case RIGHT:
		snake.setX(snake.getX() + 1);
		break;
	default:
		break;
	}

}

/**
 * Function that moves the tail of the snake
 */
void moveTail() {
	int frontX = snake.getX(); //coordinates of the segment infront of current segment
	int frontY = snake.getY();

	int tempX, tempY;

	for (int i = 0; i < snake.getTail(); i++) { //loop through tail
		tempX = snake.getTailX(i); //get coordinates of current segment
		tempY = snake.getTailY(i);

		snake.setTailX(i, frontX); //set current segment to segment infront of it
		snake.setTailY(i, frontY);

		frontX = tempX; //current segment becomes front segment
		frontY = tempY;
	}
}

/**
 * Function that checks if the snake hits a wall or their tail that causes a game over
 */
void checkDeath() {
	if (field[snake.getY()][snake.getX()] != " " && field[snake.getY()][snake.getX()] != "o") { //if not an empty space and a food
		gameOver = true;
	}
	if (field[snake.getY()][snake.getX()] == "@") { //prevents user to lose at begining when snake hasn't started to move yet
		gameOver = false;
	}
}

/**
 * This function checks if a food is eaten
 */
void checkFood() {
	if (field[snake.getY()][snake.getX()] == "o") { //if the head is on same coordinates as the food

		snake.setTailSize(snake.getTail() + 1); //increase tail by 1

		do { //new random food
			food.randomFood();
		} while (!emptySpace(food.getPosX(), food.getPosY()));

		score += 10;
	}
}

/**
 * This function checks specific x and y values in the field to see if that spot is empty
 *
 * @param x Width index in field array
 * @param y Hieght index in field array
 */
bool emptySpace(int x, int y) {
	std::string pos = field[y][x];

	if (pos == " ") {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	system("cls");
	setupGame();

	while (!gameOver) { //run game until gameover
		updateField();
		drawField();
		input();
		moveTail();
		moveSnake();
		checkDeath();
		checkFood();
		std::cout << "Score: " << score << "\n";
		//Sleep(10);
	}
	system("pause");
	return 0;
}