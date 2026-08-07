/*
Lab 2 - Task 2

Problem Statement:
Write a C program using the fork() system call to create a child process.
The child process should determine whether a user-entered number is even
or odd. The parent process should wait for the child process to complete
and then calculate and display the factorial of the same number. Also
display the Process ID (PID) of both the parent and child processes.
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
    }
    else if (pid == 0)
    {
        printf("Current process is Child Process\n");
        printf("Child PID: %d\n", getpid());

        if (n % 2 == 0)
            printf("The given number is Even\n");
        else
            printf("The given number is Odd\n");
    }
    else
    {
        wait(NULL);
        printf("Current process is Parent Process\n");
        printf("Parent PID: %d\n", getpid());
        int fact = 1;

        for (int i = 1; i <= n; i++)
        {
            fact *= i;
        }
        printf("Factorial of %d is %d\n", n, fact);
    }
    return 0;
}