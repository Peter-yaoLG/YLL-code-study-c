#include <stdio.h>

float Add(float x, float y)
{
    float z = x + y;
    return z;
}

float subtraction(float x, float y)
{
    float z = x - y;
    return z;
}

float multiplication(float x, float y)
{
    float z = x * y;
    return z;
}

float Division(float x, float y)
{
    float z = x / y;
    return z;
}

int main()
{
    int part = 0;
    float x = 0;
    float y = 0;
    printf("��ѡ�����㣺\n");
    printf("1.�ӷ� 2.���� 3.�˷� 4.������");
    scanf("%d", &part);
    printf("�������������֣�");
    scanf("%f %f", &x, &y);

    if (part == 1)
    {
        float sum = Add(x, y);
        printf("%f ", sum);
    }
    if (part == 2)
    {
        float sum = subtraction(x, y);
        printf("%f ", sum);
    }
    if (part == 3)
    {
        float sum = multiplication(x, y);
        printf("%f ", sum);
    }
    if (part == 4)
    {
        float sum = Division(x, y);
        printf("%f ", sum);
    }

    return 0;
}
