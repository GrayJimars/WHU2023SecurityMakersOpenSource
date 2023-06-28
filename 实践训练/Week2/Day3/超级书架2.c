#include<stdio.h>
long long min = 10000000000000;

void dfs(int cownumber
, int cowheights[]
, long long nowheight
, int bookshelfheight
, int nownumber){

    if(nowheight >= bookshelfheight){
        if(nowheight < min){
            min = nowheight;
        }
        return;
    }
    
    if(nownumber > cownumber){
        return;
    }

    dfs(cownumber
    , cowheights
    , nowheight + cowheights[nownumber]
    , bookshelfheight
    , nownumber + 1);

    dfs(cownumber
    , cowheights
    , nowheight
    , bookshelfheight
    , nownumber + 1);
}

int main(){
    int N, H[21], B;
    scanf("%d %d", &N, &B);
    for(int i = 1;i <= N;i++){
        scanf("%d", &H[i]);
    }
    dfs(N, H, 0, B, 1);
    printf("%lld", min - B);
    return 0;
}