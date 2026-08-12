#include <stdio.h>

int main(void)
{
    int n = 0;
    if (scanf("%d", &n) != 1)
    {
        return 1;
    }

    int cnt[100001] = {0};
    for (int i = 1; i <= n; i++)
    {
        int color = 0;
        scanf("%d", &color);
        cnt[color]++;
    }

    int pairs = 0;
    for (int i = 1; i <= 100000; i++)
    {
        pairs += cnt[i] / 2;
    }

    printf("%d", n / 2 - pairs);
    return 0;
}
