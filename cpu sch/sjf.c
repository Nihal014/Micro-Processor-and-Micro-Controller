
#include <stdio.h>
struct fc{
    int pid,bt,tat,wt,ct,at;
};
int main()
{
   int i,j,n;
   float awt=0,atat=0;
   struct fc  p[10],temp;
   printf("enter the total number of processes\t");
   scanf("%d",&n);
   for(i=0;i<n;i++){
       printf("\nenter arrival time and bt for process %d:",i+1);
       scanf("%d\t%d",&p[i].at,&p[i].bt);
       p[i].pid=i+1;
   }
  for(i=0;i<n;i++){
      for(j=0;j<n-1;j++){
          if(p[j].at>p[j+1].at){
              temp=p[j];
              p[j]=p[j+1];
              p[j+1]=temp;
          }
      }
  }
    
    p[0].ct=p[0].at+p[0].bt;
    
    
    for(i=1;i<n;i++){
      for(j=1;j<n-1;j++){
          if(p[j].bt>p[j+1].bt){
              temp=p[j];
              p[j]=p[j+1];
              p[j+1]=temp;
          }
      }
  }
    
    
      for(i=1;i<n;i++)
    {  
      //when proess is ideal in between i and i+1
    
     p[i].ct=p[i-1].ct+p[i].bt;
    }
    
    
    printf("\np\t A.T\t B.T\t C.T\t TAT\t WT");
    
    for(i=0;i<n;i++)
    {
    p[i].tat=p[i].ct-p[i].at;
    p[i].wt=p[i].tat-p[i].bt;
    atat+=p[i].tat;
    awt+=p[i].wt;
    }
    atat=atat/n;
    awt=awt/n;
    
    for(i=0;i<n;i++)
    {
      printf("\nP%d\t %d\t %d\t %d \t %d \t %d",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }
    printf("\naverage turnaround time is %f",atat);

    printf("\naverage wating timme is %f",awt);
    
    
    return 0;
}




