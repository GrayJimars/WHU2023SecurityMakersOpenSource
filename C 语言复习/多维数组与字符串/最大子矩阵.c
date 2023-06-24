#include <stdio.h>
int main(){
    long long m, n, max = 0, maxpoint[2] = { 0, 0}, matrix[100][100];
    scanf("%lld %lld", &m, &n);
    for(long long i = 0;i < m;i++){
        for(long long j = 0;j < n;j++){
            scanf("%lld", &matrix[i][j]);
            if(i > 0 
               && j > 0 
               && matrix[i][j] 
               * matrix[i - 1][j] 
               * matrix[i][j - 1] 
               * matrix[i - 1][j - 1] 
               > max){
                max = matrix[i][j] 
                    * matrix[i - 1][j] 
                    * matrix[i][j - 1] 
                    * matrix[i - 1][j - 1];
                maxpoint[0] = i;
                maxpoint[1] = j;
            }
        }
    }
    printf("%lld\n%lld %lld\n%lld %lld"
           , max
           , matrix[maxpoint[0] - 1][maxpoint[1] - 1]
           , matrix[maxpoint[0] - 1][maxpoint[1]]
           , matrix[maxpoint[0]][maxpoint[1] - 1]
           , matrix[maxpoint[0]][maxpoint[1]]);
    return 0;
}