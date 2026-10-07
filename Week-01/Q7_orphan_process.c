#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
        return 1;
    }

    else if (pid == 0)
    {
        printf("Child before sleep:\n");
        printf("PID  = %d\n", getpid());
        printf("PPID = %d\n", getppid());

        sleep(10);

      
        printf("\nChild after parent exits:\n");
        printf("PID  = %d\n", getpid());
        printf("PPID = %d\n", getppid());
    }

    else
    {
        printf("Parent process exiting...\n");
        return 0;
    }

    return 0;
}
