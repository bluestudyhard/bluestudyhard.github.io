int *p;
a[3]={1,2,3};
p = a;//== p[0]; *p+1 = p[0+1];
#include<stdio.h>
int main(void)
{
    int a[2][3]={1, 2, 3, 4, 5, 6}, i, j;
    int (*p)[3];//(*p) = p[]
    p = a;
    for (i=0; i<2; i++)
    {
        for (j=0; j<3; j++)
        {
            printf("%d   ", **p + i +//其实可以等价于， j));     2分
        }
        printf("\n");
    }
    return 0;
}
