#include <stdio.h>
#include <math.h>
#define  EPS 0.000001
#define MAXIT 20
#define F(x) (x)*(x)+(x)-2
#define FD(x) 2*(x)+1

main()
{
    int count = 1;
    float x0,xn,fx,fdx;
    printf("\nInput initial value of x: ");
    scanf("%f",&x0);
    printf("\n Solution by FALSE POSITION METHOD\n\n");

    begin:
        fx = F(x0);
        fdx = FD(x0);

        if(fabs((xn-x0)/xn)< EPS)
        {
            printf("Root = %.4f\n",xn);
            printf("Function value = %0.4f\n",F(xn));
            printf("Number of Iteration = %d\n",count);
        }
        else
        {
            x0 =xn;
            count++;
            if(count<MAXIT)
            {
                goto begin;
            }
            else
            {
                printf("\nSolution does not converge \n");
                printf("in %d iteration.", MAXIT);
            }
        }

}
