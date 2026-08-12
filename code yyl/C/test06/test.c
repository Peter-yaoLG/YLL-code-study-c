#include <stdio.h>

int main()
{
    int year = 0;
    printf("������һ����ݣ�\n");
    scanf("%d", &year);
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
    {
        printf("������\n");
    }
    else
    {
        printf("��������\n");
    }

    return 0;
}
