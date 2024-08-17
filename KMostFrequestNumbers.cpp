#include <iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
 
 
bool comp(pair<int, int> a, pair<int,int> b)
{
    if(a.second == b.second)
        return a.first > b.first;
    
    return a.second > b.second;
    
}
vector<int> print_N_mostFrequentNumber(vector<int>& nums,
                                       int k,
                                       vector<int>& out)
{
    unordered_map<int,int> mapf;
    for(int i : nums)
    {
        ++mapf[i];
    }
    vector<pair<int,int>> count(mapf.begin(),mapf.end());
    
    sort(count.begin(),count.end(), comp);
    
    cout<<"First k elements are\n";
    for(int i =0; i < k ; i++)
        cout<<count[i].first<< " ";
}
 
// Driver's code
int main()
{
    vector<int> arr{ 3, 1, 4, 4, 5,5,5,5,5,5, 2, 6, 1,1 ,1 };
    int K = 2;
 
    // Function call
    vector<int> ans(K);
    print_N_mostFrequentNumber(arr, K, ans);

    return 0;
}