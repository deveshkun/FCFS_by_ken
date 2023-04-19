#include <stdio.h>

int main()
{
  printf("Enter No of Processes -> ");
  int n;
  scanf("%d",&n);

  int PID[n],ART[n],BT[n],WT[n];
  int ST[n];

  for (int i=0;i<n;i++)
    {
      printf("Enter PID -> ");
      scanf("%d",&PID[i]);
      printf("Arriving Time -> ");
      scanf("%d",&ART[i]);
      printf("Enter Burst Time -> ");
      scanf("%d",&BT[i]);
      ST[i] = 0;
    }

  WT[0] = 0;

  for(int i=1;i<n;i++)
    {
      WT[i] = BT[i-1] + WT[i-1];
    }
  int k = 0;
  int sum = 0;
  ST[0] = 0;
  for (int i=1;i<=n;i++)
    {
      sum = BT[i-1];
      ST[i] = k + sum; 
      k = ST[i];
    }
  int s = 0;
  for (int i=0;i<n;i++)
    {
      WT[i] = ST[i] - ART[i];
    }
  int x=0;
  for (int i=0;i<n;i++)
    {
      x = x + WT[i];
    }

  printf("%d is AVG waiting Time",x/n);
  
  return 0;
}