//Question 
//Write a program that creates one child and prints the PID and PPID of parent and the child 

#include<unistd.h>
#include<stdio.h>
int main(){
    fork();
    print("The parent id is %d\n",getppid());
    print("The child pid is %d\n",getpid());
    return 0;
}