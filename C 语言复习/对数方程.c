#include<stdio.h>
#include<math.h>
#define EPSILON 1e-7
//4013.678 4005.382605
double function(double x, double a){
    return pow(exp(1), a - x) - x ;
}

double bisection(double a, double (*func)(double, double)) {
    double x, down = 1e-18, up = 10000, fx, temp;
    if(func(down, a) > func(up, a)){
        temp = down;
        down = up;
        up = temp;
    }
    
    do{
        x = (down + up) / 2;
        fx = func(x, a);
        if(fx > 0){
            up = x;
        }else{
            down = x;
            fx = -fx;
        }
    }while(fx >= EPSILON);
    return x;
}

int main() {
    double a;
    scanf("%lf", &a);
    printf("%.6lf", bisection(a, function));
    return 0;
}