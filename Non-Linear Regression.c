#include <stdio.h>
#include <math.h>

int main ()
{

    float arrx[5] = {1,2,3,4,5}, arry[5]={0.5,2,4.5,8,12.5};
    double a, b, d, sumx=0, sumxsqr=0, sumy=0, sumxy=0, n=5.0;
    int i;
    for (i=0 ; i<5; i++)
    {
        sumx = sumx + log (arrx[i]);
        sumy = sumy + log (arry[i]);
        sumxsqr = sumxsqr + ( log (arrx[i]) * log (arrx [i]));
        sumxy = sumxy + ( log (arrx [i]) * log (arry [i]) );

    }
    d = (n*sumxsqr) - (sumx *sumx);
    if (d==0) printf("Divide by zero error.\n");
    else {
        b = ((n*sumxy) - (sumx*sumy)) / (d);
        a = exp ((sumy - (b*sumx))/n);
        printf("The equation : y = %lf * (x^%lf)", a, b);
    }

    return 0;
}
