#include <stdio.h>
#include <math.h>

float F(float x);

main()
{
    int n, i;
    float a,b,h,sum,ict;
    float F(float x);

    printf("\nGive initial value of x: ");
    scanf("%f",&a);
    printf("\nGive final value of x: ");
    scanf("%f",&b);
    printf("\nWhat is the segment width: ");
    scanf("%f",&h);

    n=(b-a)/h;

    sum = (F(a) + F(b)) / 2;
    for(i=1;i<=n;i++)
    {
        sum = sum + F(a+i*h);
    }
    ict = sum * h;

    printf("\nIntegration between %f and %f ",a,b);
    printf("When h = %f is %f\n",h,ict);

}

float F(float x)
{
    float f;
    f = 1.0-exp(-x/2);
    return f;
}
