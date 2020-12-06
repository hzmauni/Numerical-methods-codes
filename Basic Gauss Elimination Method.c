#include <stdio.h>

void gaussElimination(float arr[3][4], int n)
{
   int i , j, k;
   float c, sol1, sol2, sol3;
   for (k=0 ; k<n-1 ; k++){
        for (i=0 ; i<n ; i++){
            if (i>k){
                c=(arr[i][k]/arr[k][k]);
                for (j=0 ; j<=n ; j++) arr [i][j] = arr [i][j] + (c * arr [k][j]);
            }
        }
    }
    printf("\nAfter Gauss Elimination method is applied:\n\n");
    for (i=0; i< n;++i)
    {
        printf("Equation %d:\t", i+1);
        for (j=0;j<=n;++j)
        {
            printf("%f\t", arr [i][j]);
        }
        printf("\n");
    }
    printf("The solution is: \n");
    sol1 = arr[n-1][n]/arr[n-1][n-1];
    sol2 = (arr[n-2][n] - (sol1* arr[n-2][n-1]) ) / arr[n-2][n-2];
    sol3 = (arr[n-3][n]-(sol1* arr[n-3][n-1])-(sol2* arr[n-3][n-2]))/arr[n-3][n-3];
    printf("x3: %f \tx2:%f \tx1=%f \n", sol1, sol2, sol3);


}
int main ()
{
    int num, x, soln, i, j;
    //printf("Enter the number of equations/variables in each equation: ");
    //scanf("%d", &num);
    num =3;
    float eqn [3][4]= {2,-1,3,1,-3,4,-5,0,1,3,-6,0};
    /*for (i=0; i< num;++i)
    {
        printf("\nEnter the coefficients of equation no. %d:\n", i+1);
        for (j=0;j<num;++j)
        {
            printf("x%d: ",j+1);
            scanf("%d", &eqn [i][j]);
        }
        printf("Enter the solution of equation no. %d: ", i+1);
        scanf("%d",&eqn[i][num]);

    }*/
    for (i=0; i< num;++i)
    {
        printf("Equation %d:\t", i+1);
        for (j=0;j<=num;++j)
        {
            printf("%d\t", (int)eqn [i][j]);
        }
        printf("\n");
    }
    gaussElimination(eqn, num);


    return 0;
}

