#include <stdio.h>
#include <stdlib.h>


typedef struct process{
    int aT,bT, pID, cT, tT, wT;
    
}proc;

void completionT(proc p[], int n){
    for (int j=0; j<n; j++){
        if(p[j].aT == 0)
        {
            p[j].cT = p[j].bT;
        }
        else if(p[j].aT>p[j-1].cT){
            p[j].cT = p[j].aT+p[j].bT;
        }
        else if(p[j].aT<p[j-1].cT){
            p[j].cT = p[j-1].cT+p[j].bT;
        }
    }
}

void tatT(proc p[], int n){
    for (int k=0; k<n; k++){
        p[k].tT=p[k].cT-p[k].aT;
    }
}

void waitingT(proc p[], int n){
    for (int l=0; l<n; l++){
        p[l].wT=p[l].tT-p[l].bT;
    }
}

void FCFS(proc arr[], int n){
    double TATavg=0;
    double WTavg=0;

    completionT(arr, n);
    tatT(arr, n);
    waitingT(arr, n);

    for(int i=0;i<n;i++){
        TATavg+=arr[i].tT;
        WTavg+=arr[i].wT;
    }
    printf("");
    printf("Process ID\t Arrival Time\t Burst Time\t Completion Time\t Turn Around Time\t Waiting Time\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n",arr[i].pID,arr[i].aT,arr[i].bT,arr[i].cT,arr[i].tT,arr[i].wT);
    }

    printf("Averrage Turn Around Time: %f\n",(TATavg/n));
    printf("Average Waiting Time: %f\n",(WTavg/n));
    
}

int main(){
    int no;
    printf("Enter No. of Processes: ");
    scanf("%d", &no);
    proc process[no];

    for (int i=0; i<no ; i++){
        process[i].pID = i + 1;
        printf("Procerss %d :", (i+1));
        printf("Arrival Time: ");
        scanf("%d", &process[i].aT);
        printf("Burst Length: ");
        scanf("%d", &process[i].bT);
    }
    FCFS(process, no);
   
}
