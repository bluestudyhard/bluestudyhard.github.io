    for(i = 1;i<n;i++) 
    {   
        sum = a[i+1]-a[i];
        if(i%3==0||i==n-1)//第三行换行，于是就在3的倍数这里不输出空格，把最终要的列出来，那么剩下的就可以else了
        
            cout<<sum;
        else
            cout<<sum<<" ";
       if(i%3==0&&i!=n-1)
            cout<<endl;
    }