#include <stdio.h>

#define N 3

typedef struct {
    int id;
    int arrival;
    int burst;
    int waiting;
    int turnaround;
    int completed;
} Proceso;

int main() {
    Proceso p[N] = {
        {1, 0, 5, 0, 0, 0},  // P1
        {2, 1, 3, 0, 0, 0},  // P2
        {3, 2, 3, 0, 0, 0}   // P3
    };

    int time = 0, completed = 0;
    int total_wait = 0, total_turnaround = 0;

    while (completed < N) {
        int idx = -1;
        int min_burst = 1e9;
        int i;
        for ( i = 0; i < N; i++) {
            if (!p[i].completed && p[i].arrival <= time) {
                if (p[i].burst < min_burst || 
                   (p[i].burst == min_burst && p[i].arrival < p[idx].arrival)) {
                    min_burst = p[i].burst;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            p[idx].waiting = time - p[idx].arrival;
            time += p[idx].burst;
            p[idx].turnaround = p[idx].waiting + p[idx].burst;
            p[idx].completed = 1;
            completed++;

            total_wait += p[idx].waiting;
            total_turnaround += p[idx].turnaround;
        } else {
            time++; // Si ningún proceso ha llegado todavía
        }
    }

    printf("Proceso\tLlegada\tRáfaga\tEspera\tRetorno\n");
    int i;
    for (i = 0; i < N; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n",
               p[i].id, p[i].arrival, p[i].burst, p[i].waiting, p[i].turnaround);
    }

    printf("Promedio espera: %.2f\n", total_wait / (float)N);
    printf("Promedio retorno: %.2f\n", total_turnaround / (float)N);

    return 0;
}
