#include <stdio.h>
#include <math.h>

float E= 0.001, a, b, x1, x2, f1, f2, dx;


float func(float X)
{
    return (X*X)+4*X-5;
}
void mod_bisection (float X1, float X2, float F1, float F2)
{
    float X= (X1+X2)/2;
    float F = func(X);
    printf(" x = %f \t y= %f\n", X, F);
    if (F1*F<0)
    {
        X2=X;
        F2=F;
    }
    else
    {
        X1=X;
        F1=F;
    }
    if (fabs((X2-X1)/(X2)) < E){
        printf("root is: %f\n", (X1+X2)/2);
        x2=X2;
    }

    else
        if (F1*F2<=0) mod_bisection(X1, X2, F1, F2);

}
int main ()
{
    int flag=0;
    printf("Choose the interval in which to check for roots: ");
    scanf("%f %f",&a,&b);
    printf("Choose the increment interval: ");
    scanf("%f",&dx);
    while (flag==0)
    {
        x1 = a;
        x2 = x1+dx;
        f1 = func(x1);
        f2 = func(x2);

        if (f2*f1<=0 && x2<b) mod_bisection (x1, x2, f1, f2);

        if (x2<b) a=x2;
        else flag=1;

    }
    return 0;
}
