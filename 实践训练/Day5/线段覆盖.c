#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int start;
    int end;
}Line;

void Random_Quick_Sort(Line array[], int start, int end) {
	if(start < end){
		int standard, i = start, j = end;
	    Line key, temp;
		standard = start + rand() % (end - start);
	
		temp = array[standard];
		array[standard] = array[start];
		array[start] = temp;
	
		key = array[start];
	
		while(i < j){
			while(i < j && array[j].end >= key.end){
				j--;
			}
			array[i] = array[j];
			while(i < j && array[i].end <= key.end){
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
    Line *line;
    int n;
    scanf("%d", &n);
    line = (Line*)malloc(n * sizeof(Line));
    
    for(int i = 0;i < n;i++){
        scanf("%d %d", &line[i].start, &line[i].end);
    }
    
    Random_Quick_Sort(line, 0, n - 1);
    
    int count = 0, minend = 0;
    for(int i = 0;i < n;i++){
        if(line[i].start >= minend){
            count++;
            minend = line[i].end;
        }
    }
    
    printf("%d", count);
    free(line);
	return 0;
}