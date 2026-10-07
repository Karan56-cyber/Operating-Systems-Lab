// Question:
// Write a C program using fork() where the child process calculates
// the sum of all odd numbers from 1 to n, while the parent process
// calculates the sum of all even numbers from 1 to n.

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int n;

    printf("Enter value of n: ");
    scanf("%d", &n);

    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
        return 1;
    }

    else if (pid == 0)
    {

        int oddSum = 0;

        for (int i = 1; i <= n; i++)
        {
            if (i % 2 != 0)
            {
                oddSum += i;
            }
        }

        printf("Child Process\n");
        printf("Sum of odd numbers = %d\n", oddSum);
    }

    else
    {
    
        int evenSum = 0;

        for (int i = 1; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                evenSum += i;
            }
        }

     
        wait(NULL);

        printf("Parent Process\n");
        printf("Sum of even numbers = %d\n", evenSum);
    }

    return 0;
}
