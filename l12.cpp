#include <stdio.h>

#define NUM_PARTITIONS 6

int main() {
    int partitions[] = {300, 600, 350, 200, 750, 125};
    int num_processes = 5;
    int processes[] = {115, 500, 358, 200, 375};
    int i, j, best_fit_partition;

    for (i = 0; i < num_processes; i++) {
        best_fit_partition = -1;
        for (j = 0; j < NUM_PARTITIONS; j++) {
            if (partitions[j] >= processes[i]) {
                if (best_fit_partition == -1 || partitions[j] < partitions[best_fit_partition]) {
                    best_fit_partition = j;
                }
            }
        }

        if (best_fit_partition != -1) {
            printf("Process of size %d KB allocated to partition of size %d KB.\n", processes[i], partitions[best_fit_partition]);
            partitions[best_fit_partition] -= processes[i];
        } else {
            printf("Process of size %d KB could not be allocated.\n", processes[i]);
        }
    }

    return 0;
}

