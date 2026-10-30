#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], priority[n];
    int wt[n], tat[n],ct[i];

    for(i = 0; i < n; i++) {
        pid[i] = i + 1;

        printf("\nProcess P%d\n", pid[i]);

        printf("Enter Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Enter Burst Time: ");
        scanf("%d", &bt[i]);

        printf("Enter Priority: ");
        scanf("%d", &priority[i]);
    }

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {

            if(priority[i] > priority[j]) {

                int temp;

                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;

                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

    int current_time = 0;

    for(i = 0; i < n; i++) {

        if(current_time < at[i]) {
            current_time = at[i];
        }

        wt[i] = current_time - at[i];
        tat[i] = wt[i] + bt[i];

        current_time += bt[i];

        ct[i]=current_time;
    }

    printf("\nPID\tAT\tBT\tPriority\tCT\tWT\tTAT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t\t%d\t%d\n",
               pid[i], at[i], bt[i], priority[i],ct[i],
               wt[i], tat[i]);
    }

    return 0;
}