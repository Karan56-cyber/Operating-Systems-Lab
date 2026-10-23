#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(void)
{
    key_t key;
    int shmid;
    char *shared;

    key = ftok(".", 'S');

    if (key == -1) {
        perror("ftok");
        return EXIT_FAILURE;
    }

    shmid = shmget(key, 1024, IPC_CREAT | 0666);

    if (shmid == -1) {
        perror("shmget");
        return EXIT_FAILURE;
    }

    shared = (char *)shmat(shmid, NULL, 0);

    if (shared == (char *)-1) {
        perror("shmat");
        return EXIT_FAILURE;
    }

    strcpy(shared, "Hello from Shared Memory!");

    printf("Data written: %s\n", shared);

    shmdt(shared);

    return EXIT_SUCCESS;
}