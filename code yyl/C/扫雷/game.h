// 游戏函数的声明
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Row 9
#define Col 9

#define Rows Row + 2
#define Cols Col + 2
#define Easy 10

void displayboard(char board[Rows][Cols], int r, int c);
void Initboard(char board[Rows][Cols], int r, int c, char set);
void Setmine(char board[Rows][Cols], int r, int c);
void Findmine(char mine[Rows][Cols], char show[Rows][Cols], int r, int c);
int Expand(char mine[Rows][Cols], char show[Rows][Cols], int x, int y);