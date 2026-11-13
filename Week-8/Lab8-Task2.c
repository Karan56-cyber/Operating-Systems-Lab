// Shared Memory Reader using System V IPC in C

// * Demonstrates Inter-Process Communication (IPC) using shared memory.
// * Accesses an existing shared memory segment using shmget().
// * Attaches the segment using shmat().
// * Reads and displays the data written by another process.
// * Detaches the shared memory using shmdt().

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(void)
{
    key_t key;
    int shmid;
    char *shared;

    key = ftok(".", 'S');

    shmid = shmget(key, 1024, 0666);

    if (shmid == -1)
    {
        perror("shmget");
        return EXIT_FAILURE;
    }

    shared = (char *)shmat(shmid, NULL, 0);

    if (shared == (char *)-1)
    {
        perror("shmat");
        return EXIT_FAILURE;
    }

    printf("Data received: %s", shared);

    shmdt(shared);

    return EXIT_SUCCESS;
}
