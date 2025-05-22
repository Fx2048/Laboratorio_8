 #include <stdio.h> // librería
 int main() { // funcion principal main
    int n = 4; // 4 procesos variable
    int burst_time[] = {5, 3, 8, 6}; // tiempo rafaga  de esos 4 procesos
    int waiting_time[4], turnaround_time[4]; //matriz de 4 valores de almacenamiento para esas 4 valores de procesos
    int total_waiting = 0, total_turnaround = 0; //contadores de espera y retorno time
    // Primer proceso siempre tiene 0 de tiempo de espera
    waiting_time[0] = 0;
    // Calcular tiempo de espera para cada proceso
    int i; // solicito variable 
    for ( i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i-1] + burst_time[i-1]; // operacion de waiting
    }
    // Calcular tiempo de retorno
    for (i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];//operacion de retorno
        total_waiting += waiting_time[i];
        total_turnaround += turnaround_time[i];
    }
    printf("Proceso\tRáfaga\tEspera\tRetorno\n"); // imprimo tabla de 4 vlores
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i+1, burst_time[i], waiting_time[i], // los valores
turnaround_time[i]);
    }
    printf("Promedio espera: %.2f\n", total_waiting / (float)n); // total waiting
    printf("Promedio retorno: %.2f\n", total_turnaround / (float)n); // total retorno
 return 0;
 }
