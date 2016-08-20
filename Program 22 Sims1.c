#include <stdio.h>
#include <math.h>
#define F(x) 1-exp(-(x)/2)

main()
{
    int n,m,i;
    float a,b,h,sum=0,ics,x,f1,f2,f3;

    printf("\nGive initial value of x: ");
    scanf("%f",&a);
    printf("\nGive final value of x: ");
    scanf("%f",&b);
    printf("\nWhat is the segments (even number) : ");
    scanf("%f",&n);

    h=(b-a)/n;
    m=n/2;
    x=a;
    f1=F(x);
    for(i=1;i<=m;i++)
    {
        f2 = F(x+h);
        f3 = F(x+2*h);
        sum = sum+f1+4*f2+f3;
        f1 = f3;
        x = x+2*h;
    }
    ics = sum * h/3;

    printf("\nIntegration between %f and %f ",a,b);
    printf("When h = %f is %f\n",h,ics);

}

