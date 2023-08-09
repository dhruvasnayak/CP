#include<iostream>
using namespace std;

int  fibanacci(int n)
{
    if(n==1) return 0;
    if(n==2) return 1;
    return fibanacci(n-1)+fibanacci(n-2);
}
int main()
{
    int n = 6;
    int f = fibanacci(n);
    cout<<f<<endl;
}
