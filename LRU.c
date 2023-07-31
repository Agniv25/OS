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
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < frame_size; j++)
        {
            if (ref[i] == m[j])
            {
                break;
            }
        }
        // if page fault occurs
        if (j == frame_size)
        {
            int minusspresent = 0;
            int k;
            for (k = 0; k < frame_size; k++)
            {
                if (m[k] == -1)
                {
                    minusspresent = 1;
                    break;
                }
            }
            if (minusspresent == 0)
            {
                int min = 1000;
                int index;
                for (int k = 0; k < frame_size; k++)
                {
                    int element = m[k];
                    int l = i - 1;

                    while (l >= 0)
                    {
                        if (ref[l] == element)
                        {
                            if (min > l)
                            {
                                min = l;
                                index = k;
                            }
                            break;
                        }
                        l--;
                    }
                }
                m[index] = ref[i];
                // printf("min is %d ", min);
            }
            else
            {
                m[k] = ref[i];
            }
        }
        for (int a = 0; a < frame_size; a++)
        {
            printf("%d ", m[a]);
        }
        if (j == frame_size)
        {
            pf++;
            printf("pf is %d ", pf);
        }
        printf("\n");
    }
    return 0;
}