#include <stdio.h>

int Add(int x, int y)
{
    int Z = 0;
    Z = x + y;
    return Z;
}

int main()
{
    int x = 0;
    int y = 0;
    scanf("%d %d", &x, &y);
    int sum = Add(x, y);
    printf("%d\n", sum);

    return 0;
}
