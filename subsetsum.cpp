#include<iostream>
#include<vector>
using namespace std;

void gen(vector<int> v, vector<int>& e, int i, int sum, vector<vector<int>>& ans, int k) {
    if (i >= v.size()) {
        if (sum == k) {
            ans.push_back(e);
        }
        return;
    }

    int temp = sum + v[i];
    if (temp <= k) {
        e.push_back(v[i]);
        gen(v, e, i + 1, temp, ans, k);
        e.pop_back();
        gen(v, e, i + 1, sum, ans, k);
    }
    else{
        gen(v, e, i + 1, sum, ans, k);
    }
   
}

vector<vector<int>> subsetsum(vector<int> v, int k) {
    int i = 0;
    vector<int> e;
    int sum = 0;
    vector<vector<int>> ans;
    gen(v, e, i, sum, ans, k);
    return ans;
}

int main() {
    vector<int> v = {1, 1, 1};
    int k = 3;
    vector<vector<int>> ans = subsetsum(v, k);
    for (const auto& vec : ans) {
        for (const auto& element : vec) {
            cout << element << " ";
        }
        cout << endl;
    }
    return 0;
}
