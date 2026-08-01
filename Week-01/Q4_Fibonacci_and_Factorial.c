//Question 4
//Write a program to print fibonacci series upto n in child process and factorial of n in parent process only.

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    pid_t pid=fork();
    if(pid<0){
        printf("Fork failed");
        return 0;
    }
    else if(pid==0){
        printf("Child process\n");
        printf("Fibonacci Series\n");
        int a=0,b=1,c;
        for(int i=0;i<n;i++){
            printf("%d ",a);
            c=a+b;
            a=b;
            b=c;
        }
        printf("\n");
    }
    else{
        wait(NULL);
        printf("Parent process\n");
        int fact=1;
        for(int i=1;i<=n;i++){
            fact*=i;
        }
        printf("Factorial of %d is %d\n", n, fact);
    }
    return 0;
}