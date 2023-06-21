#include <stdio.h>

int Is_Weak_Equal(char *a, int a_start, int a_end,
                  char *b, int b_start, int b_end){
    int length_a = a_end - a_start + 1, 
        length_b = b_end - b_start + 1;
    if(length_a == length_b){
        int Is_Equal = 1;
        for(int i = 0;i < length_a;i++){
            if(a[a_start + i] != b[b_start + i]){
                Is_Equal = 0;
                break;
            }
        }
        
        if(Is_Equal){
            return 1;
        }else if(length_a % 2 == 0){
            return ((Is_Weak_Equal(a, a_start, a_end - length_a / 2,
                                   b, b_start, b_end - length_a / 2) && 
                     Is_Weak_Equal(a, a_start + length_a / 2, a_end,
                                   b, b_start + length_a / 2, b_end)) ||
                    (Is_Weak_Equal(a, a_start, a_end - length_a / 2,
                                   b, b_start + length_a / 2, b_end) && 
                     Is_Weak_Equal(a, a_start + length_a / 2, a_end,
                                   b, b_start, b_end - length_a / 2)));
        }
    }else{
        return 0;
    }
}

int main(){
    char a[200010], b[200010];
    scanf("%s%s",a ,b);
    if(Is_Weak_Equal(a, 0, strlen(a) - 1, b, 0, strlen(b) - 1)){
        printf("YES");
    }else{
        printf("NO");
    }
    return 0;
}
