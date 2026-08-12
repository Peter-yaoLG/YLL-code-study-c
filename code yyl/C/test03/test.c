#include <stdio.h>

int main()
{
    int arr[10] = {12, 13, 14, 15, 16, 17, 18, 19, 20};
    int i = 0;

    while (i < 10)
    {
        printf("%d ", arr[i]);
        i = i + 1;
    }

    return 0;
}
