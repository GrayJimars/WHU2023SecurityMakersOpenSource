#include <stdio.h>
#include <stdlib.h>
#define maxn 17
#define max(a,b) (((a)>(b))?(a):(b))

int preference[maxn][maxn], visit[maxn] = { 0 }, max = 0, n;

int findMax(int child_number) {
	int max = preference[child_number][0];
	for (int i = 1; i < n; i++) {
		max = max(max, preference[child_number][i]);
	}
	return max;
}

int h(int child_number) {
	int sum = 0;
	for (; child_number < n; child_number++) {
		sum += findMax(child_number);
	}
	return sum;
}

void dfs(int child_number, int preference_sum) {
	if (child_number == n) {
		max = max(max, preference_sum);
		return;
	}
	if (h(child_number) + preference_sum <= max) {
		return;
	}
	for (int i = 0; i < n; i++) {
		if(!visit[i]){
			visit[i] = 1;
			dfs(child_number + 1, preference_sum + preference[child_number][i]);
			visit[i] = 0;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &preference[i][j]);
		}
	}
	dfs(0, 0);
	printf("%d", max);
	return 0;
}