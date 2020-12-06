#include <stdio.h>
#include <math.h>
float E= 0.001;
float x1, x2, f1, f2;

float func(float X)
{
    return (X*X)+(4*X)-5;
}

void bisection (float X1, float X2, float F1, float F2)
{
    float x0 = (X1+X2)/2.0;
    float f0 = func(x0);
    if (f0==0) printf("The root is: %f", x0);
    else{
        if (F1*f0<0){
           X2=x0;
           F2=f0;
        }
        else {
            X1=x0;
            F1=f0;
        }
        if (fabs((X2-X1)/(X2*1.0)) < E) printf("The root is: %f", x0);
        else bisection (X1, X2, F1, F2);
    }

}
int main ()
{
    int i, flag = 1;
    do {
    printf("Enter the values of x: ");
    scanf("%f %f", &x1, &x2);
    f1= func(x1);
    f2= func(x2);
    if (f1*f2>0) flag=0;
    if (f1==0) printf("The root is: %f", x1);
    if (f2==0) printf("The root is: %f", x2);
    if (f1*f2<0) bisection (x1, x2, f1, f2);

    }
    while (flag==0);
    return 0;
}
