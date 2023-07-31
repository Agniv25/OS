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
            if (m[j] == ref[i])
            {
                break;
            }
        }
        // if page fault occurs;
        if (j == frame_size)
        {
            // check if -1 is present or not
            int k;
            int minuspresent = 0;
            for (k = 0; k < frame_size; k++)
            {
                if (m[k] == -1)
                {
                    minuspresent = 1;
                    break;
                }
            }
            // if not present
            if (minuspresent == 0)
            {
                // check for each frame
                int index;
                int max = -1;
                for (k = 0; k < frame_size; k++)
                {
                    int element = m[k];

                    int l = i;

                    while (l < n)
                    {
                        if (ref[l] == element)
                        {
                            if (max < l)
                            {
                                max = l;
                                index = k;
                            }
                            break;
                        }
                        l++;
                    }
                    if (l == n)
                    {
                        index = k;
                        break;
                    }
                }
                m[index] = ref[i];
            }
            else
            {
                m[k] = ref[i];
            }
        }
        // print it
        for (int a = 0; a < frame_size; a++)
        {
            printf("%d ", m[a]);
        }
        // if fault is there
        if (j == frame_size)
        {
            printf("pf is %d ", ++pf);
        }
        printf("\n");
    }
}