#include <stdio.h>
int main()
{
    int m = 3, n = 5;
    int alloc[5][3] = {{0, 1, 0},  // P0 // Allocation Matrix
                       {2, 0, 0},  // P1
                       {3, 0, 2},  // P2
                       {2, 1, 1},  // P3
                       {0, 0, 2}}; // P4
    int max[5][3] = {{7, 5, 3},    // P0 // MAX Matrix
                     {3, 2, 2},    // P1
                     {9, 0, 2},    // P2
                     {2, 2, 2},    // P3
                     {4, 3, 3}};   // P4
    int avail[3] = {3, 3, 2};      // Available Resources
    int need[5][3];
    int ans[n];
    int index = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    int f[n];
    for (int i = 0; i < n; i++)
    {
        f[i] = 0;
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {
                int flag = 0;
                for (int j = 0; j < m; j++)
                {
                    if (avail[j] < need[i][j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    for (int j = 0; j < m; j++)
                    {

                        avail[j] += alloc[i][j];
                        f[i] = 1;
                    }
                    ans[index++] = i + 1;
                }
            }
        }
    }
    printf("Following is the safe sequence\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", ans[i]);
    }
}