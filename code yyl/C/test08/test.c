
#include <stdio.h>

int main(void)
{
    int year = 0;
    int thisyear = 2026;
    printf("请输入你的出生年份:\n");
    if (scanf("%d", &year) != 1)
    {
        printf("输入无效\n");
        return 1;
    }

    int diff = (thisyear - year) % 12;
    if (diff < 0)
    {
        diff = diff + 12;
    }
    int result = 7 - (int)diff;
    if (result <= 0)
    {
        result = result + 12;
    }

    switch (result)
    {
    case 1:
        printf("鼠\n");
        break;
    case 2:
        printf("牛\n");
        break;
    case 3:
        printf("虎\n");
        break;
    case 4:
        printf("兔\n");
        break;
    case 5:
        printf("龙\n");
        break;
    case 6:
        printf("蛇\n");
        break;
    case 7:
        printf("马\n");
        break;
    case 8:
        printf("羊\n");
        break;
    case 9:
        printf("猴\n");
        break;
    case 10:
        printf("鸡\n");
        break;
    case 11:
        printf("狗\n");
        break;
    case 12:
        printf("猪\n");
        break;
    }

    return 0;
}
