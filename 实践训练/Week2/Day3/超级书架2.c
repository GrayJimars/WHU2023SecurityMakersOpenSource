#include<stdio.h>
long long ans = 10000000000000;
void dfs(int N, int H[], long long S, int B, int k){
    if(S >= B){
        if(S < ans){
            ans = S;
        }
        return;
    }
    if(k > N){
        return;
    }
    dfs(N, H, S + H[k], B, k + 1);
    dfs(N, H, S, B, k + 1);
}

int main(){
    int N, H[21], B;
    scanf("%d %d", &N, &B);
    for(int i = 1;i <= N;i++){
        scanf("%d", &H[i]);
    }
    dfs(N, H, 0, B, 1);
    printf("%lld", ans - B);
    return 0;
}