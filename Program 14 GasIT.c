#include <stdio.h>
#include <math.h>
#define MAXIT 50
#define EPS 0.000001


main()
{
    int i,j,n,count,status;
    float a[10][10], b[10], x[10];

    printf("\n Solution by Gauss-Seidel Iteration METHOD\n\n");
    printf("\nWhat is the size of n of the system: ");
    scanf("%d",&n);

    printf("\nInput coefficients a[i][j], row by row:\n");
    for(i=1;i<=n;i++)
        for(j = 1;j<=n;j++)
            scanf("%f",&a[i][j]);

    printf("\nInput vector b:\n");
    for(i=1;i<=n;i++)
        scanf("%f",&b[i]);

    gaseid(n,a,b,x,&count,&status);

    if(status == 2)
    {
        printf("\nNo convergence in %d iterations.\n\n",MAXIT);
    }
    else
    {
        printf("\n Solution Vectors X \n\n");
        for(i=1;i<=n;i++)
            printf("%15.6f",x[i]);
        printf("Iterations: %d",count);
    }

}

gaseid(int n, float a[10][10],float b[10],float x[10],int *count, int *status)
{
    int i,j,key;
    float sum, x0[10];

    for(i=1;i<=n;i++)
        x0[i] = b[i]/a[i][i];

    *count=1;
    begin:
        key = 0;
        for(i=1;i<=n;i++)
        {
            sum = b[i];
            for(j=1;j<=n;j++)
            {
                if(i==j)
                    continue;
                sum = sum -a[i][j] * x0[j];
            }
            x[i] = sum/a[i][i];
            if(key==0)
            {
                if(fabs((x[i]-x0[i])/x[i])>EPS)
                    key=1;
            }
        }
            if(key==1)
            {
                if(*count == MAXIT)
                {
                    *status = 2;
                    return;
                }
                else
                {
                    *status = 1;
                    return;
                }
                *count++;
                goto begin;
            }
            return;
}

