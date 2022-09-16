#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
    int status;  
    pid_t child_pid;
    child_pid=fork();

    if(child_pid<0)
    {
        printf("\n Error ");
        exit(-1);
    }
    else if(child_pid==0)
    {
        pid_t parent_pid = getppid();
    	int status2;
        pid_t grandchild_pid = fork();
        if(grandchild_pid < 0){
            printf("Error\n");
            exit(0);
        }
        else if(grandchild_pid == 0){
            printf("\nI'm the grandchild process. My process Id is: '%d \nI'm the grandchild of %d, and child of %d. \n",getpid(), parent_pid, getppid());
        }
        else{
            wait(&status2);
            printf("\nI'm the child process, My process Id is:%d \nI'm the child of %d, and parent of %d. \n", getpid(), getppid(), grandchild_pid);
            exit(0);
        }
    }
    else
    {
	wait(&status);
        printf("\nI'm the parent process, My process Id is:'%d \nI'm the parent of process %d. I do not know my grandchild's process Id! \n", getpid(), child_pid);
        exit(0);
    }

}
