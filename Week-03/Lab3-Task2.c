


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int n = 0;
    char str[100];

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
    }
    else
    {
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
                        printf("%c%c%c\n",
                               str[i], str[j], str[k]);
                    }
                }
            }
        }
    }

    return 0;
}