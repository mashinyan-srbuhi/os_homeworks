#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void) {

	int status1;
	pid_t pid1 = fork();

	if(pid1 == -1) {
		perror("fork1");
		exit(1);
	}
	if(pid1 == 0) {
		printf("Child1: Success\n");
		exit(0);
	}

	pid_t pid3 = waitpid(pid1, &status1, 0);
	if (pid3 == -1) {
		perror("waitpid1");
                exit(1);
        }

        if (WIFEXITED (status1)) {
		if(WEXITSTATUS(status1) == 0) {
			printf ("Normal termination with exit status=%d\n",
                        WEXITSTATUS (status1));
		} else {
			printf ("Failed termination with status=%d\n", WEXITSTATUS(status1));
		}
	}
        if (WIFSIGNALED (status1))
                printf ("Killed by signal=%d%s\n",
                        WTERMSIG (status1),
                        WCOREDUMP (status1) ? " (dumped core)" : "");


	int status2;
	pid_t pid2 = fork();

        if(pid2 == -1) {
                perror("fork2");
                exit(1);
        }
        if(pid2 == 0) {
                printf("Child2: Fail\n");
                exit(5);
        }

        pid3 = waitpid(pid2, &status2, 0);
        if (pid3 == -1) {
                perror("waitpid2");
                exit(1);
        }

        if (WIFEXITED (status2)) {
                if(WEXITSTATUS(status2) == 0) {
                        printf ("Normal termination with exit status=%d\n",
                        WEXITSTATUS (status2));
                } else {
                        printf ("Failed termination with status=%d\n", WEXITSTATUS(status2));
                }
	}
        if (WIFSIGNALED (status2))
                printf ("Killed by signal=%d%s\n",
                        WTERMSIG (status2),
                        WCOREDUMP (status2) ? " (dumped core)" : "");


	return 0;


}
