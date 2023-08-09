#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int partision(vector<int>& v,int l,int r)
{   
    int i=l;
    int pivot = v[r];
    for(int j=l;j<r;j++)
    {
        if(v[j]<=pivot)
        {
            swap(v[i],v[j]);
            i++;
        }
    }
    swap(v[i],v[r]);
    return i;
}
void quicksort(vector<int>& v,int l,int r)
{
    if(l<r)
    {
        int p = partision(v,l,r);
        quicksort(v,l,p-1);
        quicksort(v,p+1,r);
    }
}
int main()
{
    vector<int> v = {2,5,7,1,3,0,-1,8,6,9,4};
    int l=0;
    int r=v.size()-1;
    quicksort(v,l,r);
    for(auto i:v)
    {
        cout<<i<<endl;
    }
}