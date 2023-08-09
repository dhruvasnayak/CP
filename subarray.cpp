#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> subarray(vector<int> v)
{
    vector<vector<int>> p;
    int n = v.size();
    vector<int> temp;

    for(int i=0;i<n;i++)
    {
        temp.clear();
        for(int j=i;j<n;j++)
        {
            temp.push_back(v[j]);
            p.push_back(temp);
        }
    }
    return p;
}
int main()
{
    vector<int> v = {1,2,3};
    vector<vector<int>> p = subarray(v);
    for(auto &i:p)
    {
        for(auto &j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}