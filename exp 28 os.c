#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main() {
    char fileName[100];
    printf("Enter file name: ");
    scanf("%s", fileName);

    int fd = open(fileName, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        printf("Failed to create file.");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    printf("Enter data to write to file (max %d characters):\n", BUFFER_SIZE);
    scanf(" %[^\n]s", buffer);
    write(fd, buffer, sizeof(buffer));

    close(fd);

    fd = open(fileName, O_RDONLY);
    if (fd == -1) {
        printf("Failed to open file for reading.");
        exit(1);
    }

    printf("Data read from file:\n");
    int bytesRead = read(fd, buffer, sizeof(buffer));
    while (bytesRead > 0) {
        write(STDOUT_FILENO, buffer, bytesRead);
        bytesRead = read(fd, buffer, sizeof(buffer));
    }

    close(fd);

    return 0;
}

