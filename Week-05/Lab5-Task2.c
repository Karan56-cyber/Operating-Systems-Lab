#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    int pipefd[2];
    pid_t pid;
    char filename[100];

    if (pipe(pipefd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid > 0) {
        close(pipefd[0]);

        printf("Enter file name: ");
        scanf("%s", filename);

        getchar();

        char name[100];
        int rollNo;
        char className[50];

        printf("Enter Name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';

        printf("Enter Roll No: ");
        scanf("%d", &rollNo);

        printf("Enter Class: ");
        scanf("%s", className);

        FILE *fp = fopen(filename, "w");

        if (fp == NULL) {
            perror("File creation failed");
            return 1;
        }

        fprintf(fp, "Name: %s\n", name);
        fprintf(fp, "Roll No: %d\n", rollNo);
        fprintf(fp, "Class: %s\n", className);

        fclose(fp);

        write(pipefd[1], filename, strlen(filename) + 1);

        close(pipefd[1]);

        wait(NULL);
    }
    else {
        close(pipefd[1]);

        read(pipefd[0], filename, sizeof(filename));

        close(pipefd[0]);

        printf("\nChild received file name: %s\n", filename);

        FILE *fp = fopen(filename, "r");

        if (fp == NULL) {
            perror("File opening failed");
            return 1;
        }

        printf("\nData read by child:\n");

        char ch;

        while ((ch = fgetc(fp)) != EOF) {
            printf("%c", ch);
        }

        fclose(fp);
    }

    return 0;
}