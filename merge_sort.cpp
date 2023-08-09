#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& v,int l,int mid,int r)
{
    int n1 = mid-l+1;
    int n2 = r-mid;

    vector<int> temp;

    int i=l;
    int j=mid+1;
    int k=0;

    while(i<=mid && j<=r)
    {
        if(v[i]>v[j])
        {
            temp.push_back(v[j]);
            j++;
        }
        else{
            temp.push_back(v[i]);
            i++;
        }
        k++;
    }
    for(int p=i;p<=mid;p++)
    {
            temp.push_back(v[p]);
    }
    for(int p=j;p<=r;p++)
    {
            temp.push_back(v[p]);
    }
    
    for(auto i:temp)
    {
        v[l]=i;
        l++;
    }

}
void mergesort(vector<int>& v,int l,int r)
{
   if(l>=r) return;
   else
   {
   int mid=(l+r)/2;
   mergesort(v,l,mid);
   mergesort(v,mid+1,r);
   merge(v,l,mid,r);
   }
}
int main()
{
    vector<int> v = {3,5,1,2,4,9,7,6,-1,0,8};
    int l=0;
    int r=v.size()-1;
    mergesort(v,l,r); 

    for(auto i:v)
    {
        cout<<i<<endl;
    }
}