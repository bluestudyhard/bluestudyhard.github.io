#include <bits/stdc++.h>
using namespace std;
class retangle
{
    private:
    double width,height;
    public:
    void get_date()
    {
        cin>>width>>height;
    }
    void set_date()
    {
        cout<<width*height<<endl<<(height+width)*2;
    }
};
int main()
{
    
    retangle d1;
    d1.get_date();
    d1.set_date();
}