#include <stdio.h>

#define N 4

typedef struct {
    int id;
    int arrival;
    int burst;
    int priority;
    int remaining;
    int waiting;
    int turnaround;
    int completed;
} Proceso;

int main() {
    Proceso p[N] = {
        {1, 0, 10, 3, 10, 0, 0, 0},
        {2, 0, 1, 1, 1, 0, 0, 0},
        {3, 0, 2, 4, 2, 0, 0, 0},
        {4, 0, 1, 2, 1, 0, 0, 0}
    };

    int time = 0, completed = 0;
    int total_wait = 0, total_turnaround = 0;
    int last_executed = -1;

    while (completed < N) {
        int idx = -1;
        int min_priority = 1e9;

        // Seleccionar el proceso con la prioridad más alta (número más bajo)
        int i;
		for (i = 0; i < N; i++) {
            if (p[i].arrival <= time && p[i].remaining > 0) {
                if (p[i].priority < min_priority || 
                   (p[i].priority == min_priority && p[i].arrival < p[idx].arrival)) {
                    min_priority = p[i].priority;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            p[idx].remaining--;
            if (p[idx].remaining == 0) {
                p[idx].completed = 1;
                p[idx].turnaround = time + 1 - p[idx].arrival;
                p[idx].waiting = p[idx].turnaround - p[idx].burst;

                total_wait += p[idx].waiting;
                total_turnaround += p[idx].turnaround;
                completed++;
            }
        }

        time++;
    }

    printf("Proceso\tLlegada\tRáfaga\tPrioridad\tEspera\tRetorno\n");
    int i;
	for ( i = 0; i < N; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n",
               p[i].id, p[i].arrival, p[i].burst, p[i].priority,
               p[i].waiting, p[i].turnaround);
    }

    printf("Promedio espera: %.2f\n", total_wait / (float)N);
    printf("Promedio retorno: %.2f\n", total_turnaround / (float)N);

    return 0;
}

