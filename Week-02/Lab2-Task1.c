/*
Lab 2 - Task 1

Problem Statement:
Write a C program using the fork() system call to create a child process.
The child process should generate and display the Fibonacci series up to a
given number entered by the user. The parent process should wait for the
child process to complete and then display all Armstrong numbers up to the
same given number. Also display the Process ID (PID) of both the parent
and child processes.
*/


#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void fibonacci(int n)
{
    int a = 0;
    int b = 1;
    int c;
    printf("Fibonacci series upto %d:\n", n);
    for (int i = 0; i < n; i++)
    {
        if (a > n)
        {
            return;
        }
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
}

void armstrong(int n)
{
    int rem;
    int arm = 0;
    printf("The Armstrong numbers upto %d are:\n", n);
    for (int i = 1; i <= n; i++)
    {
        int temp = i;
        arm = 0;

        while (temp)
        {
            rem = temp % 10;
            temp = temp / 10;
            arm += rem * rem * rem;
        }
        if (i == arm)
        {
            printf("%d\n", arm);
        }
    }
}

int main()
{
    int n;
    printf("Enter the number n: ");
    scanf("%d", &n);
    pid_t pid = fork();
    if (pid < 0)
    {
        printf("Fork failed\n");
        return 0;
    }
    else if (pid == 0)
    {
        printf("\nCurrent process is the Child Process\n");
        printf("Child PID: %d\n", getpid());

        fibonacci(n);
    }
    else
    {
        wait(NULL);

        printf("\nCurrent process is the Parent Process\n");
        printf("Parent PID: %d\n", getpid());

        armstrong(n);
    }

    return 0;
}