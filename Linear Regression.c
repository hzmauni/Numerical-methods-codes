#include <stdio.h>

int main ()
{

    int arrx[5] = {1,2,3,4,5}, arry[5]={3,4,5,6,8}, i, n=5;
    float a, b, d, sumx=0, sumxsqr=0, sumy=0, sumxy=0;

    for (i=0 ; i<5; i++)
    {
        sumx = sumx + arrx[i];
        sumy = sumy + arry[i];
        sumxsqr = sumxsqr + ( arrx[i] * arrx [i]);
        sumxy = sumxy + ( arrx [i] * arry [i] );

    }
    d = (n*sumxsqr) - (sumx *sumx);
    if (d==0) printf("Divide by zero error.\n");
    else {
        b = ((n*sumxy) - (sumx*sumy)) / (d);
        a = (sumy/n)- (b*(sumx/n));
        printf("The equation : y = %f + %f x", a, b);
    }

    return 0;
}
