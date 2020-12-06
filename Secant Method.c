#include <stdio.h>
#include <math.h>

float E = 0.01;
int it=0;

float func(float X)
{
    return (X*X)+(4*X)-5;
}


void printRoot(float x1, float x2, float x3, float fx1, float fx2, float fx3, float ER)
{
    printf("\n\nIt.\t x1\t x2\t x3\t f1\t f2\t f3\t E\n");
    printf("%.4d  %.4f  %.4f  %.4f  %.4f  %.4f  %.4f  %.4f\n", it, x1, x2, x3, fx1, fx2, fx3, ER);
}

void secant(float X1, float X2, float FX1, float FX2)
{
    float X3, FX3, error;
    it ++;
    X3 = X2 - ((FX2*(X2-X1))/(FX2-FX1));
    FX3= func (X3);
    printRoot(X1, X2, X3, FX1, FX2, FX3, error);
    if (fabs((X3-X2)/X3)<E) printf("\nRoot found!\nRoot= %f", X3) ;
    else {
            FX1=FX2;
            X1=X2;
            FX2=FX3;
            X2=X3;
            secant(X1, X2, FX1, FX2);
    }
}

int main()
{

    float x1, x2, fx1, fx2;
        printf ("Enter two initial points : ");
        scanf("%f %f", &x1, &x2);

        fx1= func(x1);
        fx2= func(x2);

        if (fx1==0 || fx2==0) printf("The root is given. Secant Method not applied.");
        else secant(x1, x2, fx1, fx2);

    return 0;

}


