#include <stdio.h>

int main(void)
{
    int n = 0;
    if (scanf("%d", &n) != 1)
    {
        return 1;
    }

    int m = 0;
    for (int i = 0; i < n; i++)
    {
        int a = 0;
        if (scanf("%d", &a) != 1)
        {
            return 1;
        }
        if (a == 2)
        {
            m++;
        }
    }

    printf("%d\n", (n + m) / 2);
    return 0;
}
