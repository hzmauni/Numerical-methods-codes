#include <stdio.h>
#include <math.h>

float E = 0.001;
int it=0;

float func(float X)
{
    return (X*X)+(4*X)-5;
}

float derFunc(float X)
{
    return (2*X)+4;
}

void printRoot(float x0, float x1, float fx0, float fx1, float ER)
{
    printf("\n\nIt.\t x0\t x1\t f0\t f1\t E\n");
    printf("%.4d  %.4f  %.4f  %.4f  %.4f  %.4f\n", it, x0, x1, fx0, fx1, ER);
}
float err(float x0, float x1)
{
    return fabs((x1-x0)/x1);
}
void nrMethod(float X0, float FX0)
{
    float X1, FX1, error;
    it ++;
    X1 = X0 - (FX0/derFunc(X0));
    FX1= func (X1);
    error= err (X0, X1);
    printRoot(X0, X1, FX0, FX1, error);
    if (error<E) printf("\nRoot found!\nRoot= %f", X1) ;
    else nrMethod(X1,FX1);
}

int main()
{
    float x, fx;

    printf ("Enter a value: ");
    scanf("%f", &x);

    fx= func(x);
    if (fx==0) printf("%d is the root. Newton Rhapson Method not applied.", x);
    else {
        nrMethod(x, fx);
    }
    return 0;
}

