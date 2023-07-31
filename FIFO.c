#include <stdio.h>
int main()
{
    int ref[30];
    int n;
    int frame_size;
    int pf = 0;
    printf("Enter the size of the reference string\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ref[i]);
    }
    printf("Enter the frame size\n");
    scanf("%d", &frame_size);
    int m[frame_size];
    for (int i = 0; i < frame_size; i++)
    {
        m[i] = -1;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {

        int j;
        for (j = 0; j < frame_size; j++)
        {
            if (m[j] == ref[i])
            {
                break;
            }
        }
        if (j == frame_size)
        {
            m[count++] = ref[i];
            pf++;
        }
        for (int k = 0; k < frame_size; k++)
        {
            printf("%d ", m[k]);
        }
        if (j == frame_size)
        {
            printf("pf is %d ", pf);
        }
        if (count == frame_size)
        {
            count = 0;
        }
        printf("\n");
    }
    return 0;
}