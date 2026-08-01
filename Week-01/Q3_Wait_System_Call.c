//Question 3
//Write a program in which the child prints number from 1 to 5 and the perent waits for it using wait().


#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){

    pid_t pid=fork();
    if(pid<0){
        printf("Fork failed\n");
        return 0;
    }
    else if(pid==0){
        printf("Child process\n");
        for(int i=1;i<=5;i++){
            printf("%d ",i);
        }
        printf("\n");
    }
    else{
        wait(NULL);
        printf("Parent process\n");
    }
    return 0;
}