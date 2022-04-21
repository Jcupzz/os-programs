#include <stdio.h>  
  
  

void RoundRobin(){ 
    int i, NOP, sum=0,count=0, y, quant, wt=0, tat=0, at[10], bt[10], temp[10];    
    printf(" Total number of process in the system: ");  
    scanf("%d", &NOP);  
    y = NOP; 
for(i=0; i<NOP; i++)  
{  
printf(" Enter the Arrival and Burst time of the Process[%d]\n", i+1);  
printf(" Arrival time is: \t");   
scanf("%d", &at[i]);  
printf(" Burst time is: \t");  
scanf("%d", &bt[i]);  
temp[i] = bt[i]; 
}  
 
printf("Enter the Time Quantum for the process: \t");  
scanf("%d", &quant);  

printf("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");  
for(sum=0, i = 0; y!=0; )  
{  
if(temp[i] <= quant && temp[i] > 0)   
{  
    sum = sum + temp[i];  
    temp[i] = 0;  
    count=1;  
    }     
    else if(temp[i] > 0)  
    {  
        temp[i] = temp[i] - quant;  
        sum = sum + quant;    
    }  
    if(temp[i]==0 && count==1)  
    {  
        y--; 
        printf("\nProcess No[%d] \t\t %d\t\t\t %d\t\t %d", i+1, bt[i], sum-at[i], sum-at[i]-bt[i]);  
        wt = wt+sum-at[i]-bt[i];  
        tat = tat+sum-at[i];  
        count =0;     
    }  
    if(i==NOP-1)  
    {  
        i=0;  
    }  
    else if(at[i+1]<=sum)  
    {  
        i++;  
    }  
    else  
    {  
        i=0;  
    }  
}  

  
printf("\nTurn Around Time: \t%d",tat);  
printf("\nWaiting Time: \t%d",wt);} 
      

void ShortestJobFirst(){
    int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
    float Twt,Ttat;
    printf("Enter number of process:");
    scanf("%d",&n);
  
    printf("Enter Burst Time\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;         
    }
  

    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
  
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
  
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
   
    wt[0]=0;            
  
   
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
  
        total+=wt[i];
    }
  
    Twt=total;      
    total=0;
  
 
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];   
        total+=tat[i];
        
    }
  
    Ttat=total;    
    printf("\nWaiting Time=%f",Twt);
    printf("\nTurnaround Time=%f",Ttat);
}


void FCFS(){
    int n,bt[20],wt[20],tat[20],i,j;
    float avwt=0,avtat=0;
    printf("Enter total number of processes(maximum 20):");
    scanf("%d",&n);
 
    printf("Enter Process Burst Time\n");
    for(i=0;i<n;i++)
    {
        printf("P[%d]:",i+1);
        scanf("%d",&bt[i]);
    }
 
    wt[0]=0;   
 
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }
 

 
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
       
    }
 
   
    printf("Waiting Time:%f",avwt);
    printf("\nTurnaround Time:%f",avtat);
 
}



void PS(){
    int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,pos,temp;
    float total=0,avg_wt,avg_tat;
    printf("Enter Total Number of Process:");
    scanf("%d",&n);
 
    printf("\nEnter Burst Time and Priority\n");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Burst Time:");
        scanf("%d",&bt[i]);
        printf("Priority:");
        scanf("%d",&pr[i]);
        p[i]=i+1;          
    }
 
   for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=total;     
    total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];   
        total+=tat[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
 
    avg_tat=total;   
    printf("\n\nWaiting Time=%f",avg_wt);
    printf("\nTurnaround Time=%f\n",avg_tat);
 
}

int main(){
   int ch;
    do{ 
        
        int select;  
        printf("\nSelect from following\n 1.Round Robin\n 2.Shortest Job First \n 3.First come First Serve \n 4.Prioriry Scheduling \n"); 
        scanf("%d", &select);
        if( select==1) RoundRobin() ;
        if(select==2) ShortestJobFirst();
        if(select==3) FCFS();
        if(select==4) PS();
printf("\nDo you want to repeat ?\n1.Start over\n2.No\n");
        scanf("%d",&ch);         
        }while(ch==1);
  
}
