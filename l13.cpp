#include <stdio.h>
#include <string.h>

#define MAX_FILES 100

struct File {
    char name[50];
};

struct Directory {
    char name[50];
    struct File files[MAX_FILES];
    int num_files;
};

int main() {
    struct Directory cse_directory;
    strcpy(cse_directory.name, "CSE");
    cse_directory.num_files = 0;

 
    struct File file_a, file_b, file_c;
    strcpy(file_a.name, "A");
    strcpy(file_b.name, "B");
    strcpy(file_c.name, "C");

    cse_directory.files[cse_directory.num_files++] = file_a;
    cse_directory.files[cse_directory.num_files++] = file_b;
    cse_directory.files[cse_directory.num_files++] = file_c;

    
    printf("Contents of directory %s:\n", cse_directory.name);
    for (int i = 0; i < cse_directory.num_files; i++) {
        printf("%s\n", cse_directory.files[i].name);
    }

    return 0;
}

