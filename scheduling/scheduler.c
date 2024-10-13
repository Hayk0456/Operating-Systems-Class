#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
} Process;

void fcfs(Process processes[], int n) {
    int current_time = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        processes[i].waiting_time = current_time - processes[i].arrival_time;
        processes[i].response_time = processes[i].waiting_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        current_time += processes[i].burst_time;
    }
}

void sjf(Process processes[], int n) {
    int current_time = 0;
    bool completed[n];
    for (int i = 0; i < n; i++) {
        completed[i] = false;
    }
    int completed_count = 0;
    while (completed_count < n) {
        int shortest_job = -1;
        for (int i = 0; i < n; i++) {
            if (!completed[i] && processes[i].arrival_time <= current_time) {
                if (shortest_job == -1 || processes[i].burst_time < processes[shortest_job].burst_time ||
                    (processes[i].burst_time == processes[shortest_job].burst_time &&
                        processes[i].arrival_time < processes[shortest_job].arrival_time)) {
                    shortest_job = i;
                }
            }
        }
        if (shortest_job != -1) {
            processes[shortest_job].waiting_time = current_time - processes[shortest_job].arrival_time;
            processes[shortest_job].response_time = processes[shortest_job].waiting_time;
            processes[shortest_job].turnaround_time = processes[shortest_job].waiting_time + processes[shortest_job].burst_time;
            current_time += processes[shortest_job].burst_time;
            completed[shortest_job] = true;
            completed_count++;
        }
        else {
            current_time++;
        }
    }
}

void display_gantt_chart(Process processes[], int n) {
    printf("Gantt Chart: ");
    for (int i = 0; i < n; i++) {
        printf("| P%d ", processes[i].pid);
    }
    printf("|\n");
}

void display_process_info(Process processes[], int n) {
    printf("PID\tAT\tBT\tWT\tTAT\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", processes[i].pid, processes[i].arrival_time,
            processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time,
            processes[i].response_time);
    }
}

void calculate_averages(Process processes[], int n) {
    float avg_waiting_time = 0, avg_turnaround_time = 0, avg_response_time = 0;
    for (int i = 0; i < n; i++) {
        avg_waiting_time += processes[i].waiting_time;
        avg_turnaround_time += processes[i].turnaround_time;
        avg_response_time += processes[i].response_time;
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    avg_response_time /= n;
    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
    printf("Average Response Time: %.2f\n", avg_response_time);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    Process processes[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].pid = i + 1;
    }

    Process fcfs_processes[n], sjf_processes[n];
    for (int i = 0; i < n; i++) {
        fcfs_processes[i] = processes[i];
        sjf_processes[i] = processes[i];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (sjf_processes[j].arrival_time > sjf_processes[j + 1].arrival_time) {
                Process temp = sjf_processes[j];
                sjf_processes[j] = sjf_processes[j + 1];
                sjf_processes[j + 1] = temp;
            }
        }
    }
    fcfs(fcfs_processes, n);
    sjf(sjf_processes, n);
    printf("=== First Come First Served (FCFS) ===\n");
    display_gantt_chart(fcfs_processes, n);
    display_process_info(fcfs_processes, n);
    calculate_averages(fcfs_processes, n);
    printf("\n=== Shortest Job First (SJF) ===\n");
    display_gantt_chart(sjf_processes, n);
    display_process_info(sjf_processes, n);
    calculate_averages(sjf_processes, n);
    return 0;
}