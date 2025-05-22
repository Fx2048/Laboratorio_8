 #include <stdio.h>
 #define MAX 10
 int main() {
    int n = 4;
    int arrival_time[] = {0, 1, 2, 3};
    int burst_time[] = {5, 3, 1, 2};
    int remaining_time[4];
    int waiting_time[4] = {0}, turnaround_time[4];
    int quantum = 2;
    int time = 0, done = 0;
    int i;
    for ( i = 0; i < n; i++) {
        remaining_time[i] = burst_time[i];
    }
    while (done < n) {
        int executed = 0;
        
        for ( i = 0; i < n; i++) {
            if (arrival_time[i] <= time && remaining_time[i] > 0) {
                if (remaining_time[i] <= quantum) {
                    time += remaining_time[i];
                    waiting_time[i] = time - burst_time[i] - arrival_time[i];
                    remaining_time[i] = 0;
                    done++;
                } else {
                    time += quantum;
                    remaining_time[i] -= quantum;
                }
                executed = 1;
            }
        }
        if (!executed) time++;  // Si no se ejecutó nada, avanza el tiempo
    }
    int total_wait = 0, total_turnaround = 0;
    for ( i = 0; i < n; i++) {

 turnaround_time[i] = burst_time[i] + waiting_time[i];
 total_wait += waiting_time[i];
 total_turnaround += turnaround_time[i];
 }
 
 
 printf("Proceso\tLlegada\tRáfaga\tEspera\tRetorno\n");
 for ( i = 0; i < n; i++) {
 printf("P%d\t%d\t%d\t%d\t%d\n", i+1, arrival_time[i], burst_time[i], 
waiting_time[i], turnaround_time[i]);
 }
 printf("Promedio espera: %.2f\n", total_wait / (float)n);
 printf("Promedio retorno: %.2f\n", total_turnaround / (float)n);
 return 0;
 }
