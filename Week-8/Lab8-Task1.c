// Shared Memory Implementation using System V IPC in C

// * Demonstrates Inter-Process Communication (IPC) using shared memory.
// * Creates a shared memory segment using shmget().
// * Attaches the segment using shmat().
// * Writes and displays a message in shared memory.
// * Detaches the shared memory using shmdt().

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
