 #include <stdio.h>
 int main() {
 int n = 4;
 int arrival[] = {0, 0, 0, 0};
 int burst[] = {10, 1, 2, 1};
 int priority[] = {2, 1, 3, 4};

    int process[] = {1, 2, 3, 4};
    int waiting[4], turnaround[4];
    int total_wait = 0, total_turnaround = 0;
    // Ordenar por prioridad
    int i;
    for ( i = 0; i < n - 1; i++) {
    	int j;
        for ( j = i + 1; j < n; j++) {
            if (priority[j] < priority[i]) {
                int temp;
                temp = priority[i]; priority[i] = priority[j]; priority[j] = temp;
                temp = burst[i]; burst[i] = burst[j]; burst[j] = temp;
                temp = process[i]; process[i] = process[j]; process[j] = temp;
            }
        }
    }
    waiting[0] = 0;
    for (i = 1; i < n; i++) {
        waiting[i] = waiting[i - 1] + burst[i - 1];
    }
    for ( i = 0; i < n; i++) {
        turnaround[i] = waiting[i] + burst[i];
        total_wait += waiting[i];
        total_turnaround += turnaround[i];
    }
    printf("Proceso\tPrioridad\tRáfaga\tEspera\tRetorno\n");
    for ( i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t%d\t%d\n", process[i], priority[i], burst[i], waiting[i], turnaround[i]);
    }
    printf("Promedio espera: %.2f\n", total_wait / (float)n);
    printf("Promedio retorno: %.2f\n", total_turnaround / (float)n);
    return 0;
 }
