#include<stdio.h>
#include<conio.h>
int main(){
	// Loading animation
	printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tLoading ");
	int z;
	for(z=0;z<3;z++)
	{
		printf(".");
		sleep(1);
	}
	system("cls");
	
	printf("\t\t\tThis project is submitted by: Rudhanshi Acharya\n\n\n");
	printf("\t                                    11811130                                  \n");
	printf("\t                                     K18PB                                 \n");
	system("COLOR f2");
	printf("\t                                   Scheduling                          \n");
  long int n,i=0,j=0;
  printf("No of Process : ");
  scanf("%ld",&n ); 
  double prt[n],avgwait,avgTA,burstTime[n],arrivalTime[n],WT[n],TurnAT[n], Process[n], temp, CT[n],min,sum=0,sum2=0,
  waitFinal,TAFinal, waitavg, TAavg;
  for(i=0;i<n;i++)
  {
    printf("\n Burst Time for Process [%d] : ", i+1 );
    scanf("%lf", &burstTime[i]);
    printf("\n Arrival Time for Process [%d] : ", i+1 );
    scanf("%lf", &arrivalTime[i] );
    Process[i]=i+1;
  }

  printf("\n\n\t\t\t                          TABLE                            \n\n");
  printf("\t\t\t Process  Arrival Time  Burst Time \n");
  for(i=0;i<n;i++)
  {
    printf("\t\t\t  P[%0.0lf]          %0.0lf           %0.0lf      \n",Process[i],arrivalTime[i],burstTime[i]);
  }


  printf("\n\n\t\t\t                Sorted according Arrival Time              \n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(arrivalTime[i]<arrivalTime[j])
      {
        
        temp = burstTime[j];
        burstTime[j] = burstTime[i];
        burstTime [i] = temp;
	
	      temp = Process[j];
        Process[j] = Process[i];
        Process[i] = temp;

	      temp = arrivalTime[j];
        arrivalTime[j] = arrivalTime[i];
        arrivalTime[i] = temp;
      
  }
  }
}


  printf("\n\n\t\t\t                       Sorted Table                  \n\n");
  printf("\t\t\t Process  Arrival Time  Burst Time \n");
  for(i=0;i<n;i++)
  {
    printf("\t\t\t  P[%0.0lf]          %0.0lf           %0.0lf      \n",Process[i],arrivalTime[i],burstTime[i]);
  }
  
  long int k = 1;
  double b_time = 0;
  for(j=0;j<n;j++)
  {
    b_time = b_time + burstTime[j];
    min = burstTime[k];

    for(i=k;i<n;i++)
    {
      if((b_time >= arrivalTime[i])&&(burstTime[i]<min))
      {
        temp = burstTime[k];
        burstTime[k] = burstTime[i];
        burstTime[i] = temp;

        temp = arrivalTime[k];
        arrivalTime[k] = arrivalTime[i];
        arrivalTime[i] = temp;

        temp = Process[k];
        Process[k] = Process[i];
        Process[i] = temp;
      }
    }
    k++;
  }
  WT[0] = 0;
  for(i=1;i<n;i++)
  {
    sum += burstTime[i-1];
    WT[i] = sum - arrivalTime[i];
    waitFinal += WT[i]; 
  }
  waitavg = waitFinal/n;
  for(i=0;i<n;i++)
  {
    sum2 += burstTime[i];
    TurnAT[i] = sum2 - arrivalTime[i];
    TAFinal += TurnAT[i];
  }
  TAavg=TAFinal/n;
printf("\n\n\t\t\t                        Waiting time and Turn Around Time                        \n\n");
  printf("\t\t\t Process  Arrival Time  Burst Time   Waiting Time    Turn Around Time  \n");
  for(i=0;i<n;i++)
  {
    printf("\t\t\t  P[%0.0lf]          %0.0lf           %0.0lf              %0.0lf                %0.0lf          \n",Process[i],arrivalTime[i],burstTime[i],WT[i],TurnAT[i]);
  }



  /*prioritizing the processes according to the formulae Priority = 1+ Waiting time / Estimated run time
  */
 
  
  CT[0] = burstTime[0];
  for(i=1;i<n;i++)
  {
    CT[i] = CT[i-1] + burstTime[i];
  }

  for(i=0;i<n;i++)
  {
    prt[i] = 1+WT[i]/CT[i];
    printf("Priority :");
    printf("%lf \n",prt[i]);
  }


  printf("\n\n\t\t\t                                Final Table                                       \n\n");
  printf("\t\t\t Process  Arrival Time  Burst Time   Waiting Time    Turn Around Time  \n");
  printf("\t\t\t  P[%0.0lf]          %0.0lf           %0.0lf              %0.0lf                %0.0lf          \n",Process[0],arrivalTime[0],burstTime[0],WT[0],TurnAT[0]);
  for(i=n-1;i>0;i--)
  {
    printf("\t\t\t  P[%0.0lf]          %0.0lf           %0.0lf              %0.0lf                %0.0lf          \n",Process[i],arrivalTime[i],burstTime[i],WT[i],TurnAT[i]);
  }

  printf("\n\n\n\t\t\tAverage Turn Around Time : %lf",TAavg);
  printf("\n\t\t\tAverage Waiting Time     : %lf\n\n",waitavg);
	
  getch();
  return 0;
}

