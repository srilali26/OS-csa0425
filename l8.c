#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, head, i;
    float avg_movement = 0;
    
    printf("Enter the number of tracks: ");
    scanf("%d", &n);
    
    int tracks[n];
    
    printf("Enter the track positions: ");
    for(i=0; i<n; i++)
        scanf("%d", &tracks[i]);
        
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    
    printf("Head Movement: %d", abs(tracks[0] - head));
    
    for(i=1; i<n; i++)
    {
        avg_movement += abs(tracks[i] - tracks[i-1]);
        printf(" -> %d", tracks[i]);
    }
    
    printf("\nAverage Head Movement: %.2f", avg_movement/n);
    
    return 0;
}
