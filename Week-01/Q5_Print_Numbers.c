//Question 5
//Child process print 1 to 10 and Parent process print 11 to 20.

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    pid_t pid=fork();
    if(pid<0){
        printf("Fork failed");
        return 0;
    }
    else if(pid==0){
        printf("Child process\n");
        for(int i=1;i<=10;i++){
            printf("%d ",i);
        }
        printf("\n");
    }
    else{
        wait(NULL);
        printf("Parent process\n");
        for(int i=11;i<=20;i++){
            printf("%d ",i);
        }
        printf("\n");
    }
    return 0;
}