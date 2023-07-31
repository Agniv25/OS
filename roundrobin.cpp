#include <stdio.h>
int main()
{
    int arrival_time[10], burst_time[10], temp[10];
    int total_waiting_time = 0, total_turnaround_time = 0;
    float avg_waiting_time, avg_turnaround_time;
    int q_time;
    int n;
    printf("Enter the number of process\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("enter details of process %d \n", i);
        printf("enter arrival time\n");
        scanf("%d", &arrival_time[i]);
        printf("enter burst time\n");
        scanf("%d", &burst_time[i]);
        temp[i] = burst_time[i];
    }
    printf("Enter quantum time \n");
    scanf("%d", &q_time);
    int x = 0;
    int i = 0;
    int total = 0;
    int counter = 0;
    printf("\nProces\tarrival_time\tburst_time\tTurnaround\tWaiting\n ");
    while (x < n)
    {
        if (temp[i] <= q_time && temp[i] > 0)
        {
            total += temp[i];
            temp[i] = 0;
            counter = 1;
        }
        else if (temp[i] > 0)
        {
            total += q_time;
            temp[i] -= q_time;
        }
        // this is one part

        if (counter == 1 and temp[i] == 0)
        {
            printf("%d\t%d\t%d\t%d\t%d \n", i, arrival_time[i], burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
            total_turnaround_time += total - arrival_time[i];
            total_waiting_time += total - arrival_time[i] - burst_time[i];
            x++;
            counter = 0;
        }
        // this is another part
        if (i == n - 1)
        {
            i = 0;
        }
        else if (arrival_time[i + 1] <= total)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }
    avg_turnaround_time = total_turnaround_time * 1.0 / n;
    avg_waiting_time = total_waiting_time * 1.0 / n;
    printf("The avg turnaround time is %f", avg_turnaround_time);
    return 0;
}