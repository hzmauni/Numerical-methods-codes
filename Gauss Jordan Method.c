#include <stdio.h>

void gaussJordan(float arr[3][4], int n)
{
    int i , j, k, m;
    float c, in;
    for (k=0; k<n ; k++){
        for (m=0, in = arr[k][k] ; m<=n ; m++) arr[k][m]= arr[k][m]/in;

        for (i=0;i<n;i++){
            if (i!=k){
                c= arr [i][k];
                for (j=0;j<=n;j++) arr [i][j]= arr[i][j] - (c*arr [k][j]);

            }
        }
    }
    printf("\nAfter Gauss Jordan method is applied:\n\n");
    for (i=0; i< n;++i)
    {
        printf("Equation %d :", i+1);
        for (j=0;j<=n;++j)
        {
            printf("%f\t", arr [i][j]);
        }
        printf("\n");
    }
    printf("\nThe solution is: \n");
    for (i=0; i<n ; i++)
    {
        printf("x%d = %f\t", i+1, arr[i][3]);
    }


}
int main ()
{
    int num, x, soln, i, j;
    num =3;
    float eqn [3][4]= {2,4,-6,-8,1,3,1,10,2,-4,-2,-12};

    for (i=0; i< num;++i)
    {
        printf("Equation %d :", i+1);
        for (j=0;j<=num;++j)
        {
            printf("%f\t", eqn [i][j]);
        }
        printf("\n");
    }
    gaussJordan(eqn, num);


    return 0;
}

