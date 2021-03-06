#include <stdio.h>
#include <math.h>
#define EPS 0.000001
#define F(x) (x)*(x)+(x)-2

fal(float *a, float *b, float *root, int *s, int *count);

main()
{
    int s, count;
    float a,b,root;

    printf("\n Solution by FALSE POSITION METHOD\n");
    printf("\n Input Starting Values: ");
    scanf(" %f%f",&a,&b);

    fal(&a,&b,&root,&s,&count);

    if(s==0)
    {
        printf("\n Starting points do not bracket any root \n\n");
    }
    else
    {
            printf("\n Root = %.4f\n",root);
            printf("F(root) = %.4f\n",F(root));
            printf("No of Iteration = %d\n",count);

    }
    return 0;
}

fal(float *a, float *b, float *root, int *s, int *count)
{
    float x1=*a,x2=*b,x0,f1=F(x1),f2=F(x2),f0;

    if(f1*f2 > 0)
    {
        *s = 0;
        return 0;
    }
    else
    {

        *count = 1;
        begin:
            x0 = x1-f1*(x2-x1)/(f2-f1);
            f0 = F(x0);
            if(f1*f0<0)
            {
                x2=x0;
                f2 = f0;
            }
            else
            {
                x1=x0;
                f1=f0;
            }
            printf("%5d %15.6f %15.6f \n",*count,x1,x2);

            if((fabs(x2-x1)/x2) < EPS)
            {
                *s=1;
                *root = (x1+x2)*0.5;
                return;
            }
            else
            {
                *count++;
                goto begin;
            }
    }

}

