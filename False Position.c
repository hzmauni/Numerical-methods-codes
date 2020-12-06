#include <stdio.h>
#include <math.h>

float E=0.001, x0,f0;
int it;
float func(float X)
{
    return (X*X)+(4*X)-5;
}

void print(X1, X2, X0, F1, F2, F0, IT)
{
    char s1='-', s2='-';
    if (F1>0) s1= '+';
    else s2='+';
    printf("It.\t x1\t x2\t x0\t y1\t y2\t");
    printf("%.4lf\t %.4lf\t %.4lf\t %.4lf\t %.4ch\t %.4ch\t ", IT, X1, X2, X0, s1, s2 );
}
void falsePosition( float X1, float X2,float F1, float F2)
{
    float x0, y0;
    it++;
    x0=(X1-((F1*(X2-X1))/(F2-F1)));
    f0= func(x0);
    if (f0==0) printf("\nRoot is %f.",x0);
    else {
        if (f0*F1<0)
        {
            X2=x0;
            F2=f0;
        }
        else{
            X1=x0;
            F1=f0;
        }
    if (fabs((X2-X1/X2)<E)) printf("\nRoot is %f.",x0);
    else falsePosition (X1, X2, F1, F2);
    }
}
int main ()
{
    float x1, x2, f1, f2, flag=1;
    do{
       printf("Enter x1: "); scanf("%f, ", &x1);
       printf("Enter x2: "); scanf("%f, ", &x2);
       f1=func(x1); f2= func(x2);
       if (f1*f2>0) flag=0;
       else falsePosition (x1, x2, f1, f2);
       }

    while (flag==0);
    return 0;
}
