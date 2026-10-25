#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct process {
        int pid;
        int arrival_time;
        int burst_time;
        int turnaround_time;
        int waiting_time;
        int response_time;
        int completion_time;
};

void helper(struct process processes[], int n) {
        for (int i = 0; i < n; i++) {
                processes[i].pid = i + 1;
                processes[i].arrival_time = rand() % 10;
                processes[i].burst_time = rand() % 10 + 1;
        }
}

void print_results(struct process processes[], int n) {
        double tw = 0, tt = 0, tr = 0;
        printf("PID\tAT\tBT\tWT\tTAT\tRT\n");
        for (int i = 0; i < n; i++) {
                printf("%d\t%d\t%d\t%d\t%d\t%d\n",
                processes[i].pid, processes[i].arrival_time,
                processes[i].burst_time, processes[i].waiting_time,
                processes[i].turnaround_time, processes[i].response_time);
                tw += processes[i].waiting_time;
                tt += processes[i].turnaround_time;
                tr += processes[i].response_time;
        }
        printf("\nAverage Waiting Time: %.2f\n", tw / n);
        printf("Average Turnaround Time: %.2f\n", tt / n);
        printf("Average Response Time: %.2f\n", tr / n);
}

int compare_arrival(const void *x, const void *y) {
        const struct process p1 = *(const struct process *)x;
        const struct process p2 = *(const struct process *)y;

        if (p1.arrival_time != p2.arrival_time) {
                return p1.arrival_time - p2.arrival_time;
        }
        return p1.pid - p2.pid;
}

void fcfs(struct process processes[], int n) {

        qsort(processes, n, sizeof(struct process), compare_arrival);

        int current_time = 0;

        printf("=== First Come First Served (FCFS) ===\n");
        printf("Gantt Chart: ");
        for (int i = 0; i < n; i++) {
                if (current_time < processes[i].arrival_time) {
                        printf("| idle ");
                        current_time = processes[i].arrival_time;
                }

                processes[i].waiting_time = current_time - processes[i].arrival_time;
                processes[i].response_time = processes[i].waiting_time;
                current_time += processes[i].burst_time;
                processes[i].completion_time = current_time;
                processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
                printf("| P%d ", processes[i].pid);
        }
        printf("|\n");
        print_results(processes, n);
}

void sjf(struct process processes[], int n) {

        qsort(processes, n, sizeof(struct process), compare_arrival);
        int current_time = 0;

        printf("=== Shortest Job First (SJF) ===\n");
        printf("Gantt Chart: ");
        for(int i = 0; i < n; i++) {
                if (current_time < processes[i].arrival_time) {
                        printf("| idle ");
                        current_time = processes[i].arrival_time;
                }

                int min = i;
                for (int j = i+1; j < n; j++) {
                        if (processes[j].arrival_time > current_time) {
                                break;
                        }
                        if (processes[j].burst_time < processes[min].burst_time) {
                                min = j;
                        }
                }

                struct process temp = processes[min];
                for (int k = min; k > i; k--) {
                        processes[k] = processes[k-1];
                }
                processes[i] = temp;

                processes[i].waiting_time = current_time - processes[i].arrival_time;
                processes[i].response_time = processes[i].waiting_time;
                current_time += processes[i].burst_time;
                processes[i].completion_time = current_time;
                processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
                printf("| P%d ", processes[i].pid);

        }

        printf("|\n");
        print_results(processes, n);
}

int main() {
        srand(time(NULL));
        int n;
        printf("number of processes: ");
        scanf("%d", &n);
        if (n<=0) {
                printf("must be positive.\n");
                return 1;
        }

        struct process processes[n];
        helper(processes, n);

        for (int i = 0; i < n; i++) {
                printf("P%d: Arrival = %d, Burst = %d\n",
                processes[i].pid,
                processes[i].arrival_time,
                processes[i].burst_time);
        }

        printf("\n");

        fcfs(processes, n);
	printf("\n");
        sjf(processes, n);

        return 0;
}
