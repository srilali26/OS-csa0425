#include<stdio.h>
#define MAX_FRAMES 3 

int main()
{
    int frames[MAX_FRAMES], page_faults = 0, current_frame = 0;
    int page_reference[] = {4, 1, 2, 4, 3, 2, 1, 5};
    int n = sizeof(page_reference) / sizeof(page_reference[0]);
    int i, j, k, flag;

    
    for(i = 0; i < MAX_FRAMES; i++)
        frames[i] = -1;

   
    for(i = 0; i < n; i++)
    {
        flag = 0;
        
        for(j = 0; j < MAX_FRAMES; j++)
        {
            if(frames[j] == page_reference[i])
            {
                flag = 1;
                break;
            }
        }

       
        if(flag == 0)
        {
            frames[current_frame] = page_reference[i];
            current_frame = (current_frame + 1) % MAX_FRAMES;
            page_faults++;
        }

        
        printf("Page reference: %d\tPage frames: ", page_reference[i]);
        for(k = 0; k < MAX_FRAMES; k++)
        {
            if(frames[k] == -1)
                printf(" - ");
            else
                printf(" %d ", frames[k]);
        }
        printf("\n");
    }

    
    printf("Total page faults: %d\n", page_faults);

    return 0;
}

