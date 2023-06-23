#include<stdio.h>

int check(int m) {
    if(m % 7 == 0 && m != 0) {
        return 0;
    }else {
        while(m != 0){
            if(m % 10 == 7){
                return 0;
            }
            m /= 10;
        }
        return 1;
    }
}

int main()
{
    char name[1001][21];
	int hasquited[1001] = { 0 };
	int n, m, t, count = 0;
	scanf("%d %d %d", &n, &m, &t);
    m--;
    
    for(int i = 0;i < n;i++) {
        scanf("%s", name[i]);
    }
    
    if(!check(t)) {
        hasquited[m] = 1;
        count++;
    }
    
	while(count < n) {
        int find = 0;
        while(check(t) || find == 0) {
            m = (m + 1) % n;
            if(hasquited[m] == 0) {
                t++;
                find = 1;
            }
        }
        hasquited[m] = 1;
		count++;
	}
    puts(name[m]);
	return 0;
}
