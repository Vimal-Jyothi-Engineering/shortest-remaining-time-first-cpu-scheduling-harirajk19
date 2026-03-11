#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char pid[20][10];
    int at[20], bt[20], rt[20];
    int wt[20], tat[20];
    int n = 0;

    char first[20];

    if(scanf("%s", first) != 1)
        return 0;

    if(isdigit(first[0])) {
        n = atoi(first);
        for(int i=0;i<n;i++) {
            scanf("%s %d %d", pid[i], &at[i], &bt[i]);
            rt[i] = bt[i];
        }
    } else {
        strcpy(pid[0], first);
        scanf("%d %d", &at[0], &bt[0]);
        rt[0] = bt[0];
        n = 1;

        while(scanf("%s %d %d", pid[n], &at[n], &bt[n]) == 3) {
            rt[n] = bt[n];
            n++;
        }
    }

    int complete = 0, t = 0, shortest;
    int minm, finish_time, check;

    while(complete != n) {

        minm = 9999;
        check = 0;

        for(int j=0;j<n;j++) {
            if(at[j] <= t && rt[j] > 0 && rt[j] < minm) {
                minm = rt[j];
                shortest = j;
                check = 1;
            }
        }

        if(check == 0) {
            t++;
            continue;
        }

        rt[shortest]--;

        if(rt[shortest] == 0) {
            complete++;
            finish_time = t + 1;

            wt[shortest] = finish_time - bt[shortest] - at[shortest];
            if(wt[shortest] < 0)
                wt[shortest] = 0;
        }

        t++;
    }

    float total_wt = 0, total_tat = 0;

    printf("Waiting Time:\n");
    for(int i=0;i<n;i++) {
        printf("%s %d\n", pid[i], wt[i]);
        total_wt += wt[i];
    }

    printf("Turnaround Time:\n");
    for(int i=0;i<n;i++) {
        tat[i] = bt[i] + wt[i];
        printf("%s %d\n", pid[i], tat[i]);
        total_tat += tat[i];
    }

    printf("Average Waiting Time: %.1f\n", total_wt/n);
    printf("Average Turnaround Time: %.1f\n", total_tat/n);

    return 0;
}
