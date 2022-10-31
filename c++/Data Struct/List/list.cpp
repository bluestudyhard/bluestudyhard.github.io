#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int Data;
    Node *Next;
};
typedef Node *List;

List read()
{
    int n, x;
    List ans;
    ans->Next = NULL;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &x);
        ans->Data = x;
        ans = ans->Next;
    }
    return ans;
}

int main()
{
    List p1 = read();
    List p2 = read();
}