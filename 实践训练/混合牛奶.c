#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int prize;
    int amount;
}Farmer;

void Random_Quick_Sort(Farmer array[], int start, int end) {
	if(start < end){
		int standard, i = start, j = end;
	    Farmer key, temp;
		standard = start + rand() % (end - start);
	
		temp = array[standard];
		array[standard] = array[start];
		array[start] = temp;
	
		key = array[start];
	
		while(i < j){
			while(i < j && array[j].prize >= key.prize){
				j--;
			}
			array[i] = array[j];
			while(i < j && array[i].prize <= key.prize){
				i++;
			}
			array[j] = array[i];
		}
	
		array[i] = key;

		Random_Quick_Sort(array, start, i - 1);
		Random_Quick_Sort(array, i + 1, end);
	}
}

int main(){
    Farmer farmer[5001];
    int N, M, min_money = 0;
    scanf("%d %d", &N, &M);
    for(int i = 0;i < M;i++){
        scanf("%d %d", &farmer[i].prize, &farmer[i].amount);
    }
    
    Random_Quick_Sort(farmer, 0, M - 1);
    
    int i = 0;
    while(N){
        while(N && farmer[i].amount){
            N--;
            min_money += farmer[i].prize;
            farmer[i].amount--;
        }
        i++;
    }
    
    printf("%d", min_money);
    
	return 0;
}