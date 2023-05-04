#include <stdio.h>

int main() {
    int n = 3; 
    int burst_time[] = {2, 4, 8}
    int waiting_time[n], turnaround_time[n], completion_time[n];
    float total_waiting_time = 0, total_turnaround_time = 0;

    completion_time[0] = burst_time[0];
    for (int i = 1; i < n; i++) {
        completion_time[i] = completion_time[i - 1] + burst_time[i];
    }
    for (int i = 0; i < n; i++) {
        waiting_time[i] = completion_time[i] - burst_time[i];
        turnaround_time[i] = completion_time[i];
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }
    float avg_waiting_time = total_waiting_time / n;
    float avg_turnaround_time = total_turnaround_time / n;

    printf("Process\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", i, burst_time[i], completion_time[i], waiting_time[i], turnaround_time[i]);
    }
    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}
