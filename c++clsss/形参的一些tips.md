##传参

```C++ {.line-numbers}
float &cut(float &a, float &b)
{
    return a < b ? a : b;
}
int main()
{
    float a, b;
    cin >> a >> b;
    cut(a, b) = 0;
    int c = a+b;
    cout << "to pay:" << c << endl;
    return 0;
}
```
