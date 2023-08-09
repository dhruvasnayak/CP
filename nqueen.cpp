#include<iostream>
#include<vector>
using namespace std;

void printvec(vector<pair<int,int>> &chess)
{
    for(pair<int,int> pos:chess)
    {
        cout<<pos.first<<" "<<pos.second<<endl;
    }
    cout<<"......................"<<endl;
}
bool is_avb(vector<pair<int,int>> &chess, int n, int col, int row)
{
    for (auto pos : chess)
    {
        // Check if same row or same column
        if (pos.first == row || pos.second == col)
            return false;

        // Check diagonals
        if (abs(pos.first - row) == abs(pos.second - col))
            return false;
    }
    return true;
}

void rec(vector<pair<int,int>> &chess,int n,int i)
{
    if(i==n){
        printvec(chess);
        return;
    }
    for(int k=0;k<n;k++)
    {
        bool avb = is_avb(chess,n,i,k);
        if(avb){
            chess.push_back({k,i});
            rec(chess,n,i+1);
            chess.pop_back();
        }
    }
    return;
}
void nqueen(int n)
{
    vector<pair<int,int>> chess;
    rec(chess,n,0);
}
int main()
{
    int n=8;
    nqueen(n);
}