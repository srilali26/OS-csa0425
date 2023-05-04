#include<stdio.h>

int main() {
    int n = 6;  
    int memory[] = {300, 600, 350, 200, 750, 125}; 
    int m = 5;  
    int process[] = {115, 500, 358, 200, 375};  
    
    int allocation[m];
    
    for(int i=0; i<m; i++) {
        allocation[i] = -1;
        
        for(int j=0; j<n; j++) {
            if(memory[j] >= process[i]) {
                allocation[i] = j; 
                memory[j] -= process[i];  
                break;
            }
        }
    }
    
    printf("Process\tProcess Size\tAllocated Memory Partition\n");
    
    for(int i=0; i<m; i++) {
        printf("P%d\t%d\t\t", i+1, process[i]);
        
        if(allocation[i] != -1) {
            printf("%d\n", allocation[i]+1);  
        } else {
            printf("Not Allocated\n");
        }
    }
    
    return 0;
}

