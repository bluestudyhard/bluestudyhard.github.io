int factorsum(int number)
{
    int sum = 0;
    for (int i = 1; i < number; i++)
    {
        if (number % i == 0)
        {
            sum += i;
        }
    }
    return sum;
}
void PrintPN(int m, int n)
{
    int flag = 0; //要经常用这玩意来判断是否能满足
    for (int i = m; i <= n; i++)
    {
        if (factorsum(i) == i)
        {
            flag = 1;
            printf("%d = 1", i); //因为都有1，所以要把1先打出来，不然后面就会
            //有空格的问题
            for (int j = 2; j < i; j++)
            {
                if (i % j == 0) //从2 开始分解它的因数并打印
                {
                    printf(" + %d", j);
                }
            }
            printf("\n");
        }
    }
    if (flag == 0)
    {
        printf("No perfect number\n");
    }
}
int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    if (factorsum(m) == m)
        printf("%d is a perfect number\n", m);
    if (factorsum(n) == n)
        printf("%d is a perfect number\n", n);
    PrintPN(m, n);
    return 0;
}