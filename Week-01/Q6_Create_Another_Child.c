// Question 6
// Write a program in which the child process creates another child process.
// The second child prints the Fibonacci series up to n.
// The first child calculates the factorial of n.
// The parent process prints numbers up to n.

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);
    pid_t pid = fork();
    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }
    else if (pid == 0) {

        pid_t pid2 = fork();

        if (pid2 < 0) {
            printf("Second fork failed\n");
            return 1;
        }
        else if (pid2 == 0) {
            printf("\nGrandchild Process\n");
            printf("Fibonacci Series:\n");

            int a = 0, b = 1, c;

            for (int i = 0; i < n; i++) {
                printf("%d ", a);
                c = a + b;
                a = b;
                b = c;
            }

            printf("\n");
        }

        else {

            wait(NULL);
            printf("\nChild Process\n");
            int fact = 1;
            for (int i = 1; i <= n; i++) {
                fact *= i;
            }
            printf("Factorial of %d is %d\n", n, fact);
        }
    }
    else {

        wait(NULL);   
        printf("\nParent Process\n");
        printf("Numbers up to %d:\n", n);

        for (int i = 1; i <= n; i++) {
            printf("%d ", i);
        }
        printf("\n");
    }

    return 0;
}