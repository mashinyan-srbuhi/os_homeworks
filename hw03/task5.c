#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
	pid_t pid = fork();
	if(pid == -1) {
		perror("fork");
		exit(1);
	}
	if (pid == 0) {
		printf("(inside child process) Child's pid: %d\n",getpid());
		exit(0);
	}
	printf("(inside parent process) Parent's pid: %d, Child's pid: %d\n", 
			getpid(), pid);
	
	while(1);

	return 0;
}
