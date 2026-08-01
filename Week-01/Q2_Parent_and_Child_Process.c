//Question 2
//Use the return value of the fork() to print "Parent process" only in the parent and "Child process" only in the child.

#include<stdio.h>
#include<unistd.h>


int main(){
    pid_t pid=fork();
    if (pid<0){
        printf("The fork failed\n");
        return 0;
    }
    else if(pid==0){
        printf("Child process\n");
    }
    else{
        printf("Parent process\n");
    }
    return 0;
}
