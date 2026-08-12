// 游戏函数的实现
#include "game.h"
#include <stdio.h>

void Initboard(char board[Rows][Cols], int r, int c, char set) // 初始化棋盘
{
    int i = 0;
    int j = 0;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            board[i][j] = set;
        }
    }
}
void displayboard(char board[Rows][Cols], int r, int c) // 打印棋盘
{
    int i = 0;
    int j = 0;
    for (j = 0; j <= r; j++)
    {
        printf("%d  ", j);
    }
    printf("\n");
    for (i = 1; i <= r; i++)
    {
        printf("%d  ", i);
        for (j = 1; j <= c; j++)
        {
            printf("%c  ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void Setmine(char board[Rows][Cols], int r, int c)
{
    int count = Easy;
    while (count)
    {
        int x = rand() % r + 1;
        int y = rand() % c + 1;
        if (board[x][y] == '0')
        {
            board[x][y] = '1';
            count--;
        }
    }
}
static int Getminecount(char mine[Rows][Cols], int x, int y)
{
    return mine[x - 1][y] + mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1] +
           mine[x + 1][y] + mine[x + 1][y + 1] + mine[x][y + 1] + mine[x - 1][y + 1] - 8 * '0';
}

int Expand(char mine[Rows][Cols], char show[Rows][Cols], int x, int y)
{
    int count = Getminecount(mine, x, y);
    show[x][y] = count == 0 ? ' ' : count + '0';
    int revealed = 1;
    if (count == 0)
    {
        for (int dx = -1; dx <= 1; dx++)
        {
            for (int dy = -1; dy <= 1; dy++)
            {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 1 && nx <= Row && ny >= 1 && ny <= Col && mine[nx][ny] != '1' &&
                    show[nx][ny] == '*')
                {
                    revealed += Expand(mine, show, nx, ny);
                }
            }
        }
    }
    return revealed;
}

void Findmine(char mine[Rows][Cols], char show[Rows][Cols], int r, int c)
{
    int x = 0;
    int y = 0;
    int win = 0;
    while (win < r * c - Easy)
    {

        printf("请输入要排查的坐标：");
        scanf("%d%d", &x, &y);
        if (x >= 1 && x <= r && y >= 1 && y <= c)
        {
            if (show[x][y] != '*')
            {
                printf("该坐标已被排查\n");
            }
            else
            {
                if (mine[x][y] == '1')
                {
                    printf("炸飞你\n");
                    displayboard(mine, Row, Col);
                    break;
                }
                else
                {
                    int count = Getminecount(mine, x, y);
                    if (count == 0)
                        win += Expand(mine, show, x, y);
                    else
                    {
                        show[x][y] = count + '0';
                        win++;
                    }
                    displayboard(show, Row, Col);
                }
            }
        }
        else
        {
            printf("输入错误请重新输入\n");
        }
    }
    if (win == r * c - Easy)
    {
        printf("太可恶了没有炸飞你\n");
        displayboard(show, Row, Col);
    }
}