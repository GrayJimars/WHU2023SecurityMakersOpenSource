#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int missrate;
    int health;
}Zombie;

void Random_Quick_Sort(Zombie array[], int start, int end) {
	if(start < end){
		int standard, i = start, j = end;
	    Zombie key, temp;
		standard = start + rand() % (end - start);
	
		temp = array[standard];
		array[standard] = array[start];
		array[start] = temp;
	
		key = array[start];
	
		while(i < j){
			while(i < j && array[j].health >= key.health){
				j--;
			}
			array[i] = array[j];
			while(i < j && array[i].health <= key.health){
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
    int n, m, h, b;
    Zombie zombie[5001];
    scanf("%d %d %d %d", &n, &m, &h, &b);
    
    for(int i = 0;i < n;i++){
        scanf("%d %d", &zombie[i].missrate, &zombie[i].health);
    }
    
    Random_Quick_Sort(zombie, 0, n - 1);
    
    int i = 0, count = 0;
    while(m && i < n){
        while(m && zombie[i].health && zombie[i].missrate <= h + b){
            m--;
            zombie[i].health--;
        }
        if(zombie[i].health == 0){
            count++;
        }
        i++;
    }
    
    printf("%d", count);
    
	return 0;
}