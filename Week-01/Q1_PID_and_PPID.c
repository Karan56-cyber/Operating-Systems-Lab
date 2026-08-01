//Question 
//Write a program that creates one child and prints the PID and PPID of parent and the child 

#include<unistd.h>
#include<stdio.h>
int main(){
    pid_t pid=fork();
    if(pid<0){
        printf("Fork failed");
    }
    else if(pid==0){
        printf("The pid of the child is %d \n",getpid());
    }
    else{
        printf("The pid of the parent is %d \n ",getppid());
    }
    return 0;
}