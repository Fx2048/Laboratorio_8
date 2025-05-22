#include <stdio.h>

#define N 3

typedef struct {
    int id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
} Proceso;

void ordenar_por_llegada(Proceso p[], int n) {
	int i;
    for ( i = 0; i < n - 1; i++) {
    	int j;
        for (j = 0; j < n - i - 1; j++) {
            if (p[j].arrival_time > p[j + 1].arrival_time) {
                Proceso temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

int main() {
    Proceso p[N] = {
        {1, 1, 2, 0, 0, 0}, // P1
        {2, 0, 2, 0, 0, 0}, // P2
        {3, 3, 2, 0, 0, 0}  // P3
    };

    ordenar_por_llegada(p, N);

    int tiempo_actual = 0;
    float total_waiting = 0, total_turnaround = 0;
	int i;
    for (i = 0; i < N; i++) {
        if (tiempo_actual < p[i].arrival_time) {
            tiempo_actual = p[i].arrival_time;
        }

        p[i].waiting_time = tiempo_actual - p[i].arrival_time;
        p[i].completion_time = tiempo_actual + p[i].burst_time;
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;

        tiempo_actual += p[i].burst_time;

        total_waiting += p[i].waiting_time;
        total_turnaround += p[i].turnaround_time;
    }

    printf("Proceso\tLlegada\tRáfaga\tEspera\tRetorno\tFinalización\n");
    for (i = 0; i < N; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].id,
               p[i].arrival_time,
               p[i].burst_time,
               p[i].waiting_time,
               p[i].turnaround_time,
               p[i].completion_time);
    }

    printf("Promedio de espera: %.2f\n", total_waiting / N);
    printf("Promedio de retorno: %.2f\n", total_turnaround / N);

    return 0;
}
