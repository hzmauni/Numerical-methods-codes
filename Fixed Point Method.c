#include<stdio.h>
#include<math.h>
int main()
{
    float a[100],c=100;
    int j=0;
    printf("\nEnter initial guess:\n");
    scanf("%f",&a[0]);
    printf("\n\n The values of iterations are:\n\n");
    while(c>0.00001)
    {
        a[j+1]=(cos(a[j])+2)/3;
        c=a[j+1]-a[j];
        c=fabs(c);
        printf("Iteration: %d\tValue:%f\tError: %f\n",j,a[j],c);
        j++;

    }
    printf("\n The root of the given function is %f",a[j]);
    return 0;
}

