#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

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
        printf("Child process exiting...\n");
        return 0;
    }

    else
    {
        sleep(10);

        printf("Parent is now calling wait()...\n");

        wait(NULL);

        printf("Zombie process removed.\n");
    }

    return 0;
}
