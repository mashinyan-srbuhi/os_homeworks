#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
        pid_t pid1 = fork();
        if(pid1 == -1) {
                perror("fork");
                exit(1);
        }
        if (pid1 == 0) {
                printf("(inside child process) Child's pid: %d\n",getpid());
                exit(0);
        }
        printf("(inside parent process) Parent's pid: %d, Child's pid: %d\n",
                        getpid(), pid1);

	int status;
	pid_t pid2 = wait(&status);
	if(pid2 == -1) {
		perror("wait");
		exit(1);
	}

	printf("(inside parent process) Checked child's status. Child's pid: %d\n", pid2);

        while(1);
	
        return 0;
}
