#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& nums, int target) {
        int l = 0;
        int n = nums.size();
        int r = n;
        int m;
        while(l<n and r>-1)
        {
            m=(l+r)/2;
            if(nums[m]>target)
            {
                r=m-1;
            }
            else if(nums[m]<target)
            {
                l=l+1;
            }
            else
            {
                return m;
            }
            // cout<<m<<endl;

        }
        return -1;
    }
int main()
{
    vector<int> nums = {1,2,3,4,5};
    int target = 2;
    cout<<search(nums,target)<<endl;

}