#include <stdio.h>

main()
{
    int i,n;
    float x,y,xp,h,m1,m2,m3,m4;
    float func(float x, float y);

    printf("\n Solution by 4th Order RK METHOD\n\n");

    printf("\nInput the initial values of x and y: ");
    scanf("%f%f",&x,&y);
    printf("\nInput x at which y is required: ");
    scanf("%f",&xp);
    printf("\nInput step-size required: ");
    scanf("%f",&h);

    n = (int)((xp-x)/h+0.5);
    for(i=1;i<=n;i++)
    {
        m1 = func(x,y);
        m2 = func(x+0.5*h, y+0.5*m1*h);
        m3 = func(x+0.5*h, y+0.5*m2*h);
        m4 = func(x+h, y+m3*h);
        x = x+h;
        y = y+(m1+2*m2+2*m3+m4)*h/6;
        printf("\nStep: %5d X: %15.6f Y: %15.6f",i,x,y);
    }
    printf("\n\n\nValue of y at x = %f is %f",x,y);

}

float func(float x, float y)
{
    float f;
    f = 2*y/x;
    return (f);
}

