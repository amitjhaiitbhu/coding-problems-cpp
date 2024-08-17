#include <iostream>
#include <set>
#include <vector>
using namespace std;
 
 
void printIntersection(const vector<int> arr1, const vector<int> &arr2)
{
    // Defining set container s
    set<int> s;
 
    //  Insert the elements of arr1[] to set s
    for (int i : arr1) {
        s.insert(i);
    }
 
    cout << "Intersection:" << endl;
 
    for (int i: arr2) {
        // If element is present in set then
        if (s.find(i) != s.end()) {
            cout << i << " ";
        }
    }
    
    cout<<"Union"<<endl;
    for(int i : s)
    cout<<i<<" ";
    for(int i : arr2)
    {
        if(s.find(i) !=s.end())
            continue;
        cout<<i << " ";
    }
 
    cout << endl;
}
 
// Driver Code
int main()
{
    vector<int> arr1 = { 7, 1, 5, 2, 3, 6 };
    vector<int> arr2 = { 3, 8, 6, 20, 7 };

    //printUnion(arr1, arr2);
    printIntersection(arr1, arr2);
}