#include <stdio.h>
void main()
{
    int arrival_time[10], burst_time[10], temp[10];
    int total_waiting_time = 0, total_turnaround_time = 0;
    int q_time;
    int n;
    float avg_waiting_time, avg_turnaround_time;
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

    int visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    printf("\nProcess\tArrival_time\tburst_time\tturnaround_time\twaiting_time\n");
    for (int i = 0; i < n; i++)
    {
        int k = -1;
        int min_bt = 10000;
        int arrival = 0;

        for (int j = 0; j < n; j++)
        {
            if (min_bt > burst_time[j] && visited[j] == 0)
            {
                min_bt = burst_time[j];

                arrival = arrival_time[j];
                k = j;
            }
            else if (min_bt == burst_time[j] && arrival_time[j] < arrival)
            {
                k = j;
                arrival = arrival_time[j];
            }
        }
        if (k == -1)
        {
            break;
        }
        else
        {
            visited[k] = 1;
            if (total < arrival_time[k])
            {
                total += (arrival_time[k] - total) + burst_time[k];
            }
            else
            {
                total += burst_time[k];
            }
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\n", k, arrival_time[k], burst_time[k], total - arrival_time[k], total - arrival_time[k] - burst_time[k]);
            total_turnaround_time = total_turnaround_time + (total - arrival_time[k]);
            total_waiting_time += (total - arrival_time[k] - burst_time[k]);
        }
    }
    avg_turnaround_time = (total_turnaround_time * 1.0) / n;
    avg_waiting_time = (total_waiting_time * 1.0) / n;
    printf("average turnaround time is %f", avg_turnaround_time);
    printf("average waiting time is %f", avg_waiting_time);
}