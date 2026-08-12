#include "game.h"
#include <stdio.h>
void menu()
{
    printf("----------------------------------\n");
    printf("----------  1 . play   -----------\n");
    printf("----------  0 . exit   -----------\n");
    printf("----------------------------------\n");
}
void game()
{
    char mine[Rows][Cols]; // 地雷信息
    char show[Rows][Cols]; // 存放排查的信息
    // 初始化棋盘
    Initboard(mine, Rows, Cols, '0');
    Initboard(show, Rows, Cols, '*');
    displayboard(show, Row, Col); // 打印show棋盘
    Setmine(mine, Row, Col);//设置雷
    // displayboard(mine, Row, Col);
    //  开始
    Findmine(mine, show, Row, Col);
}
int main()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("请选择");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            game();

            break;
        case 0:
            printf("退出游戏\n");
            break;
        default:
            printf("选择错误,重新选择");

            break;
        }

    } while (input);
    return 0;
}