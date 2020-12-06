#include <stdio.h>

int i;

int horner(int n, int x, int arr[])
{
    int result = arr[0];
    for (i=1; i<n ; ++i) {
            result = result * x + arr [i];
    }
    return result;

}

int main ()
{
    int deg, x, soln;
    printf("Enter the degree of polynomial: ");
    scanf("%d", &deg);
    int eqn [deg +1];
    printf ("Enter the coefficients of the polynomial expression: ");
    for (i=0; i< deg+1;++i)
    {
        scanf("%d", &eqn [i]);
    }
    x=3;
    soln = horner(deg+1, x, eqn);
    printf("The value of the polynomial is: %d", soln);

    return 0;
}

