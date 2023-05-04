#include<stdio.h>

int main() {
    int n = 4;  
    int arrival[] = {0, 1, 2, 4}; 
    int burst[] = {5, 3, 3, 1}; 
    
    int remaining[n];
    int waiting[n];
    int turnaround[n];
    int total_waiting = 0;
    int total_turnaround = 0;
    int complete = 0;
    int t = 0;
    int shortest = 0;
    int finish_time;
    float average_waiting;
    float average_turnaround;
    
    for(int i=0; i<n; i++) {
        remaining[i] = burst[i];
    }
    
    while(complete != n) {
        shortest = 0;
        
       
        for(int i=1; i<n; i++) {
            if(remaining[i] < remaining[shortest] && arrival[i] <= t) {
                shortest = i;
            }
        }
        
       
        remaining[shortest]--;
        
       
        if(remaining[shortest] == 0) {
            complete++;
            finish_time = t + 1;
            
           
            waiting[shortest] = finish_time - arrival[shortest] - burst[shortest];
            if(waiting[shortest] < 0) {
                waiting[shortest] = 0;
            }
            turnaround[shortest] = finish_time - arrival[shortest];
            total_waiting += waiting[shortest];
            total_turnaround += turnaround[shortest];
        }
   
        t++;
    }
  
    average_waiting = (float) total_waiting / n;
    average_turnaround = (float) total_turnaround / n;
    
    printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    
    for(int i=0; i<n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, arrival[i], burst[i], waiting[i], turnaround[i]);
    }
    
    printf("Average Waiting Time = %0.2f milliseconds\n", average_waiting);
    printf("Average Turnaround Time = %0.2f milliseconds\n", average_turnaround);
    
    return 0;
}
