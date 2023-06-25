#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n][n];
    int count=1;
    if(!(n%2))
    {
        for(int i=0;i<n/2;i++)
        {
           for(int j=i;j<n-i;j++)
           {  
               arr[i][j]=count;
               arr[j][i]=count;
               arr[n-i-1][j]=count;
               arr[j][n-i-1]=count;
               
           }
            count++;   
        }
    }
    else
    {
        for(int i=0;i<n/2+1;i++)
        {
           for(int j=i;j<n-i;j++)
           {  
               arr[i][j]=count;
               arr[j][i]=count;
               arr[n-i-1][j]=count;
               arr[j][n-i-1]=count;
               
           }
            count++;   
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%d ",arr[i][j]);
        printf("\n");
    }
}
