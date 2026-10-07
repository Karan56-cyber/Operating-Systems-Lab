/*
Lab 4 - Task 1

Problem Statement:
Write a C program using the fork() system call and pipe for inter-process
communication. The child process should accept a string from the user and
send the entered data to the parent process through a pipe. The parent
process should receive the data from the pipe and display the received
message. Use wait() to ensure proper synchronization between the parent and
child processes.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    int fd[2];        
    pid_t pid;
    char parent_data[100];

    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }

    
    pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {

        char child_data[100];

        close(fd[0]);  

        printf("Child: Enter something: ");
        fgets(child_data, sizeof(child_data), stdin);

        
        write(fd[1], child_data, strlen(child_data) + 1);

        close(fd[1]);
    }
    else {
     

        close(fd[1]);  
        
        
        read(fd[0], parent_data, sizeof(parent_data));

        close(fd[0]);

        wait(NULL);

        printf("Parent: Data received = %s", parent_data);
    }

    return 0;
}
