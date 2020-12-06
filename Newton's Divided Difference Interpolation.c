#include <stdio.h>

int main()
{
    int n,i,j;
    float xp, fp, sum, pi, x[10], f[10], a[10], d[10][10];
    printf("Input the number of data points: ");
    //scanf("%d",&n);
    n=3;
    x[1] = 2; x[2] = 3; x[3] =4;
    f[1] =1.4142; f[2] = 1.7321; f[3]= 2;
    for (i=1; i<=n;i++)printf("X: %f, F: %f\n", x[i],f[i]);

    for (i=1; i<=n;i++) d[i][1] = f[i];
    for (j=2;j<=n;j++){
        for (i=1;i<=n-j+1;i++){
            d[i][j] = (d[i+1][j-1]-d[i][j-1])/ (x[i+j-1]-x[i]);
        }
    }
    for (j=1;j<=n;j++) a[j] = d[1][j];
    //printf("Input x at which interpolation occurs: ");
    //scanf("%f",&xp);
    xp= 2.5;
    sum = a[1];

    for (i=2; i<=n;i++){
        pi=1.0;
        for (j=1; j<i; j++) pi = pi*(xp-x[j]);
        sum = sum + a[i]*pi;
    }
    fp = sum;

    printf("\nLagrange's interpolated value of x=%f is %f", xp, fp);

    return 0;
}

