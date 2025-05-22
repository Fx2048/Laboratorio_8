 #include <stdio.h>
 int main() {
    int n = 4;
    int burst_time[] = {5, 3, 8, 6};
    int waiting_time[4], turnaround_time[4];
    int total_waiting = 0, total_turnaround = 0;
    // Primer proceso siempre tiene 0 de tiempo de espera
    waiting_time[0] = 0;
    // Calcular tiempo de espera para cada proceso
    int i;
    for ( i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i-1] + burst_time[i-1];
    }
    // Calcular tiempo de retorno
    for (i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        total_waiting += waiting_time[i];
        total_turnaround += turnaround_time[i];
    }
    printf("Proceso\tRáfaga\tEspera\tRetorno\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i+1, burst_time[i], waiting_time[i], 
turnaround_time[i]);
    }
    printf("Promedio espera: %.2f\n", total_waiting / (float)n);
    printf("Promedio retorno: %.2f\n", total_turnaround / (float)n);
 return 0;
 }
