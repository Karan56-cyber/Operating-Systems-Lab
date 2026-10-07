// Question:
// Write a C program using pipe() and fork() where the child process
// sends a message to the parent process through a pipe,
// and the parent process reads and displays the message.

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    int pipefd[2];
    char buffer[100];
    pipe(pipefd);

    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
        return 1;
    }

    else if (pid == 0)
    {
        close(pipefd[0]);

        char message[] = "Hello from Child";
        write(pipefd[1], message, strlen(message) + 1);

        close(pipefd[1]);
    }

    else
    {
        close(pipefd[1]);
        read(pipefd[0], buffer, sizeof(buffer));

        printf("Parent received: %s\n", buffer);

        close(pipefd[0]);
        wait(NULL);
    }

    return 0;
}
