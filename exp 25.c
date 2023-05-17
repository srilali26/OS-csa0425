#include <stdio.h>

#define CONTIGUOUS 1
#define LINKED 2
#define INDEXED 3

int calculateDiskIO(int allocationStrategy, int blockSize, int totalBlocks, int blockPosition) {
    int diskIO = 0;

    switch (allocationStrategy) {
        case CONTIGUOUS:
            
            diskIO = 1;
            break;
            
        case LINKED:
            
            diskIO = 0;
            break;
            
        case INDEXED:
            
            diskIO = 1;
            break;
            
        default:
            printf("Invalid allocation strategy.\n");
            break;
    }
    
    return diskIO;
}

int main() {
    int allocationStrategy = CONTIGUOUS;
    int blockSize = 1;
    int totalBlocks = 100; 
    int blockPosition = 0; 
    
    int diskIO = calculateDiskIO(allocationStrategy, blockSize, totalBlocks, blockPosition);
    
    printf("Number of disk I/O operations required: %d\n", diskIO);
    
    return 0;
}

