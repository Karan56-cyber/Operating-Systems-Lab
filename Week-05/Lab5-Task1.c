/*
Lab 5 - Task 1

Problem Statement:
Write a C program using the fork() system call and pipe for inter-process
communication. The parent process should calculate the sum of all elements
of a given integer array and send the calculated sum to the child process
through a pipe. The child process should receive the sum from the pipe and
check whether the received sum is a prime number or not. Display the sum
calculated by the parent and the prime/non-prime result checked by the child
process. Use wait() to ensure proper synchronization between the parent and
child processes.
*/



#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int isPrime(int n) {
    if (n <= 1)
        return 0;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }

    return 1;  
}

int main() {
    int arr[] = {2, 4, 6, 8, 5};
    int n = 5;

    int pipefd[2];
    pipe(pipefd);

    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }

    if (pid > 0) {
        close(pipefd[0]);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }
        printf("Parent: Sum = %d\n", sum);

        write(pipefd[1], &sum, sizeof(sum));

        close(pipefd[1]);

        wait(NULL);
    }
    else {
        close(pipefd[1]);

        int sum;

        read(pipefd[0], &sum, sizeof(sum));

        if (isPrime(sum))
            printf("Child: %d is Prime\n", sum);
        else
            printf("Child: %d is Not Prime\n", sum);

        close(pipefd[0]);
    }

    return 0;
}
