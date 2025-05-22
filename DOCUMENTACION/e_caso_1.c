#include <stdio.h>
 #include <limits.h>
 int main() {
    int n = 4;
    int arrival[] = {0, 2, 4, 5};
    int burst[] = {7, 4, 1, 4};
    int priority[] = {2, 1, 3, 2};
    int remaining[4];
    int waiting[4] = {0}, turnaround[4];
    int completed = 0, time = 0;
    int current = -1;
    int i;
    for (i = 0; i < n; i++)
        remaining[i] = burst[i];

    while (completed < n) {
        int highest_priority = INT_MAX;
        int idx = -1;
        // Buscar proceso disponible con mayor prioridad (menor valor)
        for ( i = 0; i < n; i++) {
            if (arrival[i] <= time && remaining[i] > 0) {
                if (priority[i] < highest_priority) {
                    highest_priority = priority[i];
                    idx = i;
                } else if (priority[i] == highest_priority) {
                    // En empate, elegir proceso con llegada más temprana
                    if (arrival[i] < arrival[idx]) {
                        idx = i;
                    }
                }
            }
        }
        if (idx == -1) {
            time++;  // No hay procesos listos, avanzar tiempo
            continue;
        }
        // Ejecutar el proceso seleccionado 1 unidad de tiempo
        remaining[idx]--;
        time++;
        // Si proceso termina
        if (remaining[idx] == 0) {
            completed++;
            turnaround[idx] = time - arrival[idx];
            waiting[idx] = turnaround[idx] - burst[idx];
        }
    }
    int total_wait = 0, total_turnaround = 0;
    printf("Proceso\tLlegada\tRáfaga\tPrioridad\tEspera\tRetorno\n");
    for ( i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n", i+1, arrival[i], burst[i], priority[i], waiting[i], 
turnaround[i]);
        total_wait += waiting[i];
        total_turnaround += turnaround[i];
    }
    printf("Promedio espera: %.2f\n", total_wait / (float)n);
    printf("Promedio retorno: %.2f\n", total_turnaround / (float)n);

 return 0;
 }
