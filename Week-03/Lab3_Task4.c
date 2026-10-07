// Question:
// Write a C program using fork() where the child process takes a string
// as input and generates all possible permutations of the string.
// The parent process waits for the child process to complete.
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void permutation(char str[], int start, int end)
{
    char temp;

    if (start == end)
    {
        printf("%s\n", str);
        return;
    }

    for (int i = start; i <= end; i++)
    {
        // Swap
        temp = str[start];
        str[start] = str[i];
        str[i] = temp;
        permutation(str, start + 1, end);
      temp = str[start];
        str[start] = str[i];
        str[i] = temp;
    }
}

int main()
{
    char str[100];
    int n = 0;

    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
        return 1;
    }

    else if (pid == 0)
    {
      
        printf("Child Process\n");

        printf("Enter a string: ");
        scanf("%s", str);

  
        while (str[n] != '\0')
        {
            n++;
        }

        printf("\nAll Permutations:\n");

        permutation(str, 0, n - 1);
    }

    else
    {

        wait(NULL);

        printf("\nParent Process\n");
        printf("Child process completed.\n");
    }

    return 0;
}
