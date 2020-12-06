#include <stdio.h>

int main()
{
    int n,i,j;
    float x[100], f[100], fp, lf, sum=0.0, xp;
    printf("Input the number of data points: ");
    //scanf("%d",&n);
    n=3;
    x[0] = 2; x[1] = 3; x[2] =4;
    f[0] =1.4142; f[1] = 1.7321; f[2]= 2;
    for (i=0; i<n;i++)printf("X: %f, F: %f\n", x[i],f[i]);
    printf("Input y at which interpolation occurs: ");
    //scanf("%f",&xp);
    xp= 1.5794;
    for (i=0; i<n;i++){
        lf=1.0;
        for (j=0;j<n;j++){
            if (i!=j) lf = lf*(xp-f[j])/(f[i]-f[j]);
        }
        sum = sum+ lf*x[i];
    }
    fp=sum;

    printf("\nLagrange's interpolated value of y=%f is %f", xp, fp);

    return 0;
}

