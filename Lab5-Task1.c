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