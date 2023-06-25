//整理药名
#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d",&n);
    char arr[101][21];
    for(int i=0;i<n;i++)
        scanf("%s",arr[i]);
    for(int i=0;i<n;i++)
    {
        if(arr[i][0]>='a'&&arr[i][0]<='z')
           arr[i][0]-=32;
        for(int j=1;j<strlen(arr[i]);j++)
        {
            if ((arr[i][j]>='A')&&(arr[i][j]<='Z')) arr[i][j]+=32;
                //判断是否为大写字母，是则转换为小写字母。
    
        }
    }
    for(int i=0;i<n;i++){
      printf("%s",arr[i]);
      printf("\n");
    }
    return 0;
}
