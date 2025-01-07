#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define DISK_SIZE (1024 * 1024 * 5) // 5MB virtual disk

char disk_image[256] = "";

void format_disk(const char *disk_name) {
    strcpy(disk_image, disk_name);
    int fd = open(disk_image, O_CREAT | O_WRONLY, 0666);
    if (fd < 0) {
        perror("Error creating disk");
        exit(1);
    }
    char buffer[DISK_SIZE] = {0};
    if (write(fd, buffer, DISK_SIZE) != DISK_SIZE) {
        perror("Error formatting disk");
        close(fd);
        exit(1);
    }
    close(fd);
    printf("Disk '%s' formatted.\n", disk_image);
}

void copy_to_disk(const char *src, const char *dest) {
    if (strlen(disk_image) == 0) {
        fprintf(stderr, "Error: No disk formatted.\n");
        return;
    }
    int src_fd = open(src, O_RDONLY);
    if (src_fd < 0) {
        perror("Error opening source file");
        return;
    }
    int disk_fd = open(disk_image, O_WRONLY);
    if (disk_fd < 0) {
        perror("Error opening disk image");
        close(src_fd);
        return;
    }
    lseek(disk_fd, 0, SEEK_END);
    char buffer[1024];
    ssize_t bytes;
    while ((bytes = read(src_fd, buffer, sizeof(buffer))) > 0) {
        if (write(disk_fd, buffer, bytes) != bytes) {
            perror("Error writing to disk");
            close(src_fd);
            close(disk_fd);
            return;
        }
    }
    if (bytes < 0) perror("Error reading source file");
    close(src_fd);
    close(disk_fd);
    printf("Copied '%s' to '%s' on disk '%s'.\n", src, dest, disk_image);
}

void remove_from_disk(const char *path) {
    printf("Simulated removal of '%s' from disk '%s'.\n", path, disk_image);
    // Actual removal logic for a virtual disk would go here
}

void create_directory(const char *dir_path) {
    printf("Simulated creation of directory '%s' on disk '%s'.\n", dir_path, disk_image);
    // Actual directory creation logic for a virtual disk would go here
}

void execute_command(const char *command) {
    char cmd[256], arg1[256], arg2[256];
    int args = sscanf(command, "%255s %255s %255s", cmd, arg1, arg2);

    if (strcmp(cmd, "format") == 0 && args == 2) {
        format_disk(arg1);
    } else if (strcmp(cmd, "copy") == 0 && args == 3) {
        copy_to_disk(arg1, arg2);
    } else if (strcmp(cmd, "remove") == 0 && args == 2) {
        remove_from_disk(arg1);
    } else if (strcmp(cmd, "mkdir") == 0 && args == 2) {
        create_directory(arg1);
    } else if (strcmp(cmd, "exit") == 0) {
        printf("Exiting UnixV5Fish Shell.\n");
        exit(0);
    } else {
        fprintf(stderr, "Unknown command: %s\n", cmd);
    }
}

int main() {
    printf("UnixV5Fish Shell. Type 'exit' to quit.\n");
    char command[512];
    while (1) {
        printf("unixv5fish> ");
        if (fgets(command, sizeof(command), stdin) == NULL) {
            break;
        }
        command[strcspn(command, "\n")] = 0; // Remove newline character
        if (strlen(command) > 0) {
            execute_command(command);
        }
    }
    return 0;
}