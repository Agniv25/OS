#include <stdio.h>
void main()
{
    int arrival_time[10], burst_time[10], temp[10];
    int total_waiting_time = 0, total_turnaround_time = 0;
    float avg_wait_time, avg_turnaround_time;
    int q_time;
    int n;
    int total = 0;
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
    printf("process\tarrival_time\tburst_time\tturnaround_time\twaiting_time\n");
    for (int i = 0; i < n; i++)
    {
        if (total < arrival_time[i])
        {
            total += (arrival_time[i] - total) + burst_time[i];
        }
        else
        {
            total += burst_time[i];
        }
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, arrival_time[i], burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
    }
}
