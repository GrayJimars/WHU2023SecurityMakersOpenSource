#include<stdio.h>

int main()
{
	int children[1001] = { 0 };
	int n, m, count = 1, current_child = -1;
	scanf("%d %d", &n, &m);
	while(count <= n){
        for(int i = 0;i < m;) {
            current_child = (current_child + 1) % n;
            if(children[current_child] == 0) {
                i++;
            }
        }
        children[current_child] = 1;
		count++;
	}
	printf("%d",current_child + 1);
	return 0;
}
