#include <iostream>

int LIS(int arr[], int n, int dp[], int index)
{
    if (dp[index] != 0)
        return dp[index];
    int max = 1;
    for (int i = index + 1; i < n; i++)
    {
        int temp;
        temp = LIS(arr, n, dp, i) + 1;
        if (arr[index] < arr[i] && max < temp)
            max = temp;
    }
    dp[index] = max;
    return max;
}

int main()
{
    int arr[8] = {6, 2, 4, 9, 1, 5, 3, 7};
    int dp[8] = {0, 0, 0, 0, 0, 0, 0, 1};

    LIS(arr, 8, dp, 0);

    int max = 0;
    for (int i = 0; i < 8; i++)
    {
        if (max < dp[i])
            max = dp[i];
    }
    std::cout << max << std::endl;
    return 0;
}