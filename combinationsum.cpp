#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void helper(vector<int> &v,int i,int sum,int calsum,vector<int> &e)
{
    int n = v.size()-1;
    if(i>n) return;
    if(calsum==sum)
    {
        for(int &j:e)
        {
            cout<<j<<" ";
        }
        cout<<endl;
        return;
    }
    else if(calsum>sum) return;
    else{
        calsum += v[i];
        e.push_back(v[i]);
        helper(v,i,sum,calsum,e);
        e.pop_back();
        calsum -= v[i];
        helper(v,i+1,sum,calsum,e);
    }
    
}
void combinationsum(vector<int> &v,int sum)
{
    int i=0;
    vector<int> e;
    int calsum=0;
    helper(v,i,sum,calsum,e);
}
int main()
{
    vector<int> v = {1,2,2,6,8,5,5,3};
    sort(v.begin(),v.end());
    vector<int> s;
    s.push_back(v[0]);
    for(int i=0;i<v.size()-1;i++)
    {
        if(v[i]!=v[i+1]) s.push_back(v[i+1]);
    }
    int sum=6;
    combinationsum(s,sum);
}