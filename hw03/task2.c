#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
int main() {
	
	int status1;
        pid_t pid1 = fork();

        if (pid1 < 0) {
               perror("fork1");
               exit(1);
        }

        if (pid1 == 0) {
                printf("Child1's pid: %d, Parent's pid: %d\n", getpid(), getppid());
                exit(0);
        }

        pid_t pid3 = wait(&status1);
        if (pid3 == -1) {
                perror("wait1");
                exit(3);
        }

        printf("(inside Parent process) Parent's pid: %d, Child1's pid: %d\n", getpid(), pid1);	
	printf("wait() used\n");

        if (WIFEXITED (status1))
                printf ("Normal termination with exit status=%d\n",
                        WEXITSTATUS (status1));
        if (WIFSIGNALED (status1))
                printf ("Killed by signal=%d%s\n",
                        WTERMSIG (status1),
                        WCOREDUMP (status1) ? " (dumped core)" : "");

	printf("\n");


	int status2;
	pid_t pid2 = fork();
	if (pid2 < 0) {
		perror("fork2");
		exit(2);
	}
	
	if (pid2 == 0) {
                printf("Child2's pid: %d, Parent's pid: %d\n", getpid(), getppid());
                exit(0);
	}

	pid3 = waitpid (pid2, &status2, 0);
	if (pid3 == -1) {
		perror("waitpid");
		exit(4);
	}

        printf("(inside Parent process) Parent's pid: %d, Child2's pid: %d\n", getpid(), pid2);
	printf("waitpid() used\n");

	if (WIFEXITED (status2))
		printf ("Normal termination with exit status=%d\n",
                        WEXITSTATUS (status2));
	if (WIFSIGNALED (status2))
		printf ("Killed by signal=%d%s\n",
                        WTERMSIG (status2),
                        WCOREDUMP (status2) ? " (dumped core)" : "");

        return 0;
}
