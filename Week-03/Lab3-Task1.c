#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int n, sum = 0;
    int arr[10];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
    }
    else if (pid == 0)
    {
        printf("Current process is Child Process\n");

        for (int i = 0; i < n; i++)
        {
            sum = sum + arr[i];
        }

        printf("Sum = %d\n", sum);
    }
    else
    {
        wait(NULL);

        printf("Current process is Parent Process\n");

        int prime = 1;

        if (sum < 2)
        {
            prime = 0;
        }
        else
        {
            for (int i = 2; i * i <= sum; i++)
            {
                if (sum % i == 0)
                {
                    prime = 0;
                    break;
                }
            }
        }

        if (prime == 1)
        {
            printf("The sum of the given array is prime\n");
        }
        else
        {
            printf("The sum of the given array is not prime\n");
        }
    }

    return 0;
}