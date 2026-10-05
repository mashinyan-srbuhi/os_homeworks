#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
	pid_t pid = fork();

	if(pid < 0) {
	       perror("fork");
	       exit(1);
	}

	if (pid == 0) {
		printf("(inside Child process) Child's pid: %d, Parant's pid: %d\n", getpid(), getppid());
		exit(0);
	} else {
		printf("(inside Parent process) Parent's pid: %d, Child's pid: %d\n", getpid(), pid);
	}

	return 0;
}
