#include"stdio.h"
void main(){
    int i,j,n,tim,remain,flag=0,tq;
    float sumwt,sumtat;
    int at[10],bt[10],rt[10],pid[9];
    printf("enter the number of processes:");
    scanf("%d",&n);
    remain=n;
    printf("\nenter the arrival time and burst time-");
    for(i=0;i<n;i++){
        scanf("%d%d",&at[i],&bt[i]);
        rt[i]=bt[i];
        pid[i]=i+1;
    }
    printf("\nenter the time quantum:");
    scanf("%d",&tq);
    printf("\np\t A.T\t B.T\t TAT\t\t\t WT");
    for(tim=0,i=0;remain!=0;){
        if(rt[i]<=tq&&rt[i]>0){
            tim+=rt[i];
            rt[i]=0;
            flag=1;
        }
        else if(rt[i]>0){
            rt[i]-=tq;
            tim+=tq;
        }
        if(rt[i]==0&&flag==1){
            remain--;
            sumwt+=tim-at[i]-bt[i];
            sumtat+=tim-at[i];
            flag=0;
            printf("\nP%d\t %d\t %d\t %f \t %f ",pid[i],at[i],bt[i],sumtat,sumwt);
        }    
        if(i==n-1)
        i=0;
        else if(at[i+1]<=tim){
            i++;
        }
        else
        i=0; 
        }
        printf("\naverage tat=%f",sumtat*1.0/n);
        printf("\naverage wt=%f",sumwt/n);   
}


