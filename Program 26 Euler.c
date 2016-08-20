#include <stdio.h>

main()
{
    int i,n;
    float x,y,xp,h,dy;
    float func(float x, float y);

    printf("\n Solution by Euler's METHOD\n\n");

    printf("\nInput the initial values of x and y: ");
    scanf("%f%f",&x,&y);
    printf("\nInput x at which y is required: ");
    scanf("%f",&xp);
    printf("\nInput step-size required: ");
    scanf("%f",&h);

    n = (int)((xp-x)/h+0.5);

    for(i=1;i<=n;i++)
    {
        dy = h*func(x,y);
        x += h;
        y += dy;
        printf("%5d %10.6f %10.6f \n",i,x,y);
    }
    printf("Value of y at x = %f is %f",x,y);
}

float func(float x, float y)
{
    float f;
    f = 2*y/x;
    return (f);
}
