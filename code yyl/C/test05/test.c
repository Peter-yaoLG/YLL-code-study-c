#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    static int result[2];

    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }

    *returnSize = 0;
    return NULL;
}

int main()
{
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
    int* result = twoSum(nums, 4, target, &returnSize);

    if (result != NULL)
    {
        printf("[%d, %d]\n", result[0], result[1]);
    }

    return 0;
}
