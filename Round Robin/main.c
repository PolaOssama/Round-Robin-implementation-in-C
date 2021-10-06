#include<stdio.h>
/*
     at = Arrival Time
     bt = Burst Time
     rt = Response Time
    time_q = Time Quantum


*/
int at=0,bt[100],rt[100],temp[100];  // Global variables
float wait_time=0,turn_time=0;

void main()
{
    int c,j,n,time,r,flag=0,time_q,ltt,i,wt=0;
    printf("Enter no.of process:");
    scanf("%d",&n);   // no. processes
    r=n;

    for(c=0; c<n; c++)  // Take inputs from the user
    {

        printf("Enter burst time of p%d: \t",c+1);
        scanf("%d",&bt[c]);
        rt[c]=bt[c];
        temp[c]=bt[c];
        printf("\n");
    }
    printf("Enter time quantum:\t");
    scanf("%d",&time_q);    // Quantuam time
    printf("\n\n\tprocess\tAT\tTAT\tWT\torder\n\n");

    for(time=0,c=0; r!=0;)
    {
        if(rt[c]<=time_q && rt[c]>0)  // rt[] have the same values of burst time S
        {
            time=time+rt[c];
            rt[c]=0;
            flag=1;
        }
        else if (rt[c]>0)
        {
            rt[c]=rt[c]-time_q;
            time=time+time_q;
        }
        if(rt[c]==0 && flag==1)
        {
            wt=0;
            wt = time-at-bt[c];
            r--;
            printf("\tP%d\t%d\t%d\t%d\t%d\n",c+1,at,time-at,wt,c+1);
            ltt=time-at;
            wait_time=wait_time+time-at-bt[c];
            turn_time=turn_time+time-at;
            flag=0;
        }
        if( c == n-1)
            c=0;
        else if(at<=time)
            c++;
        else
            c=0;
    }
    j=0;
    printf("\n\n\n");
    printf("Gantt Chart ");
    printf("\n\n\n");
    printf("\t");
/********************************************************/
  for (int i=at;i<=time;i++){
    printf("--");


  }
         printf("--");
  printf("\n");
   printf("\t");


/****************************************************************/
    for(i=at; i<time;)
    {
        if(bt[j]>=time_q)
        {
            printf("P%d    |\t",j+1);
            i+=time_q;
            bt[j]=bt[j]-time_q;
        }
        else if(bt[j]>0)
        {
            printf("P%d |\t",j+1);
            i+=bt[j];
            bt[j]=0;
        }
        j++;
        if(j>=n)
        {
            j=0;
        }
    }
    printf("\n");

    j=0;
    printf("\t");
    /*****************/
      for (int i=at;i<=time;i++){
    printf("--");

  }
         printf("--");
     printf("\n");
      printf("\t ");
/*********************/
    for(i=at; i<time;)
    {

        if(temp[j]>=time_q)
        {

            printf("    ");
            printf(" %d\t",i+time_q);
            i+=time_q;
            temp[j]=temp[j]-time_q;

        }

        else if(temp[j]>0)
        {      printf("   ");
            printf("%d\t",i+temp[j]);
            i+=temp[j];
            temp[j]=0;

        }
        j++;
        if(j>=n)
        {
            j=0;

        }
    }



    printf("\n\n\n");
    printf("\nAverage_waiting_time=%.2f\n",wait_time/n);
    printf("Average_turn_around_time=%.2f\n",turn_time/n);
    printf("\n\n");
}
