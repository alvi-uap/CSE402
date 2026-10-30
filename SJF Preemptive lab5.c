#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n],ct[n], rt[n], wt[n], tat[n];

    for(i = 0; i < n; i++) {
        pid[i] = i + 1;

        printf("\nProcess P%d\n", pid[i]);

        printf("Enter Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Enter Burst Time: ");
        scanf("%d", &bt[i]);

        rt[i] = bt[i];
    }

    while(completed < n) {
        int shortest = -1;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0) {
                if(shortest == -1 || rt[i] < rt[shortest]) {
                    shortest = i;
                }
            }
        }

        if(shortest == -1) {
            time++;
        } else {
            rt[shortest]--;
            time++;

            if(rt[shortest] == 0) {
                completed++;
                ct[shortest]=time;
                tat[shortest] = ct[shortest] - at[shortest];
                wt[shortest] = tat[shortest] - bt[shortest];
            }
        }
    }

    printf("\nPID\tAT\tBT\tCT\tWT\tTAT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i],ct[i], wt[i], tat[i]);
    }

    return 0;
}