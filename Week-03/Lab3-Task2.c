#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int n = 0;
    char str[100];
    int pipefd[2];

    pipe(pipefd);

    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
    }
    else if (pid == 0)
    {
        printf("Current process is Child Process\n");
        printf("Enter a string: ");
        scanf("%s", str);

        n = strlen(str);

        close(pipefd[0]);

        write(pipefd[1], str, sizeof(str));
        write(pipefd[1], &n, sizeof(n));

        close(pipefd[1]);
    }
    else
    {
        close(pipefd[1]);

        read(pipefd[0], str, sizeof(str));
        read(pipefd[0], &n, sizeof(n));

        close(pipefd[0]);

        wait(NULL);

        printf("Current process is Parent Process\n");

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (i != j && j != k && i != k)
                    {
                        printf("%c%c%c\n", str[i], str[j], str[k]);
                    }
                }
            }
        }
    }

    return 0;
}