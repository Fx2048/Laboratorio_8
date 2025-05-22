#include <stdio.h>

#define N 3  // Número de procesos

int main() {
    int arrival_time[N] = {0, 1, 2};
    int burst_time[N] = {2, 4, 1};
    int remaining_time[N];
    int waiting_time[N] = {0}, turnaround_time[N];
    int quantum = 3;
    int time = 0, done = 0;
    int i;

    for (i = 0; i < N; i++) {
        remaining_time[i] = burst_time[i];
    }

    while (done < N) {
        int executed = 0;

        for (i = 0; i < N; i++) {
            if (arrival_time[i] <= time && remaining_time[i] > 0) {
                executed = 1;
                if (remaining_time[i] <= quantum) {
                    time += remaining_time[i];
                    waiting_time[i] = time - burst_time[i] - arrival_time[i];
                    remaining_time[i] = 0;
                    done++;
                } else {
                    time += quantum;
                    remaining_time[i] -= quantum;
                }
            }
        }

        if (!executed) time++;  // Si no se ejecutó ningún proceso, avanza el tiempo
    }

    int total_wait = 0, total_turnaround = 0;
    for (i = 0; i < N; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        total_wait += waiting_time[i];
        total_turnaround += turnaround_time[i];
    }

    printf("Proceso\tLlegada\tRáfaga\tEspera\tRetorno\n");
    for (i = 0; i < N; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i + 1, arrival_time[i], burst_time[i],
               waiting_time[i], turnaround_time[i]);
    }

    printf("Promedio espera: %.2f\n", total_wait / (float)N);
    printf("Promedio retorno: %.2f\n", total_turnaround / (float)N);

    return 0;
}
