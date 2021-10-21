/*
 * Header file that contains the function declarations
 */
#pragma once
void ShowConsoleCursor(bool showFlag);
void setupGame();
void updateField();
void drawField();
void input();
void moveSnake();
void moveTail();
void checkDeath();
void checkFood();
bool emptySpace(int x, int y);