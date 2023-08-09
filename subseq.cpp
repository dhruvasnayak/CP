#include<iostream>
#include<vector>
using namespace std;

void sgen(int i,vector<int> v,vector<int> &e,vector<vector<int>> &p)
{
    if(i>=(v.size()))
    {
        p.push_back(e);
        return;
    }
    e.push_back(v[i]);
    sgen(i+1,v,e,p);
    e.pop_back();
    sgen(i+1,v,e,p);
}
vector<vector<int>> subseq(vector<int> v)
{
    vector<vector<int>> p;
    vector<int> e;
    int i=0;
    sgen(i,v,e,p);
    return p;
}
int main()
{
    vector<int> v = {1,2,3,4};
    vector<vector<int>> ps=subseq(v);

    for (const auto& vec : ps) {
        for (const auto& element : vec) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}