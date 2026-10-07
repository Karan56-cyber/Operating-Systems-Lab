// Question:
// Write a C program using fork() and pipe() where the child process
// calculates the sum of elements of an array and sends the sum to
// the parent process through a pipe. The parent process checks whether
// the received sum is prime or not.

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int isPrime(int n)
{
    if (n < 2)
        return 0;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int main()
{
    int arr[] = {2, 4, 6, 3, 5};
    int n = 5;

    int pipefd[2];
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

        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }

        printf("Child: Sum = %d\n", sum);

        write(pipefd[1], &sum, sizeof(sum));

        close(pipefd[1]);
    }

    else
    {
      
        close(pipefd[1]); 

        int sum;
        read(pipefd[0], &sum, sizeof(sum));

        close(pipefd[0]);
        wait(NULL);

        printf("Parent: Received Sum = %d\n", sum);
        if (isPrime(sum))
            printf("%d is Prime\n", sum);
        else
            printf("%d is Not Prime\n", sum);
    }

    return 0;
}
