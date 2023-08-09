#include<iostream>
#include<vector>
using namespace std;

void helper(vector<vector<int>> v,int right,int down,bool wentright,bool wentdown,vector<pair<int,int>> sol)
{
    int rightdst = v.size()-1;
    int downdst = v.size() -1;
    if(right==rightdst and down==downdst)
    {
        for(pair<int,int> &i:sol)
        {
            cout<<i.first<<" "<<i.second<<"--";
        }
        cout<<endl;
        return;
    }
    else if(right>rightdst or down>downdst) return;
    else
    {   
        if(!wentdown and down<downdst) //when the wentdown is false
        {
            if(v[down+1][right])
            {   
                sol.push_back({down,right});
                helper(v,right,down+1,wentright,wentdown,sol);
            }
            else
            {  
                if(v[down][right+1]){
                    sol.push_back({down,right});
                    helper(v,right+1,down,wentright,wentdown,sol);
                }
                else
                {
                    if(down==0)
                    {
                        for(int j=right+1;j<=rightdst;j++)
                        {
                            if(v[0][j]==1)
                            {
                                right=j;
                                helper(v,right,down,wentright,wentdown,sol);
                            }
                        }
                    }
                    else{
                        down--;
                        wentdown=true;
                        helper(v,right,down,wentright,wentdown,sol);
                    }
                }

            }
        }
        else //when the went down is true 
        {
            if(right<rightdst)
            {
                if(v[down][right+1]){
                    sol.push_back({down,right});
                    helper(v,right+1,down,wentright,wentdown,sol);
                }
                else
                {
                    if(down==0)
                    {
                        for(int j=right+1;j<=rightdst;j++)
                        {
                            if(v[0][j]==1)
                            {
                                right=j;
                                helper(v,right,down,wentright,wentdown,sol);
                            }
                        }
                    }
                    else{
                        down--;
                        wentdown=true;
                        helper(v,right,down,wentright,wentdown,sol);
                    }
                }

            }
            
        }  
    }
}

void ratnmaze(vector<vector<int>> v)
{
    int right = 0;
    int down = 0;
    bool wentright = false;
    bool wentdown = false;
    vector<pair<int,int>> sol;

    helper(v,right,down,wentright,wentdown,sol);
}
int main()
{
    vector<vector<int>> v = {
        {1,1,1,0},
        {0,0,1,0},
        {0,0,1,0},
        {0,0,1,1}
        };
    ratnmaze(v);
}