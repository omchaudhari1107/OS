#include <stdio.h>
int ct[50], tat[50], wt[50];
float avgct, avgtat, avgwt;
int CompletionTime(int bt[], int n)
{
    ct[0] = bt[0];
    for (int i = 0; i < n; i++)
    {
        ct[i + 1] = ct[i] + bt[i + 1];
    }
}
int TurnAroundTime(int at[], int n)
{
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
    }
}
int WaitTime(int bt[], int n)
{
    for (int i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];
    }
}
void display(int process[], int at[], int bt[], int n)
{
    int temp1[n], temp2[n], temp3[n];
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT");
    for (int i = 0; i < n; i++)
    {
        printf("\n%d\t%d\t%d\t%d\t%d\t%d ", process[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    temp1[-1] = 0;
    temp2[-1] = 0;
    temp3[-1] = 0;
    for (int i = 0; i < n; i++)
    {
        temp1[i] = temp1[i - 1] + ct[i];
    }
    for (int i = 0; i < n; i++)
    {
        temp2[i] = temp2[i - 1] + tat[i];
    }
    for (int i = 0; i < n; i++)
    {
        temp3[i] = temp3[i - 1] + wt[i];
    }
    avgct = temp1[n - 1] / n;
    avgtat = temp2[n - 1] / n;
    avgwt = temp3[n - 1] / n;
    printf("\nAverage Completion Time = %f", avgct);
    printf("\nAverage Turn Around Time = %f", avgtat);
    printf("\nAverage Waiting Time = %f", avgwt);
}
int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int process[n];
    int bt[n];
    int at[n];
    printf("Enter process ID:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &process[i]);
    }
    printf("Enter Burst Time:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }
    printf("Enter Arrival time:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &at[i]);
    }
    CompletionTime(bt, n);
    TurnAroundTime(at, n);
    WaitTime(bt, n);
    display(process, at, bt, n);
    return 0;
}